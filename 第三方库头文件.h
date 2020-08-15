#pragma once
#include "CSocketProtocol.h"

class CSckFactoryImp1 :public CSoketProtocl
{
public:
	//客户端初始化 获取handle
	virtual int cltSoketInit(/*out*/);

	//客户端发报文
	virtual int cltSoketSend(unsigned char* buf/*in*/, int buflen/*in*/);

	//客户端收报文
	virtual int cltSoketRev(unsigned char* buf/*in*/, int* buflen/*in out*/);

	//客户端释放资源
	virtual int cltSoketDestroy();

private:
	unsigned char* p;
	int len;
};
