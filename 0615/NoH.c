#include <stdio.h>
#include <unistd.h>

int string_length (char a[])
{
  if(a[0] != '\0') return string_length(++a) + 1;
  else return 0;
}

int main ()
{
  char a[] = "Dozi";
  printf ("%d\n", string_length (a));
  printf ("%s\n", a);

  return 0;
}
