//
//  Change.hpp
//  CashRegister
//
//  Created by Michael Murdock on 09/18/2016.
//  Copyright © 2016 Michael Murdock. All rights reserved.
//

#ifndef Change_hpp
#define Change_hpp

#include <stdio.h>

const int iDenomAmt[] = { 100, 25, 10, 5, 1 };

class Change
{
public:
	Change() {};
	~Change() {};

	virtual int& DispenseChange(bool bState, int iChangeAmt);
	void Gather();
	void Order();

protected:
	int ChangeCount[5] = { 0, 0, 0, 0, 0};
	int* pChgLst = ChangeCount;
};
#endif /* Change_hpp */
