#include<iostream>
#include<string>
#include<vector>
#include<stack>
using namespace std;
vector<char> v;
stack<char> s;
char to13(int n){
  if(n<=9){
    return n+'0';
  }else if(n==10){
      return 'A';
  }else if(n==11){
      return 'B';
  }else {
      return 'C';
  }
}
void exhange2thr(int n){
  int i,temp;
  //string s;
  while(n){
     temp=n%13;
     s.push(to13(temp));
     n/=13;
  }
  if(s.size()==1){
    v.push_back('0');
  }else if(s.size()==0){
     v.push_back('0');
     v.push_back('0');
  }
  while(!s.empty()){
    v.push_back(s.top());
    s.pop();
  }

}
int main(){
  int len,i,R,B,G;
  cin>>R>>B>>G;
  exhange2thr(R);
  exhange2thr(B);
  exhange2thr(G);
  cout<<"#";
  len=v.size();
  for(i=0;i<len;i++){
    printf("%c",v[i]);
  }
  cout<<endl;
  //system("pause");
return 0;
}
