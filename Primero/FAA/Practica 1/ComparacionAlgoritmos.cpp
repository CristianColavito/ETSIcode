#include <iostream>
#include <conio.h>
#include "Mtime.h"
#include "Test.h"
#include "ConjuntoInt.h"
#include "Constantes.h"

using namespace std;

int menuCasos() {
	char c;

	system("cls");
	do {
		cout << "\n\n"
			<< "-----        Caso a estudiar para la busqueda secuencial           -----\n\n"
			<< "     1.- Caso peor\n"
			<< "     2.- Caso medio\n"
			<< "     3.- Caso mejor\n"
			<< "  -------------------\n"
			<< "   Elija una opcion:";

		c = cin.get();
		system("cls");
	} while (c != '1' && c != '2' && c != '3');

	switch (c) {
	case '1':
		c = 2;
		break;
	case '2':
		c = 3;
		break;
	case '3':
		c = 4;
		break;
	}

	return c;
}
int menu(){
	/******************  OPERACIONES  ***********************
	**** 0. Salir               1. Probar algoritmo      ****
	**** 2. Teorico caso Peor   6. Practico caso Peor    ****
	**** 3. Teorico caso Medio  7. Practico caso Medio   ****
	**** 4. Teorico caso Mejor  8. Practico caso Mejor   ****
	**** 5. Teorico Comparar    9. Practico Comparar     ****
	*********************************************************/
	char c;
	system("cls");

	do {
		cout << " FAA. Practica 1. Curso 18/19 \n"
			<< "                                                           Borja Lopez Pineda \n"
			<< "-----  ESTUDIO DE LA COMPLEJIDAD DE UN ALGORITMO DE BUSQUEDA SECUENCIAL  -----\n\n"
			<< "                         1.- ESTUDIO TEORICO\n"
			<< "                         2.- ESTUDIO EMPIRICO\n"
			<< "                         0.- Salir\n"
			<< "                  ---------------------------------\n"
			<< "                       Elija una opcion:";

		c = cin.get();
		system("cls");
	} while (c != '1' && c != '2' && c != '0');


	switch (c) {
	case '1':
		do {
			cout << "\n\n"
				<< "-----        MENU TEORICO DEL ALGORITMO DE BUSQUEDA SECUENCIAL           -----\n\n"
				<< "            1.- Probar el algoritmo de busqueda secuencial\n"
				<< "            2.- Obtener los casos del metodo de busqueda secuencial\n"
				<< "            3.- Comparar los casos\n"
				<< "            0.- Volver al menu principal\n"
				<< "            --------------------------------------------------\n"
				<< "                       Elija una opcion:";

			c = cin.get();
			system("cls");
		} while (c != '1' && c != '2' && c != '3' && c != '0');
		switch (c) {
		case '1':
			c = 1;
			break;
		case '2':
			c = menuCasos();
			break;
		case '3':
			c = 5;
			break;
		case '0':
			c = menu();
			break;
		}
		break;
	case '2':
		do {
			cout << "\n\n"
				<< "-----        MENU EMPIRICO DEL ALGORITMO DE BUSQUEDA SECUENCIAL           -----\n\n"
				<< "            1.- Probar el algoritmo de busqueda secuencial\n"
				<< "            2.- Obtener los casos del metodo de busqueda secuencial\n"
				<< "            3.- Comparar los casos\n"
				<< "            0.- Volver al menu principal\n"
				<< "            -------------------------------------------------\n"
				<< "                       Elija una opcion:";

			c = cin.get();
			system("cls");
		} while (c != '1' && c != '2' && c != '3' && c != '0');
		switch (c) {
		case '1':
			c = 1;
			break;
		case '2':
			c = menuCasos()+4;
			break;
		case '3':
			c = 9;
			break;
		case '0':
			c = menu();
			break;
		}

		break;
	case '0':
		c = 0;
		break;
	}

	cout << "\n\n";
	return c;
}

int main(){
	int opt;
	TestAlgoritmo test;

	do {
		opt = menu();
		switch (opt) {
		case 1://Probar algoritmo
			test.comprobarAlgoritmo();
			break;
		case 2://Teorico caso Peor
			test.costeTeorico(SECUENCIALPEOR);
			break;
		case 3://Teorico caso Medio
			test.costeTeorico(SECUENCIALMEDIO);
			break;
		case 4://Teorico caso Mejor
			test.costeTeorico(SECUENCIALMEJOR);
			break;
		case 5://Teorico Comparativa
			test.compararTeorico(SECUENCIALPEOR, SECUENCIALMEDIO, SECUENCIALMEJOR);
			break;
		case 6://Practico caso Peor
			test.costeEmpirico(SECUENCIALPEOR);
			break;
		case 7://Practico caso Medio
			test.costeEmpirico(SECUENCIALMEDIO);
			break;
		case 8://Practico caso Mejor
			test.costeEmpirico(SECUENCIALMEJOR);
			break;
		case 9://Practico Comparativa
			test.compararEmpirico(SECUENCIALPEOR, SECUENCIALMEDIO, SECUENCIALMEJOR);
			break;
		case 0://Salir
			break;
		}
	} while (opt != 0);

	system("pause");
	return 0;
}

