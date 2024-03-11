#include <iostream>
#include <string>
#include <locale>

void repeticion();

void administradorBiblioteca();
void informacionEstudiantes();
void calculadora();
void menuCajero();
void peliculasTaquilla();

using namespace std;

char respuesta;
bool repetir;

class Biblioteca {
private:
	string m_autor;
	string m_titulo;
	string m_anio;
	string m_isbn;
public:
	Biblioteca(string titulo, string autor, string anio, string isbn)
		: m_titulo(titulo), m_autor(autor), m_anio(anio), m_isbn(isbn) {}

	void mostrarNuevoLibro() {
		cout << "Titulo del libro: " << m_titulo << endl;
		cout << "Autor del libro: " << m_autor << endl;
		cout << "Anio de publicacion: " << m_anio << endl;
		cout << "ISBN del libro: " << m_isbn;
	}
};

class Peliculas {
private:
	string m_director;
	string m_titulo;
	string m_anio;
	string m_genero;
	string m_hora;
	string m_clasificacion;
public:
	Peliculas(string titulo, string director, string anio, string genero, string clasificacion,string hora)
		: m_titulo(titulo), m_director(director), m_anio(anio), m_genero(genero), m_clasificacion(clasificacion), m_hora(hora) {}

	void peliculasDisponibles() {
		cout << "Nombre de la pelicula: " << m_titulo << endl;
		cout << "Genero: " << m_genero << endl;
		cout << "Clasificacion " << m_clasificacion << endl;
		cout << "Director: " << m_director << endl;
		cout << "Fecha de estreno: " << m_anio << endl;
		cout << "Hora de la funcion: " << m_hora;
	}
};

class Estudiante {
private:
	string m_nombre;
	string m_apellido;
	int m_edad;
	string m_carrera;
	string m_salon;
	float m_promedio;
public:
	Estudiante(string nombre, string apellido, int edad, string carrera, string salon, float promedio)
		: m_nombre(nombre), m_apellido(apellido), m_edad(edad), m_carrera(carrera), m_salon(salon), m_promedio(promedio) {}

	void mostrarInformacionEstudiante() {
		cout << "Nombres: " << m_nombre << endl;
		cout << "Apellidos: " << m_apellido << endl;
		cout << "Edad: " << m_edad << endl;
		cout << "Carrera: " << m_carrera << endl;
		cout << "Salon: " << m_salon << endl;
		cout << "Promedio: " << m_promedio;
	}
};

class CalculadoraSimple {
private:
	int m_opcion;
	float m_num1, m_num2;
public:
	CalculadoraSimple(int opcion, float num1, float num2)
		: m_opcion(opcion), m_num1(num1), m_num2(num2) {}

	void mostrarResultado() {
		cout << "El resultado de la ";
		switch (m_opcion) {
		case 1:
			cout << "suma es: " << m_num1 + m_num2 << endl;
			break;
		case 2:
			cout << "resta es: " << m_num1 - m_num2 << endl;
			break;
		case 3:
			cout << "multiplicacion es: " << m_num1 * m_num2 << endl;
			break;
		case 4:
			cout << "division es: " << m_num1 / m_num2 << endl;
			break;
		}
	}
};

class GestionBanco {
private:
	string m_titular;
	float m_saldo;
public:
	GestionBanco(string titular, float saldo)
		: m_titular(titular), m_saldo(saldo) {}
	
	void retirarDinero() {
		int opcionDinero;

		do {
			system("cls");
			cout << "\tRetiro de dinero\n\n";
			cout << "Opciones a retirar: \n\n";

			cout << "1. Q50\n";
			cout << "2. Q100\n";
			cout << "3. Q500\n";
			cout << "4. Q1000\n";
			cout << "5. Ingresar cantidad\n\n";

			cout << "Digite la opcion: ";
			cin >> opcionDinero;

		} while (opcionDinero < 1 or opcionDinero > 5);

		if ((opcionDinero == 1 and m_saldo < 50) or (opcionDinero == 2 and m_saldo < 100) or (opcionDinero == 3 and m_saldo < 500) or (opcionDinero == 4 and m_saldo < 1000)) {
			system("cls");
			cout << "Fondos insuficientes disponibles en la cuenta del usuario\n\n";
			return;
		}

		switch (opcionDinero) {
		case 1:
			m_saldo -= 50;
			break;
		case 2:
			m_saldo -= 100;
			break;
		case 3:
			m_saldo -= 500;
			break;
		case 4:
			m_saldo -= 1000;
			break;
		case 5:
			system("cls");
			int cantRetirar;
			cout << "Ingrese la cantidad a retirar: ";
			cin >> cantRetirar;
			if (cantRetirar > m_saldo) {
				system("cls");
				cout << "Fondos insuficientes disponibles en la cuenta del usuario\n\n";
				return;
			}
			m_saldo -= cantRetirar;
			break;
		}

		cout << "\n\tSe ha retirado de manera correcta\n\n";
	}

	void depositarDinero() {
		float deposito;
		system("cls");
		cout << "\tDeposito de dinero\n\n";
		cout << "Ingrese la cantidad a depositar en su cuenta: ";
		cin >> deposito;
		m_saldo += deposito;
		cout << "\n\tEl deposito se ha realizado de manera correcta\n\n";
	}

	void consultarEstadoCuenta() const{
		system("cls");
		cout << "\tResumen estado de cuenta\n\n";
		cout << "Nombre del usuario: " << m_titular << endl;
		cout << "Fondos de la cuenta: Q" << m_saldo << endl;
	}
};


int main() {
	setlocale(LC_ALL, "");

	do {
		system("cls");
		int opcion;
		cout << "\tMenu:\n\n";
		cout << "1. Biblioteca virtual\n";
		cout << "2. Registro de estudiantes\n";
		cout << "3. Calculadora simple\n";
		cout << "4. Gestion bancaria\n";
		cout << "5. Registro de peliculas\n";
		cout << "6. Salir del menu\n\n";
		cout << "Opcion a elegir: ";
		cin >> opcion;
		system("cls");
		switch (opcion) {
		case 1:
			administradorBiblioteca();
			repeticion();
			break;
		case 2:
			informacionEstudiantes();
			repeticion();
			break;
		case 3:
			calculadora();
			repeticion();
			break;
		case 4:
			menuCajero();
			repeticion();
			break;
		case 5:
			peliculasTaquilla();
			repeticion();
			break;
		case 6:
			return 0;
		default:
			repetir = true;
		}
	} while (repetir == true);

	return 0;
}


void administradorBiblioteca() {
	Biblioteca libro1("El corazón de la piedra", "José María García López ", "2013", "978-84-939750-7-4");
	Biblioteca libro2("Salmos de vísperas", "Esteban Hernández Castelló", "2003", "84 932914 8 X");
	Biblioteca libro3("La música en las catedrales españolas del Siglo de Oro", "Robert Stevenson", "1993", "84-206-8562-3");
	Biblioteca libro4("Tomás Luis de Victoria: A guide to research", "Eugene Casjen Cramer", "1998", "0 8153 2096 5");

	cout << "\tBienvenido al mostrador de libros de la biblioteca\n\n";
	cout << "Libros disponibles: \n\n";

	libro1.mostrarNuevoLibro();
	cout << "\n------------------------------------------------------------------\n";
	libro2.mostrarNuevoLibro();
	cout << "\n------------------------------------------------------------------\n";
	libro3.mostrarNuevoLibro();
	cout << "\n------------------------------------------------------------------\n";
	libro4.mostrarNuevoLibro();
	cout << "\n------------------------------------------------------------------\n";
	system("pause");
}

void informacionEstudiantes() {
	Estudiante estudiante1("Pablo Sebastián", "Quan Montenegro", 19, "Ingenieria en Sistemas", "B-101", 90.6);
	Estudiante estudiante2("Jorge Mario", "Folgar Martínez", 18, "Arquitectura", "B-105", 90.5);
	Estudiante estudiante3("Luis Eduardo", "Guevara Juárez", 18, "Arte", "A-202", 90.4);
	Estudiante estudiante4("Esteban Mauricio", "Contreras Molina", 20, "Derecho", "C-301", 90);

	cout << "\tBienvenido al registro de estudiantes de la UMG\n\n";
	cout << "Estudiantes disponibles: \n\n";

	estudiante1.mostrarInformacionEstudiante();
	cout << "\n------------------------------------------------------------------\n";
	estudiante2.mostrarInformacionEstudiante();
	cout << "\n------------------------------------------------------------------\n";
	estudiante3.mostrarInformacionEstudiante();
	cout << "\n------------------------------------------------------------------\n";
	estudiante4.mostrarInformacionEstudiante();
	cout << "\n------------------------------------------------------------------\n";
	system("pause");
}

void calculadora() {
	bool repetirCalcu;
	char respuestaCalcu;
	do {
		int operacion, numero1, numero2;
		do {
			system("cls");
			cout << "\tCalculadora Basica\n\n";
			cout << "1. Suma\n2. Resta\n3. Multiplicacion\n4. Division\n\n";
			cout << "Elige la operacion que deseas realizar: ";
			cin >> operacion;
		} while (operacion < 1 or operacion > 4);

		system("cls");
		cout << "Elige el numero 1: ";
		cin >> numero1;
		cout << "Elige el numero 2: ";
		cin >> numero2;

		CalculadoraSimple operar(operacion, numero1, numero2);
		operar.mostrarResultado();
		cout << endl;

		do {
			cout << "Desea realizar otra operacion de la calculadora? S/N: ";
			cin >> respuestaCalcu;
		} while (respuestaCalcu != 'n' and respuestaCalcu != 'N' and respuestaCalcu != 'S' and respuestaCalcu != 's');

		if (respuestaCalcu == 's' or respuestaCalcu == 'S') {
			repetirCalcu = true;
		}
		else if (respuestaCalcu == 'n' or respuestaCalcu == 'N') {
			repetirCalcu = false;
		}

	} while (repetirCalcu == true);

}

void menuCajero() {
	int opcionUsuario;
	bool decisionRepetir;
	int opcionRepetir;

	GestionBanco usuario1("Pablo Sebastian Quan Montenegro", 500);

	do {
		do {
			system("cls");
			cout << "\tBienvenido al menu del cajero\n\n";
			cout << "1. Consultar estado de cuenta\n";
			cout << "2. Retirar dinero\n";
			cout << "3. Depositar dinero\n";
			cout << "4. Salir\n\n";
			cout << "Digite la opcion a elegir: ";
			cin >> opcionUsuario;
		} while (opcionUsuario < 1 or opcionUsuario > 5);

		switch (opcionUsuario) {
		case 1:
			usuario1.consultarEstadoCuenta();
			break;
		case 2:
			usuario1.retirarDinero();
			break;
		case 3:
			usuario1.depositarDinero();
			break;
		case 4:
			return;
		}

		int repeTempo = 0;
		cout << endl;
		do {
			if (repeTempo > 0)
				system("cls");

			repeTempo += 1;

			cout << "Desea realizar otra accion?\n1. Si\n2. No\nDigite la respuesta: ";
			cin >> opcionRepetir;
		} while (opcionRepetir != 1 and opcionRepetir != 2);
		if (opcionRepetir == 1)
			decisionRepetir = true;
		else if (opcionRepetir == 2)
			decisionRepetir = false;

	} while (decisionRepetir == true);

}

void peliculasTaquilla() {
	Peliculas pelicula1("Kung Fu Panda 4", "Jack Black", "2024", "Animacion", "Todo publico", "16:00");
	Peliculas pelicula2("Atrapados en lo profundo", "Claudio Fäh", "2024", "Accion/Aventura", "B14", "17:00");
	Peliculas pelicula3("Imaginario: Juguete diabólico", "Jeff Wadlow", "2024", "Terror", "B15", "19:00");
	Peliculas pelicula4("Dune: Part Two", "Denis Villeneuve", "2024", "Ciencia Ficcion", "B12", "21:00");

	cout << "\tBienvenido a las peliculas en taquilla de Cinepolis\n\n";
	cout << "Peliculas disponibles: \n\n";

	pelicula1.peliculasDisponibles();
	cout << "\n------------------------------------------------------------------\n";
	pelicula2.peliculasDisponibles();
	cout << "\n------------------------------------------------------------------\n";
	pelicula3.peliculasDisponibles();
	cout << "\n------------------------------------------------------------------\n";
	pelicula4.peliculasDisponibles();
	cout << "\n------------------------------------------------------------------\n";
	system("pause");
}

void repeticion() {
	do {
		system("cls");
		cout << "Desea regresar al menu? S/N: ";
		cin >> respuesta;
	} while (respuesta != 'n' and respuesta != 'N' and respuesta != 'S' and respuesta != 's');

	if (respuesta == 's' or respuesta == 'S') {
		repetir = true;
	}
	else if (respuesta == 'n' or respuesta == 'N') {
		repetir = false;
	}
}
