
# Libft

*This project has been created as part of the 42 curriculum by mazorin*.

## Description

Libft is the first project of the 42 curriculum. The goal is to build a static C library (`libft.a`) that re-implements some standard C functions and adds extra utilities for string manipulation, memory handling and linked lists, to be reused in future projects.

The project teaches how the standard C library works internally by re-implementing it. Along the way, it covers pointers and pointer arithmetic, memory handling, string manipulation, dynamic memory allocation, file descriptor output and linked lists.

## Library content

The library is organized in three parts:

### Part 1 - Libc functions

Re-implementation of common libc functions for working with characters, strings and memory. They keep the same prototypes and behavior as the originals, prefixed with `ft_`.

**Character checking and conversion**
- `ft_isalpha`: Checks for an alphabetic character.
- `ft_isdigit`: Checks for a decimal digit.
- `ft_isalnum`: Checks for an alphanumeric character.
- `ft_isascii`: Checks for an ASCII character (0-127).
- `ft_isprint`: Checks for a printable character.
- `ft_toupper`: Converts a lowercase letter to uppercase.
- `ft_tolower`: Converts an uppercase letter to lowercase.
- `ft_atoi`: Converts a string to an integer.

**Memory manipulation**
- `ft_memset`: Fills memory with a constant byte.
- `ft_bzero`: Zeroes a block of memory.
- `ft_memcpy`: Copies memory (areas must not overlap).
- `ft_memmove`: Copies memory (areas may overlap).
- `ft_memchr`: Finds a byte in a memory block.
- `ft_memcmp`: Compares two memory blocks.
- `ft_calloc`: Allocates zero-initialized memory using `malloc`.

**String manipulation**
- `ft_strlen`: Returns the length of a string.
- `ft_strlcpy`: Size-bounded string copy.
- `ft_strlcat`: Size-bounded string concatenation.
- `ft_strchr`: Finds the first occurrence of a character in a string.
- `ft_strrchr`: Finds the last occurrence of a character in a string.
- `ft_strncmp`: Compares two strings up to n characters.
- `ft_strnstr`: Finds a substring within a length-limited string.
- `ft_strdup`: Duplicates a string using `malloc`.

### Part 2 - Additional functions

Utilities that are not in libc, or that are in a different form:
- `ft_substr`: Returns a substring of a string.
- `ft_strjoin`: Concatenates two strings into a new one.
- `ft_strtrim`: Trims a set of characters from both the start and the end of a string.
- `ft_split`: Splits a string into an array of strings using a delimiter.
- `ft_itoa`: Converts an integer to a string.
- `ft_strmapi`: Applies a function to each character, building a new string.
- `ft_striteri`: Applies a function to each character, in place.
- `ft_putchar_fd`: Writes a character to a file descriptor.
- `ft_putstr_fd`: Writes a string to a file descriptor.
- `ft_putendl_fd`: Writes a string followed by a newline to a file descriptor.
- `ft_putnbr_fd`: Writes an integer to a file descriptor.

### Part 3 - Linked lists

Functions to manage a singly linked list built on the `t_list` structure:
- `ft_lstnew`: Creates a new node using `malloc`.
- `ft_lstadd_front`: Adds a node at the beginning of the list.
- `ft_lstsize`: Counts the nodes of the list.
- `ft_lstlast`: Returns the last node of the list.
- `ft_lstadd_back`: Adds a node at the end of the list.
- `ft_lstdelone`: Frees one node and its content using `del`.
- `ft_lstclear`: Frees a node and all the following ones, and sets the list pointer to `NULL`.
- `ft_lstiter`: Applies a function to the content of each node.
- `ft_lstmap`: Creates a new list by applying a function to each node, freeing everything on allocation failure.

## Instructions

### Requirements

- A C compiler (`cc`)
- `make`
- `ar`

### Compilation

From the root of the repository:

```bash
make        # builds libft.a
make clean  # removes object files
make fclean # removes object files and libft.a
make re     # rebuilds everything from scratch
```

The Makefile uses `cc` with `-Wall -Wextra -Werror`, builds the library with `ar rcs` and does not relink.

### Usage

Include the header in your source file:

```c
#include "libft.h"
```

Then compile your program linking the library:

```bash
cc -Wall -Wextra -Werror main.c -L. -lft -o program
```

Example:

```c
#include "libft.h"

int main(void)
{
	char *s;

	s = ft_itoa(-42);
	ft_putendl_fd(s, 1);
	free(s);
	return (0);
}
```

## Resources

### References

- `man` pages of the re-implemented functions (`man 3 strlen`, `man 3 memmove`, etc.)
- *Introduccion a la Programacion con C*, Andrés Marzal and Isabel Gracia
- Makefile Tutorial: https://makefiletutorial.com/
- GNU Make manual: https://www.gnu.org/software/make/manual/
- Linked list tutorial : https://www.geeksforgeeks.org/dsa/linked-list-data-structure/
- Valgrind and AddressSanitizer documentation, used to detect leaks and invalid accesses

### Use of AI

AI (Claude) was used as a learning aid, not to generate the project. It was used for:

- Explaining concepts (pointers vs. indices, `void *`, `size_t` underflow, post/pre-decrement, `NULL` vs `'\0'`).
- Reviewing my own implementations and pointing out bugs and edge cases.
- Suggesting test cases for edge conditions.
- Helping to understand Makefile, linker and compilation errors.
