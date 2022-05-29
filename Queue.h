//
// Created by ofir1 on 29-May-22.
//

#ifndef EX3_QUEUE_H
#define EX3_QUEUE_H
typedef int T

struct Node{
    T data;
    Node *next;
};


class Queue {
public:
    Node *head,*tail;
    int count;
    Queue(); //todo: ofir
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
    class EmptyQueue {};
    ~Queue();
};

void Queue::insert(int n){
    Node *temp=new Node;
    if(temp==NULL){
        cout<<"Overflow"<<endl;
        return;
    }
    temp->data=n;
    temp->next=NULL;

    //for first node
    if(front==NULL){
        front=rear=temp;
    }
    else{
        rear->next=temp;
        rear=temp;
    }
    cout<<n<<" has been inserted successfully."<<endl;
}

void Queue::display(){
    if(front==NULL){
        cout<<"Underflow."<<endl;
        return;
    }
    Node *temp=front;
    //will check until NULL is not found
    while(temp){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

void Queue :: deleteitem()
{
    if (front==NULL){
        cout<<"underflow"<<endl;
        return;
    }

    cout<<front->data<<" is being deleted "<<endl;
    if(front==rear)//if only one node is there
        front=rear=NULL;
    else
        front=front->next;
}

Queue ::~Queue()
{
    while(front!=NULL)
    {
        Node *temp=front;
        front=front->next;
        delete temp;
    }
    rear=NULL;
}
#endif //EX3_QUEUE_H
