#include<iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
//#define MAXN 100001
using namespace std;
struct per{
  int id;
  int m;
  int i;
  void output(){
    printf("%d %d %d\n",id,m,i);
  }
  bool operator<(const per &A) const {
    if (m+i!=A.m+A.i)
    {
      return m+i>A.m+A.i;
    }else{
      if (m!=A.m)
      {
        return m>A.m;
      }else{
                return id<A.id;
      }
    }
  }
};
vector<per> stu1,stu2,stu3,stu4;
int main(){
  int N,L,H,i;
  int level=0;
  per input;
  cin>>N>>L>>H;
  for (i=0;i<N;i++){
    scanf("%d%d%d",&input.id,&input.m,&input.i);
    if (input.m>=L&&input.i>=L)
    {
      level++;
      if (input.m>=H&&input.i>=H)
      {
        stu1.push_back(input);
        //lv1++;
      }else if (input.m>=H&&input.i<H)
      {
        stu2.push_back(input);
        //lv2++;
      }else if (input.m<H&&input.i<H&&input.m>=input.i)
      {
        stu3.push_back(input);
        //lv3++;
      }else{
        stu4.push_back(input);
        //lv4++;
      }
    }
  }
  sort(stu1.begin(),stu1.end());
  sort(stu2.begin(),stu2.end());
  sort(stu3.begin(),stu3.end());
  sort(stu4.begin(),stu4.end());
    printf("%d\n",level);
  vector<per> ::iterator it;
  for (it=stu1.begin();it!=stu1.end();it++)
  {
     it->output();
  }
  for (it=stu2.begin();it!=stu2.end();it++)
  {
    //stu2[i].output();
      it->output();
  }
  for (it=stu3.begin();it!=stu3.end();it++)
  {
    //stu2[i].output();
    it->output();
  }
  for (it=stu4.begin();it!=stu4.end();it++)
  {
    //stu2[i].output();
    it->output();
  }
  //system("pause");
  return 0;
}
