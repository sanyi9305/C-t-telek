#include <stdio.h>
#include <stdlib.h>
#define false 0
#define true !false

struct pont {float x; float y;};
struct teglalap{struct pont  balLent; struct pont jobbFent;};
int benneVan(struct pont a, struct teglalap t){
    if(a.x > t.balLent.x && a.x < t.jobbFent.x && a.y > t.balLent.x && a.y < t.jobbFent.y)
       return true;
    return false;
}

int main(int argc, char *argv[])
{ 
  struct pont b,u,v;
  struct teglalap q;
  b.x = 3;
  b.y = 2;
  u.x = 1;
  u.y = 1;
  v.x = 4;
  v.y = 3;
  q.balLent = u;
  q.jobbFent = v;
  printf("A pont ");
  if(benneVan(b,q))
    printf("benne van");
  else
  printf("nincs benne");
  printf(" teglalapban.\n");
  
  system("PAUSE");	
  return 0;
}
