#include <iostream>
class stack{
    private:
        int* _arr;
        int  _size;
        int  _top;
        
    public:
        stack(const int sz);
        void push(const int value);
        int  pop();
        ~stack();
};

