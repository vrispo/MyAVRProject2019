// UtilityDll.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"

//TestDLL.__AddFunction( C_PCHAR , "get_IPaddress");

void int_to_bin_digit(unsigned int in, int count, int* out)
{
	/* assert: count <= sizeof(int)*CHAR_BIT */
	unsigned int mask = 1U << (count - 1);
	int i;
	for (i = 0; i < count; i++) {
		out[i] = (in & mask) ? 1 : 0;
		in <<= 1;
	}
}

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

				/*				char temp[40];

				strcpy(temp, to_ret);
				
				i = 0;

				while (to_ret[i] != '.') {
					temp[i] = to_ret[i];
					i++;
				}

				int a[8];
				unsigned int ip_1 = 0;
			    ip_1 = atoi(temp);

				int_to_bin_digit(ip_1, 8, a);

				if (a[1] == 0) {
					strcat(temp, ",B");
				}
				else{
					strcat(temp, ",C");
				}

			std::cout << to_ret;

				char * pch;
				pch = strtok(to_ret, ".");
				int ip_1 = atoi(pch);
				int n;
				uint8_t a[8];
				for (int j = 0; ip_1 > 0; j++) {
					a[j] = ip_1 % 2;
					ip_1 = ip_1 / 2;
				}

				if (a[1] == 0) {
					to_ret[i] = ',';
					to_ret[i + 1] = 'B';
					to_ret[i + 2] = '\0';
				}else 
					if (a[1] == 1) {
						to_ret[i] = ',';
						to_ret[i + 1] = 'C';
						to_ret[i + 2] = '\0';
					}
					else {
						to_ret[i] = ',';
						to_ret[i + 1] = 'E';
						to_ret[i + 2] = '\0';
					}
*/
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
