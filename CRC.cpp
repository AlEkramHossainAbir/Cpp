#include<bits/stdc++.h>
#define size 20
using namespace std;

class CRC
{
    string msg,div,rmsg;
    int reminder[size],restore[size],divisor[size],message[size];
    int rmessage[size],rrestore[size],rreminder[size];
    int msize,rsize,dsize,rmsize,rrsize;
public:
    CRC();
    void getdata();
    void display();
    void convert();
    void check();
};
CRC :: CRC()
{

    msize=0;
    dsize=0;
    rsize=0;
    rmsize=0;
    rrsize=0;

}

void CRC :: getdata()
{
    cout<<"Message: ";
    cin>>msg;
    msize=msg.length();
    cout<<"Divisor : ";
    cin>>div;
    dsize=div.length();

}


void CRC :: convert()
{
    int n=0,m=0,k=0,flag=0,count=0;

    for(int i=0; i<msize; i++)
    {
        message[i]=(int)msg[i] - 48;
    }
    for(int i=0; i<dsize; i++)
    {
        divisor[i]=(int)div[i] - 48;
    }

    for(int i=msize; i<(msize+dsize)-1; i++)
    {
        message[i]=0;
    }
    msize=(msize+dsize)-1;
    cout<<"New Message: ";
    for(int i=0; i<msize; i++)
        cout<<message[i]<<" ";
    rsize=msize;
    for(int i=0; i<msize; i++)
        restore[i]=message[i];



    while(n <=msize)
    {
        while(flag==0)
        {
            if(restore[m]==0)
                m++;
            else
                flag=1;

        }
        flag=0;

        for(int i=m; i<(dsize+m); i++)
        {
            if(restore[i]==0||restore[i]==1)
                count++;
        }

        if(count==dsize)
        {
            for(int i=m; i<(dsize+m); i++)
            {
                restore[i]=restore[i]^divisor[k];
                k++;
            }
            k=0;

        }
        else
            break;
        count=0;
        n=(dsize+m)+1;
    }
    rsize=msize-1;
    for(int i=1; i<dsize; i++)
    {
        message[rsize]=restore[rsize];
        rsize--;


    }

    rsize=msize-1;
    for(int i=(dsize-1); i>0; i--)
    {
        reminder[i]=restore[rsize];
        rsize--;
    }

    cout<<"\n Frame Check Sequence :";
    for(int i=1; i<dsize; i++)
        cout<<reminder[i]<<" ";

    cout<<"\n Frame : ";
    for(int i=0; i<msize; i++)
        cout<<message[i];

}

void CRC :: check()
{
    int n=0,m=0,k=0,flag=0,count=0,flag1=0;
    rmsize=msize;
    cout<<"\n After Randomly Changing 3 bits: ";
    cin>>rmsg;
    for(int i=0; i<rmsize; i++)
    {
        rmessage[i]=int(rmsg[i])-48;
    }
    rrsize=rmsize;
    for(int i=0; i<rmsize; i++)
        rrestore[i]=rmessage[i];

    while(n<=rmsize)
    {
        while(flag==0)
        {
            if(rrestore[m]==0)
                m++;
            else
                break;

        }
        flag=0;

        for(int i=m; i<(dsize+m); i++)
        {
            if(rrestore[i]==0||rrestore[i]==1)
                count++;
        }
        if(count==dsize)
        {
            for(int i=m; i<(dsize+m); i++)
            {
                rrestore[i]=rrestore[i]^divisor[k];
                k++;
            }
            k=0;
        }
        else
            break;
        count=0;
        n=(dsize+m)+1;
    }
    cout<<endl;
    rrsize=rmsize-1;
    for(int i=(dsize-1); i>0; i--)
    {
        rreminder[i]=rrestore[rrsize];
        rrsize--;
    }
    cout<<"Reminder is: ";
    for(int i=1; i<dsize; i++)
    {
        if(rreminder[i]==1)
        {
            flag1=1;
            break;
        }
    }
    for(int i=1; i<dsize; i++)
        cout<<rreminder[i]<<" ";
    if(flag1==0)
        cout<<"No Error "<<endl;
    else
        cout<<"Error detected"<<endl;

}



int main()
{
    CRC ob;
    ob.getdata();
    ob.convert();
    ob.check();
}
