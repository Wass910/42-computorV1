#include "../inc/computor-V1.hpp"

void analyze_polynomial_form(std::string equation)
{
    equation.erase(std::remove(equation.begin(), equation.end(), ' '), equation.end());
    if (equation.length() == 0)
        exit_function("No equation");
    if (equation[0] != '+' && equation[0] != '-' && (equation[0] < '0' || equation[0] > '9'))
        exit_function("Please enter a valid form");
    int count_equal = std::count(equation.begin(), equation.end(), '=');
    if (count_equal != 1)
        exit_function("Please enter a valid form");
    for (size_t i = 0; i < equation.length(); i++)
    {
        if (equation[i] != '=' && equation[i] != '.' && equation[i] != '*' && equation[i] != '+' && equation[i] != '-' && equation[i] != 'X' && equation[i] != '^' && (equation[i] < '0' || equation[i] > '9'))
            exit_function("Please enter a valid form");
        if (equation[i] == 'X'){
            if (i > 0 && (equation[i + 1] != '^' || equation[i - 1] != '*'))
                exit_function("Please enter a valid form");
        }
        else if (equation[i] == '^')
        {
            if (i > 0 && equation[i - 1] != 'X')
                exit_function("Please enter a valid form");
            else if (equation[i+1] != '-' && equation[i+1] != '+'){
                if (equation[i + 1] < '0' || equation[i + 1] > '9')
                    exit_function("Please enter a valid form");
            }
        }
        else if (equation[i] == '*')
        {
            if (i > 0 && (equation[i + 1] != 'X' || (equation[i - 1] < '0' || equation[i - 1] > '9')))
                exit_function("Please enter a valid form");
        }
        else if (equation[i] == '+' || equation[i] == '-')
        {
            if (i > 0 && (equation[i + 1] < '0' || equation[i + 1] > '9'))
                exit_function("Please enter a valid form");
            else if (i > 0 && (equation[i - 1] < '0' || equation[i - 1] > '9') && equation[i - 1] != '=')
                exit_function("Please enter a valid form");
        }
        else if (equation[i] == '=')
        {
            if (i > 0 && (equation[i + 1] < '0' || equation[i + 1] > '9')){
                if (equation[i + 1] != '+' && equation[i + 1] != '-')
                    exit_function("Please enter a valid form");
            }
        }
        else if (equation[i] == '.')
        {
            if ((equation[i + 1] < '0' || equation[i + 1] > '9'))
                exit_function("Please enter a valid form");
            if ((equation[i - 1] < '0' || equation[i - 1] > '9'))
                exit_function("Please enter a valid form");
        }
        else if (equation[i] >= '0' && equation[i] <= '9')
        {
            if (i > 0 && (equation[i - 1] != '-' && equation[i - 1] != '+' && equation[i - 1] != '^' && equation[i - 1] != '=' && equation[i - 1] != '.')){
                if (equation[i - 1] < '0' || equation[i - 1] > '9')
                    exit_function("Please enter a valid form");
            }
            if (i != equation.length()-1 && (equation[i + 1] != '-' && equation[i + 1] != '+' && equation[i + 1] != '*' && equation[i + 1] != '=' && equation[i + 1] != '.')){
                if (equation[i + 1] < '0' || equation[i + 1] > '9')
                    exit_function("Please enter a valid form");
            }
        }
    }
    equation.erase(std::remove(equation.begin(), equation.end(), '*'), equation.end());
    return;
}