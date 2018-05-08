#include <stdio.h>


void to_pol(char f[100], char pol_f[100]);
int cal_from_pol(char pol_f[100]);

int my_priority(char c);

int c2i(char c);
char i2c(int i);

void push(char stack[100], int *sp, char c);
char pop(char stack[100], int *sp);

void push_i(int stack[100], int *sp, int i);
int pop_i(int stack[100], int *sp);


int main(void)
{
	char f[100];
	char pol_f[100];
	char dmy;

	printf("Input formula : ");
	scanf("%s%c", f, &dmy);

	to_pol(f, pol_f);

	printf("Reverse poland : %s\n", pol_f);

	printf("Ans : %d\n", cal_from_pol(pol_f));

	return 0;
}

void to_pol(char f[100], char pol_f[100])
{
	char stack[100];
	int sp = 0; //次にのせるべきstackのインデックス(一番上を見るには-1する必要がある)
	int i;
	int pi = 0;
	char tmp = '\0';

	int pri;

	for ( i = 0; f[i] != '\0'; i++ ) {
		printf("\n%c\n\n", f[i]);
		if('1' <= f[i] && f[i] <= '9'){
			printf("数字を検出しました。そのまま出力します。\n");
			while('0' <= f[i] && f[i] <= '9') pol_f[pi++] = f[i++];
			i--;
			pol_f[pi++] = ' ';
		}else{
			printf("記号を検出しました。優先度を判定します。\n");
			printf("この記号の優先度は%dです。", my_priority(f[i]));

			if(f[i] == '('){
				printf("左括弧が検出されました。特殊スタックをします。\n");
				push(stack, &sp, f[i]);
				continue;
			}

			if(f[i] == ')'){
				printf("右括弧が検出されました。左括弧が検出されるまで特殊出力をします。\n");
				do{
					if(sp != 0) tmp = pop(stack, &sp);
					else break;

					if(tmp != '('){
						pol_f[pi++] = tmp;
						pol_f[pi++] = ' ';
					}
				}while(tmp != '(');
				continue;
			}

			//通常記号
			while(sp != 0){
				pri = my_priority(stack[sp-1]);
				if(pri >= my_priority(f[i])){ // スタック内の優先度以下の時
					printf("スタックの優先度以下なので、スタックを出力します。\n");
					pol_f[pi++] = pop(stack, &sp);
					pol_f[pi++] = ' ';
					printf("繰り返し、スタックの中を調査します。\n");
				}else{
					printf("スタックの優先度より上なのでスタックに保存します。\n");
					break;
				}
			}
			if(sp == 0) printf("スタックが空なので、スタックに保存します。\n");
			push(stack, &sp, f[i]);
		}

	}

	printf("文字列を探索し終えました。残った記号を出力して終了します。\n");
	while ( sp != 0 ) {
		pol_f[pi++] = pop(stack, &sp);
		pol_f[pi++] = ' ';
	}
	pol_f[pi] = '\0';
}

int cal_from_pol(char pol_f[100])
{
	int stack[100]; //intに変更
	int sp = 0;
	int i;
	int first, second;
	int num;

	for(i = 0; pol_f[i] != '\0';i++){
		printf("%c/%d\n", pol_f[i], pol_f[i]);
	}

	for ( i = 0; pol_f[i] != '\0'; i++) {
		printf("pol_f[%d] = %c/%d\n", i, pol_f[i], pol_f[i]);
		if ( '9' >= pol_f[i] && pol_f[i] >= '0' ) {
			num = 0;
			while('9' >= pol_f[i] && pol_f[i] >= '0'){
				num *= 10;
				num += c2i(pol_f[i++]);
			}
			push_i(stack, &sp, num);
		} else {
			if (pol_f[i] == '+') {
				second = pop_i(stack, &sp);
				first = pop_i(stack, &sp);
				push_i(stack, &sp, first + second);

			} else if  (pol_f[i] == '-') {
				second = pop_i(stack, &sp);
				first = pop_i(stack, &sp);
				push_i(stack, &sp, first - second);

			} else if  (pol_f[i] == '*') {
				second = pop_i(stack, &sp);
				first = pop_i(stack, &sp);
				push_i(stack, &sp, first * second);

			} else { // if  (pol_f[i] == '/')
				second = pop_i(stack, &sp);
				first = pop_i(stack, &sp);
				push_i(stack, &sp, first / second);

			}
			i++;
		}
	}

	return pop_i(stack, &sp);
}

int my_priority(char c)
{
	if (c == '(' || c == ')' ) return 0;
	else if ( c == '*' || c == '/' ) return 2;
	else return 1; //c == + || c == -
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
	printf("push!, %c\n", c);
	stack[(*sp)++] = c;
}

void push_i(int stack[100], int *sp, int i)
{
	printf("push!, %d\n", i);
	stack[(*sp)++] = i;
}

char pop(char stack[100], int *sp)
{
	printf("pop!, %c\n", stack[*sp-1]);
	return stack[--*sp];
}

int pop_i(int stack[100], int *sp)
{
	printf("pop! %d\n", stack[*sp-1]);
	return stack[--*sp];
}
