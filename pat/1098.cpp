#include<iostream>
#include<climits>
using namespace std;
//插入排序
const int maxn=101;
int OriginArray[maxn];
int TargetArray[maxn];
int OriginArray1[maxn];
void PrintfArray(int *A,int len)
{
  int i;
  cout<<A[1];
  for(i=2;i<=len;i++)
  {
    cout<<" "<<A[i];
  }
  cout<<endl;
}
bool InsertSort(int *sum,int len)
{
  int ii,i,j,key;
  int f=0;
  for(i=2;i<=len;++i)
  {
    key=sum[i];
    j=i-1;
    while(j>=1&&sum[j]>key)
    {
      sum[j+1]=sum[j];
      j--;
    }
    sum[j+1]=key;
    /*PrintfArray(sum,len);*/
    if(f)
      return true;
    for(ii=1;ii<=len;++ii)
    if(sum[ii]!=TargetArray[ii])
             break;
    if(ii==len+1)
    {
      f=1;
      continue;
    }
  }
  return false;
}
/*归并排序*/
void Merge(int A[],int p,int q,int r)
{
  int n1=q-p+1;
  int n2=r-q;
  int *L=new int[n1+1];
  int *R=new int[n2+1];
  int i,j,k;
  for(i=0;i<n1;++i)
  {
    L[i]=A[p+i];
  }
  //PrintfArray(L,n1);
  for(j=0;j<n2;++j)
  {
    R[j]=A[q+j+1];
  }
  //PrintfArray(R,n2);
  L[n1]=INT_MAX;
  R[n2]=INT_MAX;
  j=0;
  i=0;
  for(k=p;k<=r;k++)
  {
    if(L[i]<=R[j])
    {
       A[k]=L[i++];
    }
    else
    {
       A[k]=R[j++];
    }
  }
  //PrintfArray(A,r+1);
  delete []L;
  delete []R;
}
void Merge_Sort(int A[],int p,int r)
{
  if(p<r)
  {
     int q=(r+p)/2;
     Merge_Sort(A,p,q);
     Merge_Sort(A,q+1,r);
     Merge(A,p,q,r);
  }
}
//堆排序
int Parent(int n)
{
    return n/2;
}
int Left(int n)
{
  return n<<1;
}
int Right(int n)
{
   return (n<<1)+1;
}
//维护堆的性质
void MaxHeapify(int A[],int i,int len)
{
  int l=Left(i);
  int r=Right(i);
  int largest;
  if(l<=len&&A[l]>A[i])
  {
    largest=l;
  }else
  {
    largest=i;
  }
  if(r<=len&&A[r]>A[largest])
    largest=r;
  if(largest!=i)
  {
     swap(A[largest],A[i]);
     MaxHeapify(A,largest,len);
  }
}
void BuildMaxHeap(int A[],int len)
{
  int i;
   for(i=len/2;i>0;i--)
     MaxHeapify(A,i,len);
}
bool HeapSort(int A[],int len)
{
  int f=0;
  int ii;
  //int maxlen=len;
  BuildMaxHeap(A,len);
  for(int i=len;i>1;i--)
  {
    swap(A[1],A[i]);
    len--;
    MaxHeapify(A,1,len);
    //PrintfArray(A,maxlen);
    if(f)
      return true;
    for(ii=1;ii<=len;++ii)
    {
      if(A[ii]!=TargetArray[ii])
             break;
    }
    if(ii==len+1)
    {
      f=1;
    continue;
    }
  }
  return false;
}

int main()
{
  //cout<<(8<<1)+1<<endl;
  /*int i,sum[]={123,5,2,4,6,1,3};
  int len=sizeof(sum)/sizeof(int);
  InsertSort(sum,len);
  for(i=0;i<=len;++i)
    printf("%d ",sum[i]);
  cout<<endl;
  /*____________________________________________________
  int _array[]={22,14,35,74,1,12,3,6};
  len=sizeof(_array)/sizeof(int);
  Merge_Sort(_array,0,len-1);
  PrintfArray(_array,len);
  /*____________________________________________________
  int HeapArray[]={9999,4,1,3,2,16,9,10,14,8,7};
  len=sizeof(HeapArray)/sizeof(int);
  HeapSort(HeapArray,len-1);
  PrintfArray(HeapArray,len);*/
  int n,i;
  cin>>n;
  for(i=1;i<=n;i++)
  {
     scanf("%d",OriginArray+i);
     OriginArray1[i]=OriginArray[i];
  }
  for(i=1;i<=n;i++)
  {
   scanf("%d",TargetArray+i);
  }
  
  if(InsertSort(OriginArray,n))
  {
    cout<<"Insertion Sort"<<endl;
    PrintfArray(OriginArray,n);
  }else if(HeapSort(OriginArray1,n))
  {
    cout<<"Heap Sort"<<endl;
    PrintfArray(OriginArray1,n);
  }
    system("pause");
  return 0;
}
