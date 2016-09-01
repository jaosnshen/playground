#include<iostream>
#include<cstring>
#include<string>
using namespace std;
int main()
{
  int a, b,i,c,len,time;
  char s[10];
  while (scanf("%d%d", &a, &b) == 2){
    memset(s, '\0', sizeof(s));
    c = a + b;
  /*  time = 0;
    sprintf_s(s, "%d", c);
    len = strlen(s);
    len %= 3;
    for (i = 0; i < len; i++)
      cout << s[i]<<",";
    for (i = len; i < strlen(s); i++)
    {
      cout << s[i];
      if (time % 3 == 0&i!=strlen(s)-1)
      {
        cout << ",";
        time=0;

      }
      time++;
    }*/
    if (c < 0)
    {
      c = -c;
      cout << "-";
    }
    if (c >= 1000000)
      printf("%d,%03d,%03d\n", c / 1000000, (c / 1000) % 1000, c % 1000);
    else if (c >= 1000)
      printf("%d,%03d\n", c / 1000, c % 1000);
    else
      printf("%d\n", c);
   
  }
 return 0;
}