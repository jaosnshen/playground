#include<iostream>
#include<queue>
using namespace std;
const int maxn=1000;
int TimeCusTomer[maxn];
int TimeFinish[maxn];
int WindowsListTime[20];//窗口时间
int TimeStart[maxn];
struct CTime{
    int NumWindow;//属于哪个窗口
  int ListHost;//队列所属位置
  int TatolTime;//
  CTime()
  {
  NumWindow=ListHost=TatolTime=0;
  }
  CTime(int N,int L,int T):NumWindow(N),ListHost(L),TatolTime(T){}
  bool operator<(const CTime &a) const 
  {
    if(TatolTime>a.TatolTime)
      return true;
    else if(TatolTime==a.TatolTime)
    {
      return NumWindow>a.NumWindow;
    }
    else
      return false;
  }
  friend ostream &operator<<(ostream &os,const CTime &a)
  {
    os<<a.TatolTime<<" "<<a.NumWindow<<" "<<a.ListHost<<endl;
    return os;
  }
};
priority_queue<CTime> p;
void PrintfTime(int num,int timeStart)
{
  num+=8*60;
  timeStart+=8*60;
  if(num<=60*17||timeStart<60*17)
  {
     printf("%02d:%02d\n",num/60,num%60);
  }
  else 
  {
    printf("Sorry\n");
  }
}
int main()
{
  int i,l,N,M,K,Q;
  int num;
  int cur=0;
  scanf("%d%d%d%d",&N,&M,&K,&Q);
  for(i=0;i<K;++i)
  {
     scanf("%d",TimeCusTomer+i);
  }
  for(l=0;l<N&&cur<K;++l)
  {
    p.push(CTime(l,cur,TimeCusTomer[cur]));
    WindowsListTime[cur]=TimeCusTomer[cur];
    TimeStart[cur]=0;
    cur++;
  }
  for(i=N;i<N*M&&cur<K;++i)
  {
    TimeStart[cur]=WindowsListTime[i%N];
    WindowsListTime[i%N]+=TimeCusTomer[i];
    p.push(CTime(i%N,cur,WindowsListTime[i%N]));
    cur++;
  }
  while(!p.empty())
  {
    CTime now=p.top();
    p.pop();
    TimeFinish[now.ListHost]=now.TatolTime;
    TimeStart[cur]=WindowsListTime[now.NumWindow];
    WindowsListTime[now.NumWindow]+=TimeCusTomer[cur];
      if(cur<K)
    {
      p.push(CTime(now.NumWindow,cur,WindowsListTime[now.NumWindow]));//进入排队
        cur++;
    }
  }
  for(int i=0;i<Q;++i)
  {
      scanf("%d",&num);
    PrintfTime(TimeFinish[num-1],TimeStart[num-1]);
  }
  system("pause");
   return 0;
}
