#include "../inc/computor-V1.hpp"

double     have_int_of_equation(std::string equation, std::vector<int>::iterator it_puissance)
{
    double reduct_value = 0;
    int j = 0;
    int tmp = 0;
    int coeff = 0;

    for(size_t i = 0; i < equation.length(); i++)
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

    for (size_t i = 0; i < puissance.size(); i++, it_puissance++)
        result.push_back(have_int_of_equation(equation, it_puissance));

    for (size_t i = 0; i < result.size(); i++){
        if (result[i] == 0)
        {
            puissance.erase(puissance.begin()+i, puissance.begin()+i+1);
            result.erase(result.begin()+i, result.begin()+i+1);
            i--;
        }
    }

    equation.clear();
    equation = "";

    for (size_t i = 0; i < result.size(); i++, it_puissance++){
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
    analyze_polynomial_form(argv[1]);
    resolution_of_the_equation(argv[1]);
    return 0;
}

 