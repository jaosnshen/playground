#include<iostream>
#include<algorithm>
#define MAXN 10001
using namespace std;
int Stripe[MAXN];
int Like[MAXN];
int dp[MAXN][MAXN];
int main()
{
  int i,x,n,m,l;
  cin>>x>>n;
  for(i=0;i<n;++i)
  {
     cin>>Like[i+1];
  }
  cin>>m;
  for(i=0;i<m;++i)
  {
     cin>>Stripe[i+1];
  }
  for(i=1;i<=n;++i)
  {
     for(l=1;l<=m;++l)
     {
        int temp=max(dp[i-1][l],max(dp[i][l-1],dp[i-1][l-1]));
      if(Stripe[l]==Like[i])
        dp[i][l]=temp+1;
      else
        dp[i][l]=temp;
     }
  }
  cout<<dp[n][m]<<endl;
  //system("pause");
   return 0;
}
