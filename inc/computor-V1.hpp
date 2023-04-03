#include <iostream>
#include <string>
#include <cstdlib>
#include <cctype>
#include <vector>
#include <cmath>

void                exit_function(const char *message);
bool                compare(int a, int b);
double              my_sqrt(double x);
void                print_equation(std::string equation);
void                analyze_polynomial_form(std::string equation);
void                resolution_of_the_degree_two(std::string equation);
void                resolution_of_the_degree_one(std::string equation);
std::vector<int>    fill_puissance(std::string equation);
std::string         formating_equation(std::string equation);
std::string         reduction_form(std::string equation);
double              have_int_of_equation(std::string equation, std::vector<int>::iterator it_puissance);
