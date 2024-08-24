#pragma once
#include "PacketNew.h"

std::string IntToHex(int c) {
    std::stringstream ss;
    ss << std::hex << c;
    return ss.str();
}

std::string GetMac(bool generateFake) {
    std::string macAddress = "";

    if (generateFake) {
        srand(static_cast<unsigned int>(time(nullptr))); // Seed the random number generator
        for (int i = 0; i < 12; i++) {
            if (i != 0 && i % 2 == 0)
                macAddress += "-";
            macAddress += IntToHex(rand() % 16);
        }
    }

    return macAddress;
}

std::string GetHWID(bool generateFake, const std::string& mac) {
    std::string hwid = "";

    if (generateFake) {
        std::string cleanedMac = mac;
        cleanedMac.erase(std::remove(cleanedMac.begin(), cleanedMac.end(), '-'), cleanedMac.end()); // Remove dashes from the MAC address

        hwid += cleanedMac;
        hwid += "_";

        srand(static_cast<unsigned int>(time(nullptr))); // Seed the random number generator
        for (int i = 0; i < 8; i++) {
            hwid += IntToHex(rand() % 16); // Append random hexadecimal digits
        }
    }

    return hwid;
}
void SendSelectCharPacket(int character, bool existsPIC) {
    std::string packet = "";
    std::string macAddress = GetMac(true);
    if (existsPIC) {
        std::string PIC = "111111";
        cwriteBytes(packet, std::vector<unsigned char> { 0x1E, 0x00 }); // Character Select (With PIC) OpCode
        cwriteString(packet, PIC); // PIC
        cwriteInt(packet, character); // Character Number (starts with 1)
        cwriteString(packet, macAddress); // Mac Address
        cwriteString(packet, GetHWID(true, macAddress)); // HWID
        cSendPacket(packet);
    }
}


void SendLoginPacket(const std::string& username, const std::string& password) {
    std::string packet = "";
    cwriteBytes(packet, std::vector<unsigned char> { 0x01, 0x00 });
    cwriteString(packet, username); // Username
    cwriteString(packet, password); // Password
    cwriteBytes(packet, std::vector<unsigned char> { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 }); // Unknown bytes
    cwriteBytes(packet, std::vector<unsigned char> { 0x00, 0x00, 0x00, 0x00 }); // Account id? setting to 0 for now
    cSendPacket(packet);
}

void SendCharListRequestPacket(int world, int channel) {
	std::string packet = "";
	cwriteBytes(packet, std::vector<unsigned char> { 0x05, 0x00 }); // Character List Request OpCode
	cwriteByte(packet, 0x02); // Unknown byte
	cwriteByte(packet, world); // World
	cwriteByte(packet, channel); // Channel
	cwriteBytes(packet, std::vector<unsigned char> { 0x7F, 0x00, 0x00, 0x01 }); // Unknown bytes
	cSendPacket(packet);
}


