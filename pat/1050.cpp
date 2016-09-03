#include<iostream>
#include<string>
#define MAXN 266
using namespace std;
int sum[MAXN];
int main(){
  string str,target;
  int i,len;
  getline(cin,str);
  getline(cin,target);
  len=target.size();
  for(i=0;i<len;i++)
    sum[target[i]]=1;
  len=str.size();
  for(i=0;i<len;i++){
    if(!sum[str[i]]){
      cout<<str[i];
    }
  }
  cout<<endl;
  //system("pause");
return 0;
}
