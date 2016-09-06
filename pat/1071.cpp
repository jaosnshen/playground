#include<iostream>
#include<map>
#include<vector>
#include<string>

using namespace std;

int main(){
  map<string,int> m;  //记录单词出现的次数
  int i = 0;
  char t;
  vector<char> input;
  while(scanf("%c",&t)){
    if(t == '\n')
      break;
    input.push_back(t);    
  }
  input.push_back('\n');
  vector<char>::iterator it = input.begin();
  int len = input.size();
  int begin = -1,end = -1;  //记录一个单词的起止位置
  int max = 0;
  string s_temp;
  for(i=0; i<len; i++){
    if(input[i] == '\n') break;
    //如果是字母或者数字就继续输入
    if( isalpha(input[i]) || isdigit(input[i])){
      if(!islower(input[i])){
        input[i] = tolower(input[i]);      
      }      
      if(begin == -1){
        begin = i;
      }
      end = i;
    }
    //如果不是字母或数字
    else{
      if( begin != -1 ){
        string s(it+begin, it+end+1);
        m[s] ++;
        if(m[s] > max || ( m[s] == max && s<s_temp )){
          max = m[s];
          s_temp = s;
        } 
      }      
      begin = -1;
    }
  }
  //最后一个单词
  if(begin != -1){
    string s(it+begin, it+end+1);
    m[s] ++;
    if(m[s] > max || ( m[s] == max && s<s_temp )){
      max = m[s];
      s_temp = s;
    }
  }
  if(max != 0)
    cout<<s_temp<<" "<<max<<endl;
  return 0;
}
