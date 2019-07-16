//
//  Convert.h
//  DKW_HW1
//
//  Created by Derrick Ward on 7/15/19.
//  Copyright © 2019 Derrick. All rights reserved.
//

class Convert
{

public:
    Convert();
    void startConversionProgram();
    bool validUserSuppliedNumberBasedOnBase(int number, int base);
    int convertNumberToBase10(int number, int base);
};
