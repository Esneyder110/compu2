#include <iostream>
#include <cstring>
#include <cmath>
#include <cctype>

using namespace std;

class BARCO
{
public:
	void cargar();
	void mensaje(int);
private:
	char nombre[15];
	char estado[15];
};


void BARCO::cargar()
{
	int r;

	cout << "Ingrese el nombre del barco: ";
	cin >> ws;
	cin >> nombre;
	do
	{
		cout << "Ingrese el estado del barco:" << endl;
		cout << "1-)Navegando\n2-)Anclado\nRespuesta: ";
		cin >> r;
		switch(r)
		{
			case 1:
				strcpy(estado, "navegando");
			break;
			case 2:
				strcpy(estado, "anclado");
			break;
			default:
				cout << "Error Intentelo otra vez" << endl;
		}		
	} while ((r != 1) && (r != 2));
}

void BARCO::mensaje(int tripulantes)
{
	if (!strcmp(estado, "navegando"))
	{
		cout << "El  barco " << nombre << " se encuentra en peligro con " << tripulantes << "tripulantes" << endl;
	}
}


class CRUCERO:public BARCO
{
public:
	void cargar();
	void mensaje();
private:
	int numeroTuristas;
};

void CRUCERO::cargar()
{
	BARCO::cargar();
	cout << "Ingrese el numero de turistas: ";
	cin >> numeroTuristas;
	numeroTuristas = fabs(numeroTuristas);
}

void CRUCERO::mensaje()
{
	BARCO::mensaje(numeroTuristas);
}

class PORTA:public BARCO
{
public:
	void cargar();
	void mensaje();
private:
	int numeroAviones;
	int cantidadTripulantes;

};

void PORTA::cargar()
{
	BARCO::cargar();
	cout << "Ingrese el numero de aviones: ";
	cin >> numeroAviones;
	numeroAviones = fabs(numeroAviones);
	cout << "Ingrese cantidad de tripulantes: ";
	cin >> cantidadTripulantes;
	cantidadTripulantes = fabs(cantidadTripulantes);
}

void PORTA::mensaje()
{
	BARCO::mensaje(cantidadTripulantes);
}

class PESQUERO:public BARCO
{
public:
	void cargar();
	void mensaje();
private:
	int numeroPescadores;
	char clasificacion[15];
};

void PESQUERO::cargar()
{
	int r;
	bool ok;

	BARCO::cargar();
	cout << "Ingrese el numero de pescadores: ";
	cin >> numeroPescadores;
	numeroPescadores = fabs(numeroPescadores);
	do
	{
		cout << "Ingrese la clasificacion del barco:\n\n";
		cout << "1-)Atunero\n"
				 << "2-)Palangrero\n"
				 << "3-)Cerquero" << endl;
		cin >> r;

		switch(r)
		{
			case 1:
				strcpy(clasificacion, "Atunero");
				break;
			case 2:
				strcpy(clasificacion, "Palangrero");
				break;
			case 3:
				strcpy(clasificacion, "Cerquero");
				break;
			default:
				cout << "Error Intentelo otra vez" << endl;
		}

		ok = (r != 1) && (r != 2) && (r != 3);
	} while (ok);
}

void PESQUERO::mensaje()
{
	BARCO::mensaje(numeroPescadores);
}

int main()
{
	const int N = 10;
	CRUCERO crucero[N];
	PORTA portaAvion[N];
	PESQUERO pesquero[N];
	char r; // repuesta S/N
	int op; // opcion de menu
	int ncr = 0; // cruceros procesados
	int npa = 0; // portaviones procesados
	int npq = 0; // pesqueros procesados

	do
	{
		cout << "Cargar Datos\n\n";
		cout << "1-) Crucero\n"
				 << "2-) Porta Aviones\n"
				 << "3-) Pesquero\n"
				 << "4-) Salir" << endl;
		cin >> op;

		switch(op)
		{
			case 1:
				ncr = 0;
				do
				{
					crucero[ncr].cargar();
					ncr++;
					if (ncr < N)
					{
						cout << "Desea Procesar otro crucero?[S/N]: ";
						cin >> r;
						r = toupper(r);
					}
				}while(r == 'S' && ncr < N);
				break;
			case 2:
				npa = 0;
				do
				{
					portaAvion[npa].cargar();
					npa++;
					if (npa < N)
					{
						cout << "Desea Procesar otro porta aviones?[S/N]: ";
						cin >> r;
						r = toupper(r);
					}
				}while(r == 'S' && npa < N);
				break;
			case 3:
				npq = 0;
				do
				{
					crucero[npq].cargar();
					npq++;
					if (npq < N)
					{
						cout << "Desea Procesar otro pesquero?[S/N]: ";
						cin >> r;
						r = toupper(r);
					}
				}while(r == 'S' && npq < N);
				break;
			case 4:
				cout << "Saliendo..." << endl;
				break;
			default:
				cout << "Error Intentelo otra vez" << endl;
		}
	} while (op != 4);

	cout << "Existe algun tifon?[S/N]: ";
	cin >> ws;
	cin >> r;


	if (toupper(r) == 'S')
	{
		cout << "ALERTA TIFON!!!" << endl;
		for (int i = 0; i < ncr; ++i)
		{
			crucero[i].mensaje();
		}
		for (int i = 0; i < npa; ++i)
		{
			portaAvion[i].mensaje();
		}
		for (int i = 0; i < npq; ++i)
		{
			pesquero[i].mensaje();
		}
	}else
	{
		cout << "No hay tifon" << endl;
	}
	return 0;
}