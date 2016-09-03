#include<iostream>
#include<string>
#include<algorithm>
#define MAXN 101
using namespace std;
string str[MAXN];//,str1;
int main(){
  int k,end=266,i,l,n,len,len1;
  bool f;
  cin>>n;
  getchar();
  for(i=0;i<n;i++){
  getline(cin,str[i]);
  reverse(str[i].begin(),str[i].end());
  }
  for(k=1;k<n;k++){
    len=str[k-1].length();
    len1=str[k].length();
    for(i=0,l=0;i<len&&l<len1;i++,l++){
      if(str[k][l]!=str[k-1][i]){
            break;     
      }
    }
        if(end>i){
       end=i;
    }
  }
  ////  if(f)
  if(end==0){
      cout<<"nai\n";  
  }else{
  for(i=end-1;i>=0;i--){
       cout<<str[n-1][i];
  }
  cout<<endl;
  }
  //system("pause");
return 0;
}
