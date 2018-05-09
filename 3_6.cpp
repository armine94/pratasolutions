#include <iostream>


int main()
{
    float petrol;
    float kilometrs;
    float temp;
    std::cout << "Enter number of petrol in litr  " ;//es anglerenic shat vat em esli chto :D
    std::cin >> petrol;
    std::cout << "Enter number of kilometrs  " ;
    std::cin >> kilometrs;
    temp=petrol/kilometrs;
    std::cout << "You used 100 kilometrs " << temp*100<<" litr petrol"<< std::endl;
    return 0;
}

