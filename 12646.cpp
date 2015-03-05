#include <iostream>
#include <stdio.h>
using namespace std;

int main() {
 int a, b, c;
 while(scanf("%d%d%d", &a, &b, &c)==3) {
  if(a!=b && a!=c) printf("A");
  else if(b!=a && b!=c) printf("B");
  else if(c!=a && c!=b) printf("C");
  else printf("*");
  printf("\n");
 }
 return 0;
}
