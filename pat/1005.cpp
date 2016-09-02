nclude<iostream>
#include<string>
using namespace std;
string s[]={"zero","one","two","three","four","five","six","seven","eight","nine"};
const int MAXN=1000+5;
int main()
{
   string str;
   int num;
   int arry[MAXN];
   int i,j;
   while(cin>>str)
   {
     num=0;
     for(i=0;i<str.size();i++)
            num+=str[i]-'0';
     j=0;
     while(num!=0){
       arry[j]=num%10;
     num/=10;
       j++;
     }
     for(i=j-1;i>=1;i--)
       cout<<s[arry[i]]<<" ";
     cout<<s[arry[0]]<<endl;
   }
}
