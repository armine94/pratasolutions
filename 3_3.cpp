#include <iostream>


int main()
{
    double degrees;
    double minutes;
    double seconds;
    double count;
    std::cout << "Enter a latitude in degrees, minutes, and seconds:"<<std::endl ;
    std::cout << "First, enter the degrees:" ;
    std::cin >> degrees;
    std::cout << "Next, enter the minutes of arc:" ;
    std::cin >> minutes;
    std::cout << "Finally, enter the seconds of arc:" ;
    std::cin >> seconds;
    count=degrees+minutes/60+seconds/3600;
    std::cout << degrees<<" degrees," 
             <<minutes <<" minutes,"
             <<seconds<<"seconds = "
             <<count
             <<" degrees"<< std::endl;
    return 0;
}
