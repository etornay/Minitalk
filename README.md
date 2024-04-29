<h1>1. Instrucciones específicas</h1>

• Los ejecutables deben llamarse client y server.

• Deberás proporcionar un archivo Makefile, que compilará los archivos fuente de
tu programa. No deberá hacer relink.

• Puedes usar tu libft.

• Debes gestionar los errores con cuidado. Bajo ninguna circunstancia tu programa
puede terminar inesperadamente (segfault, bus error, double free, etc).

• Tu programa no puede tener leaks de memoria.

• Puedes utilizar una variable global por programa (una para el cliente y otra
para el servidor), pero tendrás que justificar su uso.

• En la parte obligatoria se te permite utilizar las siguientes funciones:

**◦ write**

**◦ ft_printf y cualquier equivalente que TÚ hayas programado**

**◦ signal**

**◦ sigemptyset**

**◦ sigaddset**

**◦ sigaction**

**◦ kill**

**◦ getpid**

**◦ malloc**

**◦ free**

**◦ pause**

**◦ sleep**

**◦ usleep**

**◦ exit**

<h1>2. Parte obligatoria</h1>

• Debes crear un programa de comunicación en la forma de un cliente y un servidor.

• El servidor debe lanzarse primero, tras lanzarse debe mostrar su PID.

• El cliente tomará como parámetros:

**◦ El PID del servidor.**

**◦ La string que debería mandarse.**

• El cliente debe comunicar la string pasada como parámetro al servidor. Una vez la
string se haya recibido, el servidor debe mostrarla.

• El servidor debe ser capaz de mostrar la string suficientemente rápido. Por rápido
queremos decir que si piensas que es está tardando mucho, probablemente es que
está tardando demasiado.

• Tu servidor debe poder recibir strings de distintos clientes consecutivamente, sin
necesidad de reiniciar.

• La comunicación entre tu cliente y tu servidor debe hacerse SOLO utilizando
señales UNIX.

• Solo puedes utilizar estas dos señales: SIGUSR1 y SIGUSR2.

<h1>3. Extras</h1>

_**Lista de bonus:**_

• El servidor confirma cada señal recibida mandando una señal al cliente.

• Soporta los caracteres Unicode.
