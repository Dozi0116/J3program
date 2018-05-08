#include <stdio.h>


void to_pol(char f[100], char pol_f[100]);
char cal_from_pol(char pol_f[100]);

int my_priority(char c);

int c2i(char c);
char i2c(int i);

void push(char stack[100], int *sp, char c);
char pop(char stack[100], int *sp);


int main(void)
{
	char f[100];
	char pol_f[100];
	char dmy;

	printf("Input formula : ");
	scanf("%s%c", f, &dmy);	

	to_pol(f, pol_f);
	
	printf("Reverse poland : %s\n", pol_f);
	
	printf("Ans : %c\n", cal_from_pol(pol_f));

	return 0;
}				

void to_pol(char f[100], char pol_f[100])
{
	char stack[100];
	int sp = 0;
	int i;
	int pi = 0;
	char tmp;

	for ( i = 0; f[i] != '\0'; i++ ) {
		if ( sp != 0 ) {
			tmp = pop(stack, &sp);
			if ( my_priority( tmp ) >= my_priority( f[i] ) ) {
				pol_f[pi++] = tmp;
				
				while ( sp != 0 ) {
					tmp = pop(stack, &sp);
					if ( my_priority( tmp ) >= my_priority( f[i] ) ) {
						pol_f[pi++] = tmp;
					} else {
						push(stack, &sp, tmp);
						break;
					}
				}

			} else {
				push(stack, &sp, tmp);
			}
		}
		push(stack, &sp, f[i]);
	}

	while ( sp != 0 ) {
		pol_f[pi++] = pop(stack, &sp);
	}
	pol_f[pi] = '\0';
}

char cal_from_pol(char pol_f[100])
{
	char stack[100];
	int sp = 0;
	int i;
	char first, second;

	for ( i = 0; pol_f[i] != '\0'; i++) {
		if ( '9' >= pol_f[i] && pol_f[i] >= '1' ) {

			/* You can write program here! */
			
		} else {
			if (pol_f[i] == '+') {
				second = pop(stack, &sp);
				first = pop(stack, &sp);
				push(stack, &sp, i2c(c2i(first) + c2i(second)));
			} else if  (pol_f[i] == '-') {
				
				/* You can write program here! */

			} else if  (pol_f[i] == '*') {
				
				/* You can write program here! */

			} else { // if  (pol_f[i] == '/')
				
				/* You can write program here! */

			}
		}
	}

	return pop(stack, &sp);
}

int my_priority(char c)
{
	if ( '9' >= c && c >= '1' )  return 3;
	else if ( c == '*' || c == '/' ) return 2;
	else return 1;
}

int c2i(char c)
{
	return c - '0';
}

char i2c(int i)
{
	return '0' + i;
}

void push(char stack[100], int *sp, char c)
{
	stack[(*sp)++] = c;
}

char pop(char stack[100], int *sp)
{
	return stack[--*sp];
}