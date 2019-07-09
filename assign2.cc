                         /******************************
                          * Name       : Manoj Veluru  *
                          * Zid        : Z1840907      *
                          * Course     : CSCI689       *
                          * Assignment : 2             *
                         *******************************/

/********Program to print Gregorian calendar for a given month and year*********/

/* Including Required Libraries */
#include<iostream>
#include"function.h" //Included header file
#include<iomanip>
#include<cstdlib>
using std :: cout;
using std :: cin;
using std :: endl;
using std :: exit;
using std :: cerr;

/* Main method to input values and to call a method to print calender */
int main()
{
	int month,year;
	cout<<endl;
	cout<<"Month and Year? ";
	cin>>month>>year;
	/* IF Loop to check for errors */
	if((month>0 && month<=12) && year > 0)
	{
	header(month,year); //Function call to print Calender for given month and year
	}
	else
	{
	  cerr<<"Please input acceptable values in the range month[1-12] and year[>0]"<<endl;
	  exit(0);
	}
	cout<<endl;
	return 0;
}
