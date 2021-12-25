#include<iostream>
#include<string>
#include<iomanip>
#include<fstream>
#include "Personal.h"

using namespace std;

void personal::setData1(string s, string n, string g)
{//function to set values for name , gender and staff id
	ID = s;
	name = n;
	gender = g;
}

personal::personal()
{
	name = " ";
	ID = " ";
	gender = " ";
}//constructor

personal::~personal()
{
	name = " ";
	ID = " ";
	gender = " ";
}//destructor
