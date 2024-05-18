## About libft

The objective of this project was to develop functions that have the same prototypes and implement the same behaviors as the original functions in the libc (for example, ft_atoi recreates the behavior of atoi). They must be as described in the man pages. Additionally, a set of functions must be developed that either are not in the libc or are in a different form.

### 🟠 Functions from the libc:

• isalpha
• isdigit
• isalnum
• isascii
• isprint
• strlen
• memset
• bzero
• memcpy
• memmove
• strlcpy
• strlcat
• toupper
• tolower
• strchr
• strrchr
• strncmp
• memchr
• memcmp
• strnstr
• atoi
• calloc
• strdup

### 🟠 Extra functions:

| Function | Description |
| :---: | :---: |
| ft_substr | Allocates (with malloc(3)) and returns a substring from the string ’s’. The substring begins at index ’start’ and is of maximum size ’len’. |
| ft_strjoin | Allocates (with malloc(3)) and returns a new string, which is the result of the concatenation of ’s1’ and ’s2’. |
| ft_strtrim | Allocates (with malloc(3)) and returns a copy of ’s1’ with the characters specified in ’set’ removed from the beginning and the end of the string. |
| ft_split | Allocates (with malloc(3)) and returns an array of strings obtained by splitting ’s’ using the character ’c’ as a delimiter. The array must be ended by a NULL pointer. |
| ft_itoa | Allocates (with malloc(3)) and returns a string representing the integer received as an argument. Negative numbers must be handled. |
| ft_strmapi | Applies the function ’f’ to each character of the string ’s’ to create a new string resulting from successive applications of ’f’. |
| ft_striteri | Applies the function ’f’ to each character of the string ’s’ with its index as first argument. |
| ft_putchar_fd | Outputs the character ’c’ to the given file descriptor. |
| ft_putstr_fd | Outputs the string ’s’ to the given file descriptor. |
| ft_putendl_fd | Outputs the string ’s’ to the given file descriptor, followed by a newline. |
| ft_putnbr_fd | Outputs the integer ’n’ to the given file descriptor. |

### 🟠 Bonus:

| Function | Description |
| :---: | :---: |
| ft_lstnew | Allocates (with malloc(3)) and returns a new element. The variable ’content’ is initialized with the value of the parameter ’content’. The variable ’next’ is initialized to NULL. |
| ft_lstadd_front | Adds the element ’new’ at the beginning of the list. |
| ft_lstsize | Counts the number of elements in a list. |
| ft_lstlast | Returns the last element of the list. |
| ft_lstadd_back | Adds the element ’new’ at the end of the list. |
| ft_lstdelone | Takes as a parameter an element and frees the memory of the element’s content using the function ’del’ given as a parameter, and free the element. The memory of ’next’ must not be freed. |
| ft_lstclear | Deletes and frees the given element and every successor of that element, using the function ’del’ and free(3). Finally, the pointer to the list must be set to NULL. |
| ft_lstiter | Iterates the list ’lst’ and applies the function ’f’ to the content of each element. |
| ft_lstmap | Iterates the list ’lst’ and applies the function ’f’ to the content of each element. Creates a new list resulting from the successive applications of ’f’. |

##

### 🔄 You may also like...
[-> My profile on the 42 Intranet](https://profile.intra.42.fr/users/mgimon-c)

[-> My LinkedIn profile](https://www.linkedin.com/in/mgimon-c/)
