#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>

using namespace std;

class PARTICIPANTE
{

	public:
		void carga(int);
		void semana(int);
		void resumen(int);
		string cat();
		string obtenerNombre();

		double obtenerPSI();
		double obtenerPSF();
		double obtenerMCI();
		double obtenerMCF();
		double obtenerPI();
	private:
		string nombre;
		double estatura;
		double pesoInicial;
		double pSemanaI;
		double pSemanaF;
		double mCinturaI;
		double mCinturaF;
		double imc;
};

void PARTICIPANTE::carga(int i)
{
	cout << "Ingrese el nombre del participante " << i+1 << ": ";
	cin >> ws;
	getline(cin, nombre);
	cout << "Ingrese la estatura: ";
	cin >> estatura;
	estatura = fabs(estatura);
}


void PARTICIPANTE::semana(int semana)
{
	cout << "Participante: " << nombre << endl;
	cout << "Ingrese el peso a principio de la semana: ";
	cin >> pSemanaI;
	pSemanaI = fabs(pSemanaI);	
	
	if(semana == 0)
		pesoInicial = pSemanaI;

	cout << "Ingrese la medida de la cintura a principio de la semana: ";
	cin >> mCinturaI;
	mCinturaI = fabs(mCinturaI);
	cout << "Ingrese el peso al final de la semana: ";
	cin >> pSemanaF;
	pSemanaF = fabs(pSemanaF);
	cout << "Ingrese la medida de la cintura a final de la semana: ";
	cin >> mCinturaF;
	mCinturaF =	fabs(mCinturaF);
	imc = pSemanaI / pow(estatura, 2);
	cout << "\n\n" << endl;
}

void PARTICIPANTE::resumen(int n)
{	
	cout << setw(n) << left << nombre << setw(n) << right << pSemanaI << setw(n) << imc 
	<< setw(n) << this->cat() << endl;
}

string PARTICIPANTE::cat()
{
	string categoria;

	if(imc <= 25)
		categoria = "Peso Normal";
	else if(imc > 25 && imc <= 28)
		categoria = "Sobre peso";
	else if (imc > 28 && imc <= 31)
		categoria = "Obesidad I";
	else if(imc > 31)
		categoria = "Obesidad II";

	return categoria;

}

string PARTICIPANTE::obtenerNombre()
{
	return nombre;
}

double PARTICIPANTE::obtenerPSI()
{
	return pSemanaI;
}

double PARTICIPANTE::obtenerPSF()
{
	return pSemanaF;
}

double PARTICIPANTE::obtenerMCI()
{
	return mCinturaI;
}

double PARTICIPANTE::obtenerMCF()
{
	return mCinturaF;
}

double PARTICIPANTE::obtenerPI()
{
	return pesoInicial;
}

int main()
{
	int N = 2, n = 16, sem = 0;
	PARTICIPANTE participante[N];
	string ganadorP, ganadorC, ganador;
	double pesoMayor, pesoAux, cinturaMayor, cinturaAux, mayorPP, auxPP;
	char r;
	cout << "\n\nREGISTRO\n" << endl;
	for(int i = 0; i < N; i++)
		participante[i].carga(i);

	do
	{
		cout << "\n\nSEMANA " << sem + 1 << '\n' << endl;
		for(int i = 0; i < N; i++)
			participante[i].semana(sem);
	
		cout << setw(n) << left << "Nombre" << setw(n) << right << "Peso" << setw(n) << "IMC" << setw(n) << "Categoria" << endl;
		
		for(int i = 0; i < N; i++)
			participante[i].resumen(n);

		ganadorP = participante[0].obtenerNombre();
		pesoMayor = participante[0].obtenerPSI() - participante[0].obtenerPSF();
		ganadorC = participante[0].obtenerNombre();
		cinturaMayor = participante[0].obtenerMCI() - participante[0].obtenerMCF();
		
		for(int i = 1; i < N; i++)
		{
			pesoAux = participante[i].obtenerPSI() - participante[i].obtenerPSF();
			if (pesoMayor < pesoAux)
			{
				ganadorP = participante[i].obtenerNombre();
				pesoMayor = pesoAux;
			}
			cinturaAux = participante[i].obtenerMCI() - participante[i].obtenerMCF();
			if (cinturaMayor < cinturaAux)
			{
				ganadorC = participante[i].obtenerNombre();
				cinturaMayor = cinturaAux;
			}
		}
	
		cout << "Ganadores de la semana" << endl;

		cout << ((pesoMayor >= 0)? "Mayor perdida de peso: ": "Menor incremento de peso: ")
		     << fabs(pesoMayor) << " Kg " << ganadorP << endl;

		cout << ((cinturaMayor >= 0)? "Mayor perdida de cintura: ": "Menor incremento de cintura: ")
				 << fabs(cinturaMayor) << " cm " << ganadorC << endl;

		cout << "Registrar pesos de una nueva semana? [S/N]: ";
		cin >> ws;
		cin >> r;
		r = toupper(r);
		sem++;
	}while(r != 'N');

	ganador = participante[0].obtenerNombre();
	mayorPP = participante[0].obtenerPI() - participante[0].obtenerPSF();
	
	for( int i = 1; i < N; i++)
	{	
		auxPP = participante[i].obtenerPI() - participante[i].obtenerPSF();
		
		if (mayorPP < auxPP)
		{
			ganador = participante[i].obtenerNombre();
			mayorPP = auxPP;	
		}
	}


//	cout << "El ganador del concurso " << ((mayorPP >= 0)? "con una mayor perdida de peso es: ":"con un menor incremento de peso es: ") << ganador << endl;

	cout << "Ganador del concurso: " << ganador << endl;

	return 0;
}



