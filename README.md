# get_next_line (linux version 2024)

# 1 OPEN 
### ```int open(const char *camino, int flags);```
### ```int open(const char *camino, int flags, mode_t modo) (Opcional modo);```

### **INPUT (parámetros):**
const char **camino = Puntero a la ruta de fichero que queremos abrir<br>
int flags = flags que indican la forma de apertura<br>
**Opcional** mode_t modo = permisos en caso de crear archivo

Las flags de apertura pueden ser:<br><br>
• Solo Lectura (O_RDONLY)<br>
• Solo Escritura (0_WRONLY)<br>
• Lectura / Escritura (O_RDWR)<br>
• otros (O_CREAT, O_EXCL, O_NOCTTY, O_TRUNC, O_APPEND, O_NONBLOCK u O_NDELAY, O_SYNC, O_NOFOLLOW, O_DIRECTORY, O_DIRECT, O_ASYNC y O_LARGEFILE)<br><br>
Tercer parámetro de permisos pueden ser:<br><br>
• S_IRUSR (el usuario puede leer "R")<br>
• S_IWUSR (el usuario puede escribir "w")<br>
• S_IXUSR (el usuario puede ejecutar "x")<br>
• S_IRWXU (el usuario puede leer, escribir y ejecutar "RWX")<br>
• y otros como S_IRWXG, S_IRGRP, S_IWGRP, S_IXGRP, S_IRWXO, S_IROTH, S_IWOTH y S_IXOTH.<br>
### **OUTPUT (return):**
Un int que identifica un descriptor de fichero, o -1 en caso de error.
<p><br></p>

# 2 CLOSE
### ```int close(int fd);```
### **INPUT:**
int fd = file descriptor de un archivo
### **OUTPUT:**
Devuelve 0 en caso de éxito y -1 en caso de error
<p><br></p>

# 3 READ
### ```size_t read(int fd, void *buf, size_t nbytes);```
### **INPUT:**
int fd = Número descriptor de fichero que devuelve la función open<br>
void *buf = un puntero a un buffer de memoria<br>
size_t nbytes = un tamaño que indica el número de bytes del buffer que vamos a leer o escribir<br>
### **OUTPUT:**
Número de bytes leídos o escritos, o -1 en caso de error.
<p><br></p>

# 4 WRITE
### ```size_t write(int fd, void *buf, size_t num);```
### **INPUT:**
Número descriptor de fichero que devuelve la función open, un puntero a un buffer de memoria, un tamaño que indica el número de bytes del buffer que vamos a leer o escribir. 
### **OUTPUT:**
Número de bytes leídos o escritos, o -1 en caso de error.
<p><br></p>

# PROYECTO OBLIGATORIO
• Llamar a tu función get_next_line de manera repetida (con bucle) <br>
• Devolver la línea que se acaba de leer<br>
• Si no hay más que leer o si hay error, devuelve nil<br>
• Función que se comporte adecuadamente cuando lea un archivo y cuando lea de stdin<br>
• La línea devuelta deber terminar con el caracter n, excepto si ha llegado al final del archivo y esté no termina con un caractér n<br>
• En el header get_next_line.h deberás tener como mínimo el prototipo de la función get_next_line.c<br>
• Programa debe compilar con el flag -D BUFFER_SIZE=xx para determinar el tamaño del buffer de las lecturas de tu get_next_line<br>
• Ejemplo compilación: cc -Wall -Werror -Wextra -D BUFFER_SIZE=42 <archivos>.c<br>
• Se considera que get_next_line() tiene un comportamiento indeterminado si el archivo al que apunta el fd ha cambiado desde la ult. vez que se llamo, siempre que read no haya llegado al final del archivo<br>
• Un comportamiento indeterminado cuando lo que se lee es un archivo binario, buscar solucion para este problema<br>
• inteta leer lo menos posible cada vez que se llame a la función<br>
• No se permite utilización de lseek<br>

# PARTE BONUS
• Desarolla get_next_line() con una sola variable estática<br>
• Tu get_next_line debe gestionar múltiples fd a la vez. Es decir, si tienes tres fd disponibles para lectura (por ejemplo: 3, 4 y 5), debes poder utilizar get_next_line una vez sobre el fd 3, otra vez sobre el fd 4, y otra vez sobre el fd 5 de forma alterna. Y sí, no debe perder el hilo de lectura de cada uno de los fd.<br>
• Añade sufijo _bonus.[c\h] (los extra a parte de los obligatorios serian get_next_line_bonus.c, get_next_line_bonus.h, get_next_line_utils_bonus.c)<br>
