#include <iostream>

double year(double);

int main()
{   
    double year1;
    std::cout << "Enter the number of light years:" << std::endl; 
    std::cin >> year1;
    std::cout <<year1 << " light years =  " << year(year1) <<" astronomical units."<< std::endl;
    return 0;
}

double year(double a){
    return a*63240;
}