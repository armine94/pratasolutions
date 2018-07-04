
//Cube.h
#include <iostream>
#include <map>
#include <vector>

class Cube {
  
  private :
    std::map<std::string, char> tMap;				//cube
    std::vector <std::map<std::string, char> > mVec;		//cubes
  public :
    void uRotate(int);						//rotate cube upper
    void rRotate(int);						//rotate cube right
    void dRotate(int);						//rotate cube down
    void lRotate(int);						//rotate cube left
    void writeVector(char[]);					//write text     
    void read();						//read text
};

class CubeControler :public Cube {
  public:		
    void rotate(int pos, char);					//rotate pos-th cube rotates 
    void parseText(std::string);				//parse and write in cube
    void decription(std::string );				//decription text in cube 
    void encription(std::string);
    
    
};
