#include<iostream>
#include<string>
#include<climits>
using namespace std;
int main()
{
  int len, l, i, max = INT_MIN;
  string str;
  //cin >> str;
  getline(cin, str, '\n');
  len = str.size();
  for (i = 0; i < len; ++i)
  {
    for (l = 0; l + i < len&&i - l >= 0; ++l)
    {
      if (str[i - l] != str[i + l])
        break;
      if (max < l * 2+1)
        max = l * 2+1;
    }
    for (l =0; l + i < len&&i - l >= 0; ++l)
    {
      if (str[i - l] != str[i + 1 + l])
        break;
      if (max <  l * 2 + 2)
        max =  l* 2 + 2;
    }
  }
  cout << max << endl;
  //system("pause");
  return 0;
}
