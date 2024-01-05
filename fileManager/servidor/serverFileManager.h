#pragma once

#include "filemanager.h"
#include "operaciones.h"
#include "utils.h"

class ServerFileManager{
	private:
		FileManager* f = nullptr;
		int idClient = -1;
	public:
		bool exit = false;
		ServerFileManager(int idClient);		
		~ServerFileManager();
		void recvOp();
};