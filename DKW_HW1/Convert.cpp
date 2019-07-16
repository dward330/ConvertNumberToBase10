//
//  Convert.cpp
//  DKW_HW1
//
//  Created by Derrick Ward on 7/15/19.
//  Copyright © 2019 Derrick. All rights reserved.
//

#include <iostream> // For input and output functionality
#include <cmath>
#include "Convert.h" // Brings in our Convert Class Interface

using std::cout;
using std::cin;
using std::endl;

Convert::Convert()
{
    
}

/* Runs Program To convert user supplied numbers into base 10 equivalents*/
void Convert::startConversionProgram()
{
    int numberToConvert = 0; // Will hold number the user wants to convert to base 10
    int baseOfNumberToConvert = 10; // Will hold the base of the number user wants to convert
    
    // Prompt the user for the number they would like to convert
    cout << "Please enter the number you would like to convert: ";
    cin >> numberToConvert;
    
    // Prompt the user for the base of the number they previously supplied
    cout << "\nPlease enter the base of the number you supplied: ";
    cin >> baseOfNumberToConvert;
    
    if (Convert::isValidNumberBasedOnBase(numberToConvert, baseOfNumberToConvert))
    {
        // If user supplied input was valid, print message to user telling them their base 10 equivalent number
        cout << numberToConvert << " of base " << baseOfNumberToConvert << " is equal to " << Convert::convertNumberToBase10(numberToConvert, baseOfNumberToConvert) << " of base 10" << endl << endl;
    }
}

/* Converts supplied number to base 10 based off of supplied base */
int Convert::convertNumberToBase10(int number, int base)
{
    int base10Value = 0; // Will hold the final base 10 equivalent value
    int remainingNumbersToProcess = number; // Will hold a copy of the number to convert
    
    /* Begin Base 10 Conversion Process */
    for(int currentDigitOfFocus = remainingNumbersToProcess % 10, currentDigitPlace = 0; remainingNumbersToProcess > 0; remainingNumbersToProcess = (remainingNumbersToProcess / 10), currentDigitOfFocus = remainingNumbersToProcess % 10, currentDigitPlace++)
    {
        /* Caclulate the current base 10 value, thus far, in the process of reading user's
           supplied number from least significant to most significant digit
         */
        base10Value += (currentDigitOfFocus * (int)pow((double)base,(double)currentDigitPlace));
    }
    
    // Return the base 10 equivalent value
    return base10Value;
}

/* Will validate if user supplied number is valid based on the supplied base */
bool Convert::isValidNumberBasedOnBase(int number, int base)
{
    int remainingNumbersToProcess = number; // Will hold a copy of the number to convert
    bool inputWasValid = true; // Will hold whether the user's number input was valid for the base they stated it is in
    
    /* Validate Input and Begin Conversion Process */
    for(int currentDigitOfFocus = remainingNumbersToProcess % 10, currentDigitPlace = 0; remainingNumbersToProcess > 0; remainingNumbersToProcess = (remainingNumbersToProcess / 10), currentDigitOfFocus = remainingNumbersToProcess % 10, currentDigitPlace++)
    {
        // Print Error Message to user if an invalid numerical value is found for the given base
        if (currentDigitOfFocus >= base)
        {
            cout << "Invalid number found, for the base " << base << " numerical alphabet! -> " << currentDigitOfFocus << endl;
            inputWasValid = false;
        }
    }
    
    cout << endl;
    
    // Return whether the user supplied valid number
    return inputWasValid;
}
