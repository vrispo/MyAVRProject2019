/* C++ Program - Get User Id */

#include <iostream>
#include <string>
#include <fstream>
#include <iostream>

using namespace std;

int main(){
	string line="default";
	ofstream IdFile;

	cout << "Insert your nickname" << endl;
	cin >> line;

	IdFile.open("userid.txt");
	if (IdFile.is_open()) {		
		IdFile << line;
	}

	IdFile.close();
	return 0;
}