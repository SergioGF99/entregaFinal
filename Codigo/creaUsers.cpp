#include <cstdlib>
#include <iostream>
#include <list>
#include <string>
#include <fstream>
#include <string.h>
using namespace std;

int main(){

	ofstream f("users.bin",ios::binary);

	char usuario[256] = "profesor1";
	char clave[256] = "1234";

	if (f.is_open()){
		f.write((char*)&usuario, sizeof(char)*256);
		f.write((char*)&clave, sizeof(char)*256);
	}
	f.close();
	return 0;
}