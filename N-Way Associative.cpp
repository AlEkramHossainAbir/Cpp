#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,block;
    cin>>n; //column
    cin>>block;
    int set1= block/n; //row
    int cache[set1][n];
    int priority[set1][n];
    int data[100];
    int i=0,count=0;
    int j;
    cout<<"Input -1 for Execute the input Section: "<<endl;
    for(i=0; ; i++)
    {
        cin>>data[i];
        count++;
        if(data[i]<0)
            break;
    }

    cout<<endl;
    for(i=0; i<set1; i++)
    {
        for(j=0; j<n; j++)
        {
            cache[i][j]=-1;
            priority[i][j]=-1;
        }
    }
    for(i=0; i<set1; i++)
    {
        for(j=0; j<n; j++)
        {
            if(cache[i][j]==-1)
            {
                cout<<"B \t";
            }
        }
        cout<<endl;
    }
    for(j=0; j<count-1; j++)
    {
        int cache_set;
        int hit=0;
        int minimum=100;
        int empty=1;
        //how many set associative
        cache_set = data[j]%set1;
        //set hit value
        for(int g=0; g<n; g++)
        {
            if(cache[cache_set][g] == data[j])
            {
                hit=1;
                break;
            }
        }
        //check hit/miss by hit value
        if(hit == 0)
        {
            cout<<"\nMISS\n";
            //if cache set is empty
            for(int g=0; g<n; g++)
            {
                if(cache[cache_set][g] == -1)
                {
                    cache[cache_set][g]=data[j];
                    priority[cache_set][g]=j;
                    empty=0;
                    break;
                }
            }
            //LRU
            if(empty == 1)
            {

                for(int g=0; g<n; g++)
                {
                    if(minimum>priority[cache_set][g])
                    {
                        minimum=priority[cache_set][g] ;
                    }
                }
                for(int g=0; g<n; g++)
                {

                    if(priority[cache_set][g]==minimum)
                    {
                        cache[cache_set][g]=data[j];
                        priority[cache_set][g]=j;
                        break;
                    }
                }
            }
        }
        else if(hit == 1)
        {
            cout<<"\nHIT\n";
            for(int g=0; g<n; g++)
            {
                if(cache[cache_set][g] == data[j])
                {
                    priority[cache_set][g]=j;
                }
            }
        }
        //show output
        for(int k=0; k<set1; k++)
        {
            for(int k1=0; k1<n; k1++)
            {
                if(cache[k][k1] == -1)
                {
                    cout<<"B\t";
                }
                else
                {
                    cout<<cache[k][k1]<<"\t";
                }
            }
            cout<<"\n";
        }
    }

}

