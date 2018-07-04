#include "cube.h"
#include <iostream>
#include <cstring>
#include <bits/stdc++.h>

void Cube::writeVector(char chr[]) {
	char garbige = '&';
	int i = 0;

        tMap["000"] = garbige;
        tMap["100"] = garbige;
        tMap["110"] = garbige;
        tMap["010"] = garbige;
        tMap["001"] = garbige;
        tMap["101"] = garbige;
        tMap["111"] = garbige;
        tMap["011"] = garbige;
       	
	while(chr[i] != '\0') {
		char ch = chr[i];
		switch(i) {			 
			case 0 : {
				tMap["000"] = ch;
				break;
				 }
			case 1 : {
				tMap["100"] = ch;
				break;
				 }
			case 2 : {
				tMap["110"] = ch;
				break;
				}
			case 3 : {
				tMap["010"] = ch;
                                break;
				}
			case 4 : {
				tMap["001"] = ch;
                                break;
				}
			case 5 : {
				tMap["101"] = ch;
                                break;
				 }
			case 6 : {
				tMap["111"] = ch;
                                break; 
				}
			case 7 : {
				tMap["011"] = ch;
				break;
				}
			default : {
	  			break;
				  }
			}
		++i;
        }
	mVec.push_back(tMap);
	for(std::vector<std::map<std::string, char> > :: iterator it = mVec.begin(); it != mVec.end(); ++it) {
                for(std::map<std::string, char> :: iterator mit = it->begin(); mit != it->end(); ++ mit){
                }
        }
}

void Cube::lRotate(int index){
	int i = 0;
	for(std::vector<std::map<std::string, char> > :: iterator it = mVec.begin(); it != mVec.end(); ++it) {
   		if(i == index ){
		        std::map<std::string, char> &mMap = *it;
			char tmp = mMap["100"];
	        	mMap["100"] = mMap["110"];
        		mMap["110"] = mMap["010"];
	        	mMap["010"] = mMap["000"];
        		mMap["000"] = tmp;
	        	tmp = mMap["101"];
        		mMap["101"] = mMap["111"];
	        	mMap["111"] = mMap["011"];
	        	mMap["011"] = mMap["001"];
        		mMap["001"] = tmp ;
		}
		++i;
	}
}

void Cube::rRotate(int index){
	int i = 0;
        for(std::vector<std::map<std::string, char> > :: iterator it = mVec.begin(); it != mVec.end(); ++it) {
                if(i == index ){
                       	std::map<std::string, char> &mMap = *it;
			char tmp = mMap["010"];
		        mMap["010"] = mMap["110"];
		        mMap["110"] = mMap["100"];
        		mMap["100"] = mMap["000"];
		        mMap["000"] = tmp;
		        tmp = mMap["011"];
        		mMap["011"] = mMap["111"];
        		mMap["111"] = mMap["101"];
        		mMap["101"] = mMap["001"];
        		mMap["001"] = tmp;
			break;
		}
		++i;
	}
}

void Cube::uRotate(int index){
        int i = 0;
        for(std::vector<std::map<std::string, char> > :: iterator it = mVec.begin(); it != mVec.end(); ++it) {
                if(i == index ){
                        std::map<std::string, char> &mMap = *it;
			char tmp = mMap["010"];
	         	mMap["010"] = mMap["011"];
       			mMap["011"] = mMap["001"];
	        	mMap["001"] = mMap["000"];
        		mMap["000"] = tmp;
		        tmp = mMap["110"];
		        mMap["110"] = mMap["111"];
		        mMap["111"] = mMap["101"];
		        mMap["101"] = mMap["100"];
		        mMap["100"] = tmp;
                	break;
		}
		++i;
	}
}

void Cube::dRotate(int index){
	int i = 0;
        for(std::vector<std::map<std::string, char> > :: iterator it = mVec.begin(); it != mVec.end(); ++it) {
                if(i == index ){
                        std::map<std::string, char> &mMap = *it;
        		char tmp = mMap["001"];
		        mMap["001"] = mMap["011"];
		        mMap["011"] = mMap["010"];
		        mMap["010"] = mMap["000"];
		        mMap["000"] = tmp;
		        tmp = mMap["101"];
		        mMap["101"] = mMap["111"];
		        mMap["111"] = mMap["110"];
		        mMap["110"] = mMap["100"];
		        mMap["100"] = tmp;
			break;
                }
		++i;
	}

}


void CubeControler:: parseText (std::string str){
	int i = 0;
	if((str.length() % 8) == 0) {
		i = str.length() / 8;
	}
	else {
		i = str.length() / 8 + 1;
	}
	for(int j = 0 ; j < i; ++j) {
		char buffer[9];
  		std::size_t length = str.copy(buffer, 8, j * 8);
  		buffer[length]='\0';
		writeVector(buffer);
	}
}


void CubeControler:: encription(std::string str) {
	if(str.length() < 3){
		std::cout<< " rotate not executed , enter new version " <<std::endl;
		return;
	}
	std::size_t pos = 0;
        int i = 0;
        std::string token,tok;
        while(str[i] != '\0') {
                pos = str.find(",",pos);
                if(pos != std::string::npos) {
                	token = str.substr(i, pos - i);
                	pos++;
                	i = pos;
                }
                else {
                        token = str.substr(i,str.length() - i );
                	i = str.length();
                }
                int num ;
                std::string a = token.substr(0, 1);
                size_t found1 = a.find_first_not_of("1234567890");
                if(found1 != std::string::npos){
                        std::cout<<"number of Cube have not " << std::endl;
                        return;
                }
                else {
                        num = stoi(a);
                }
		int j = 1;
		while (token[j] != '\0') {
			if(token[j] == ':' && token[j + 1]  != '\0'){
				switch (token[j+1]) {
					case 'l': case 'L': {
								rotate(num,'l');
								break;
							}
					case 'r': case 'R': {
                                                                rotate(num,'r');
                                                                break;
                                                        }
					case 'u': case 'U': {
                                                                rotate(num,'u');
                                                                break;
                                                        }
					case 'd': case 'D': {
                                                                rotate(num,'d');
                                                                break;
                                                        }
					default : {
							  std::cout << token[j +1 ] << " this rotate have not"<<std::endl;
							  return;
						  }
				}
			}
			else {
				std::cout<< " : error " << std::endl;
			        return;
			}
			j = j + 2;	
		}
	}
}

void CubeControler:: rotate(int pos,char ch) {
	switch (ch) {
		case 'l': {
			      lRotate(pos);
                              break;
                          }
                case 'r': {
                              rRotate(pos);
                              break;
                          }
                case 'u': {
			      uRotate(pos);
                              break;
                          }
                case 'd': {
                              dRotate(pos);
                              break;
                          }
                default : {
                              break;
                          }
                          
	}
}
void CubeControler:: decription(std::string str) {
	reverse(str.begin(), str.end());
	std::size_t pos = 0;
	int i = 0;
	std::string token,tok;
	while(str[i] != '\0') {
		pos = str.find(",",pos);
		if(pos != std::string::npos) {
			token = str.substr(i, pos - i);
			pos++;
			i = pos;
		}
		else { 
			token = str.substr(i,str.length() - i );
			i = str.length();
		}
		int num ; 
		std::string a = token.substr(token.length() - 1, 1);
		size_t found1 = a.find_first_not_of("1234567890");
                if(found1 != std::string::npos){
			std::cout<<"number of cube dose not"<<std::endl;
                        return;
                }
                else {
                        num = stoi(a);
                }
		int ix = 0;
		while (token[ix + 1] != '\0') {
                	if(token[ix + 1] == ':' && token[ix + 2]  != '\0'){
				switch (token[ix]) {
                                        case 'l': case 'L': {				    
                                                                rotate(num,'r');
                                                                break;
                                                            }
                                        case 'r': case 'R': {
                                                                rotate(num,'l');
                                                                break;
                                                            }
                                        case 'u': case 'U': {
                                                                rotate(num,'d');
                                                                break;
                                                            }
                                        case 'd': case 'D': {
                                                                rotate(num,'u');
                                                                break;
                                                            }
                                        default : {
                                                          std::cout <<  " this rotate have not"<<std::endl;
                                                          return;
                                                  }
                                }
			}
                        else {
                                std::cout<< " : error " << std::endl;
                                return;
                        }
                ix = ix + 2;
                }
	}
}

void Cube:: read() {
	for(std::vector<std::map<std::string, char> > :: iterator it = mVec.begin(); it != mVec.end(); ++it) {
                std::map<std::string, char> &mMap = *it;
	        std::cout<<mMap["000"]<<mMap["100"]<<mMap["110"]<<mMap["010"]<<mMap["001"]<<mMap["101"]<<mMap["111"]<<mMap["011"]
			       <<std::endl;
	}
}
