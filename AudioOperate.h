// AudioOperate.h : AudioOperate DLL 的主头文件

#pragma once

#ifndef __AFXWIN_H__
	#error "在包含此文件之前包含“stdafx.h”以生成 PCH 文件"
#endif

#include "resource.h"		// 主符号


#define AUDIO_API _declspec(dllexport)

//读取Wav文件得到文件buf和文件长度
extern "C" AUDIO_API BOOL ReadWavFile(char* filePath, char* wavbuf, int& wavlen);
//将buff内存写到指定的路径下
extern "C" AUDIO_API BOOL WriteWavFile(char* filePath, char* wavbuf, int wavlen);
//释放dll中分配的内存
extern "C" AUDIO_API void FreeMemory(char* wavbuf);