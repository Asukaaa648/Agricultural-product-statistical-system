#include"adminbase.h"
int authority = 1;
int authenticate()
{
	cout << "�������Ա�û�����";
	string name, pwd;
	cin >> name;
	cout << "\n�������Ա���룺";
	cin >> pwd;

	if (name == "superadmin" && pwd == "lpfH5a3h78") return 1;
	
	if (name == "admin" && pwd == "2277") return 2;
	else return 0;
}
