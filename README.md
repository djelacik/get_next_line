# Get Next Line

Write a function that returns a line read from a file descriptor.

This was my second project at Hive Helsinki. The task was quite straightforward, so the implementation was simple. Despite the simplicity, memory management was challenging, especially ensuring there are no leaks if the file descriptor returns an error midway through the program.

The bonus part required managing multiple file descriptors with a single static variable. The implementation was straightforward as I assumed there could be a maximum number of open file descriptors at once, so I used a static array of integers.

## Installation

Clone this repository and use the Makefile to compile the project:
```
Git clone https://github.com/djelacik/get_next_line
```

## Usage

The `get_next_line` function can be called by providing an open file descriptor. The function returns the read line with '\n' included or NULL if there are no more lines to read or an error occurs.

Example usage:
```c
char *get_next_line(int fd);

int fd = open("example.txt", O_RDONLY);
char *line;

while ((line = get_next_line(fd)) != NULL) {
    printf("%s", line);
    free(line);
}
close(fd);
```

## Contributing

Don't copy the code as it is. Pdf of instructions is provided in the repo, so you can try writing your own code.

## Test your function

If you make it as far as testing, you can download a tester here with instructions:
```
Git Clone https://github.com/xicodomingues/francinette
```
You can run the tester with following command:
`francinette`

Or for more strict tests which tests memory leaks:
`francinette -strict`
## Norminette

42 network schools need to follow the Norm, which provides rules for writing your code. The Norm will be provided in the repo. If you wish to write code like a real 42 student, you can download Norminette on your own computer:
```
https://github.com/42School/norminette
```
You can run Norminette with following command:
`Norminette`

## License

This project is licensed under the MIT License