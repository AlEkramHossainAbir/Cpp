#include<bits/stdc++.h>
#include<string.h>
using namespace std;
//int bin_to_dec(int num)
//{
//    int decimal_val=0,base=1,rem;
//
//    while (num > 0)
//
//    {
//
//        rem = num % 10;
//
//        decimal_val = decimal_val + rem * base;
//
//        num = num / 10 ;
//
//        base = base * 2;
//
//    }
//
//
//    return decimal_val;
//}
double convertStringToDecimal(string binary)
{
    int len=binary.length();
    int point = binary.find('.');
    //int indexCounter = 0;
    double fracDecimal=0;
    double decimal=0;
    double twos=1;

    // Update point if not found
    if (point == string::npos)
        point = len;
// Convert integral part of binary to decimal equivalent
    for (int i = point-1; i>=0; --i)
    {
        // Subtract '0' to convert character into integer
        decimal += (binary[i] - '0') * twos;
        twos *= 2;
    }
    twos = 2;
    for (int i = point+1; i < len; ++i)
    {
        fracDecimal += (binary[i] - '0') / twos;
        twos *= 2.0;
    }

    // Add both integral and fractional part
    decimal=decimal + fracDecimal;


    return decimal;
//    for(int i=point-1; i>=0; i--)
//    {
//
//        if(binary[i]=='1')
//        {
//           decimal += pow(2, indexCounter);
//        }
//        indexCounter++;
//    }


}
int main()
{
    int i;
    int x;
    double value;
    double fraction;
    double temp_value=1.0;
    int dummy_expo,expo;
    string IEEEnum;
    string signbit;
    string exponent;
    string zero;
    string real_fraction="1.";

    cout<<"input 32 bit binary: ";
    cin>>IEEEnum;
    signbit=IEEEnum[0];
    IEEEnum= IEEEnum.erase(0,1);
    exponent="";
    for(i=0; i<8; i++)
        exponent+=IEEEnum[i];
    dummy_expo=convertStringToDecimal(exponent);
    expo=dummy_expo-127;

    IEEEnum= IEEEnum.erase(0,8);
    IEEEnum=real_fraction.append(IEEEnum);
    stringstream DECIMAL(IEEEnum);
    DECIMAL >> fraction;


    if(expo<0)
    {
        expo=-(expo);
        x=IEEEnum.find('.');
        IEEEnum= IEEEnum.erase(x,1);
        zero="";
        for(i=0; i<expo; i++)
            zero+="0";


        IEEEnum=zero.append(IEEEnum);
        IEEEnum=IEEEnum.insert(0,".");
    }
    else
    {
        x=IEEEnum.find('.');
        IEEEnum= IEEEnum.erase(x,1);
        IEEEnum=IEEEnum.insert(expo+1,".");

    }


    temp_value=convertStringToDecimal(IEEEnum);

    if(signbit=="1")
    {
        value=-(temp_value);
    }
    else
        value=temp_value;
    cout<<"Decimal Value: "<<value<<endl;
}
