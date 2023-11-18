#include "controller.h"
#include <sstream>
controller::controller()
{
	vector<string> tokens; // ����һ�����ڴ洢�ָ���ַ�����vector

	// ���ı��ļ�
	ifstream inputFile("data.txt");
	if (!inputFile.is_open()) {
		cout << "�޷����ļ�" << endl;
	}
	else {
		string line;
		while (getline(inputFile, line)) { // ���ж�ȡ�ļ�
			istringstream iss(line); // ʹ��istringstream�ָ���

			string token;
			while (iss >> token) { // ʹ�ÿո�ָ���
				tokens.push_back(token); // ���ָ����ַ�����ӵ�vector��
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

		inputFile.close(); // �ر��ļ�

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
	cout << "������ʽ��"
		<< "1.��������\n"
		<< "2.�ֻ�������\n"
		<< "3.�߲���������\n"
		<< "4.��ַģ������\n"
		<< "�����Ӧ���֣�";
	int choice1 = 0;
	string findinfo;
	cin >> choice1;
	vector<Farmer*> vectorclloctions;
	switch (choice1)
	{
	case(1):
		cout << "�������ݣ�" ;
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
				cout << "��ţ�" << item << endl;
				(*iter)->showAllInfo();
				item++;
			}

		}
			
		else
		{
			cout << "δ�ҵ���Ӧ����" << endl;
		}
		return vectorclloctions;
			
		
		
	case(2):
		cout << "�������ݣ�";
		cin >> findinfo;
		for (vector<Farmer>::iterator iter = this->allfarmer.begin(); iter != this->allfarmer.end(); iter++)
		{

			if ((*iter).getPhoneNamber().find(findinfo) != string::npos)
			{

				vectorclloctions.push_back(&(*iter));
			}
		}
		if (vectorclloctions.empty() == true) cout << "δ�ҵ���Ӧ����" << endl;
		else
		{
			int item = 1;
			for (vector<Farmer *>::iterator iter = vectorclloctions.begin(); iter != vectorclloctions.end(); iter++)
			{
				cout << "��ţ�" << item << endl;
				(*iter)->showAllInfo();
				item++;
			}
		}
			return vectorclloctions;

		
	case(3):
		cout << "�������ݣ�";
		cin >> findinfo;
		for (vector<Farmer>::iterator iter = this->allfarmer.begin(); iter != this->allfarmer.end(); iter++)
		{

			if ((*iter).breed.find(findinfo) != string::npos)
			{
				vectorclloctions.push_back(&(*iter));
			}
		}
		if (vectorclloctions.empty() == true) cout << "δ�ҵ���Ӧ����" << endl;
		else
		{
			int item = 1;
			for (vector<Farmer *>::iterator iter = vectorclloctions.begin(); iter != vectorclloctions.end(); iter++)
			{
				cout << "��ţ�" << item << endl;
				(*iter)->showAllInfo();
				item++;
			}
		}
		return vectorclloctions;

		
	case(4):
		cout << "�������ݣ�";
		cin >> findinfo;
		for (vector<Farmer>::iterator iter = this->allfarmer.begin(); iter != this->allfarmer.end(); iter++)
		{

			if ((*iter).getAdress().find(findinfo) != string::npos)
			{

				vectorclloctions.push_back(&(*iter));
			}
		}
		if (vectorclloctions.empty() == true) cout << "δ�ҵ���Ӧ����" << endl;
		else
		{
			int item=1;
			for (vector<Farmer *>::iterator iter = vectorclloctions.begin(); iter != vectorclloctions.end(); iter++)
			{
				cout << "��ţ�" << item << endl;
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
	cout << "�����Ӧ��ţ�";
	cin >> number;
	cout << "�����޸���Ŀ��\n"
		<< "1.����\n"
		<< "2.סַ\n"
		<< "3.�绰\n"
		<< "4.�߲�����\n"
		<< "5.�����С(Ķ)\n"
		<< "6.�۸�(Ԫ/Ķ)\n"
		<< "7.��������\n"
		<< "�����Ӧ���֣�";
	int choice3 = 0;
	cin >> choice3;
	cout << "�����޸ĺ����ݣ�";
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
		cout << "��������(�� �� ��,�س�����)��";
		cin >> vectorclloctions[number - 1]->maturityDate["year"] >> vectorclloctions[number - 1]->maturityDate["month"] >> vectorclloctions[number - 1]->maturityDate["day"];
		break;
	default:
		break;
	}
	
}

void controller::del()
{
	vector<Farmer>::iterator itr = this->allfarmer.begin();
	cout << "�������֣���ȷ��:";
	string nameinfo;
	cin >> nameinfo;
	int item = 0;
	while (itr != this->allfarmer.end())
	{
		if ((*itr).name == nameinfo)
		{
			itr = this->allfarmer.erase(itr);//ɾ��Ԫ�أ�����ֵָ����ɾ��Ԫ�ص���һ��λ��
			cout << "�ɹ�ɾ����" << endl;
			item++;
		}
		else
		{
			++itr;
		}
	}
	if (item != 1) cout << "δ�ҵ���" << endl;
}

void controller::exit()
{
	ofstream outputFile("data.txt", ios::out || ios::trunc);
	if (!outputFile.is_open()) {
		cout << "�޷����ļ�" << endl;
	}
	else
	{
		cout << "�����ļ���" << endl;
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
	cout << "��ӭ�´�ʹ��";
}