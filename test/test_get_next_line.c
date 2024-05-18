#include "../get_next_line.h"
#include <stdio.h>

int	test_negative_fd()
{
	char	*ret;
	ret = get_next_line(-1);
	return ret == NULL;
}

int main() {
    if (test_negative_fd()) {
        printf("Test 1 passed\n");
    } else {
        printf("Test 1 failed\n");
    }
    return 0;
}