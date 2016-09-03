nclude<iostream>
#include<string>
#include<algorithm>
using namespace std;
class  person{
public:
   string name;
   string Id;
   int grade;
   bool operator<(const person &a) const{
     if(a.grade<=grade) return true;
       return false;
   }
   void output(){
     cout<<name<<" "<<Id<<endl;
   }
};
person *p;
void intput(int &n,int &low,int &high){
  int i;//,low,high;
  cin>>n;
  p=new person[n];
  person indigit;
  for(i=0;i<n;++i){
    cin>>p[i].name>>p[i].Id>>p[i].grade;
  }
  cin>>low>>high;
}
void solve(int n,int low,int high){
  int i;
  bool flag=false;
  sort(p,p+n);
  for(i=0;i<n;i++){
    if(low<=p[i].grade&&p[i].grade<=high){
      p[i].output();
        flag=true;
    }
  }
  if(!flag)
    cout<<"NONE\n";
  delete []p;
}
int main(){
   int n,low,high;
   intput(n,low,high);
   solve(n,low,high);
   //system("pause");
return 0;
}
