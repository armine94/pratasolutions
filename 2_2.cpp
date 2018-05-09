#include <iostream>

int yard(int);

int main()
{   int chap;
    std::cout<<"nermuceq heravorutyan chap@  Farlongnerov"<<std::endl;
    std::cin >> chap;
    std::cout<<chap<<" Farlong@ = "<<yard(chap)<<" yardi"<<std::endl;
  
    return 0;
}

int yard(int a){
    return a*220;
}