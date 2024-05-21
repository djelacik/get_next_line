NAME = test_get_next_line.out

SOURCES = test_get_next_line.c
# TODO: add output directory https://stackoverflow.com/questions/75501339/how-do-i-create-object-files-into-a-different-directory-than-makefiles-one
OBJECTS = $(SOURCES:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g 

test: parent $(NAME)

parent:
	$(MAKE) -C .. all

$(NAME): $(OBJECTS) ../libgetnextline.a
	$(CC) $(CFLAGS) -o $@ $^ -lgetnextline -L .. 

%.o: %.c test_get_next_line.h
	$(CC) -c $(CFLAGS) $<

clean:
	$(MAKE) -C .. $@
	rm -f $(OBJECTS) \
    rm -f $(NAME)


print:
	echo @make -C .. $@
	echo $(MAKE) -C .. $@
	echo $(MAKE) -C .. all
	$(MAKE) -C .. all

#%:
#	$(MAKE) -C .. $@
