#include<iostream>
#include<string>
#include<iomanip>
#include<fstream>
#include "Fitness.h"
#include "Staff.h"
#include "Personal.h"

using namespace std;

int main()
{
	const int size = 300;//declaring variables
	int count = 0, age = 0, begin = 0, choose = 0, yesno = 0;
	staff ob1[size];
	string filename, filename2, name, gender;
	string id, id1;
	double weight = 0, height = 0, bi = 0, br = 0, rr = 0;
	char option = ' ';

	ifstream dataReadFile, dataReadFile2;//two input files
	cout << "Enter file's name that contains personal info:";
	cout << "\nEnter filename with (.txt) :";
	cin >> filename;

	while (!dataReadFile)//input validation for file name
	{
		system("CLS");
		cout << "Wrong Filename!!!\n";
		cout << "Enter the correct personal file with (.txt) :";
		cin >> filename;
		dataReadFile.open(filename, ios::in);
	}

	dataReadFile.open(filename, ios::in);//opening file that has personal info

	if (dataReadFile)
	{
		for (int i = 0; i < size && (!dataReadFile.eof()); i++)
		{
			dataReadFile >> id;//reading from file and setting it into array object
			dataReadFile.ignore();
			getline(dataReadFile, name, '\t');
			dataReadFile >> gender;
			ob1[i].Data(id, name, gender);
			dataReadFile.ignore();
			count = count + 1;
		}
	}
	dataReadFile.close();//closing personal file
	system("CLS");
	cout << "Enter file's name that contains fitness info:";
	cout << "\nEnter filename with (.txt) :";
	cin >> filename2;

	dataReadFile2.open(filename2, ios::in);//opening fitness file

	while (!dataReadFile2)//input validation for filename
	{
		system("CLS");
		cout << "Wrong Filename!!!\n";
		cout << "Enter the correct fitness file with (.txt) :";
		cin >> filename2;
		dataReadFile2.open(filename2, ios::in);
	}

	if (dataReadFile2)
	{
		for (int i = 0; i < size && (!dataReadFile2.eof()); i++)
		{
			dataReadFile2 >> id1;//reading fitness info and settinginto array object
			dataReadFile2 >> weight;
			dataReadFile2 >> height;
			for (int i = 0; i < size; i++)//because the values in fitness info not arranged properly
			{//for loop used to sort weight and height according to their staffid
				if (id1 == ob1[i].getStaff())
				{
					ob1[i].Data2(weight, height);
				}
			}
		}
	}
	dataReadFile2.close();//closing fitness file

	for (int i = 0; i < count; i++)//calculates and  sets bmi,bmr and rmr value
	{
		ob1[i].calculation();
	}

	cout << "\nType 1 to start the program.\n";
	cin >> begin;//this input is to loop the main menu.User must 1 to reach menu. 

	while (begin != 1)//input validate for input used to reach main menu.
	{
		cout << "Enter the correct input!\n";
		cin >> begin;//this will loop until the 1  is pressed.
	}

	system("CLS");//clearing commmend prom

	while (begin == 1)//loop for main menu
	{
		cout << "\n\n******************\n";
		cout << "Let's Get Fit\n";
		cout << "******************";
		cout << "\n!!!MAIN MENU!!!\n";
		cout << "Enter a number according to the below options.\n";
		cout << "1.Information about staff.\n2.Search\n";
		cout << "3.Statistics\n4.Health Advisor.\n";
		cout << "Options:";//option that are given to user
		cin >> option;//each option will go to different case in switch.

		while (option != '1' && option != '2' && option != '3' && option != '4')
		{//input validation for option.
			cout << "Input the correct value.\n";
			cout << "Options:";
			cin >> option;//it will loop until input is correct
		}

		switch (option)
		{
		case'1': //when user choose option one above
		{
			int yn;
			cout << "Do you want to access data?\n";
			cout << "1.Yes.\n2.No\nOption:";
			cin >> yn;//this input is to create loop whithin the case
			while (yn < 1 || yn>2)//input validation for yn
			{
				cout << "Input the correct value.\n";
				cout << "Options:";
				cin >> yn;//it will loop until input is correct
			}
			while (yn == 1)//loop within the case
			{
				system("CLS");
				cout << "\n\nInformation about staffs\n";
				cout << "1.Update data.\n2.Add new data.\n";//choices given to user
				cout << "3.Display particular staff's data.\n4.Display all data\nOption:";
				cin >> choose;//this input is to call each function.
				//each call fuction has its own usage.
				while (choose < 1 || choose>4)//input validate for choose variable
				{
					cout << "Input the correct value.\n";
					cout << "Options:";
					cin >> choose;
				}

				if (choose == 1)
				{//function called to edit data
					string staffid;//declare variable
					cout << "\nWho's data you want to edit?\n";
					cout << "Enter the staffID of the person you want to edit.\n";
					cin >> staffid;//asking user for staff id whose data they want to edit
					for (int i = 0; i < size; i++)
					{
						if (staffid == ob1[i].getStaff())
						{
							ob1[i].editData();
						}
					}
				}
				else if (choose == 2)
				{
					system("CLS");//clearing command prompt
					int y = 0, x = 0;//y is number of staff user want to add
					//x is the new size of of array(changed using & for val in function)
					cout << "How many new data do you want to add?\n";
					cin >> y;//asking user to input number of new staffs
					while (y < 0 || y>count)//input validation
					{
						cout << "Input the correct value.\n";
						cout << "Enter:";
						cin >> y;
					}
					x = count + y;//changing sizeof array
					for (int i = count; i < x; i++)
					{
						ob1[i].addData();
					}
					count = x;
				}
				else if (choose == 3)
				{//function called to only display particular staff
					displayOne(ob1, count);
				}
				else if (choose == 4)
				{//function called to  display all staff
					for (int i = 0; i < count; i++)
					{
						ob1[i].displayAll();
					}
					system("PAUSE");
				}
				cout << "Do you want to access more data?\n";
				cout << "1.Yes.\n2.No\nOption:";
				cin >> yn;//input for continue looping or to exit the loop
				while (yn < 1 || yn>2)//input validation
				{
					cout << "Input the correct value.\n";
					cout << "Options:";
					cin >> yn;
				}
			}
			break;//exiting the switch
		}
		case'2':
		{
			int yn;
			cout << "Do you want to search data?\n";
			cout << "1.Yes.\n2.No\nOption:";
			cin >> yn;//input to loop case2
			while (yn < 1 || yn>2)//input validation
			{
				cout << "Input the correct value.\n";
				cout << "Options:";
				cin >> yn;
			}

			while (yn == 1) //this is to loop the case 2.
			{
				int enter;//declare variable
				cout << "\nSearch Data.\n***************\n";
				cout << "Enter\n1.Simple search\n2.Combined search\nOption:";
				cin >> enter;//options given to user to call different function
				while (enter < 1 || enter>2)
				{//input validation for enter
					cout << "Input the correct value.\n";
					cout << "Options:";
					cin >> enter;
				}

				if (enter == 1)
				{//function call for simple search
					simple(ob1, count);
				}
				else if (enter == 2)
				{//function call for combined search
					combine(ob1, count);
				}
				cout << "Do you want to search more?\n";
				cout << "1.Yes.\n2.No\nOption:";
				cin >> yn;//input to continue looping or exit it
				while (yn < 1 || yn>2)
				{//input validation
					cout << "Input the correct value.\n";
					cout << "Options:";
					cin >> yn;
				}
			}
			break;//exiting case 2
		}
		case'3':
		{
			int yn;
			cout << "Statistical Informations\n";
			cout << "1.Enter.\n2.Exit\nOption:";
			cin >> yn;//input to loop case3
			while (yn < 1 || yn>2)
			{//input validation
				cout << "Input the correct value.\n";
				cout << "Options:";
				cin >> yn;
			}

			while (yn == 1)//looping case 3
			{
				system("CLS");//clearing command prompt
				cout << "\nStatistical Information\n";
				//calling function for statistical information
				genstats(ob1, count);
				system("PAUSE");//pausing the command prompt
				cout << "Do you want to access for statistical information?\n";
				cout << "1.Yes.\n2.No\nOption:";
				cin >> yn;//input to continue looping or to exit case 3
				while (yn < 1 || yn>2)
				{//input validation
					cout << "Input the correct value.\n";
					cout << "Options:";
					cin >> yn;
				}
			}
			break;//exiting case 3
		}
		case'4':
		{
			int yn;
			cout << "\nHealth Advisor.\n";
			cout << "1.Enter.\n2.Exit\nOption:";
			cin >> yn;//input to loop case 4
			while (yn < 1 || yn>2)
			{//input validaion
				cout << "Input the correct value.\n";
				cout << "Options:";
				cin >> yn;
			}

			while (yn == 1)//looping case 4
			{
				system("CLS");//clearing screen
				cout << "\nHealth Advisor\n";
				string staff;
				int z = 0;
				cout << "\nEnter staff's ID:";//asking user to input staff id.
				cin >> staff;

				for (int i = 0; i < count; i++)
				{
					if (staff == ob1[i].getStaff())
					{
						z = z + 1;
					}
				}
				while (z != 1)
				{
					system("CLS");
					cout << "This staffID does not exist in file.\n";
					cout << "Enter the correct id:";
					cin >> staff;
					for (int i = 0; i < count; i++)
					{
						if (staff == ob1[i].getStaff())
						{
							z = z + 1;
						}
					}
				}
				for (int i = 0; i < count; i++)
				{
					if (staff == ob1[i].getStaff()) { ob1[i].health(); }
				}
				cout << "Do you want to continue using health advisor?\n";
				cout << "1.Yes.\n2.No\nOption:";
				cin >> yn;//input to continue looping or to exit case 4
				while (yn < 1 || yn>2)
				{//input validation
					cout << "Input the correct value.\n";
					cout << "Options:";
					cin >> yn;
				}
			}
			break;//exiting case 4
		}

		}
		system("CLS");//clearing command prompt
		cout << "\n\nLet's Get Fit(Enter number according to below option)\n";
		cout << "1.Back to main menu.\n2.Exit.\nOption:";
		cin >> begin;//input to loop or exit main menu
		while (begin < 1 || begin>2)
		{//input validation
			cout << "Input the correct value.\n";
			cout << "Options:";
			cin >> begin;
		}
		system("CLS");//clearing command prompt
	}
	//calling function which will write all processed data into a file
	output(ob1, count);
	system("CLS");//clearing command prompt
	cout << "\n\nEnd of program.\nThank you for using.\n";//program ends
	system("PAUSE");//pausing command prompt
	return 0;//return value in main is 0	
}

