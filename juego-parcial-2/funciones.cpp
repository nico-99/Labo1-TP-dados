#include <iostream>
#include <ctime>
#include "funciones.h"
using namespace std;


//Numero aleotorio
int numeroAleatorio(int inicio, int fin){
    return rand() % ( fin - inicio + 1) + inicio;
}

//Mostrar creditos
int mostrarCreditos(){

    cout <<endl <<endl;
    cout <<"Nicolas Dorazio" <<endl;
    cout <<"Lucas Guariniello" <<endl;
    //cout <<"Tomas Olmedo" <<endl;
}

//Funcion para tirar un dado y ver quien comienza la partida
int tiradaInicial(){

    //Pido los nombres de los jugadores
    string jugadorA, jugadorB;

    cout << "Jugador A ingrese su nombre: ";
    cin >> jugadorA;
    cout << "Jugador B ingrese su nombre: ";
    cin >> jugadorB;

    int tiradaJugadorA = numeroAleatorio(1, 6);
    int tiradaJugadorB = numeroAleatorio(1, 6);

    while(tiradaJugadorA == tiradaJugadorB){
        tiradaJugadorA = numeroAleatorio(1, 6);
        tiradaJugadorB = numeroAleatorio(1, 6);
    }

    cout <<endl <<endl;
    cout << "Primer tirada para ver quien empieza " <<endl;
    cout <<jugadorA <<":" << tiradaJugadorA <<endl;
    cout <<jugadorB <<":" << tiradaJugadorB <<endl;

    if(tiradaJugadorA > tiradaJugadorB){
        cout <<endl <<endl;
        cout << "Empieza: " <<jugadorA;

    } else {
        cout <<endl <<endl;
        cout << "Empieza: " <<jugadorB;
    }

}

//primer tirada de dados de 12
int dadosDoce[12] = {}, numeroObjetivo=0;

int tirarDadosDoce(){
    cout <<endl <<endl;

    for(int i=0; i<2; i++){
        dadosDoce[i] = numeroAleatorio(1, 12);
        numeroObjetivo += dadosDoce[i];
    }

    for(int i=0; i<2; i++){
        cout << "dados de 12 N: " << i+1 << " " << dadosDoce[i] <<endl;
    }

    cout <<endl;
    cout << "Numero Objetivo: " << numeroObjetivo <<endl;
}

//Tirar dados stock
int tirarDadosStock(){
    cout <<endl;

    int dadosStock1[6] , dadosStock2[6];

    for(int i=0; i<6; i++){
        dadosStock1[i] = numeroAleatorio(1, 6);
    }

    for(int i=0; i<6; i++){
        cout << "dados Stock N: " << i+1 << " " << dadosStock1[i] <<endl;
    }

    cout <<endl;
}



//Funcion que engloba a todas las demas que componen el juego
int jugar(){

    tiradaInicial();
    tirarDadosDoce();
    tirarDadosStock();

    cout <<endl <<endl;

}

//Mostrar Menu
int mostrarMenu(){
    int opcion;

        cout <<endl <<endl;
        cout << "REVENGE" <<endl;
        cout << "---------------" <<endl;
        cout << "1- JUGAR" <<endl;
        cout << "2- ESTADISTICAS" <<endl;
        cout << "3- CREDITOS" <<endl;
        cout << "---------------" <<endl;
        cout << "0- SALIR" <<endl;

        cin >> opcion;

    do{
        switch(opcion){
            case 1:
            cout <<endl <<endl;
            jugar();
            break;

            case 2:
            cout << "Estadisticas" <<endl;
            break;

            case 3:
            mostrarCreditos();
            break;

            case 0:
            return 0;
            break;
        }
    }
    while(opcion);
}
