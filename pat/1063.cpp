#include<iostream>
#include<vector>
#include<algorithm>
#include<iterator>
#include<set>
using namespace std;
vector<int> Array[50];
void getAns(int n,int m)
{
  set<int> s(Array[n].begin(),Array[n].end());
  set<int> s1(Array[m].begin(),Array[m].end());
  set<int> v,u;
  //set_union(s.begin(),s.end(),s1.begin(),s1.end(),inserter(u,u.begin()));
  set_intersection(s.begin(),s.end(),s1.begin(),s1.end(),inserter(v,v.begin()));
  double ans=(v.size()*1.0)/((s.size()+s1.size()-v.size())*1.0);
  printf("%.1lf%%\n",ans*100);
}
int main()
{

  int i,n,num,l,m;
  int c1,c2;
  scanf("%d",&n);
  for(i=0;i<n;++i)
  {
     scanf("%d",&num);
     for(l=0;l<num;++l)
     {
       scanf("%d",&m);
       Array[i].push_back(m);
     }
     sort(Array[i].begin(),Array[i].end());
  }
  scanf("%d",&n);
  for(i=0;i<n;++i)
  {
     scanf("%d%d",&c1,&c2);
     getAns(c1-1,c2-1);
  }
  //system("pause");
return 0;

}
