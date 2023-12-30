
#include <iostream>
#include <string>
#include <stack>

#include "parse_out.hpp"
#include "binary_operation.hpp"


void print_stack(std::stack<int> s)
{
    while(!s.empty())
    {
        std::cout << s.top() << " "; 
        s.pop();
    }
    std::cout << std::endl;

}

int eval_tree(std::stack<std::string> output)
{
    // std::cout << "Parse File" << std::endl;

    std::stack<std::string> tree;
    while(!output.empty())
    {
        tree.push(output.top());
        output.pop();
    }

    std::stack<int> temp;
    std::string token;
    while(!tree.empty())
    {
        token = tree.top();
        if(token != "+" && token != "-" && token != "*")
        {
            temp.push(std::stoi(token));

            // std::cout << ">> "<< token << std::endl;
        }

        else if(token == "+")
        {
            
            int operand1 = temp.top();
            temp.pop();
            int operand2 = temp.top();
            temp.pop();

            temp.push(ADD(operand2, operand1));

            // std::cout << "ADD" << std::endl;
            
        }
        else if(token == "-")
        {
            
            int operand1 = temp.top();
            temp.pop();
            int operand2 = temp.top();
            temp.pop();

            temp.push(SUB(operand2, operand1));

            // std::cout << "SUB" << std::endl;
            
        }
        else if(token == "*")
        {
            
            int operand1 = temp.top();
            temp.pop();
            int operand2 = temp.top();
            temp.pop();

            temp.push(MUL(operand2, operand1));

            // std::cout << "MULTI" << std::endl;
            
        }
        // std::cout << "DEBUG FOR TEMP IN LOOP: ";
        // print_stack(temp);

        tree.pop();
    }

    // std::cout << "TEMP: ";
    // while(!temp.empty())
    // {
    //     std::cout << temp.top() << " "; 
    //     temp.pop();
    // }
    return temp.top();
}
