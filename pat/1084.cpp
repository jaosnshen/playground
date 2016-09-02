#include <iostream>
#include <string>
#include <vector>
using namespace std;
void capitalize(string &s){
  int len=s.size();
  for (size_t i=0;i<len;i++){
    if (s[i]>='a'&&s[i]<='z'){
      s[i]=s[i]-'a'+'A';
    }
  }
}
int main()
{
  string s1,s2;
  vector<bool> already(1000,false);
  int len;
  //int len1;
  cin>>s1>>s2;
  len=s1.size();
  //len1=s2.size();
  capitalize(s1);
  capitalize(s2);
  for (size_t i=0,j=0;i<len;i++){
    if(s1[i]!=s2[j]){
      if (!already[s1[i]]){
        already[s1[i]]=true;
          cout<<s1[i];
      }
    }
    else
    {
      j++;
    }
  }
  return 0;
}
