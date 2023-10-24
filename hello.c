#include <stdio.h>
#include <string.h>

int main(void) {
  // int n = 50;
  // int *p = &n;

  // printf("%i\n", n);
  // printf("%p\n", p);

  char *s = "Hi!";

  printf("%s\n", s);
  
  printf("%p\n", &s[0]);
  printf("%p\n", &s[1]);
  printf("%p\n", &s[2]);
  printf("%p\n", &s[3]);

  printf("%c\n", *(s + 0));
  printf("%c\n", *(s + 1));
  printf("%c\n", *(s + 2));
  printf("%c\n", *(s + 3));
}