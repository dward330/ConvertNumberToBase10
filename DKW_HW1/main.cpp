//
//  main.cpp
//  DKW_HW1
//
//  Created by Derrick Ward on 7/15/19.
//  Copyright © 2019 Derrick. All rights reserved.
//

#include <iostream>
#include <cmath>
#include "Convert.h"

using std::cout;
using std::cin;
using std::endl;

int main(int argc, const char * argv[]) {
    Convert convertProgram;
    
    int numberToConvert = 0;
    int baseOfNumberToConvert = 10;
    int base10Value = 0;
    
    // Prompt the user for the number they would like to convert
    cout << "Please enter the number you would like to convert: ";
    cin >> numberToConvert;
    
    // Prompt the user for the base of the number they previously supplied
    cout << "\nPlease enter the base of the number you supplied: ";
    cin >> baseOfNumberToConvert;
    
    /* Validate input and Begin Conversion Process */
    int remainingNumbers = numberToConvert; // Will hold a copy of the number to convert
    bool inputWasValid = true; // Will hold whether the user's number input was valid for the base they stated it is in
    
    for(int currentDigitOfFocus = remainingNumbers % 10, digitPlace = 0; remainingNumbers > 0; remainingNumbers = (remainingNumbers / 10), currentDigitOfFocus = remainingNumbers % 10, digitPlace++)
    {
        if (currentDigitOfFocus >= baseOfNumberToConvert)
        {
            cout << "Invalid number found for a base " << baseOfNumberToConvert << " alphabet! -> " << currentDigitOfFocus << endl;
            inputWasValid = false;
        }
        else {
            base10Value += (currentDigitOfFocus * (int)pow((double)baseOfNumberToConvert,(double)digitPlace));
        }
        
        if (!inputWasValid)
        {
            break;
        }
    }
    
    if (inputWasValid)
    {
        cout << numberToConvert << " of base " << baseOfNumberToConvert << " is equal to " << base10Value << " of base 10" << endl;
    }
    
    return 0;
}
