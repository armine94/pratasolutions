#include <iostream>

const int day=86400;
const int hour= 3600;
const int minutes=60;

int main()
{
    long long seconds;
    int dayCount;
    int hourCount;
    int minutesCount;
    int temp;
    std::cout << "Enter the number of seconds: ";
    std::cin >> seconds;
    dayCount=seconds/day;
    hourCount=(seconds - dayCount * day)/hour;
    minutesCount = (seconds - dayCount * day - hourCount * hour)/minutes;
    temp = seconds - dayCount * day - hourCount * hour - minutesCount*minutes;
    std::cout << seconds<<" seconds = "<<dayCount<<" days, "<< hourCount <<" hours "<<minutesCount<<" minutes, "<<temp<<" seconds" << std::endl;
    return 0;
}
