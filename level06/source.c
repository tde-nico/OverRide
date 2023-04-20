#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ptrace.h>


int	auth(char *s, unsigned int input)
{
	int	n;
	int	len;

	s[strcspn(s, "\n")] = 0;
	len = strnlen(s, 32);
	if ( len <= 5 )
		return (1);
	if ( ptrace(PTRACE_TRACEME, 0, 1, 0) == -1 )
	{
		puts("\x1B[32m.---------------------------.");
		puts("\x1B[31m| !! TAMPERING DETECTED !!	|");
		puts("\x1B[32m'---------------------------'");
		return (1);
	}
	n = (s[3] ^ 0x1337) + 0x5EEDED;
	for ( int i = 0; i < len; ++i )
	{
		if ( s[i] <= 31 )
			return 1;
		n += (n ^ s[i]) % 0x539;
	}
	return (input != n);
}

int	main(void)
{
	unsigned int	input;
	char			s[32];

	puts("***********************************");
	puts("*\t\tlevel06\t\t	*");
	puts("***********************************");
	printf("-> Enter Login: ");
	fgets(s, 32, stdin);
	puts("***********************************");
	puts("***** NEW ACCOUNT DETECTED ********");
	puts("***********************************");
	printf("-> Enter Serial: ");
	scanf("%u", &input);
	if ( auth(s, input) )
		return (1);
	puts("Authenticated!");
	system("/bin/sh");
	return (0);
}
