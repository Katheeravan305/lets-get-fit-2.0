#include<iostream>
#include<string>
#include<iomanip>
#include<fstream>
#include "Fitness.h"

using namespace std;

void fitness::setData2(double w, double h)//member to set value of weight and height
{
	weight = w;
	height = h;
}

fitness::fitness()//constructor
{
	weight = 0;
	height = 0;
}

fitness::~fitness()//destructor
{
	weight = 0;
	height = 0;
}



