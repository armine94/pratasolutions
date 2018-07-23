#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
};
class List {
    struct Node* head,* tail;
public:
    List() {
        head = tail = NULL;
    }
    void enQueue();
    int deQueue();
    void displayQueue();
    int elem;
    int choice;
};
void List::enQueue() {
    cout << "Enter your element to be inserted the queue:" << endl;
    cin >> elem;
    Node* pointer = new Node;
    pointer -> data = elem;
    pointer -> next = NULL;
    if(head == NULL) {
        head = pointer;
    }
    else
        tail -> next = pointer;
        tail = pointer;
        cout << "Element has been inserted in the queue!" << endl;
}
int List::deQueue() {
    if(head == NULL){
        cout << "Queue is empty!" << endl;
	return 1;
    }
    Node* temp = head;
    head = head -> next;
    delete temp;
    return -1;
}
void List::displayQueue() {
    Node* pointer1 = head;
    if(head == NULL) {
        cout << "Queue is empty!" << endl;
    }
    else
    cout << "Elements of your QUEUE!" << endl;
    while (pointer1 != NULL) {
        cout << pointer1 -> data << endl;
        pointer1 = pointer1 -> next;
    }
    cout << "End" << endl;
}

class Queue : private List {
	public:
void menu() {
    int a = 1;
    while(a)
   {
    cout<<"     1. Queue"<<"\n";
    cout<<"     2. Dequeue"<<"\n";
    cout<<"     3. Display Queue"<<"\n";
    cout<<"     4. Exit"<<"\n";
    cout << endl;
    cout << endl;
      cout<<"\nEnter your choice: ";
      cin>>choice;
      switch(choice)
      {
       case 1:
      enQueue();
      break;
       case 2:{
	if(deQueue() == 1){
		a = 0;
	}
      break;
	      }
       case 3:
      displayQueue();
      break;
       case 4:
      a = 0;
      break;
       default:
      cout<<"Please enter correct choice(1-4)!!";
      break;
       }
   }
}
};
int main () {
    Queue frank;
    frank.menu();
}
