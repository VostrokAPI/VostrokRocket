#include "greatest.h"
#include "vs_file.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

TEST	test_file1(void)
{
	vs_file_t	f;

	system("echo -n 'hello' > toto.txt");

	ASSERT_EQ(vs_read_file(&f, "toto.txt", O_RDONLY, S_IRUSR), 0);
	ASSERT_STR_EQ(f.i8ptr, "hello");
	remove("toto.txt");
	PASS();
}

SUITE(file_test)
{
	RUN_TEST(test_file1);
}

GREATEST_MAIN_DEFS();

int main(int argc, char **argv)
{
	GREATEST_MAIN_BEGIN();

	RUN_SUITE(file_test);

	GREATEST_MAIN_END(); 
	return (0);
}
