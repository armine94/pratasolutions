#include <iostream>

template <typename T>
class List {
	public : 
		List(){
			head = NULL;
		}

		void insert(int pos,const T& elem){
			Node* tmp = new Node();
		        int cout = size();
        		if(pos == 0) {
                		tmp->data = elem;
		                tmp->next = head;
		                head = tmp;
        		}
			
		        else  if (pos < cout && pos > 0){
		                Node* prev = head;
				tmp->data = elem;
				int i ;
                		for( i = 0; i < pos - 1;++i){
		                      prev = prev->next;
                		}
		                tmp->next = prev->next;
                		prev->next = tmp;

        		}
			else if (pos > 0 && pos == cout) {
				Node* tmp = new Node();
				Node* cur = head;
				tmp->data = elem;
				for(int i = 0; i<pos-1; ++i){
					cur= cur->next;
				}
				cur->next = tmp;
			}
		}

		void remove(int pos){
			Node* tmp = new Node;
			Node* cur = head; 
			int count = size();
			if(pos > -1 && pos < count ){
				for(int i = 0; i < count - 2;++i){
					std::cout<<"=== "<<cur->data<<std::endl;
					cur = cur->next;
					if(i == pos-1) {
						tmp= cur->next;
						cur = tmp;
					}
				}
			}
			else {
				std::cout<<"that position don't have\n";
			
			}
		}
		int find(const T& elem) {
			Node* tmp = head;
			for(int i = 0; i < size() - 1; ++i) {
				if(tmp->data == elem) {
					return i;
				}
				//else {
				//	std::

				tmp = tmp->next;
			}
			return -1;
		}
		void print(){
		        int a = 0;
		        Node* cur =head;
		        while(cur != NULL) {
                		std::cout<<cur->data<<std::endl;
		                cur = cur->next ;
                	}
		}
		int size(){
		        int size = 0;
		        Node* tmp = head;
		        while(tmp != NULL) {
                		++size;
		                tmp = tmp->next;
        		}
		        return size;
		}

	private :
		struct Node {
			T data;
			Node* next;
		};
		Node* head;




};


int main() {
	int b = 20;
        List<int> a;
        a.insert(0,b);
        a.insert(0,b++);
        a.insert(0,++b);
        a.insert(1,b + 100);
	a.insert(4,b--);
	a.insert(2,b + 6);
	a.insert(0,200);
	a.remove(3);
	int k = a.find(22);
	std::cout<<"find = "<<k<<std::endl;
        a.print();
        return 0 ;
}

