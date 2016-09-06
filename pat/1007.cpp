#include <cstdio>
int a[10001];
int main(){
  int k;
  scanf("%d", &k);
  for (int i = 0; i < k; i++){
    scanf("%d", &a[i]);
  }
  int sum = 0, start = 0, end = k - 1, temp = 0, tempi = 0, tempj = 0;
  for (int i = 0; i < k; i++){
    if (temp >= 0){
      temp += a[i];
      tempj = i;
    }
    else{
      temp = a[i];
      tempi = i;
      tempj = i;
    }
    if (temp > sum || (temp == 0 && end == k -1)){
      sum = temp;
      start = tempi;
      end = tempj;
    }
  }
  printf("%d %d %d\n", sum, a[start], a[end]);
  return 0;
}
