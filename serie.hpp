#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "episodio.hpp"
#include "video.hpp"

class Serie : public Video
{
public:
    std::vector<Episodio *> episodios;
    Serie(std::string, std::string, int, std::string, int);
    Serie();
    virtual ~Serie();
    std::vector<Episodio *> getEpisodios();

    void printEpisodios();
    void addEpisodio(Episodio *);
    std::string mostrarInformacion() override;
    void operator+(Episodio *);
};