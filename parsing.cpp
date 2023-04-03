#include "computor-V1.hpp"

void analyze_polynomial_form(std::string equation)
{
    equation.erase(std::remove(equation.begin(), equation.end(), ' '), equation.end());
    if (equation.length() == 0)
    {
        std::cout << "No equation" << std::endl;
        exit (1);
    }
    if (equation[0] != '+' && equation[0] != '-' && (equation[0] < '0' || equation[0] > '9'))
    {
        std::cout << "Bad forme" << std::endl;
        exit (1);
    }
    int count_equal = std::count(equation.begin(), equation.end(), '=');
    if (count_equal != 1)
    {
        std::cout << "Too much equals" << std::endl;
        exit (1);
    }
    for (int i = 0; i < equation.length(); i++)
    {
        if (equation[i] != '=' && equation[i] != '.' && equation[i] != '*' && equation[i] != '+' && equation[i] != '-' && equation[i] != 'X' && equation[i] != '^' && (equation[i] < '0' || equation[i] > '9'))
        {
            std::cout << "Bad character in the equation" << std::endl;
            exit (1);
        }
        if (equation[i] == 'X')
        {
            if (i > 0 && (equation[i + 1] != '^' || equation[i - 1] != '*')){
                std::cout << "Bad form7" << std::endl;
                exit (1);
            }
        }
        else if (equation[i] == '^')
        {
            if (i > 0 && equation[i - 1] != 'X'){
                std::cout << "Bad form6" << std::endl;
                exit (1);
            }
            else if (equation[i+1] != '-' && equation[i+1] != '+'){
                if (equation[i + 1] < '0' || equation[i + 1] > '9'){
                    std::cout << "Bad form2" << std::endl;
                    exit (1);
                }
            }
        }
        else if (equation[i] == '*')
        {
            if (i > 0 && (equation[i + 1] != 'X' || (equation[i - 1] < '0' || equation[i - 1] > '9'))){
                std::cout << "Bad form1" << std::endl;
                exit (1);
            }
        }
        else if (equation[i] == '+' || equation[i] == '-')
        {
            if (i > 0 && (equation[i + 1] < '0' || equation[i + 1] > '9')){
                std::cout << "Bad form5" << std::endl;
                exit (1);
            }
            else if (i > 0 && (equation[i - 1] < '0' || equation[i - 1] > '9') && equation[i - 1] != '='){
                std::cout << "Bad form4" << std::endl;
                exit (1);
            }
        }
        else if (equation[i] == '=')
        {
            if (i > 0 && (equation[i + 1] < '0' || equation[i + 1] > '9')){
                if (equation[i + 1] != '+' && equation[i + 1] != '-'){
                    std::cout << "Bad form8" << std::endl;
                    exit (1);
                }
            }
        }
        else if (equation[i] == '.')
        {
            if ((equation[i + 1] < '0' || equation[i + 1] > '9')){
                std::cout << "Bad form11" << std::endl;
                exit (1);
            }
            if ((equation[i - 1] < '0' || equation[i - 1] > '9')){
                std::cout << "Bad form11" << std::endl;
                exit (1);
            }
        }
        else if (equation[i] >= '0' && equation[i] <= '9')
        {
            if (i > 0 && (equation[i - 1] != '-' && equation[i - 1] != '+' && equation[i - 1] != '^' && equation[i - 1] != '=' && equation[i - 1] != '.')){
                if (equation[i - 1] < '0' || equation[i - 1] > '9'){
                    std::cout << "Bad form9" << std::endl;
                    exit (1);
                }
            }
            if (i != equation.length()-1 && (equation[i + 1] != '-' && equation[i + 1] != '+' && equation[i + 1] != '*' && equation[i + 1] != '=' && equation[i + 1] != '.')){
                std::cout << "equ = " << equation[i] << std::endl;
                if (equation[i + 1] < '0' || equation[i + 1] > '9'){
                    std::cout << "Bad form0" << std::endl;
                    exit (1);
                }
            }
        }
    }
    equation.erase(std::remove(equation.begin(), equation.end(), '*'), equation.end());
    return;
}