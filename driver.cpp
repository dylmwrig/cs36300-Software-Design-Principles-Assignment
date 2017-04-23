#include <iostream>
#include "Calculator.h"

int main()
{
    std::string input = "";
    std::string expression = "";
    int lineCount = 0;

    while (input != "QUIT")
    {
        std :: cout << lineCount << "\tPlease enter your expression: ";
        std :: getline (std::cin,input);
        if (input != "QUIT")
        {
            Calculator calculator;
            std::cout << "\n\nThe answer is " << calculator.calculate(input) << std :: endl;
	        input = "";
            lineCount++;
        } //end if
    } //end while
    return 0;
} //end main