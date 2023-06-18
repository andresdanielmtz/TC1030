#include "serie.hpp"
#include <iostream>

Serie::Serie(std::string title, std::string id, int duracion, std::string genero, int calificacion) : Video(title, id, duracion, genero, calificacion)
{
    this->episodios = std::vector<Episodio *>();
}

Serie::Serie() : Video()
{
    this->episodios = std::vector<Episodio *>();
}

Serie::~Serie() {}

void Serie::printEpisodios()
{
    for (int i = 0; i < this->episodios.size(); i++)
    {
        std::cout << this->episodios[i]->mostrarInformacion() << std::endl;
    }
}

void Serie::addEpisodio(Episodio *e)
{
    this->episodios.push_back(e);
}

void Serie::operator+(Episodio *e)
{
    this->episodios.push_back(e);
}
std::string Serie::mostrarInformacion()
{
    std::string info = "Tipo: Serie\nTitle: " + this->title + "\n" +
                       "ID: " + this->id + "\n" +
                       "Duracion: " + std::to_string(this->duracion) + "\n" +
                       "Genero: " + this->genero + "\n"
                                                   "Calificacion: " +
                       std::to_string(this->calificacion) + "\n"
                                                            "Episodios: " +
                       std::to_string(this->episodios.size()) + "\n";
    return info;
}

std::vector<Episodio *> Serie::getEpisodios()
{
    return this->episodios;
}