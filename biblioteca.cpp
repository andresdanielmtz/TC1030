#include "biblioteca.hpp"
#include "video.hpp"
#include "pelicula.hpp"
#include "serie.hpp"
#include "episodio.hpp"
#include <fstream>
#include <iostream>
#include <sstream>
#include <limits>

Biblioteca::Biblioteca()
{
    this->videos = std::vector<Video *>();
}
void Biblioteca::addVideo(Video *video)
{
    this->videos.push_back(video);
}

void Biblioteca::printCatalog()
{
    for (int i = 0; i < this->videos.size(); i++)
    {
        this->videos[i]->mostrarInformacion();
    }
}

void Biblioteca::printMoviesOrSeries(bool onlyMovies)
{
    for (int i = 0; i < this->videos.size(); i++)
    {
        Pelicula *pelicula = dynamic_cast<Pelicula *>(this->videos[i]);
        Serie *serie = dynamic_cast<Serie *>(this->videos[i]);

        if ((onlyMovies && pelicula) || (!onlyMovies && serie))
        {
            std::cout << this->videos[i]->mostrarInformacion();
        }
    }
}

void Biblioteca::changeGrade()
{
    std::cout << "Ingrese el nombre del video que desea calificar: " << std::endl;

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::string name;
    std::getline(std::cin, name);

    std::cout << "Ingrese la nueva calificacion: " << std::endl;
    std::string newGrade;
    std::cin >> newGrade;
    std::cin.ignore(); // Clear the newline character from the buffer

    for (int i = 0; i < this->videos.size(); i++)
    {
        if (this->videos[i]->title == name)
        {
            this->videos[i]->calificacion = std::stoi(newGrade);
        }
    }
}

void Biblioteca::showVideosByCriteria(std::string criteria, std::string value = "")
{ // criteria = "genre" or "rating"
    for (int i = 0; i < this->videos.size(); i++)
    {
        Video *currVideo = this->videos[i];

        if (currVideo && (criteria == "genre" && currVideo->genero == value) ||
            (criteria == "rating" && (value.empty() || currVideo->calificacion == std::stoi(value))))
        {
            std::cout << this->videos[i]->mostrarInformacion() << std::endl;
        }
    }
    std::cout << "\n"; // lmao
}
void Biblioteca::showMoviesByCriteria(const std::string criteria, const std::string value = "")
{
    // separa las peliculas de las series
    Biblioteca peliculas;
    for (int i = 0; i < this->videos.size(); i++)
    {
        Pelicula *pelicula = dynamic_cast<Pelicula *>(this->videos[i]);

        if (pelicula)
        {
            // añade esta pelicula a un nuevo vector
            peliculas.videos.push_back(pelicula);
        }
    }
    peliculas.showVideosByCriteria(criteria, value);
}
void Biblioteca::showSeriesByCriteria(int rating)
{
    for (int i = 0; i < this->videos.size(); i++)
    {
        Serie *serie = dynamic_cast<Serie *>(this->videos[i]);

        if (serie && videos[i]->calificacion == rating)
        {
            std::cout << "Información de la serie:\n";
            std::cout << serie->mostrarInformacion() << std::endl;
            std::cout << "Episodios:\n";
            serie->printEpisodios();
        }
    }
}
Biblioteca Biblioteca::operator+(Video *video)
{
    this->videos.push_back(video);
    return *this;
}

void Biblioteca::calificarVideo(std::string titulo)
{
    int calificacion;
    for (int i = 0; i < this->videos.size(); i++)
    {
        if (this->videos[i]->title == titulo)
        {
            std::cout << "Ingrese la calificacion que le dara al video: ";
            std::cin >> calificacion;
            this->videos[i]->calificacion = calificacion;
        }
    }
}
void Biblioteca::initialParameters()
{
    // create movie vector
    // añadir nueva pelicula con el operador sobrecargado de Biblioteca
    // Pelicula *piña = new Pelicula("The Godfather", "1", 175, "Drama", 1);
    // *this + piña;
    *this + new Pelicula("Whiplash", "4", 420, "Action", 5);
    *this + new Pelicula("Sharks", "1", 175, "Drama", 1);
    *this + new Pelicula("The Batman", "2", 202, "Action", 4);
    *this + new Pelicula("The Godfather", "3", 162, "Drama", 3);
    *this + new Pelicula("The Shawshank Redemption", "1", 142, "Comedy", 5);

    // add vectors
    // this->showMoviesByCriteria("genre", "Comedy");
    // crea 3 episodios

    // mete los episodios a un objeto serie

    // crea una serie y ponle episodios
    Serie *serie = new Serie("The Office", "1", 22, "Comedy", 3);
    serie->addEpisodio(new Episodio("Pilot", 1, 1));
    serie->addEpisodio(new Episodio("Diversity Day", 1, 2));
    serie->addEpisodio(new Episodio("Health Care", 1, 3));
    // agrega la serie al vector de videos
    *this + serie;
}

void Biblioteca::readCoolFile(std::string fileName)
{
    std::ifstream file(fileName);
    std::string line;
    std::string type, title, genre, id, episodeTitle;
    int duration, rating, season, episodeRating;

    if (file.is_open())
    {
        while (getline(file, line))
        {
            if (line == "## Pelicula")
            {
                type = "Pelicula";

                // Read Pelicula details
                getline(file, line); // Skip the line "Id: [id]"
                id = line.substr(line.find(":") + 2);

                getline(file, line); // Read the line "Title: [title]"
                title = line.substr(line.find(":") + 2);

                getline(file, line); // Read the line "Duration: [duration]"
                duration = std::stoi(line.substr(line.find(":") + 2));

                getline(file, line); // Read the line "Genre: [genre]"
                genre = line.substr(line.find(":") + 2);

                getline(file, line); // Read the line "Rating: [rating]"
                rating = std::stoi(line.substr(line.find(":") + 2));

                *this + new Pelicula(title, id, duration, genre, rating);
            }
            else if (line == "## Serie")
            {
                type = "Serie";

                // Read Serie details
                getline(file, line); // Skip the line "Id: [id]"
                id = line.substr(line.find(":") + 2);

                getline(file, line); // Read the line "Title: [title]"
                title = line.substr(line.find(":") + 2);

                getline(file, line); // Read the line "Duration: [duration]"
                duration = std::stoi(line.substr(line.find(":") + 2));

                getline(file, line); // Read the line "Genre: [genre]"
                genre = line.substr(line.find(":") + 2);

                getline(file, line); // Read the line "Rating: [rating]"
                rating = std::stoi(line.substr(line.find(":") + 2));

                *this + new Serie(title, id, duration, genre, rating);
            }
            else if (line == "## Episodio")
            {
                type = "Episodio";
                std::string serieTitle;

                // Read Episodio details
                getline(file, line); // Skip the line "Id: [id]"
                getline(file, line); // Read the line "Serie Title: [serieTitle]"
                serieTitle = line.substr(line.find(":") + 2);

                getline(file, line); // Read the line "Season: [season]"
                season = std::stoi(line.substr(line.find(":") + 2));

                getline(file, line); // Read the line "Episode Title: [episodeTitle]"
                episodeTitle = line.substr(line.find(":") + 2);

                getline(file, line); // Read the line "Episode Rating: [episodeRating]"
                episodeRating = std::stoi(line.substr(line.find(":") + 2));

                // Find the corresponding Serie by title
                Serie *serie = nullptr;
                for (int i = 0; i < this->videos.size(); i++)
                {
                    if (dynamic_cast<Serie *>(this->videos[i]) && this->videos[i]->title == serieTitle)
                    {
                        serie = dynamic_cast<Serie *>(this->videos[i]);
                        break;
                    }
                }

                // Add the episode to the Serie
                if (serie != nullptr)
                {
                    serie->addEpisodio(new Episodio(episodeTitle, season, episodeRating));
                }
            }
        }
        std::cout << "\n Archivo leido con exito \n";
        file.close();
    }
}
