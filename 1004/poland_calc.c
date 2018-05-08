#include <stdio.h>
#include <time.h>


void to_pol(char f[100], char pol_f[100]);
char cal_from_pol(char pol_f[100]);

int my_priority(char c);

int c2i(char c);
char i2c(int i);

void push_c(char stack[100], int *sp, char c);
char pop_c(char stack[100], int *sp);
void push_i(int stack[100], int *sp, int i);
int pop_i(int stack[100], int *sp);


int main(void)
{
	char f[100] = "((((9*1)-1)-1)-1)-1-1-1-1-1-1";
	char pol_f[100];
	//char dmy;

	//clock_t start, end;

	//printf("Input formula : ");
	//scanf("%s%c", f, &dmy);

	//start = clock();
	to_pol(f, pol_f);
	//end = clock();

	//printf("Reverse poland : %s\n", pol_f);

	//printf("Ans : %d\n", cal_from_pol(pol_f));

	//printf("%fsec!\n", (double)(end - start) / CLOCKS_PER_SEC);

	return 0;
}

void to_pol(char f[100], char pol_f[100])
{
	char stack[100];
	int sp = 0;
	int i = 0;
	int pi = 0;
	char tmp;

	for ( i = 0; f[i] != '\0' && f[i] != ')'; i++ ) {

		if(f[i] == ' ') continue;

		if(f[i] == '(') {
			to_pol(&f[++i], &pol_f[pi]);
			for(;f[i] != ')';i++);
			f[i] = ' ';
			for(;pol_f[pi] != '\0';pi++);
			continue;
		}

		if ( sp != 0 ) {
			tmp = pop_c(stack, &sp);
			if ( my_priority( tmp ) >= my_priority( f[i] ) ) {
				pol_f[pi++] = tmp;

				while ( sp != 0 ) {
					tmp = pop_c(stack, &sp);
					if ( my_priority( tmp ) >= my_priority( f[i] ) ) {
						pol_f[pi++] = tmp;
					} else {
						push_c(stack, &sp, tmp);
						break;
					}
				}

			} else {
				push_c(stack, &sp, tmp);
			}
		}
		push_c(stack, &sp, f[i]);
	}

	while ( sp != 0 ) {
		pol_f[pi++] = pop_c(stack, &sp);
	}
	pol_f[pi] = '\0';
}

char cal_from_pol(char pol_f[100])
{
	int stack[100];
	int sp = 0;
	int i;
	int first, second;

	for ( i = 0; pol_f[i] != '\0'; i++) {
		if ( '9' >= pol_f[i] && pol_f[i] >= '1' ) {
			push_i(stack, &sp, c2i(pol_f[i]));
		} else {
			second = pop_i(stack, &sp);
			first = pop_i(stack, &sp);
			if (pol_f[i] == '+') {
				push_i(stack, &sp, first + second);
			} else if  (pol_f[i] == '-') {
				push_i(stack, &sp, first - second);
			} else if  (pol_f[i] == '*') {
				push_i(stack, &sp, first * second);
			} else {
				push_i(stack, &sp, first / second);
			}
		}
	}

	return pop_i(stack, &sp);
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

void push_c(char stack[100], int *sp, char c)
{
	stack[(*sp)++] = c;
}

void push_i(int stack[100], int *sp, int i)
{
	stack[(*sp)++] = i;
}

char pop_c(char stack[100], int *sp)
{
	return stack[--*sp];
}

int pop_i(int stack[100], int *sp)
{
	return stack[--*sp];
}
