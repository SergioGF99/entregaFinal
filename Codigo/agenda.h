//ESTO VA A ESTAR EN EL MAIN DE AGENDA

#include <string>
#include <cstdio>
#include <cstdlib>
#include "alumno.h"
#include <list>
#ifndef AGENDA_H
#define AGENDA_H

using namespace std;

class Agenda{
	private:
		list<Alumno> alumnos_;

	public:
		bool addAlumno(list<Alumno>& alumnos_);
		void mostrarAlumno(list<Alumno>::iterator &i);
		list<Alumno>::iterator buscarAlumno(list<Alumno>& alumnos_, string DNI, string apellidos);
		void eliminarAlumno(list<Alumno>::iterator &i);
		void mostrarTodosAlumnos(list<Alumno>& alumnos_);//falta mostrar por orden!!
		bool modificarAlumno(list<Alumno>::iterator &i);

		bool comprobarDni(string DNI);//comprueba que el dni pasado no existe en la lista
		bool comprobarAlumnos();//comprueba si el numero de alumnos s 150
		bool prueba(string DNI);
		bool prueba2(string telefono);
		string convierte_a_mayuscula(string& DNI);
};

#endif