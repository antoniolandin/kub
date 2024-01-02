# Authors: Antonio Cabrera y Alejandro Gómez
# Group: 3º MAIS 2023/2024

FROM gcc:latest

# Copiar archivos

COPY . /usr/src/servidor

# Especificar espacio de trabajo

WORKDIR /usr/src/servidor

# Compilar y ejecutar

RUN g++ servidor.cpp conexion_cliente.h filemanager.cpp filemanager.h operaciones.h utils.cpp utils.h -o servidor.exe
RUN ["chmod", "+x", "servidor.exe"]
ENTRYPOINT [ "./servidor.exe"] 
