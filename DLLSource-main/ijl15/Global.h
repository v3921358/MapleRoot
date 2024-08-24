#include <windows.h>
#include <cstdint>
#include <stdio.h>
#include <stdexcept>
#include <iostream>
#include <string>
#include <typeinfo>
#include <sstream>
#include <conio.h>
#include <intrin.h>
#include <WinUser.h>
#include <timeapi.h>
#include <rpcdce.h>
#include <rpc.h>
#include <memoryapi.h>
#include <winapifamily.h>
#include <format>
#include <regex>
#include <locale>
#include <map>
#include <list>
#include <mutex>
#include <memory>
#include <SDKDDKVer.h>
#include <dos.h>
#include <chrono>
#include <cstdio>
#include <stdint.h>
#include <ctime>
#include <thread>
#include <future>
#include <time.h>
#include <comutil.h>
#include "Funcs.h"
#include "Config.h"
#include "detours.h"
#include "INIReader.h"
#pragma comment(lib, "ws2_32.lib")
#pragma comment(lib, "detours.lib")

#define relative_address(frm, to) (int)(((int)to - (int)frm) - 5)

extern HMODULE _this;
extern int expTable[200];