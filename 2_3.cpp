#include <iostream>

void f1(void);
void f2(void);

int main()
{   
    f1();
    f1();
    f2();
    f2();
  
    return 0;
}

void f1(){
    std::cout<<"Three blind mice "<<std::endl;
}

void f2(){
    std::cout<<"See how they run"<<std::endl;
}
