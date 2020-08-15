#pragma once
#include "CSocketProtocol.h"

class CSckFactoryImp1 :public CSoketProtocl
{
public:
	//�ͻ��˳�ʼ�� ��ȡhandle
	virtual int cltSoketInit(/*out*/);

	//�ͻ��˷�����
	virtual int cltSoketSend(unsigned char* buf/*in*/, int buflen/*in*/);

	//�ͻ����ձ���
	virtual int cltSoketRev(unsigned char* buf/*in*/, int* buflen/*in out*/);

	//�ͻ����ͷ���Դ
	virtual int cltSoketDestroy();

private:
	unsigned char* p;
	int len;
};
