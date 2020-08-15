#include "CSckFactoryImp1.h"

//�ͻ��˳�ʼ�� ��ȡhandle
int CSckFactoryImp1::cltSoketInit(/*out*/)
{
	p = NULL;
	len = 0;
	return 0;
}

//�ͻ��˷�����
int CSckFactoryImp1::cltSoketSend(unsigned char* buf/*in*/, int buflen/*in*/)
{
	p = new unsigned char[buflen];
	if (p == NULL)
	{
		return -1;
	}
	memcpy(p, buf, buflen);
	len = buflen;
	return 0;
}

//�ͻ����ձ���
int CSckFactoryImp1::cltSoketRev(unsigned char* buf/*in*/, int* buflen/*in out*/)
{
	if (buf == NULL || buflen == NULL)
	{
		return -1;
	}

	*buflen = this->len;
	memcpy(buf, this->p, this->len);
	return 0;
}

//�ͻ����ͷ���Դ
int CSckFactoryImp1::cltSoketDestroy()
{
	if (p != NULL)
	{
		delete[] p;
		p = NULL;
		len = 0;
	}
	return 0;
}
