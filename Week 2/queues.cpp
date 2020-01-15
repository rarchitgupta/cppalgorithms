#include<iostream>
using namespace std;

class queues
{

        int front;
        int rear;
        int a[100];
        int MAX=100;
    public:
        
        queues()
		{
            front=-1;
            rear=-1;
        }

        void insertq(int x)
        {
            if(rear==MAX-1)
            {
                cout <<"Queue overflow: "<<endl;
                return;
            }
            else
                a[rear++]=x;
        }

        int deleteq()
        {
            if(front==rear)
            {
                cout <<"Queue Empty: "<<endl;
                return -1;
            }
            else 
            { 
                return a[front++];
            } 
        }

        void display()
        {
                int i;

                if(front==rear)
                {
                    cout<<"Queue empty!"<<endl;
                }
                else
                {
                    for (i = front; i < rear; i++)
                    {
                        cout<<a[i]<<" ";
                    }
                    cout<<endl;
                }
                
        }


};

int main()
{
    queues q;
    int ch;
    int x;
    do
    {
        cout<<"1. Insert into queue"<<endl;
        cout<<"2. Delete from queue"<<endl;
        cout<<"3. Display current stack"<<endl;
        cout<<"4. Exit"<<endl;
        cin>>ch;

        switch(ch)
        {
            case 1: cout<<"Enter element to insert into queue:"<<endl;
                    cin>>x;
                    q.insertq(x);
                    break;

            case 2: x=q.deleteq();
                    cout<<x<<" deleted from queue"<<endl;
                    break;

            case 3: q.display();
                    break;


            default: break;                               
        }
    } while (ch!=4);
    
}