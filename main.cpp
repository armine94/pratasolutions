#include <iostream>
#include "stack.h"

int main()
{
    stack* obj = new stack(105);
    
    obj->push(4);
    obj->push(5);
    obj->push(6);
    std::cout << obj->pop() << std::endl;
    std::cout << obj->pop() << std::endl;
    std::cout << obj->pop() << std::endl;    
    std::cout << obj->pop() << std::endl;
    obj->~stack();
    return 0;
}
