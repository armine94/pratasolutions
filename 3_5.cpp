#include <iostream>


int main()
{
    long long worldCount;
    long long WorldUs;
    float procent;
    
    std::cout << "Enter the world's population:" ;
    std::cin >> worldCount;
    std::cout << "Enter the population of the US:" << std::endl;
    std::cin >> WorldUs;
    procent = (long double)WorldUs*100/(long double)worldCount;
    std::cout << "The population of the US is "<<procent<<"%"<<" of the world population." << std::endl;
    
    return 0;
}

