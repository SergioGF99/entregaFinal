#include <string>
#ifndef ALUMNO_H
#define ALUMNO_H

using namespace std;

class Alumno{
private:
	string DNI_;
	string nombre_;
	string apellidos_;
	string direccion_;
	string correo_;
	string curso_;
	string telefono_;
	int equipo_;
	bool lider_;
public:
	inline Alumno(string DNI, string nombre, string apellidos, string direccion, string correo, string curso, string telefono, int equipo=0, bool lider="FALSE"){DNI_=DNI; nombre_=nombre; apellidos_=apellidos; direccion_=direccion; correo_=correo; curso_=curso; telefono_=telefono; equipo_=equipo; lider_=lider;}

	inline void setDNI(string DNI){DNI_=DNI;}
	inline string getDNI(){return DNI_;}

	inline void setNombre(string nombre){nombre_=nombre;}
	inline string getNombre(){return nombre_;}

	inline void setApellidos(string apellidos){apellidos_=apellidos;}
	inline string getApellidos(){return apellidos_;}

	inline void setDireccion(string direccion){direccion_=direccion;}
	inline string getDireccion(){return direccion_;}

	inline void setCorreo(string correo){correo_=correo;}
	inline string getCorreo(){return correo_;}

	inline void setCurso(string curso){curso_=curso;}
	inline string getCurso(){return curso_;}

	inline void setTelefono(string telefono){telefono_=telefono;}
	inline string getTelefono(){return telefono_;}

	inline void setEquipo(int equipo){equipo_=equipo;}
	inline int getEquipo(){return equipo_;}

	inline void setLider(bool lider){lider_=lider;}
	inline bool getLider(){return lider_;}
};

#endif