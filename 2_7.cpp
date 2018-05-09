#include <iostream>

void hourMinute(int,int);

int main()
{   
    int hour;
    int minute;
    std::cout << "Enter the number of hours:"   ;
    std::cin >> hour;
    std::cout<< "Enter the number of minutes: " ;
    std::cin >> minute;
    hourMinute(hour,minute);
    return 0;
}

void hourMinute(int a,int b){
    std::cout << "Time:  " << a << ":"<<b<<std::endl;
}