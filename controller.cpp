#include "controller.h"
#include <sstream>
controller::controller()
{
	vector<string> tokens; // 创建一个用于存储分割后字符串的vector

	// 打开文本文件
	ifstream inputFile("data.txt");
	if (!inputFile.is_open()) {
		cout << "无法打开文件" << endl;
	}
	else {
		string line;
		while (getline(inputFile, line)) { // 逐行读取文件
			istringstream iss(line); // 使用istringstream分割行

			string token;
			while (iss >> token) { // 使用空格分割行
				tokens.push_back(token); // 将分割后的字符串添加到vector中
			}
			Farmer f;
			f.name = tokens[0];
			f.renameAdress(tokens[1]);
			f.renamePhoneNumber(tokens[2]);
			f.breed = tokens[3];
			f.areaSize = stod(tokens[4]);
			f.price = stod(tokens[5]);
			f.maturityDate["year"] = stoi(tokens[6]);
			f.maturityDate["month"] = stoi(tokens[7]);
			f.maturityDate["day"] = stoi(tokens[8]);
			this->allfarmer.push_back(f);
			tokens.clear();
		}

		inputFile.close(); // 关闭文件

	}
	
}

void controller::create()
{
	Farmer f;
	f.createFarmer();
	this->allfarmer.push_back(f);
	f.showAllInfo();
}

vector<Farmer*> controller::find()
{
	cout << "搜索方式："
		<< "1.名字搜索\n"
		<< "2.手机号搜索\n"
		<< "3.蔬菜类型搜索\n"
		<< "4.地址模糊搜索\n"
		<< "输入对应数字：";
	int choice1 = 0;
	string findinfo;
	cin >> choice1;
	vector<Farmer*> vectorclloctions;
	switch (choice1)
	{
	case(1):
		cout << "搜索内容：" ;
		cin >> findinfo;
		for (vector<Farmer>::iterator iter = this->allfarmer.begin(); iter != this->allfarmer.end(); iter++)
		{
			
			if ((*iter).name.find(findinfo) != string::npos)
			{
				vectorclloctions.push_back(&(*iter));
			}
		}
		if (vectorclloctions.empty() != true)
		{
			int item = 1;
			for (vector<Farmer *>::iterator iter = vectorclloctions.begin(); iter != vectorclloctions.end(); iter++)
			{
				cout << "序号：" << item << endl;
				(*iter)->showAllInfo();
				item++;
			}

		}
			
		else
		{
			cout << "未找到相应数据" << endl;
		}
		return vectorclloctions;
			
		
		
	case(2):
		cout << "搜索内容：";
		cin >> findinfo;
		for (vector<Farmer>::iterator iter = this->allfarmer.begin(); iter != this->allfarmer.end(); iter++)
		{

			if ((*iter).getPhoneNamber().find(findinfo) != string::npos)
			{

				vectorclloctions.push_back(&(*iter));
			}
		}
		if (vectorclloctions.empty() == true) cout << "未找到相应数据" << endl;
		else
		{
			int item = 1;
			for (vector<Farmer *>::iterator iter = vectorclloctions.begin(); iter != vectorclloctions.end(); iter++)
			{
				cout << "序号：" << item << endl;
				(*iter)->showAllInfo();
				item++;
			}
		}
			return vectorclloctions;

		
	case(3):
		cout << "搜索内容：";
		cin >> findinfo;
		for (vector<Farmer>::iterator iter = this->allfarmer.begin(); iter != this->allfarmer.end(); iter++)
		{

			if ((*iter).breed.find(findinfo) != string::npos)
			{
				vectorclloctions.push_back(&(*iter));
			}
		}
		if (vectorclloctions.empty() == true) cout << "未找到相应数据" << endl;
		else
		{
			int item = 1;
			for (vector<Farmer *>::iterator iter = vectorclloctions.begin(); iter != vectorclloctions.end(); iter++)
			{
				cout << "序号：" << item << endl;
				(*iter)->showAllInfo();
				item++;
			}
		}
		return vectorclloctions;

		
	case(4):
		cout << "搜索内容：";
		cin >> findinfo;
		for (vector<Farmer>::iterator iter = this->allfarmer.begin(); iter != this->allfarmer.end(); iter++)
		{

			if ((*iter).getAdress().find(findinfo) != string::npos)
			{

				vectorclloctions.push_back(&(*iter));
			}
		}
		if (vectorclloctions.empty() == true) cout << "未找到相应数据" << endl;
		else
		{
			int item=1;
			for (vector<Farmer *>::iterator iter = vectorclloctions.begin(); iter != vectorclloctions.end(); iter++)
			{
				cout << "序号：" << item << endl;
				(*iter)->showAllInfo();
				item++;
			}
		}
		return vectorclloctions;

		
	default:
		break;
	}
}

void controller::edit()
{
	vector<Farmer*> vectorclloctions = this->find();
	int number;
	cout << "输入对应序号：";
	cin >> number;
	cout << "输入修改项目：\n"
		<< "1.姓名\n"
		<< "2.住址\n"
		<< "3.电话\n"
		<< "4.蔬菜种类\n"
		<< "5.面积大小(亩)\n"
		<< "6.价格(元/亩)\n"
		<< "7.成熟日期\n"
		<< "输入对应数字：";
	int choice3 = 0;
	cin >> choice3;
	cout << "输入修改后数据：";
	switch (choice3)
	{
	case(1):
		cin >> vectorclloctions[number - 1]->name;
		break;
	case(2):
		vectorclloctions[number - 1]->editAdress();
		break;
	case(3):
		vectorclloctions[number - 1]->editPhoneNamber();
		break;
	case(4):
		cin >> vectorclloctions[number - 1]->breed;
		break;
	case(5):
		cin >> vectorclloctions[number - 1]->areaSize;
		break;
	case(6):
		cin >> vectorclloctions[number - 1]->price;
		break;
	case(7):
		cout << "成熟日期(年 月 日,回车隔开)：";
		cin >> vectorclloctions[number - 1]->maturityDate["year"] >> vectorclloctions[number - 1]->maturityDate["month"] >> vectorclloctions[number - 1]->maturityDate["day"];
		break;
	default:
		break;
	}
	
}

void controller::del()
{
	vector<Farmer>::iterator itr = this->allfarmer.begin();
	cout << "输入名字（精确）:";
	string nameinfo;
	cin >> nameinfo;
	int item = 0;
	while (itr != this->allfarmer.end())
	{
		if ((*itr).name == nameinfo)
		{
			itr = this->allfarmer.erase(itr);//删除元素，返回值指向已删除元素的下一个位置
			cout << "成功删除！" << endl;
			item++;
		}
		else
		{
			++itr;
		}
	}
	if (item != 1) cout << "未找到！" << endl;
}

void controller::exit()
{
	ofstream outputFile("data.txt", ios::out || ios::trunc);
	if (!outputFile.is_open()) {
		cout << "无法打开文件" << endl;
	}
	else
	{
		cout << "保存文件中" << endl;
		for (size_t i = 0; i < this->allfarmer.size(); ++i) {
			outputFile << this->allfarmer[i].name << " "
				<< this->allfarmer[i].getAdress() << " "
				<< this->allfarmer[i].getPhoneNamber() << " "
				<< this->allfarmer[i].breed << " "
				<< this->allfarmer[i].areaSize << " "
				<< this->allfarmer[i].price << " "
				<< this->allfarmer[i].maturityDate["year"] << " "
				<< this->allfarmer[i].maturityDate["month"] << " "
				<< this->allfarmer[i].maturityDate["day"] << " " << endl;
		}
		outputFile.close();
	}
	cout << "欢迎下次使用";
}