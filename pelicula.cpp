#include "pelicula.hpp" 
#include <iostream>

Pelicula::Pelicula() : Video() {}

Pelicula::Pelicula(std::string title, std::string id, int duracion, std::string genero, int calificacion) : Video(title, id, duracion, genero, calificacion) {}

Pelicula::~Pelicula() {}


std::string Pelicula::mostrarInformacion() {
    std::string info = "Tipo: Pelicula\nTitle: " + this->title + "\n" +
                       "ID: " + this->id + "\n" +
                       "Duracion: " + std::to_string(this->duracion) + "\n" +
                       "Genero: " + this->genero + "\n" +
                          "Calificacion: " + std::to_string(this->calificacion) + "\n";
    return info;
}
