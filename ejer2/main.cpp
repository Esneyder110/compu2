
// Author: Esneyder Monsalve
// Regalos

#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <cstring>
#include <cstdio>

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


void carga(Student [], int*);
char sino();
int porceEnvoltura(Student [], int tam, double *porce);
void regalosIntervalos(Student Estudiantes[], int tam);	
int buscarCedula(Student Estudiantes[], int tam, int id, string *materia); 
string formato(string materia, int seccion);
void toUpper(string *str);

int main() // int argc, char const *argv[]
{   
  Student Estudiantes[MAX];
  // A
  int numeroAlumnosRegalo = 0;
  // B
  int sinenv = 0;
  double porce;
  // C
  int cedula;
  string materiaInteres;
  int seccion;


  // A
  carga(Estudiantes, &numeroAlumnosRegalo);
  
  // B
  sinenv = porceEnvoltura(Estudiantes, numeroAlumnosRegalo, &porce);
  cout << "\n\nEl porcentaje de regalos para nina es: " << porce << "\%" << endl;
  cout << "La cantidad de regalos sin envoltura es: " << sinenv << endl;

  // C
  regalosIntervalos(Estudiantes, numeroAlumnosRegalo);

	// D

	cout << "\n\n" << setw(40) << "BUSQUEDA" << "\n\n"
	<< "Ingrese el numero de cedula a consultar: ";
	cin >> cedula;
	
	printf( "%s\n",
		((seccion = buscarCedula(Estudiantes, numeroAlumnosRegalo, cedula, &materiaInteres)) ==  -1) ?
			"No se ha encontrado la cedula registra": 
			formato(materiaInteres, seccion).c_str()
	
	);
	
	// seccion = buscarCedula(Estudiantes, numeroAlumnosRegalo, cedula, &materiaInteres);
	
	// if (seccion != -1)
	// 	printf("La Materia de interes es : %s en la seccion: %d\n", materiaInteres.c_str(), seccion);
		

	// if (seccion != -1)
	// 	printf("La Materia de interes es : %s en la seccion: %d\n", materiaInteres.c_str(), seccion);
	// else
	// 	printf("No se encontro\n");


  return 0;
}


void carga(Student Estudiantes[], int *contador )
{
	char r;
	bool ok;
  do
  {

    cout << "Datos del alumno\n";
    cout << "Ingrese la cedula del Estudiante: ";
    cin >> ws;
    cin >> Estudiantes[*contador].cedula;
    cout << "Ingrese la asignatura de interes: ";
    cin >> ws;
    getline(cin, Estudiantes[*contador].asignatura);
    toUpper(&Estudiantes[*contador].asignatura);
    cout << "Ingrese el numero de seccion: ";
    cin >> Estudiantes[*contador].numeroSeccion;
    cout << "Caracteristicas del Regalo\n";
    do
    {
	    cout << "Ingrese el genero del regalo (nina/nino): ";
	    cin >> ws;
	    getline(cin, Estudiantes[*contador].regalo.genero);
	    toUpper(&Estudiantes[*contador].regalo.genero);
			ok = (Estudiantes[*contador].regalo.genero == "NINA")||(Estudiantes[*contador].regalo.genero == "NINO");
    	if (!ok)
    	{
    		cout << "Valor invalido intentelo otra vez" << endl;
    	}
    }while(!ok);


  	cout << "Edad comprendida: ";
  	cin >> Estudiantes[*contador].regalo.edad;
  	Estudiantes[*contador].regalo.edad = fabs(Estudiantes[*contador].regalo.edad);
   
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
	int sinenv = 0, ninas = 0;

	for (int i = 0; i < tam; ++i)
	{
		if(Estudiantes[i].regalo.genero == "NINA")
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

void regalosIntervalos(Student Estudiantes[], int tam)
{
	int trescinco, seisnueve, nuevemayor;
	int edad;
	int intervalosEdad[3] = {0};
	int espaciadoP = 40, espaciadoS = 13;
	int total = 0;
	int a;
	string nombreIntervalo[3] = {"3 a 5", "6 a 9", "9 en adelante" };
	
	trescinco = seisnueve = nuevemayor = 0;


	for (int i = 0; i < tam; ++i)
	{
		if (!strcmp(Estudiantes[i].regalo.genero.c_str(), "NINO"))
		{
			edad = Estudiantes[i].regalo.edad;
			if ((edad >=3) && (edad <= 5))
			{
				intervalosEdad[0] += 1; // [tres - cinco]
			}
			else if ((edad >= 6) && (edad <= 9))
			{
				intervalosEdad[1] += 1; // [seis - nueve]
			}else if (edad > 9)
			{
				intervalosEdad[2] += 1; // (nueve - mayor)
			}
		}
	}

	a = strlen("GENERO: NINOS");

	cout << "\n\n" <<  setw(((espaciadoP + espaciadoS )/ 2) + a / 2) << "GENERO: NINOS" << endl;
	cout << setw(espaciadoS) << "EDADES" << setw(espaciadoP) << "CANTIDAD REGALOS" << endl;

	for (int i = 0; i < 3; ++i)
	{
		cout << setw(espaciadoS) << nombreIntervalo[i] << setw(espaciadoP) << intervalosEdad[i] << endl;
		total += intervalosEdad[i];
	}

	// cout << setw(espaciadoS) <<  << setw(espaciadoP) << trescinco << endl;
	// cout << setw(espaciadoS) << "6 a 9" << setw(espaciadoP) << seisnueve << endl;
	// cout << setw(espaciadoS) << "9 en adelante" << setw(espaciadoP) << nuevemayor << endl;

	cout << setfill('_') << setw(espaciadoP + espaciadoS)  << '_' << endl;
	cout << setfill(' ') << setw(espaciadoP + espaciadoS) << "TOTAL = " << total << endl;
}

int buscarCedula(Student Estudiantes[], int tam, int id, string *materia)
{
	for (int i = 0; i < tam; ++i)
	{
		if (Estudiantes[i].cedula == id)
		{
			*materia = (Estudiantes[i].asignatura);
			return Estudiantes[i].numeroSeccion;
		}
	}
	return -1;
}

string formato(string materia, int seccion)
{
	
	string cadena = "La Materia de interes es : ";
	char buffer[10];
		
	cadena.append(materia);
	cadena.append(" en la seccion: ");
	itoa (seccion,buffer,10);
	cadena.append(buffer);

	return cadena;
}


void toUpper(string *str)
{
   int tam = str->length();
   int i = 0;
   char *cadena = new char[tam + 1];
   strcpy(cadena, str->c_str());
   for (; i < tam; i++)
   {
       cadena[i] = toupper(cadena[i]);
   }
   *str = cadena;
}