#include "../inc/computor-V1.hpp"

void exit_function(const char *message)
{
    std::cout << message << std::endl;
    exit(1);
}

bool compare(int a, int b) {
    return a > b;
}

double my_sqrt(double x) {
    if (x < 0) {
        return std::numeric_limits<double>::quiet_NaN();
    } else if (x == 0) {
        return 0;
    } else {
        double guess = x / 2;
        double error = x;
        double epsilon = 0.0000001;
        while (error > epsilon) {
            double next_guess = (guess + x / guess) / 2;
            error = std::abs(next_guess - guess);
            guess = next_guess;
        }
        return guess;
    }
}

void        print_equation(std::string equation)
{
    for (size_t i = 0; i < equation.length(); i++)
    {
        if (equation[i] == '+'){
            if (i != 0)
                std::cout << " + ";
            i++;
            std::cout << equation[i];
        }
        else if (equation[i] == '-' && i != 0){
            std::cout << " - ";
            i++;
            std::cout << equation[i];
        }
        else if (equation[i] == '='){
            std::cout << " = ";
            i++;
            std::cout << equation[i];
        }
        else
            std::cout << equation[i];
    }
    std::cout << std::endl;
    return ;
}