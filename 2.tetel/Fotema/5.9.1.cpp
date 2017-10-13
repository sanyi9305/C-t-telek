#include <stdio.h>
#include <string>
using namespace std;
int main()
{
  char x = 'a';
  char* a = &x;
  int b[10] = {0,1,2,3,4,5,6,7,8,9};
  int &c = *b;
  string d[] = {"asd", "sdf", "dfg"};
  string *e = d;
  char* f = a;
  const int g = 1;
  const int* h = &g;
  int i = 1;
  const int * j = &i;
  return 0;
}
