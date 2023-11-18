#pragma once
#include"Farmer.h"
#include<fstream>
#include<vector>
extern int authority;
class controller
{
public:
	controller();
	void create();
	vector<Farmer*> find();
	void edit();
	void del();
	void exit();
private:
	vector<Farmer> allfarmer;
};