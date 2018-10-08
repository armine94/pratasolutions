#include <iostream>

class A {
	private :
		int pr_int;
	protected :
		double pr_d;
	public :
		A(int a,double d) {
			std::cout<<"constructor";
			this->pr_int = a;
			this->pr_d = d;
		}

		void foo(){}
		A* operator = (const A* op){
			std::cout<<"opttt";
			if(this == op) {
				std::cout<<"if";
				return this;
			}
			else {
				std::cout<<"else";
				this->pr_int = op->pr_int;
				this->pr_d = op->pr_d;
			}
			return this;
		}

};
int main()
{
	A a(4,88.7);
	A b(8,7.9);
	b = a;
	return 0;
}
