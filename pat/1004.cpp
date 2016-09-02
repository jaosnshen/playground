nclude<iostream>
#include <map>
#include <vector>
#define MAXN 101
using namespace std;
map<int,vector<int>> Graph;
int count_[MAXN];
int maxnLevel=0;
void dfs(int node,int levels){
  if(Graph[node].empty()){
    if(maxnLevel<levels){
      maxnLevel=levels;
    }
          count_[levels]++;  
  }else{
  vector<int>::iterator it;
    for (it=Graph[node].begin();it!=Graph[node].end();it++){
      dfs(*it,levels+1);
  }
  }
  return;
}
void init(int m){
  int i;
  for (i=0;i<m;i++)
  {
    count_[i]=0;
  }
}
int main()
{
  int m,n,i,l,node,_count,p;
  cin>>m>>n;
  init(n);
  for (i=0;i<n;i++){
    cin>>node>>_count;
    for (l=0;l<_count;l++){
      cin>>p;
      Graph[node].push_back(p);
    }
  }
  if (n==0)
  {
    count_[0]=1;
    maxnLevel=0;
  }
  else{
  //count_[0]=0;
  dfs(1,0);
  }
  for (i=0;i<maxnLevel;i++)
  {
    cout<<count_[i]<<" ";
  }
  cout<<count_[i]<<endl;
  //system("pause");
  return 0;
}
