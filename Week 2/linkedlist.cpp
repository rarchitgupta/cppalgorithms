#include <bits/stdc++.h>

using namespace std;

class node
{
  public:
  int data;
  node *next;

}*head;


void insend()
{
    node *cur;
    cur=head;
    cout<<"Enter data: "<<endl;
    node *temp=new node;
    cin>>temp->data;
    temp->next=NULL;

    if(head==NULL)
    {
        head=temp;
    }
    else
    {
        while((cur->next)!=NULL)
            cur=cur->next;

        cur->next=temp;
    }
}

void inspos()
{
    node *temp=new node;
    cout<<"Enter data: "<<endl;
    cin>>temp->data;
    temp->next=NULL;
    cout<<"Enter position to insert node at: "<<endl;
    int pos;
    cin>>pos;

    node *t1,*t2;

    if(head==NULL)
    {
        head=temp;
    }
    else
    {
        t1=head;
        int i;
        for(i=1;i<pos;i++)
            t1=t1->next;

        t2=t1->next;
        t1->next=temp;
        temp->next=t2;
    }
}

void deletegiven(int key)
{
    node *temp=head;
    node *prev;

    if(temp!=NULL&&temp->data==key)
    {
        head=temp->next;
        delete temp;
        return;
    }

    while(temp!=NULL&&temp->data!=key)
    {
        prev=temp;
        temp=temp->next;
    }

    if(temp==NULL)
        return;

    prev->next=temp->next;

    delete temp;
}

void deletepos()
{
    cout<<"Enter position to delete node from: "<<endl;
    int pos;
    cin>>pos;
    int i;

    if(head==NULL)
    {
        cout<<"List empty: "<<endl;
        return;
    }

    node *cur=head->next;
    node *prev=head;

    for(i=1;i<pos;i++)
    {
        prev=prev->next;
        cur=cur->next;
    }

    prev->next=cur->next;
    delete cur;

}

void search(int key)
{
    node *cur=head;
    int ct=1;

    while(cur!=NULL)
    {
        if(cur->data==key)
        {
            cout<<"Found at position "<<ct<<endl;
            return;
        }

        ct++;
        cur=cur->next;
    }

    cout<<"Not Found!"<<endl;
}

void display()
{
    node *cur;
    cur=head;
    if(head==NULL)
    {
        cout<<"List empty"<<endl;
    }
    else
    {
        while((cur)!=NULL)
        {
            cout<<cur->data<<"->";
            cur=cur->next;
        }
        cout<<endl;
    }
}

int main()
{
    int ch;
    do
    {
      cout<<"1. Insert element at end"<<endl;
      cout<<"2. Insert element at given position"<<endl;
      cout<<"3. Delete a given node"<<endl;
      cout<<"4. Display current list"<<endl;
      cout<<"5. Search for an element"<<endl;
      cout<<"6. Delete node from given position"<<endl;
      cout<<"7. Exit"<<endl;
      cin>>ch;
      int x;

      switch(ch)
      {
        case 1: insend();
                break;
        case 2: inspos();
                break;
        case 3: cout<<"Enter data to delete: "<<endl;
                cin>>x;
                deletegiven(x);
                break;
        case 4: display();
                break;
        case 5: cout<<"Enter element to search for: "<<endl;
                cin>>x;
                search(x);
        case 6: deletepos();
                break;
        default:break;
      }
    }
    while(ch!=7);

}
 