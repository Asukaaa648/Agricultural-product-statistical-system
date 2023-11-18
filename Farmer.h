#pragma once
#include"userbase.h"
#include"adminbase.h"
#include<map>
extern int authority;
class Farmer: public userBase
{
public:
	Farmer();
	string breed;  //种类
	double areaSize;  //大小
	map<string,int> maturityDate;  //成熟日期
	double price;  //每亩蔬菜价格
	string getPublicInfo();
	string getPhoneNamber();
	string getAdress();
	void editPhoneNamber();
	void editAdress();
	void renameAdress(string adress);
	void renamePhoneNumber(string num);
	void showAllInfo();
	void createFarmer();
private:
	string adress;  //地址
};