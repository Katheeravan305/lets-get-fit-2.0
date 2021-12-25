#pragma once
#ifndef Assignment1Sem2_Fitness_H
#define Assignment1Sem2_Fitness_H
#include<string>
using namespace std;

class fitness//compositon class for staff class
{
protected:
	double weight;//members that are compose to staff class
	double height;
public:
	void setData2(double, double);//member to set value of weight and height
	double weight1() { return weight; }//function to return weight
	double height1() { return height; }//function to return height
	fitness();//constructor
	~fitness();//destructor
};

#endif