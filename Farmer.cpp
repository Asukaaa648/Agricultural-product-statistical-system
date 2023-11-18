#include"Farmer.h"
string Farmer::getPublicInfo()
{
	string areaSize = to_string(this->areaSize);
	map< string, int>::iterator it;
	string date = "";
	for (it = this->maturityDate.begin(); it != this->maturityDate.end(); it++)
		date = date + to_string(it->second)+"/";
	date.erase(date.end() - 1);
	return this->name, this->areaSize,date,this->price,this->breed;

}

string Farmer::getPhoneNamber()
{
	if (authority == 1|| authority == 2) return this->phoneNamber;
	else
	{
		cout << "无权限使用该功能" << endl;
		return "";
	}
}

string Farmer::getAdress()
{
	if (authority == 1 || authority == 2) return this->adress;
	else
	{
		cout << "无权限使用该功能" << endl;
		return "";
	}
}

void Farmer::editPhoneNamber()
{
	if (authority == 1)
	{
		cin >> this->phoneNamber;

	}
	else
	{
		cout << "无权限使用该功能" << endl;

	}
}

void Farmer::editAdress()
{
	if (authority == 1)
	{
		cin >> this->adress;
	}
	else
	{
		cout << "无权限使用该功能" << endl;
		
	}
}

void Farmer::renameAdress(string adress)
{
	this->adress = adress;
}

void Farmer::renamePhoneNumber(string num)
{
	this->phoneNamber = num;
}

void Farmer::showAllInfo()
{
	if (authority == 1|| authority == 2)
	{
		cout << "名字：" << this->name << endl
			<< "住址：" << this->adress << endl
			<< "电话：" << this->phoneNamber << endl
			<< "蔬菜种类：" << this->breed << endl
			<< "面积" << this->areaSize << "亩" << endl
			<< "价格" << this->price << "元/亩" << endl
			<< "成熟日期：";
		string date = to_string(this->maturityDate["year"]) + "/" + to_string(this->maturityDate["month"]) + "/" + to_string(this->maturityDate["day"]);
		cout << date << endl;
	}
	else
	{
		cout << "无权限使用该功能" << endl;

	}
}

void Farmer::createFarmer()
{
	if (authority == 1)
	{
		cout << "名字：";
		cin >> this->name;
		cout << "住址：";
		cin >> this->adress;
		cout << "电话：";
		cin >> this->phoneNamber;
		cout << "蔬菜种类：";
		cin >> this->breed;
		cout << "面积大小(亩)";
		cin >> this->areaSize;
		cout << "价格(元/亩)";
		cin >> this->price;
		cout << "成熟日期(年 月 日,回车隔开)：";
		cin >> this->maturityDate["year"] >> this->maturityDate["month"] >> this->maturityDate["day"];
	}
	else
	{
		cout << "无权限使用该功能" << endl;
		
	}
}

Farmer::Farmer()
{
	map<string, int> maturityDate;
	maturityDate["year"] = 2000;
	maturityDate["month"] = 1;
	maturityDate["day"] = 1;
}
