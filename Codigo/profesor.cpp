#include <cstdlib>
#include <iostream>
#include <list>
#include <string>
#include <fstream>
#include <string.h>
#include "profesor.h"
#include "agenda.h"
#include "alumno.h"
using namespace std;

#define MEMORIA 1550;

bool profesor::cargarBD(list<Alumno>& alumnos_, string archivo){
	char dni[9];
	char nombre[256];
	char apellidos[256];
	char direccion[256];
	char correo[256];
	char curso[256];
	char telefono[256];
	int equipo;
	bool lider;

	alumnos_.clear();
	ifstream f(archivo, ios::binary);

	if (f.is_open()){
		while(f.read((char*)&dni, sizeof(char)*9)) {
			string NDNI(dni);
			f.read((char*)&nombre, sizeof(char)*256);
			string Nnombre(nombre);
			f.read((char*)&apellidos, sizeof(char)*256);
			string Napellidos(apellidos);
			f.read((char*)&direccion, sizeof(char)*256);
			string Ndireccion(direccion);
			f.read((char*)&correo, sizeof(char)*256);
			string Ncorreo(correo);
			f.read((char*)&curso, sizeof(char)*256);
			string Ncurso(curso);
			f.read((char*)&telefono, sizeof(char)*256);
			string Ntelefono(telefono);
			f.read((char*)&equipo, sizeof(int));
			f.read((char*)&lider, sizeof(bool));

			Alumno a1(NDNI, Nnombre, Napellidos, Ndireccion, Ncorreo, Ncurso, Ntelefono, equipo, lider);	
			alumnos_.push_back(a1);
		}
		f.close();
		return true;
	}else{
		return false;
	}
}

bool profesor::guardarBD(list<Alumno> alumnos_, string archivo){
	list<Alumno>::iterator i;
	ofstream f(archivo,ios::binary);	
	char dni[9];
	char nombre[256];
	char apellidos[256];
	char direccion[256];
	char correo[256];
	char curso[256];
	char telefono[256];
	int equipo;
	bool lider;

	if (f.is_open()){
		for(i=alumnos_.begin(); i!=alumnos_.end(); i++){
			strcpy(dni, i->getDNI().c_str());
			f.write((char*)&dni, sizeof(char)*9);
			strcpy(nombre, i->getNombre().c_str());
			f.write((char*)&nombre, sizeof(char)*256);
			strcpy(apellidos, i->getApellidos().c_str());
			f.write((char*)&apellidos, sizeof(char)*256);
			strcpy(direccion, i->getDireccion().c_str());
			f.write((char*)&direccion, sizeof(char)*256);
			strcpy(correo, i->getCorreo().c_str());
			f.write((char*)&correo, sizeof(char)*256);
			strcpy(curso, i->getCurso().c_str());
			f.write((char*)&curso, sizeof(char)*256);
			strcpy(telefono, i->getTelefono().c_str());
			f.write((char*)&telefono, sizeof(char)*256);
			equipo = i->getEquipo();
			f.write((char*)&equipo, sizeof(int));
			lider = i->getLider();
			f.write((char*)&lider, sizeof(bool));
		}	
		f.close();
		return true;
	}else{
		return false;
	}
}

bool profesor::login(string nombre, string clave){
	ifstream f("users.bin", ios::binary);

	char user[256];
	char contra[256];

	if (f.is_open()){
		while(f.read((char*)&user, sizeof(char)*256)) {
			string NUser(user);
			f.read((char*)&contra, sizeof(char)*256);
			string NContra(contra);

			if(NUser.compare(nombre)==0 && NContra.compare(clave)==0){
				return true;
			}

		}
	}
	f.close();
	return false;
}
