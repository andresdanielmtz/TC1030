#include <iostream>
#include "serie.hpp"
#include "pelicula.hpp"
#include "biblioteca.hpp"
#include "VideoStreamingApp.hpp"
#include "pelicula.hpp"
#include <vector>
#include <string>
#include <limits>

VideoStreamingApp::VideoStreamingApp()
{
}

VideoStreamingApp::~VideoStreamingApp()
{
}
void clearScreen()
{
#if defined(_WIN32) || defined(_WIN64) // Windows
    std::system("cls");
#elif defined(__APPLE__) // macOS
    std::system("clear");
#elif defined(__linux__) // Linux
    std::system("clear");
#endif
}

void VideoStreamingApp::menuPrincipal()
{

    // variables for adding later on

    std::string titulo;
    std::string identificacion;
    int duracion;

    std::string criterio;
    std::cout << "\n\n\n\n\n\nBienvenido a la aplicacion de streaming: NETFLIX 2\n\n\n\n\n\n" << std::endl;
    Biblioteca *biblioteca = new Biblioteca();
    biblioteca->initialParameters();
    while (true)
    {
        std::cout << "1. Agregar video individual (Manual o Automatico)" << std::endl;
        std::cout << "2. Mostrar los videos en general con una cierta calificación o de un cierto género" << std::endl;
        std::cout << "3. Mostrar los episodios de una determinada serie con una calificacion determinada" << std::endl;
        std::cout << "4. Mostrar las películas con cierta calificacion" << std::endl;
        std::cout << "5. Calificar un video de la cartelera" << std::endl;
        std::cout << "6. Salir" << std::endl;
        int opcion;
        std::cin >> opcion;
        switch (opcion)
        {

        case 1:
        {
            std::cout << "\n\n\n¿Qué desea agregar? \n\n\n";
            std::cout << "1. Agregar pelicula" << std::endl;
            std::cout << "2. Agregar serie" << std::endl;
            std::cout << "3. Añadir Series y Peliculas de forma automatica" << std::endl;
            std::cout << "4. Regresar" << std::endl;
            int opcion2;
            std::cin >> opcion2;
            switch (opcion2)
            {
            case 1:
            {

                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // fix for getline

                std::cout << "Nombre de la pelicula:";
                std::string title_ = "";
                std::getline(std::cin, title_);

                std::cout << "ID:";
                std::string id_ = "";
                std::cin >> id_;

                std::cout << "Duración (Minutos):";
                int time_ = 0;
                std::cin >> time_;

                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // fix for getline

                std::cout << "Genero:";
                std::string genre_;
                std::getline(std::cin, genre_);

                std::cout << "Calificacion:";
                int calificacion_;
                std::cin >> calificacion_;

                Pelicula *pelicula = new Pelicula(title_, id_, time_, genre_, calificacion_);
                *biblioteca + pelicula;
                break;
            }

            case 2:
            {
                std::cout << "Nombre de la serie:";

                std::cin >> titulo;

                std::cout << "ID:";
                std::cin >> identificacion;

                std::cout << "Duración:";
                std::cin >> duracion;

                std::cout << "Genero:";
                std::string genre_;
                std::cin >> genre_;

                std::cout << "Calificacion:";
                int calificacion_;
                std::cin >> calificacion_;

                Serie *serie = new Serie(titulo, identificacion, duracion, genre_, calificacion_);
                *biblioteca + serie;

                // cuantos episodios tiene la serie?
                std::cout << "Cuantos episodios tiene la serie?" << std::endl;
                int numEpisodios;
                std::cin >> numEpisodios;
                for (int i = 0; i < numEpisodios; i++)
                {
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cout << "Nombre del episodio:";
                    std::string title_;
                    std::getline(std::cin, title_);

                    std::cout << "Temporada:";
                    int temporada_;
                    std::cin >> temporada_;

                    std::cout << "Calificacion:";
                    int calificacion_;
                    std::cin >> calificacion_;

                    Episodio *episodio = new Episodio(title_, temporada_, calificacion_);
                    serie->addEpisodio(episodio);
                }
                break;
            }
            case 3:
            {
                std::cout << "Nombre del archivo:";
                std::string nombreArchivo;

                std::cin >> nombreArchivo;
                nombreArchivo += ".txt";
                biblioteca->readCoolFile(nombreArchivo);
                break;
            }

            case 4:
            {
                clearScreen();
                break;
            }

            default:
            {
                std::cout << "Opcion invalida" << std::endl; // EXCEPTIONS
                break;
            }
            }
            break;
        }

        case 2:
        {
            clearScreen();
            std::cout << "\n\n\n ¿Qué criterio deseas utilizar para encontrar videos? \n\n\n";
            std::cout << "1. Criterio de género" << std::endl;
            std::cout << "2. Criterio de calificación" << std::endl;
            int opcion3;
            std::cin >> opcion3;
            switch (opcion3)
            {
            case 1:
                clearScreen();
                std::cout << "Ingrese el género que desea buscar: " << std::endl;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // fix for getline
                std::getline(std::cin, criterio);
                clearScreen();
                std::cout << "Videos encontrados de género: " << criterio << std::endl;
                biblioteca->showVideosByCriteria("genre", criterio);
                std::cout << "Presione cualquier tecla para continuar" << std::endl;
                std::cin.ignore();
                std::cin.get();
                clearScreen();
                break;
            case 2:
                clearScreen();
                // TO FINISH YET
                std::cout << "Ingrese la calificación que desea buscar: " << std::endl;
                std::cin >> criterio;
                clearScreen();
                std::cout << "Videos encontrados con calificación: " << criterio << std::endl;
                biblioteca->showVideosByCriteria("rating", criterio);
                std::cout << "Presione cualquier tecla para continuar" << std::endl;
                std::cin.ignore();
                std::cin.get();
                clearScreen();
                break;
            default:
                std::cout << "Opcion invalida" << std::endl; // EXCEPTIONS
                break;
            }
            break;
        }
        case 3:
        {
            // mostrar las series dependiendo de una calificacion
            clearScreen();
            int value;
            std::cout << "Ingrese la calificación que desea buscar: " << std::endl;
            std::cin >> value;
            biblioteca->showSeriesByCriteria(value);
            std::cout << "Presione cualquier tecla para continuar" << std::endl;
            std::cin.ignore();
            std::cin.get();
            clearScreen();
            break;
        }

        case 4:
            clearScreen();
            // mostrar peliculas con cierta calificacion
            std::cout << "Ingrese la calificación que desea buscar: " << std::endl;
            std::cin >> criterio;
            biblioteca->showMoviesByCriteria("rating", criterio);
            std::cout << "Presione cualquier tecla para continuar" << std::endl;
            std::cin.ignore();
            std::cin.get();
            clearScreen();
            break;

        case 5:
        {
            biblioteca->changeGrade();
            break;
        }

        case 6:
            clearScreen();
            std::cout << "Gracias por usar la aplicacion de streaming: NETFLIX 2 \n ¡Nos vemos pronto!" << std::endl;
            return;
        default:
            std::cout << "Opcion invalida" << std::endl; // EXCEPTIONS
            break;
        }
    }
}
