#include "stack.h"



    stack::stack(const int sz){
        if (sz < 1) {
            std::cout << "size is small "  << std::endl;
            return ;
        }
    
    //this = new stack;
    _size = sz;
    _arr = new int [_size];
    _top = -1;
    
    }
    
    stack::~stack(){
        //delete this;
    }
    
    void stack:: push(const int value){
        if ( _top == (_size - 1)) {
            int* tmp = new int [2 * _size];
            for (int i = 0; i < _size; ++i) {
                tmp[i] = _arr[i];
            }
        
            delete[] _arr;
            _arr = tmp;
            _size = 2 * _size;
        }
        _arr[++_top] = value;
        
    }
    
    int stack:: pop(){
        if(_top == -1){
            std::cout<<"Stack is empty"<<std::endl;
            return -1;
        }
        return _arr[_top--];
    }
    
