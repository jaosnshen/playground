#include<iostream>
#include <string>
#include<vector>
#include <algorithm>
#include<cstring>
#define MAXN 100000
using namespace std;
struct people
{
     char _name[9];
     int _age;
     int _worth;
};
vector<people> ans;
bool cmp(const people &a,const people &b)
{ 
  if(a._age<b._age)
    return true;
  else if (a._age==b._age)
    if (a._worth>b._worth)
      return true;
    else if (a._worth==b._worth)
       if (memcmp(a._name,b._name,min(strlen(a._name),strlen(b._name)))<0)
         return true;
       else
         return false;
      //return ;
  return false;
}
bool cmp1(const people &a,const people &b)
{ 
  if(a._worth>b._worth)
    return true;
  else if (a._worth==b._worth)
    if (a._age<b._age)
      return true;
    else if (a._age==b._age)
      if (memcmp(a._name,b._name,min(strlen(a._name),strlen(b._name)))<0)
        return true;
      else
        return false;
  return false;
}
people number[MAXN];
int main()
{
  int count=0,i,N,K,len;
  int num,amin,amax;
  //cin>>N>>K;
  scanf("%d%d",&N,&K);
  for (i=0;i<N;++i)
  {
    //cin>>number[i]._name>>number[i]._age>>number[i]._worth;
      scanf("%s%d%d",number[i]._name,&number[i]._age,&number[i]._worth);
  }
  sort(number,number+N,cmp1);
  while(count<K)
  {
    int t=0;
    ans.clear();
    //cin>>num>>amin>>amax;
    //cout<<""
    scanf("%d%d%d",&num,&amin,&amax);
    printf("Case #%d:\n",++count);
    for (i=0;i<N&&t<num;i++)
    {
      if(number[i]._age>=amin&&number[i]._age<=amax){
          //ans.push_back(number[i]);
            printf("%s %d %d\n",number[i]._name,number[i]._age,number[i]._worth);
              t++;
      }
    }
    if(!t)
      printf("None\n");
    //sort(ans.begin(),ans.end(),cmp1);
      ///len=ans.size();
    //if(len!=0)
    //{
    //fo(i=0;i<num&&i<len;++i)
    //{
    //  printf("%s %d %d\n",ans[i]._name,ans[i]._age,ans[i]._worth);
    //}
    //}
    //else
    //{
      //printf("None\n");
    //}
    
  }
  system("pause");
  return 0;
}
