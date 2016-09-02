nclude <iostream>
#include<string>
//#include <stdio.h>
using namespace std;
int main(){
  int n;
  cin>>n;
  string id;
  int ih,im,is,oh,om,os;
  int intime=3600*24;
  int otime=-1,time;
  string fid,lid;
  while (n--){
    cin>>id;
    //scanf("%d%*c%d%*c%d %d%*c%d%*c%d",&ih,&im,&is,&oh,&om,&os);
    scanf("%d:%d:%d %d:%d:%d",&ih,&im,&is,&oh,&om,&os);
    time=ih*3600+im*60+is;
    if (time<intime){
      intime=time;
      fid=id;
    }
    time=oh*3600+om*60+os;
    if (time>otime){
      //strcpy(lid,id);
      otime=time;
      lid=id;
    }
  }
  cout<<fid<<" "<<lid<<endl;

  //system("pause");
  return 0;
}
