// UtilityDll.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"

//TestDLL.__AddFunction( C_PCHAR , "get_IPaddress");

extern "C" __declspec(dllexport) char * get_IPaddress(){
	std::string line;
	std::ifstream IPFile;
	int offset;
	int i = 0;
	char search0[40] = "IPv4";      // search pattern
	char chr_line[20] = {0};
	char *to_ret;

	system("ipconfig > ip.txt");

	IPFile.open("ip.txt");
	if (IPFile.is_open()) {
		while (!IPFile.eof()) {
			getline(IPFile, line);

			if ((offset = line.find(search0, 0)) != std::string::npos){
				line.erase(0, 43);
				int off;
				if ((off = line.find(" ", 0)) != std::string::npos)
					line.erase(off, std::string::npos);
				IPFile.close();

				strcpy(chr_line, line.c_str());				
				while(chr_line[i] != '\0'){
					to_ret[i] = chr_line[i];
					i++;
				}
				to_ret[i] = '\0';

				return to_ret;			
			}
		}
	}
	return "";
}

extern "C" __declspec(dllexport) int open_idprog(){
	int ret = system("GetId.exe");
	return ret;
}
