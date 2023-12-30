#include <string>
#include <stack>
#include <iostream>
#include <vector>
#include <typeinfo>
#include "eval.hpp"
#include "parse_out.hpp"

void show_stack(std::stack<std::string> s)
{
    while(!s.empty())
    {
        std::cout << s.top() << " "; 
        s.pop();
    }
    std::cout << std::endl;

}


std::vector<std::string> tokenize(std::string exp)
{

    std::vector<std::string> token_list;

    std::string digit_token = "";
    std::string op = "";
    for(int i = 0; i<exp.length(); i++)
    {
  
        if(exp[i] != '+' && exp[i] != '-' && exp[i] != '*')
        {
            digit_token += exp[i];
        }
        else {
            token_list.push_back(digit_token);
            
            digit_token = "";
            op = exp[i];
            token_list.push_back(op);
            op = "";
        }
    }
    
    token_list.push_back(digit_token);
    // std::cout << "token: " << digit_token <<std::endl;
    // for(auto i = token_list.begin(); i!= token_list.end(); ++i)
    // {
    //     std::cout << *i << " ";
    // }
    return token_list;
}



int evaluate_expression(std::string exp)
{
    

    std::vector<std::string> token_list = tokenize(exp);

    std::stack<std::string> output;
    std::stack<std::string> operator_stack;

    for(auto token = token_list.begin(); token != token_list.end(); ++token)
    {


        if(*token != "+" && *token != "-" && *token != "*")
        {

            std::string digit = *token;
            output.push(digit);

        }

        else if(*token == "*")
        {
            while(operator_stack.empty() != 1 && operator_stack.top() == "*")
            {
                std::string op = operator_stack.top();
                output.push(op);
                operator_stack.pop();
            }
            operator_stack.push(*token);
        }

        else if(*token == "+" || *token == "-")
        {



            while(operator_stack.empty() != 1 && operator_stack.top() == "+" || operator_stack.empty() != 1 && operator_stack.top() == "-" || operator_stack.empty() != 1 && operator_stack.top() == "*" )
            {

                std::string op = operator_stack.top();
                output.push(op);
                operator_stack.pop();
            }
            operator_stack.push(*token);
        }

    }

    // for debuggin 

    // while(!output.empty())
    // {
    //     std::cout << output.top() << " ";
    //     output.pop();
    // }
    // std::cout << std::endl;

    // if(operator_stack.empty()){std::cout <<" Stack empty" ;}
    // while(!operator_stack.empty())
    // {
    //     std::cout << operator_stack.top() << " ";
    //     operator_stack.pop();
    // }
    // std::cout << std::endl;
    


    while(!operator_stack.empty())
    {
        output.push(operator_stack.top());
        operator_stack.pop();
    }

    // while(!output.empty())
    // {
    //     std::cout << output.top() << " ";
    //     output.pop();
    // }
    // std::cout << std::endl;

    // show_stack(output);
    // std::cout << "END of eval.cpp" << std::endl;
    

    int value = eval_tree(output);
    return value;
}
