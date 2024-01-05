#include "serverFileManager.h"

ServerFileManager::ServerFileManager(int idClient){
	this->idClient = idClient;
	if(this->idClient < 0) std::cout << "Error: al inicializar conexion con el cliente > " << idClient << std::endl;
}

ServerFileManager::~ServerFileManager(){
	closeConnection(this->idClient);
}

void ServerFileManager::recvOp(){
	std::vector<unsigned char> buffIn;
	std::vector<unsigned char> buffOut;
	
	recvMSG(this->idClient, buffIn);
	
	tipoOperacion op = unpack<tipoOperacion>(buffIn);		
	switch(op){
		case opBuilder:{
			std::vector<char> path;
			int pathLen = unpack<int>(buffIn);		
			
			path.resize(pathLen);
					
			unpackv(buffIn, (char*)path.data(), pathLen);
			
			this->f = new FileManager(std::string(path.data()));
					
			pack(buffOut, (int)1);
		}break;
		
		case opDestroyer:{
			delete this->f;
			
			this->f = nullptr;
			this->exit = true;
			
			pack(buffOut, (int)1);
		}break;

		case opListFiles:{					
			vector<string*>* fileList = this->f->listFiles();
			
			pack(buffOut, (int)1);				
			pack(buffOut, (int)(fileList->size()));
			
			int fileTam = 0;
			for(int i = 0; i < fileList->size(); i++) {
				std::string* file =  fileList->at(i);
				fileTam = file->size();
				
				pack(buffOut, (int)fileTam);
				packv(buffOut, (char*)file->data(), fileTam);
			}
		}break;
				
		case opReadFile:{
			std::string fileName;
			int fileNameLen = unpack<int>(buffIn);

			fileName.resize(fileNameLen);
			unpackv(buffIn, (char*)fileName.data(), fileNameLen);
					
			char* data = nullptr;
			unsigned long int dataLen = 0;
					
			this->f->readFile((char*)fileName.data(), data, dataLen);		

			pack(buffOut, dataLen);
			packv(buffOut, data, dataLen);
					
			pack(buffOut, (int)1);
		}break;
			
		case opWriteFile:{
			std::string fileNameW;
			int fileNameLenW = unpack<int>(buffIn);
			
			fileNameW.resize(fileNameLenW);
			unpackv(buffIn, (char*)fileNameW.data(), fileNameLenW);
			
			std::string dataW;
			unsigned long int dataLenW = unpack<unsigned long int>(buffIn);
			
			dataW.resize(dataLenW);
			unpackv(buffIn, (char*)dataW.data(), dataLenW);
			
			this->f->writeFile((char*)fileNameW.data(), (char*)dataW.data(), dataLenW);
			
			pack(buffOut, (int)1);
		}break;			
		
		default:{
			std::cout << "Error: op no valido" << std::endl;
		}break;
	}

	sendMSG(this->idClient, buffOut);
}