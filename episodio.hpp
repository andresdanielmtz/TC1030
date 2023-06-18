#pragma once
#include <iostream> 

class Episodio { 
    private: 
        std::string title; 
        int temporada; 
        
    public: 
    int calificacion; 
        std::string mostrarInformacion();
        Episodio(std::string, int,int);
        Episodio();
        virtual ~Episodio();
        bool operator<(const Episodio& e) const;
};