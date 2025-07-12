Para el funcionamiento del script, se crea una clase llamada RansowareSimulator, dicha clase cuenta con un metodo inicializador para crear una instancia de la clase en el momento de ser llamado, este método cuenta con los siguientes atributos:
* directory: Es el directorio objetivo de ataque.
* server_host: Es el dominio del servidor que recibe los datos de la victima
* server_port: Puerto del servidor (server_host) que se encuentra habilitado para recibir los datos de la victima
* file_extensions: Son las estenxiones de archivo que serán atacadas (principalmente .txt .dock. .csv .jpg entre otras)
* key: Token generado de la operación `generate_key` de la libreria fernet

```
class RansomwareSimulator:
    def __init__(self, directory, server_host, server_port, file_extensions):
        self.directory = directory
        self.server_host = server_host
        self.server_port = server_port
        self.file_extensions = file_extensions
        self.key = Fernet.generate_key()
```

