#include<iostream>
#define MAXN  100000
using namespace std;
int map[MAXN];
int dp[MAXN]={0};
int main(){
    int sum=0,ans,i,l,x,y,N,M;
  cin>>N;
  for(i=1;i<=N;i++){
      cin>>map[i];
    dp[i]=dp[i-1]+map[i];
      sum+=map[i];
  }
  //sum/=2;
  cin>>M;
  ans=0;
  //ans1=0;
  for(i=0;i<M;i++){
      cin>>x>>y;
    if(x>y)
      swap(x,y);
    ans=dp[y-1]-dp[x-1];
    if(sum/2<ans){
       ans=sum-ans;
    }
    cout<<ans<<endl;
    ans=0;
    //ans1=0;
  }
  //system("pause");

return 0;
}
