#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <limits>

using namespace std;

// Función para mostrar el menú de pausa
void mostrarMenuPausa() {
    cout << "\n--- Menú de Pausa ---\n";
    cout << "1. Continuar\n";
    cout << "2. Reiniciar\n";
    cout << "3. Salir\n";
    cout << "---------------------\n";
}

// Función para mostrar el menú de inicio
int mostrarMenuInicio() {
    int opcion;
    do {
        cout << "\n--- Menú de Inicio ---\n";
        cout << "1. Iniciar Partida\n";
        cout << "2. Salir del Juego\n";
        cout << "3. Visitar mi Canal de YouTube\n";
        cout << "4. Ver el código en GitHub\n";
        cout << "------------------------\n";
        cout << "Selecciona una opción: ";
        cin >> opcion;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

    } while (opcion < 1 || opcion > 4);

    return opcion;
}

// Función para abrir el enlace de YouTube
void abrirYouTube() {
    cout << "Abriendo tu canal de YouTube...\n";
    // Aquí deberías abrir el enlace a YouTube en el navegador web
}

// Función para abrir el enlace de GitHub
void abrirGitHub() {
    cout << "Abriendo el código en GitHub...\n";
    system("start https://github.com/Project-Z1K/juego-en-consola-app-c-");
}

int main() {
    srand(static_cast<unsigned int>(time(0)));

    int opcionInicio;
    int puntuacion = 0;

    do {
        opcionInicio = mostrarMenuInicio();

        switch (opcionInicio) {
        case 1: {
            int numeroSecreto = rand() % 100 + 1;
            int intento, intentosRealizados = 0;
            bool adivinado = false;

            cout << "\nBienvenido al juego de adivinanzas.\n";
            cout << "Intenta adivinar el número secreto entre 1 y 100.\n";

            do {
                cout << "Introduce tu intento: ";
                cin >> intento;
                intentosRealizados++;

                if (intento == numeroSecreto) {
                    cout << "¡Felicidades! ¡Adivinaste el número en " << intentosRealizados << " intentos!\n";

                    int puntuacionActual = 1000 / intentosRealizados;
                    cout << "Tu puntuación en esta partida es: " << puntuacionActual << " puntos.\n";
                    puntuacion += puntuacionActual;
                    cout << "Tu puntuación total es: " << puntuacion << " puntos.\n";
                }
                else if (intento < numeroSecreto) {
                    cout << "El número secreto es mayor. Intenta de nuevo.\n";
                }
                else {
                    cout << "El número secreto es menor. Intenta de nuevo.\n";
                }

                mostrarMenuPausa();
                int opcionPausa;
                cout << "Selecciona una opción: ";
                cin >> opcionPausa;

                switch (opcionPausa) {
                case 1:
                    break;
                case 2:
                    numeroSecreto = rand() % 100 + 1;
                    intentosRealizados = 0;
                    cout << "Juego reiniciado. ¡Buena suerte!\n";
                    break;
                case 3:
                    cout << "Gracias por jugar. ¡Hasta luego!\n";
                    return 0;
                case 4:
                    abrirGitHub();
                    break;
                default:
                    cout << "Opción inválida. Por favor, selecciona una opción válida.\n";
                    break;
                }
            } while (!adivinado);
            break;
        }
        case 2:
            cout << "Gracias por jugar. ¡Hasta luego!\n";
            return 0;
        case 3:
            abrirYouTube();
            break;
        case 4:
            abrirGitHub();
            break;
        default:
            cout << "Opción inválida. Por favor, selecciona una opción válida.\n";
            break;
        }
    } while (opcionInicio != 2);

    return 0;
}
