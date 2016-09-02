#include <iostream>
#include <string>
#define  MAXN 1000
using namespace std;
bool chess[MAXN]={0};
bool chesstarget[MAXN]={0};
int main()
{
  string s;
  string s1;
  int ans=0,i,l;
  cin>>s>>s1;
  int slen=s.size();
  int slen1=s1.size();
  for (i=0;i<slen1;i++)
  {
    for (l=0;l<slen;l++){
    if (s1[i]==s[l]&&!chesstarget[l]){
      chess[i]=true;
      chesstarget[l]=true;
        break;
    }
    }
  }
  for (i=0;i<slen1;i++)
  {
    if (chess[i])
    {
      ans++;
    }
  }
  if (ans==slen1)
  {
        cout<<"Yes"<<" "<<slen-slen1<<endl;
  }
  else
  {
    cout<<"No"<<" "<<slen1-ans<<endl;
  }

  system("pause");
  return 0;
}
