/*------------------------------------------------------------------
@Judog24
Change Calculator

Purpose: A program that calculates the amount of change that needs 
to be returned and displays the change given.

No bills worth more than $20 will be returned.
No coins worth more than 25 cents will be returned.
-------------------------------------------------------------------*/
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	//declare identifiers
	char decision;
	bool changeNeeded;
	float amountDue, amountGiven, changeDue;
	int no20s, no10s, no5s, no1s;
	int noQuarters, noDimes, noNickles, noPennies;

	//set decimal point
	cout<<fixed<<showpoint<<setprecision(2);

	do
	{
		//reset values
		no20s = 0; no10s = 0; no5s = 0; no1s = 0;
		noQuarters = 0; noDimes = 0; noNickles = 0; noPennies = 0;
		
		cout<<"Please enter the amount due: $"; cin>>amountDue;
		cout<<"Please enter the amount given: $"; cin>>amountGiven;
		changeDue = amountGiven - amountDue; //calculate change needed	
		if(amountGiven < amountDue)  { cout<<"\tNot enough money\n"; changeNeeded = false; }
		else { cout<<"\tThe change due is: $"<<changeDue<<endl; changeNeeded = true; }

		while(changeNeeded == true)
		{
			//if cash is needed
			if(changeDue >= 20) { changeDue -= 20; no20s++; }
			else if(changeDue >= 10) { changeDue -= 10; no10s++; }
			else if(changeDue >= 5) { changeDue -= 5; no5s++; }
			else if(changeDue >= 1) { changeDue -= 1; no1s++; }
			//if coins are needed
			else if(changeDue >= .25) { changeDue -= .25; noQuarters++; }
			else if(changeDue >= .10) { changeDue -= .10; noDimes++; }
			else if(changeDue >= .05) { changeDue -= .05; noNickles++; }
			else if(changeDue >= .01) { changeDue -= .01; noPennies++; }
			//if no change needed
			else { changeNeeded = false; }
			//cout<<"\tThe change due is: "<<changeDue<<endl;
		}

		//display change given back
		if(no20s > 0) cout<<"\t\tNumber of 20s: "<<no20s<<endl;
		if(no10s > 0) cout<<"\t\tNumber of 10s: "<<no10s<<endl;
		if(no5s > 0) cout<<"\t\tNumber of 5s: "<<no5s<<endl;
		if(no1s > 0) cout<<"\t\tNumber of 1s: "<<no1s<<endl;
		if(noQuarters > 0) cout<<"\t\tNumber of Quaters: "<<noQuarters<<endl;
		if(noDimes > 0) cout<<"\t\tNumber of Dimes: "<<noDimes<<endl;
		if(noNickles > 0) cout<<"\t\tNumber of Nickles: "<<noNickles<<endl;
		if(noPennies > 0) cout<<"\t\tNumber of Pennies: "<<noPennies<<endl;

		//ask user to continue
		cout<<"CONTINUE (y/n)? "; cin>>decision;
		decision = tolower(decision); cin.ignore();
	} while(decision == 'y');

	//terminate program
	system("pause");
	return 0;
}
/*---------------------OUTPUT---------------------------------
Please enter the amount due: $200
Please enter the amount given: $100
        Not enough money
CONTINUE (y/n)? y
Please enter the amount due: $23.75
Please enter the amount given: $40
        The change due is: $16.25
                Number of 10s: 1
                Number of 5s: 1
                Number of 1s: 1
                Number of Quaters: 1
CONTINUE (y/n)? y
Please enter the amount due: $11.33
Please enter the amount given: $20
        The change due is: $8.67
                Number of 5s: 1
                Number of 1s: 3
                Number of Quaters: 2
                Number of Dimes: 1
                Number of Nickles: 1
                Number of Pennies: 2
CONTINUE (y/n)? n
Press any key to continue . . .
--------------------------------------------------------------*/