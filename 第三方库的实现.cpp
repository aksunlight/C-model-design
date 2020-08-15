#include "CSckFactoryImp1.h"

//客户端初始化 获取handle
int CSckFactoryImp1::cltSoketInit(/*out*/)
{
	p = NULL;
	len = 0;
	return 0;
}

//客户端发报文
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

//客户端收报文
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

//客户端释放资源
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
