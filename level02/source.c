#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	FILE *file;
	char content[41];
	char s[100];
	char s2[100];
	size_t readed;

	memset(content, 0, 0x28);
	memset(s, 0, sizeof(s));
	memset(s2, 0, sizeof(s2));
	content[40] = 0;
	readed = 0;
	file = fopen("/home/users/level03/.pass", "r");
	if ( !file )
	{
		fwrite("ERROR: failed to open password file\n", 1, 0x24, stderr);
		exit(1);
	}
	readed = fread(content, 1, 0x29, file);
	content[strcspn(content, "\n")] = 0;
	if ( readed != 41 )
	{
		fwrite("ERROR: failed to read password file\n", 1, 0x24, stderr);
		fwrite("ERROR: failed to read password file\n", 1, 0x24, stderr);
		exit(1);
	}
	fclose(file);
	puts("===== [ Secure Access System v1.0 ] =====");
	puts("/***************************************\\");
	puts("| You must login to access this system. |");
	puts("\\**************************************/");
	printf("--[ Username: ");
	fgets(s, 100, stdin);
	s[strcspn(s, "\n")] = 0;
	printf("--[ Password: ");
	fgets(s2, 100, stdin);
	s2[strcspn(s2, "\n")] = 0;
	puts("*****************************************");
	if ( strncmp(content, s2, 0x29) )
	{
		printf(s);
		puts(" does not have access!");
		exit(1);
	}
	printf("Greetings, %s!\n", s);
	system("/bin/sh");
	return (0);
}
