// Author: Esneyder Monsalve
// Buildin Height

#include <iostream>
#include <cmath>
#include <cctype>
#include <string>

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
}

int main(int argc, char const *argv[])
{   
    Student Estudiantes[1200];
    // A
    int numeroAlumnosRegalo = 0;

    carga(Estudiantes, &numeroAlumnosRegalo);
    
    return 0;
}

void carga(Student Estudiantes[], int *contador )
{

    do
    {
        cout << "Datos del alumno" << endl;
        cout << "Ingrese el Nombre del Estudiante: ";
        cin >> Estudiantes[*contador].cedula;
        cout << "Ingrese la asignatura de interes: ";
        cin >> Estudiantes[*contador].asignatura;
        cout << "Ingrese el numero de seccion: ";
        cin >> Estudiantes[*contador].numeroSeccion;
        cout << "Caracteristicas del Regalo";
        cout << "Ingrese el genero del regalo (nina/nino): ";
        do
        {
            cin >> Estudiantes[*contador].regalo.genero;

        } while ();
        
        cout << "Edad comprendida: ";
        cout << "Posee envoltura? (S/N): ";

        *contador += 1;
    }while();
}


string toUpper(string str)
{
    int tam = str.length();
    int i = 0;
    char *cadena = new char[tam + 1];
    for (; i < tam; i++)
    {
        cadena[i] = toupper(cadena[i]);
    }
    cadena[i] = '\0';
    
}