#include <iostream>
#include <string>
using namespace std;
struct stu
{
  string name;
  char  gender;
  string ID ;
  int grade;
};
void output(string s){
  int i,len=s.size();
  for (i=0;i<len;i++)
  {
    cout<<s[i];
  }

}
stu Student;
int Fi,Mi;
int Mgrade=-1,Fgrade=101;
int main()
{
  int n,i,flag=0;
  stu Fstemp,Mstemp;
  cin>>n;
  for (i=0;i<n;i++)
  {
    cin>>Student.name>>Student.gender>>Student.ID>>Student.grade;
    if (Student.gender=='M')
    {
      if (Fgrade>Student.grade)
      {
        Fgrade=Student.grade;
        Fstemp=Student;
      }
    }
    else{
      if (Mgrade<Student.grade)
      {
        Mgrade=Student.grade;
        Mstemp=Student;
      }
    }
  }
  if (Mgrade!=-1){
    output(Mstemp.name);
    cout<<" ";
    output(Mstemp.ID);
    cout<<endl;
  }
  else{
    flag=1;
    cout<<"Absent"<<endl;
  }
  if (Fgrade==101){
    cout<<"Absent"<<endl;
    flag=1;
  }
  else{
    output(Fstemp.name);
    cout<<" ";
    output(Fstemp.ID);
    cout<<endl;
  }
  
  if (flag)
  {
    cout<<"NA"<<endl;
  }
  else{
    cout<<Mstemp.grade-Fstemp.grade<<endl;
  }
  //system("pause");
  return 0;
}
