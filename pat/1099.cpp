#include<iostream>
#include<algorithm>
#include<queue>
#define MAXN 101
using namespace std;
struct Node {
  int right, left;
};
Node Tree[MAXN];
int Array[MAXN];
int After[MAXN];
int IndexNum[MAXN];
int Count;
void LevelTravel(int root)
{
  queue<int> q;
  q.push(root);
  int cnt=1;
  IndexNum[cnt] = root;
  while (!q.empty())
  {
    int now = q.front();
    q.pop();
    if (Tree[now].left != -1)
    {
      q.push(Tree[now].left);
      IndexNum[cnt++] = Tree[now].left;
    }
    if (Tree[now].right != -1)
    {
      q.push(Tree[now].right);
      IndexNum[cnt++] = Tree[now].right;
    }
  }
}
int index;
void InOrderTravel(int root) 
{
  if(root!= -1)
  {
    InOrderTravel(Tree[root].left);
    //InOrderTravel();
    //cout << Array[index]<<endl;
    After[root] = Array[index++];
    InOrderTravel(Tree[root].right);
  }
}
int main()
{
  int i,n;
  int l, r;
  cin >> n;
  for (i = 0;i<n;++i)
  {
    cin >> l >> r;
    Tree[i].left = l;
    Tree[i].right = r;
  }
  for (i = 0;i<n;++i)
  {
    cin >> Array[i];
  }
  sort(Array, Array + n);
  index=0;
  InOrderTravel(0);
  LevelTravel(0);
  cout << After[IndexNum[0]];
  for (i = 1;i<n;++i)
  {
    cout<<" "<<After[IndexNum[i]];
  }
  cout << endl;
  //system("pause");
  return 0;
}
