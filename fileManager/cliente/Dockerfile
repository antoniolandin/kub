FROM gcc:latest

# Copiar archivos

COPY . /usr/src/cliente/
WORKDIR /usr/src/cliente

# Compilar y ejecutar

RUN g++ cliente.cpp conexion_cliente.h filemanager.cpp filemanager.h operaciones.h utils.cpp utils.h -o cliente.exe
RUN ["chmod", "+x", "cliente.exe"]
ENTRYPOINT [ "./cliente.exe"] 
