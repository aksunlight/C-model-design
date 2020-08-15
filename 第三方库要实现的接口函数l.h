#pragma once
#include <iostream>
using namespace std;

class CSoketProtocl
{
public:
	CSoketProtocl()
	{
		;
	}
	virtual ~CSoketProtocl()
	{
		;
	}

	//�ͻ��˳�ʼ�� ��ȡhandle
	virtual int cltSoketInit(/*out*/) = 0;

	//�ͻ��˷�����
	virtual int cltSoketSend(unsigned char* buf/*in*/, int buflen/*in*/) = 0;

	//�ͻ����ձ���
	virtual int cltSoketRev(unsigned char* buf/*in*/, int* buflen/*in out*/) = 0;

	//�ͻ����ͷ���Դ
	virtual int cltSoketDestroy() = 0;

};
