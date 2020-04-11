//#include "stdafx.h" // Permite compilar en Visual Studio
#include <iostream>
#include <map> // Para coleccionar menu.
#include <string>
#include <cctype> // toupper();
#include <limits> // Valida entrada por teclado.
#include "PriorityQueue.h"
//-------------------------
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::toupper;
// Valida entrada por teclado.
using std::streamsize;
//-------------------------
enum class MenuCola
{
    AGREGAR = 1,
    REMOVER,
    VACIAR,
    BUSCAR,
    MOSTRAR
};
// ------------------------
void validarNumero(int &numero, string mensaje);
unsigned short mostrarTipoColas();
bool haSalido();
void mostrarColaPrioridad(const int tamano);
void mostrarColaSimple(const int tamano);
//------------------------
int main(int argc, char **argv)
{
    enum class MenuPrincipal
    {
        COLA_SIMPLE = 1,
        COLA_PRIORIDAD
    };
    // Tipo de colas
    std::map<unsigned short, MenuPrincipal> opcionesMenu;
    opcionesMenu[1] = MenuPrincipal::COLA_SIMPLE;
    opcionesMenu[2] = MenuPrincipal::COLA_PRIORIDAD;
    unsigned short opcion;
    int tamano;
    // ---------------------------------------
    bool haTerminado = false;
    while (!haTerminado)
    {
        try
        {
            opcion = mostrarTipoColas(); // Menu de colas.
            validarNumero(tamano, "Ingrese tamano de la cola: ");
            switch (opcionesMenu[opcion])
            {
            case MenuPrincipal::COLA_SIMPLE:
                mostrarColaSimple(tamano);
                break;
            case MenuPrincipal::COLA_PRIORIDAD:
                mostrarColaPrioridad(tamano);
                break;
            default:
                haTerminado = haSalido();
            }
        }
        catch (const string &e)
        {
            cout << e;
        }
        cout << "\n\n";
        cout << "Presione ENTER para continuar...";
        cin.ignore();
        cin.get();
        cout << "\n\n";
        return 0;
    }
}
void validarNumero(int &numero, string mensaje)
{
    bool esValido = false;
    while (!esValido)
    {
        cout << mensaje;
        if (cin >> numero)
        {
            esValido = true;
        }
        else
        {
            cin.clear();
            cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
        }
        cout << "\n\n";
    }
}
unsigned short mostrarTipoColas()
{
    int opcion;
    bool esValida = false;
    string menu = "\t\tSelecciona tipo de cola que desea a usar: \n";
    menu.append("1. Cola Simple.\n");
    menu.append("2. Cola de prioridad.\n");
    menu.append("0. Salir.\n\n");
    while (!esValida)
    {
        validarNumero(opcion, menu);
        esValida = opcion >= 0 && opcion <= 2;
    }
    return opcion;
}
void mostrarColaPrioridad(const int tamano)
{
    // Colas menu.
    std::map<unsigned short, MenuCola> opciones;
    opciones[1] = MenuCola::AGREGAR;
    opciones[2] = MenuCola::REMOVER;
    opciones[3] = MenuCola::VACIAR;
    opciones[4] = MenuCola::BUSCAR;
    opciones[5] = MenuCola::MOSTRAR;
    //---------------------------
    int opcion;
    bool esValida = false;
    int num;
    PriorityQueue cola(tamano);
    // Cola de prioridad;
    string menu = "\t\tElija la opcion que desea dentro del plano: \n";
    menu.append("1. Agregar un numero.\n");
    menu.append("2. Remover un numero.\n");
    menu.append("3. Vaciar todos los numeros.\n");
    menu.append("4. Buscar un numero.\n");
    menu.append("5. Mostrar numeros.\n");
    menu.append("0. Salir.\n\n");
    bool haTerminado = false;
    while (!haTerminado)
    {
        while (!esValida)
        {
            validarNumero(opcion, menu);
            esValida = opcion >= 0 && opcion <= 5;
        }
        switch (opciones[opcion])
        {
        case MenuCola::AGREGAR:
            cout << "Ingrese numero para cola: ";
            cin >> num;
            int prioridad;
            cout << "Ingrese prioridad en la cola: ";
            cin >> prioridad;
            cola.add(num, prioridad);
            break;
        case MenuCola::REMOVER:
            cola.remove(num);
            break;
        case MenuCola::VACIAR:
            cola.clear();
            break;
        case MenuCola::BUSCAR:
            cout << "Ingrese numero para buscar en cola: ";
            cin >> num;
            num = cola.search(num);
            (num == -1) ? cout << "El elemento no esta en la cola.\n" : cout << "El elemento está en la posición " << num << " de la cola";
            break;
        case MenuCola::MOSTRAR:
            cout << cola.toString();
            break;
        default:
            haTerminado = haSalido();
            break;
        }
        esValida = false;
    }
}
void mostrarColaSimple(const int tamano)
{
    // Colas menu.
    std::map<unsigned short, MenuCola> opciones;
    opciones[1] = MenuCola::AGREGAR;
    opciones[2] = MenuCola::REMOVER;
    opciones[3] = MenuCola::VACIAR;
    opciones[4] = MenuCola::BUSCAR;
    opciones[5] = MenuCola::MOSTRAR;
    //---------------------------
    int opcion;
    bool esValida = false;
    int num;
    Queue cola(tamano);
    // Cola de prioridad;
    string menu = "\t\tElija la opcion que desea dentro del plano: \n";
    menu.append("1. Agregar un numero.\n");
    menu.append("2. Remover un numero.\n");
    menu.append("3. Vaciar todos los numeros.\n");
    menu.append("4. Buscar un numero.\n");
    menu.append("5. Mostrar numeros.\n");
    menu.append("0. Salir.\n\n");
    bool haTerminado = false;
    while (!haTerminado)
    {
        while (!esValida)
        {
            validarNumero(opcion, menu);
            esValida = opcion >= 0 && opcion <= 5;
        }
        switch (opciones[opcion])
        {
        case MenuCola::AGREGAR:
            cout << "Ingrese numero para cola: ";
            cin >> num;
            cola.add(num);
            break;
        case MenuCola::REMOVER:
            cola.remove(num);
            break;
        case MenuCola::VACIAR:
            cola.clear();
            break;
        case MenuCola::BUSCAR:
            cout << "Ingrese numero para buscar en cola: ";
            cin >> num;
            num = cola.search(num);
            (num == -1) ? cout << "El elemento no esta en la cola.\n" : cout << "El elemento está en la posición " << num << " de la cola";
            break;
        case MenuCola::MOSTRAR:
            cout << cola.toString();
            break;
        default:
            haTerminado = haSalido();
            break;
        }
        esValida = false;
    }
}
bool haSalido()
{
    char salir;
    bool esValida = false; // Valida entrada por teclado del siguiente mensaje.
    while (!esValida)
    {
        cout << "Desea salir del programa?[S/N]: ";
        cin >> salir;
        salir = toupper(salir);                  // Convierte a mayuscula la opcion.
        esValida = salir == 'S' || salir == 'N'; // Condicion de entrada por teclado.
    }
    return (salir == 'S');
}
