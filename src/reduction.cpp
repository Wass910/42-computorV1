#include "../inc/computor-V1.hpp"

std::string formating_equation(std::string equation)
{
    std::vector<int> puissance;
    double reduct_value = 0;
    std::string new_equation;
    std::string str;

    std::cout << "Intermediate steps: ";
    print_equation(equation);
    if (equation[0] >= '0' && equation[0] <= '9')
        equation.insert(0, "+");
    puissance = fill_puissance(equation);
    std::sort(puissance.begin(), puissance.end(), compare);
    for (std::vector<int>::iterator it_puissance = puissance.begin(); it_puissance != puissance.end(); it_puissance++)
    { 
        reduct_value = have_int_of_equation(equation, it_puissance);
        str = std::to_string(reduct_value);
        str.erase(str.find_last_not_of('0') + 1, std::string::npos);
        if (str.back() == '.') {
            str.pop_back();
        }
        if (reduct_value >= 0 && new_equation.length() != 0)
            new_equation.append("+");
        new_equation.append(str);
        new_equation.append("X^");
        new_equation.append(std::to_string(*it_puissance));
        reduct_value = 0;
    }
    new_equation.append("=0");
    return new_equation;
}

std::string reduction_form(std::string equation)
{
    equation.erase(std::remove(equation.begin(), equation.end(), ' '), equation.end());
    std::cout << "Intermediate steps: ";
    print_equation(equation);
    int equal_position = equation.find("=");
    std::string next_to_equal = equation.substr(equal_position + 1);
    if (next_to_equal[0] >= '0' && next_to_equal[0] <= '9')
        next_to_equal.insert(0, 1, '+');
    std::replace(next_to_equal.begin(), next_to_equal.end(), '+', '?');
    std::replace(next_to_equal.begin(), next_to_equal.end(), '-', '+');
    std::replace(next_to_equal.begin(), next_to_equal.end(), '?', '-');
    equation.replace(equal_position + 1, next_to_equal.length(), "0");
    equation.insert(equal_position, next_to_equal);
    equation = formating_equation(equation);
    return equation;
}