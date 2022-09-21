#include<bits/stdc++.h>
using namespace std;


class Node{
    public:
        int val;
        Node* next;
        Node* prev;
        Node(int val){
            this->val=val;
            next=NULL;
            prev=NULL;
        }
};

class Stack{

    public:
        Node* head;
        Node* top;
        int cnt=0;
        Stack(){
            head=NULL;
            top=NULL;
        }
        ///push
        void push(int val){
                Node* newNode=new Node(val);
                cnt++;

                if(head==NULL){
                    head=top=newNode;
                    return;
            }

                top->next=newNode;
                newNode->prev=top;
                top=newNode;
        }
        ///pop
        int pop(){

            Node* delNode=top;
            int chk=-1;
            if(head==NULL){
                cout<<"Stack Under Flow";
                return chk;

            }

            if(top==head){
                head=top=NULL;

            }
            else{

             top=delNode->prev;
             top->next=NULL;

            }
             cnt--;
             chk=delNode->val;
             delete delNode;
             return chk;
        }
        ///Empty ....capital E to avoid error.codeblocks shows a built in function name empty.
        bool Empty(){

            if(head==NULL)
                return true;
            else
                return false;
        }
        ///Top
        int Top(){
            if(top==NULL){
                cout<<"stack underflow! Stack is empty!";
                //return 0;
            }
            else{
                return top->val;
            }
        }
        ///Size ....Used capital S to avoid error.codeblocks shows a built in function name size.
        int Size(){
            return cnt;
        }
        ///mid
        int mid(){
            if(head==NULL){
                cout<<"Stack is empty!";
                return -1;
            }
            else if(head==top){
                cout<<"Insufficient elemnet! Only one element";
                return -1;
            }
            else if(cnt%2==0){
                cout<<"statck Size is even.Approximate Mid will be : ";
                int i=1;
                Node* tmp=head;
                while(i<((cnt+1)/2)){
                    tmp=tmp->next;
                    i++;
                }
                return tmp->val;
            }
            else if(cnt%2){
                int i=1;
                Node* tmp=head;
                while(i<((cnt+1)/2)){
                    tmp=tmp->next;
                    i++;
                }
                return tmp->val;
            }


        }


};


