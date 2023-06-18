#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "video.hpp"

class Biblioteca
{
public:
    std::vector<Video *> videos;
    Biblioteca();
    void addVideo(Video *);
    Biblioteca operator+(Video *);
    void printCatalog();            // general
    void printMoviesOrSeries(bool); // true -> movies, false -> series
    void calificarVideo(std::string);
    void showMoviesByCriteria(const std::string, const std::string);
    void showSeriesByCriteria(int);

    void initialParameters();
    void showVideosByCriteria(std::string, std::string);
    void changeGrade();

    void readVideosFromFile(std::string);
    void readCoolFile(std::string);
};