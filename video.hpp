#pragma once
#include <iostream>
#include <string>

class Video
{
protected:
    std::string id; // only for developers 

public:
    std::string title;
    int duracion;
    std::string genero;
    int calificacion;

    Video();
    Video(std::string, std::string, int, std::string, int);
    virtual std::string mostrarInformacion() = 0;
    virtual ~Video();
};