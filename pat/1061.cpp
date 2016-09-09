#include<iostream>
#include<string>
#include<cstring>
using namespace std;
string WEEK[]={"MON","TUE","WED","THU","FRI","SAT","SUN"};
int main()
{
  // "MON" for Monday, "TUE" for Tuesday, "WED" for Wednesday, 
  //"THU" for Thursday, "FRI" for Friday, "SAT" for Saturday, 
  //and "SUN" for Sunday
  int i;
  int len;
  int len1;
  bool flag=false;
  string s[4];
  for(i=0;i<4;++i)
    cin>>s[i];
  len=s[0].size();
  len1=s[1].size();
  for(i=0;i<len&&i<len1;++i)
  {
      if(s[0][i]==s[1][i]&&!flag&&s[0][i]<='G'&&s[0][i]>='A')
    {
      cout<<WEEK[s[1][i]-'A']<<" ";
      flag=true;
      continue;
    }
    if(s[0][i]==s[1][i]&&flag)//&&(s[0][i]<='9'&&s[0][i]>='0')||(s[0][i]<='N'&&s[0][i]>='A'))
    {
      if(s[0][i]<='9'&&s[0][i]>='0'){
        cout<<0<<s[0][i]<<":";
        flag=false;
      }
      else if(s[0][i]<='N'&&s[0][i]>='A')
      {
        cout<<s[0][i]-'A'+10<<":";
        // break;
        flag=false;
      }
      if(!flag)
        break;
    }
  }
  len=s[2].size();
  len1=s[3].size();
  int pos=-1;
  for(i=0;i<len1&&i<len;++i)
  {
    if(s[2][i]==s[3][i]&&s[2][i]<='z'&&s[2][i]>='a'||s[2][i]<='Z'&&s[2][i]>='A')
    {
    //  cout<<i<<endl;
    //printf("%02d\n",i);
      pos=i;
      break;
    }
  }
  if(pos!=-1)
  printf("%02d\n",pos);
  else
  printf("00\n");
    system("pause");
  return 0;
}
