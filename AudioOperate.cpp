// AudioOperate.cpp : 定义 DLL 的初始化例程。
//

#include "stdafx.h"
#include "AudioOperate.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////////
//函数描述: 读取Wav文件得到文件buf和文件长度
//输入参数: char* filePath	读取文件的全路径
//输出参数: char* wavbuf	读取文件内容的指针
//          int& wavlen		读取文件的字节长度
//返 回 值: 成功返回TRUE,失败返回FALSE
//////////////////////////////////////////////////////////////////////////
BOOL ReadWavFile(char* filePath, char* wavbuf, int& wavlen)
{
	int iRet = 0;
	FILE* fp = NULL;

	iRet = fopen_s(&fp,filePath,"rb");
	if (iRet != 0)
	{
		wavbuf = NULL;
		wavlen = 0;
		return FALSE;
	}

	fseek(fp,0,SEEK_END);
	wavlen = ftell(fp);
	fseek(fp,0,SEEK_SET);
	wavbuf = (char*)malloc(wavlen);
	if (wavbuf == NULL)
	{
		wavlen = 0;
		fclose(fp);
		return FALSE;
	}

	int Readsize = fread_s(wavbuf,wavlen,1,wavlen,fp);
	//int Readsize = fread_s(wavbuf,1,iwavlen,fp);

	if (Readsize <= 0)
	{
		free(wavbuf);
		wavbuf = NULL;
		wavlen = 0;
		fclose(fp);
		return FALSE;
	}

	fclose(fp);
	return TRUE;
}

//////////////////////////////////////////////////////////////////////////
//函数描述: 将buff内存写到指定的路径下
//输入参数: char* filePath	写文件的全路径
//输出参数: char* wavbuf	写文件内容的指针
//          int wavlen		写文件的字节长度
//返 回 值: 成功返回TRUE,失败返回FALSE
//////////////////////////////////////////////////////////////////////////
BOOL WriteWavFile(char * filePath, char * wavbuf, int wavlen)
{
	int iRet = 0;
	FILE* fp = NULL;

	iRet = fopen_s(&fp, filePath, "wb");
	if (iRet != 0)
	{
		return FALSE;
	}
	fwrite(wavbuf, wavlen, 1, fp);
	fclose(fp);
	return TRUE;
}

//////////////////////////////////////////////////////////////////////////
//函数描述: 从buff内存读取采样数据
//输入参数: char* wavbuf	数据内存指针
//          int wavlen      数据长度
//输出参数: float* fsampleData 采样数据
//返 回 值: TRUE/FALSE
//////////////////////////////////////////////////////////////////////////
BOOL GetSampleData(float* fsampleData, char* wavbuf, int wavlen)
{
	return TRUE;
}

//////////////////////////////////////////////////////////////////////////
//函数描述: 释放dll中分配的内存
//输入参数: char* wavbuf	释放的内存指针
//返 回 值: NONE
//////////////////////////////////////////////////////////////////////////
void FreeMemory(char* wavbuf)
{
	if (wavbuf != NULL)
	{
		free(wavbuf);
		wavbuf = NULL;
	}
}