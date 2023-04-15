#include <stdio.h>
#include <string.h>

char	a_user_name[100];

int	verify_user_name(void)
{
	puts("verifying username....\n");
	return (strncmp(a_user_name, "dat_wil", 7) != 0);
}

int	verify_user_pass(char *pass)
{
  return (strncmp(pass, "admin", 5) != 0);
}

int	main(void)
{
	char s[16];

	memset(s, 0, 16);
	puts("********* ADMIN LOGIN PROMPT *********");
	printf("Enter Username: ");
	fgets(a_user_name, 256, stdin);
	if (verify_user_name())
	{
		puts("nope, incorrect username...\n");
		return (1);
	}
	puts("Enter Password: ");
	fgets(s, 100, stdin);
	if (verify_user_pass(s))
		return (0);
	puts("nope, incorrect password...\n");
	return (1);
}
