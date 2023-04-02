#include "computor-V1.hpp"

double     have_int_of_equation(std::string equation, std::vector<int>::iterator it_puissance)
{
    double reduct_value = 0;
    int j = 0;
    int tmp = 0;
    int coeff = 0;

    for(int i = 0; i < equation.length(); i++)
        {
            if (equation[i] == '^'){
                j = i + 1;
                while (equation[j] >= '0' && equation[j] <= '9')
                    j++;
                j--;
                coeff = std::stoi(equation.substr(i + 1, j - i));
                if (coeff == *it_puissance){
                    while(equation[j] != '+' && equation[j] != '-')
                        j--;
                    j++;
                    tmp = j;
                    while ((equation[tmp] >= '0' && equation[tmp] <= '9') || equation[tmp] == '.')
                        tmp++;
                    
                    if (equation.substr(j - 1, tmp - j + 1).find('.') != std::string::npos)
                        reduct_value = reduct_value + std::stod(equation.substr(j - 1, tmp - j + 1));
                    else{
                        reduct_value = reduct_value + std::stod(equation.substr(j - 1, tmp - j + 1));
                    }
                }
            }
        }
    return reduct_value;
}

void analyze_polynomial_form(std::string expression)
{
    
    return;
}

std::vector<int> fill_puissance(std::string equation)
{
    std::vector<int> puissance;
    std::vector<int>::iterator it_puissance = puissance.begin();
    int j = 0;
    for(int i = 0; i < equation.length(); i++)
    {
        if (equation[i] == '^'){
            j = i + 1;
            while ((equation[j] >= '0' && equation[j] <= '9'))
                j++;
            it_puissance = std::find(puissance.begin(), puissance.end(), atoi(equation.substr(i + 1, j - i - 1).c_str()));
            if (it_puissance == puissance.end())
                puissance.push_back(atoi(equation.substr(i + 1, j - i - 1).c_str()));
        }
    }
    return puissance;
}

std::string formating_equation(std::string equation)
{
    std::vector<int> puissance;
    
    int j = 0;
    int tmp = 0;
    int coeff;
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
    int j = 0;
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

void    resolution_of_the_degree_two(std::string equation)
{   
    double a = 0.0;
    double b = 0.0;
    double c = 0.0;
    if (equation[0] >= '0' && equation[0] <= '9')
        equation.insert(0, "+");
    std::vector<int> puissance = fill_puissance(equation);
    std::vector<int>::iterator it_puissance = puissance.begin();    

    for (int i = 0; i < puissance.size(); i++, it_puissance++){
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

    for (int i = 0; i < puissance.size(); i++, it_puissance++){
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

void    resolution_of_the_equation(std::string equation)
{
    std::vector<int> puissance;
    std::string str;
    equation = reduction_form(equation);
    std::vector<double> result;

    if (equation[0] >= '0' && equation[0] <= '9')
        equation.insert(0, "+");
    puissance = fill_puissance(equation);
    std::vector<int>::iterator it_puissance = puissance.begin();    

    for (int i = 0; i < puissance.size(); i++, it_puissance++)
        result.push_back(have_int_of_equation(equation, it_puissance));
    for (int i = 0; i < result.size(); i++){
        if (result[i] == 0)
        {
            puissance.erase(puissance.begin()+i, puissance.begin()+i+1);
            result.erase(result.begin()+i, result.begin()+i+1);
            i--;
        }
    }
    equation.clear();
    equation = "";
    for (int i = 0; i < result.size(); i++, it_puissance++){
        str = std::to_string(result[i]);
        str.erase(str.find_last_not_of('0') + 1, std::string::npos);
        if (str.back() == '.') {
            str.pop_back();
        }
        if (result[i] >= 0 && equation.length() != 0)
            equation.append("+");
        equation.append(str);
        equation.append("X^");
        equation.append(std::to_string(puissance[i]));
        str.clear();
    }
    equation.append("=0");
    std::cout << "Reduced form:       ";
    if (equation[0] == '='){
        std::cout << "0\n";
        std::cout << "Polynomial degree:   0" << std::endl;
        std::cout << "There is no solution for this equation." << std::endl;
        return ;
    }
    print_equation(equation);

    std::cout << "Polynomial degree:  " << *puissance.begin() << std::endl;
    if (*puissance.begin() == 1)
        resolution_of_the_degree_one(equation);
    else if (*puissance.begin() == 2)
        resolution_of_the_degree_two(equation);
    else if(*puissance.begin() > 2)
        std::cout << "The polynomial degree is stricly greater than 2, I can't solve." << std::endl;
    else
        std::cout << "There is no solution for this equation." << std::endl;
    return;
}

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        printf("Bad number of arguments\n");
        return 1;
    }
    // analyze_polynomial_form(argv[1]);
    resolution_of_the_equation(argv[1]);
    return 0;
}

 