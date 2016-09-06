#include <iostream>
#include<algorithm>
#include<map>
#include<vector>
#include<set>
#include<queue>
#define MAXN 10000
using namespace std;
map<int,vector<int>> adj;
set<int> tree,tre;
bool vis[MAXN];
int pos[MAXN],maxstep=-1;
int find(int x){
    if(x!=pos[x]){
       x=find(pos[x]);

    }
  return x;
}
void meger(int x,int y){
     x=find(x);
     y=find(y);
     if(x!=y){
        pos[x]=y;
     }
}
void init(int n){
    int i;
    for(i=1;i<=n;++i){
        pos[i]=i;
        vis[i]=false;
    }
}
void dfs(int n,int step){
    int i;
    if(maxstep<step){
         maxstep=step;
         tre.clear();
         tre.insert(n);
     }else if(maxstep==step){
         tre.insert(n);
    }
    int len=adj[n].size();
    for(i=0;i<len;i++){
        if(!vis[adj[n][i]]){
            vis[adj[n][i]]=true;
            dfs(adj[n][i],step+1);
            vis[adj[n][i]]= false;
        }
    }
}
int main() {
    int abence=0,n,i,a,b;
    cin>>n;
    init(n);
    for (i = 0; i <n-1 ; ++i) {
        cin>>a>>b;
        meger(a,b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(i=1;i<=n;i++){
        if(pos[i]==i)
            abence++;
    }
    if(abence>1){
        printf("Error: %d components\n",abence);
    }else{
        vis[1]=true;
        dfs(1,0);
        vis[1]= false;
        auto it=tre.begin();
        for(it=tre.begin();it!=tre.end();it++){
            tree.insert(*it);
        }
        int max=*tre.begin();
        tre.clear();
        vis[max]=true;
        dfs(max,0);
        vis[max]=false;
        for (it = tre.begin(); it!=tre.end();it++) {
            tree.insert(*it);
        }
        for (it = tree.begin(); it !=tree.end() ; ++it) {
            cout << *it << endl;
        }
    }
    return 0;
}
