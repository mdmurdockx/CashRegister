//
//  RandomChange.cpp
//  CashRegister
//
//  Created by Michael Murdock on 09/19/2016.
//  Copyright © 2016 Michael Murdock. All rights reserved.
//

#include <cstdlib>
#include "RandomChange.hpp"

int& RandomChange::DispenseChange(int iAmt)
{

	while(iAmt > 0)
	{
		int i = 0;
		while (iAmt > iDenomAmt[i])
			i++;

		int n = 0;
		if (i < 4)
			n = rand() % (5 - i);

		ChangeCount[n]++;
		iAmt -= iDenomAmt[n];
	}

	return(*pChgLst);
}
