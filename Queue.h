
#ifndef EX3_QUEUE_H
#define EX3_QUEUE_H

#include <iostream>

//Node Struct for linked list
template<class T>
struct Node{
    T data;
    Node *next;
};

// Queue Class interface
template<class T>
class Queue {
    int m_count;
    Node<T> *head;
    Node<T> *tail;
public:
    Queue();
    Queue(const Queue& s);
    ~Queue();
    Queue& operator=(const Queue&);
    //Enters item to end of line, saves copy.
    void pushBack(const T& t);
    //Return the first item in Queue
    T& front() const;
    // Delete the first item in Queue
    void popFront();
    // return the size of Queue
    int size() const;
    // Exception:
    class EmptyQueue {};
    //Iterator
    class Iterator;
    Iterator begin() {return Iterator(this, head);};
    Iterator end() {return Iterator(this, NULL);};
    //Const Iterator
    class ConstIterator;
    ConstIterator begin() const {return ConstIterator(this, head); };
    ConstIterator end() const {return ConstIterator(this, NULL);
    };

};

//Queue Iterator - Non const.
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
    T& operator*() const;
    Iterator& operator++();
    bool operator==(const Iterator& it) const;
    bool operator!=(const Iterator& it) const;
    class InvalidOperation{};
};

///======Queue Template Implementations =========
template<class T>
Queue<T>::Queue():
        m_count(0),
        head(NULL),
        tail(NULL)
        {
}

template<class T>
void Queue<T>::pushBack(const T &t) {
    Node<T> *temp=new Node<T>;
    //handling std::bad_alloc:
    try{
        temp->data=t;
    } catch (const std::bad_alloc& e){
        delete temp;
        throw;
    }
    temp->next=NULL;

    if (m_count==0){
        head=temp;
    }
    else{
        this->tail->next=temp;
    }
    tail=temp;
    m_count++;
}

template<class T>
T& Queue<T>::front() const {
    if (this->m_count==0) {
        throw Queue<T>::EmptyQueue();
    }
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
    //empty current values:
    while(m_count>0){
        popFront();
    }
    //load new values:
    try {
        for (Queue::ConstIterator it = queue.begin(); it != queue.end(); ++it) {
            this->pushBack( *it);
        }
    }
    catch (const std::bad_alloc& e) {
        while(m_count>0){
            this->popFront();
        }
        throw;
    }
    return *this;
}

template<class T>
Queue<T>::Queue(const Queue<T> &s) :
    m_count(0),
    head(NULL),
    tail(NULL)
    {
    try{
        for (Queue::ConstIterator it = s.begin(); it != s.end(); ++it) {
            pushBack( *it);
        }
    } catch(const std::bad_alloc& e) {
            while (m_count>0) {
                popFront();
            }
            throw;
    }
}


template<class T>
int Queue<T>::size() const {
    return this->m_count;
}

template<class T>
void Queue<T>::popFront() {
    if(this->m_count == 0) throw Queue::EmptyQueue();
    if(this->head==this->tail) {
        Node<T> *temp=this->head;
        delete temp;
        this->head = this->tail = NULL;
        --m_count;
    }
    else {
        Node<T> *temp=this->head;
        this->head=this->head->next;
        delete temp;
        --m_count;
    }
}


///======Iterator Template Implementations =========
template<class T>
bool Queue<T>::Iterator::operator!=(const Iterator& it) const{
    bool equal = *this==it;
    return not equal;
}

template<class T>
bool Queue<T>::Iterator::operator==(const Iterator& it) const{
    if (it.current_node==this->current_node){
        return true;
    }
    else {
        return false;
    }
}

template<class T>
typename Queue<T>::Iterator& Queue<T>::Iterator::operator++() {
    if (current_node==NULL) {
        throw Iterator::InvalidOperation();
    }
    this->current_node = this->current_node->next;
    return *this;
}


template<class T>
T& Queue<T>::Iterator::operator*() const {
    T& temp = this->current_node->data;
    return temp;
}

///======Queue transform& Filter functions Template Implementations =========
template<class T,typename filter_funct>
Queue<T>  filter(const Queue<T>& queue, filter_funct condition)
{
    Queue<T> temp= Queue<T>();
    for (typename Queue<T>::ConstIterator it = queue.begin(); it != queue.end(); ++it) {
        if (condition(*it)) {
            temp.pushBack( *it);
        }
    }
    return temp;
}

template<class T,typename transform_func>
void transform(Queue<T>& queue, transform_func func)
{
    for (typename Queue<T>::Iterator it = queue.begin(); it != queue.end(); ++it) {
        func(*it);
    }
}

///======ConstIterator Template Implementations =========
template<class T>
class Queue<T>::ConstIterator {
    const Queue* queue;
    Node<T>* current_node;
    ConstIterator(const Queue* queue,Node<T>* position):
            queue(queue),
            current_node(position){
    };
    friend class Queue;
public:
    ConstIterator(const ConstIterator&) = default;
    ConstIterator& operator=(const ConstIterator&) = default;
    const T& operator*() const;
    ConstIterator& operator++();
    bool operator==(const ConstIterator& it) const;
    bool operator!=(const ConstIterator& it) const;
    class InvalidOperation{};
};


template<class T>
const T& Queue<T>::ConstIterator::operator*() const {
    T& temp = this->current_node->data;
    return temp;
}

template<class T>
bool Queue<T>::ConstIterator::operator!=(const ConstIterator& it) const{
    bool equal = *this==it;
    return not equal;
}

template<class T>
bool Queue<T>::ConstIterator::operator==(const ConstIterator& it) const{
    if (it.current_node==this->current_node){
        return true;
    }
    else {
        return false;
    }
}

template<class T>
typename Queue<T>::ConstIterator& Queue<T>::ConstIterator::operator++() {
    if (current_node==NULL) {
        throw ConstIterator::InvalidOperation();
    }
    this->current_node = this->current_node->next;
    return *this;
}
#endif //EX3_QUEUE_H


