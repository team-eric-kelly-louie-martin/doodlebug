/*******************************************************************************
** Program Name: Utility Functions
** Author: Kelly von Borstel
** Date: 2/1/2018
** Description: This is the declaration file for utility functions getInt() and
** getRandNum().
*******************************************************************************/

#ifndef UTILITY_HPP
#define UTILITY_HPP

#include <string>
using std::string;


/*******************************************************************************
** Description: This is the declaration for the getInt() function, which
** gets and validates integers. The function has three parameters, an integer
** for the minimum accepted value, an integer for the maximum accepted value,
** and a string prompt. The prompt is optional. If a prompt is passed in, it
** will be displayed before the user enters input. If the user enters anything 
** other than a valid integer, they will be prompted again. The function returns
** the integer that the user input.
*******************************************************************************/

int getInt(int min, int max, string prompt = "");


/*******************************************************************************
** Description: This is the declaration for the getRandNum() function,
** which gets a random number between a min and max value. The function has
** two parameters, integers for the min and max values. It returns a random
** number within that range as an integer.
*******************************************************************************/

int getRandNum(int min, int max);


/*******************************************************************************
** Description: This is the declaration for the getRandNum() function for
** doubles, which gets a random number between min and max. The function has two
** parameters, doubles for min and max values. It returns a random number within
** that range as a double. https://ubuntuforums.org/showthread.php?t=1717717
*******************************************************************************/

double getRandNum(double min, double max);

#endif
