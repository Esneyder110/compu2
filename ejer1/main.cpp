// Author: Esneyder Monsalve
// Buildin Height

#include <iostream>
#include <cmath>
#include <cctype>

using namespace std;

double methodOne(double*, double*);
double readPossitive();
double methodTwo(double*, double*, double*);
double toRadian(double);


int main()
{
	char option;
	bool optionNoOk;
	double height;

	// Method One
	double base, quantity;

	// Method Two
	double horizontalDistance, eyeHeight, alpha;


	do
	{
		cout << "A-) Metodo por bloques repetitivos \n";
		cout << "B-) Metodo por trigonometria\n";
		cin >> ws;
		cin >> option;
		option = toupper(option);

		optionNoOk = ((option != 'A') && (option != 'B'));
		
		if (optionNoOk)
			cout << "Opcion invalida\n";	
		
	}while( optionNoOk );

	if (option == 'A')
	{
		cout << "Ingrese el tamano de la unidad base (bloque/nivel)";
		base = readPossitive();
		cout << "Ingrese la cantidad de (bloque/niveles)";
		quantity = readPossitive();

	
		height = methodOne(&base, &quantity);
	}
	else
	{
		cout << "Ingrese la distancia horizontal";
		horizontalDistance = readPossitive();
		cout << "Ingrese la altura de los ojos";
		eyeHeight = readPossitive();
		cout << "Ingrese el angulo de mirada";
		alpha = readPossitive();
		
		height = methodTwo(&horizontalDistance, &eyeHeight, &alpha);
	}
	cout << "La altura del edificio es aprox. " << height << endl;

	return 0;
}

double methodOne(double* base, double* quantity)
{
	return (*base * *quantity);
}


double readPossitive()
{
	string n;
	double num;
	bool ok;

	do
	{
		cout << ": ";
		cin >> ws;
		// cin >> n;
		getline(cin, n);
		try
		{
			num = stod(n);
			ok = true;
		}catch ( const exception e )
		{
			cout << "Error Intentelo de nuevo" << endl;
			ok = false;
		}
	}while(!ok);

	return  fabs(num);
}


double methodTwo(double* hd, double* eh, double* alpha )
{
	*alpha = toRadian(*alpha);

	return (tan(*alpha) * *hd) + *eh;
}

double toRadian(double alpha)
{
	return alpha * M_PI / 180;
}

