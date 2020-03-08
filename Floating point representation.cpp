#include<bits/stdc++.h>
#define N 100
using namespace std;
int num,digit[N],i=0,fract[N];
int main()
{
    int sign_bit;
    int exponent;
    double n,fact;
    char binary[N];
    int temp,flag,tmp1;
    stringstream bin;
    stringstream bin1;
    cout<<"input Decimal Number: ";
    cin>>n;
    if(n<0)
    {
        flag=1;
        n=-(n);
        sign_bit=1;
    }
    else if(n>0)
    {
        flag=0;
        sign_bit=0;
    }
    else
        return 0;

    num=n;
    fact=n-num;

    while(num!=0)
    {
        digit[i]= num%2;
        num=num/2;
        i++;
    }
    tmp1=i;
    cout<<"Binary of "<<n<<" is : ";
    for(int j=i-1; j>=0; j--)
    {
        bin<<digit[j];

    }
    string str(bin.str());
    string str2=".";
    str.append(str2);
    i=0;
    while(fact!=0)
    {
        fract[i]= fact*2;
        temp=fact*2;
        fact=(fact*2)-temp;
        i++;
    }
    for(int k=0; k<i; k++)
    {
        bin1<<fract[k];
    }
    string str3(bin1.str());
    str.append(str3);
    cout<<str<<endl;

    if(n<1)
    {
        int one= str.find('1');
        exponent= -(one)+127;
        str.erase(0,one);
        str.insert(1, 1, '.');
        if(str.size()>=23)
            str.erase(25,100);
    }
    else
    {
        int dot_pos = str.find('.');
        exponent= dot_pos-1+127;
        str.erase(dot_pos, 1);
        str.insert(1, 1, '.');
        if(str.size()>=23)
            str.erase(25,100);
    }
    string fraction= str.erase(0,2);
    i=0;
     while(exponent!=0)
    {
        digit[i]= exponent%2;
        exponent=exponent/2;
        i++;
    }

    cout<<sign_bit<<"   ";
    for(int j=i-1; j>=0; j--)
    {
        cout<<digit[j];

    }
    cout<<"  " <<fraction<<endl;

    return 0;
}

