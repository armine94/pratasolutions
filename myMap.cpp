#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <map>

std::map <std::string, std::string> myMap;

void print (std::string ,std::string , std::string, int) ;
int result(std::string, std::string, std::string, int);
int myOperatorDef(std::string, std::string);
int myOperatorMul(std::string, std::string);
int myOperatorDiv(std::string, std::string);
int myOperatorPluss(std::string, std::string);
int extention(std::string , std::string );
int readLines(std::string);
int convert(std::string);
std::string delLastChr(std::string);
std::string convertStr(std::string );

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
        int lineCount = 0 ;  
        std::fstream fin;
        fin.open(pafh);
        if (!fin.is_open()) {
                std::cout<< "file dose not  open" << std:: endl;
                return -1;
        }
        while(!fin.eof()) {
		++lineCount;
		int res;
                std::string str;
		std::string val, opr, var, opr1, val1;
		str = "";
		val = "";
		var = "";
		opr = "";
		val1 = "";
		opr1 = "";
                fin>>str;
                if (str == "pghvar") {
			fin>>var;
			std::size_t a = var.find(';', var.length() - 1);
                        if( a <= var.length() ) {
				var = var.substr(0, var.length() - 1);
					myMap[var] = "";
                        }
			else{
				fin>> opr;
				fin>> val;
				std::size_t a = val.find(';', val.length() - 1);
	                        if( a <= val.length() ) {
					val = val.substr(0, val.length() - 1);
					size_t found=val.find_first_not_of("1234567890");
					if (found != std::string::npos) {
						auto it = myMap.find(val);
						a = val.find('"', 0);
                                                size_t b = val.find('"',val.length() - 1);
						if(it->first == val) {
							myMap[var] = it->second;
						}
						else if((a == 0) && (b <= val.length())) {
							val = val.substr(0, val.length() - 1);
							val = val.substr(1, val.length());
							myMap[var] = val + " string";
						}						
						else {
							std::cout<< lineCount <<" toxum  stringi  nshan@ chka"<<std::endl;
							return -2;
						}
					}
					else {
						myMap[var] = val + " int";
					}
				}
				else {
					std::cout<< lineCount << "  toxum ; chka"<<std::endl;
					return -2;
				}
			}

		}
		else if (str == "print"){
			fin>>var;
                        std::size_t a = var.find(';', var.length() - 1);
                        if( a <= var.length() ) {
				var = delLastChr(var);
				size_t found = var.find_first_not_of("1234567890");
				if(found == std::string::npos) {
					std::cout<< var << std::endl;
				}
				else {	
					auto it = myMap.find(var);
                                        if (it == myMap.end()) {
						std::cout<< lineCount <<"undefine variable "<<std::endl;
					}
					else{
						std::string s = myMap[var];
						std::size_t pos = s.find("string",s.length() - 6);
						if( pos <= s.length()){
							std::cout << convertStr(s) << std::endl;
						}
						else {
							std::cout << convert(s) << std::endl;
						}
					}
                                }
			}
			else { 
				fin>>opr;
			 	if ( ( opr == "+" ) || ( opr == "-" ) ||( opr == "*" ) ||( opr == "/" ) ) {
					fin>>val;
			 		print(var, opr, val, lineCount);
				}
				else {
					std::cout<< lineCount <<"; dose not"<<std::endl;
				} 
			}
		}
		else {
			int res;
			var = str;
			auto it = myMap.find(var);
			std::size_t a = var.find(';', var.length() - 1);
			if(a <= var.length()) {
				var = var.substr(0,var.length() - 1);
				if (it == myMap.end()){
					std::cout<< lineCount <<"undefine variable "<<std::endl;
					return -3;
				}
			}
			else if(it != myMap.end()){
				fin>>opr;
				if (opr == "=") {
					fin>>val;
					std::size_t b = val.find(';', val.length() - 1);
                        		if(b <= val.length()) {
                                		val = val.substr(0,val.length() - 1);
						size_t found = val.find_first_not_of("1234567890");
						if(found != std::string::npos) {
							auto it = myMap.find(val);
							if (it == myMap.end()){
								size_t h = val.find('"',0);
								size_t e = val.find('"',val.length() - 1);
								if((h == 0) && (e <= val.length())) {
                                                                	val = val.substr(0, val.length() - 1);
                                                                	val = val.substr(1, val.length());
                                                                	myMap[var] = val + " string";      
								}
                                                        	else    {
                                                                	std::cout<< lineCount <<" toxum  stringi  nshan@ chka"<<std::endl;
                                                                	return -2;
                                                        	}
							}
							else {
								myMap[var] = myMap[val] + " string";
							}
                                		}
						else {
							myMap[var] = val + "int";
						}
					}
					else {
						fin>>opr1;
					       	if((opr1 == "+") || (opr1 == "-") || (opr1 == "*") || (opr1 == "/")){
							fin>>val1;
							std::size_t d = val1.find(';', val1.length() - 1);
        	                                	if(d <= val1.length()) {
								res = result(val,opr1,val1, lineCount);
								std::string s = std::to_string(res);
								myMap[var] = s + "int";
        						}
							else {
								std::cout<< lineCount <<"; dose not"<<std::endl;
							}
						}
					
						else {
							std::cout<< lineCount <<"operator " << opr1 <<"undefine"<< std::endl; 
							return -4;
						}
					}
                        	}
			}

		}
	}
}


std::string delLastChr(std::string s){
	std::size_t a = s.find(';', s.length() - 1);
	s = s.substr(0, s.length() - 1);
	return s;
}

int convert(std::string var){
	var = var.substr(0,var.length() - 3 );
	return atoi(var.c_str());
}
std::string convertStr(std::string var) {
	var = var.substr(0,var.length() - 6 );
	return var;
}

void print (std::string var1,std::string op,std::string var2, int lCount) {
	int res;
	res = result(var1, op, var2,lCount);
	std::cout<< res << std::endl;
}

int result(std::string var1,std::string op,std::string var2, int lCount) {
	int ascChar,val1,val2;
        std::string var,var3;
	std::size_t dd = var2.find(';', var2.length() - 1);
        if(dd <= var2.length()) {
  		var2 = var2.substr(0,var2.length() - 1);
	        size_t found1 = var1.find_first_not_of("1234567890");
        	size_t found2 = var2.find_first_not_of("1234567890");
	        val1 = atoi(var1.c_str());
        	val2 = atoi(var2.c_str());
	        if(found1 != std::string::npos) {
        	        var = myMap[var1];
                	std::size_t pos = var.find("int", var.length() - 3);
                	if( pos <= var.length()) {
                        	val1 = convert(var);
                	}
			else {
				std::cout<<lCount<< "error ";
				return -5;
			}	
		}
        	if(found2 != std::string::npos) {
                	var3 = myMap[var2];
                	std::size_t pos1 = var3.find("int", var3.length() - 3);
                	if( pos1 <= var3.length()) {
                        	val2 = convert(var3);
                	}
        	}

		for (int i = 0; i < op.length(); ++i) {
                	ascChar = op[i];
                	}
        	int result ;

   	     switch(ascChar) {
        	        case 43 : { 
                	                result = val1 + val2;
                        	        break;
                        	  }
              		case 42 : {
                        	        result = val1 * val2;
                                	break;
                          	  }
                	case 47 : {
                        	        result = val1 / val2;
                                	break;
                        	  }
                	case 45 : {
                        	        result = val1 - val2;
                                	break;
                        	  }
                	default : {
                        	        break;
                         	 }
       		}

		return result;
	}
	else {std::cout<< lCount <<"; dose not	";
		return -5;
	}
}
