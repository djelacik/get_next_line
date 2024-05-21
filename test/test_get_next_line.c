#ifdef _WIN32
//Windows
#include <io.h>
#define open _open
#define write _write
#define read _read
#define close _close
#define STDIN_FILENO 0
#define STDOUT_FILENO 1

#define OPEN_FLAGS _O_BINARY | _O_RDONLY

#else
//Linux
#include <unistd.h>
#define OPEN_FLAGS O_RDONLY
#endif

#include <sys/types.h> 
#include <sys/stat.h> 
#include <fcntl.h>
#include <stdio.h>

#include "../get_next_line.h"
#include "test_get_next_line.h"


const char* t = "first line\n"
"second line\n"
"third line";

void read_console();

int main()
{

	set_up();

	ASSERT(test_empty_file(), "Empty file");
	ASSERT(test_one_line_file(), "One line file");
	ASSERT(test_two_lines_file(), "Two lines file");
	ASSERT(test_long_line_file(), "Long line file");

	tear_down();
	
	test_console();

	return 0;
}

void read_console()
{
	char c[BUFFER_SIZE];
	while (1) {
		int r = read(0, c, BUFFER_SIZE);
		// read() here read from stdin charachter by character
		// the buf[0] contains the character got by read()
		//write(STDOUT_FILENO, c, 1);
		printf("read:%d\n", r);
		if (r == 0)
			break;
	}
}

void set_up()
{
	create_file(EMPTY_FILE_NAME, EMPTY_FILE_CONTENT);
	create_file(ONELINE_FILE_NAME, ONELINE_FILE_CONTENT);
	create_file(TWOLINES_FILE_NAME, TWOLINES_FILE_CONTENT);
	create_file(LONG_LINE_FILE_NAME, LONG_LINE_FILE_CONTENT);
}

void tear_down()
{
	delte_file(EMPTY_FILE_NAME);
	delte_file(ONELINE_FILE_NAME);
	delte_file(TWOLINES_FILE_NAME);
	delte_file(LONG_LINE_FILE_NAME);
}

void create_file(const char* file_name, const char* file_content)
{
	FILE* fPtr  = fopen(file_name, "wb");
	if (fPtr == NULL)
	{
		printf("Unable to create file [%s].\n",file_name);
	}
	else
	{
		fputs(file_content, fPtr);
		fclose(fPtr);
	}
}

void delte_file(const char* file_name)
{
	remove(file_name);
}

int test_empty_file()
{
	int fd = open(EMPTY_FILE_NAME, OPEN_FLAGS);
	char* ret = get_next_line(fd);
	printf("%s", ret);
	close(fd);
	if (ret)
		return 0;
	return 1;
}


int test_one_line_file()
{
	int fd = open(ONELINE_FILE_NAME, OPEN_FLAGS);
	char* ret = get_next_line(fd);
	printf("%s", ret);
	ret = get_next_line(fd);
	if(ret)
		printf("|%s|", ret);
	else
		printf("{NULL}\n");
	close(fd);
	return 1;
}

int test_two_lines_file()
{
	int fd = open(TWOLINES_FILE_NAME, OPEN_FLAGS);
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	close(fd);
	return 1;
}

int test_long_line_file()
{
	int fd = open(LONG_LINE_FILE_NAME, OPEN_FLAGS);
	printf("%s", get_next_line(fd));
	close(fd);
	return 1;
}

int test_console()
{
	char* c;
	while ( (c = get_next_line(STDIN_FILENO)) )
	{
		printf("Console:%s", c);
	}
	return 0;
}
