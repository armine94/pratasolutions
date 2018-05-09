#include <iostream>
const float gLitr = 3.875;
const float Kmil = 62.14;

int main()
{   float benzin;
    std::cout << "Nermucel 100km hamar caxsvox benzini qanak@ literov";
    std::cin >> benzin;
    std::cout << " chanaparhi vra caxsvel e "<<(int)(Kmil/(benzin/gLitr))<< std::endl;
    return 0;
}
