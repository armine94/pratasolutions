#include <iostream>

class vector {
public:
	int	m_size;
	int*	m_arr;
	vector(){
	    m_size = 0;
	    m_arr = new int [m_size];
    	}
	~vector(){
        delete[] m_arr;
    	}

	vector(const vector &copy){
        	this->m_size = copy.m_size;
        	this->m_arr = new int[copy.m_size];
        	for (int i = 0; i < m_size; ++i) {
            	this->m_arr[i] = copy.m_arr[i];
        	}
    	}

     	void operator = (const vector& op){
        	this->m_size = op.m_size;
        	if(this->m_arr != nullptr){
            		delete[] m_arr;
        	}
        	this->m_arr = new int[op.m_size];
        	for(int i = 0 ; i < op.m_size; ++i){
            		this->m_arr[i] = op.m_arr[i];
        	}
    	}
	
	int get_elem(int num){
                if(num <= m_size) {
                	return m_arr[num];
                }
        }

    	int get_size(){
        	return m_size;
    	}
	void push_back(const int value){
                int* tmp = new int [1 + m_size];
                for (int i = 0; i < m_size; ++i) {
                        tmp[i] = m_arr[i];
                }
                delete[] m_arr;
                m_arr = tmp;
                m_arr[m_size ] = value;
                m_size =  1 + m_size;
        }

        int pop() {
            if(m_size == 0) {
                    std::cout << "Stack is empty "<< std::endl;
                    return 1;
            }
            m_arr[m_size--];
	    return -1;
        }

};

class Stack : private vector{
	public:
	void menu(){
		int iz = 1;
		int choice;
		while(iz){
			std::cout<< "     1. Push_back" << "\n";
			std::cout<< "     2. Pop" << "\n";
			std::cout<< "     3. Display Stack" << "\n";
			std::cout<< "     4. Exit" << "\n";
			std::cout<< "	  \nEnter your choice: ";
			std::cin>>choice;
                switch(choice){
       			case 1: {
		        	std::cout<< "enter number" << std::endl;
                		int in;
                		std::cin>>in;
      				push_back(in);
      				break;
	       			} 
       			case 2:{
				if(pop() == 1){
					iz--;
				}
      				break;
				}
       				case 3:
      				print();
      				break;
       				case 4:
				iz--;
      				break;
       				default:
      				std:: cout<<"Please enter correct choice(1-4)!!\n";
      				break;
				}
		    	}
		}
	void print (){
		for(int i = 0; i < get_size(); ++i) {
			std::cout << get_elem(i) << std::endl;
		}
	}
};

int main(){
	Stack* obj = new Stack();
	obj->menu();

	return 0;
}

