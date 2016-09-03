nclude<iostream>
#include<cstdio>
using namespace std;
int main(){
  int n,i=1;
  bool flag;
  cin>>n;
  long long a,b,c,ans;
  while(i<=n){
    cin>>a>>b>>c;
      printf("Case #%d: ",i++);
  ans=a+b;
    if(a>0&&b>0&&ans<=0)
        flag=true;
    else if(a<0&&b<0&&ans>=0)
      flag=false;
    else
      flag=ans>c;
    if(flag)
      printf("true\n");
    else
      printf("false\n");
  }
  //system("pause");
return 0;
}
