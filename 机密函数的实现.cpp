#pragma once
#include <iostream>
#include "HwEncDec.h"
#include "DES.h"

using namespace std;

//

int HwEncDec::EncData(unsigned char* plain, int plainlen, unsigned char* cryptdata, int* cryptlen)
{
	int ret = 0;
	std::string s1((char*)plain);
	std::string key = "19970505";
	DES p;

	//º”√‹
	ret = p.Encrypt(plain, plainlen, cryptdata, cryptlen, key);
	if (ret != 0)
	{
		cout << "Encrypt() err:" << ret << endl;
		return ret;
	}
	return ret;
}

int HwEncDec::DecData(unsigned char* cryptdata, int cryptlen, unsigned char* plain, int* plainlen)
{
	int ret = 0;
	std::string s1((char*)plain);
	std::string key = "19970505";
	DES p;

	//Ω‚√‹
	ret = p.Decrypt(cryptdata, cryptlen, plain, plainlen, key);
	if (ret != 0)
	{
		cout << "HwEncDec Encrypt() err:" << ret << endl;
		return ret;
	}
	return ret;
}

