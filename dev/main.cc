#include<iostream>

// El exponente es xA o xB según se llame a la función y se modifica en la columna central
// la x es el número correspondiente a la columna derecha del algoritmo
// La y corresponde a la columna izquierda

int fastExponentiation(int exponente, int modulo_p, int base_alfa) {
    int b = exponente;  // Guardamos el exponente original
    int x = 1;          // Inicializamos x a 1
    int y = base_alfa % modulo_p;   // Inicializamos y a alfa mod p
    while ((exponente > 0) && (y > 1)) {
        if ((exponente % 2) != 0) { // Si el exponente es impar
            x = (x * y) % modulo_p;     // Multiplicamos x por y
            exponente = exponente - 1;  // Restamos 1 al exponente
        }
        else {  // Si el exponente es par
            y = (y * y) % modulo_p;     // Elevamos y al cuadrado
            exponente = exponente / 2;  // Dividimos el exponente entre 2
        }
    }
    return x;   // Devolvemos el resultado
}

void showResults(int moduloP, int alfa , int xA, int xB , int yA , int yB , int k) {
    std::cout << "p = " << moduloP;     //
    std::cout << ", α = " << alfa;      //
    std::cout << ", xA = " << xA;       //
    std::cout << ", xB = " << xB;       //  Imprimo los datos (Tanto los recibidos como los calculados)
    std::cout << ", yA = " << yA;       //
    std::cout << ", yB = " << yB;       //
    std::cout << ", k  = " << k;        //
    std::cout << "\n";                  //
}

void diffie(int p, int alpha, int xa, int xb) { // Función que implementa el algoritmo de Diffie-Hellman
    int yA = fastExponentiation(xa , p , alpha);    // Calculamos yA
    int yB = fastExponentiation(xb , p , alpha);    // Calculamos yB

    // Calculamos las dos K , pero dan lo mismo
    int kA = fastExponentiation(xa , p , yB);       // Calculamos kA
    int kB = fastExponentiation(xb , p , yA);       // Calculamos kB
    showResults(p,alpha,xa,xb,yA,yB,kA);        // Mostramos resultados
}

void ejemplosGuion() {  // Ejecuto los ejemplos del guión
    // Ejemplo 1
   diffie(13, 4, 5, 2);
   // Ejemplo 2 
   diffie(43, 23, 25, 33);
   // Ejemplo 3
   diffie(113, 43, 54, 71);
}

void read(int& p, int& alpha, int& xa, int& xb) {

    std::cout << "Introduzca número primo p: "; 
    std::cin >> p;

    std::cout << "Introduzca número alfa (menor que p): ";
    std::cin >> alpha;

    std::cout << "Escoja secreto xA: ";
    std::cin >> xa;
    
    std::cout << "Escoja secreto xB: ";
    std::cin >> xb;
}


int main() {
    int p, xa, xb = 0;
    int alpha,opcion = -1;
    

    std::cout << "----------------------------------------------------\n";
    std::cout << "Práctica 9 - Intercambio de claves de Diffie-Hellman\n";
    std::cout << "----------------------------------------------------\n";
    std::cout << "1.Introducir datos por teclado\n";
    std::cout << "2.Hacer ejemplo del guión\n";
    std::cout << "0. Salir\n";
    
    while (opcion < 0 || opcion > 2) {
        std::cout << "Elija una opción: ";
        std::cin >> opcion;
    }
    
    switch (opcion) {
        case 1: // Opción para introducir datos por teclado
            read(p, alpha, xa, xb);
            std::cout << "----------------------------------------------------\n";
            diffie(p, alpha, xa, xb);
            std::cout << "----------------------------------------------------\n";
            break;
        case 2: // Opción para hacer ejemplos del guión
            std::cout << "----------------------------------------------------\n";
            ejemplosGuion();
            std::cout << "----------------------------------------------------\n";
            break;
        case 0: // Opción para salir
            std::cout << "Saliendo...\n";
            return 0;
    }
    
    return 0;
}