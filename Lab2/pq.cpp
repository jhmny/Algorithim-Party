#include <iostream>

 template <typename Type>
 class Node
{     
   template<typename T> friend class LinkedList;

   Type data;
   Type priority;
   Node<Type>*l next; // you need to specify which data type the node will be

};

 template <typename T>
 class LinkedList
{
 public:
//Default constructor
LinkedList(){
    head = NULL;
    tail = NULL;
}

 Node<T>* newNode(T d, T p){
    Node<T>* temp = (Node<T>*)malloc(sizeof(Node<T>));
    temp->data = d;
    temp -> priority = p;
    temp->next = NULL;

    return temp;
 }
void push(Node<T>** head,T d, T p)
{
    Node<T>* start = (*head);
    // create a new node
    Node<T>* temp = newNode(d,p);
    if ((*head)->priority > p)
    {
        temp-> next = *head;
        (*head) = temp;
    }
    else{
        while(start->next != NULL && start ->next->priority<p){
            start = start->next;
        }
        temp-> next = start->next;
        start->next = temp;
    }
}
void pop(Node<T>** head){
    Node<T>* temp = *head;
    (*head) = (*head)->next;
    free(temp);
}

int isEmpty(Node<T>** head)
{
    return(*head) == NULL;
}

int peek(Node<T>** head){
    return(*head)->data;
}

private:
    //Declare the head and tail of the LinkedList
    Node<T>* head;// Again specify the data type of the template
    Node<T>* tail;// here the same thing

};

int main(){

   LinkedList<int> PQ;
   Node<int>* pq = PQ.newNode(4,1);

   PQ.push(&pq,2,1);
   PQ.push(&pq,8,3);
   PQ.push(&pq,9,2);

   while(!PQ.isEmpty(&pq)){
       std::cout<< " " << PQ.peek(&pq);
       PQ.pop(&pq);
   }
return 0;
    }
