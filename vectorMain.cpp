#include <iostream>
#include "vector.h"

int main()
{
    vector* obj = new vector();
    
    obj->push_back(4);
    obj->push_back(5);
    obj->push_back(6);
    obj->push_back(7);
    obj->insert_at(2,9);
    obj->insert_at(4,127);
    std::cout << "get element at index " << obj->get_at(2) << std::endl;
    std::cout << "array size is " << obj->get_size() << std::endl;
    
   return 0;
}