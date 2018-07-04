#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <cstring>
#include "cube.h"
#include <climits>

int main () {
	std::string str;
	std::string rotate;
	std::string deRotate;
	std::cout<< "enter text" <<std::endl;
	getline(std::cin,str);
	//std::cin.get(str);
	//std::cin.ignore(INT_MAX);
	std::cout<< "enter encription rotate" <<std::endl;
	std::cin>>rotate;
	std::cout<< "enter decription rotete" <<std::endl;
	std::cin>>deRotate;
	CubeControler a;
	
	a.parseText(str);
	a.encription(rotate);
	if(rotate == deRotate){
		a.decription(deRotate);
	}
	else {
		a.decription(rotate);
	}
	a.read();	

	return 0;
}
