#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
};
class Queue {
    struct Node* head,* tail;
public:
    Queue() {
        head = tail = NULL;
    }
    void enQueue();
    void deQueue();
    void displayQueue();
    void menu();
    int elem;
    int choice;
};
void Queue::enQueue() {
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
void Queue::deQueue() {
    if(head == NULL){
        cout << "Queue is empty!" << endl;
    }
    Node* temp = head;
    head = head -> next;
    delete temp;
}
void Queue::displayQueue() {
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
void Queue::menu() {
    while(1)
   {
    cout<<"==============================================================="<<"\n";
    cout<<"              MENU - QUEUE(FIFO - First In First Out)                                 "<<"\n";
    cout<<"==============================================================="<<"\n";
    cout<<"     1. Queue"<<"\n";
    cout<<"     2. Dequeue"<<"\n";
    cout<<"     3. Display Queue"<<"\n";
    cout<<"     4. Exit"<<"\n";
    cout<<"==============================================================="<<"\n";
    cout << endl;
    cout<<"==============================================================="<<"\n";
    cout << endl;
    cout << endl;
      cout<<"\nEnter your choice: ";
      cin>>choice;
      switch(choice)
      {
       case 1:
      enQueue();
      break;
       case 2:
      deQueue();
      break;
       case 3:
      displayQueue();
      break;
       case 4:
      break;
       default:
      cout<<"Please enter correct choice(1-4)!!";
      break;
       }
   }
}
int main () {
    Queue frank;
    frank.menu();
}
