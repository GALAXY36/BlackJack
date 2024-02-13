// BlackJackJC.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

string nombreJugador;

int corazones[13] = { 1,2,3,4,5,6,7,8,9,10,11,12,13 };
int diamantes[13] = { 1,2,3,4,5,6,7,8,9,10,11,12,13 };
int treboles[13] = { 1,2,3,4,5,6,7,8,9,10,11,12,13 };
int picas[13] = { 1,2,3,4,5,6,7,8,9,10,11,12,13 };

int puntosjugador = 0;
int puntoscroupier = 0;


int comprobarValorCarta(int pValorCarta, string pPalo);
int comprobarValorCartaCroupier(int pValorCarta, string pPalo);
int repartirCartaCroupier();


int comprobarValorCarta(int pValorCarta, string pPalo) {
    int lvValor = 0;
    if (pValorCarta == 1) {
        //ES UN AS
        bool valorcorrecto = false;
        int valorAS = 0;
        cout << "La carta es un AS.\n";
        cout << "Quieres que valga 1 o 11?\n";

        while (valorcorrecto == false) {
            int opcvalorAS;
            cin >> opcvalorAS;

              switch (opcvalorAS) {
              case 1:
                  valorAS = 1;
                  valorcorrecto = true;
                  break;
              case 11:
                  valorAS = 11;
                  valorcorrecto = true;
                  break;
              default:
                  cout << "Un AS solo puede valer 1 o 11.\n";
                  cout << "ESCRIBA UN NUMERO VALIDO.\n";
                  cout << "Quieres que valga 1 o 11?\n";
              }
        }
        lvValor = valorAS;
    }
    else if (pValorCarta > 1 && pValorCarta < 11) {
        cout << "La carta es un " << pValorCarta << " de " << pPalo << "\n";
        lvValor = pValorCarta;
    }
    else if (pValorCarta == 11) {
        cout << "La carta es una J de " << pPalo << "\n";
        lvValor = 10;
    }
    else if (pValorCarta == 12) {
        cout << "La carta es una Q de " << pPalo << "\n";
        lvValor = 10;
    }
    else if (pValorCarta == 13) {
        cout << "La carta es una K de " << pPalo << "\n";
        lvValor = 10;
    }
    return lvValor;
}

int comprobarValorCartaCroupier(int pValorCarta, string pPalo) {
    //int lvValorCartaCroupier1 = repartirCartaCroupier();
    int lvValor = 0;
    bool cartaAS1 = false;
    if (pValorCarta == 1 && cartaAS1 == false) {
        //ES UN AS
        int valorAS = 11;
        cout << "La carta es un AS de " << pPalo << "\n";
        lvValor = valorAS;
        cartaAS1 = true;
    }
    else if (pValorCarta == 1 && cartaAS1 == true) {
        //ES UN AS

        if (((puntoscroupier + 11) == 21) || ((puntoscroupier + 11) > 21)) {
            int valorAS = 11;
            cout << "La carta es un AS de " << pPalo << "\n";
            lvValor = valorAS;
        }
        else {
            int valorAS = 1;
            cout << "La carta es un AS de " << pPalo << "\n";
            lvValor = valorAS;
        }
    }
    else if (pValorCarta > 1 && pValorCarta < 11) {
        cout << "La carta es un " << pValorCarta << " de " << pPalo << "\n";
        lvValor = pValorCarta;
    }
    else if (pValorCarta == 11) {
        cout << "La carta es una J de " << pPalo << "\n";
        lvValor = 10;
    }
    else if (pValorCarta == 12) {
        cout << "La carta es una Q de " << pPalo << "\n";
        lvValor = 10;
    }
    else if (pValorCarta == 13) {
        cout << "La carta es una K de " << pPalo << "\n";
        lvValor = 10;
    }
    return lvValor;
}


int repartirCartaCroupier() {

    bool lvCartaCorrecta = false;
    int lvValorCartaCroupier = 0;
    while (lvCartaCorrecta == false) {
        //devuelve vaklor random entre el 0 al 12
        int lvCarta = rand() % 13;
        int lvPalo = rand() % 4;

        switch (lvPalo) {
        case 0:
            if (corazones[lvCarta] > 0) {
                //lvValorCarta = corazones[lvCarta];
                lvValorCartaCroupier = comprobarValorCartaCroupier(corazones[lvCarta], "Corazones");
                lvCartaCorrecta = true;
                corazones[lvCarta] = 0;
                cout << "(Valor de la carta: " << lvValorCartaCroupier << ")" << "\n";
            }
            break;
        case 1:
            if (diamantes[lvCarta] > 0) {
                //lvValorCarta = diamantes[lvCarta];
                lvValorCartaCroupier = comprobarValorCartaCroupier(diamantes[lvCarta], "Diamantes");
                lvCartaCorrecta = true;
                diamantes[lvCarta] = 0;
                cout << "(Valor de la carta: " << lvValorCartaCroupier << ")" << "\n";
            }
            break;
        case 2:
            if (treboles[lvCarta] > 0) {
                //lvValorCarta = treboles[lvCarta];
                lvValorCartaCroupier = comprobarValorCartaCroupier(treboles[lvCarta], "Treboles");
                lvCartaCorrecta = true;
                treboles[lvCarta] = 0;
                cout << "(Valor de la carta: " << lvValorCartaCroupier << ")" << "\n";
            }
            break;
        case 3:
            if (picas[lvCarta] > 0) {
                //lvValorCarta = picas[lvCarta];
                lvValorCartaCroupier = comprobarValorCartaCroupier(picas[lvCarta], "Picas");
                lvCartaCorrecta = true;
                picas[lvCarta] = 0;
                cout << "(Valor de la carta: " << lvValorCartaCroupier << ")" << "\n";
            }
            break;
        }
    }
    return lvValorCartaCroupier;
}



int repartirCarta() {

    bool lvCartaCorrecta = false;
    int lvValorCarta = 0;
    while(lvCartaCorrecta == false){
        //devuelve vaklor random entre el 0 al 12
        int lvCarta = rand() % 13;
        int lvPalo = rand() % 4;

        switch (lvPalo) {
        case 0:
            if (corazones[lvCarta] > 0) {
                //lvValorCarta = corazones[lvCarta];
                lvValorCarta = comprobarValorCarta(corazones[lvCarta], "Corazones");
                lvCartaCorrecta = true;
                corazones[lvCarta] = 0;
                cout << "(Valor de la carta: " << lvValorCarta << ")" << "\n";
            }
            break;
        case 1:
            if (diamantes[lvCarta] > 0) {
                //lvValorCarta = diamantes[lvCarta];
                lvValorCarta = comprobarValorCarta(diamantes[lvCarta], "Diamantes");
                lvCartaCorrecta = true;
                diamantes[lvCarta] = 0;
                cout << "(Valor de la carta: " << lvValorCarta << ")" << "\n";
            }
            break;
        case 2:
            if (treboles[lvCarta] > 0) {
                //lvValorCarta = treboles[lvCarta];
                lvValorCarta = comprobarValorCarta(treboles[lvCarta], "Treboles");
                lvCartaCorrecta = true;
                treboles[lvCarta] = 0;
                cout << "(Valor de la carta: " << lvValorCarta << ")" << "\n";
            }
            break;
        case 3:
            if (picas[lvCarta] > 0) {
                //lvValorCarta = picas[lvCarta];
                lvValorCarta = comprobarValorCarta(picas[lvCarta], "Picas");
                lvCartaCorrecta = true;
                picas[lvCarta] = 0;
                cout << "(Valor de la carta: " << lvValorCarta << ")" << "\n";
            }
            break;
        }
    }
    return lvValorCarta;
}

void iniciojuego() {
    cout << "Bienvenido al BlackJack.JC!!\n\n";
    cout << "Ingrese su nombre: ";
    cin >> nombreJugador;
    cout << "\nHola " << nombreJugador << ", ahora, sabiendo tu nombre.\n";
    cout << "Demos comienzo a la partida:\n\n";
}


int main() {

    srand(static_cast<unsigned int>(time(0)));

    iniciojuego();

    int lvValorCarta = 0;
    int lvValorCartaCroupier = 0;

    // Repartir la primera carta al jugador
    lvValorCarta = repartirCarta();
    puntosjugador = puntosjugador + lvValorCarta;
    cout <<nombreJugador<<", tus puntos son: " << puntosjugador << "\n";

    // Repartir la segunda carta al jugador
    lvValorCarta = repartirCarta();
    puntosjugador = puntosjugador + lvValorCarta;
    cout << nombreJugador << ", tus puntos son: " << puntosjugador << "\n";

    // Repartir la primera carta al croupier
    lvValorCartaCroupier = repartirCartaCroupier();
    puntoscroupier = puntoscroupier + lvValorCartaCroupier;
    cout << "Los puntos del Croupier son: " << puntoscroupier << "\n";

    bool finjuego = false;

    while ((puntosjugador <= 21 && puntoscroupier <= 21) and (finjuego == false)) {


        string seguirjuego = "";
        bool seguirjugando = true;
        bool stopjugador = false;

        while (seguirjugando == true) {
            if (stopjugador == false) {

                cout << nombreJugador << ", tus puntos son: " << puntosjugador << ". Quieres otra carta (Si/No)?" << "\n";
                cin >> seguirjuego;
                for (auto& x : seguirjuego) { // PASAR A MINUSCULAS LA OPCION SELECCIONADA
                    x = tolower(x);
                }

                bool seguircomprobado = false;
                while (seguircomprobado == false) {
                    if ((seguirjuego == "si") or (seguirjuego == "no")) {
                        if (seguirjuego == "si") {
                            //Repartir carta jugador
                            lvValorCarta = repartirCarta();
                            puntosjugador = puntosjugador + lvValorCarta;
                            cout <<nombreJugador<<", tus puntos son: " << puntosjugador << "\n";
                            seguircomprobado = true;
                            seguirjugando = false;
                            stopjugador = true;
                        }
                        else if (seguirjuego == "no") {
                            seguirjugando = false;
                            seguircomprobado = true;
                            stopjugador = true;
                            break;
                        }
                        else {
                            cout << "Error, respuesta incorrecta. Responde (Si/No)." << "\n";
                            cout << "Quieres otra carta?";
                            cin >> seguirjuego;
                            for (auto& x : seguirjuego) { // PASAR A MINUSCULAS LA OPCION SELECCIONADA
                                x = tolower(x);
                            }
                        }
                    }
                }
            }

        }
        if (puntosjugador > 21) {
            finjuego = true;
        }

        if (finjuego == false) {
            while (puntosjugador > puntoscroupier) {
                // Repartir carta al croupier
                lvValorCartaCroupier = repartirCartaCroupier();
                puntoscroupier = puntoscroupier + lvValorCartaCroupier;
                cout << "Los puntos del Croupier son: " << puntoscroupier << "\n";
            }
            if (puntoscroupier > 21) {
                finjuego = true;
            }
        }

    }

    if ((puntosjugador <= 21) && (puntoscroupier <= 21)) {
        if (puntosjugador < puntoscroupier) {
            cout << "DERROTA :(" << "\n" << "La banca ha ganado.";
        }
        else if ((puntosjugador == 21) && (puntoscroupier == 21)) {
            cout << "VICTORIA!!" << "\n" << "Has ganado a la banca.";
        }
        else if (puntosjugador > puntoscroupier) {
            cout << "VICTORIA!!" << "\n" << "Has ganado a la banca.";
        }
    }
    else {
        if (puntosjugador < puntoscroupier) {
            cout << "VICTORIA!!" << "\n" << "Has ganado a la banca.";
        }
        else if (puntosjugador > puntoscroupier) {
            cout << "DERROTA :(" << "\n" << "La banca ha ganado.";
        }
    }


    //Si el juegador tiene menos de 21 puntos, quiere el juegador una carta?


    //Si el jugador no ha perdido y ha termninado, turno del croupier. ha de empatar o superar al juagdor, sin pasarse de 21. 
    

    return 0;
}


// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
