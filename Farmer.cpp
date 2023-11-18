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
		cout << "��Ȩ��ʹ�øù���" << endl;
		return "";
	}
}

string Farmer::getAdress()
{
	if (authority == 1 || authority == 2) return this->adress;
	else
	{
		cout << "��Ȩ��ʹ�øù���" << endl;
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
		cout << "��Ȩ��ʹ�øù���" << endl;

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
		cout << "��Ȩ��ʹ�øù���" << endl;
		
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
		cout << "���֣�" << this->name << endl
			<< "סַ��" << this->adress << endl
			<< "�绰��" << this->phoneNamber << endl
			<< "�߲����ࣺ" << this->breed << endl
			<< "���" << this->areaSize << "Ķ" << endl
			<< "�۸�" << this->price << "Ԫ/Ķ" << endl
			<< "�������ڣ�";
		string date = to_string(this->maturityDate["year"]) + "/" + to_string(this->maturityDate["month"]) + "/" + to_string(this->maturityDate["day"]);
		cout << date << endl;
	}
	else
	{
		cout << "��Ȩ��ʹ�øù���" << endl;

	}
}

void Farmer::createFarmer()
{
	if (authority == 1)
	{
		cout << "���֣�";
		cin >> this->name;
		cout << "סַ��";
		cin >> this->adress;
		cout << "�绰��";
		cin >> this->phoneNamber;
		cout << "�߲����ࣺ";
		cin >> this->breed;
		cout << "�����С(Ķ)";
		cin >> this->areaSize;
		cout << "�۸�(Ԫ/Ķ)";
		cin >> this->price;
		cout << "��������(�� �� ��,�س�����)��";
		cin >> this->maturityDate["year"] >> this->maturityDate["month"] >> this->maturityDate["day"];
	}
	else
	{
		cout << "��Ȩ��ʹ�øù���" << endl;
		
	}
}

Farmer::Farmer()
{
	map<string, int> maturityDate;
	maturityDate["year"] = 2000;
	maturityDate["month"] = 1;
	maturityDate["day"] = 1;
}
