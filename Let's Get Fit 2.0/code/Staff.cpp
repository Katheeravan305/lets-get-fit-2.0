#include "Staff.h"
#include<iostream>
#include<string>
#include<iomanip>
#include<fstream>
#include "Fitness.h"

using namespace std;

string staff::getName()
{
	return name;
}

string staff::getStaff()
{
	return ID;
}

string staff::getGender()
{
	return gender;
}

int staff::getAge()
{
	return age;
}

double staff::getWeight()
{
	return ob.weight1();
}

double staff::getHeight()
{
	return ob.height1();
}

void staff::Data(string s, string n, string g)
{
	setData1(s, n, g);
}

void staff::Data2(double w, double h)
{
	ob.setData2(w, h);
}


void staff::calculation()
{
	long long int calc = stoll(getStaff());//convert staffid frm str to int
	int current = 2020;
	long long int calc2 = (calc / 10000000000);//calculation to get first two numbers in staffid
	month = getStaff()[2];
	month2 = getStaff()[3];
	date = getStaff()[4];
	date2 = getStaff()[5];
	if (calc2 <= 20) { year = calc2 + 2000; age = current - year; }//calculation for age and year
	else { year = calc2 + 1900; age = current - year; }

	bmi = getWeight() / ((getHeight() / 100) * (getHeight() / 100));//bmi formula

	if (gender == "Male")//checking for male gender staffs
	{//formula of rmr for male
		rmr = 88.362 + (13.397 * getWeight()) + (4.799 * getHeight()) - (5.677 * age);
	}
	else
	{//formula of rmr for female
		rmr = 447.593 + (9.247 * getWeight()) + (3.098 * getHeight()) - (4.330 * age);
	}

	if (gender == "Male")//checking for male gender staffs
	{//formula of bmr for male
		bmr = 10 * getWeight() + 6.25 * getHeight() - 5 * age + 5.0;
	}
	else
	{//formula of bmr for female
		bmr = 10 * getWeight() + 6.25 * getHeight() - 5 * age - 161.0;
	}
}

void staff::editData()
{
	int edit;
	double w, h;
	string n, g, s;
	//displaying all the data of the staff which entered by user
	cout << "Name: " << getName() << endl;
	cout << "Staff ID: " << getStaff() << endl;
	cout << "Gender: " << getGender() << endl;
	cout << "Date Of Birth: " << getdate() << getdate2() << "/" << getmonth() << getmonth2() << "/" << getyear() << endl;
	cout << "Age: " << getAge() << endl;
	cout << "Weight: " << getWeight() << endl;
	cout << "Height: " << getHeight() << endl;
	cout << "BMI: " << getbmi() << endl;
	cout << "BMR: " << getbmr() << endl;
	cout << "RMR: " << getrmr() << endl;

	cout << "\nWhich data you want to edit?\n";
	cout << "1.Name\n2.StaffID.\n3.Gender\n4.Weight\n5.Height\n";
	cout << "Option:";
	cin >> edit;//option asking to edit height or weight.
	while (edit < 1 || edit>6)
	{//input validate
		cout << "Input the correct value.\n";
		cout << "Options:";
		cin >> edit;
	}

	if (edit == 1)//option to edit name
	{
		cout << "Enter new name:\n";
		cin.ignore();
		getline(cin,n);//asking user to input new name
		Data(getStaff(), n, getGender());
	}
	else if (edit == 2)//option to edit id
	{
		cout << "Enter new staff ID:\n";
		cin >> s;//asking user to input new id
		Data(s, getName(), getGender());
	}
	else if (edit == 3)//option to edit gender
	{
		cout << "Enter new gender:\n";
		cin >> g;//asking user to input new gender
		while (g != "Male" && g != "Female")
		{//input validation for gender
			cout << "Input the correct value.\n";
			cout << "'Male' for male and 'Female' for female.\n";
			cout << "Enter:";
			cin >> g;
		}
		Data(getStaff(),getName(),g);
	}
	else if (edit == 4)//option to edit weight
	{
		cout << "Enter new weight:\n";
		cin >> w;//asking user to input new weight
		while (w < 1 || w>300)
		{//input validation for weight
			cout << "Input the correct value.\n";
			cout << "Options:";
			cin >> w;
		}
		Data2(w, getHeight());
	}
	else if (edit == 5)//option to edit height
	{
		cout << "Enter new height:\n";
		cin >> h;//asking user to enter new height
		while (h < 50 || h>250)
		{//input validate for age
			cout << "Input the correct value.\n";
			cout << "Enter:";
			cin >> h;
		}
		Data2(getWeight(), h);
	}


	cout << "\n\nStaff's new information...\n";
	calculation();//calling function to recalculate bmi,bmr and rmr.

	cout << "Name: " << getName() << endl;
	cout << "Staff ID: " << getStaff() << endl;
	cout << "Gender: " << getGender() << endl;
	cout << "Age: " << getAge() << endl;
	cout << "Weight: " << getWeight() << endl;
	cout << "Height: " << getHeight() << endl;
	cout << "BMI: " << getbmi() << endl;
	cout << "BMR: " << getbmr() << endl;
	cout << "RMR: " << getrmr() << endl;
	system("PAUSE");//pausing command prompt.
}

void staff::addData()
{
	double weight, height;
	string ID, name, gender;
	cout << "Adding new data.......\n";
	cout << "\nEnter new name:\n";
	cin.ignore();
	getline(cin, name);//input for new staff's name

	cout << "Enter new staffID:\n";
	//cin.ignore();
	cin >> ID;//input for new staffID

	cout << "Enter new gender:\n";
	cin >> gender;//gender input
	while (gender != "Male" && gender != "Female")
	{//input validation for gender
		cout << "Input the correct value.\n";
		cout << "'Male' for male and 'Female' for female.\n";
		cout << "Enter:";
		cin >> gender;
	}

	cout << "Enter new weight:\n";
	cin >> weight;//weight of new staff
	while (weight < 1 || weight >300)
	{//input validation for weight.
		cout << "Input the correct value.\n";
		cout << "Enter:";
		cin >> weight;
	}

	cout << "Enter new height:\n";
	cin >> height;//height input for new staff
	while (height < 100 || height >200)
	{//input validation for height
		cout << "Input the correct value.\n";
		cout << "Enter:";
		cin >> height;
	}
	Data2(weight, height);//setting values of weight and height
	Data(ID, name, gender);//set value for staddid ,gender and name
	calculation();//calculating bmi,bmr,rmr,year and age for new staffs

	//displaying data of new staff
	cout << "Name: " << getName() << endl;
	cout << "Staff ID: " << getStaff() << endl;
	cout << "Gender: " << getGender() << endl;
	cout << "Date Of Birth: " << getdate() << getdate2() << "/" << getmonth() << getmonth2() << "/" << getyear() << endl;
	cout << "Age: " << getAge() << endl;
	cout << "Weight: " << getWeight() << endl;
	cout << "Height: " << getHeight() << endl;
	cout << "BMI: " << getbmi() << endl;
	cout << "BMR: " << getbmr() << endl;
	cout << "RMR: " << getrmr() << endl;

	system("PAUSE");//pausing command prompt
}

void staff::displayAll()
{//printing out all staffs data
	cout << "\nName: " << getName() << endl;
	cout << "Staff ID: " << getStaff() << endl;
	cout << "Gender: " << getGender() << endl;
	cout << "Date Of Birth: " << getdate() << getdate2() << "/" << getmonth() << getmonth2() << "/" << getyear() << endl;
	cout << "Age: " << getAge() << endl;
	cout << "Weight: " << getWeight() << endl;
	cout << "Height: " << getHeight() << endl;
	cout << "BMI: " << getbmi() << endl;
	cout << "BMR: " << getbmr() << endl;
	cout << "RMR: " << getrmr() << endl;
	cout << "\n";//to print the next staff in the next line
}

void displayOne(staff ob1[], int val)
{
	string staff;//declare variable
	cout << "\nEnter staff ID to display thier information only.\n";
	cout << "ID: ";//user entering staff id of the staff they want to know about
	cin >> staff;
	int x = 0;

	//input validation for staff id
	for (int i = 0; i < val; i++)
	{
		if (staff == ob1[i].getStaff())
		{
			x = x + 1;
		}
	}
	while (x != 1)
	{
		system("CLS");
		cout << "This staffID does not exist in file.\n";
		cout << "Enter the correct id:";
		cin >> staff;
		for (int i = 0; i < val; i++)
		{
			if (staff == ob1[i].getStaff())
			{
				x = x + 1;
			}
		}
	}

	for (int i = 0; i < val; i++)
	{//loop to search for the staffID.
		if (staff == ob1[i].getStaff())//comparing user entered id with staffid array.
		{//printing out all information of the staff searched.
			cout << "\nName: " << ob1[i].getName() << endl;
			cout << "Staff ID: " << ob1[i].getStaff() << endl;
			cout << "Gender: " << ob1[i].getGender() << endl;
			cout << "Date Of Birth: " << ob1[i].getdate() << ob1[i].getdate2() << "/" << ob1[i].getmonth() << ob1[i].getmonth2() << "/" << ob1[i].getyear() << endl;
			cout << "Age: " << ob1[i].getAge() << endl;
			cout << "Weight: " << ob1[i].getWeight() << endl;
			cout << "Height: " << ob1[i].getHeight() << endl;
			cout << "BMI: " << ob1[i].getbmi() << endl;
			cout << "BMR: " << ob1[i].getbmr() << endl;
			cout << "RMR: " << ob1[i].getrmr() << endl;
		}
	}
	system("PAUSE");//pausing the command prompt.
}

void simple(staff ob1[], int val)
{
	int option;
	system("CLS");//clearing command prompt
	cout << "How do you want to search?\nBy\n";//asking user to choose whether to display data according to 
	cout << "1.Staff ID\n2.Gender.\n3.Age.\nOption:";//staffID , gender or age.
	cin >> option;
	while (option < 1 || option >3)
	{//input validation
		cout << "Input the correct value.\n";
		cout << "Enter:";
		cin >> option;
	}

	if (option == 1)//if user choose staffID
	{
		system("CLS");//clearing command prompt
		string staff;
		cout << "\nEnter staff ID .\n";
		cout << "ID: ";//asking user to enter staff id to be searched
		cin >> staff;
		int x = 0;

		//input validation for staff id
		for (int i = 0; i < val; i++)
		{
			if (staff == ob1[i].getStaff())
			{
				x = x + 1;
			}
		}
		while (x != 1)
		{
			system("CLS");
			cout << "This staffID does not exist in file.\n";
			cout << "Enter the correct id:";
			cin >> staff;
			for (int i = 0; i < val; i++)
			{
				if (staff == ob1[i].getStaff())
				{
					x = x + 1;
				}
			}
		}

		for (int i = 0; i < val; i++)
		{//loop to search for staff id in array
			if (staff == ob1[i].getStaff())//comparing user input with array
			{//printing out all information about s
				cout << "\nName: " << ob1[i].getName() << endl;
				cout << "Staff ID: " << ob1[i].getStaff() << endl;
				cout << "Gender: " << ob1[i].getGender() << endl;
				cout << "Date Of Birth: " << ob1[i].getdate() << ob1[i].getdate2() << "/" << ob1[i].getmonth() << ob1[i].getmonth2() << "/" << ob1[i].getyear() << endl;
				cout << "Age: " << ob1[i].getAge() << endl;
				cout << "Weight: " << ob1[i].getWeight() << endl;
				cout << "Height: " << ob1[i].getHeight() << endl;
				cout << "BMI: " << ob1[i].getbmi() << endl;
				cout << "BMR: " << ob1[i].getbmr() << endl;
				cout << "RMR: " << ob1[i].getrmr() << endl;
			}
		}
	}
	else if (option == 2)//if user choose gender
	{
		system("CLS");//clearing command prompt
		string gender;//declaring a variable char for user input
		int y = 0;
		cout << "\nEnter staff gender .\n";
		cout << "Gender: ";//asking user to input gender
		cin >> gender;
		while (gender != "Male" && gender != "Female")
		{//input validation for gender
			cout << "Input the correct value.\n";
			cout << "'Male' for male and 'Female' for female.\n";
			cout << "Enter:";
			cin >> gender;
		}
		//to display data 
		for (int i = 0; i < val; i++)
		{//loop to find all the data with the same gender as user entered.
			if (gender == ob1[i].getGender())//comparing user input with array
			{//printing out all information within the gender
				cout << "\nName: " << ob1[i].getName() << endl;
				cout << "Staff ID: " << ob1[i].getStaff() << endl;
				cout << "Gender: " << ob1[i].getGender() << endl;
				cout << "Date Of Birth: " << ob1[i].getdate() << ob1[i].getdate2() << "/" << ob1[i].getmonth() << ob1[i].getmonth2() << "/" << ob1[i].getyear() << endl;
				cout << "Age: " << ob1[i].getAge() << endl;
				cout << "Weight: " << ob1[i].getWeight() << endl;
				cout << "Height: " << ob1[i].getHeight() << endl;
				cout << "BMI: " << ob1[i].getbmi() << endl;
				cout << "BMR: " << ob1[i].getbmr() << endl;
				cout << "RMR: " << ob1[i].getrmr() << endl;
				y = y + 1;//counter to calculate total number of male or female staff.
			}
		}//displaying total number of male or female staff.
		cout << endl << y << " number of staffs are " << gender << ".\n";
	}
	else if (option == 3)//if user choose age
	{
		system("CLS");//clearing command prompt
		int AGE, AGE2, z = 0;//declaring 2 variable to input age range
		cout << "\nEnter staff age .\n";
		cout << "MinAge: ";//entering minimum age range
		cin >> AGE;
		while (AGE < 18 || AGE>100)
		{//input validation
			cout << "Input the correct value.\n";
			cout << "Enter:";
			cin >> AGE;
		}
		cout << "MaxAge:";//entering maximum age range
		cin >> AGE2;
		while (AGE2 < 18 || AGE2>100)
		{//input validation
			cout << "Input the correct value.\n";
			cout << "Enter:";
			cin >> AGE2;
		}
		//displaying data in table like form.
		for (int i = 0; i < val; i++)
		{//looping to search staff within the age range
			if ((ob1[i].getAge() > AGE) && (ob1[i].getAge() < AGE2))//age range
			{//displaying staff within the range
				cout << "\nName: " << ob1[i].getName() << endl;
				cout << "Staff ID: " << ob1[i].getStaff() << endl;
				cout << "Gender: " << ob1[i].getGender() << endl;
				cout << "Date Of Birth: " << ob1[i].getdate() << ob1[i].getdate2() << "/" << ob1[i].getmonth() << ob1[i].getmonth2() << "/" << ob1[i].getyear() << endl;
				cout << "Age: " << ob1[i].getAge() << endl;
				cout << "Weight: " << ob1[i].getWeight() << endl;
				cout << "Height: " << ob1[i].getHeight() << endl;
				cout << "BMI: " << ob1[i].getbmi() << endl;
				cout << "BMR: " << ob1[i].getbmr() << endl;
				cout << "RMR: " << ob1[i].getrmr() << endl;
				z = z + 1;//to calculate number of staff within the range.
			}
		}//to display number of staff within the range.
		cout << endl << z << " number of staff are the same age.\n";
	}
	system("PAUSE");//pausing the command prompt.
}

void combine(staff ob1[], int val)
{
	//First user will choose bmi,bmr or rmr.Then they will select age(range),gender or all staffs to combine with bmi,bmr and rmr.
	//After that user have to choose bmi,bmr and rmr range.
	//<,>,<=,>= and in between range (range input by user).
	//after all this program will compare every array depending on the above requirements.
	//this is how this combined search function will work.
	system("CLS");//clearing command prompt
	int enter, start;
	cout << "\nSearch for.....\n";
	cout << "1.BMI\n2.BMR\n3.RMR\nOption:";
	cin >> start;
	while (start < 1 || start >3)
	{//input validation
		cout << "Input the correct value.\n";
		cout << "Enter:";
		cin >> start;
	}

	if (start == 1)//combined search under BMI.
	{
		int begin, AGE, AGE2;
		string Gender;
		cout << "\nSearch by...\n";
		cout << "1.Age\n2.Gender\n3.All staffs\nOptions:";
		cin >> begin;//asking user to choose combined 
		while (begin < 1 || begin >3)
		{//input validation
			cout << "Input the correct value.\n";
			cout << "Enter:";
			cin >> begin;
		}

		if (begin == 1)
		{
			cout << "Enter age.Min age:";
			cin >> AGE;
			while (AGE < 18 || AGE >100)
			{
				cout << "Input the correct value.\n";
				cout << "Enter:";
				cin >> AGE;
			}
			cout << "\nMax age:";
			cin >> AGE2;
			while (AGE2 < 18 || AGE2 >100)
			{
				cout << "Input the correct value.\n";
				cout << "Enter:";
				cin >> AGE2;
			}
			int enter, value, value2;
			cout << "\n1.BMI less than.\n2.BMI more than.\n";
			cout << "3.BMI less than equals to.\n4.BMI more than equals to.\n";
			cout << "5.BMI within range.\nOptions:";
			cin >> enter;
			while (enter < 1 || enter >5)
			{
				cout << "Input the correct value.\n";
				cout << "Enter:";
				cin >> enter;
			}

			if (enter == 1)
			{
				cout << "Enter value of BMI:";
				cin >> value;
				while (value < 1 || value >100)
				{
					cout << "Input the correct value.\n";
					cout << "Enter:";
					cin >> value;
				}
				cout << "\nNo\tName\t" << "\t\tStaffID\t\t" << "Age\t" << "Gender\t" << "BMI\n";
				for (int i = 0; i < val; i++)
				{
					if ((ob1[i].getAge() > AGE) && (ob1[i].getAge() < AGE2))
					{
						if (ob1[i].getbmi() < value)
						{
							cout << (i + 1) << "\t" << ob1[i].getName() << "\t\t\t" << ob1[i].getStaff() << "\t\t" << ob1[i].getGender() << "\t" << ob1[i].getAge() << "\t" << ob1[i].getbmi();
							cout << "\n";
						}
					}
				}
			}
			else if (enter == 2)
			{
				cout << "Enter value of BMI:";
				cin >> value;
				while (value < 1 || value >100)
				{
					cout << "Input the correct value.\n";
					cout << "Enter:";
					cin >> value;
				}
				cout << "\nNo\tName\t" << "\tStaffID\t\t" << "Gender\t" << "Age\t" << "BMI\n";
				for (int i = 0; i < val; i++)
				{
					if ((ob1[i].getAge() > AGE) && (ob1[i].getAge() < AGE2))
					{
						if (ob1[i].getbmi() > value)
						{
							cout << (i + 1) << "\t" << ob1[i].getName() << "\t\t\t" << ob1[i].getStaff() << "\t\t" << ob1[i].getGender() << "\t" << ob1[i].getAge() << "\t" << ob1[i].getbmi();
							cout << "\n";
						}
					}
				}
			}
			else if (enter == 3)
			{
				cout << "Enter value of BMI:";
				cin >> value;
				while (value < 1 || value >100)
				{
					cout << "Input the correct value.\n";
					cout << "Enter:";
					cin >> value;
				}
				cout << "\nNo\tName\t" << "\tStaffID\t\t" << "Gender\t" << "Age\t" << "BMI\n";
				for (int i = 0; i < val; i++)
				{
					if ((ob1[i].getAge() > AGE) && (ob1[i].getAge() < AGE2))
					{
						if (ob1[i].getbmi() <= value)
						{
							cout << (i + 1) << "\t" << ob1[i].getName() << "\t\t\t" << ob1[i].getStaff() << "\t\t" << ob1[i].getGender() << "\t" << ob1[i].getAge() << "\t" << ob1[i].getbmi();
							cout << "\n";
						}
					}
				}
			}
			else if (enter == 4)
			{
				cout << "Enter value of BMI:";
				cin >> value;
				while (value < 1 || value >100)
				{
					cout << "Input the correct value.\n";
					cout << "Enter:";
					cin >> value;
				}
				cout << "\nNo\tName\t" << "\tStaffID\t\t" << "Gender\t" << "Age\t" << "BMI\n";
				for (int i = 0; i < val; i++)
				{
					if ((ob1[i].getAge() > AGE) && (ob1[i].getAge() < AGE2))
					{
						if (ob1[i].getbmi() >= value)
						{
							cout << (i + 1) << "\t" << ob1[i].getName() << "\t\t\t" << ob1[i].getStaff() << "\t\t" << ob1[i].getGender() << "\t" << ob1[i].getAge() << "\t" << ob1[i].getbmi();
							cout << "\n";
						}
					}
				}
			}
			else if (enter == 5)
			{
				cout << "Enter value of BMI:\nMin Value1:";
				cin >> value;
				while (value < 1 || value >100)
				{
					cout << "Input the correct value.\n";
					cout << "Enter:";
					cin >> value;
				}
				cout << "\nMax Value:";
				cin >> value2;
				while (value2 < 1 || value2 >100)
				{
					cout << "Input the correct value.\n";
					cout << "Enter:";
					cin >> value2;
				}
				cout << "\nNo\tName\t" << "\tStaffID\t\t" << "Gender\t" << "Age\t" << "BMI\n";
				for (int i = 0; i < val; i++)
				{
					if ((ob1[i].getAge() > AGE) && (ob1[i].getAge() < AGE2))
					{
						if ((ob1[i].getbmi() > value) && (ob1[i].getbmi() < value2))
						{
							cout << (i + 1) << "\t" << ob1[i].getName() << "\t\t\t" << ob1[i].getStaff() << "\t\t" << ob1[i].getGender() << "\t" << ob1[i].getAge() << "\t" << ob1[i].getbmi();
							cout << "\n";
						}
					}
				}
			}
		}
		else if (begin == 2)
		{
			cout << "Enter gender.'Male' for male and 'Female' for female.\nGender:";
			cin >> Gender;
			while (Gender != "Male" && Gender != "Female")
			{
				cout << "Input the correct value.\n";
				cout << "'Male' for male and 'Female' for female.\n";
				cout << "Enter:";
				cin >> Gender;
			}
			int enter, value, value2;
			cout << "\n1.BMI less than.\n2.BMI more than.\n";
			cout << "3.BMI less than equals to.\n4.BMI more than equals to.\n";
			cout << "5.BMI within range.\nOptions:";
			cin >> enter;
			while (enter < 1 || enter >5)
			{
				cout << "Input the correct value.\n";
				cout << "Enter:";
				cin >> enter;
			}
			if (enter == 1)
			{
				cout << "Enter value of BMI:";
				cin >> value;
				while (value < 1 || value >100)
				{
					cout << "Input the correct value.\n";
					cout << "Enter:";
					cin >> value;
				}
				cout << "\nNo\tName\t" << "\tStaffID\t\t" << "Gender\t" << "Age\t" << "BMI\n";
				for (int i = 0; i < val; i++)
				{
					if (Gender == ob1[i].getGender())
					{
						if (ob1[i].getbmi() < value)
						{
							cout << (i + 1) << "\t" << ob1[i].getName() << "\t\t\t" << ob1[i].getStaff() << "\t\t" << ob1[i].getGender() << "\t" << ob1[i].getAge() << "\t" << ob1[i].getbmi();
							cout << "\n";
						}
					}
				}
			}
			else if (enter == 2)
			{
				cout << "Enter value of BMI:";
				cin >> value;
				while (value < 1 || value >100)
				{
					cout << "Input the correct value.\n";
					cout << "Enter:";
					cin >> value;
				}
				cout << "\nNo\tName\t" << "\tStaffID\t\t" << "Gender\t" << "Age\t" << "BMI\n";
				for (int i = 0; i < val; i++)
				{
					if (Gender == ob1[i].getGender())
					{
						if (ob1[i].getbmi() > value)
						{
							cout << (i + 1) << "\t" << ob1[i].getName() << "\t\t\t" << ob1[i].getStaff() << "\t\t" << ob1[i].getGender() << "\t" << ob1[i].getAge() << "\t" << ob1[i].getbmi();
							cout << "\n";
						}
					}
				}
			}
			else if (enter == 3)
			{
				cout << "Enter value of BMI:";
				cin >> value;
				while (value < 1 || value >100)
				{
					cout << "Input the correct value.\n";
					cout << "Enter:";
					cin >> value;
				}
				cout << "\nNo\tName\t" << "\tStaffID\t\t" << "Gender\t" << "Age\t" << "BMI\n";
				for (int i = 0; i < val; i++)
				{
					if (Gender == ob1[i].getGender())
					{
						if (ob1[i].getbmi() <= value)
						{
							cout << (i + 1) << "\t" << ob1[i].getName() << "\t\t\t" << ob1[i].getStaff() << "\t\t" << ob1[i].getGender() << "\t" << ob1[i].getAge() << "\t" << ob1[i].getbmi();
							cout << "\n";
						}
					}
				}
			}
			else if (enter == 4)
			{
				cout << "Enter value of BMI:";
				cin >> value;
				while (value < 1 || value >100)
				{
					cout << "Input the correct value.\n";
					cout << "Enter:";
					cin >> value;
				}
				cout << "\nNo\tName\t" << "\tStaffID\t\t" << "Gender\t" << "Age\t" << "BMI\n";
				for (int i = 0; i < val; i++)
				{
					if (Gender == ob1[i].getGender())
					{
						if (ob1[i].getbmi() >= value)
						{
							cout << (i + 1) << "\t" << ob1[i].getName() << "\t\t\t" << ob1[i].getStaff() << "\t\t" << ob1[i].getGender() << "\t" << ob1[i].getAge() << "\t" << ob1[i].getbmi();
							cout << "\n";
						}
					}
				}
			}
			else if (enter == 5)
			{
				cout << "Enter value of BMI:\nMin Value1:";
				cin >> value;
				while (value < 1 || value >100)
				{
					cout << "Input the correct value.\n";
					cout << "Enter:";
					cin >> value;
				}
				cout << "\nMax Value:";
				cin >> value2;
				while (value2 < 1 || value2 >100)
				{
					cout << "Input the correct value.\n";
					cout << "Enter:";
					cin >> value2;
				}
				cout << "\nNo\tName\t" << "\tStaffID\t\t" << "Gender\t" << "Age\t" << "BMI\n";
				for (int i = 0; i < val; i++)
				{
					if (Gender == ob1[i].getGender())
					{
						if ((ob1[i].getbmi() > value) && (ob1[i].getbmi() < value2))
						{
							cout << (i + 1) << "\t" << ob1[i].getName() << "\t\t\t" << ob1[i].getStaff() << "\t\t" << ob1[i].getGender() << "\t" << ob1[i].getAge() << "\t" << ob1[i].getbmi();
							cout << "\n";
						}
					}
				}
			}
		}
		else if (begin == 3)
		{
			int enter, value, value2;
			cout << "\n1.BMI less than.\n2.BMI more than.\n";
			cout << "3.BMI less than equals to.\n4.BMI more than equals to.\n";
			cout << "5.BMI within range.\nOptions:";
			cin >> enter;
			while (enter < 1 || enter >100)
			{
				cout << "Input the correct value.\n";
				cout << "Enter:";
				cin >> enter;
			}
			if (enter == 1)
			{
				cout << "Enter value of BMI:";
				cin >> value;
				while (value < 1 || value >100)
				{
					cout << "Input the correct value.\n";
					cout << "Enter:";
					cin >> value;
				}
				cout << "\nNo\tName\t" << "\tStaffID\t\t" << "Gender\t" << "Age\t" << "BMI\n";
				for (int i = 0; i < val; i++)
				{
					if (ob1[i].getbmi() < value)
					{
						cout << (i + 1) << "\t" << ob1[i].getName() << "\t\t\t" << ob1[i].getStaff() << "\t\t" << ob1[i].getGender() << "\t" << ob1[i].getAge() << "\t" << ob1[i].getbmi();
						cout << "\n";
					}
				}
			}
			else if (enter == 2)
			{
				cout << "Enter value of BMI:";
				cin >> value;
				while (value < 1 || value >100)
				{
					cout << "Input the correct value.\n";
					cout << "Enter:";
					cin >> value;
				}
				cout << "\nNo\tName\t" << "\tStaffID\t\t" << "Gender\t" << "Age\t" << "BMI\n";
				for (int i = 0; i < val; i++)
				{
					if (ob1[i].getbmi() > value)
					{
						cout << (i + 1) << "\t" << ob1[i].getName() << "\t\t\t" << ob1[i].getStaff() << "\t\t" << ob1[i].getGender() << "\t" << ob1[i].getAge() << "\t" << ob1[i].getbmi();
						cout << "\n";
					}
				}
			}
			else if (enter == 3)
			{
				cout << "Enter value of BMI:";
				cin >> value;
				while (value < 1 || value >100)
				{
					cout << "Input the correct value.\n";
					cout << "Enter:";
					cin >> value;
				}
				cout << "\nNo\tName\t" << "\tStaffID\t\t" << "Gender\t" << "Age\t" << "BMI\n";
				for (int i = 0; i < val; i++)
				{
					if (ob1[i].getbmi() <= value)
					{
						cout << (i + 1) << "\t" << ob1[i].getName() << "\t\t\t" << ob1[i].getStaff() << "\t\t" << ob1[i].getGender() << "\t" << ob1[i].getAge() << "\t" << ob1[i].getbmi();
						cout << "\n";
					}
				}
			}
			else if (enter == 4)
			{
				cout << "Enter value of BMI:";
				cin >> value;
				while (value < 1 || value >100)
				{
					cout << "Input the correct value.\n";
					cout << "Enter:";
					cin >> value;
				}
				cout << "\nNo\tName\t" << "\tStaffID\t\t" << "Gender\t" << "Age\t" << "BMI\n";
				for (int i = 0; i < val; i++)
				{
					if (ob1[i].getbmi() >= value)
					{
						cout << (i + 1) << "\t" << ob1[i].getName() << "\t\t\t" << ob1[i].getStaff() << "\t\t" << ob1[i].getGender() << "\t" << ob1[i].getAge() << "\t" << ob1[i].getbmi();
						cout << "\n";
					}
				}
			}
			else if (enter == 5)
			{
				cout << "Enter value of BMI:\nMin Value1:";
				cin >> value;
				while (value < 1 || value >100)
				{
					cout << "Input the correct value.\n";
					cout << "Enter:";
					cin >> value;
				}
				cout << "\nMax Value:";
				cin >> value2;
				while (value2 < 1 || value2>100)
				{
					cout << "Input the correct value.\n";
					cout << "Enter:";
					cin >> value2;
				}
				cout << "\nNo\tName\t" << "\tStaffID\t\t" << "Gender\t" << "Age\t" << "BMI\n";
				for (int i = 0; i < val; i++)
				{
					if ((ob1[i].getbmi() > value) && (ob1[i].getbmi() < value2))
					{
						cout << (i + 1) << "\t" << ob1[i].getName() << "\t\t\t" << ob1[i].getStaff() << "\t\t" << ob1[i].getGender() << "\t" << ob1[i].getAge() << "\t" << ob1[i].getbmi();
						cout << "\n";
					}
				}
			}
		}
	}
	else if (start == 2)//if user choose combined search for bmr
	{
		int begin, AGE, AGE2;
		string Gender;
		cout << "\nSearch by...\n";
		cout << "1.Age\n2.Gender\n3.All Staffs\nOptions:";
		cin >> begin;
		while (begin < 1 || begin >3)
		{
			cout << "Input the correct value.\n";
			cout << "Enter:";
			cin >> begin;
		}
		if (begin == 1)
		{
			cout << "Enter age.Min age:";
			cin >> AGE;
			while (AGE < 18 || AGE>100)
			{
				cout << "Input the correct value.\n";
				cout << "Enter:";
				cin >> AGE;
			}
			cout << "\nMax age:";
			cin >> AGE2;
			while (AGE2 < 18 || AGE2>100)
			{
				cout << "Input the correct value.\n";
				cout << "Enter:";
				cin >> AGE2;
			}
			int enter, value, value2;
			cout << "\n1.BMR less than.\n2.BMR more than.\n";
			cout << "3.BMR less than equals to.\n4.BMR more than equals to.\n";
			cout << "5.BMR within range.\nOptions:";
			cin >> enter;
			while (enter < 1 || enter >5)
			{
				cout << "Input the correct value.\n";
				cout << "Enter:";
				cin >> enter;
			}
			if (enter == 1)
			{
				cout << "Enter value of BMR:";
				cin >> value;
				while (value < 1 || value >5000)
				{
					cout << "Input the correct value.\n";
					cout << "Enter:";
					cin >> value;
				}
				cout << "\nNo\tName\t" << "\tStaffID\t\t" << "Gender\t" << "Age\t" << "BMR\n";
				for (int i = 0; i < val; i++)
				{
					if ((ob1[i].getAge() > AGE) && (ob1[i].getAge() < AGE2))
					{
						if (ob1[i].getbmr() < value)
						{
							cout << (i + 1) << "\t" << ob1[i].getName() << "\t\t\t" << ob1[i].getStaff() << "\t\t" << ob1[i].getGender() << "\t" << ob1[i].getAge() << "\t" << ob1[i].getbmr();
							cout << "\n";
						}
					}
				}
			}
			else if (enter == 2)
			{
				cout << "Enter value of BMR:";
				cin >> value;
				while (value < 1 || value >5000)
				{
					cout << "Input the correct value.\n";
					cout << "Enter:";
					cin >> value;
				}
				cout << "\nNo\tName\t" << "\tStaffID\t\t" << "Gender\t" << "Age\t" << "BMR\n";
				for (int i = 0; i < val; i++)
				{
					if ((ob1[i].getAge() > AGE) && (ob1[i].getAge() < AGE2))
					{
						if (ob1[i].getbmr() > value)
						{
							cout << (i + 1) << "\t" << ob1[i].getName() << "\t\t\t" << ob1[i].getStaff() << "\t\t" << ob1[i].getGender() << "\t" << ob1[i].getAge() << "\t" << ob1[i].getbmr();
							cout << "\n";
						}
					}
				}
			}
			else if (enter == 3)
			{
				cout << "Enter value of BMR:";
				cin >> value;
				while (value < 1 || value >5000)
				{
					cout << "Input the correct value.\n";
					cout << "Enter:";
					cin >> value;
				}
				cout << "\nNo\tName\t" << "\tStaffID\t\t" << "Gender\t" << "Age\t" << "BMR\n";
				for (int i = 0; i < val; i++)
				{
					if ((ob1[i].getAge() > AGE) && (ob1[i].getAge() < AGE2))
					{
						if (ob1[i].getbmr() <= value)
						{
							cout << (i + 1) << "\t" << ob1[i].getName() << "\t\t\t" << ob1[i].getStaff() << "\t\t" << ob1[i].getGender() << "\t" << ob1[i].getAge() << "\t" << ob1[i].getbmr();
							cout << "\n";
						}
					}
				}
			}
			else if (enter == 4)
			{
				cout << "Enter value of BMR:";
				cin >> value;
				while (value < 1 || value >5000)
				{
					cout << "Input the correct value.\n";
					cout << "Enter:";
					cin >> value;
				}
				cout << "\nNo\tName\t" << "\tStaffID\t\t" << "Gender\t" << "Age\t" << "BMR\n";
				for (int i = 0; i < val; i++)
				{
					if ((ob1[i].getAge() > AGE) && (ob1[i].getAge() < AGE2))
					{
						if (ob1[i].getbmr() >= value)
						{
							cout << (i + 1) << "\t" << ob1[i].getName() << "\t\t\t" << ob1[i].getStaff() << "\t\t" << ob1[i].getGender() << "\t" << ob1[i].getAge() << "\t" << ob1[i].getbmr();
							cout << "\n";
						}
					}
				}
			}
			else if (enter == 5)
			{
				cout << "Enter value of BMR:\nMin Value1:";
				cin >> value;
				while (value < 1 || value >5000)
				{
					cout << "Input the correct value.\n";
					cout << "Enter:";
					cin >> value;
				}
				cout << "\nMax Value:";
				cin >> value2;
				while (value2 < 1 || value2 >5000)
				{
					cout << "Input the correct value.\n";
					cout << "Enter:";
					cin >> value2;
				}
				cout << "\nNo\tName\t" << "\tStaffID\t\t" << "Gender\t" << "Age\t" << "BMR\n";
				for (int i = 0; i < val; i++)
				{
					if ((ob1[i].getAge() > AGE) && (ob1[i].getAge() < AGE2))
					{
						if ((ob1[i].getbmr() > value) && (ob1[i].getbmr() < value2))
						{
							cout << (i + 1) << "\t" << ob1[i].getName() << "\t\t\t" << ob1[i].getStaff() << "\t\t" << ob1[i].getGender() << "\t" << ob1[i].getAge() << "\t" << ob1[i].getbmr();
							cout << "\n";
						}
					}
				}
			}
		}
		else if (begin == 2)
		{
			cout << "Enter gender.'Male' for male and 'Female' for female.\nGender:";
			cin >> Gender;
			while (Gender != "Male" && Gender != "Female")
			{
				cout << "Input the correct value.\n";
				cout << "'Male' for male and 'Female' for female.\n";
				cout << "Enter:";
				cin >> Gender;
			}
			int enter, value, value2;
			cout << "\n1.BMR less than.\n2.BMR more than.\n";
			cout << "3.BMR less than equals to.\n4.BMR more than equals to.\n";
			cout << "5.BMR within range.\nOptions:";
			cin >> enter;
			while (enter < 1 || enter >5)
			{
				cout << "Input the correct value.\n";
				cout << "Enter:";
				cin >> enter;
			}
			if (enter == 1)
			{
				cout << "Enter value of BMR:";
				cin >> value;
				while (value < 1 || value >5000)
				{
					cout << "Input the correct value.\n";
					cout << "Enter:";
					cin >> value;
				}
				cout << "\nNo\tName\t" << "\tStaffID\t\t" << "Gender\t" << "Age\t" << "BMR\n";
				for (int i = 0; i < val; i++)
				{
					if (Gender == ob1[i].getGender())
					{
						if (ob1[i].getbmr() < value)
						{
							cout << (i + 1) << "\t" << ob1[i].getName() << "\t\t\t" << ob1[i].getStaff() << "\t\t" << ob1[i].getGender() << "\t" << ob1[i].getAge() << "\t" << ob1[i].getbmr();
							cout << "\n";
						}
					}
				}
			}
			else if (enter == 2)
			{
				cout << "Enter value of BMR:";
				cin >> value;
				while (value < 1 || value >5000)
				{
					cout << "Input the correct value.\n";
					cout << "Enter:";
					cin >> value;
				}
				cout << "\nNo\tName\t" << "\tStaffID\t\t" << "Gender\t" << "Age\t" << "BMR\n";
				for (int i = 0; i < val; i++)
				{
					if (Gender == ob1[i].getGender())
					{
						if (ob1[i].getbmr() > value)
						{
							cout << (i + 1) << "\t" << ob1[i].getName() << "\t\t\t" << ob1[i].getStaff() << "\t\t" << ob1[i].getGender() << "\t" << ob1[i].getAge() << "\t" << ob1[i].getbmr();
							cout << "\n";
						}
					}
				}
			}
			else if (enter == 3)
			{
				cout << "Enter value of BMR:";
				cin >> value;
				while (value < 1 || value >5000)
				{
					cout << "Input the correct value.\n";
					cout << "Enter:";
					cin >> value;
				}
				cout << "\nNo\tName\t" << "\tStaffID\t\t" << "Gender\t" << "Age\t" << "BMR\n";
				for (int i = 0; i < val; i++)
				{
					if (Gender == ob1[i].getGender())
					{
						if (ob1[i].getbmr() <= value)
						{
							cout << (i + 1) << "\t" << ob1[i].getName() << "\t\t\t" << ob1[i].getStaff() << "\t\t" << ob1[i].getGender() << "\t" << ob1[i].getAge() << "\t" << ob1[i].getbmr();
							cout << "\n";
						}
					}
				}
			}
			else if (enter == 4)
			{
				cout << "Enter value of BMR:";
				cin >> value;
				while (value < 1 || value >5000)
				{
					cout << "Input the correct value.\n";
					cout << "Enter:";
					cin >> value;
				}
				cout << "\nNo\tName\t" << "\tStaffID\t\t" << "Gender\t" << "Age\t" << "BMR\n";
				for (int i = 0; i < val; i++)
				{
					if (Gender == ob1[i].getGender())
					{
						if (ob1[i].getbmr() >= value)
						{
							cout << (i + 1) << "\t" << ob1[i].getName() << "\t\t\t" << ob1[i].getStaff() << "\t\t" << ob1[i].getGender() << "\t" << ob1[i].getAge() << "\t" << ob1[i].getbmr();
							cout << "\n";
						}
					}
				}
			}
			else if (enter == 5)
			{
				cout << "Enter value of BMR:\nMin Value1:";
				cin >> value;
				while (value < 1 || value >5000)
				{
					cout << "Input the correct value.\n";
					cout << "Enter:";
					cin >> value;
				}
				cout << "\nMax Value:";
				cin >> value2;
				while (value2 < 1 || value2 >5000)
				{
					cout << "Input the correct value.\n";
					cout << "Enter:";
					cin >> value2;
				}
				cout << "\nNo\tName\t" << "\tStaffID\t\t" << "Gender\t" << "Age\t" << "BMR\n";
				for (int i = 0; i < val; i++)
				{
					if (Gender == ob1[i].getGender())
					{
						if ((ob1[i].getbmr() > value) && (ob1[i].getbmr() < value2))
						{
							cout << (i + 1) << "\t" << ob1[i].getName() << "\t\t\t" << ob1[i].getStaff() << "\t\t" << ob1[i].getGender() << "\t" << ob1[i].getAge() << "\t" << ob1[i].getbmr();
							cout << "\n";
						}
					}
				}
			}
		}
		else if (begin == 3)
		{
			int enter, value, value2;
			cout << "\n1.BMR less than.\n2.BMR more than.\n";
			cout << "3.BMR less than equals to.\n4.BMR more than equals to.\n";
			cout << "5.BMR within range.\nOptions:";
			cin >> enter;
			while (enter < 1 || enter >5)
			{
				cout << "Input the correct value.\n";
				cout << "Enter:";
				cin >> enter;
			}
			if (enter == 1)
			{
				cout << "Enter value of BMR:";
				cin >> value;
				while (value < 1 || value >5000)
				{
					cout << "Input the correct value.\n";
					cout << "Enter:";
					cin >> value;
				}
				cout << "\nNo\tName\t" << "\tStaffID\t\t" << "Gender\t" << "Age\t" << "BMR\n";
				for (int i = 0; i < val; i++)
				{
					if (ob1[i].getbmr() < value)
					{
						cout << (i + 1) << "\t" << ob1[i].getName() << "\t\t\t" << ob1[i].getStaff() << "\t\t" << ob1[i].getGender() << "\t" << ob1[i].getAge() << "\t" << ob1[i].getbmr();
						cout << "\n";
					}
				}
			}
			else if (enter == 2)
			{
				cout << "Enter value of BMR:";
				cin >> value;
				while (value < 1 || value >5000)
				{
					cout << "Input the correct value.\n";
					cout << "Enter:";
					cin >> value;
				}
				cout << "\nNo\tName\t" << "\tStaffID\t\t" << "Gender\t" << "Age\t" << "BMR\n";
				for (int i = 0; i < val; i++)
				{
					if (ob1[i].getbmr() > value)
					{
						cout << (i + 1) << "\t" << ob1[i].getName() << "\t\t\t" << ob1[i].getStaff() << "\t\t" << ob1[i].getGender() << "\t" << ob1[i].getAge() << "\t" << ob1[i].getbmr();
						cout << "\n";
					}
				}
			}
			else if (enter == 3)
			{
				cout << "Enter value of BMR:";
				cin >> value;
				while (value < 1 || value >5000)
				{
					cout << "Input the correct value.\n";
					cout << "Enter:";
					cin >> value;
				}
				cout << "\nNo\tName\t" << "\tStaffID\t\t" << "Gender\t" << "Age\t" << "BMR\n";
				for (int i = 0; i < val; i++)
				{
					if (ob1[i].getbmr() <= value)
					{
						cout << (i + 1) << "\t" << ob1[i].getName() << "\t\t\t" << ob1[i].getStaff() << "\t\t" << ob1[i].getGender() << "\t" << ob1[i].getAge() << "\t" << ob1[i].getbmr();
						cout << "\n";
					}
				}
			}
			else if (enter == 4)
			{
				cout << "Enter value of BMR:";
				cin >> value;
				while (value < 1 || value >5000)
				{
					cout << "Input the correct value.\n";
					cout << "Enter:";
					cin >> value;
				}
				cout << "\nNo\tName\t" << "\tStaffID\t\t" << "Gender\t" << "Age\t" << "BMR\n";
				for (int i = 0; i < val; i++)
				{
					if (ob1[i].getbmr() >= value)
					{
						cout << (i + 1) << "\t" << ob1[i].getName() << "\t\t\t" << ob1[i].getStaff() << "\t\t" << ob1[i].getGender() << "\t" << ob1[i].getAge() << "\t" << ob1[i].getbmr();
						cout << "\n";
					}
				}
			}
			else if (enter == 5)
			{
				cout << "Enter value of BMR:\nMin Value1:";
				cin >> value;
				while (value < 1 || value >5000)
				{
					cout << "Input the correct value.\n";
					cout << "Enter:";
					cin >> value;
				}
				cout << "\nMax Value:";
				cin >> value2;
				while (value2 < 1 || value2 >5000)
				{
					cout << "Input the correct value.\n";
					cout << "Enter:";
					cin >> value2;
				}
				cout << "\nNo\tName\t" << "\tStaffID\t\t" << "Gender\t" << "Age\t" << "BMR\n";
				for (int i = 0; i < val; i++)
				{
					if ((ob1[i].getbmr() > value) && (ob1[i].getbmr() < value2))
					{
						cout << (i + 1) << "\t" << ob1[i].getName() << "\t\t\t" << ob1[i].getStaff() << "\t\t" << ob1[i].getGender() << "\t" << ob1[i].getAge() << "\t" << ob1[i].getbmr();
						cout << "\n";
					}
				}
			}
		}
	}
	else if (start == 3)//if user choose combined search for rmr
	{
		int begin, AGE, AGE2;
		string Gender;
		cout << "\nSearch by...\n";
		cout << "1.Age\n2.Gender\n3.ALL staff.\nOptions:";
		cin >> begin;
		while (begin < 1 || begin >3)
		{
			cout << "Input the correct value.\n";
			cout << "Enter:";
			cin >> begin;
		}
		if (begin == 1)
		{
			cout << "Enter age.Min age:";
			cin >> AGE;
			while (AGE < 18 || AGE >100)
			{
				cout << "Input the correct value.\n";
				cout << "Enter:";
				cin >> AGE;
			}
			cout << "\nMax age:";
			cin >> AGE2;
			while (AGE2 < 18 || AGE2 >100)
			{
				cout << "Input the correct value.\n";
				cout << "Enter:";
				cin >> AGE2;
			}
			int enter, value, value2;
			cout << "\n1.RMR less than.\n2.RMR more than.\n";
			cout << "3.RMR less than equals to.\n4.RMR more than equals to.\n";
			cout << "5.RMR within range.\nOptions:";
			cin >> enter;
			while (enter < 1 || enter >5)
			{
				cout << "Input the correct value.\n";
				cout << "Enter:";
				cin >> enter;
			}
			if (enter == 1)
			{
				cout << "Enter value of RMR:";
				cin >> value;
				while (value < 1 || value >5000)
				{
					cout << "Input the correct value.\n";
					cout << "Enter:";
					cin >> value;
				}
				cout << "\nNo\tName\t" << "\tStaffID\t\t" << "Gender\t" << "Age\t" << "RMR\n";
				for (int i = 0; i < val; i++)
				{
					if ((ob1[i].getAge() > AGE) && (ob1[i].getAge() < AGE2))
					{
						if (ob1[i].getrmr() < value)
						{
							cout << (i + 1) << "\t" << ob1[i].getName() << "\t\t\t" << ob1[i].getStaff() << "\t\t" << ob1[i].getGender() << "\t" << ob1[i].getAge() << "\t" << ob1[i].getrmr();
							cout << "\n";
						}
					}
				}
			}
			else if (enter == 2)
			{
				cout << "Enter value of RMR:";
				cin >> value;
				while (value < 1 || value >5000)
				{
					cout << "Input the correct value.\n";
					cout << "Enter:";
					cin >> value;
				}
				cout << "\nNo\tName\t" << "\tStaffID\t\t" << "Gender\t" << "Age\t" << "RMR\n";
				for (int i = 0; i < val; i++)
				{
					if ((ob1[i].getAge() > AGE) && (ob1[i].getAge() < AGE2))
					{
						if (ob1[i].getrmr() > value)
						{
							cout << (i + 1) << "\t" << ob1[i].getName() << "\t\t\t" << ob1[i].getStaff() << "\t\t" << ob1[i].getGender() << "\t" << ob1[i].getAge() << "\t" << ob1[i].getrmr();
							cout << "\n";
						}
					}
				}
			}
			else if (enter == 3)
			{
				cout << "Enter value of RMR:";
				cin >> value;
				while (value < 1 || value >5000)
				{
					cout << "Input the correct value.\n";
					cout << "Enter:";
					cin >> value;
				}
				cout << "\nNo\tName\t" << "\tStaffID\t\t" << "Gender\t" << "Age\t" << "RMR\n";
				for (int i = 0; i < val; i++)
				{
					if ((ob1[i].getAge() > AGE) && (ob1[i].getAge() < AGE2))
					{
						if (ob1[i].getrmr() <= value)
						{
							cout << (i + 1) << "\t" << ob1[i].getName() << "\t\t\t" << ob1[i].getStaff() << "\t\t" << ob1[i].getGender() << "\t" << ob1[i].getAge() << "\t" << ob1[i].getrmr();
							cout << "\n";
						}
					}
				}
			}
			else if (enter == 4)
			{
				cout << "Enter value of RMR:";
				cin >> value;
				while (value < 1 || value >5000)
				{
					cout << "Input the correct value.\n";
					cout << "Enter:";
					cin >> value;
				}
				cout << "\nNo\tName\t" << "\tStaffID\t\t" << "Gender\t" << "Age\t" << "RMR\n";
				for (int i = 0; i < val; i++)
				{
					if ((ob1[i].getAge() > AGE) && (ob1[i].getAge() < AGE2))
					{
						if (ob1[i].getrmr() >= value)
						{
							cout << (i + 1) << "\t" << ob1[i].getName() << "\t\t\t" << ob1[i].getStaff() << "\t\t" << ob1[i].getGender() << "\t" << ob1[i].getAge() << "\t" << ob1[i].getrmr();
							cout << "\n";
						}
					}
				}
			}
			else if (enter == 5)
			{
				cout << "Enter value of RMR:\nMin Value1:";
				cin >> value;
				while (value < 1 || value >5000)
				{
					cout << "Input the correct value.\n";
					cout << "Enter:";
					cin >> value;
				}
				cout << "\nMax Value:";
				cin >> value2;
				while (value2 < 1 || value2 >5000)
				{
					cout << "Input the correct value.\n";
					cout << "Enter:";
					cin >> value2;
				}
				cout << "\nNo\tName\t" << "\tStaffID\t\t" << "Gender\t" << "Age\t" << "RMR\n";
				for (int i = 0; i < val; i++)
				{
					if ((ob1[i].getAge() > AGE) && (ob1[i].getAge() < AGE2))
					{
						if ((ob1[i].getrmr() > value) && (ob1[i].getrmr() < value2))
						{
							cout << (i + 1) << "\t" << ob1[i].getName() << "\t\t\t" << ob1[i].getStaff() << "\t\t" << ob1[i].getGender() << "\t" << ob1[i].getAge() << "\t" << ob1[i].getrmr();
							cout << "\n";
						}
					}
				}
			}
		}
		else if (begin == 2)
		{
			cout << "Enter gender.'Male' for male and 'Female' for female.\nGender:";
			cin >> Gender;
			while (Gender != "Male" && Gender != "Female")
			{
				cout << "Input the correct value.\n";
				cout << "'Male' for male and 'Female' for female.\n";
				cout << "Enter:";
				cin >> Gender;
			}
			int enter, value, value2;
			cout << "\n1.RMR less than.\n2.RMR more than.\n";
			cout << "3.RMR less than equals to.\n4.RMR more than equals to.\n";
			cout << "5.RMR within range.\nOptions:";
			cin >> enter;
			while (enter < 1 || enter >5)
			{
				cout << "Input the correct value.\n";
				cout << "Enter:";
				cin >> enter;
			}
			if (enter == 1)
			{
				cout << "Enter value of RMR:";
				cin >> value;
				while (value < 1 || value >5000)
				{
					cout << "Input the correct value.\n";
					cout << "Enter:";
					cin >> value;
				}
				cout << "\nNo\tName\t" << "\tStaffID\t\t" << "Gender\t" << "Age\t" << "RMR\n";
				for (int i = 0; i < val; i++)
				{
					if (Gender == ob1[i].getGender())
					{
						if (ob1[i].getrmr() < value)
						{
							cout << (i + 1) << "\t" << ob1[i].getName() << "\t\t\t" << ob1[i].getStaff() << "\t\t" << ob1[i].getGender() << "\t" << ob1[i].getAge() << "\t" << ob1[i].getrmr();
							cout << "\n";
						}
					}
				}
			}
			else if (enter == 2)
			{
				cout << "Enter value of RMR:";
				cin >> value;
				while (value < 1 || value >5000)
				{
					cout << "Input the correct value.\n";
					cout << "Enter:";
					cin >> value;
				}
				cout << "\nNo\tName\t" << "\tStaffID\t\t" << "Gender\t" << "Age\t" << "RMR\n";
				for (int i = 0; i < val; i++)
				{
					if (Gender == ob1[i].getGender())
					{
						if (ob1[i].getrmr() > value)
						{
							cout << (i + 1) << "\t" << ob1[i].getName() << "\t\t\t" << ob1[i].getStaff() << "\t\t" << ob1[i].getGender() << "\t" << ob1[i].getAge() << "\t" << ob1[i].getrmr();
							cout << "\n";
						}
					}
				}
			}
			else if (enter == 3)
			{
				cout << "Enter value of RMR:";
				cin >> value;
				while (value < 1 || value >5000)
				{
					cout << "Input the correct value.\n";
					cout << "Enter:";
					cin >> value;
				}
				cout << "\nNo\tName\t" << "\tStaffID\t\t" << "Gender\t" << "Age\t" << "RMR\n";
				for (int i = 0; i < val; i++)
				{
					if (Gender == ob1[i].getGender())
					{
						if (ob1[i].getrmr() <= value)
						{
							cout << (i + 1) << "\t" << ob1[i].getName() << "\t\t\t" << ob1[i].getStaff() << "\t\t" << ob1[i].getGender() << "\t" << ob1[i].getAge() << "\t" << ob1[i].getrmr();
							cout << "\n";
						}
					}
				}
			}
			else if (enter == 4)
			{
				cout << "Enter value of RMR:";
				cin >> value;
				while (value < 1 || value >5000)
				{
					cout << "Input the correct value.\n";
					cout << "Enter:";
					cin >> value;
				}
				cout << "\nNo\tName\t" << "\tStaffID\t\t" << "Gender\t" << "Age\t" << "RMR\n";
				for (int i = 0; i < val; i++)
				{
					if (Gender == ob1[i].getGender())
					{
						if (ob1[i].getrmr() >= value)
						{
							cout << (i + 1) << "\t" << ob1[i].getName() << "\t\t\t" << ob1[i].getStaff() << "\t\t" << ob1[i].getGender() << "\t" << ob1[i].getAge() << "\t" << ob1[i].getrmr();
							cout << "\n";
						}
					}
				}
			}
			else if (enter == 5)
			{
				cout << "Enter value of RMR:\nMin Value1:";
				cin >> value;
				while (value < 1 || value >5000)
				{
					cout << "Input the correct value.\n";
					cout << "Enter:";
					cin >> value;
				}
				cout << "\nMax Value:";
				cin >> value2;
				while (value2 < 1 || value2 >5000)
				{
					cout << "Input the correct value.\n";
					cout << "Enter:";
					cin >> value2;
				}
				cout << "\nNo\tName\t" << "\tStaffID\t\t" << "Gender\t" << "Age\t" << "RMR\n";
				for (int i = 0; i < val; i++)
				{
					if (Gender == ob1[i].getGender())
					{
						if ((ob1[i].getrmr() > value) && (ob1[i].getrmr() < value2))
						{
							cout << (i + 1) << "\t" << ob1[i].getName() << "\t\t\t" << ob1[i].getStaff() << "\t\t" << ob1[i].getGender() << "\t" << ob1[i].getAge() << "\t" << ob1[i].getrmr();
							cout << "\n";
						}
					}
				}
			}
		}
		else if (begin == 3)
		{
			int enter, value, value2;
			cout << "\n1.RMR less than.\n2.RMR more than.\n";
			cout << "3.RMR less than equals to.\n4.RMR more than equals to.\n";
			cout << "5.RMR within range.\nOptions:";
			cin >> enter;
			while (enter < 1 || enter >5)
			{
				cout << "Input the correct value.\n";
				cout << "Enter:";
				cin >> enter;
			}
			if (enter == 1)
			{
				cout << "Enter value of RMR:";
				cin >> value;
				while (value < 1 || value >5000)
				{
					cout << "Input the correct value.\n";
					cout << "Enter:";
					cin >> value;
				}
				cout << "\nNo\tName\t" << "\tStaffID\t\t" << "Gender\t" << "Age\t" << "RMR\n";
				for (int i = 0; i < val; i++)
				{
					if (ob1[i].getrmr() < value)
					{
						cout << (i + 1) << "\t" << ob1[i].getName() << "\t\t\t" << ob1[i].getStaff() << "\t\t" << ob1[i].getGender() << "\t" << ob1[i].getAge() << "\t" << ob1[i].getrmr();
						cout << "\n";
					}
				}
			}
			else if (enter == 2)
			{
				cout << "Enter value of RMR:";
				cin >> value;
				while (value < 1 || value >5000)
				{
					cout << "Input the correct value.\n";
					cout << "Enter:";
					cin >> value;
				}
				cout << "\nNo\tName\t" << "\tStaffID\t\t" << "Gender\t" << "Age\t" << "RMR\n";
				for (int i = 0; i < val; i++)
				{
					if (ob1[i].getrmr() > value)
					{
						cout << (i + 1) << "\t" << ob1[i].getName() << "\t\t\t" << ob1[i].getStaff() << "\t\t" << ob1[i].getGender() << "\t" << ob1[i].getAge() << "\t" << ob1[i].getrmr();
						cout << "\n";
					}
				}
			}
			else if (enter == 3)
			{
				cout << "Enter value of RMR:";
				cin >> value;
				while (value < 1 || value >5000)
				{
					cout << "Input the correct value.\n";
					cout << "Enter:";
					cin >> value;
				}
				cout << "\nNo\tName\t" << "\tStaffID\t\t" << "Gender\t" << "Age\t" << "RMR\n";
				for (int i = 0; i < val; i++)
				{
					if (ob1[i].getrmr() <= value)
					{
						cout << (i + 1) << "\t" << ob1[i].getName() << "\t\t\t" << ob1[i].getStaff() << "\t\t" << ob1[i].getGender() << "\t" << ob1[i].getAge() << "\t" << ob1[i].getrmr();
						cout << "\n";
					}
				}
			}
			else if (enter == 4)
			{
				cout << "Enter value of RMR:";
				cin >> value;
				while (value < 1 || value >5000)
				{
					cout << "Input the correct value.\n";
					cout << "Enter:";
					cin >> value;
				}
				cout << "\nNo\tName\t" << "\tStaffID\t\t" << "Gender\t" << "Age\t" << "RMR\n";
				for (int i = 0; i < val; i++)
				{
					if (ob1[i].getrmr() >= value)
					{
						cout << (i + 1) << "\t" << ob1[i].getName() << "\t\t\t" << ob1[i].getStaff() << "\t\t" << ob1[i].getGender() << "\t" << ob1[i].getAge() << "\t" << ob1[i].getrmr();
						cout << "\n";
					}
				}
			}
			else if (enter == 5)
			{
				cout << "Enter value of RMR:\nMin Value1:";
				cin >> value;
				while (value < 1 || value >5000)
				{
					cout << "Input the correct value.\n";
					cout << "Enter:";
					cin >> value;
				}
				cout << "\nMax Value:";
				cin >> value2;
				while (value2 < 1 || value2 >5000)
				{
					cout << "Input the correct value.\n";
					cout << "Enter:";
					cin >> value2;
				}
				cout << "\nNo\tName\t" << "\tStaffID\t\t" << "Gender\t" << "Age\t" << "RMR\n";
				for (int i = 0; i < val; i++)
				{
					if ((ob1[i].getrmr() > value) && (ob1[i].getrmr() < value2))
					{
						cout << (i + 1) << "\t" << ob1[i].getName() << "\t\t\t" << ob1[i].getStaff() << "\t\t" << ob1[i].getGender() << "\t" << ob1[i].getAge() << "\t" << ob1[i].getrmr();
						cout << "\n";
					}
				}
			}
		}
	}
	system("PAUSE");//pausing command prompt
}

void genstats(staff ob1[], int val)
{
	system("CLS");//clearing the command prompt
	int age1, age2, under = 0, normal = 0, over = 0, obese = 0, x = 0, enter;
	double avebmi = 0, avebmr = 0, avermr = 0;//average for bmi,bmr,rmr
	string gender;//declare variable
	cout << "Which type of general data do you want?\n";
	cout << "1.All staffs\n2.Staffs with age and gender requirement.\n";
	cin >> enter;//asking user to  choose how to display information.
	//either all staffs or with age and gender requirement.
	while (enter < 1 || enter >2)
	{//input validation
		cout << "Input the correct value.\n";
		cout << "Enter:";
		cin >> enter;
	}

	if (enter == 1)//if user choose all staffs.
	{
		system("CLS");//clearing command prompt.
		for (int i = 0; i < val; i++)
		{//loop to calculate average bmi,bmr and rmr.
			avebmi = avebmi + ob1[i].getbmi();
			avebmr = avebmr + ob1[i].getbmr();
			avermr = avermr + ob1[i].getrmr();
			x = x + 1;//divisor to divide total bmi,bmr,rmr.
		}
		avebmi = avebmi / x;//average bmi
		avebmr = avebmr / x;//average bmr
		avermr = avermr / x;//average rmr
		cout << "\n1.Average BMI for staffs is " << avebmi << "." << endl;//displaying all average
		cout << "\n2.Average BMR for staffs is " << avebmr << "." << endl;//bmi,bmr and rmr
		cout << "\n3.Average RMR for staffs is " << avermr << "." << endl;

		for (int i = 0; i < val; i++)
		{//loop to determine staff for each weight catogary
			if (ob1[i].getbmi() < 20)
			{
				under = under + 1;
			}
			else if ((ob1[i].getbmi() < 25) && (ob1[i].getbmi() >= 20))
			{
				normal = normal + 1;
			}
			else if ((ob1[i].getbmi() < 30) && (ob1[i].getbmi() >= 25))
			{
				over = over + 1;
			}
			else
			{
				obese = obese + 1;
			}
		}
		//displaying number of staff for each weight catogary
		cout << "\n1.The number of people in underweight catogary is " << under << "." << endl;
		cout << "\n2.The number of people in normalweight catogary is " << normal << "." << endl;
		cout << "\n3.The number of people in overweight catogary is " << over << "." << endl;
		cout << "\n4.The number of people in obese catogary is " << obese << "." << endl;
		system("PAUSE");//pausing command prompt
	}
	else if (enter == 2)//if user choose general stats for staff with requirements
	{
		system("CLS");//clearing command prompt
		cout << "Enter age range.\nMin age:";
		cin >> age1;//user entering min age for age range
		while (age1 < 18 || age1>100)
		{//input validation for age
			cout << "Input the correct value.\n";
			cout << "Enter:";
			cin >> age1;
		}
		cout << "Max age:";
		cin >> age2;//user entering max age for age range
		while (age2 < 18 || age2>100)
		{//input validation for age
			cout << "Input the correct value.\n";
			cout << "Enter:";
			cin >> age2;
		}
		cout << "Enter gender.'Male' for male and 'Female' for female:";
		cin >> gender;//asking for gender of staffs
		while (gender != "Male" && gender != "Female")
		{//input validation for gender
			cout << "Input the correct value.\n";
			cout << "'M' for male and 'F' for female.\n";
			cout << "Enter:";
			cin >> gender;
		}

		for (int i = 0; i < val; i++)
		{//loop to search for number of people in each weight catogary 
		 //within the age range and gender.
			if (gender == ob1[i].getGender())
			{//searching array for data with same gender
				if ((ob1[i].getAge() > age1) && (ob1[i].getAge() < age2))
				{//searching array for data within the range.
					if (ob1[i].getbmi() < 20)
					{
						under = under + 1;
					}
					else if ((ob1[i].getbmi() < 25) && (ob1[i].getbmi() >= 20))
					{
						normal = normal + 1;
					}
					else if ((ob1[i].getbmi() < 30) && (ob1[i].getbmi() >= 25))
					{
						over = over + 1;
					}
					else
					{
						obese = obese + 1;
					}
					avebmi = avebmi + ob1[i].getbmi();//calculating average bmi.
					avebmr = avebmr + ob1[i].getbmr();//calculating average bmr.
					avermr = avermr + ob1[i].getrmr();//calculating average rmr.
					x = x + 1;//divisor for average
				}
			}
		}
		avebmi = avebmi / x;//calculating average bmi.
		avebmr = avebmr / x;//calculating average bmr.
		avermr = avermr / x;//calculating average rmr.
		//displaying every processed data in this loop.
		cout << "\nAge range:" << age1 << "-" << age2 << "\nGender:" << gender << ".\n";
		cout << "Average BMI:" << avebmi << endl;
		cout << "Average BMR:" << avebmr << endl;
		cout << "Average RMR:" << avermr << endl;
		cout << "\n1)The number of people in underweight catogary is " << under << "." << endl;
		cout << "\n2)The number of people in normalweight catogary is " << normal << "." << endl;
		cout << "\n3)The number of people in overweight catogary is " << over << "." << endl;
		cout << "\n4)The number of people in obese catogary is " << obese << "." << endl;
		system("PAUSE");//pausing command prompt.
	}
}

void staff::health()
{
	system("CLS");//clearing command prompt
	double calc, calc2, height, ideal, days;
	height = (getHeight() / 2.54) - 60;//convert height to inches and sub with 5feet.
	ideal = 50 + (height * 2.3);//formula to find ideal weight 
	//displaying all data within the search.
	cout << "\nName: " << getName() << endl;
	cout << "Staff ID: " << getStaff() << endl;
	cout << "Gender: " << getGender() << endl;
	cout << "Date Of Birth: " << getdate() << getdate2() << "/" << getmonth() << getmonth2() << "/" << getyear() << endl;
	cout << "Age: " << getAge() << endl;
	cout << "Weight: " << getWeight() << endl;
	cout << "Height: " << getHeight() << endl;
	cout << "BMI: " << getbmi() << endl;
	cout << "BMR: " << getbmr() << endl;
	cout << "RMR: " << getrmr() << endl;

	if (getbmi() < 20)
	{
		cout << "You are in underweight catogary.\n";
		calc = (getbmr() * 1.3) * 1.25;//formula for calories
		calc2 = (getbmr() * 1.3) * 1.75;//formula for calories
		days = (ideal - getWeight()) / (0.5 / 7);//number of days to reach ideal weight.
		cout << "Your ideal weight is " << ideal << "kg.\n";
		cout << "You need to increase your weight.\n";//displaying advice
		cout << "You need to consume at least " << calc << " to " << calc2 << " calories everyday\n";
		cout << " until you reach your ideal weight.\n";
		cout << "This will help you to reach your goal in " << days << "days.\n";
	}
	else if ((getbmi() < 25) && (getbmi() >= 20))
	{
		cout << "\nYou are in normalweight catogary.\n";
		calc = (getbmr() * 1.3);//formula for calories.
		cout << "Your ideal weight is " << ideal << "kg.\n";//display ideal weight
		cout << "You are in the ideal weight catogary.\n";//display advice
		cout << "You need to consume at least " << calc << " calories everyday\n";
		cout << " to maintain your ideal weight.\n";
	}
	else if ((getbmi() < 30) && (getbmi() >= 25))
	{
		cout << "You are in overweight catogary.\n";
		calc = (getbmr() * 1.3) * 0.75;//formula calories
		days = (getWeight() - ideal) / (0.5 / 7);//number of days to reach ideal weight.
		cout << "Your ideal weight is " << ideal << "kg.\n";//display ideal weight
		cout << "\nYou need to consume only " << calc << " calories everyday\n";
		cout << " until you reach your ideal weight.\n";//display advice.
		cout << "This will help you to reach your goal in " << days << "days.\n";
		cout << "You must not lose weight more than that because of its negative health effects.\n";
	}
	else
	{
		cout << "You are in obese catogary.\n";
		calc = (getbmr() * 1.3) * 0.75;//formula calories
		days = (getWeight() - ideal) / (0.5 / 7);//number of days to reach ideal weight.
		cout << "Your ideal weight is " << ideal << "kg.\n";//display ideal weight
		cout << "\nYou need to consume only " << calc << " calories everyday\n";
		cout << " until you reach your ideal weight.\n";//display advice
		cout << "This will help you to reach your goal in " << days << "days.\n";
		cout << "You must not lose weight more than that because of its negative health effects.\n";
	}
	system("PAUSE");//pausing command prompt
}

void output(staff ob1[], int val)
{
	ofstream OutputFile;//declaring output file
	OutputFile.open("output.txt", ios::out);//opening output file

	if (OutputFile)
	{
		for (int i = 0; i < val; i++) {
			//loop to display all staffs data in output file.
			OutputFile << left << setw(30) << ob1[i].getName() << "\t" << left << setw(12) << ob1[i].getStaff() << "\t" << left << setw(6) << ob1[i].getGender() << "\t";
			OutputFile << internal << setw(3) << ob1[i].getAge() << "\t" << internal<< setw(2) << ob1[i].getWeight() << "\t" << internal << setw(3) << ob1[i].getHeight() << "\t";
			OutputFile << internal << setw(1) << ob1[i].getdate() << internal << setw(1) << ob1[i].getdate2() << "/" << internal << setw(1) << ob1[i].getmonth();
			OutputFile << internal << setw(1) << ob1[i].getmonth2() << "/" << internal << setw(4) << ob1[i].getyear() << "\t";
			OutputFile << right << setw(10) << ob1[i].getbmi() << "\t" << right << setw(10) << ob1[i].getbmr() << "\t" << right << setw(10) << ob1[i].getrmr() << "\n";
		}
	}
	OutputFile.close();
}

staff::staff()//constructor
{
	age = 0;
	bmi = 0;
	bmr = 0;
	rmr = 0;
	year = 0;
	date = " "; date2 = " ";
	month = " "; month2 = " ";
}

staff::~staff()//destructor
{
	age = 0;
	bmi = 0;
	bmr = 0;
	rmr = 0;
	year = 0;
	date = " "; date2 = " ";
	month = " "; month2 = " ";
}

