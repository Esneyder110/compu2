#include <iostream>
#include <string>


using namespace std;

class Persona
{
public:
	// Persona();
	// ~Persona();
	void cargar_p();
	void mostrar_p();
private: 
	string nombre;
};


void Persona::cargar_p()
{
	cout << "Ingrese el nombre: ";
	cin >> ws;
	cin >> nombre;
}

void Persona::mostrar_p()
{
	cout << "Nombre: " << nombre << endl;
}


class Estudiante:public Persona
{
public:
	// Estudiante();
	// ~Estudiante();
	void cargar_e();
	void mostrar_e();

private:
	char especialidad[12];
	double indice;
};

void Estudiante::cargar_e()
{
	cargar_p();
	cout << "Ingrese la especialidad: ";
	cin >> ws;
	cin >> especialidad;
	cout << "Ingrese el indice: ";
	cin >> indice;
}

void Estudiante::mostrar_e()
{
	mostrar_p();
	cout << "Especialidad: " << especialidad << endl;
	cout << "Indice: " << indice << endl;
}

class Profesor:public Persona
{
public:
	// Profesor();
	// ~Profesor();
	void cargar_pro();
	void mostrar_pro();
private:

	string categoria;
	double sueldo;
};

void Profesor::cargar_pro()
{
	cargar_p();
	cout << "Ingrese categoria: ";
	cin >> ws;
	cin >> categoria;
	cout << "Ingrese sueldo: ";
	cin >> sueldo;
}

void Profesor::mostrar_pro()
{
	mostrar_p();
	cout << "Categoria: " << categoria << endl;;
	cout << "Sueldo: " << sueldo << endl;
}




int main()
{
	int ce, op;
	char r;
	Profesor pro[100];
	Estudiante unet[100];
	
	do
	{
		cout << "MENU\n1-) Profesores\n2-) Estudiantes\n0-) Salir" << endl;
		cout << ": ";
		cin >> op;
		ce = 0;

		switch(op)
		{
			case 1:
				
				do
				{
					pro[ce].cargar_pro();
					ce++;
					if(ce < 100)
					{
						cout << "Otro Profesor a procesar?[S/N]: ";
						cin >> ws;
						cin >> r;
						r = toupper(r);
					}
				} while (r == 'S' && ce < 100);
				cout << "\n\nListado de Profesores Procesados" << endl;
				
				for (int i = 0; i < ce; ++i)
				{
					pro[i].mostrar_pro();
					cout << endl;
				}
				cout << endl;
				break;
			case 2:
				
				do
				{
					unet[ce].cargar_e();
					ce++;
					if(ce < 100)
					{
						cout << "Otro Estudiante a procesar?[S/N]: ";
						cin >> ws;
						cin >> r;
						r = toupper(r);
					}
				} while (r == 'S' && ce < 100);
				cout << "\n\nListado de Estudiantes Procesados" << endl;
				
				for (int i = 0; i < ce; ++i)
				{
					unet[i].mostrar_e();
					cout << endl;
				}
				cout << endl;
				break;
			case 0:
				cout << "Saliendo...bye ;)" ;
				break;
			default:
			cout << "Error Opcion Invalida" << endl;
		}
	} while (op != 0);
	return 0;
}