#include<iostream>
#define MAXN 100001
using namespace std;
bool used[MAXN];
int add[MAXN];
//int add1[MAXN];
int getbit(int n){
  int c=0;
  while(n){
    n/=10;
    c++;
  }
  return c;
}
int main(){
  int i,a,b,N;
  int f,s;
  bool flag=false;
  char c;
  cin>>a>>b>>N;
  for(i=0;i<N;i++){
    scanf("%d %c %d",&f,&c,&s);
    add[f]=s;
  }
  for(i=0;i<N;i++){
    if(a!=-1){
      used[a]=true;
    a=add[a];
    }
  }
  for(i=0;i<N;i++){
      if(used[b]&&used[b]!=-1){
        flag=true;
      break;
    }
    b=add[b];
  }
  if(flag){
    int bb=getbit(b);
    for(i=0;i<5-bb;i++)
      cout<<0;
    cout<<b<<endl;
  }
  else
    cout<<-1<<endl;
  //system("pause");
return 0;
}
