#include <iostream> 
#include <string> 
#include "episodio.hpp"

Episodio::Episodio():title{""},temporada{0}, calificacion{0}
{}

Episodio::Episodio(std::string title, int temporada, int calificacion) {
    this->title = title;
    this->temporada = temporada;
    this->calificacion = calificacion;
}

Episodio::~Episodio() {}

std::string Episodio::mostrarInformacion() {
    return "Tipo: Episodio\nTitle: " + this->title + "\n" +
           "Temporada: " + std::to_string(this->temporada) + "\n" +
           "Capitulo: " + std::to_string(this->calificacion) + "\n"; 

}

bool Episodio::operator<(const Episodio& e) const {
    return this->temporada < e.temporada;
}