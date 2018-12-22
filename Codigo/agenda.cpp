#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <list>
#include <limits>
#include <cstdio>
#include <cstdlib>
#include "alumno.h"
#include "agenda.h"

using namespace std;

bool Agenda::addAlumno(list<Alumno>& alumnos_){
	Agenda a;
	string DNI;
	string nombre;
	string apellidos;
	string direccion;
	string correo;
	string curso;
	string telefono;
	int equipo;
	bool lider;

	cout<<"				[Creando alumno]\n";
	cout<<"				Introduce DNI: ";
	cin>>DNI;
	convierte_a_mayuscula(DNI);
		if(prueba(DNI)==false){
		cout<<"				EL DNI que ha introducido no es valido."<<endl;
		cout<<"				Recuerde: 8 digitos y 1 letra." <<endl;
		return false;
		}
	cout<<"				Introduce Nombre: ";
	cin>>nombre;
	cout<<"				Introduce Apellidos: ";
	cin.ignore(256,'\n');
	getline(cin, apellidos);
	cout<<"				Introduce Direccion: ";
	getline(cin, direccion);
	cout<<"				Introduce Correo: ";
	cin>>correo;
	cout<<"				Introduce Curso: "<<endl;
	cout<<"				Por ejemplo: primero, segundo..."<<endl;
	cout<<"				>>";
	cin>>curso;
	cout<<"				Introduce Telefono: ";
	cin>>telefono;
		if(prueba2(telefono)==false){
		cout<<"				EL telefono que ha introducido no es valido."<<endl;
		cout<<"				Recuerde: 9 digitos." <<endl;
		return false;
		}
	cout<<"				Introduce Nº Equipo: ";
	cin>>equipo;
	cout<<"				¿Es lider?"<<endl;
	cout<<"				1. Si"<<endl;
	cout<<"				0. No"<<endl;
	cout<<"				>>";
	while(!(cin >> lider)){
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout<<"				[Error]Entrada invalida"<<endl;
		cout<<"				Vuelva a intentarlo: ";
	}
	if(comprobarDni(DNI)){
		cout<<"				[Error] El DNI introducido ya existe"<<endl;
		return false;
	}else{
		system("clear");
		cout<<"\n\n				[Alumno creado]"<<endl;
		cout<<"				[Datos]"<<endl;
		cout<<"				DNI: "<<DNI<<endl;
		cout<<"				Nombre: "<<nombre<<endl;
		cout<<"				Apellidos: "<<apellidos<<endl;
		cout<<"				Direccion: "<<direccion<<endl;
		cout<<"				Correo: "<<correo<<endl;
		cout<<"				Curso: "<<curso<<endl;
		cout<<"				Telefono: "<<telefono<<endl;
		cout<<"				Nº Equipo: "<<equipo<<endl;
		cout<<"				Lider: "<<lider<<endl;
		cout<<endl;

		Alumno a1(DNI, nombre, apellidos, direccion, correo, curso, telefono, equipo, lider);	
		alumnos_.push_back(a1);
		return true;
	}
}


void Agenda::mostrarAlumno(list<Alumno>::iterator &i){
	system("clear");
	cout<<"\n\n				[Alumno "<<i->getNombre()<<"]\n";;
	cout<<" 				 DNI: "<<i->getDNI()<<endl;
	cout<<" 				 Nombre: "<<i->getNombre()<<endl;
	cout<<" 				 Apellidos: "<<i->getApellidos()<<endl;
	cout<<" 				 Direccion: "<<i->getDireccion()<<endl;
	cout<<" 				 Correo: "<<i->getCorreo()<<endl;
	cout<<" 				 Curso: "<<i->getCurso()<<endl;
	cout<<" 				 Telefono: "<<i->getTelefono()<<endl;
	cout<<" 				 Equipo: "<<i->getEquipo()<<endl;
	cout<<" 				 Lider: "<<i->getLider()<<endl;
	cout<<"\n";
}

void Agenda::mostrarTodosAlumnos(list<Alumno>& alumnos_){
	list<Alumno>::iterator i;
	int c=0;
	for(i=alumnos_.begin(); i!=alumnos_.end(); i++){
		cout<<"				[Alumno "<<c<<"]\n";
		cout<<" 				 DNI: "<<i->getDNI()<<endl;
		cout<<" 				 Nombre: "<<i->getNombre()<<endl;
		cout<<" 				 Apellidos: "<<i->getApellidos()<<endl;
		cout<<" 				 Direccion: "<<i->getDireccion()<<endl;
		cout<<" 				 Correo: "<<i->getCorreo()<<endl;
		cout<<" 				 Curso: "<<i->getCurso()<<endl;
		cout<<" 				 Telefono: "<<i->getTelefono()<<endl;
		cout<<" 				 Equipo: "<<i->getEquipo()<<endl;
		cout<<" 				 Lider: "<<i->getLider()<<endl;
		cout<<"\n";
		c++;
	}
}

list<Alumno>::iterator Agenda::buscarAlumno(list<Alumno>& alumnos_, string DNI, string apellidos){	
	
	list<Alumno>::iterator i;						
	while(!alumnos_.empty()){

		list<Alumno>::iterator i_aux;
		int contador=0;
		string dni_aux;

		if(apellidos.compare("")==0){
			for(i=alumnos_.begin(); i!=alumnos_.end(); i++){
				if(i->getDNI().compare(DNI)==0){
					return i;				
				}
			}
			i=alumnos_.end();
			return i;	
		}

		if(DNI.compare("")==0){												
			for(i=alumnos_.begin(); i!=alumnos_.end(); i++){
				if(i->getApellidos().compare(apellidos)==0){		
					contador++;
					i_aux=i;
				}
			}
		}
		if(contador == 1){
			return i_aux;
		}else{
			cin.ignore();
			cout<<"				[Error]Se encontraron 2 o más registros"<<endl;
			cout<<"				[Error]Introduzca su DNI:"<<endl;
			cout<<"				>>";
			cin.ignore(256,'\n');
			getline(cin, dni_aux);

			for(i=alumnos_.begin(); i!=alumnos_.end(); i++){
				if(i->getDNI().compare(dni_aux)==0){
					return i;						
				}
			}
			i=alumnos_.end();
			return i;
		}
	}
	i=alumnos_.end();
	return i;
}

void Agenda::eliminarAlumno(list<Alumno>::iterator &i){
	alumnos_.erase(i);
}

bool Agenda::modificarAlumno(list<Alumno>::iterator &i){

	string DNI;
	string nombre;
	string apellidos;
	string direccion;
	string correo;
	string curso;
	string telefono;
	int equipo;
	bool lider;
	int opt;

	system("clear");
	cout<<"\n\n\n				[MODIFICANDO ALUMNO]\n";
	cout<<"				[Datos actuales] "<<endl;
	cout<<"				DNI: "<<i->getDNI()<<endl;
	cout<<"				Nombre: "<<i->getNombre()<<endl;
	cout<<"				Apellidos: "<<i->getApellidos()<<endl;
	cout<<"				Direccion: "<<i->getDireccion()<<endl;
	cout<<"				Correo: "<<i->getCorreo()<<endl;
	cout<<"				Curso: "<<i->getCurso()<<endl;
	cout<<"				Telefono: "<<i->getTelefono()<<endl;
	cout<<"				Equipo: "<<i->getEquipo()<<endl;
	cout<<"				Lider: "<<i->getLider()<<endl;
	cout<<endl;
	cout<<"				¿Desea modificar?"<<endl;
	cout<<"				1. Si"<<endl;
	cout<<"				0. No"<<endl;
	cout<<"				>>";
	while(!(cin >> opt)){
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout<<"				[Error]Entrada invalida"<<endl;
		cout<<"				Vuelva a intentarlo: ";
	}
	if(opt==1){
		system("clear");
		cout<<"\n\n\n				[Modificando alumno]\n";
		cout<<"				DNI actual: "<<i->getDNI()<<endl;
		cout<<"				Introduce DNI: ";
		cin>>DNI;
		cout<<"				Nombre actual: "<<i->getNombre()<<endl;
		cout<<"				Introduce Nombre: ";
		cin>>nombre;
		cout<<"				Apellidos actuales: "<<i->getApellidos()<<endl;
		cout<<"				Introduce Apellidos: ";
		cin.ignore(256,'\n');
		getline(cin, apellidos);
		cout<<"				Direccion actual: "<<i->getDireccion()<<endl;
		cout<<"				Introduce Direccion: ";
		getline(cin, direccion);
		cout<<"				Correo actual: "<<i->getCorreo()<<endl;
		cout<<"				Introduce Correo: ";
		cin>>correo;
		cout<<"				Curso actual: "<<i->getCurso()<<endl;
		cout<<"				Introduce Curso: "<<endl;
		cout<<"				Por ejemplo: primero, segundo..."<<endl;
		cout<<"				>>";
		cin>>curso;
		cout<<"				Telefono actual: "<<i->getTelefono()<<endl;
		cout<<"				Introduce Telefono: ";
		cin>>telefono;
		cout<<"				Equipo actual: "<<i->getEquipo()<<endl;
		cout<<"				Introduce Nº Equipo: ";
		cin>>equipo;
		cout<<"				Lider actual: "<<i->getLider()<<endl;
		cout<<"				¿Es lider?"<<endl;
		cout<<"				1. Si"<<endl;
		cout<<"				0. No"<<endl;
		cout<<"				>>";
		while(!(cin >> lider)){
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout<<"				[Error]Entrada invalida"<<endl;
			cout<<"				Vuelva a intentarlo: ";
		}
		if(comprobarDni(DNI)){
			cout<<"				[Error] El DNI introducido ya existe"<<endl;
			return false;
		}else{
			system("clear");
			cout<<"\n\n				[Datos introducidos]"<<endl;
			cout<<"				DNI: "<<DNI<<endl;
			cout<<"				Nombre: "<<nombre<<endl;
			cout<<"				Apellidos: "<<apellidos<<endl;
			cout<<"				Direccion: "<<direccion<<endl;
			cout<<"				Correo: "<<correo<<endl;
			cout<<"				Curso: "<<curso<<endl;
			cout<<"				Telefono: "<<telefono<<endl;
			cout<<"				Nº Equipo: "<<equipo<<endl;
			cout<<"				Lider: "<<lider<<endl;
			cout<<endl;
			cout<<"				¿Confirmar cambios?"<<endl;
			cout<<"				1. Si"<<endl;
			cout<<"				0. No"<<endl;
			cout<<"				>>";
			while(!(cin >> opt)){
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout<<"				[Error]Entrada invalida"<<endl;
				cout<<"				Vuelva a intentarlo: ";
			}
			if(opt == 1){
				i->setDNI(DNI);
				i->setNombre(nombre);
				i->setApellidos(apellidos);
				i->setDireccion(direccion);
				i->setCorreo(correo);
				i->setCurso(curso);
				i->setTelefono(telefono);
				i->setEquipo(equipo);
				i->setLider(lider);
				return true;
			}else{
				return false;
			}
			
		}
	}
	

}

bool Agenda::comprobarDni(string DNI){
	list<Alumno>::iterator i;

	for(i=alumnos_.begin(); i!=alumnos_.end(); i++){
		if(i->getDNI().compare(DNI)==true){							
			return true;						
		}
	}
	return false;
}


bool Agenda::prueba(string DNI){
   if (DNI.size()!=9)return false;
   if (!isalpha(DNI[DNI.size()-1]) ) return false;

   char letra=DNI.back();
   DNI.pop_back();

   int number=stoi(DNI);
   string letras="TRWAGMYFPDXBNJZSQVHLCKE";
   if (  letras[ number%letras.size()] ==toupper(letra)){
       return true;
   }
   else return false;
}

bool Agenda::prueba2(string telefono){
	string ndigitos="1234567890";
	int t=telefono.size();
	if(t!=9){
		return false;
	}
	for(int i=0; i<t; i++){
		if(i<9){
			if(!isdigit(telefono[i])){
				return false;
			}else{
				if(!isalpha(telefono[i])){
					return true;
				}
			}
		}
	}
	return true;
}

string Agenda::convierte_a_mayuscula(string& DNI){
	for(unsigned int i=0; i<DNI.size(); i++){
		DNI[i]=toupper(DNI[i]);
	}
	return DNI;
}
/*
bool Agenda::comprobarDni(string DNI){
	list<Alumno>::iterator i;

	for(i=alumnos_.begin(); i!=alumnos_.end(); i++){
		if(i->getDNI().compare(DNI)==true){							
			return true;						
		}else{
			return false;
		}
	}
}
*/