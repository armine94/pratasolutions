#include <iostream>

const double duymm=0.254;
const double funtt=2.2;
int duym(int,int);
double metr(int);
int kg(int);

int main()
{   
    int fut ;
    int duym1;
    int funt;
    float BMI;
    int k; 
    std::cout << "Enter the number of fut:"   ;
    std::cin >> fut;
    std::cout<< "Enter the number of duym: " ;
    std::cin >> duym1;
    std::cout << "Enter the number of funt:"   ;
    std::cin >> funt;
    
    k=duym(fut,duym1);
    BMI=kg(funt)/(metr(k)*metr(k));
    std::cout << "BMI = " << BMI << std::endl;
    
    
    return 0;
}

int duym(int a,int b){
    return a*12+b;
}
double metr(int a){
    return a*duymm;
}

int kg(int a){
    return a/funtt;
}