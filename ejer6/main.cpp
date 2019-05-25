// Integrantes
// Emmy Perez
// Esneyder Monsalve
// Diego Salazar
// Seccion 2

#include <iostream>
#include <string.h>

using namespace std;

class Dispositivo
{
public:
	
	void cargar();
	void mostrar();
	void contar_s(int &);
	void buscar(double &);
private:
	char marca[15];
	char modelo[15];
	double costoAdquisicion;
	double porcentajeGananciaVenta;
	char fechaDespacho[11];

};

void Dispositivo::cargar()
{
	cout << "Ingrese la marca: ";
	cin >> ws;
	cin >> marca;
	cout << "Ingrese el modelo: ";
	cin >> ws;
	cin >> modelo;
	cout << "Ingrese costo de adquisicion: ";
	cin >> costoAdquisicion;
	cout << "Ingrese el porcentaje de ganancia: ";
	cin >> porcentajeGananciaVenta;
	cout << "Ingrese fecha de despacho: ";
	cin >> ws;
	cin >> fechaDespacho;
}

void Dispositivo::mostrar()
{
	double precioVenta = costoAdquisicion + (costoAdquisicion * (double) porcentajeGananciaVenta / 100.0);
	cout << marca << " " << modelo << " " << precioVenta << endl;
}

void Dispositivo::contar_s(int & contador)
{
	if (!strcmpi(marca,"SAMSUNG") && (strcmpi(modelo, "GALAXY")))
	{
		contador++;
	}

}

void Dispositivo::buscar(double &ganancia)
{
	ganancia += porcentajeGananciaVenta * (double)costoAdquisicion / 100.0;
}

// CLASE TV

class TV:public Dispositivo
{
public:
	void cargar();
	void mostrar();
	void buscar(double, int, bool &, double &);
	
private:
	double pulgadas;
	int nPuertosHDMI;

};

void TV::cargar()
{
	Dispositivo::cargar();
	cout << "Ingrese el numero de pulgadas: ";
	cin >> pulgadas;
	cout << "Ingrese el numero de puertos HDMI: ";
	cin >> nPuertosHDMI;

}

void TV::mostrar()
{
	Dispositivo::mostrar();
}

void TV::buscar(double pul, int np, bool & encontrado, double & acum)
{
	if ((pul == pulgadas) && (np == nPuertosHDMI))
	{
		Dispositivo::buscar(acum);
		encontrado = true;
	}
}


// CLASE CELULAR 

class Celular:public Dispositivo
{
public:
	void cargar();
	void mostrar();
	void contar_s(int &);
private:
	double capacidadMemoria;
};

void Celular::cargar()
{
	Dispositivo::cargar();
	cout << "Ingrese la cantidad de memoria: ";
	cin >> capacidadMemoria;
}

void Celular::mostrar()
{
	Dispositivo::mostrar();
}

void Celular::contar_s(int & contador)
{
	if (capacidadMemoria < 8)
	{
		Dispositivo::contar_s(contador);
	}
}

int main()
{
	int NTV = 500 , NCL = 500;
	TV televisores[NTV];
	Celular celulares[NCL];
	int tvp = 0, clp = 0, celularesSamsung = 0;
	double pulgadas;
	int np;
	char r;
	bool encontrado;
	double ganancia = 0;


	cout << "Carga de televisores" << endl;
	do
	{
		televisores[tvp].cargar();
		tvp++;
		if (tvp < NTV)
		{
			cout << "Desea procesar otro televisor? [S/N]: ";
			cin >> ws;
			cin >> r;
			r = toupper(r);
		}
	}while(tvp < NTV && r == 'S');

	
	cout << "Carga de celulares" << endl;

	do
	{
		celulares[clp].cargar();
		clp++;
		if (clp < NCL)
		{
			cout << "Desea procesar otro celular? [S/N]: ";
			cin >> ws;
			cin >> r;
			r = toupper(r);
		}
	}while(clp < NCL && 'S' == r);
	
	for (int i = 0; i < clp; ++i)
	{
		celulares[i].contar_s(celularesSamsung);
	}
	cout << "El porcentaje de celulares SAMSUNG es: " << celularesSamsung /(double)clp * 100 << "\%" << endl;

	cout << "Marca Modelo Precio Venta" << endl;

	for (int i = 0; i < tvp; ++i)
	{
		televisores[i].mostrar();
	}

	for (int i = 0; i < clp; ++i)
	{
		celulares[i].mostrar();
	}

	cout << "Televisor a consultar ganancia" << endl;
	cout << "Ingrese pulgadas: ";
	cin >> pulgadas;
	cout << "Ingrese numero de puertos: ";
	cin >> np;

	for (int i = 0; i < tvp; ++i)
	{
		televisores[i].buscar(pulgadas, np, encontrado, ganancia);
	}
	if (!encontrado)
	{
		cout << "No hay televisores con ese tipo de especificaciones" << endl;
	}
	else
	{
		cout << "La ganancia para ese tipo de televisor es: " << ganancia << " Bs." << endl;
	}

	return 0;
}