nclude<iostream>
#include<cstdio>
#include<sstream>
#include<string>
#include<algorithm>
using namespace std;
bool is_palindromic(string n){
     string s;
   s=n; 
   reverse(n.begin(),n.end());
   if(s==n){
      return true;
   }
   return false;
}
string add(string s,string n){
  int temp=0,i,len=s.size();
  string ans;
  for(i=len-1;i>=0;i--){
     temp+=(s[i]-'0')+(n[i]-'0');
     ans.push_back(temp%10+'0');
     temp/=10;
  }
  if(temp){
    ans.push_back(temp+'0');
  }
   reverse(ans.begin(),ans.end());
  return ans;
}
string calculate(string s){
  string ans,n;
  n=s;
  reverse(s.begin(),s.end());
  ans=add(s,n);
  return ans;
}
int main(){
    string num,temp;
  int i,step;
  while(cin>>num>>step){
  for(i=0;i<step;i++){
    if(is_palindromic(num)){
       break;
    }
      num=calculate(num);
  
  }
    cout<<num<<endl<<i<<endl;
  }
  //system("pause");
    return 0;
}
