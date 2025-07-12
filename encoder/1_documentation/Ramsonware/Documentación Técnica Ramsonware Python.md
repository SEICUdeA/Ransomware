# Librerias
* GC: Proporciona un modulo o interfaz para el manejo del recolector de basura de python, brinda la capacidad de deshabilitar el recolector, ajustar la frecuencia de recolección y establecer opciones de depuración.
En este caso se usa `gc.collect()` para forzar una liberaración de memora, posiblemente para mejorar el rendimiento y o evitar la detección por análisis dinámico.

* OS: Provee funcionalidades que pueden interactuar directamente con el sistema operativo.
Se usa `os.name == 'nt':` para identificar el sistema operativo de la terminal victima
`os.path.join(os.path.join(os.environ['USERPROFILE']), 'Desktop')` accede a la ruta base del sistema usando las variables de entorno con la finalidad de crear un archivo readme.txt en el escritorio de la victima.
`os.path.join(desktop_path, 'Readme.txt')` le añade readme.txt a la ruta antes mencionada para crear el archivo con la intención de notificar el ataque.
`os.remove(file_path)` borra el archivo del sistema de archivos que coincida con la ruta ingresada.
`os.walk(self.directory)` recorre carpetas y subcarpetas del sistema de forma recursiva, esto con el fin de encontrar archivos con información potencialmente valiosa para ser encriptada.

* JSON: convierte datos a cadenas de texto en formato JSON `(json.dumps(data))` se usa para enviar los datos (hostname, key, active_users, mac_address) de la victima al servidor del atacante.

* UUID: Universally Unique Identifier, este módulo proporciona objetos UUID inmutables `hex(uuid.getnode()).replace('0x', '').upper()`
obtiene la dirección del hardware como un entero positivo de 48 bits, para este caso transforma el código UUID obtenido a sistema hexadecimal, elimina los valores '0x' contenidos y convierte a mayusculas el resultado. Esto con fines de optener la mac del dispositivo atacado y posiblemente poder asociarlo en una base de datos de dispositivos vulnerados.

* CTYPES: Proporciona tipos de datos compatibles con C y permite llamar a funciones en archivos DLL o bibliotecas compartidas (funciones del sistema operativo directamente). `ctypes.windll.user32.SystemParametersInfoW(20, 0, image_path , 0)` Accede a la librería user32.dll, que controla funciones de la interfaz gráfica del usuario en Windows, esto con el fin de cambiar el fondo de pantalla por una imagen previamente seleccionada por el atacante.

* SOCKET: Este módulo proporciona acceso a la interfaz BSD socket para `socket.gethostname()` retorna una cadena que contenga el nombre de host de la máquina donde se está ejecutando actualmente el intérprete de Python. `socket.socket(socket.AF_INET, socket.SOCK_STREAM)` proporciona una conexión TCP con un servidor remoto, `AF_INET` indica que se usará la familia de direcciones IPv4, `SOCK_STREAM` define el tipo de socket como TCP.

* SUBPROCESS: permite lanzar nuevos procesos, conectarse a sus pipes de entrada/salida/error y obtener sus códigos de resultado. `subprocess.check_output(command, shell=True)` este fragmento de código tiene como objetivo obtener información sobre los usuarios conectados actualmente al sistema.

* FERNET: Es una implementación de criptografía autenticada simétrica, el cifrado no puede ser manipulado o leído sin la llave. `Fernet.generate_key()` genera una clave para mantener los archivos a salvo, `fernet.encrypt(original)` cifra los datos y genera un Token codificado en base64.