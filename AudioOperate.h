// AudioOperate.h : AudioOperate DLL ����ͷ�ļ�

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


#define AUDIO_API _declspec(dllexport)

//��ȡWav�ļ��õ��ļ�buf���ļ�����
extern "C" AUDIO_API BOOL ReadWavFile(char* filePath, char* wavbuf, int& wavlen);
//��buff�ڴ�д��ָ����·����
extern "C" AUDIO_API BOOL WriteWavFile(char* filePath, char* wavbuf, int wavlen);
//�ͷ�dll�з�����ڴ�
extern "C" AUDIO_API void FreeMemory(char* wavbuf);