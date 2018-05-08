#include <stdio.h>
void shift (char a[])
{
  int n = 0;
  while (a[n] != '\0')
  {
    a[n] = a[n + 1];
    n++;
  }
}

int string_length (char a[])
{
  if (a[0] != '\0')
  {
    shift (a);
    return string_length (a) + 1;
  }else
  return 0;
}

int main ()
{
  char a[] = "abcdef";
  printf ("%d\n", string_length (a));
  printf ("%s\n", a);

  return 0;
}
