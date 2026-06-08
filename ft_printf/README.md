_This project has been created as part of the 42 curriculum by tpinto-v._

# Description

In this project, it will be replicated some of the behaviors of the well known `printf` function which prints values on the `stdout`,  standard output stream(a page is refered to this topic in the **Resources** section).  And then it was created a library with this implementation, called `libftprintf.a`.

In the present case, the behaviors of the mandatory part of this project, which are the following format specifiers `%c`(characters),  `%s`(strings), `%p` (pointer), `%d`(decimal number), `%i` (integer number in base 10, i.e. same of `%d`), `%u`(unsigned integer in base 10), `%x`(unsigned integer in hexadecimal lowercase base), `%X`(unsigned integer in hexadecimal uppercase base) and `%%`(for printing the percentage `%`).

## Some details about this implementation

Another things to take in account is that this implementation handle the case that the argument is a null pointer (i.e., `printf((void *) 0)` or with the alias), in this case the printf function will return `-1` and won't print anything. 

Some undefine behaviors are also handled and are listed below (where `NULL` is an alias for a null pointer `#define NULL (void *) 0`, commonly used in the libc by the header file `stdlib.h`),

Format specifier | Argument | Example/Explanation
--|--|--
`%p` | `NULL` | `ft_printf("%p", NULL);` prints `(nil)`
`%s` | `NULL` | `ft_printf("%s", NULL);` prints`(null)`
`%` , i.e without the specifiers said previously |  | `ft_printf("hello% how are you ?");` prints `hello` and returns `-1`. So it prints until the `%`. 

## Auxiliary Functions in the library for making the ft_printf function

All the functions below has a pointer `count` to an integer that are used for tracking the amount of character are printed on the `stdout`.

Functions | Description | Format specifiers that use it
--|--|--
`void   ft_putchar(char c, int *count);` | Prints the character `c` |  `%c` `%%`
`void	ft_putstr(char *s, int *count);` | Prints the string pointer by `s`  | `%s`
`void	ft_putnbr_base(unsigned long n, char *base, size_t lbase, int *count);` | It is used for printing the number without sign for the next functions in the given base. | Used in the next functions
`void	ft_putsign(long n, char *base, int *count);` | Prints a signed long in a given base.| `%i` `%d` `%x` `%X`
`void	ft_putuns(unsigned long n, char *base, int *count);` | Prints an unsigned long in a given base.| `%u`
`void	ft_putptr(unsigned long n, int *count);` | Prints the number `n` in hexadecimal with `0x` on the beginning for being in the pointer format. | `%p`

# Instructions

## Makefile
Commands | Side-effect
--|--
`make` `make all` | Compile all the object files and then archive them into the library libftprintf.a (i.e., build the library)
`make clean` | Remove all the object files
`make fclean` | Remove the library libft.a and all the object files
`make re` | Rebuild the library (i.e., run `clean` and then `all`)

## How to use the library ?

1. Use `make` in order to build the library as specified previously.
2. Don't forget to have a `.c` file with a `main() function`.
3. Include libft header by doing `#include "ft_printf.h"` into your `.c` file.
4. Compile the `.c` by using `cc [name of the .c file] -I[path where the ft_printf.h is] -L[path where the libftprintf.a is] -lftprintf`
5. Execute the executable by doing `./[name of the executable]`.

# Resources

Some helpful resources about the C and the printf function:

- [FreeBSD Manual page of the printf function](https://man.freebsd.org/cgi/man.cgi?query=printf&sektion=3&apropos=0&manpath=FreeBSD+15.0-RELEASE+and+Ports.quarterly) and for the [stdarg.h](https://man.freebsd.org/cgi/man.cgi?query=stdarg&apropos=0&sektion=0&manpath=FreeBSD+15.0-RELEASE+and+Ports.quarterly&format=html).
- The [Geekforgeeks](https://www.geeksforgeeks.org) website has many tutorials for learning C, other programming languages and many other computing topics.
- [Cs50x](https://cs50.harvard.edu/x/), a course for learning many C and programming concepts.
- [Standard streams](https://en.wikipedia.org/wiki/Standard_streams). 