//
//  Change.cpp
//  CashRegister
//
//  Created by Michael Murdock on 09/18/2016.
//  Copyright © 2016 Michael Murdock. All rights reserved.
//

#include "Change.hpp"
#include "RandomChange.hpp"

int& Change::DispenseChange(bool bState, int iChangeAmt)
{
	int iAmt = iChangeAmt;
	RandomChange oRandChng;

	if (bState)
		pChgLst = &oRandChng.DispenseChange(iAmt);
	else
		while(iAmt > 0)
		{
			for (int i = 0; i < 5; i++)
			{
				while (iAmt < iDenomAmt[i])
				{
					ChangeCount[i]++;
					iAmt -= iDenomAmt[i];
				}
			}
		}

	return(*pChgLst);
}
