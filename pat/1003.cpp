#include<iostream>
#include<climits>
#define MAXN 10000
using namespace std;
int n,m;
int c1,c2;
int mindist=INT_MAX,MAXcost,path=0;
int map[MAXN][MAXN];
int cost[MAXN]={0};
int used[MAXN];
void dfs(int c1,int c2,int wei,int distance){//wei负载 dis 距离
  if(c1==c2){
    if(distance<mindist){
       path=1;
       mindist=distance;
       MAXcost=wei;
    }else if(distance==mindist){
       path++;
       if(wei>MAXcost)
         MAXcost=wei;
    }
    return;
  }
  int i;
  if(distance>mindist) return;
  for(i=0;i<n;i++){
    if(!used[i]&&map[c1][i]!=INT_MAX){
       used[i]=true;
       dfs(i,c2,wei+cost[i],distance+map[c1][i]);
       used[i]=false;
    }
  
  }
}
void init(int n){
  int i,j;
  for(i=0;i<n;i++){
     used[i]=false;
     for(j=0;j<n;j++){
        map[i][j]=INT_MAX;
     }
  }
}
int main(){
  int i,l;
  int x,y,t;
  cin>>n>>m>>c1>>c2;//>>n>>m;
  init(n);
  for(i=0;i<n;++i){
    cin>>cost[i];
  }
  for(i=0;i<m;++i){
    cin>>x>>y>>t;
    if(map[x][y]>t){
       map[x][y]=map[y][x]=t;
    }
  }
  dfs(c1,c2,cost[c1],0);
  cout<<path<<" "<<MAXcost<<endl;
  //system("pause");
return 0;
}
