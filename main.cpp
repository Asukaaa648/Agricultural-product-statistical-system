#include"Farmer.h"
#include"controller.h"
#include <stdlib.h>
using namespace std;
extern int authority;
int main()
{
	authority = authenticate();
	controller c;
	while (true)
	{
		cout << "��ӭʹ��ũ��Ʒͳ��ϵͳ��\n"
			<< "1.����ũ��Ʒ\n"
			<< "2.����ũ��Ʒ\n"
			<< "3.����ũ��Ʒ\n"
			<< "4.ɾ��ũ��Ʒ\n"
			<< "5.�˳����򡭡�\n"
			<< "�����Ӧ���֣�";
		int choice = 0;
		cin >> choice;
		
		switch (choice)
		{
		case(1):
			c.create();
			break;
		case(2):
			c.find();
			break;
		case(3):
			c.edit();
			break;
		case(4):
			c.del();
			break;
		case(5):
			c.exit();
			return 0;
		default:
			break;
		}
		system("pause");
		system("cls");
	}
	
}