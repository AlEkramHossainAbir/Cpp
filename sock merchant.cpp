#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,i;
    cin>>n;
    int ar[n]; //vector<int> ar(n);
    for(i=0;i<n;i++){
    cin>>ar[i];
    }
    map <int,int> sockpair;
    for(i=0;i<n;i++){
        int x= ar[i];
        sockpair[x]=sockpair[x]+1;

    }
    map<int, int>::iterator itr;
    int no_pairs=0;
    for(itr=sockpair.begin();itr!=sockpair.end();itr++)
    {
        cout<<itr->first <<": "<<itr->second<<endl;
        no_pairs += itr->second /2;
    }
    cout<<no_pairs<<endl;

}
