
#include <iostream>
#include <iomanip>
#include <ctime>
#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif

using namespace std;

// Declaraciones adelantadas de funciones
void ejerciciosBasicos();
void seleccionRepeticion();
void ejerciciosGenerales();
void cifrarDatos();
void descifrarDatos(int cifrado);
void operacionesConInversos();
void imprimirTriangulos();
void menuFibonacciHanoi();
void hanoi(int n, char origen, char auxiliar, char destino);
int invertirNumero(int num);
void encontrarPrimos();
void calcularDiasVividos();
void relojDigital();
bool validarFecha(int dia, int mes, int anio);
bool esBisiesto(int anio);
void limpiarBuffer();
void menuPrincipal();
void calcularImpuestoPredial();
void calcularPagoSemanal();
void calcularNotaNecesaria();

int main() {
	menuPrincipal();
	return 0;
}

void limpiarBuffer() {
	cin.clear();
	while (cin.get() != '\n');
}

void menuPrincipal() {
	int opcion;
	do {
		system("cls");
		cout << "\n========= MENU PRINCIPAL =========" << endl;
		cout << "1. Ejercicios basicos" << endl;
		cout << "2. Seleccion y repeticion" << endl;
		cout << "3. Generales" << endl;
		cout << "4. Salir" << endl;
		cout << "=================================" << endl;
		cout << "Ingrese una opcion: ";

		while (!(cin >> opcion)) {
			cin.clear();
			limpiarBuffer();
			cout << "Error: Ingrese un numero valido: ";
		}

		switch (opcion) {
		case 1: ejerciciosBasicos(); break;
		case 2: seleccionRepeticion(); break;
		case 3: ejerciciosGenerales(); break;
		case 4: cout << "\nGracias por usar el programa." << endl; break;
		default: cout << "\nOpcion invalida. Presione Enter para continuar...";
			cin.ignore(); cin.get();
		}
	} while (opcion != 4);
}

void ejerciciosBasicos() {
	int opcion;
	do {
		system("cls");
		cout << "\n===== EJERCICIOS BASICOS =====" << endl;
		cout << "1. Cifrar datos" << endl;
		cout << "2. Operaciones con inversos" << endl;
		cout << "3. Imprimir triangulos" << endl;
		cout << "4. Serie Fibonacci y Torres de Hanoi" << endl;
		cout << "5. Volver al menu principal" << endl;
		cout << "=============================" << endl;
		cout << "Elija una opcion: ";

		while (!(cin >> opcion)) {
			cin.clear();
			limpiarBuffer();
			cout << "Error: Ingrese un numero valido: ";
		}

		switch (opcion) {
		case 1: cifrarDatos(); break;
		case 2: operacionesConInversos(); break;
		case 3: imprimirTriangulos(); break;
		case 4: menuFibonacciHanoi(); break;
		case 5: break;
		default: cout << "\nOpcion invalida. Presione Enter para continuar...";
			cin.ignore(); cin.get();
		}
	} while (opcion != 5);
}

void cifrarDatos() {
	int numero;
	char respuesta;
	do {
		system("cls");
		cout << "\n=== CIFRADO DE DATOS ===" << endl;
		do {
			cout << "Ingrese un numero de 4 digitos: ";
			while (!(cin >> numero) || numero < 1000 || numero > 9999) {
				cin.clear();
				limpiarBuffer();
				cout << "Error: Ingrese un numero valido de 4 digitos: ";
			}
		} while (numero < 1000 || numero > 9999);

		int d1 = numero / 1000;
		int d2 = (numero / 100) % 10;
		int d3 = (numero / 10) % 10;
		int d4 = numero % 10;

		d1 = (d1 + 7) % 10;
		d2 = (d2 + 7) % 10;
		d3 = (d3 + 7) % 10;
		d4 = (d4 + 7) % 10;

		swap(d1, d3);
		swap(d2, d4);

		int cifrado = d1 * 1000 + d2 * 100 + d3 * 10 + d4;
		cout << "\nNumero cifrado: " << cifrado << endl;

		cout << "\nDesea descifrar este numero? (s/n): ";
		cin >> respuesta;
		if (respuesta == 's' || respuesta == 'S') {
			descifrarDatos(cifrado);
		}

		cout << "\nDesea cifrar otro numero? (s/n): ";
		cin >> respuesta;
	} while (respuesta == 's' || respuesta == 'S');
}

void descifrarDatos(int cifrado) {
	int d1 = cifrado / 1000;
	int d2 = (cifrado / 100) % 10;
	int d3 = (cifrado / 10) % 10;
	int d4 = cifrado % 10;

	swap(d1, d3);
	swap(d2, d4);

	d1 = (d1 - 7 + 10) % 10;
	d2 = (d2 - 7 + 10) % 10;
	d3 = (d3 - 7 + 10) % 10;
	d4 = (d4 - 7 + 10) % 10;

	int descifrado = d1 * 1000 + d2 * 100 + d3 * 10 + d4;
	cout << "Numero descifrado: " << descifrado << endl;
}

void operacionesConInversos() {
	system("cls");
	cout << "\n=== OPERACIONES CON INVERSOS ===" << endl;
	long long num1, num2, num3;

	cout << "Ingrese el primer numero (maximo 7 digitos): ";
	while (!(cin >> num1) || num1 < 0 || num1 > 9999999) {
		cin.clear();
		limpiarBuffer();
		cout << "Error: Ingrese un numero valido (0-9999999): ";
	}

	cout << "Ingrese el segundo numero (maximo 7 digitos): ";
	while (!(cin >> num2) || num2 < 0 || num2 > 9999999) {
		cin.clear();
		limpiarBuffer();
		cout << "Error: Ingrese un numero valido (0-9999999): ";
	}

	cout << "Ingrese el tercer numero (maximo 7 digitos): ";
	while (!(cin >> num3) || num3 < 0 || num3 > 9999999) {
		cin.clear();
		limpiarBuffer();
		cout << "Error: Ingrese un numero valido (0-9999999): ";
	}

	long long inv1 = invertirNumero(num1);
	long long inv2 = invertirNumero(num2);
	long long inv3 = invertirNumero(num3);

	cout << "\nNumeros invertidos:" << endl;
	cout << num1 << " -> " << inv1 << endl;
	cout << num2 << " -> " << inv2 << endl;
	cout << num3 << " -> " << inv3 << endl;

	cout << "\nOperaciones con numeros invertidos:" << endl;
	cout << "Suma: " << inv1 + inv2 + inv3 << endl;
	cout << "Resta: " << inv1 - inv2 - inv3 << endl;
	cout << "Multiplicacion: " << inv1 * inv2 * inv3 << endl;

	if (inv2 != 0 && inv3 != 0) {
		cout << "Division: " << fixed << setprecision(2)
			<< (double)inv1 / inv2 / inv3 << endl;
	}
	else {
		cout << "Division: No es posible (division por cero)" << endl;
	}

	cout << "\nPresione Enter para continuar...";
	cin.ignore();
	cin.get();
}

void imprimirTriangulos() {
	system("cls");
	cout << "\n=== IMPRESION DE TRIANGULOS ===" << endl;
	int n;
	cout << "Ingrese la altura de los triangulos: ";
	while (!(cin >> n) || n <= 0) {
		cin.clear();
		limpiarBuffer();
		cout << "Error: Ingrese un numero valido mayor que 0: ";
	}

	cout << "\nTriangulo A:" << endl;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			cout << "*";
		}
		cout << endl;
	}

	cout << "\nTriangulo B:" << endl;
	for (int i = 1; i <= n; i++) {
		for (int j = i; j < n; j++) {
			cout << " ";
		}
		for (int j = 1; j <= i; j++) {
			cout << "*";
		}
		cout << endl;
	}

	cout << "\nTriangulo C:" << endl;
	for (int i = n; i >= 1; i--) {
		for (int j = 1; j <= i; j++) {
			cout << "*";
		}
		cout << endl;
	}

	cout << "\nPresione Enter para continuar...";
	cin.ignore();
	cin.get();
}

void menuFibonacciHanoi() {
	int opcion;
	do {
		system("cls");
		cout << "\n=== FIBONACCI Y TORRES DE HANOI ===" << endl;
		cout << "1. Serie Fibonacci (30 numeros)" << endl;
		cout << "2. Torres de Hanoi (5 discos)" << endl;
		cout << "3. Volver al menu de ejercicios basicos" << endl;
		cout << "====================================" << endl;
		cout << "Elija una opcion: ";

		while (!(cin >> opcion)) {
			cin.clear();
			limpiarBuffer();
			cout << "Error: Ingrese un numero valido: ";
		}

		switch (opcion) {
		case 1: {
			cout << "\n=== SERIE FIBONACCI (30 numeros) ===" << endl;
			long long a = 0, b = 1;
			cout << "Serie Fibonacci: ";
			for (int i = 0; i < 30; i++) {
				cout << a << " ";
				long long temp = a;
				a = b;
				b = temp + b;
			}
			cout << "\n\nPresione Enter para continuar...";
			cin.ignore();
			cin.get();
			break;
		}
		case 2: {
			cout << "\n=== TORRES DE HANOI (5 discos) ===" << endl;
			hanoi(5, 'A', 'B', 'C');
			cout << "\nPresione Enter para continuar...";
			cin.ignore();
			cin.get();
			break;
		}
		case 3: break;
		default:
			cout << "\nOpcion invalida. Presione Enter para continuar...";
			cin.ignore();
			cin.get();
		}
	} while (opcion != 3);
}

void hanoi(int n, char origen, char auxiliar, char destino) {
	if (n == 1) {
		cout << "Mover disco 1 de " << origen << " a " << destino << endl;
	}
	else {
		hanoi(n - 1, origen, destino, auxiliar);
		cout << "Mover disco " << n << " de " << origen << " a " << destino << endl;
		hanoi(n - 1, auxiliar, origen, destino);
	}
}

int invertirNumero(int num) {
	int invertido = 0;
	while (num != 0) {
		int digito = num % 10;
		invertido = invertido * 10 + digito;
		num /= 10;
	}
	return invertido;
}

void seleccionRepeticion() {
	int opcion;
	do {
		system("cls");
		cout << "\n===== SELECCION Y REPETICION =====" << endl;
		cout << "1. Encontrar numeros primos" << endl;
		cout << "2. Calcular dias vividos" << endl;
		cout << "3. Reloj digital" << endl;
		cout << "4. Volver al menu principal" << endl;
		cout << "================================" << endl;
		cout << "Elija una opcion: ";

		while (!(cin >> opcion)) {
			cin.clear();
			limpiarBuffer();
			cout << "Error: Ingrese un numero valido: ";
		}

		switch (opcion) {
		case 1: encontrarPrimos(); break;
		case 2: calcularDiasVividos(); break;
		case 3: relojDigital(); break;
		case 4: break;
		default: cout << "\nOpcion invalida. Presione Enter para continuar...";
			cin.ignore(); cin.get();
		}
	} while (opcion != 4);
}

void encontrarPrimos() {
	system("cls");
	cout << "\n=== NUMEROS PRIMOS ===" << endl;
	int inicio, fin;

	cout << "Ingrese el numero inicial: ";
	while (!(cin >> inicio) || inicio < 0) {
		cin.clear();
		limpiarBuffer();
		cout << "Error: Ingrese un numero valido mayor o igual a 0: ";
	}

	cout << "Ingrese el numero final: ";
	while (!(cin >> fin) || fin <= inicio) {
		cin.clear();
		limpiarBuffer();
		cout << "Error: Ingrese un numero mayor que " << inicio << ": ";
	}

	cout << "Numeros primos entre " << inicio << " y " << fin << ": ";
	for (int i = inicio; i <= fin; i++) {
		if (i < 2) continue;
		bool esPrimo = true;
		for (int j = 2; j <= sqrt(i); j++) {
			if (i % j == 0) {
				esPrimo = false;
				break;
			}
		}
		if (esPrimo) {
			cout << i << " ";
		}
	}
	cout << endl;

	cout << "\nPresione Enter para continuar...";
	cin.ignore();
	cin.get();
}

void calcularDiasVividos() {
	system("cls");
	cout << "\n=== CALCULAR DIAS VIVIDOS ===" << endl;
	int dia, mes, anio;

	cout << "Ingrese su fecha de nacimiento:\n";
	cout << "Día: ";
	while (!(cin >> dia) || dia <= 0 || dia > 31) {
		cin.clear();
		limpiarBuffer();
		cout << "Error: Ingrese un día válido: ";
	}

	cout << "Mes: ";
	while (!(cin >> mes) || mes <= 0 || mes > 12) {
		cin.clear();
		limpiarBuffer();
		cout << "Error: Ingrese un mes válido: ";
	}

	cout << "Año: ";
	while (!(cin >> anio) || anio <= 0 || anio > 2100) {
		cin.clear();
		limpiarBuffer();
		cout << "Error: Ingrese un año válido (1-2100): ";
	}
	if (!validarFecha(dia, mes, anio)) {
		cout << "\nFecha inválida. Presione Enter para continuar...";
		cin.ignore();
		cin.get();
		return;
	}

	time_t now = time(0);
	tm* ltm = localtime(&now);
	int dia_actual = ltm->tm_mday;
	int mes_actual = 1 + ltm->tm_mon;
	int anio_actual = 1900 + ltm->tm_year;

	int bisiestos = contarBisiestos(anio, anio_actual);
	int diasTotales = (anio_actual - anio) * 365 + bisiestos;

	int diasPorMes[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	for (int m = mes + 1; m <= 12; m++) {
		diasTotales += diasPorMes[m];
	}
	diasTotales += diasPorMes[mes] - dia;

	for (int m = 1; m < mes_actual; m++) {
		diasTotales += diasPorMes[m];
	}
	diasTotales += dia_actual;

	if (esBisiesto(anio_actual) && mes_actual > 2) {
		diasTotales += 1;
	}

	cout << "\nDías vividos: " << diasTotales << endl;
	cout << "Años bisiestos en el periodo: " << bisiestos << endl;

	cout << "\nPresione Enter para continuar...";
	cin.ignore();
	cin.get();
}

int contarBisiestos(int anio_inicio, int anio_fin) {
	int bisiestos = 0;
	for (int anio = anio_inicio; anio <= anio_fin; anio++) {
		if (esBisiesto(anio)) {
			bisiestos++;
		}
	}
	return bisiestos;
}

bool esBisiesto(int anio) {
	return (anio % 4 == 0 && (anio % 100 != 0 || anio % 400 == 0));
}

bool validarFecha(int dia, int mes, int anio) {
	if (mes < 1 || mes > 12) return false;
	int diasEnMes[] = { 31, 28 + (esBisiesto(anio) ? 1 : 0), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	return dia >= 1 && dia <= diasEnMes[mes - 1];
}

void relojDigital() {
	system("cls");
	cout << "\n=== RELOJ DIGITAL ===" << endl;

	while (true) {
		time_t now = time(0);
		tm* ltm = localtime(&now);

		cout << "\rHora actual: " << setw(2) << setfill('0') << ltm->tm_hour << ":"
			<< setw(2) << setfill('0') << ltm->tm_min << ":"
			<< setw(2) << setfill('0') << ltm->tm_sec << flush;

		// Pausar 1 segundo
#ifdef _WIN32
		Sleep(1000);
#else
		usleep(1000000);
#endif
	}
}
void ejerciciosGenerales() {
	int opcion;
	do {
		system("cls");
		cout << "\n===== EJERCICIOS GENERALES =====" << endl;
		cout << "1. Pago del impuesto predial" << endl;
		cout << "2. Pago semanal de un trabajador" << endl;
		cout << "3. Calcular nota necesaria para estudiantes" << endl;
		cout << "4. Volver al menú principal" << endl;
		cout << "================================" << endl;
		cout << "Elija una opción: ";

		while (!(cin >> opcion)) {
			cin.clear();
			limpiarBuffer();
			cout << "Error: Ingrese un número válido: ";
		}

		switch (opcion) {
		case 1: calcularImpuestoPredial(); break;
		case 2: calcularPagoSemanal(); break;
		case 3: calcularNotaNecesaria(); break;
		case 4: break;
		default:
			cout << "\nOpción inválida. Presione Enter para continuar...";
			cin.ignore();
			cin.get();
		}
	} while (opcion != 4);
}

void calcularImpuestoPredial() {
	system("cls");
	double valorInmueble, impuestoBase, descuentoProntoPago = 0, descuentoTrabajador = 0;
	char esTrabajadorOficial, aplicaProntoPago;

	cout << "\n=== CÁLCULO DE IMPUESTO PREDIAL ===" << endl;
	do {
		cout << "Ingrese el valor del inmueble: $";
		while (!(cin >> valorInmueble) || valorInmueble <= 0) {
			cin.clear();
			limpiarBuffer();
			cout << "Error: Ingrese un valor válido mayor que 0: $";
		}
	} while (valorInmueble <= 0);

	impuestoBase = valorInmueble * 0.15;

	cout << "¿Aplica descuento por pronto pago? (S/N): ";
	cin >> aplicaProntoPago;
	if (toupper(aplicaProntoPago) == 'S') {
		descuentoProntoPago = impuestoBase * 0.10;
	}

	cout << "¿Es trabajador oficial? (S/N): ";
	cin >> esTrabajadorOficial;
	if (toupper(esTrabajadorOficial) == 'S') {
		descuentoTrabajador = impuestoBase * 0.05;
	}

	cout << fixed << setprecision(2);
	cout << "\n=== DESGLOSE DEL IMPUESTO PREDIAL ===" << endl;
	cout << "Valor del inmueble: $" << valorInmueble << endl;
	cout << "Impuesto base (15%): $" << impuestoBase << endl;
	cout << "Descuento pronto pago: $" << descuentoProntoPago << endl;
	cout << "Descuento trabajador oficial: $" << descuentoTrabajador << endl;
	cout << "TOTAL A PAGAR: $" << (impuestoBase - descuentoProntoPago - descuentoTrabajador) << endl;

	cout << "\nPresione Enter para continuar...";
	cin.ignore();
	cin.get();
}

void calcularPagoSemanal() {
	system("cls");
	double horasTrabajadas, valorHora, tasaImpuestos;
	double pagoBase, pagoExtra = 0, impuestos, pagoTotal;

	cout << "\n=== CÁLCULO DE PAGO SEMANAL ===" << endl;
	do {
		cout << "Ingrese número de horas trabajadas: ";
		while (!(cin >> horasTrabajadas) || horasTrabajadas < 0) {
			cin.clear();
			limpiarBuffer();
			cout << "Error: Ingrese un número válido de horas: ";
		}
	} while (horasTrabajadas < 0);

	do {
		cout << "Ingrese valor por hora: $";
		while (!(cin >> valorHora) || valorHora <= 0) {
			cin.clear();
			limpiarBuffer();
			cout << "Error: Ingrese un valor válido por hora: $";
		}
	} while (valorHora <= 0);

	do {
		cout << "Ingrese tasa de impuestos (porcentaje): ";
		while (!(cin >> tasaImpuestos) || tasaImpuestos < 0 || tasaImpuestos > 100) {
			cin.clear();
			limpiarBuffer();
			cout << "Error: Ingrese una tasa válida entre 0 y 100: ";
		}
	} while (tasaImpuestos < 0 || tasaImpuestos > 100);

	if (horasTrabajadas <= 40) {
		pagoBase = horasTrabajadas * valorHora;
	}
	else {
		pagoBase = 40 * valorHora;
		pagoExtra = (horasTrabajadas - 40) * (valorHora * 1.5);
	}

	impuestos = (pagoBase + pagoExtra) * (tasaImpuestos / 100);
	pagoTotal = pagoBase + pagoExtra - impuestos;

	cout << fixed << setprecision(2);
	cout << "\n=== DESGLOSE DEL PAGO SEMANAL ===" << endl;
	cout << "Pago por horas regulares: $" << pagoBase << endl;
	cout << "Pago por horas extras: $" << pagoExtra << endl;
	cout << "Impuestos: $" << impuestos << endl;
	cout << "TOTAL A PAGAR: $" << pagoTotal << endl;

	cout << "\nPresione Enter para continuar...";
	cin.ignore();
	cin.get();
}

void calcularNotaNecesaria() {
	system("cls");
	const int NUM_ESTUDIANTES = 5;
	double nota1, nota2, notaNecesaria;

	cout << "\n=== CÁLCULO DE NOTA NECESARIA ===" << endl;

	for (int i = 1; i <= NUM_ESTUDIANTES; i++) {
		cout << "\nEstudiante " << i << endl;
		do {
			cout << "Ingrese nota del primer 30%: ";
			while (!(cin >> nota1) || nota1 < 0 || nota1 > 5) {
				cin.clear();
				limpiarBuffer();
				cout << "Error: Ingrese una nota válida entre 0 y 5: ";
			}
		} while (nota1 < 0 || nota1 > 5);

		do {
			cout << "Ingrese nota del segundo 30%: ";
			while (!(cin >> nota2) || nota2 < 0 || nota2 > 5) {
				cin.clear();
				limpiarBuffer();
				cout << "Error: Ingrese una nota válida entre 0 y 5: ";
			}
		} while (nota2 < 0 || nota2 > 5);

		notaNecesaria = (3.0 - (nota1 * 0.3) - (nota2 * 0.3)) / 0.4;

		cout << fixed << setprecision(2);
		cout << "Nota actual: " << (nota1 * 0.3 + nota2 * 0.3) << endl;
		if (notaNecesaria > 5) {
			cout << "El estudiante ya no puede aprobar el curso.\n";
		}
		else if (notaNecesaria < 0) {
			cout << "El estudiante ya aprobó el curso.\n";
		}
		else {
			cout << "Nota necesaria en el 40% final: " << notaNecesaria << endl;
		}
	}

	cout << "\nPresione Enter para continuar...";
	cin.ignore();
	cin.get();
}