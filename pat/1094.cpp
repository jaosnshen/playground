#include <iostream>
#include <map>
#include <vector>
#define  MAXN 101
using namespace std;
map<int,vector<int>> adjlist;
struct ans
{
  int level;
  int num;
  ans(){
    level=num=0;
  }
};
ans lev[MAXN];
//bool cmp(const ans &a,const ans &b){
//  if (a.num>=b.num)
//  {
//    return true;
//  }
//  else
//  {
//    return false;
//  }
//
//}
void DFS(int level,int id){
    //ans[level]++;
  lev[level].num++;
  lev[level].level=level;
  vector<int>::iterator it;
  for (it=adjlist[id].begin();it!=adjlist[id].end();it++)
  {
    DFS(level+1,*it);
  }
}
int main()
{
  int n,m,i,j;
  ans finalans;
  cin>>n>>m;
  int ID,c,k;
  for (i=0;i<m;i++)
  {
    cin>>ID>>k;
    //adjlist[ID].
      for (j=0;j<k;j++){
      cin>>c;
      adjlist[ID].push_back(c);
      }
  }
  DFS(1,1);
  for (i=0;i<MAXN;i++)
  {
    if (lev[i].num>finalans.num)
    {
      finalans=lev[i];
    }
  }
    //sort(lev,lev+MAXN-1,cmp);
  cout<<finalans.num<<" "<<finalans.level<<endl;
   // system("pause");
  return 0;
}
