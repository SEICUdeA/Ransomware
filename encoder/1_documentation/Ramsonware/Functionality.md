# ¿Cómo funciona el encoder?

### Resumen general
El encoder consta de una clase que tiene de atributos el directorio objetivo, la dirección y el puerto del servidor de control; y una llave que es generada en tiempo de ejecución.

El encoder tiene preestablecidas las extensiones victimas, la carpeta, el wallpaper, y el host y puerto del servidor

El flujo de ejecución del encriptador es:
1. Encuentra los archivos y los encripta
2. recolecta y envia al servidor la información importante de la victima:
	- la llave para desencriptar
	- los usuarios activos
	- la MAC
	- y la dirección IP o hostname
3. cambia el wallpaper
4. crea el readme
5. limpia la ram

### Explicación Específica