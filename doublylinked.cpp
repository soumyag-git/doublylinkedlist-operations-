#include <iostream>

using namespace std;

class node{
    public:
    int data;
    node *prev;
    node *next;
}*first;

class linkedlist{
    public:

    linkedlist(){
        first=NULL;
    }
    linkedlist(int a[],int size){
        node *t,*last;
        first =new node;
        first->data=a[0];
        first->next=NULL;
        first->prev=NULL;
        last=first;
        for(int i=1;i<size;i++){
            t=new node;
            t->data=a[i];
            t->next=NULL;
            t->prev=last;
            last->next=t;
            last=t;
        }
    }

    void display();
    void insert(int position ,int x);
    int length();
    void deletenode(int position);
    void deletenode1(int position);
    void deletenode2(int position);
    void reverse();
};

void linkedlist::display(){
    node *p=first;
    while(p->next!=NULL){
        p=p->next;
    }
    while(p){
        cout<<p->data<<"\t";
        p=p->prev;
    }
}

int linkedlist::length(){
    node *p=first;
    int x= 0;
    while(p->next!=NULL){
        x++;
        p=p->next;
    }
    return x;
}

void linkedlist::insert(int position,int x){
    struct node *p,*t;
    p=first;
    if( position<0 || position > length()){
        return;
    }
    else{
        if(position==0){
            t=new node;
            t->data=x;
            t->next=first;
            first->prev=t;
            first=t;
        }

        else{
            for(int i=0;i<position-1;i++){
                p=p->next;
            } 
            t=new node;
            t->data=x;
            t->next=p->next;
            if(p->next){
                p->next->prev=t;
            }
            p->next=t;
            t->prev=p;
        }
    }
}

void linkedlist::deletenode(int position){
    node *p,*q;
    p=first;
    q=p;

    if(position==1){
        if(first->next){
        first=first->next;
        if(first){
        first->prev=NULL;
        }
        delete(p);
        }
        else{
            delete(p);
        }
    }
    else{
        for(int i=0;i<position-1;i++){
            q=p;
            p=p->next;
        }
        if(p){
        q->next=p->next;
        if(p->next){
         p->next->prev=q;}
        delete(p);
        }
    }
}

void linkedlist::deletenode1(int position){
    node *p;
    p=first;



    if(position==1){
        if(first->next){
        first=first->next;
        first->prev=NULL;
        delete(p);
        }
        else{
            delete(p);
        }
    }
    else{
        for(int i=0;i<position- 2;i++){
          p=p->next;
        }
        if(p->next->next){
                p->next->next->prev=p;
                p->next=p->next->next;
        }
        else{
            // p=p->next;
            p->next=NULL;
        }

    }
}

void linkedlist::deletenode2(int position){
    node *p;
    p=first;

    if(position==1){
        if(first->next){
        first=first->next;
        first->prev=NULL;
        delete(p);
        }
        else{
            delete(p);
        }
    }
    else{
        for(int i=0;i<position- 1;i++){
          p=p->next;
        }
        p->prev->next=p->next;
        if(p->next){
            p->next->prev=p->prev;
        }

        delete(p);

    }
}

void linkedlist::reverse(){
    node *p,*t ;
    p=first;

    while(p){
        t=p->next;
        p->next=p->prev;
        p->prev=t;
        p=p->prev;

        if(p!=NULL && p->next==NULL){
        first=p;
        }
    }

}

int main(){
    int a[]={1,2,3,4,5};
    linkedlist ar(a,5);
    //cout<<ar.length();
    //ar.insert(1,10);
    // ar.deletenode2(5);
    ar.reverse();
    
    ar.display();
}
