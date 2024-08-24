#pragma once
#include "../Global.h"
#include <algorithm> 
#include "structs.h"




// TODO: rewrite in c++ WinSock Style
// Hooking client may not be available however hooking windows sockets api will be
// Addresses
ULONG clientSocketAddr = 0x00BE7914;
ULONG COutPacketAddr = 0x0049637B;
ULONG CInPacketAddr = 0x004965F1;
PVOID* ClientSocket = reinterpret_cast<PVOID*>(clientSocketAddr);
typedef void(__thiscall* PacketSend)(PVOID clientSocket, COutPacket* packet); //Send packet from client to server
PacketSend Send = reinterpret_cast<PacketSend>(COutPacketAddr);
typedef void(__thiscall* PacketRecv)(PVOID clientSocket, CInPacket* packet); //Receive packet from client to server
PacketRecv Recv = reinterpret_cast<PacketRecv>(CInPacketAddr);


void cwriteByte(std::string& packet, BYTE byte) {
    std::stringstream ss;
    ss << std::setw(2) << std::setfill('0') << std::hex << static_cast<int>(byte) << " ";
    packet += ss.str();
}

// Function to write an array of bytes to the packet string
void cwriteBytes(std::string& packet, const std::vector<BYTE>& bytes) {
    for (BYTE byteVal : bytes) {
        cwriteByte(packet, byteVal);
    }
}


// Function to write a string to the packet string
void cwriteString(std::string& packet, const std::string& str) {
    cwriteByte(packet, static_cast<BYTE>(str.length())); // Write the length of the string
    cwriteByte(packet, 0); // Null terminator byte
    cwriteBytes(packet, std::vector<BYTE>(str.begin(), str.end())); // Write the string bytes
}

// Function to write an integer to the packet string
void cwriteInt(std::string& packet, int num) {
    cwriteByte(packet, static_cast<BYTE>(num));
    cwriteByte(packet, static_cast<BYTE>((num >> 8) & 0xFF));
    cwriteByte(packet, static_cast<BYTE>((num >> 16) & 0xFF));
    cwriteByte(packet, static_cast<BYTE>((num >> 24) & 0xFF));
}

// Function to write a short integer to the packet string
void cwriteShort(std::string& packet, short num) {
    cwriteByte(packet, static_cast<BYTE>(num));
    cwriteByte(packet, static_cast<BYTE>((num >> 8) & 0xFF));
}

// Function to write an unsigned short integer to the packet string
void cwriteUnsignedShort(std::string& packet, USHORT num) {
    cwriteByte(packet, static_cast<BYTE>(num));
    cwriteByte(packet, static_cast<BYTE>((num >> 8) & 0xFF));
}
// Hooks
// Define your packet structures
// Function to convert hexadecimal string to byte array
BYTE* atohx(BYTE* szDestination, const char* szSource) {
    Log(szSource);
    BYTE* const szReturn = szDestination;
    for (int lsb, msb; *szSource; szSource += 2) {
        msb = tolower(*szSource);
        lsb = tolower(*(szSource + 1));
        msb -= isdigit(msb) ? 0x30 : 0x57;
        lsb -= isdigit(lsb) ? 0x30 : 0x57;
        if ((msb < 0x0 || msb > 0xf) || (lsb < 0x0 || lsb > 0xf)) {
            *szReturn = 0;
            return nullptr;
        }
        *szDestination++ = static_cast<BYTE>(lsb | (msb << 4));
    }
    *szDestination = 0;
    return szReturn;
}

// Function to check if a raw packet is valid
bool IsValidRawPacket(const std::string& rawPacket) {
    for (char c : rawPacket) {
        if (!((c >= '0' && c <= '9') || (c >= 'A' && c <= 'F') || c == '*')) {
            return false;
        }
    }
    return true;
}

// Function to send a packet
bool cSendPacket(const std::string& packetStr) {
    Log(packetStr.c_str());

    std::string rawPacket = packetStr;
    
    COutPacket Packet;
    Packet.Size = rawPacket.length() / 2;
    BYTE tmpPacketBuf[150];
    Packet.Data = atohx(tmpPacketBuf, rawPacket.c_str());

    try {
        Send(*ClientSocket, &Packet);
        return true;
    }
    catch (...) {
        return false;
    }
}

// Function to receive a packet
bool cRecvPacket(const std::string& packetStr, PVOID* ClientSocket, PacketRecv Recv) {
    if (packetStr.empty() || !IsValidRawPacket(packetStr)) {
        return false;
    }

    std::string rawPacket = packetStr;
    std::replace_if(rawPacket.begin(), rawPacket.end(), [](char c) { return c == ' '; }, ' ');
    std::replace_if(rawPacket.begin(), rawPacket.end(), [](char c) { return c == '*'; }, rand() % 16 + '0');

    CInPacket Packet;
    Packet.Size = rawPacket.length() / 2;
    unsigned char tmpPacketBuf[150];
    Packet.lpvData = atohx(tmpPacketBuf, rawPacket.c_str());

    try {
        Recv(*ClientSocket, &Packet);
        return true;
    }
    catch (...) {
        return false;
    }
}