//cragir@ terminalic stanum e mardu hasak@ sm-nerov ev verapoxum duymeri u futeri arandzin funkcianeri mijocov ev tpum ekranin
#include <iostream>

const double duymRost=2.54;//mek duym@ 2.54 sm e
const double futRost=30.48;//mek fut@ 30.48 sm e 
double rostDuym(int);//f-i prototip
double rostFut(int);

int main()
{
    
    int rost; //integer tipi popoxakan rost anunov;
    std::cout<<"_";
    std::cin >> rost;//nermucum
    std::cout<<"Hasak@ duymerov = "<<rostDuym(rost)<<std::endl;
    std::cout<<"Hasak@ futerov = "<<rostFut(rost)<<std::endl;
  
    return 0;
}


double rostDuym(int hasak){
    return hasak/duymRost;
}
double rostFut(int hasak){
    return hasak/futRost;
}