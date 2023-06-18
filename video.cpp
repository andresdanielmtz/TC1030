#include "video.hpp"

Video::Video():title{""}, id{""}, duracion{0}, genero{""}, calificacion{0}
{}

Video::Video(std::string title, std::string id, int duracion, std::string genero, int calificacion)
{
    this->title = title;
    this->id = id;
    this->duracion = duracion;
    this->genero = genero;
    this->calificacion = calificacion;
}

Video::~Video() {}