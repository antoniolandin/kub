#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <thread>

#include "utils.h"
#include "operaciones.h"
#include "serverFileManager.h"

void initConnection(int idClient);

int main(){
    int server = initServer(15000);
	
	while(1){
		if(checkClient()){
			std::thread* thread = new std::thread(initConnection, getLastClientID());
		}else{
            usleep(1000);
        }
	}
    close(server);
	return 0;
}

void initConnection(int idClient){
    ServerFileManager* serverFileManager = new ServerFileManager(idClient);
	
    while(serverFileManager->exit == false){
		serverFileManager->recvOp();
	}
}
