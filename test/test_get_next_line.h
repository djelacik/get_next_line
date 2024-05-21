#ifndef _TEST_GET_NEXT_LINE_H_
#define _TEST_GET_NEXT_LINE_H_

#define ASSERT(f, t) if(!f) {printf(t" test failed\n");} else {printf(t" test passed\n");}

#endif


#define EMPTY_FILE_NAME "empty.txt"
#define EMPTY_FILE_CONTENT ""

#define ONELINE_FILE_NAME "one_line.txt"
#define ONELINE_FILE_CONTENT "as\n"

#define TWOLINES_FILE_NAME "two_lines.txt"
#define TWOLINES_FILE_CONTENT "qwer\nasd"

#define LONG_LINE_FILE_NAME "long_line.txt"
#define LONG_LINE_FILE_CONTENT "1234567890123456789a123456789b\n"

void set_up();
void tear_down();

void create_file(const char *file_name, const char *file_content);
void delte_file(const char* file_name);

int test_empty_file();
int test_one_line_file();
int test_two_lines_file();
int test_long_line_file();
int test_console();
