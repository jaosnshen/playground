#include<iostream>
#include<algorithm>
#include<string.h>
#define MAXN 100000
using namespace std;
struct node{
  int Address;
  int Key;
  int next;
};
node a[MAXN],b[MAXN];
bool vis[MAXN];
bool cmp(const node &a,const node &b){
  return a.Key<b.Key;
}
int main(){
  //int key,i,n,head,a,k,next;
  //bool flag=false;
  //memset(vis,false,sizeof(vis));
  //scanf("%d %d",&n,&head);
  //for(i=0;i<n;i++){
  //  scanf("%d%d%d",&p[i].Address,&p[i].Key,&p[i].next);
  //  //vis[p[i].Address]=true;//vis[p[i].next]=true;
  //  //if(head==p[i].Address)
  //    //flag=true;
  //}
  //if(head==-1){
  //  printf("0 -1\n");
  //    return 0;
  //}
  //if(n!=0&&flag){
  //  for(i=0;i<n;i++){
  //    if(p[i].next==-1)
  //      break;
  //  }
  //  sort(p,p+n,cmp);
  //  n=i;
  //  printf("%d %05d\n",n,p[0].Address);
  //  //n=i;
  //  for(i=0;i<n;++i){
  //    printf("%05d %d ",p[i].Address,p[i].Key);
  //    if(!vis[p[i+1].Address]||i==n-1){
  //      printf("-1\n");
  //      break;
  //    }
  //    else
  //      printf("%05d\n",p[i+1].Address);
  //  }
  //}else{
  //  printf("0 -1\n");
  //}
  //
  int n,x,p,q,r,i;
  scanf("%d%d",&n,&x);
  for(i=0;i<n;i++){
  scanf("%d%d%d",&p,&q,&r);
  a[p].Address=p;
  a[p].Key=q;
  a[p].next=r;
  }
  if(x==-1){
     printf("0 -1\n");
     return 0;
  }
  int index=0;
  while(x!=-1){
    b[index].Address=a[x].Address;
    b[index].Key=a[x].Key;
    b[index].next=a[x].next;
    x=a[x].next;
      ++index;
  }
  sort(b,b+index,cmp);
  printf("%d %05d\n",index,b[0].Address);
  for(i=0;i<index-1;++i){
    printf("%05d %d %05d\n",b[i].Address,b[i].Key,b[i+1].Address);
  }
  printf("%05d %d -1\n",b[index-1].Address,b[index-1].Key);

  system("pause");
return 0;
}
