#include <string.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct s_info
{
    char	msg[140];
    char	name[40];
    int		size;
}	t_info;

void secret_backdoor()
{
	char	s[128];

	fgets(s, 128, stdin);
	system(s);
}

void	set_username(t_info *user)
{
	char	s[128];

	memset(s, 0, sizeof(s));
	puts(">: Enter your username");
	printf(">>: ");
	fgets(s, 128, stdin);
	for ( int i = 0; i <= 40 && s[i]; ++i )
		user->name[i] = s[i];
	printf(">: Welcome, %s", user->name);
}

void	set_msg(t_info *user)
{
	char	s[1024];

	memset(s, 0, sizeof(s));
	puts(">: Msg @Unix-Dude");
	printf(">>: ");
	fgets(s, 1024, stdin);
	strncpy(user->msg, s, user->size);
}

void	handle_msg(void)
{
	t_info	user;

	memset(user, 0, sizeof(user));
	user.size = 140;
	set_username(&user);
	set_msg(&user);
	puts(">: Msg sent!");
}

int	main(void)
{
	puts("--------------------------------------------\n"
		"|   ~Welcome to l33t-m$n ~    v1337        |\n"
		"--------------------------------------------");
	handle_msg();
	return (0);
}