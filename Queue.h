//
// Created by ofir1 on 29-May-22.
//

#ifndef EX3_QUEUE_H
#define EX3_QUEUE_H
//typedef int T;
//static const int NULL = 0;
#include <iostream>

//template<class T>
//template<class T,typename transform_func>
//typedef void (*transform_func)(T&);
//
//template<class T, filter_funct>
//typename bool (*filter_funct)(T);

template<class T>
struct Node{
    T data;
    Node *next;
};

template<class T>
class Queue {
    int count;
    Node<T> *head,*tail;
    template<class transform_func>
    friend void transform(Queue& queue, transform_func func);
public:
    Queue();
    Queue(const Queue& s);
    ~Queue();
    Queue& operator=(const Queue&);
    //Enters item to end of line, saves copy.
    void pushBack(const T& t);
    //Return the first item in Queue
    T& front();
    // Delete the first item in Queue
    void popFront();
    // return the size of Queue
    int size();
    // Exception:
    class EmptyQueue {};
    class Iterator;
    Iterator begin() const;
    Iterator end() const;
};

template<class T>
class Queue<T>::Iterator {
    const Queue* queue;
    Node<T>* current_node;
    Iterator(const Queue* queue,Node<T>* position):
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

template<class T>
Queue<T>::Queue():
        head(NULL),
        tail(NULL),
        count(0){
}

template<class T>
void Queue<T>::pushBack(const T &t) {
    Node<T> *temp=new Node<T>;
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

template<class T>
T& Queue<T>::front() {
    T& temp = this->head->data;
    return temp;
}

template<class T>
Queue<T> ::~Queue()
{
    while(head !=NULL)
    {
        Node<T> *temp=head;
        head=head->next;
        delete temp;
    }
    tail=NULL;
}

template<class T>
Queue<T>& Queue<T>::operator=(const Queue<T>& queue){
    Queue temp= Queue();
    for (Queue::Iterator it = queue.begin(); it != queue.end(); ++it) {
        this->pushBack( *it);
    }
    return *this;
};

template<class T>
Queue<T>::Queue(const Queue<T> &s) :
    count(0),
    head(NULL),
    tail(NULL)
    {
    for (Queue::Iterator it = s.begin(); it != s.end(); ++it) {
        pushBack( *it);
    }
}


template<class T>
int Queue<T>::size() {
    return this->count;
}

template<class T>
void Queue<T>::popFront() {
    if(this->count == 0) throw Queue::EmptyQueue();
    if(this->head==this->tail) {
        this->head = this->tail = NULL;
        --count;
    }
    else {
        Node<T> *temp=this->head;
        this->head=this->head->next;
        delete temp;
        --count;
    }
}

/// Iterator Implementations:

template<class T>
bool Queue<T>::Iterator::operator!=(const Iterator& it) const{
    bool equal = *this==it;
    return not equal;
};

template<class T>
bool Queue<T>::Iterator::operator==(const Iterator& it) const{
    if (it.current_node==this->current_node){
        return true;
    }
    else {
        return false;
    }
};

template<class T>
typename Queue<T>::Iterator& Queue<T>::Iterator::operator++() {
    if (current_node==NULL) {
        throw Iterator::InvalidOperation();
    }
    this->current_node = this->current_node->next;
}

template<class T>
const T& Queue<T>::Iterator::operator*() const {
    T& temp = this->current_node->data;
    return temp;
}

//T& Queue::Iterator::operator*() const {
//    T& temp = this->current_node->data;
//    return temp;
//};

template<class T>
typename Queue<T>::Iterator Queue<T>::begin() const {
    return Iterator(this, head);
}

template<class T>
typename Queue<T>::Iterator Queue<T>::end() const {
    return Iterator(this, NULL);
}



template<class T,typename filter_funct>
Queue<T> & filter(const Queue<T>& queue, filter_funct condition)
{
    Queue<T> *temp= new Queue<T>();
    for (typename Queue<T>::Iterator it = queue.begin(); it != queue.end(); ++it) {
        if (condition(*it)) {
            (*temp).pushBack( *it);
        }
    }
    return *temp;
}

template<class T,typename transform_func>
void transform(Queue<T>& queue, transform_func func)
{
    Node<T> * position = queue.head;
    while(position!=NULL){
        func(position->data);
        position= position->next;
    }
}
#endif //EX3_QUEUE_H


