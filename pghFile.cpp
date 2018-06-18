#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <map>
#include <utility>


std::map <std::pair<std::string,std::string>, std::string> myMap;
std::pair <std::string,std::string> myPair;
int convert(std::string);
int readLines(std::string);
int extention(std::string ,std::string );
int myOperatorDef(std::string,std::string);
int myOperatorMul(std::string,std::string);
int myOperatorDiv(std::string,std::string);
int myOperatorPluss(std::string,std::string);
int opSwitch(std::string,std::string,std::string);
void print(std::string);
void pghvar(std::string);
void pghvar(std::string,std::string,std::string); 
void print(std::string,std::string,std::string);
std::string convertString(std::string) ;

int main(int argc,char* argv[]) {
	std::string pafh = argv[1];
	std::string s1 = ".pgh";
  	int mmm = extention(pafh,s1);
	if(mmm != 1) {
	       	return 1;
	}
	else {
		if(readLines(pafh) == -1)
			return -1;
	}
	return 0;
}

int extention(std::string pafh, std::string extention) {
        std::size_t found = pafh.find(extention, pafh.length() - 4);
        if (found != (pafh.length() - 4)){
                std::cout << "file extention not .pgh " << std::endl;
		return -1;
        }
	return 1;
}

int readLines(std::string pafh) {
	std::string s2, s3, s4, s5, s6, s7, s8, s9, s10, s11;
	std::fstream fin;
        fin.open(pafh);
        if (!fin.is_open()) {
                std::cout<< "file dose not  open" << std:: endl;
                return -1;
        }
        while(!fin.eof()) {
        	std::string str;
                fin>>str;
                if (str == "pghvar") {
		
			fin>>s2;
			std::size_t c = s2.find(';', s2.length() - 1);
                                if( c <= s2.length() ) {
                                        s2 = s2.substr(0, s2.length() - 1);
					pghvar(s2);
				}
				else {
					fin>>s3;
					fin>>s4;
					pghvar(s2, s3, s4);
				}
		
			s2 = "";
			s3 = "";
			s4 = "";
			str = "";
        	}
		else if(str == "print"){
			s5 = "";
			s6 = "";
			s7 = "";
			fin>>s5;
			std::size_t c = s5.find(';', s5.length() - 1);
                                if( c <= s5.length() ) {
        //                  s5 = s5.substr(0, s5.length() - 1);
                                        print(s5);
                                }
                                else {
                                        fin>>s6;
                                        fin>>s7;
                                        print(s5, s6, s7);
                                }
			str = "";		
		}
		else { 
			s8 = "";
			s9 = "";
			s10 = "";
			s11 = "";
			fin>>s8;
			fin>>s9;
			std::size_t c = s9.find(';', s9.length() - 1);
                        if( c <= s9.length() ) {
                           	s9 = s9.substr(0, s9.length() - 1);
				std::map <std::pair<std::string, std::string>, std::string> ::iterator myIterator;
	                        for(myIterator = myMap.begin(); myIterator != myMap.end(); ++myIterator) {
        	         	       if(str != (myIterator->first).first) {
                        	       //                 std::cout <<str <<"not declarrr";
						return 1;
                                        }
                        	}
				int z = atoi(s9.c_str());
				for(myIterator = myMap.begin(); myIterator != myMap.end(); ++myIterator) {
                                	if(str == (myIterator->first).first) {
                                        	if( myIterator->second == "int") {
                                                	myMap.erase(myIterator);
                                                        myPair = make_pair(str, s9);
                                                        myMap.insert(std::make_pair(myPair, "int"));
                                                }
						else if(z) {
							myMap.erase(myIterator);
        	                                        myPair = make_pair(str, s9);
                	                                myMap.insert(std::make_pair(myPair, "int"));
						}
						else {
							myMap.erase(myIterator);
                       	                                myPair = make_pair(str, s9);
                              	                        myMap.insert(std::make_pair(myPair, "string"));
						}
                              		}
                       		}
			}	
			else {
				fin>>s10;
				fin>>s11;
				int q = 0;
				int w = 0;
				std::map <std::pair<std::string, std::string>, std::string> ::iterator myIterator;
				for(myIterator = myMap.begin(); myIterator != myMap.end(); ++myIterator) {
	                		if(str != (myIterator->first).first){
						//std::cout <<str<<" not declarrr"<<std::endl;
						return -1;
                       			}	
				}
				std::string ss, sss;
				int num1;
				std::size_t c = s11.find(';', s11.length() - 1);
         			if( c <= s11.length() ) {
                			s11 = s11.substr(0, s11.length() - 1);
    				}
				for(myIterator = myMap.begin(); myIterator != myMap.end(); ++myIterator) {
	                		if(s9 == (myIterator->first).first){
               		        		if( myIterator->second == "int") {
                               				ss = (myIterator->first).second;
                      		 	        	++q;
						}
					}
				}			
				for(myIterator = myMap.begin(); myIterator != myMap.end(); ++myIterator) {
	                		if(s11 == (myIterator->first).first){
               		        		if( myIterator->second == "int") {
                               				sss = (myIterator->first).second;
                              				++w;
                       				}
					}
				}
				if(q == 1) {
					if(w == 1) {
						num1 = opSwitch(ss, s10, sss);
		     			}
					else {
						num1 =  opSwitch(ss, s10, s11);
					}
				}
				else {
					if (w == 1) {
						num1 = opSwitch(s9, s10, sss);
					}
					else {
						num1 = opSwitch(s9, s10, s11);
					}
				}
				std::string ass = std::to_string(num1);
				for(myIterator = myMap.begin(); myIterator != myMap.end(); ++myIterator) {
                               		if(str == (myIterator->first).first) {
                               			if( myIterator->second == "int") {
							myMap.erase(myIterator);
				  			myPair = make_pair(str, ass);
							myMap.insert(std::make_pair(myPair, "int"));	
			       			}
                               		}
                       		}
			}
		}
	}

 	fin.close();
	return 1;
}

void pghvar(std::string var, std::string op, std::string value) {
         std::size_t b;
         std::size_t a = var.find(';', var.length() - 1);
         if( a <= var.length() ) {
                var = var.substr(0, var.length() - 1);
         }
         else {
                 b = value.find(';', value.length() - 1);
                 if(b <= value.length()){
                        value = value.substr(0,value.length()-1);
                 }
                 else{
                        std::cout<<"toxum ; @ chka"<<std::endl;
			return;
                 }
         }
	 int a1 = atoi(value.c_str());
	 if(a1){
		 myPair = make_pair(var, value);
                 myMap.insert(std::make_pair(myPair, "int"));
         }
         else {
		 myPair = make_pair(var, value);
                 myMap.insert(std::make_pair(myPair, "string"));
         }	
}

void pghvar(std::string var) {		
	 std::string value = " ";
	 std::string op = "string";
         std::size_t a = var.find(';', var.length() - 1);
         if( a <= var.length() ) {
                var = var.substr(0, var.length() - 1);
         }
         myPair = make_pair(var, value);
         myMap.insert(std::make_pair(myPair,op));
         
}


void print(std::string var, std::string op, std::string var1) {
	int ascChar;
	std::string a1 = var;
	std::string a2 = var1;
	if(var1.find(';', var1.length() - 1)){
                var1 = var1.substr(0, var1.length()-1);
        }

	std::map <std::pair<std::string, std::string>, std::string> :: iterator myIterator;
       for(myIterator = myMap.begin(); myIterator != myMap.end(); ++myIterator) {
	       if(var == (myIterator->first).first){
        	       if(myIterator->second == "int") {
	                    a1 = (myIterator->first).second;
			}
		   }
	       }
	for(myIterator = myMap.begin(); myIterator != myMap.end(); ++myIterator) {
               if(var1 == (myIterator->first).first){
                        if(myIterator->second == "int") {
                            a2 = (myIterator->first).second;
			}
               }
        }
        for (int i = 0; i < op.length(); ++i) {
        ascChar = op[i];
    	}
        int resalt ;

        switch(ascChar) {
                case 43 : {
                        	resalt = myOperatorPluss(var, var1);
                        	break;
                          }
                case 42 : {
                        	resalt = myOperatorMul(var, var1);
                        	break;
                          }
                case 47 : {
                        	resalt = myOperatorDiv(var, var1);
                        	break;
                          }
                case 45 : {
                        	resalt = myOperatorDef(var, var1);
                        	break;
                          }
                default : {
                        	break;
                          }
	}
	std::cout<< resalt << std::endl;
}

void print(std::string var) {
	if(var.find(';', var.length() - 1)){
		var = var.substr(0, var.length()-1);
	}
	int a = 0; 
	std::string res;
        std::map <std::pair<std::string, std::string>, std::string> :: iterator myIterator;
        for(myIterator = myMap.begin(); myIterator != myMap.end(); ++myIterator) {
                if(var == (myIterator->first).first){
                        if(myIterator->second == "string") {
                                res = (myIterator->first).second;
				std::cout<< convertString(res) << std::endl;
				a = 1;
                        }

                }
        }
	if(a != 1){
		std::cout << convert(var) << std::endl;
	}
}
int convert(std::string var) {
	int res;
	std::string s;
	std::map <std::pair<std::string, std::string>, std::string> :: iterator myIterator;
        for(myIterator = myMap.begin(); myIterator != myMap.end(); ++myIterator) {
		if(var == (myIterator->first).first){
			if(myIterator->second == "int") {
				s = (myIterator->first).second;
				res = atoi(s.c_str());
			}				
		}
	}
	int aa = atoi(var.c_str());
        if(aa){	 	
		res = atoi(var.c_str());
	}		 
	
	return res;
}
std::string convertString(std::string var) {
	std::string res = var;
	res = res.substr(0, res.length() - 1);
	res = res.substr(1, res.length());
	return res;
}

int myOperatorPluss(std::string var1, std::string var2) {
	int a1 = convert(var1);
	int a2 = convert(var2);
	return convert(var1) + convert(var2);
}

int myOperatorMul(std::string var1, std::string var2) {
        return convert(var1) * convert(var2);
}

int myOperatorDiv(std::string var1, std::string var2) {
        return convert(var1) / convert(var2);
}

int myOperatorDef(std::string var1, std::string var2) {
        return convert(var1) - convert(var2);
}


int opSwitch(std::string var,std::string op,std::string var1) {
	int ascChar;
        for (int i = 0; i < op.length(); ++i) {
        	ascChar = op[i];
    	}
        int resalt ;
        switch(ascChar) {
                case 43 : {

				resalt = myOperatorPluss(var, var1);
                        	break;
                          }	
                case 42 : {
                        	resalt = myOperatorMul(var, var1);
                        	break;
                          }
                case 47 : {
                        	resalt = myOperatorDiv(var,var1);
                        	break;
                          }
                case 45 : {
                        	resalt = myOperatorDef(var,var1);
                        	break;
                          }
                default : {
                        	break;
                          }
	}
	return resalt;
}
