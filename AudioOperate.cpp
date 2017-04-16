// AudioOperate.cpp : ���� DLL �ĳ�ʼ�����̡�
//

#include "stdafx.h"
#include "AudioOperate.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////////
//��������: ��ȡWav�ļ��õ��ļ�buf���ļ�����
//�������: char* filePath	��ȡ�ļ���ȫ·��
//�������: char* wavbuf	��ȡ�ļ����ݵ�ָ��
//          int& wavlen		��ȡ�ļ����ֽڳ���
//�� �� ֵ: �ɹ�����TRUE,ʧ�ܷ���FALSE
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
//��������: ��buff�ڴ�д��ָ����·����
//�������: char* filePath	д�ļ���ȫ·��
//�������: char* wavbuf	д�ļ����ݵ�ָ��
//          int wavlen		д�ļ����ֽڳ���
//�� �� ֵ: �ɹ�����TRUE,ʧ�ܷ���FALSE
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
//��������: ��buff�ڴ��ȡ��������
//�������: char* wavbuf	�����ڴ�ָ��
//          int wavlen      ���ݳ���
//�������: float* fsampleData ��������
//�� �� ֵ: TRUE/FALSE
//////////////////////////////////////////////////////////////////////////
BOOL GetSampleData(float* fsampleData, char* wavbuf, int wavlen)
{
	return TRUE;
}

//////////////////////////////////////////////////////////////////////////
//��������: �ͷ�dll�з�����ڴ�
//�������: char* wavbuf	�ͷŵ��ڴ�ָ��
//�� �� ֵ: NONE
//////////////////////////////////////////////////////////////////////////
void FreeMemory(char* wavbuf)
{
	if (wavbuf != NULL)
	{
		free(wavbuf);
		wavbuf = NULL;
	}
}