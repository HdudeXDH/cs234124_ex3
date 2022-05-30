//
// Created by ofir1 on 29-May-22.
//

#ifndef EX3_QUEUE_H
#define EX3_QUEUE_H
typedef int T;
//static const int NULL = 0;
#include <iostream>
typedef void (*transform_func)(T&); //todo: validate


struct Node{
    T data;
    Node *next;
};


class Queue {
    int count;
    Node *head,*tail;
    friend void transform(Queue& queue, transform_func func);
public:
    Queue(); //todo: ofir
    Queue(const Queue& s); //todo: ofir
    ~Queue();
    Queue& operator=(const Queue&); //todo: alon
    //Enters item to end of line, saves copy.
    void pushBack(const T& t);
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

// page 45 lecture 5
class Queue::Iterator {
    const Queue* queue;
    Node* current_node;
    Iterator(const Queue* queue,Node* position):
    queue(queue),
    current_node(position){
    };
    friend class Queue;
public:
    Iterator(const Iterator&) = default;
    Iterator& operator=(const Iterator&) = default;
    const T& operator*() const;
//    T& operator*() const; //todo: delete me
    Iterator& operator++();
    bool operator==(const Iterator& it) const;
    bool operator!=(const Iterator& it) const;
    class InvalidOperation{};
};


Queue::Queue():
        head(NULL),
        tail(NULL),
        count(0){
}

void Queue::pushBack(const T &t) {
    Node *temp=new Node;
//    if(temp==NULL){
//        throw std::bad_alloc();
//    } todo: validate
    temp->data=t;
    temp->next=NULL;

    if (count==0){
        head=temp;
    }
    else{
        this->tail->next=temp;
    }
    tail=temp;
    count++;
//    return t;
}

T& Queue::front() {
    T& temp = this->head->data;
    return temp;
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
Queue& Queue::operator=(const Queue& queue){
//    Queue temp= Queue();
    for (Queue::Iterator it = queue.begin(); it != queue.end(); ++it) {
        this->pushBack( *it);
    }
    return *this;
};

Queue::Queue(const Queue &s) :
    count(0),
    head(NULL),
    tail(NULL)
    {
    for (Queue::Iterator it = s.begin(); it != s.end(); ++it) {
        pushBack( *it);
    }
}


//template <class T>
int Queue::size() {
    return this->count;
}

//template <class T>
void Queue::popFront() {
    if(this->count == 0) throw Queue::EmptyQueue();
    if(this->head==this->tail) {
        this->head = this->tail = NULL;
        --count;
    }
    else {
        Node *temp=this->head;
        this->head=this->head->next;
        delete temp;
        --count;
    }
}

/// Iterator Implementations:

bool Queue::Iterator::operator!=(const Iterator& it) const{
    bool equal = *this==it;
    return not equal;
};
bool Queue::Iterator::operator==(const Iterator& it) const{
    if (it.current_node==this->current_node){
        return true;
    }
    else {
        return false;
    }
};

Queue::Iterator& Queue::Iterator::operator++() {
    if (current_node==NULL) {
        throw Iterator::InvalidOperation();
    }
    this->current_node = this->current_node->next;
};


const T& Queue::Iterator::operator*() const {
    T& temp = this->current_node->data;
    return temp;
};

//T& Queue::Iterator::operator*() const {
//    T& temp = this->current_node->data;
//    return temp;
//};

Queue::Iterator Queue::begin() const {
    return Iterator(this, head);
}
Queue::Iterator Queue::end() const {
    return Iterator(this, NULL);
}
typedef bool (*filter_funct)(T);
Queue & filter(const Queue& queue, filter_funct condition)
{
    Queue *temp= new Queue();
    for (Queue::Iterator it = queue.begin(); it != queue.end(); ++it) {
        if (condition(*it)) {
            (*temp).pushBack( *it);
        }
    }
    return *temp;
}


void transform(Queue& queue, transform_func func)
{
    Node * position = queue.head;
    while(position!=NULL){
        func(position->data);
        position= position->next;
    }
}
//    Iterator operator++(int); //todo: alon
#endif //EX3_QUEUE_H


