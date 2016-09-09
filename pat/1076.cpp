#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
#define MAXN 1005
using namespace std;
vector<int> List[MAXN];
int vis[MAXN];
int Level;
struct Node
{
    int num;
  int l;
  Node(int num,int l):num(num),l(l){}
  Node(){}
};
int ans[MAXN];
int bfs(int num)
{
  int ans=0;
  memset(vis,0,sizeof(vis));
  queue<Node> q;
  vis[num]=true;
  q.push(Node(num,0));
  while(!q.empty())
  {
    Node now=q.front();
    q.pop();
    //if(now.l<Level)
    //  ans++;
    for(int i=0;i<List[now.num].size();++i)
    {
      if(!vis[List[now.num][i]])
      {
              vis[List[now.num][i]]=true;
        if(now.l+1<Level)
         q.push(Node(List[now.num][i],now.l+1));
        ans++;
        }
    }
  }
  return ans;
}
int main()
{
  int Ans;
  int K,child,num,l,i,N;
  cin>>N>>Level;
  for(i=1;i<=N;++i)
  {
     cin>>num;
     for(l=0;l<num;++l)
     {
       cin>>child;
     List[child].push_back(i);
     }
  }
  //cout<<endl<<endl;
  //for(i=1;i<=N;++i)
  //{
  //  cout<<i<<" ";
  //   //cin>>num;
  //  for(l=0;l<List[i].size();++l)
  //   {
  //     //cin>>child;
  //   cout<<List[i][l]<<" ";
  //   }
  //  cout<<endl;
  //}
  cin>>K;
  for(i=0;i<K;++i)
  {
      cin>>child;
       printf("%d\n",bfs(child));

    //  printf("%d\n",Ans);
  }
  //system("pause");
   return 0;
}
