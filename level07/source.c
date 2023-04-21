#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void clear_stdin(void)
{
	char	chr;

	do
		chr = getchar();
	while ( chr != 10 && chr != -1 );
}

unsigned int	get_unum(void)
{
	unsigned int	u;

	u = 0;
	fflush(stdout);
	scanf("%u", &u);
	clear_stdin();
	return (u);
}

int	read_number(char *buf)
{
	unsigned int	n;

	printf(" Index: ");
	n = get_unum();
	printf(" Number at data[%u] is %u\n", n, buf[n]);
	return (0);
}

int	store_number(char *buf)
{
	unsigned int	n;
	unsigned int	m;

	printf(" Number: ");
	n = get_unum();
	printf(" Index: ");
	m = get_unum();
	if ( !(m % 3) || n >> 24 == 0xb7 )
	{
		puts(" *** ERROR! ***");
		puts("   This index is reserved for wil!");
		puts(" *** ERROR! ***");
		return (1);
	}
	buf[m] = n;
	return (0);
}

int	main(int argc, char **argv, char **envp)
{
	int		buf[400];
	char	s[20];
	int		n;

	n = 0;
	memset(buf, 0, sizeof(buf));
	while ( *argv )
		memset(*argv, 0, strlen((*argv)++));
	while ( *envp )
		memset(*envp, 0, strlen((*envp)++));
	puts("----------------------------------------------------\n"
		"  Welcome to wil's crappy number storage service!   \n"
		"----------------------------------------------------\n"
		" Commands:                                          \n"
		"    store - store a number into the data storage    \n"
		"    read  - read a number from the data storage     \n"
		"    quit  - exit the program                        \n"
		"----------------------------------------------------\n"
		"   wil has reserved some storage :>                 \n"
		"----------------------------------------------------\n");
	
	while ( 1 )
	{
		printf("Input command: ");
		fgets(s, 20, stdin);
		s[strlen(s) - 1] = 0;
		if ( !strncmp(s, "store", 5) )
			n = store_number(buf);
		else if ( !strncmp(s, "read", 4) )
			n = read_number(buf);
		else if ( !strncmp(s, "quit", 4) )
			return (0);
		if ( n )
			printf(" Failed to do %s command\n", s);
		else
			printf(" Completed %s command successfully\n", s);
	}
}
