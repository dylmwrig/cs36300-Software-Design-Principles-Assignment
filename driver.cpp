#include <iostream>
#include "Calculator.h"

int main()
{
    /*
    Stack <int> s;
    Stack_Expr_Command_Factory factory(s);
    Array<std::string> inputs;
    std::string input = "";
    std::string expression = "";
    int lineCount = 0;

    while (input != "QUIT")
    {
        std :: cout << lineCount << "\tPlease enter your expression: ";
        std :: getline (std::cin,input);
        if (input != "QUIT")
        {
            for (char c : input)
            {
                if (c != ' ')
                {
                    if (isalpha(c))
                    {
                      //std :: cout << "\n" << c << "=";
                      //int value = 0;
                      //std :: cin >> value;
                      //std :: string s = std :: to_string(value);
                      //std :: cout << std::endl << "number to be added: " << s << std :: endl;
                      //expression += s;

                    } //end if

                    else
                    {
                      expression += c;
                    } //end else
                } //end if

                else
                {
                    //Expr_Node command;
                  
                    //expressions.push_back(command);
                    inputs.add(expression);
                    expression = "";
                } //end else
            } //end for
            inputs.add(expression);
	        expression = "";
            lineCount++;
        } //end if
    } //end while

    Array <Expr_Node * > postfixArr = postfix(inputs, factory);
    for (int i = 0; i < postfixArr.size(); i++)
    {
        postfixArr[i]->execute();
    }
    std::cout<<s.top();
    */

    std::string input = "";
    std::cout<<"Please enter your infix expression, with each item separated by a space: " << std::endl;
    std::getline(std::cin, input);

    Calculator calculator;
    calculator.calculate(input);

    return 0;
} //end main