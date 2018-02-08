/*******************************************************************************
** Program Name: Utility Functions
** Author: Kelly von Borstel
** Date: 2/1/2018
** Description: This is the implementation file for utility functions getInt()
** and getRandNum().
*******************************************************************************/

#include <iostream>
#include <cctype>
#include <ctime>
#include <cstdlib>
using std::cout;
using std::cin;
using std::endl;
using std::isdigit;

#include "utility.hpp"


/*******************************************************************************
** Description: This is the implementation for the getInt() function, which
** gets and validates integers. The function has three parameters, an integer
** for the minimum accepted value, an integer for the maximum accepted value,
** and a string prompt. The prompt is optional. If a prompt is passed in, it
** will be displayed before the user enters input. If the user enters anything 
** other than a valid integer, they will be prompted again. The function returns
** the integer that the user input.
*******************************************************************************/

int getInt(int min, int max, string prompt)
{
    string userInput;

    // if a prompt was passed in, display the prompt
    if (prompt.length() > 0)
    {
        cout << prompt << endl;
    }

    // assume input is not valid to begin
    bool isValid = false;

    // keep looping until the input is proven to be valid
    while (!isValid)
    {
        cout << "Choose an integer between " << min << " and " << max << endl;

        // get entire line of input as string
        getline(cin, userInput);

        // assume the input is all digits until we find something that isn't
        bool isAllDigits = true;

        char firstChar = userInput[0];

        // if input is only one character and not a digit, set isAllDigits false
        if (userInput.length() == 1)
        {
            if (!isdigit(firstChar))
            {
                isAllDigits = false;
            }
        }

        /* if the input is more than one character, and that character is not a
        digit, plus sign, or minus sign, set isAllDigits false */
        else
        {
            if (firstChar != '+' && firstChar != '-' && !isdigit(firstChar))
            {
                isAllDigits = false;
            }
        }

        // check all characters and if any aren't digits, set isAllDigits false
        for (int i = 1; i < userInput.length(); i++)
        {
            if (!isdigit(userInput[i]))
            {
                isAllDigits = false;
            }
        }

        // if all digits, and value is between min and max, the input is valid
        if (isAllDigits && stoi(userInput) >= min && stoi(userInput) <= max)
        {
            isValid = true;
        }
    }

    cout << '\n';

    // return input as an integer
    return stoi(userInput);
}


/*******************************************************************************
** Description: This is the implementation for the getRandNum() function,
** which gets a random number between a min and max value. The function has
** two parameters, integers for the min and max values. It returns a random
** number within that range as an integer.
*******************************************************************************/

int getRandNum(int min, int max)
{
    return (rand() % (max - min + 1)) + min;
}


/*******************************************************************************
** Description: This is the implementation for the getRandNum() function for
** doubles, which gets a random number between min and max. The function has two
** parameters, doubles for min and max values. It returns a random number within
** that range as a double. https://ubuntuforums.org/showthread.php?t=1717717
*******************************************************************************/

double getRandNum(double min, double max)
{
    double range = max - min;
    double divisor = RAND_MAX / range;
    return min + rand() / divisor;
}
