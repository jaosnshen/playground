#include<iostream>
#include<string>
#include<algorithm>
#include<sstream>
using namespace std;
void addzero(string &s){
  int len,i;
  len=s.size();
  for(i=0;i<4-len;i++){
      s='0'+s;
  }
}
string getStr(string str){
  int i,len;
  stringstream stream; 
  string str1;
  sort(str.begin(),str.end());
  reverse(str.begin(),str.end());
  int num,num2,num1;
  num=atoi(str.c_str());
  printf("%04d - ",num);
  reverse(str.begin(),str.end());
  num1=atoi(str.c_str());
  num2=num-num1;
  stream<<num2;
  stream>>str1;
  printf("%04d = %04d\n",num1,num2);
  addzero(str1);
  return str1;
}
int main(){
  string str;
  int i,len;
  while(cin>>str)
  while(true){
      addzero(str);
        str=getStr(str);
      if(str=="0000"||str=="6174")
        break;
  }
  system("pause");
return 0;
}
