nclude<iostream>
#include<cstdio>
#include<string>
#include<cstring>
using namespace std;
struct Tname{
  string name;
  string pass;
  int flag;
}account[1005];
int main()
{
  int n,i,l;
  int cot;
  //  char name[10],pass[10];
  scanf("%d",&n);
  l=n;  
  cot=0;
  while(n--){
    cin>>account[n].name>>account[n].pass;
         account[n].flag=0;
       //cout<<account[n].name<<account[n].pass<<endl;
       for(i=0;i<account[n].pass.size();i++)
         if(account[n].pass[i]=='0')
         {
           account[n].flag=1;
           account[n].pass[i]='%';
         }
         else if(account[n].pass[i]=='1')
         {
           account[n].flag=1;
           account[n].pass[i]='@';
         }  
         else if(account[n].pass[i]=='l')
         {
           account[n].flag=1;
           account[n].pass[i]='L';
         }  
         else if(account[n].pass[i]=='O')
         {
           account[n].flag=1;
           account[n].pass[i]='o';
         }
         if(account[n].flag)
           cot++;  
  }
  if(cot){
    cout<<cot<<endl;
    for(i=l-1;i>=0;i--)
      if(account[i].flag)
        cout<<account[i].name<<" "<<account[i].pass<<endl;
  }
  else{
    if(l==1)
    {
      cout<<"There is "<<l<<" account and no account is modified"<<endl;
    }
    else
    {
      cout<<"There are "<<l<<" accounts and no account is modified"<<endl;
    }
  }
  return 0;
}
