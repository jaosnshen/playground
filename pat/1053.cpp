#include<iostream>
//#include<map>
#include<vector>
#include<string>
#include<algorithm>
#define MAXN 101
using namespace std;
vector<int> tree[MAXN];
vector<int> t,ans[MAXN];
vector<int> ::iterator it;
int weight[MAXN],S,lengh=0;
//bool cmp(const int &a,int const &b){
//  return a>b;
//}
void dfs(int node,int w){
  //if()
  //if()
  if(w>S) return;
  else if(w==S&&tree[node].size()==0){
  /*  int len=t.size();
    for(int i=0;i<len-1;i++){
      cout<<t[i]<<" ";
    }
    cout<<t[len-1]<<endl;*/
    ans[lengh++]=t;
    return;
  }
  auto itt=tree[node].begin();
  for(itt=tree[node].begin();itt!=tree[node].end();++itt){
    t.push_back(weight[*itt]);
      dfs(*itt,w+weight[*itt]);
    t.pop_back();
  }
}
bool cmp(const vector<int> &a,const vector<int> &b){
  int len1=a.size();
  int i,len2=b.size();
  for(i=0;i<len1&&i<len2;i++){
     if(a[i]>b[i])
       return true;
  }
  return false;
}
int main(){
  int l,i,N,M,p,time,node;
  scanf("%d%d%d",&N,&M,&S);
  for(i=0;i<N;++i){
   cin>>weight[i];
  }
  for(i=0;i<M;++i){
     cin>>p>>time;
    for(l=0;l<time;l++){
      cin>>node;
      tree[p].push_back(node);
    }
  }
  t.push_back(weight[0]);
  dfs(0,weight[0]);
  sort(ans,ans+lengh);
  for(i=lengh-1;i>=0;i--){
    int len=ans[i].size();
    for(l=0;l<len-1;l++){
      cout<<ans[i][l]<<" ";
    }
      cout<<ans[i][len-1]<<endl;
  }
  system("pause");
return 0;
}
