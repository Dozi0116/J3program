#include <stdio.h>

void my_toupper(char str[100]);

int main(void)
{
	char str[100];
	char dmy;

	printf("Input word with a small letter: ");
	scanf("%s%c", str, &dmy);

	my_toupper(str);
	printf("%s\n", str);

	return 0;
}

void my_toupper(char str[100])
{
	int i;
	for(i = 0;str[i] != '\0';i++) str[i] = str[i] - 'a' + 'A';
}
