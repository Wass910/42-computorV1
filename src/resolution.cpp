#include "../inc/computor-V1.hpp"

void    resolution_of_the_degree_two(std::string equation)
{   
    double a = 0.0;
    double b = 0.0;
    double c = 0.0;
    if (equation[0] >= '0' && equation[0] <= '9')
        equation.insert(0, "+");
    std::vector<int> puissance = fill_puissance(equation);
    std::vector<int>::iterator it_puissance = puissance.begin();    

    for (size_t i = 0; i < puissance.size(); i++, it_puissance++){
        if (*it_puissance == 0)
            c = have_int_of_equation(equation, it_puissance);
        else if (*it_puissance == 1)
            b = have_int_of_equation(equation, it_puissance);
        else
            a = have_int_of_equation(equation, it_puissance);
    }
    
    double discriminant = b * b - 4 * a * c;
    if (my_sqrt(discriminant) == 0)
    {
        std::cout << "The solution is:" << std::endl;
        double x = (-b + my_sqrt(discriminant)) / (2 * a);
        if (a == 0 && b == 0 && c == 0)
            std::cout << "x = " << "i" << std::endl;
        std::cout << "x = " << std::round(x * 1000000) / 1000000 << std::endl;
        return ;
    }
    else if (my_sqrt(discriminant) > 0)
    {
        std::cout << "Solutions are:" << std::endl;
        double x1 = (-b + my_sqrt(discriminant)) / (2 * a);
        double x2 = (-b - my_sqrt(discriminant)) / (2 * a);
        std::cout << "x1 = " << std::round(x1 * 1000000) / 1000000 << std::endl;
        std::cout << "x2 = " << std::round(x2 * 1000000) / 1000000 << std::endl;
        return ;
    }
    else
    {
        double real_part = -b / (2 * a);
        double imaginary_part = my_sqrt(-discriminant) / (2 * a);
        std::cout << "Solutions are:" << std::endl;
        std::cout << "x1 = " << real_part << " + i*" << imaginary_part << "\nx2 = " << real_part << " - i*" << imaginary_part << std::endl;
        return ;
    }  
    return ;
}



void    resolution_of_the_degree_one(std::string equation)
{   
    double a = 0;
    double b = 0;
    if (equation[0] >= '0' && equation[0] <= '9')
        equation.insert(0, "+");
    std::vector<int> puissance = fill_puissance(equation);
    std::vector<int>::iterator it_puissance = puissance.begin();    

    for (size_t i = 0; i < puissance.size(); i++, it_puissance++){
        if (i == 0)
            a = have_int_of_equation(equation, it_puissance);
        else if (i == 1)
            b = have_int_of_equation(equation, it_puissance);
    }
    if (a == 0) 
        std::cout << "There is no solution for this equation." << std::endl;
    else  
        std::cout << "The solution is: \nx = " << std::round((-b / a) * 1000000) / 1000000 << std::endl;
    return ;
}