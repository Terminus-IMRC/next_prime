#include <stdio.h>
#include <stdlib.h>
#include <gmp.h>

int main(int argc, char *argv[])
{
	mpz_t n;
	char *s;

	if(argc!=2){
		fprintf(stderr, "%s:%d: error: invalid the number of the argument: %d\n", __FILE__, __LINE__, argc);
		exit(EXIT_FAILURE);
	}

	if(mpz_init_set_str(n, argv[1], 10)==-1){
		fprintf(stderr, "%s:%d: error: input string may be invalid: %s\n", __FILE__, __LINE__, argv[1]);
		mpz_clear(n);
		exit(EXIT_FAILURE);
	}
	mpz_nextprime(n, n);
	s=mpz_get_str(NULL, 10, n);
	if(puts(s)==EOF){
		fprintf(stderr, "%s:%d: error: puts(3) returned EOF with string: %s\n", __FILE__, __LINE__, s);
		mpz_clear(n);
		exit(EXIT_FAILURE);
	}
	free(s);
	mpz_clear(n);

	return 0;
}
