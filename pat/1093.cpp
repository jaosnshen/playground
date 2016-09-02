#include <iostream>
#include<string>
#define  MAXN 100001
using namespace std;
//int _count[MAXN][MAXN];
string s;
struct PTnum{
  int P;
  int T;
  PTnum(){
    P=T=0;
  };
};
PTnum num[MAXN];
int main()
{
  int len=0,i=0,j=0;
  long ans=0;
  cin>>s;
  len=s.size();
  if (s[0]=='P'){
    num[0].P=1;
  }
  /*if (s[len-1]=='T'){
    num[0].T=1;
  }*/
  for (i=1;i<len;i++){
    if (s[i]=='P'){
      num[i].P=num[i-1].P+1;
    }
    else
    {
      num[i].P=num[i-1].P;
    }
  }
  for (j=len-1;j>=0;j--){
    if (s[j]=='T'){
      num[j].T=num[j+1].T+1;
    }
    else
    {
      num[j].T=num[j+1].T;
    }
  }
  for (i=0;i<len;i++){
    if(s[i]=='A'){
      ans+=num[i].P*num[i].T;
    }
  }
  cout<<ans%1000000007<<endl;
  //system("pause");
  return 0;
}
