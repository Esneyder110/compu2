
// Author: Esneyder Monsalve
// Regalos

#include <iostream>
#include <cmath>
#include <cctype>
#include <string>

#define MAX 1200

using namespace std;

struct Gift
{
    string genero;
    int edad;
    char envoltura;
};

struct Student
{
    int cedula;
    string asignatura;
    int numeroSeccion;
    Gift regalo;
};


void carga(Student*, int*);
char sino();
int porceEnvoltura(Student Estudiantes[], int tam, double *porce);

int main() // int argc, char const *argv[]
{   
  Student Estudiantes[MAX];
  // A
  int numeroAlumnosRegalo = 0;
  // B
  int sinenv;
  double porce;
 


  carga(Estudiantes, &numeroAlumnosRegalo);
  sinenv = porceEnvoltura(Estudiantes, numeroAlumnosRegalo, &porce);
  cout << "El porcentaje de regalos para nina es: " << porce << "\%" << endl;
  cout << "La cantidad de regalos sin envoltura es: " << sinenv << endl;


  return 0;
}

void carga(Student Estudiantes[], int *contador )
{
	char r;
  do
  {

    cout << "Datos del alumno\n";
    cout << "Ingrese la cedula del Estudiante: ";
    cin >> Estudiantes[*contador].cedula;
    cout << "Ingrese la asignatura de interes: ";
    cin >> Estudiantes[*contador].asignatura;
    cout << "Ingrese el numero de seccion: ";
    cin >> Estudiantes[*contador].numeroSeccion;
    cout << "Caracteristicas del Regalo\n";
    cout << "Ingrese el genero del regalo (nina/nino): ";
    cin >> Estudiantes[*contador].regalo.genero;       
    cout << "Edad comprendida: ";
    cin >> Estudiantes[*contador].regalo.edad;
    cout << "Posee envoltura? (S/N)";
		Estudiantes[*contador].regalo.envoltura = sino();

    *contador += 1;
		r = 'N';

		if(*contador < MAX)
		{
			cout << "Desea procesar otro estudiante (S/N)";
			r = sino();
    }

  }while((r == 'S') && (*contador < MAX));    
}

char sino()
{
	char r;
	bool noOk;

	do
	{
		cout << ": ";
		cin >> ws;
		cin >> r;
		r = toupper(r);
		noOk = (r != 'S') && (r != 'N');
		if (noOk)
			cout << "Valor invalido intentelo de nuevo\n";
	}while(noOk);

	return r;
}

int porceEnvoltura(Student Estudiantes[], int tam, double *porce)
{
	int sinenv, ninas;

	for (int i = 0; i < tam; ++i)
	{
		if(Estudiantes[i].regalo.genero == "nina")
		{
			ninas++;
		}

		switch(Estudiantes[i].regalo.envoltura)
		{
			case 'N':
				sinenv++;
				break;
		}

	}

	*porce = (double)ninas / tam * 100.0;

	return sinenv;
}








//string toUpper(string str)
//{
//    int tam = str.length();
//    int i = 0;
//    char *cadena = new char[tam + 1];
//    for (; i < tam; i++)
//    {
//        cadena[i] = toupper(cadena[i]);
//    }
//    cadena[i] = '\0';
//    
//}
