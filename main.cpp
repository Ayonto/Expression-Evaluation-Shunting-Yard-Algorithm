#include <iostream>
#include <string>

#include "eval.hpp"

int main(int, char**){
    std::cout << "Hello, from expr_eval! WARNING: DO NOT USE DIVISION, NOT SUPPORTED YET\n";

    std::string expr;
    std::cout << "Enter an Expression >> ";
    std::cin >>expr;

    // std::string expr = "222+3*4";

    // std::string expr = "4+2-7*13";

    int result = evaluate_expression(expr);
    std::cout << "Result >> " << result << std::endl;
}
