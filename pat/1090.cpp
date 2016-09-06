#include<iostream>
#include<vector>
#include<cmath>
#include<cstring>
using namespace std;
/*
 N (<=105), the total number of the members in the supply chain (and hence they are numbered from 0 to N-1); 
 P, the price given by the root supplier; and 
 r, the percentage rate of price increment for each distributor or retailer. 
 Then the next line contains N numbers, each number Si is the index of the supplier for the i-th member. 
 Sroot for the root supplier is defined to be -1. All the numbers in a line are separated by a space.
*/
const int maxn=100001;
int vis[maxn];
int ans;
int num;
vector<int> v[maxn];
void dfs(int root,int deep)
{
  int i;
  int len=v[root].size();
    if(len==0)
  {
   if(ans<deep)
   {
     ans=deep;
     num=1;
   }else if(ans==deep)
   {
     num++;  
   }
  }
  for(i=0;i<len;++i)
  {
     if(!vis[v[root][i]])
     {
        vis[v[root][i]]=true;
      dfs(v[root][i],deep+1);
      vis[v[root][i]]=false;
     }
  }
}
void init(int n)
{
  int i;
  for(i=0;i<n;i++)
  {
    vis[i]=false;
    v[i].clear();
  }
}
int main()
{
  int i,N;
  double P,R;
  double price;
  int index;
  int root;
  scanf("%d %lf %lf",&N,&P,&R);
  init(N);
  for(i=0;i<N;++i)
  {
    scanf("%d",&index);
    if(index==-1)
      root=i;
    else
      v[index].push_back(i);
  }
  ans=0;
  dfs(root,0);
  price=pow(1.0+(R/100.0),ans*1.0)*P;
  printf("%.2lf %d",price,num);
  system("pause");
  return 0;
}
