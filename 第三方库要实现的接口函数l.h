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

	//客户端初始化 获取handle
	virtual int cltSoketInit(/*out*/) = 0;

	//客户端发报文
	virtual int cltSoketSend(unsigned char* buf/*in*/, int buflen/*in*/) = 0;

	//客户端收报文
	virtual int cltSoketRev(unsigned char* buf/*in*/, int* buflen/*in out*/) = 0;

	//客户端释放资源
	virtual int cltSoketDestroy() = 0;

};
