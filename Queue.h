//
// Created by Ofir Elyashiv & Alon Feldman
//

#ifndef EX3_QUEUE_H
#define EX3_QUEUE_H

// todo: check that support const queue and regular queue
// todo: Queue template (can be used with T)
// i just copied stack from tutorial 8 with iterator explanation from lecture 5 (page 41)
// they suggested to build with:
typedef int T;// instead of :
//template <class T>
class Queue {
    T* data;
    int maxSize;
    int nextIndex; // maybe irrelevant
    class Iterator;
    Iterator begin() const;
    Iterator end() const;
//    Iterator InvalidOperation(); todo: not sure how

public:
    explicit Queue(int maxSize = 100); //
    Queue(const Queue& s);
    ~Queue();
    Queue& operator=(const Queue&);

    //Enters item to end of line, saves copy.
    T pushBack(const T& t);
    //Return the first item in Queue
    T& front();
    // Delete the first item in Queue
    void popFront();
    // return the size of Queue
    int size();
    // Exception:
    class EmptyQueue {};

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
void front();
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



//
//class String {
//    int length;
//    char* value;
//public:	//...
//    typedef char* iterator;
//    typedef const char* const_iterator;	iterator begin() {		return value;	}
//    const_iterator begin() const {		return value;	}
//    iterator end() {		return value + length;	}
//    const_iterator end() const {		return value + length;	}	//...};


#endif //EX3_QUEUE_H
