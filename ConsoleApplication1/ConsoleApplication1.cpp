#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

#ifdef _WIN32
#include <Windows.h>
#else
#include <cstdlib>
#endif

using namespace std;

// Función para mostrar el menú de pausa
void mostrarMenuPausa() {
    cout << "\n\033[1;33m--- Menú de Pausa ---\033[0m\n";
    cout << "1. \033[1;32mContinuar\033[0m\n";
    cout << "2. \033[1;36mReiniciar\033[0m\n";
    cout << "3. \033[1;31mSalir\033[0m\n";
    cout << "---------------------\n";
}

// Función para mostrar el menú de inicio
int mostrarMenuInicio() {
    cout << "\n\033[1;34m--- Menú de Inicio ---\033[0m\n";
    cout << "1. \033[1;32mIniciar Partida\033[0m\n";
    cout << "2. \033[1;31mSalir del Juego\033[0m\n";
    cout << "3. \033[1;35mVisitar mi Canal de YouTube\033[0m\n";
    cout << "------------------------\n";
    int opcion;
    cout << "Selecciona una opción: ";
    cin >> opcion;
    return opcion;
}

// Función para abrir el enlace de YouTube
void abrirYouTube() {
    cout << "Abriendo tu canal de YouTube...\n";
#ifdef _WIN32
    ShellExecuteA(nullptr, "open", "https://www.youtube.com/@andreu1k", nullptr, nullptr, SW_SHOWNORMAL);
#else
    system("xdg-open https://www.youtube.com/@andreu1k");
#endif
}

int main() {
    srand(static_cast<unsigned int>(time(0)));

    int opcionInicio;

    do {
        opcionInicio = mostrarMenuInicio();

        switch (opcionInicio) {
        case 1: {
            // Iniciar una nueva partida
            int numeroSecreto = rand() % 100 + 1;
            int intento, intentosRealizados = 0;
            bool adivinado = false;

            cout << "\n\033[1;34mBienvenido al juego de adivinanzas.\033[0m\n";
            cout << "Intenta adivinar el número secreto entre \033[1;33m1 y 100\033[0m.\n";

            do {
                cout << "Introduce tu intento: ";
                cin >> intento;
                intentosRealizados++;

                if (intento == numeroSecreto) {
                    cout << "\033[1;32m¡Felicidades! ¡Adivinaste el número en " << intentosRealizados << " intentos!\033[0m\n";
                    adivinado = true;
                }
                else if (intento < numeroSecreto) {
                    cout << "\033[1;36mEl número secreto es mayor. Intenta de nuevo.\033[0m\n";
                }
                else {
                    cout << "\033[1;36mEl número secreto es menor. Intenta de nuevo.\033[0m\n";
                }

                // Menú de pausa
                mostrarMenuPausa();
                int opcionPausa;
                cout << "Selecciona una opción: ";
                cin >> opcionPausa;

                switch (opcionPausa) {
                case 1:
                    // Continuar el juego
                    break;
                case 2:
                    // Reiniciar el juego generando un nuevo número secreto
                    numeroSecreto = rand() % 100 + 1;
                    intentosRealizados = 0;
                    cout << "\033[1;36mJuego reiniciado. ¡Buena suerte!\033[0m\n";
                    break;
                case 3:
                    // Salir del juego
                    cout << "\033[1;31mGracias por jugar. ¡Hasta luego!\033[0m\n";
                    return 0;
                default:
                    cout << "\033[1;31mOpción inválida. Por favor, selecciona una opción válida.\033[0m\n";
                    break;
                }
            } while (!adivinado);
            break;
        }
        case 2:
            // Salir del juego
            cout << "\033[1;31mGracias por jugar. ¡Hasta luego!\033[0m\n";
            return 0;
        case 3:
            // Abrir enlace de YouTube
            abrirYouTube();
            break;
        default:
            cout << "\033[1;31mOpción inválida. Por favor, selecciona una opción válida.\033[0m\n";
            break;
        }

    } while (opcionInicio != 2);

    return 0;
}
