#pragma once
#include<string>
#include<iostream>
#include"jsoncpp-1.9.5/include/json/json.h"

using namespace std;
class userBase
{
public:
	string name;
	
	virtual string getPublicInfo();
	string getPasswd();
protected:
	string passwd;
	string email;
	string phoneNamber;
};