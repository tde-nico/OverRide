#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/prctl.h>
#include <sys/ptrace.h>
#include <sys/wait.h>
#include <string.h>

int	main(void)
{
	int status;
	char s[32];
	pid_t pid;

	pid = fork();
	memset(s, 0, sizeof(s));
	status = 0;
	if ( pid )
	{
		do
		{
			wait(&status);
			if (!(status & 0x7F))
			{
				puts("child is exiting...");
				return (0);
			}
		}
		while ( ptrace(PTRACE_PEEKUSER, pid, 44, 0) != 11 );
		puts("no exec() for you");
		kill(pid, 9);
	}
	else
	{
		prctl(1, 1);
		ptrace(PTRACE_TRACEME, 0, 0, 0);
		puts("Give me some shellcode, k");
		gets(s);
	}
	return (0);
}
