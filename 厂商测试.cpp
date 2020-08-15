#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "CSocketProtocol.h"
#include "CSckFactoryImp1.h"
#include "CSckFactoryImp2.h"
#include "HwEncDec.h"
using namespace std;

class MainOp
{
public:
	MainOp()
	{
		sp = NULL;
		ed = NULL;
	}
	MainOp(CSoketProtocl* sp, CEncDesProtocol* ed)
	{
		this->sp = sp;
		this->ed = ed;
	}

	void setSP(CSoketProtocl* sp)
	{
		this->sp = sp;
	}

	void setED(CEncDesProtocol* ed)
	{
		this->ed = ed;
	}

	int SckSendAndRec_EncDec3(CSoketProtocl* sp, CEncDesProtocol* ed, unsigned char* in, int inlen, unsigned char* out, int* outlen);
	int SckSendAndRec_EncDec3(unsigned char* in, int inlen, unsigned char* out, int* outlen);
private:
	CSoketProtocl* sp;
	CEncDesProtocol* ed;
};

//面向抽象类编程，框架实现完毕
int MainOp::SckSendAndRec_EncDec3(CSoketProtocl* sp, CEncDesProtocol* ed, unsigned char* in, int inlen, unsigned char* out, int* outlen)
{
	int ret = 0;
	unsigned char data[4096];
	int datalen = 0;

	ret = sp->cltSoketInit();
	if (ret != 0)
	{
		goto End;
	}

	ret = ed->EncData(in, inlen, data, &datalen);
	if (ret != 0)
	{
		goto End;
	}

	ret = sp->cltSoketSend(data, datalen);//发送加密数据
	if (ret != 0)
	{
		goto End;
	}

	ret = sp->cltSoketRev(data, &datalen);//接收密文
	if (ret != 0)
	{
		goto End;
	}

	ret = ed->DecData(data, datalen, out, outlen);
	if (ret != 0)
	{
		goto End;
	}

End:
	ret = sp->cltSoketDestroy();

	return 0;
}

int MainOp::SckSendAndRec_EncDec3(unsigned char* in, int inlen, unsigned char* out, int* outlen)
{
	int ret = 0;
	unsigned char data[4096];
	int datalen = 0;

	ret = this->sp->cltSoketInit();
	if (ret != 0)
	{
		goto End;
	}

	ret = this->ed->EncData(in, inlen, data, &datalen);
	if (ret != 0)
	{
		goto End;
	}

	ret = this->sp->cltSoketSend(data, datalen);//发送加密数据
	if (ret != 0)
	{
		goto End;
	}

	ret = this->sp->cltSoketRev(data, &datalen);//接收密文
	if (ret != 0)
	{
		goto End;
	}

	ret = this->ed->DecData(data, datalen, out, outlen);
	if (ret != 0)
	{
		goto End;
	}

End:
	ret = this->sp->cltSoketDestroy();

	return 0;
}

int main()
{
	int ret = 0;
	unsigned char in[4096];
	int inlen;
	unsigned char out[4096];
	int outlen = 0, outlen2 = 0;

	strcpy((char*)in, "I am the best one!");
	inlen = (const int)strlen((char*)in);

	MainOp* myMainOp = new MainOp;

	CSoketProtocl* sp = NULL;
	CEncDesProtocol* ed = NULL;

	sp = new CSckFactoryImp1;
	ed = new HwEncDec;

	myMainOp->setSP(sp);//注入框架
	myMainOp->setED(ed);

	ret = myMainOp->SckSendAndRec_EncDec3(in, inlen, out, &outlen);
	if (ret != 0)
	{
		cout << "SckSendAndRec() err:" << ret << endl;
	}

	delete ed;
	delete sp;
	delete myMainOp;

	return 0;
}
