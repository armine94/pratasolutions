#include "vector.h"

   vector::vector(){
    m_size = 0;
    m_arr = new int [m_size];
    }
    
    vector::~vector(){
        delete[] m_arr;
    }
    
    vector::vector(const vector &copy){
        this->m_size = copy.m_size;
        this->m_arr = new int[copy.m_size];
        for (int i = 0; i < m_size; ++i) {
            this->m_arr[i] = copy.m_arr[i];
        }
    }
    
    void vector:: operator = (const vector& op){
        this->m_size = op.m_size;
        if(this->m_arr != nullptr){
            delete[] m_arr;
        }
        this->m_arr = new int[op.m_size];
        for(int i = 0 ; i < op.m_size; ++i){
            this->m_arr[i] = op.m_arr[i];
        }
    }
    
    void vector:: push_back(const int value){
      
        int* tmp = new int [1 + m_size];
        for (int i = 0; i < m_size; ++i) {
            tmp[i] = m_arr[i];
        }
        
        delete[] m_arr;
        m_arr = tmp;
        m_arr[m_size ] = value;
        m_size =  1 + m_size;
    }
    
    void vector:: insert_at(int index, int elem){
        int* tmp = new int [1 + m_size];
        for (int i = 0; i <= m_size; ++i) {
             if(i < index){
                tmp[i] = m_arr[i];
            }
            else if(i == index) {
                tmp[i] = elem;
            }
            else{
                tmp[i] = m_arr[i-1];
            }    
        }
        delete[] m_arr;
        m_arr = tmp;
        m_size =  1 + m_size;
    }
    
    int vector:: get_at(int index){
        return m_arr[index];
    }
    
    int vector:: get_size(){
        return m_size;
    }
    
    
    
    
    
