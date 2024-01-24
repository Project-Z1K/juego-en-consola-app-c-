#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <limits>

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
    int opcion;
    do {
        cout << "\n\033[1;34m--- Menú de Inicio ---\033[0m\n";
        cout << "1. \033[1;32mIniciar Partida\033[0m\n";
        cout << "2. \033[1;31mSalir del Juego\033[0m\n";
        cout << "3. \033[1;35mVisitar mi Canal de YouTube\033[0m\n";
        cout << "------------------------\n";
        cout << "Selecciona una opción: ";
        cin >> opcion;

        if (cin.fail()) {
            // Manejar entrada no válida (por ejemplo, caracteres en lugar de números)
            cin.clear();  // Limpiar el estado de error
        }

    } while (opcion < 1 || opcion > 3);

    return opcion;
}

// Función para abrir el enlace de YouTube
void abrirYouTube() {
    cout << "Abriendo tu canal de YouTube...\n";
#ifdef _WIN32
    ShellExecute(nullptr, L"open", L"https://www.youtube.com/@andreu1k", nullptr, nullptr, SW_SHOWNORMAL);
#else
    system("xdg-open https://www.youtube.com/@andreu1k");
#endif
}

int main() {
    srand(static_cast<unsigned int>(time(0)));

    int opcionInicio;
    int puntuacion = 0; // Inicializar la puntuación

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

                    // Calcular y mostrar la puntuación
                    const int PUNTUACION_MAXIMA = 1000;
                    int puntuacionActual = PUNTUACION_MAXIMA / intentosRealizados;
                    cout << "\033[1;36mTu puntuación en esta partida es: " << puntuacionActual << " puntos.\033[0m\n";

                    // Sumar la puntuación actual al marcador
                    puntuacion += puntuacionActual;
                    cout << "\033[1;36mTu puntuación total es: " << puntuacion << " puntos.\033[0m\n";
                }
                else if (intento < numeroSecreto) {
                    cout << "\033[1;36mEl número secreto es mayor. Intenta de nuevo.\033[0m\n";
                }
                else {
                    cout << "\033[1;36mEl número secreto es menor. Intenta de nuevo.\033[0m\n";
                }

            } while (!adivinado);

            // Menú de pausa después de adivinar el número
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
                break;
            case 3:
                // Salir del juego
                cout << "\033[1;31mGracias por jugar. ¡Hasta luego!\033[0m\n";
                return 0;
            default:
                cout << "\033[1;31mOpción inválida. Por favor, selecciona una opción válida.\033[0m\n";
                break;
            }
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
