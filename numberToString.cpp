#include <iostream>
#include <cstring>
#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>

using namespace std;
typedef struct{
    int num;
    string numstr;
}NumStr;

string str1 [] = {"","one","two","three","four","five","six","seven","eight","nine"};
string str2 [] = {"ten","eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","nineteen"};
string str3 [] = {"twenty","thirty","fourty","fifty","sixty","seventy","eighty","ninety"};
string str4 [] = {"hundred","thousand", "million","trillion"};

NumStr countDigit(int num);
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
    NumStr NS;
    cout<<"Enter a number : ";
    cin>>number;
    NS = countDigit(number);
    cout<<"Number of digit : "<<NS.num<<endl;
    string st = numberToString(number);
    cout<<"You entered : "<<NS.numstr<<" , "<<st;
}
NumStr countDigit(int num){
    int counter = 0;
    int temp = num;
    char st[20];
    sprintf(st,"%d",temp);
    while((temp = temp/10)>0){
        counter++;
    }
    NumStr ns;
    ns.num = counter + 1;
    ns.numstr = st;
    return ns;
}
string signleDigit(int num){
    if(num==0) return str1[0];      else if(num==1) return str1[1];
    else if(num==2) return str1[2]; else if(num==3) return str1[3];
    else if(num==4) return str1[4]; else if(num==5) return str1[5];
    else if(num==6) return str1[6]; else if(num==7) return str1[7];
    else if(num==8) return str1[8]; else if(num==9) return str1[9];
}
string doubleDigit(int num){
    NumStr ns = countDigit(num);
    string tempStr1, tempStr2;

    if(num <10){
        return signleDigit(num);
    }
    else if (num>9 && num<20){
        if(ns.numstr[1]=='0') return str2[0];else if(ns.numstr[1]=='1') return str2[1];
        else if(ns.numstr[1]=='2') return str2[2];else if(ns.numstr[1]=='3') return str2[3];
        else if(ns.numstr[1]=='4') return str2[4];else if(ns.numstr[1]=='5') return str2[5];
        else if(ns.numstr[1]=='6') return str2[6];else if(ns.numstr[1]=='7') return str2[7];
        else if(ns.numstr[1]=='8') return str2[8];else if(ns.numstr[1]=='9') return str2[9];
    }
    else{
        if(ns.numstr[0]=='2')      tempStr1 = str3[0]; else if (ns.numstr[0]=='3') tempStr1 = str3[1];
        else if(ns.numstr[0]=='4') tempStr1 = str3[2]; else if (ns.numstr[0]=='5') tempStr1 = str3[3];
        else if(ns.numstr[0]=='6') tempStr1 = str3[4]; else if (ns.numstr[0]=='7') tempStr1 = str3[5];
        else if(ns.numstr[0]=='8') tempStr1 = str3[6]; else if (ns.numstr[0]=='9') tempStr1 = str3[7];

        if(ns.numstr[1]=='0')      tempStr2 = "";             else if(ns.numstr[1]=='1') tempStr2 = signleDigit(1);
        else if(ns.numstr[1]=='2') tempStr2 = signleDigit(2); else if(ns.numstr[1]=='3') tempStr2 = signleDigit(3);
        else if(ns.numstr[1]=='4') tempStr2 = signleDigit(4); else if(ns.numstr[1]=='5') tempStr2 = signleDigit(5);
        else if(ns.numstr[1]=='6') tempStr2 = signleDigit(6); else if(ns.numstr[1]=='7') tempStr2 = signleDigit(7);
        else if(ns.numstr[1]=='8') tempStr2 = signleDigit(8); else if(ns.numstr[1]=='9') tempStr2 = signleDigit(9);
        return (tempStr1 + " "+ tempStr2);
    }


}
string threeDigit(int num){
    if(num/100==0)
        return doubleDigit(num);
    else
        return signleDigit(num/100) +" "+ str4[0] +" "+ doubleDigit(num%100);
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
        return threeDigit(num/1000000) +" "+str4[2] + " "+threeDigit(num%1000000);
    else if(num%1000000 <10000)
        return threeDigit(num/1000000) +" "+str4[2] + " "+fourDigit(num%1000000);
    else if(num%1000000 <100000)
        return threeDigit(num/1000000) +" "+str4[2] + " "+fiveDigit(num%1000000);
    else
        return threeDigit(num/1000000) +" "+str4[2] + " "+sixDigit(num%1000000);
}
string numberToString(int num){
    NumStr ns = countDigit(num);
    switch(ns.num){
        case 1 : if(num==0) return "zero";
                  else{
                    return signleDigit(num);
                  }
                  break;
        case 2 : return doubleDigit(num);
            break;
        case 3 : return threeDigit(num);
            break;
        case 4 : return fourDigit(num);
            break;
        case 5 : return fiveDigit(num);
            break;
        case 6 : return sixDigit(num);
            break;
        case 7 :
        case 8 :
        case 9 : return sevenDigit(num);
            break;
        default : return "Above 999,999,999";
    }
}
