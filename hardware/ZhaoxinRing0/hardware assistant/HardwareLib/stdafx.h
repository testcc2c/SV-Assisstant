// stdafx.h: 标准系统包含文件的包含文件，
// 或是经常使用但不常更改的
// 项目特定的包含文件
//

#pragma once

#include "targetver.h"

#define WIN32_LEAN_AND_MEAN             // 从 Windows 头文件中排除极少使用的内容



// 在此处引用程序需要的其他标头

#include <windows.h>
#include <tchar.h>
#include <string>
#include <memory>
#include <vector>
#include <map>
#include <string>
#include <array>
#include <bitset>
#include <iostream>
#include "driver\Ring0Defination.h"
#include "boost/format.hpp"

#ifdef ZX_OutputLog
#include "log/easylogging++.h"
#include "log/sv_log.h"
#endif

void OutputDebugPrintf(const TCHAR* strOutputString, ...);