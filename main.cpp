#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <cstring>
#include "cube.h"

int main () {
	std::string str;
	std::string rotate;
	std::string message;
	std::cout<<"encryption or decryption   e/d \n";
	std::cin>>message;
	std::cin.get();
	std::cout<< "enter text" <<std::endl;
	getline(std::cin,str);
	std::cout<< "\nenter rotate\n" <<std::endl;
	std::cout<< "first number of cube,then rotate\nr - right  \nl - left \nd - down \nu - up\nfor example	 0:l:r:d,1:u:r:d  	" <<std::endl;
	std::cin>>rotate;
	CubeControler a;
	if((message == "e") || (message == "E")) {
		a.parseText(str);
		a.encription(rotate);
	}
	else {
		a.parseText(str);
		a.decription(rotate);
	}
	
	a.read();	

	return 0;
}
