#include "vs_file.h"

#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int	vs_read_file(vs_file_t *vs, const char *pathname, int flags, mode_t mode)
{
	if (!vs) return (1);

	int	status = 0;

	vs->fd = open(pathname, flags, mode);

	if (vs->fd < 0) return (1);
	
	status = lseek(vs->fd, 0, SEEK_END);

	if (status < 0) {
		close(vs->fd);
		return (1);
	}

	if (lseek(vs->fd, 0, SEEK_SET) < 0) return (1);

	vs->size = (size_t)status;

	vs->ptr = malloc(sizeof(char) * vs->size);
	if (!vs->ptr) {
		close(vs->fd);
		return (1);
	}

	if (read(vs->fd, vs->ptr, vs->size) != status) {
		free(vs->ptr);
		close(vs->fd);
		return (1);
	}

	close(vs->fd);

	return (0);
}
