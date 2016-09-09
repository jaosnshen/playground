#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
const int MAXN = 26*26*26*10+1;
vector<int> stu[MAXN];
int HashName(const char *name)
{
  return (name[0] - 'A') * 26 * 26 * 10
    + (name[1] - 'A') * 26 * 10
    + (name[2] - 'A') * 10
    + (name[3] - '0');
}
int main()
{
  int N, K,i,l,len;
  int course,cname;
  char  name[5];
  int haname;
  while(scanf("%d%d", &N, &K)!=EOF){
  for (i = 0;i<K;i++)
  {
    scanf("%d%d", &course, &cname);
    for (l = 0;l<cname;++l)
    {
      scanf("%s",name);
      haname = HashName(name);
      stu[haname].push_back(course);
    }
  }

  for (i = 0;i<N;++i){
    scanf("%s", name);
    haname = HashName(name);
    len = stu[haname].size();
    //cout << name << " " << len << " ";
    printf("%s %d", name, len);
    sort(stu[haname].begin(), stu[haname].end());
  //  printf(" %d", stu[haname][0]);
    for (l = 0; l < len; ++l)
    //if(l!=len-1) 
      printf(" %d", stu[haname][l]);
    //else
     // printf(" %d\n",stu[haname][l]);
     printf("\n");
  }
}
  //system("pause");
  return 0;
}
