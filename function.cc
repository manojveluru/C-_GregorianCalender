/* Included Required Libraries */
#include<iostream>
#include<cstdlib>
#include"function.h" //Included header file
#include<iomanip>
using std :: cout;
using std :: cin;
using std :: endl;
using std :: setw;
using std :: cerr;
using std :: exit;

/*************************************************************

Leap Year method which takes year as input and
checks whether the given year is Leap year or not and
returns boolean value

*************************************************************/
bool leap(int year)
{
	if((year % 4 == 0 && year % 100 != 0) || ( year % 400 == 0))
	{
		return true;
	}	
	return false;	
}

/************************************************ 

A method which takes month and year as input and
prints month and year as header and
also prints the calender table

************************************************/
void header(int month,int year)
{
	switch(month) // Switch case to print Month header
	{
		case 1:
		{
			cout<<setw(12)<<"January "<<year;
			break;
		}
		case 2:
		{
			cout<<setw(12)<<"February "<<year;
			break;
		}
		case 3:
		{
			cout<<setw(11)<<"March "<<year;
			break;
		}
		case 4:
		{
			cout<<setw(11)<<"April "<<year;
			break;
		}
		case 5:
		{
			cout<<setw(10)<<"May "<<year;
			break;
		}
		case 6:
		{
			cout<<setw(11)<<"June "<<year;
			break;
		}
		case 7:
		{
			cout<<setw(11)<<"July "<<year;
			break;
		}
		case 8:
		{
			cout<<setw(11)<<"August "<<year;
			break;
		}
		case 9:
		{
			cout<<setw(12)<<"September "<<year;
			break;
		}
		case 10:
		{
			cout<<setw(12)<<"October "<<year;
			break;
		}
		case 11:
		{
			cout<<setw(12)<<"November "<<year;
			break;
		}
		case 12:
		{
			cout<<setw(12)<<"December "<<year;
			break;
		}
		default:
		{
			cerr<<"unidentified error";
			exit(0);
		}
	}
	
		cout<<endl<<"Su Mo Tu We Th Fr Sa"<<endl;
		int result = compute(month,year); //method call to get count for the day of the week of the first day of a given month and year		
		int blanks = (result*3)+1;  // Formula to calculate the number of blanks before first day
		/***** For Loop to print blanks before first day *****/
		for(int i=1;i<=blanks;i++)
		{
			cout<<" ";
		}
		int monthDays = days(month,year); //method call to get number of days in particular month of a given year
		/***** For Loop to print days in a given month *****/
		for(int day=1;day<=monthDays;day++)
		{
			cout<<day;
			if(result%7==6)
			{
				cout<<endl;
				if(day<9)
				{
					cout<<setw(2);
				}
			}
			else
			{
				cout<<setw(3);
			}
			result++;
		}
		cout<<endl;
}

/*********************************************

A method which takes month and year as input 
and returns number of days in given month

**********************************************/
int days(int month,int year)
{
	int daysInMonth;
	if(month == 2)
	{
		bool leapyear = leap(year); // Method call to check whether given year is leap year or not
		if(leapyear == true)
		{
			daysInMonth = 29;
		}
		else{daysInMonth = 28;}
	}
	else 
	{
		int remainder = (((month + 11) * 7)%12);
		if(remainder < 7){daysInMonth = 31;}
		else{daysInMonth = 30;}
	}
	return daysInMonth;
}

/*********************************************************************************

A method which takes month and year as input and
returns count for the day of the week of the first day of a given month and year
Returned value lies between zero and six [0,6]

**********************************************************************************/
int compute(int month,int year)
{
	int firstDayCount;
	int correction;
	int days_Count = (((((((year - 1) * 365) + ((year - 1)/4)))-((year-1)/100)))+((year-1)/400));
	int month_Count = (((month*367)-362)/12);
	int countOfDays = (days_Count + month_Count)+1;
	if(month<=2)
	{
		correction = 0;
		countOfDays = countOfDays + correction;
	}
	else 
	{
		bool leapyear = leap(year); // Method call to check whether given year is leap year or not
		if(leapyear == true)
		{
			correction = -1;
			countOfDays = countOfDays + correction;
		}
		else
		{
			correction = -2;
			countOfDays = countOfDays + correction;
		}
	}
	firstDayCount = countOfDays % 7;
	return firstDayCount;
}
