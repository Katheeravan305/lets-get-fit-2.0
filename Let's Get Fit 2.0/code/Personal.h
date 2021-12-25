#pragma once
#ifndef Assignment1Sem2_Personal_H
#define Assignment1Sem2_Personal_H
#include<string>
using namespace std;

class personal //used to inherit variable from here to staff class which is derived class
{              //base class
protected:
	string name;//variables that are inherited
	string ID;
	string gender;
public:
	void setData1(string, string, string);//function to set name , id and gender variables values
	personal();//counter
	~personal();//destructor
};

#endif



