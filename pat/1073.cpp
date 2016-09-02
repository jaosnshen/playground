nclude<iostream>
#include<cstdio>
#include<cstring>
#include<sstream>
#define MAXN 10001
using namespace std;
int a,ex;
char ch,dir,sign,c,zheng[MAXN],xiao[MAXN];
stringstream stream;
void slove_0(){
     cout<<a<<'.';
   cout<<zheng<<endl;
}
void slove_1(){
  int i,len;
  printf("0.");
  //len=strlen();
  for(i=0;i<ex-1;i++){
      cout<<0;
  }
  cout<<a<<zheng<<endl;
}
void slove_2(){
  cout<<a;
  int i;
  int len=strlen(zheng);
  if(ex>=len){
    cout<<zheng;
    for(i=0;i<ex-len;i++){
          cout<<0;
    }
    cout<<endl;
  }else{
    for(i=0;i<ex;i++){
       cout<<zheng[i];
    }
    cout<<'.';
    printf("%s\n",zheng+ex);
  }

}
int main(){
 /*   char c;
  char c2;
  int n;
  int number;
  int e;
  int i;
  int num,count=0;
  /*
  +1.23400E-03
     Sample Output 1:
    0.00123400
  
  scanf("%c%d.%dE%c%d",&c,&n,&number,&c2,&e);
  //n++;

  if(c=='-')
     cout<<'-';
  if(c2=='-'){
    num=n;
    while(num){
      count++;
      num/=10;

    }
    for(i=0;i<e-count+1;i++){
      if(i==0)
        cout<<'.';
      cout<<0;
    }
    cout<<n<<number<<endl;
  }else{
  num=number;
  while(num){
       count++;
     num/=10;
  }
  if(count>e){
     
  }
  }*/

  scanf("%c%d.%[^E]%c%c%s",&sign,&a,zheng,&ch,&dir,xiao);
  if(sign=='-') cout<<'-';
  stream<<xiao;
  stream>>ex;
  if(ex==0){
     slove_0();
     return 0;
  }
  if(dir=='-'){
    slove_1();
  }else{
    slove_2();
  }
  //system("pause");
  return 0;
}
