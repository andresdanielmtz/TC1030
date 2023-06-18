#pragma once 
#include <iostream> 
#include <string> 
#include "video.hpp"

class Pelicula : public Video { 
    
    public: 
        Pelicula(); 
        Pelicula(std::string, std::string, int, std::string, int);
        virtual ~Pelicula(); 
        
        std::string mostrarInformacion();
};
