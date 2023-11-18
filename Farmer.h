#pragma once
#include"userbase.h"
#include"adminbase.h"
#include<map>
extern int authority;
class Farmer: public userBase
{
public:
	Farmer();
	string breed;  //����
	double areaSize;  //��С
	map<string,int> maturityDate;  //��������
	double price;  //ÿĶ�߲˼۸�
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
	string adress;  //��ַ
};