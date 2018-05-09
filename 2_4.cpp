#include <iostream>

int ageMonths(int);

int main()
{   
    int age;
    std::cout << "enter your age : " << std::endl; 
    std::cin >> age;
    std::cout << "Your age in monts is " <<ageMonths(age)<< std::endl;
    return 0;
}

int ageMonths(int age){
    return age*12;
}