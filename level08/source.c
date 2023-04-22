#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

void	log_wrapper(FILE *f, char *msg, char *fname)
{
	char	log[256];

	strcpy(log, msg);
	snprintf(log, strlen(fname), fname);
	log[strcspn(log, "\n")] = 0;
	fprintf(f, "LOG: %s\n", log);
}

int	main(int argc, char **argv)
{
	FILE	*log;
	FILE	*file;
	int		fd;
	char	buf;
	char	dest[104];

	if ( argc != 2 )
		printf("Usage: %s filename\n", *argv);
	log = fopen("./backups/.log", "w");
	if ( !log )
	{
		printf("ERROR: Failed to open %s\n", "./backups/.log");
		exit(1);
	}
	log_wrapper(log, "Starting back up: ", argv[1]);
	file = fopen(argv[1], "r");
	if ( !file )
	{
		printf("ERROR: Failed to open %s\n", argv[1]);
		exit(1);
	}
	strcpy(dest, "./backups/");
	strncat(dest, argv[1], strlen(argv[1]));
	fd = open(dest, 0xc1, 0x1b0);
	if ( fd < 0 )
	{
		printf("ERROR: Failed to open %s%s\n", "./backups/", argv[1]);
		exit(1);
	}
	while ( (buf = fgetc(file)) > 0 )
		write(fd, &buf, 1);
	log_wrapper(log, "Finished back up ", argv[1]);
	fclose(file);
	close(fd);
	return (0);
}
