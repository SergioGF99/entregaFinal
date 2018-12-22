#include <cstdlib>
#include <iostream>
#include <list>
#include <stdio.h>
#include <string>
#include <limits>
#include "profesor.h"
#include "agenda.h"
#include "alumno.h"
using namespace std;


int main(){

	string Lusuario, Lclave, archivo;
	int opcion,opt;
	bool logedin;
	string gth;//variable auxiliar
	list<Alumno> alumnos_;
	profesor pr;
	Agenda agenda;
	list<Alumno>::iterator i_aux;
	int busqueda, conf;

	alumnos_.clear();

	do{
		system("clear");
		cout<<"\n\n\n"<<endl;
		cout<<"				**********************"<<endl;
		cout<<"				*   MENU PRINCIPAL   *"<<endl;
		cout<<"				**********************"<<endl;
		cout<<"				[Acceso al sistema]\n"<<endl;
		cout<<"				Iniciar sesion:\n"<<endl;
		cout<<"				>Usuario: ";
		cin>>Lusuario;//profesor1
		cout<<"				>Clave: ";
		cin>>Lclave;//1234
		logedin=pr.login(Lusuario, Lclave);
	}while(!logedin);

	while(logedin){
		system("clear");

		cout<<"\n\n\n"<<endl;
		cout<<"				**********************"<<endl;
		cout<<"				*   MENU PRINCIPAL   *"<<endl;
		cout<<"				**********************\n"<<endl;
		cout<<"				OPCIONES: \n"<<endl;
		cout<<"				0. Cargar base de datos"<<endl;
		cout<<"				1. Nuevo alumno"<<endl;
		cout<<"				2. Buscar alumno "<<endl;
		cout<<"				3. Mostrar todos los alumnos"<<endl;
		cout<<"				4. Modificar alumno"<<endl;
		cout<<"				5. Eliminar alumno "<<endl;
		cout<<"				6. Guardar cambios "<<endl;
		cout<<"				7. Salir "<<endl;
		cout<<"				>>";
		while(!(cin >> opcion)){
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout<<"				[Error]Entrada invalida"<<endl;
			cout<<"				Vuelva a intentarlo: ";
		}
		opt=0;
		switch(opcion){
			case 0:
				system("clear");
				cout<<"\n\n\n"<<endl;
				cout<<"				**********************"<<endl;
				cout<<"				*     CARGAR  BD     *"<<endl;
				cout<<"				**********************\n"<<endl;
				cout<<"				Archivo que se desea cargar\n"<<endl;
				cout<<"				>>";
				cin>>archivo;
				if(pr.cargarBD(alumnos_, archivo)){
					cout<<"\n				[Ok] Base de datos "<<archivo<<" cargada."<<endl;	
				}else{
					cout<<"\n				[Error] "<<archivo<<" no se pudo cargar."<<endl;	
				}
				cout<<"				Presiona ENTER para continuar"<<endl;
				cout<<"				";
				cin.ignore(256,'\n');
				getline(cin, gth);
				break;
			case 1:
				opt=1;
				while(opt==1){
					system("clear");
					cout<<"\n\n\n"<<endl;
					cout<<"				**********************"<<endl;
					cout<<"				*    NUEVO ALUMNO    *"<<endl;
					cout<<"				**********************\n"<<endl;

					agenda.addAlumno(alumnos_);

					cout<<"\n				¿Continuar añadiendo?"<<endl;
					cout<<"				1. Si"<<endl;
					cout<<"				0. No"<<endl;
					cout<<"				>>";
					while(!(cin >> opt)){
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						cout<<"				[Error]Entrada invalida"<<endl;
						cout<<"				Vuelva a intentarlo: ";
					}
				}
				break;

			case 2:
				opt=1;
				while(opt==1){
					string dni="", apellido="";
					system("clear");
					cout<<"\n\n\n"<<endl;
					cout<<"				**********************"<<endl;
					cout<<"				*   BUSCAR  ALUMNO   *"<<endl;
					cout<<"				**********************\n"<<endl;

					cout<<"				¿Por DNI o Apellido?"<<endl;
					cout<<"				1. DNI"<<endl;
					cout<<"				2. Apellido"<<endl;
					cout<<"				>>";
					while(!(cin >> busqueda)){
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						cout<<"				[Error]Entrada invalida"<<endl;
						cout<<"				Vuelva a intentarlo: ";
					}
					if(busqueda==1){
						cout<<"				>>DNI:";
						cin.ignore(256,'\n');
						getline(cin, dni);
						i_aux = agenda.buscarAlumno(alumnos_, dni, apellido);
						if(i_aux == alumnos_.end()){
							cout<<"\n				[Error]No se encontro el alumno"<<endl;
						}else{
							agenda.mostrarAlumno(i_aux);
						}
					}else{
						cout<<"				>>Apellidos:";
						cin.ignore(256,'\n');
						getline(cin, apellido);
						i_aux = agenda.buscarAlumno(alumnos_, dni, apellido);
						if(i_aux == alumnos_.end()){
							cout<<"\n				[Error]No se encontro el alumno"<<endl;
						}else{
							agenda.mostrarAlumno(i_aux);
						}
					}

					cout<<"\n				¿Buscar otro alumno?"<<endl;
					cout<<"				1. Si"<<endl;
					cout<<"				0. No"<<endl;
					cout<<"				>>";
					while(!(cin >> opt)){
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						cout<<"				[Error]Entrada invalida"<<endl;
						cout<<"				Vuelva a intentarlo: ";
					}
				}
				break;

			case 3:
				system("clear");
				cout<<"\n\n\n"<<endl;
				cout<<"				**********************"<<endl;
				cout<<"				*   MOSTRAR  TODOS   *"<<endl;
				cout<<"				**********************\n"<<endl;

				agenda.mostrarTodosAlumnos(alumnos_);

				cout<<"				Presiona ENTER para continuar"<<endl;
				cout<<"				";
				cin.ignore(256,'\n');
				getline(cin, gth);
				break;

			case 4:
				opt=1;
				while(opt==1){
					string dni="", apellido="";
					system("clear");
					cout<<"\n\n\n"<<endl;
					cout<<"				**********************"<<endl;
					cout<<"				*  MODIFICAR ALUMNO  *"<<endl;
					cout<<"				**********************\n"<<endl;

					cout<<"				¿Buscar por DNI o Apellido?"<<endl;
					cout<<"				1. DNI"<<endl;
					cout<<"				2. Apellido"<<endl;
					cout<<"				>>";
					while(!(cin >> busqueda)){
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						cout<<"				[Error]Entrada invalida"<<endl;
						cout<<"				Vuelva a intentarlo: ";
					}
					if(busqueda==1){
						cout<<"				>>DNI:";
						cin.ignore(256,'\n');
						getline(cin, dni);
						i_aux = agenda.buscarAlumno(alumnos_, dni, apellido);
						if(i_aux == alumnos_.end()){
							cout<<"\n				[Error]No se encontro el alumno"<<endl;
						}else{
							agenda.modificarAlumno(i_aux);
						}
					}else{
						cout<<"				>>Apellidos:";
						cin.ignore(256,'\n');
						getline(cin, apellido);
						i_aux = agenda.buscarAlumno(alumnos_, dni, apellido);
						if(i_aux == alumnos_.end()){
							cout<<"\n				[Error]No se encontro el alumno"<<endl;
						}else{
							agenda.modificarAlumno(i_aux);
						}
					}

					cout<<"\n				¿Modificar otro alumno?"<<endl;
					cout<<"				1. Si"<<endl;
					cout<<"				0. No"<<endl;
					cout<<"				>>";
					while(!(cin >> opt)){
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						cout<<"				[Error]Entrada invalida"<<endl;
						cout<<"				Vuelva a intentarlo: ";
					}
				}
				break;

			case 5:
				opt=1;
				while(opt==1){
					string dni="", apellido="";
					system("clear");
					cout<<"\n\n\n"<<endl;
					cout<<"				**********************"<<endl;
					cout<<"				*  ELIMINAR  ALUMNO  *"<<endl;
					cout<<"				**********************\n"<<endl;

					cout<<"				¿Por DNI o Apellido?"<<endl;
					cout<<"				1. DNI"<<endl;
					cout<<"				2. Apellido"<<endl;
					cout<<"				>>";
					while(!(cin >> busqueda)){
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						cout<<"				[Error]Entrada invalida"<<endl;
						cout<<"				Vuelva a intentarlo: ";
					}
					if(busqueda==1){
						cout<<"				>>DNI:";
						cin.ignore(256,'\n');
						getline(cin, dni);
						i_aux = agenda.buscarAlumno(alumnos_, dni, apellido);
						if(i_aux == alumnos_.end()){
							cout<<"\n				[Error]No se encontro el alumno"<<endl;
						}else{
							agenda.mostrarAlumno(i_aux);
							cout<<"\n				Confirmar borrado:"<<endl;
							cout<<"				1. Si"<<endl;
							cout<<"				0. No"<<endl;
							cout<<"				>>";
							while(!(cin >> conf)){
								cin.clear();
								cin.ignore(numeric_limits<streamsize>::max(), '\n');
								cout<<"				[Error]Entrada invalida"<<endl;
								cout<<"				Vuelva a intentarlo: ";
							}

							if(conf == 1){
								agenda.eliminarAlumno(i_aux);
								cout<<"\n				[Ok]Alumno eliminado"<<endl;
							}
						}
					}else{
						cout<<"				>>Apellidos:";
						cin.ignore(256,'\n');
						getline(cin, apellido);
						i_aux = agenda.buscarAlumno(alumnos_, dni, apellido);
						if(i_aux == alumnos_.end()){
							cout<<"\n				[Error]No se encontro el alumno"<<endl;
						}else{
							agenda.mostrarAlumno(i_aux);
							cout<<"\n				Confirmar borrado:"<<endl;
							cout<<"				1. Si"<<endl;
							cout<<"				0. No"<<endl;
							cout<<"				>>";
							while(!(cin >> conf)){
								cin.clear();
								cin.ignore(numeric_limits<streamsize>::max(), '\n');
								cout<<"				[Error]Entrada invalida"<<endl;
								cout<<"				Vuelva a intentarlo: ";
							}

							if(conf == 1){
								agenda.eliminarAlumno(i_aux);
								cout<<"\n				[Ok]Alumno eliminado"<<endl;
							}
						}
					}

					cout<<"\n				¿Eliminar otro alumno?"<<endl;
					cout<<"				1. Si"<<endl;
					cout<<"				0. No"<<endl;
					cout<<"				>>";
					while(!(cin >> opt)){
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						cout<<"				[Error]Entrada invalida"<<endl;
						cout<<"				Vuelva a intentarlo: ";
					}
				}
				break;
			case 6:
				system("clear");
				cout<<"\n\n\n"<<endl;
				cout<<"				**********************"<<endl;
				cout<<"				*     GUARDAR BD     *"<<endl;
				cout<<"				**********************\n"<<endl;
				cout<<"				Archivo que se desea guardar\n"<<endl;
				cout<<"				>>";
				cin>>archivo;

				if(pr.guardarBD(alumnos_, archivo)){
					cout<<"				[Ok] Base de datos "<<archivo<<" guardada."<<endl;	
				}else{
					cout<<"				[Error] "<<archivo<<" no se pudo guardar."<<endl;
				}

				cout<<"				Presiona ENTER para continuar"<<endl;
				cout<<"				";
				cin.ignore(256,'\n');
				getline(cin, gth);
				break;

			case 7:
				logedin=false;
				break;

			default:
				break;
		}
	}
	return 0;
}