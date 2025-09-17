# gnl

**gnl** is a C library that provides the `get_next_line` function, enabling efficient and convenient reading of lines from file descriptors. This function is particularly useful for handling input in a line-by-line manner, such as reading from files or standard input.

## Features

- **Line Reading**: Retrieve lines from a file descriptor one at a time.
- **Buffer Management**: Efficiently manages internal buffers to handle various line lengths and input sources.
- **Error Handling**: Gracefully handles errors and end-of-file conditions.

## Installation

To incorporate the `get_next_line` function into your project, follow these steps:

1. **Clone the Repository**:
    ```sh
    git clone https://github.com/Pradene/gnl.git
    ```

2. **Include the Source Files**:

    Add the following files to your project:
    
    get_next_line.c
    get_next_line_utils.c
    get_next_line.h

3. **Compile Your Project**:

    Ensure that your build process includes the get_next_line source files. For example, if you're using gcc, you might compile your project as follows:

    ```sh
    gcc -Wall -Wextra -Werror -o your_program your_program.c get_next_line.c
    ```

## Usage

Here's a simple example demonstrating how to use the get_next_line function:

```C
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main(void) {
    int fd = open("example.txt", O_RDONLY);
    if (fd == -1) {
        perror("Error opening file");
        return 1;
    }

    char *line;
    while ((line = get_next_line(fd)) != NULL) {
        printf("%s", line);
        free(line);
    }

    close(fd);
    return 0;
}
```
