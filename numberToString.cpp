#include <iostream>
#include <cstring>
#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>

using namespace std;
string str1 [] = {"","one","two","three","four","five","six","seven","eight","nine"};
string str2 [] = {"ten","eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","nineteen"};
string str3 [] = {"twenty","thirty","fourty","fifty","sixty","seventy","eighty","ninety"};
string str4 [] = {"hundred","thousand", "million","trillion"};

int countDigit(int num);
string signleDigit(int num);
string doubleDigit(int num);
string threeDigit(int num);
string fourDigit(int num);
string fiveDigit(int num);
string sixDigit(int num);
string sevenDigit(int num);
string numberToString(int num);
int main(){
    int number, digit;
    cout<<"\n Enter a number : ";
    cin>>number;
    digit = countDigit(number);
    string st = numberToString(number);
    cout<<" You entered a "<<digit<<", number : "<<number<<endl;
    cout<<" Its string equivalent : "<<st;
}
int countDigit(int num){
    int counter = 0;
    int temp = num;
    char st[20];
    sprintf(st,"%d",temp);
    while((temp = temp/10)>0){
        counter++;
    }
    return counter + 1;
}
string signleDigit(int num){
    return str1[num];
}
string doubleDigit(int num){
    if(num <10)  return str1[num];
    else if (num>9 && num<20) return str2[num%10];
    else  return str3[num/10-2] +" "+ str1[num%10];
}
string threeDigit(int num){
    if(num/100==0) return doubleDigit(num);
    else  return signleDigit(num/100) +" "+ str4[0] +" "+ doubleDigit(num%100);
}
string fourDigit(int num){
    return signleDigit(num/1000) + " "+ str4[1] +" "+ threeDigit(num%1000);
}
string fiveDigit(int num){
    return doubleDigit(num/1000) + " "+ str4[1] +" "+ threeDigit(num%1000);
}
string sixDigit(int num){
    return threeDigit(num/1000) + " "+str4[1]+" "+ threeDigit(num%1000);
}
string sevenDigit(int num){
    if(num%1000000 <10)
        return threeDigit(num/1000000) +" "+str4[2] + " "+ signleDigit(num%1000000);
    else if(num%1000000 <100)
        return threeDigit(num/1000000) +" "+str4[2] + " "+ doubleDigit(num%1000000);
    else if(num%1000000 <1000)
        return threeDigit(num/1000000) +" "+str4[2] + " "+ threeDigit(num%1000000);
    else if(num%1000000 <10000)
        return threeDigit(num/1000000) +" "+str4[2] + " "+ fourDigit(num%1000000);
    else if(num%1000000 <100000)
        return threeDigit(num/1000000) +" "+str4[2] + " "+ fiveDigit(num%1000000);
    else
        return threeDigit(num/1000000) +" "+str4[2] + " "+ sixDigit(num%1000000);
}
string numberToString(int num){
    int numOfDigit = countDigit(num);
    switch(numOfDigit){
        case 1 : if(num==0) return "zero"; 
                 else return signleDigit(num); break;
        case 2 : return doubleDigit(num); break;
        case 3 : return threeDigit(num);  break;
        case 4 : return fourDigit(num);   break;
        case 5 : return fiveDigit(num);   break;
        case 6 : return sixDigit(num);    break;
        case 7 :  
        case 8 : 
        case 9 : return sevenDigit(num);  break;
        default : return "Above 999,999,999";
    }
}
