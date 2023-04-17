#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void	decrypt(char key)
{
	int		len;
	char	str[17];

	strcpy(str, "Q}|u`sfg~sf{}|a3");
	len = strlen(str);
	for ( int i = 0; i < len; ++i )
		str[i] ^= key;
	if ( !strcmp(str, "Congratulations!") )
		system("/bin/sh");
	else
		puts("\nInvalid Password");
}

void	test(int passwd, int test_value)
{
	int	r;

	switch ( test_value - passwd )
	{
		case 1:
		case 2:
		case 3:
		case 4:
		case 5:
		case 6:
		case 7:
		case 8:
		case 9:
		case 16:
		case 17:
		case 18:
		case 19:
		case 20:
		case 21:
			decrypt(test_value - passwd);
			break;
		default:
			r = rand();
			decrypt(r);
			break;
	}
}

int	main(void)
{
	int	passwd;

	srand(time(0));
	puts("***********************************");
	puts("*\t\tlevel03\t\t**");
	puts("***********************************");
	printf("Password:");
	scanf("%d", &passwd);
	test(passwd, 322424845);
	return (0);
}
