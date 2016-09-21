//
//  main.cpp
//  CashRegister
//
//  Created by Michael Murdock on 09/18/2016.
//  Copyright © 2016 Michael Murdock. All rights reserved.
//
// Assumption: By the wording in the description of the problem, it was
// assumed that there was no need for a GUI interface or front end. Since
// input and output were through flat files.
//
// Description: A Class Change was used to dispense the change along with
// a derived child class RandomChange was used dispense change randomly.

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "Change.hpp"

using std::cout;
using std::ifstream;
using std::ofstream;
using std::endl;
using std::string;
using std::stringstream;

const string sDenoninations[] =
{
	" dollar,",
	" quarter,",
	" dime,",
	" nickels,",
	" pennies"
};

int* iChange = NULL;

int main(int argc, const char * argv[])
{
	ifstream ifs;
  ofstream ofs;
	string sLine;
	string sChangeList;
	bool bRandChg = false;
	double dTotal_Amt = 0.0;
	double dPaid_Amt = 0.0;
	double dChange_Amt = 0.0;
	int iAmt = 0;
	Change oChng;

	ifs.open("input.txt");
	ofs.open("output.txt");

	bool b = false;
	if (ifs.is_open())
	{
		b = true;
		cout << "found input file" << endl;
	}

	while (!ifs.eof())
	{
		ifs >> dTotal_Amt >> dPaid_Amt;
		dChange_Amt = dPaid_Amt - dTotal_Amt;
		iAmt = dTotal_Amt * 100;
		bRandChg = (iAmt % 3 ? false : true);
		iChange = &oChng.DispenseChange(bRandChg, iAmt);
		string sChangeGiven = "";
		for (int i = 0; i < 5; i++)
		{
			string s;
			stringstream ss;
			ss << iChange[i];
			sChangeGiven += (iChange[i] ? ss.str() + sDenoninations[i] : "");
		}
		ofs << sChangeGiven << endl;
	}
	ifs.close();
	ofs.close();
	return(0);
}
