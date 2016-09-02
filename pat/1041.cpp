nclude<iostream>
#include<string>
using namespace std;
int main(){
  string str;
  int i,len,n1,j=0,n2,n3;
  cin>>str;
  len=str.size();
  n1=(len+2)/3;
  n2=len+2-2*n1;
  for(i=0;i<n1-1;i++){
       cout<<str[i];
     while(j<n2-2){
         cout<<" ";
       j++;
     }
     j=0;
     cout<<str[len-1-i]<<endl;
  }
  for(i=n1-1;i<n1+n2-1;i++){
      cout<<str[i];
  }  
  system("pause");
return 0;
}
