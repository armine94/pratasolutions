#include <iostream>

double CelsiusFarenheit(float);

int main()
{   
    int degre;
    std::cout << "Please enter a Celsius value:" << std::endl; 
    std::cin >> degre;
    std::cout <<degre << " degrees Celsius is  " <<CelsiusFarenheit(degre)<<" degrees Fahrenheit."<< std::endl;
    return 0;
}

double CelsiusFarenheit(float a){
    return a*1.8+32;
}