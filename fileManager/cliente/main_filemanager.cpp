#include "clientFileManager.h"
#include "filemanager.h"

int main(){
    //Constantes
    std::string comando;
    bool menu = true;
    bool error = true;

    ClientFileManager* clientFileManager = new ClientFileManager("./dirprueba/");
    FileManager* fileManager = new FileManager("./dirprueba/");

    char* data = nullptr;
    unsigned long int fileLen = 0;

    std::cout << "Escriba 'help' para ver comandos\n";
    do{
        std::getline(std::cin, comando);
        error = true;

        if(!comando.compare("exit")){
            menu = false;
            error = false;
        }

        if(!comando.compare("ls")){
            std::vector<std::string*>* archivosLocales = fileManager->listFiles();
            std::cout << "Archivos Locales:\n";
            for(int i = 0; i < archivosLocales->size(); i++){
                std::cout << "\t" << archivosLocales->at(i)->c_str() << "\n";
            }
            
            std::vector<std::string*>* archivosServer = clientFileManager->listFiles();
            std::cout << "Archivos en server:\n";
            for(int i = 0; i < archivosServer->size(); i++){
                std::cout <<"\t"<< archivosServer->at(i)->c_str()<<"\n";
            }
            error = false;
        }

        if(!comando.compare("help")){
            std::cout << "Comandos disponibles:\n\tls\n\tdownload <filename.txt>\n\tupload <filename.txt>\n\texit\n";
            error = false;
        }

        std::stringstream* aux = new std::stringstream(comando);
        std::string* comandoFilename = new std::string();
        std::vector<std::string>* comandoData = new std::vector<std::string>();
        while(std::getline(*aux, *comandoFilename , ' '))comandoData->push_back(*comandoFilename );
        
        //Si no se escribe nombre de fichero, el comando es incorrecto
        if(comandoData->size() == 2){
            if(!comandoData->at(0).compare("download")){
                //Leemos
                clientFileManager->readFile((char*)comandoData->at(1).c_str(), data, fileLen);
                //Escribimos server->local
                fileManager->writeFile((char*)comandoData->at(1).c_str(), data, fileLen);
                std::cout << comandoData->at(1).c_str() << " downloaded!\n";
                error = false;
            }

            if(!comandoData->at(0).compare("upload")){
                //Leemos
                fileManager->readFile((char*)comandoData->at(1).c_str(), data, fileLen);
                //Escribimos local->server
                clientFileManager->writeFile((char*)comandoData->at(1).c_str(), data, fileLen);
                std::cout << comandoData->at(1).c_str() << " uploaded!\n";
                error = false;
            }
        }
        //Liberamos memoria
        delete comandoFilename;
        delete comandoData;
        delete aux;

        //Control de errores
        if(error){
            std::cout << "Error> comando no valido o incorrecto\n";
        }
    }while(menu);

    //Liberamos memoria
    delete fileManager;
    delete clientFileManager;
    
    if(data != nullptr) delete[] data;
    return 0;
}
