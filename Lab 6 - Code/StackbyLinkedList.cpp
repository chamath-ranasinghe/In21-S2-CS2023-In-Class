// Implementation of a Stack using a LinkedList by Chamath Ranasinghe

#include <iostream>
#include <bits/stdc++.h>
#include <chrono>

using namespace std;

// Class to create Nodes for the LinkedList
class Node{
    public:
        int data;
        Node * next;

        Node(int d){
            data = d;
            next = nullptr;
        }
};

// Initialize a class to implement a Stack using a LinkedList
class Stack{
    private:
        Node *top = nullptr;
        Node *head = nullptr;

    public:
    void push(int data){ // Append value to the end of array
            Node *node = new Node(data); // Create a new node

            if (isEmpty()){ //If the Stack is empty assign the new node as the head and top
                top = node;
                head = node;
            }
            else{
                top -> next = node; // If not empty assign the new node as the top
                top = node;
            }

    }

    int pop(){ // Pop value at the end
        if(isEmpty()){
            cout<<"Stack Underflow"<<endl;
        }
        else{
            int value = top->data;
            if (top == head){ // top == head when there's only one element
                top = nullptr;
                head = nullptr;
            } else{
                Node *temp = head;

                while (temp->next != top){ // Traverse through the LinkedList to the end make the element before the top the new top
                    temp = temp -> next;
                }

                temp->next = nullptr;
                top = temp;
            }
    
            return value;

        }
    }

    bool isEmpty() { // Check if the stack is empty
        return (top == nullptr);
    }

    void display(){ // Display the stack
        Node *temp = head;

        while(temp!= nullptr){
            cout<<temp->data<<" ";
            temp = temp -> next;
        }

        cout<<endl;
    }
};

// Operation code
void runOperation(){
    Stack stack;

    for (int i=0; i < 10; i++){
        stack.push(rand()/100);    
    }

    stack.display();

    for (int i=0; i < 5; i++){
        stack.pop();    
    }

    stack.display();

    for (int i=0; i < 4; i++){
        stack.push(rand()/100);    
    }

    stack.display();


}

int main(){
    auto start = chrono::high_resolution_clock::now();
    runOperation();
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
    cout<< duration.count()<<endl;

    return 0;
}