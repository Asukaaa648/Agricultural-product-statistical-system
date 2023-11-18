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
		cout << "欢迎使用农产品统计系统！\n"
			<< "1.创建农产品\n"
			<< "2.查找农产品\n"
			<< "3.更改农产品\n"
			<< "4.删除农产品\n"
			<< "5.退出程序……\n"
			<< "输入对应数字：";
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