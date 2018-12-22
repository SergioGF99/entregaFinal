#ifndef PROFESOR_H
#define PROFESOR_H
#include "alumno.h"

using namespace std;

class profesor{

	private:
		string rol_;
		string nombre_;

	public:
		bool cargarBD(list<Alumno>& alumnos_, string archivo);
		bool guardarBD(list<Alumno> alumnos_, string archivo);
		inline void setRol(string rol){rol_=rol;}
		inline string getRol(){return rol_;}
		bool login(string nombre,string clave);

};

#endif