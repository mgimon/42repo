## Sobre libft

El objetivo de este proyecto fue desarrollar funciones que tienen los mismos prototipos e implementan los mismos comportamientos que las funciones originales de la libc (por ejemplo, ft_atoi recrea el comportamiento de atoi). Deberán ser tal y como las describe el man. Ademas, se han de desarrollar un conjunto de funciones que, o no son de la libc, o lo son pero de una forma distinta.

### 🔹 Funciones de la libc:

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

### 🔹 Funciones extra:

| Funcion | Descripcion |
| :---: | :---: |
| ft_substr | Reserva (con malloc(3)) y devuelve una substring de la string ’s’. La substring empieza desde el índice ’start’ y tiene una longitud máxima ’len’. |
| ft_strjoin | Reserva (con malloc(3)) y devuelve una nueva string, formada por la concatenación de ’s1’ y ’s2’. |
| ft_strtrim | Elimina todos los caracteres de la string ’set’ desde el principio y desde el final de ’s1’, hasta encontrar un caracter no perteneciente a ’set’. La string resultante se devuelve con una reserva de malloc(3) |
| ft_split | Reserva (utilizando malloc(3)) un array de strings resultante de separar la string ’s’ en substrings utilizando el caracter ’c’ como delimitador. El array debe terminar con un puntero NULL. |
| ft_itoa | Utilizando malloc(3), genera una string que represente el valor entero recibido como argumento. Los números negativos tienen que gestionarse. |
| ft_strmapi | A cada carácter de la string ’s’, aplica la función ’f’ dando como parámetros el índice de cada carácter dentro de ’s’ y el propio carácter. Genera una nueva string con el resultado del uso sucesivo de ’f’. |
| ft_striteri | A cada carácter de la string ’s’, aplica la función ’f’ dando como parámetros el índice de cada carácter dentro de ’s’ y la dirección del propio carácter, que podrá modificarse si es necesario. |
| ft_putchar_fd | Envía el carácter ’c’ al file descriptor especificado. |
| ft_putstr_fd | Envía la string ’s’ al file descriptor especificado. |
| ft_putendl_fd | Envía la string ’s’ al file descriptor especificado, seguida de un salto de linea. |
| ft_putnbr_fd | Envía el entero ’n’ al file descriptor especificado. |

### 🔹 Bonus:

| Funcion | Descripcion |
| :---: | :---: |
| ft_lstnew | Crea un nuevo nodo utilizando malloc(3). La variable miembro ’content’ se inicializa con el contenido del parámetro ’content’. La variable ’next’, con NULL. |
| ft_lstadd_front | Añade el nodo ’new’ al principio de la lista ’lst’. |
| ft_lstsize | Cuenta el número de nodos de una lista. |
| ft_lstlast | Devuelve el último nodo de la lista. |
| ft_lstadd_back | Añade el nodo ’new’ al final de la lista ’lst’. |
| ft_lstdelone | Toma como parámetro un nodo ’lst’ y libera la memoria del contenido utilizando la función ’del’ dada como parámetro, además de liberar el nodo. La memoria de ’next’ no debe liberarse. |
| ft_lstclear | Elimina y libera el nodo ’lst’ dado y todos los consecutivos de ese nodo, utilizando la función ’del’ y free(3). Al final, el puntero a la lista debe ser NULL. |
| ft_lstiter | Itera la lista ’lst’ y aplica la función ’f’ en el
contenido de cada nodo. |
| ft_lstmap | Itera la lista ’lst’ y aplica la función ’f’ al contenido de cada nodo. Crea una lista resultante de la aplicación correcta y sucesiva de la función ’f’ sobre cada nodo. La función ’del’ se utiliza para eliminar el contenido de un nodo, si hace falta. |


### - Mi perfil en la intranet de 42 ↙️
[AQUÍ](https://profile.intra.42.fr/users/mgimon-c)

### - Mi perfil de LinkedIn ↙️
[AQUÍ](https://www.linkedin.com/in/mgimon-c/)
