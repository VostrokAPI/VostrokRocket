#include "vs_file.h"
#include "vs_rocket.h"
#include <fcntl.h>
#include <stdio.h>

int main(int ac, char **av)
{
	if (ac != 2) return (1);

	vs_file_t	f;

	if (vs_read_file(&f, av[1], O_RDONLY, S_IRUSR))
		return (fprintf(stderr, "[-] Error error during reading files !\n"));

	printf("%s\n", f.i8ptr);

	vs_free_file_buf(&f);

	return (0);
}
