//
// Created by Ofir  & Alon Shkafkafim
//

#ifndef EX3_QUEUE_H
#define EX3_QUEUE_H

// todo: check that support const queue and regular queue
// todo: Queue template (can be used with T)
// i just copied stack from tutorial 8 with iterator explanation from lecture 5 (page 41)
// they suggested to build with:
//typedef int T;// instead of :
template <class T>
class Queue {
public:
    explicit Queue(int maxSize = 100); //todo: ofir
    Queue(const Queue& s); //todo: ofir
    ~Queue(); //todo: alon
    Queue& operator=(const Queue&); //todo: alon
    //Enters item to end of line, saves copy.
    T pushBack(const T& t); //todo: alon
    //Return the first item in Queue
    T& front(); //todo: alon
    // Delete the first item in Queue
    void popFront(); //todo: ofir
    // return the size of Queue
    int size(); //todo: ofir
    // Exception:
    bool isEmpty();
    bool isFull();
    class EmptyQueue {};
private:
    T* *array;
    int maxSize;
    int head;
    int tail;
    int count;
    class Iterator;
    Iterator begin() const;
    Iterator end() const;

};

template <class X>
Queue<T>::Queue(int size)
{
    arr = new T[size];
    maxSize = size;
    head = 0;
    tail = -1;
    count = 0;
}

template <class T>
Queue<T>::Queue(int maxSize) {

}

template <class T>
void Queue<T>::popFront() {

}

template <class T>
int Queue<T>::size() {
    return this->count;
}


template <class T>
bool Queue<T>::isEmpty() {
    return this->count == 0;
}

template <class T>
bool Queue<T>::isFull() {
    return this->count == this->maxSize;
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
//template <class T>
//Stack<T>& Stack<T>::operator=(const Stack<T>& s) {
//    if (this == &s) {
//        return *this;
//    }
//    T* tempData = new T[s.maxSize];
//    try {
//        maxSize = s. maxSize;
//        nextIndex = s.nextIndex;
//        for (int i = 0; i < nextIndex; ++i) {
//            data[i] = s.data[i];
//        }
//    } catch (…) {
//        delete[] tempData;
//        throw;
//    }
//    delete[] data;
//    data = tempData;
//    return *this;
//}


// todo: Queue filter(queue, condition):
// return queue with filtered values by the described condition
//template<class T>
//template<class Condition>
typedef bool Condition; //todo: delete and replace with template?
Queue filter(Queue queue, Condition condition) {

}
//
//// todo: Queue transform(queue, operation):
//// take a queue and preforms "operation" on each element
//template<class T>
//template<class Operation>
typedef bool Operation; //todo: delete and replace with template?
Queue transform(Queue queue, Operation operation){

}



#endif //EX3_QUEUE_H
