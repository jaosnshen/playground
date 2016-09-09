#include<iostream>
#include<vector>
#define N 10000
using namespace std;
vector<int> v1;
//int preOrder[N];
struct node{
  int data;
  node *left;
  node *right;
  node(int v)
  {
    data = v;
    left = right = NULL;
  }
};
node *tree; 
void buildTree(int data,node * &root)
{  
  if (root == NULL)
  {
    root = new node(data);
    return;
  }
  else
  {
    if (root->data <= data)
      buildTree(data, root->right);
    else
      buildTree(data, root->left);
  }
}
void buiMirrorTree(int data,node * &root)
{
  if (root==NULL)
  {
    root = new node(data);
  }
  else
  {
    if (root->data>data)
    {
      buiMirrorTree(data, root->right);
    }
    else{
      buiMirrorTree(data, root->left);
    }
  }
}
void posTravel(node *root)
{
  if (root == NULL) return;
  posTravel(root->left);
  posTravel(root->right);
  v1.push_back(root->data);
    
}
void Treedelete(node *root)
{
  if (root == NULL)return;
  Treedelete(root->right);
  Treedelete(root->left);
  delete root;
}
void preTravel(node *root)
{
  if (root == NULL) return;
  //printf("%d ", root->data);
  v1.push_back(root->data);
  preTravel(root->left);
  preTravel(root->right);
  //printf("%d ", root->data);
}
int main()
{
  int i,n,pre;
  vector<int> v;// , v1, v2;
  //bool IsMir = true;

  while (cin >> n){
    node *root = NULL;
    node *root1 = NULL;
    v.clear();
    v1.clear();
    for (i = 0; i < n; ++i)
    {
      scanf("%d", &pre);//&preOrder[i]);
      v.push_back(pre);
    }
    for (i = 0; i < n; ++i)
    {
      buildTree(v[i], root);
    }
    preTravel(root);
    if (v == v1)//yes BST
    {
      v1.clear();
      posTravel(root);
      printf("YES\n%d", v1[0]);
      for (i = 1; i < n; ++i)
        printf(" %d", v1[i]);
      printf("\n");
    }
    else
    {
      v1.clear();
      for (i = 0; i < n; i++)
      {
        buiMirrorTree(v[i], root1);
      }
      preTravel(root1);
      if (v == v1)//Yes mirror
      {
        v1.clear();
        posTravel(root1);
        printf("YES\n%d", v1[0]);
        for (i = 1; i < n; ++i)
          printf(" %d", v1[i]);
        printf("\n");
      }
      else{
        printf("NO\n");
      }
    }
    Treedelete(root);
    Treedelete(root1);
  }
  //system("pause");
  return 0;
}
