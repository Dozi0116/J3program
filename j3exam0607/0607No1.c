void print_list(CELL *root)
{
	CELL *p;

	/* no2 */
	for(p = root;p != NULL;p = p -> next){
		printf("%d", p -> mask);
	}
	printf("\n");

	for (p = root; p != NULL; p = p->next) {
		/* no1 */
		if(p -> mask == 0){
			printf("%c", p->ch);
		}else{
			printf("-");
		}

	}
	printf("\n");
}
