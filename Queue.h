//
// Created by ofir1 on 29-May-22.
//

#ifndef EX3_QUEUE_H
#define EX3_QUEUE_H
typedef int T;
//static const int NULL = 0;
#include <iostream>

struct Node{
    T data;
    Node *next;
};


class Queue {
    int count;
    Node *head,*tail;
public:
    Queue(); //todo: ofir
    Queue(const Queue& s); //todo: ofir
    ~Queue();
    Queue& operator=(const Queue&); //todo: alon
    //Enters item to end of line, saves copy.
    T pushBack(const T& t);
    //Return the first item in Queue
    T& front();
    // Delete the first item in Queue
    void popFront(); //todo: ofir
    // return the size of Queue
    int size(); //todo: ofir
    // Exception:
    class EmptyQueue {};
    class Iterator;
    Iterator begin() const;
    Iterator end() const;
};

Queue::Queue():
    head(NULL),
    tail(NULL),
    count(0){
}

T Queue::pushBack(const T &t) {
    Node *temp=new Node;
//    if(temp==NULL){
//        cout<<"Overflow"<<endl;
//        return;
//    } todo: check
    temp->data=t;
    temp->next=NULL;
    tail=temp;
    if (count==0){
        head=temp;
    }
    count++;
    return t;
}
Queue& Queue::operator=(const Queue&){
    Queue temp();

};

T& Queue::front() {
    return this->head->data; //todo: maybe wrong &
}

Queue ::~Queue()
{
    while(head !=NULL)
    {
        Node *temp=head;
        head=head->next;
        delete temp;
    }
    tail=NULL;
}


// page 45 lecture 5
class Queue::Iterator {
    const Queue* queue;
    int index;
    Iterator(const Queue* queue, int index);
    friend class Queue;
public:
    const int& operator*() const; //todo: ofir
    Iterator& operator++(); //todo: ofir
    Iterator operator++(int); //todo: alon
    bool operator==(const Iterator& it) const;
    bool operator!=(const Iterator& it) const; //todo: alon
    Iterator(const Iterator&) = default; //todo: alon
    Iterator& operator=(const Iterator&) = default; //todo: ofir
    class InvalidOperation{};
};
#endif //EX3_QUEUE_H


//void Queue::insert(int n){
//    Node *temp=new Node;
//    if(temp==NULL){
//        cout<<"Overflow"<<endl;
//        return;
//    }
//    temp->data=n;
//    temp->next=NULL;
//
//    //for first node
//    if(front==NULL){
//        front=rear=temp;
//    }
//    else{
//        rear->next=temp;
//        rear=temp;
//    }
//    cout<<n<<" has been inserted successfully."<<endl;
//}
//
//void Queue::display(){
//    if(front==NULL){
//        cout<<"Underflow."<<endl;
//        return;
//    }
//    Node *temp=front;
//    //will check until NULL is not found
//    while(temp){
//        cout<<temp->data<<" ";
//        temp=temp->next;
//    }
//    cout<<endl;
//}
//
//void Queue :: deleteitem()
//{
//    if (front==NULL){
//        cout<<"underflow"<<endl;
//        return;
//    }
//
//    cout<<front->data<<" is being deleted "<<endl;
//    if(front==rear)//if only one node is there
//        front=rear=NULL;
//    else
//        front=front->next;
//}
//