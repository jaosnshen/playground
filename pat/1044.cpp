#include<iostream>
#include<climits>
#define MAXN 100000
using namespace std;
int dia[MAXN];
struct node{
  int x;
  int y;
}ans[MAXN];
int main(){
  int k,i,n,pri,l,sum,max=INT_MAX,jmp=0;//初始化
    scanf("%d%d",&n,&pri);
  for(i=0;i<n;i++){
     scanf("%d",&dia[i]);
  }
  k=0;
  for(i=0;i<n;i++){
      sum=0;
    for(l=i+jmp;l<n;l++){
      sum+=dia[l];
      if(sum>=pri){
        if(sum==max){
          ans[k].x=i+1;
          ans[k].y=l+1;
          k++;
        }
        if(sum<max){
          k=0;
          ans[k].x=i+1;
          ans[k].y=l+1;
          k++;
          max=sum;
        }
        if(sum==pri&&l-i>1){
          jmp=l-i-1;
        }
        else{
          jmp=0;
        }
        break;
      }  
    }
    if(sum==max&&l==n)
      break;
  }
  for(i=0;i<k;i++){
    printf("%d-%d\n",ans[i].x,ans[i].y);
  }
      //system("pause");
return 0;
}
