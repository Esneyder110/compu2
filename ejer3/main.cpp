#include <iostream>
#include <iomanip>

using namespace std;


class Estudiante
{
public:
//	Estudiante();
//	~Estudiante();
	void cargar();
	void promedio();
	void listar();

private:
	char nombre[10];
	char materia[12];
	float notas[3]; // 0 - 9
	float pro;

};


int main(int argc, char const *argv[])
{
	int tam = 5;
	Estudiante alumno[tam];


	for (int i = 0; i < tam; ++i)
	{
		alumno[i].cargar();
	}

	for (int i = 0; i < tam; ++i)
	{
		alumno[i].promedio();
	}

	cout << left << setw(12) << "Nombre" << setw(13) << "Materia" << right << setw(9) << "Promedio" << endl;
	
	for (int i = 0; i < tam; ++i)
	{
		alumno[i].listar();
	}
	return 0;
}

void Estudiante::cargar()
{
	bool ok;
	cout << "Ingrese el nombre del Estudiante: ";
	cin >> ws;
	cin.getline(nombre, 10, '\n');
	cout << "Ingrese el nombre de la materia: ";
	cin >> ws;
	cin.getline(materia, 12, '\n');

	for (int i = 0; i < 3; ++i)
	{
		do
		{
			cout << "Ingrese la nota del corte " << i+1 << ": ";
			cin >> notas[i];
			ok = (notas[i] <=9) && (notas[i] >= 0);
		
			if (!ok)
			{
				cout << "La nota es invalida, rango [0-9]" << endl;
			}

		}while(!ok);
	}
}

void Estudiante::promedio()
{
	float acum = 0;

	for (int i = 0; i < 3; ++i)
	{
		acum += notas[i];
	}

	pro = acum / 3.0;
}

void Estudiante::listar()
{
	cout << setw(12) << left << nombre << setw(13) << materia << right << setw(9) << setprecision(2) << fixed << pro << endl;
}
