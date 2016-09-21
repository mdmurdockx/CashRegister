//
//  RandomChange.hpp
//  CashRegister
//
//  Created by Michael Murdock on 09/19/2016.
//  Copyright © 2016 Michael Murdock. All rights reserved.
//

#ifndef RandomChange_hpp
#define RandomChange_hpp

#include <stdio.h>
#include <string>
#include "Change.hpp"

using std::string;

class RandomChange : public Change
{
public:
	RandomChange() {};
	~RandomChange() {};

	int& DispenseChange(int iAmt);
};
#endif /* RandomChange_hpp */
