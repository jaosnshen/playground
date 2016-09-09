#include<iostream>
#include<vector>
#include<queue>
#define MAXN 35
using namespace std;

vector<int> ans;
struct node{
  int left;
  int right;
};
node tree[MAXN];
int buiTree(int a[],int b[],int n)
{
  if(n<=0) return -1;  
  int i,root=a[n-1];
  //tree[root].data=root;
  tree[root].left=-1;
  tree[root].right=-1;
  //if()
  for(i=0;i<n;++i){
      if(b[i]==root)
      break;
  }
  //左中右
  //左右中
  tree[root].left=buiTree(a,b,i);
  tree[root].right=buiTree(a+i,b+i+1,n-1-i);
  return root;
}
void levelTravel(int root)
{
   int now;
   queue<int> q;
   q.push(root);
   while(!q.empty())
   {
     now=q.front();
     q.pop();
     if(tree[now].left!=-1)
       q.push(tree[now].left);
     if(tree[now].right!=-1)
       q.push(tree[now].right);
     ans.push_back(now);
   }
}
int main(){
  int i,n,root,size;
  cin>>n;
  int *inOrder=new int[n];
  int *posOrder=new int[n];
  for(i=0;i<n;++i)
  {
    cin>>inOrder[i];
  }
  for(i=0;i<n;i++)
  {
    cin>>posOrder[i];
  }
  root=buiTree(inOrder,posOrder,n);
  levelTravel(root);
  size=ans.size();
  for(i=0;i<size;++i)
  {
    if(size-1!=i)
      cout<<ans[i]<<" ";
    else
      cout<<ans[i]<<endl;
  }
  delete []inOrder;
  delete []posOrder;
  system("pause");
return 0;
}
