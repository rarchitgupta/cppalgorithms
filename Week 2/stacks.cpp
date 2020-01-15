#include<iostream>
using namespace std;

class stacks
{

        int top;
        int a[100];
        int MAX=100;
    public:
        
        stacks()
		{
            top=-1;
        }

        void push(int x)
        {
            if(top==MAX-1)
            {
                cout <<"Stack overflow: "<<endl;
                return;
            }
            else
            a[++top]=x;
        }

        int pop()
        {
            if(top<0)
            {
                cout <<"Stack empty: "<<endl;
                return '\0';
            }
            return a[top--];
        }

        void display()
        {
                if(top>=0)
                {
                    for(int i=top;i>=0;i--)
                    {
                        cout<<a[i]<<" ";
                    }
                    cout <<endl;
                }
        }

        int peek()
        {
            if(top<0)
            {
                cout <<"stack empty"<<endl;
                return -1;
            }
            return a[top];
        }

        int isempty()
        {
            if(top<0)
                return 1;
        }

};

int main()
{
    stacks s;
    int ch;
    int x;
    do
    {
        cout<<"1. Push into stack"<<endl;
        cout<<"2. Pop from stack"<<endl;
        cout<<"3. Display current stack"<<endl;
        cout<<"4. Display top element"<<endl;
        cout<<"5. Exit"<<endl;
        cin>>ch;

        switch(ch)
        {
            case 1: cout<<"Enter element to push into stack:"<<endl;
                    cin>>x;
                    s.push(x);
                    break;

            case 2: x=s.pop();
                    cout<<x<<" popped from stack"<<endl;
                    break;

            case 3: s.display();
                    break;

            case 4: x=s.peek();
                    cout<<x<<endl;
                    break;

            default: break;                               
        }
    } while (ch!=5);
    
}