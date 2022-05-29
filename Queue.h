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
    void popFront();
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
//        throw std::bad_alloc();
//    } todo: validate
    temp->data=t;
    temp->next=NULL;
    tail=temp;
    if (count==0){
        head=temp;
    }
    count++;
    return t;
}

T& Queue::front() {
    T& temp = this->head->data;
    return  temp; //todo: maybe wrong &
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
    Node* current_node;
    Iterator(const Queue* queue,Node* position):
    queue(queue),
    current_node(position){};
    friend class Queue;
public:
    Iterator(const Iterator&) = default;
    Iterator& operator=(const Iterator&) = default;

    const T& operator*() const {
        T& temp = this->current_node->data;
        return temp;
    };

    Iterator& operator++() {
        if (current_node==queue->tail) {
            throw Iterator::InvalidOperation();
        }
        this->current_node = this->current_node->next;
    };

    bool operator==(const Iterator& it) const{
        if (it.current_node==this->current_node){
            return true;
        }
        else {
            return false;
        }
    };
    bool operator!=(const Iterator& it) const{
      bool equal = this==&it;
      return not equal;
    };
    class InvalidOperation{};
};


Queue::Iterator Queue::begin() const {
    return Iterator(this, head);
}
Queue::Iterator Queue::end() const {
    return Iterator(this, tail);
}

Queue& Queue::operator=(const Queue& queue){
    Queue temp= Queue();
    for (Queue::Iterator it = queue.begin(); it != queue.end(); ++it) {
        temp.pushBack( *it);
    }
};

Queue Queue(const Queue& s) {
    Queue temp = s;
    return temp;
}
//    Iterator operator++(int); //todo: alon
#endif //EX3_QUEUE_H


