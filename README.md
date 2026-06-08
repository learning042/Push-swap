_This project has been created as part of the 42 curriculum by tpinto-v._

# Description

Libft is a C library containing reimplementations of Standard C library (libc) functions, along with some additional utility functions.

## Functions in the library

### 1. Character checks and manipulation

> **Note:** libc implementations of some of these functions may use bit-shifting and bit-masking internally. See the **Resources** section for more.

| Function | Description | Category |
|--|--|--|
| `int ft_isalpha(int c);` | Checks for an alphabetic character. | libc |
| `int ft_isdigit(int c);` | Checks for a digit character (`'0'` through `'9'`). | libc |
| `int ft_isalnum(int c);` | Checks for an alphanumeric character. | libc |
| `int ft_isascii(int c);` | Checks whether the value fits within the ASCII character set. | libc |
| `int ft_isprint(int c);` | Checks for any printable character. | libc |
| `int ft_toupper(int c);` | Converts a lowercase letter to uppercase. | libc |
| `int ft_tolower(int c);` | Converts an uppercase letter to lowercase. | libc |

### 2. String manipulation

| Function | Description | Category |
|--|--|--|
| `size_t ft_strlen(const char *s);` | Returns the length of the string, excluding the null terminator `'\0'`. | libc |
| `size_t ft_strlcpy(char *dst, const char *src, size_t size);` | Copies the string pointed to by `src` into the buffer pointed to by `dst`, limited by `size`. If the buffer is too small, the result is truncated and null-terminated. Returns the length of `src`. | libc |
| `size_t ft_strlcat(char *dst, const char *src, size_t size);` | Like `ft_strlcpy`, but concatenates `src` onto the end of `dst` instead of copying. Returns the total length of the string it attempted to create (i.e., the initial length of `dst` plus the length of `src`). | libc |
| `char *ft_strchr(const char *s, int c);` | Returns a pointer to the first occurrence of character `c` in string `s`. The null terminator is considered part of the string, so passing `'\0'` returns a pointer to the end of the string. | libc |
| `char *ft_strrchr(const char *s, int c);` | Like `ft_strchr`, but returns a pointer to the last occurrence of `c`. | libc |
| `int ft_strncmp(const char *s1, const char *s2, size_t n);` | Compares the first `n` bytes of strings `s1` and `s2` using unsigned character comparison. | libc |
| `char *ft_strnstr(const char *big, const char *little, size_t len);` | Locates the first occurrence of the string `little` within `big`, searching at most `len` characters. | libc |
| `char *ft_strdup(const char *s);` | Returns a pointer to a newly allocated duplicate of the string `s`. The memory is obtained via `malloc(3)` and can be released with `free(3)`. | libc |
| `char *ft_substr(char const *s, unsigned int start, size_t len);` | Allocates and returns a substring of `s` starting at index `start` with a maximum length of `len`. If `start` is beyond the end of `s`, an empty string is returned. If `len` exceeds the available characters from `start`, it is clamped to what is available. Returns a pointer to the substring. | extra |
| `char *ft_strjoin(char const *s1, char const *s2);` | Allocates and returns a new string that is the concatenation of `s1` and `s2`. | extra |
| `char *ft_strtrim(char const *s1, char const *set);` | Allocates and returns a copy of `s1` with all leading characters (left side) and then all trailing characters (right side) that appear in `set` removed. Returns `NULL` if the allocation fails. | extra |
| `char **ft_split(char const *s, char c);` | Allocates and returns an array of strings obtained by splitting `s` on the delimiter character `c`. Each substring is independently allocated. The array is null-terminated. | extra |
| `char *ft_strmapi(char const *s, char (*f)(unsigned int, char));` | Applies `f` to each character of `s`, passing the character's index and the character itself. Returns a newly allocated string built from the results. | extra |
| `void ft_striteri(char *s, void (*f)(unsigned int, char*));` | Like `ft_strmapi`, but modifies `s` in place rather than producing a new string. The function receives a pointer to each character, allowing in-place modification. | extra |

### 3. Memory manipulation

| Function | Description | Category |
|--|--|--|
| `void *ft_memset(void *s, int c, size_t n);` | Fills the first `n` bytes of the memory area pointed to by `s` with the byte value `c` (cast to `unsigned char`). | libc |
| `void ft_bzero(void *s, size_t n);` | Erases `n` bytes starting at `s` by writing `'\0'` to each byte. | libc |
| `void *ft_memcpy(void *dest, const void *src, size_t n);` | Copies `n` bytes from memory area `src` to memory area `dest`. The areas must not overlap — if they do, bytes in `src` may be overwritten before being read, corrupting the copy. | libc |
| `void *ft_memmove(void *dest, const void *src, size_t n);` | Like `ft_memcpy`, but handles overlapping memory regions safely — either by copying from back to front, or (as in the libc implementation) by first copying `src` into a temporary buffer that doesn't overlap either area, then copying to `dest`. | libc |
| `void *ft_memchr(const void *s, int c, size_t n);` | Searches the first `n` bytes of `s` for the first occurrence of `c`. Both `c` and the bytes of `s` are interpreted as `unsigned char`. | libc |
| `int ft_memcmp(const void *s1, const void *s2, size_t n);` | Compares the first `n` bytes of `s1` and `s2`, interpreted as `unsigned char`. | libc |
| `void *ft_calloc(size_t nmemb, size_t size);` | Allocates memory for an array of `nmemb` elements of `size` bytes each, initialised to zero. If `nmemb * size` is zero, returns a unique pointer that can still be passed to `free()`. Returns `NULL` on overflow of `nmemb * size`. | libc |

### 4. Type conversion

| Function | Description | Category |
|--|--|--|
| `int ft_atoi(const char *nptr);` | Converts the string pointed to by `nptr` to an `int`. Leading whitespace (as defined by `isspace(3)`) is skipped. An optional leading `'+'` or `'-'` sign is accepted; a second sign character stops conversion. Conversion stops at the first non-digit character. | libc |
| `char *ft_itoa(int n);` | The inverse of `ft_atoi`. Converts the integer `n` to a newly allocated string. | extra |

### 5. File descriptor output

| Function | Description | Category |
|--|--|--|
| `void ft_putchar_fd(char c, int fd);` | Writes character `c` to the file descriptor `fd`. | extra |
| `void ft_putstr_fd(char *s, int fd);` | Writes the string `s` to the file descriptor `fd`. | extra |
| `void ft_putendl_fd(char *s, int fd);` | Writes the string `s` followed by a newline to the file descriptor `fd`. | extra |
| `void ft_putnbr_fd(int n, int fd);` | Writes the integer `n` to the file descriptor `fd`. | extra |

### 6. Linked lists

These functions operate on the `t_list` struct defined as follows:

```c
typedef struct s_list {
    void            *content;
    struct s_list   *next;
} t_list;
```

| Function | Description | Category |
|--|--|--|
| `t_list *ft_lstnew(void *content);` | Allocates and returns a new node. `content` is set to the given parameter and `next` is initialised to `NULL`. | extra |
| `void ft_lstadd_front(t_list **lst, t_list *new);` | Adds the node `new` at the beginning of the list. `lst` is a pointer to the pointer to the first node. | extra |
| `int ft_lstsize(t_list *lst);` | Returns the number of nodes in the list. | extra |
| `t_list *ft_lstlast(t_list *lst);` | Returns the last node of the list. | extra |
| `void ft_lstadd_back(t_list **lst, t_list *new);` | Adds the node `new` at the end of the list. | extra |
| `void ft_lstdelone(t_list *lst, void (*del)(void *));` | Frees the content of `lst` using `del`, then frees the node itself. Does **not** free subsequent nodes. | extra |
| `void ft_lstclear(t_list **lst, void (*del)(void *));` | Deletes and frees the given node and all following nodes using `del` and `free(3)`. Sets the list pointer to `NULL`. | extra |
| `void ft_lstiter(t_list *lst, void (*f)(void *));` | Iterates through the list (where `lst` points to the first node) and applies `f` to the content of each node. | extra |
| `t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));` | Iterates through the list (where `lst` points to the first node), applies `f` to each node's content, and builds a new list from the results. If a node allocation fails, `del` is used to free already-created content before returning `NULL`. | extra |

---

## Makefile

| Command | Effect |
|--|--|
| `make` / `make all` | Compile all object files and archive them into `libft.a` |
| `make clean` | Remove all object files |
| `make fclean` | Remove `libft.a` and all object files |
| `make re` | Rebuild the library (`fclean` then `all`) |

## Usage

1. Run `make` to build the library.
2. Create a `.c` file with a `main()` function.
3. Add `#include "libft.h"` at the top of your file.
4. Compile with: `cc <file.c> -I<path/to/libft.h> -L<path/to/libft.a> -lft`
5. Run the resulting executable: `./a.out`

---

## Resources

- Function documentation is available via `man <function_name>` in the terminal, or through the [FreeBSD man pages](https://man.freebsd.org/cgi/man.cgi).
- [GeeksforGeeks](https://www.geeksforgeeks.org) — tutorials for C and other programming topics.
- [CS50x](https://cs50.harvard.edu/x/) — introductory course covering C and programming fundamentals.
- [isspace(3)](https://man.openbsd.org/isspace.3) — OpenBSD manual page for `isspace`.