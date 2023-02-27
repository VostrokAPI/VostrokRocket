#ifndef VS_FILE_H
#define VS_FILE_H

#include <stddef.h>
#include <stdint.h>
#include <sys/stat.h>

/////////////////////////////
//
//		TYPEDEF
//
/////////////////////////////

typedef struct vs_file_t vs_file_t;

/////////////////////////////
//
//		STRUCT
//
/////////////////////////////

struct vs_file_t
{
	union {
		uint64_t	*u64ptr;
		uint32_t	*u32ptr;
		uint16_t	*u16ptr;
		uint8_t		*u8ptr;
		long		*i64ptr;
		int			*i32ptr;
		short		*i16ptr;
		char		*i8ptr;
		void		*ptr;
	};
	size_t			size;
	int				fd;
};

/*********************************************************************
*
* @brief   This function read a files
*
* @param    const char *pathname
* @param	int flags (O_APPEND | O_ASYNC | O_CLOEXEC | O_CREAT...)
* @param	Permissions (S_IRUSR | S_IWUSR | S_XUSR...)
*
* @return  0 if success otherwise is an error 
*
*********************************************************************/
int			vs_read_file(vs_file_t *vs, const char *pathname, int flags, mode_t mode);

/*********************************************************************
*
* @brief    This function open file descriptor
*
* @param    vs_file_t	*pointer
* @param	const char	*pathname
* @param	int flags (O_APPEND | O_ASYNC | O_CLOEXEC | O_CREAT...)
* @param	Permissions (S_IRUSR | S_IWUSR | S_XUSR...)
*
* @return  0 if success otherwise considered as an error 
*
*********************************************************************/
int			vs_open_file(vs_file_t *vs, const char *pathname, int flags, mode_t mode);

/*********************************************************************
*
* @brief    This function close file descriptor
*
* @param    vs_file_t	*pointer
*
* @return  0 if success otherwise considered as an error 
*
*********************************************************************/
int			vs_close_file(vs_file_t *vs);

/*********************************************************************
*
* @brief    This function free buf in vs_file_t structure
*
* @param    vs_file_t	*pointer
*
* @return   nothing
*
*********************************************************************/
void		vs_free_file_buf(vs_file_t *vs);

#endif
