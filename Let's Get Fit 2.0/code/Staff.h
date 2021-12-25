#pragma once
#ifndef Assignment1Sem2_Staff_H
#define Assignment1Sem2_Staff_H
#include<string>
#include "Fitness.h"
#include "Personal.h"
using namespace std;

class staff :public personal//derived class
{
private:
	fitness ob; //fitness class is used for composition.ob is object for fitness class
	int age = 0, size = 1000, year = 0;
	double bmi = 0, bmr = 0, rmr = 0;//variables declaration
	string date, month, date2, month2;
public:
	string getName();//members name that start with get means its for returning values
	string getStaff();
	string getGender();
	int getAge();
	double getWeight();
	double getHeight();
	void Data(string, string, string);
	void Data2(double, double);
	void calculation();//member functions
	void editData();
	void addData();
	double getbmi() { return bmi; }
	double getbmr() { return bmr; }
	double getrmr() { return rmr; }//members name that start with get means its for returning values
	string getdate() { return date; }
	string getmonth() { return month; }
	string getdate2() { return date2; }
	string getmonth2() { return month2; }
	int getyear() { return year; }
	void displayAll();//member functions
	void health();
	friend void output(staff[], int);//friend members
	friend void displayOne(staff[], int);
	friend void simple(staff[], int);
	friend void combine(staff[], int);
	friend void genstats(staff[], int);
	staff();//constructor
	~staff();//destructor
};

#endif