## Información sobre el proyecto

### Comandos de git
```
git add .
git commit -m "Mensaje de cambio"
git push origin main
```
```
git branch newBranch 
git checkout newBranch
```

*El menú principal del programa se encuentra por lo pronto en Exercise.cpp pero se planea moverlo a VideoStreamingApp.cpp y usar Exercise.cpp como una instance de toda la aplicación*

### Diagrama UML

_(Es un trabajo en progreso)_
```mermaid 
classDiagram 
    class Biblioteca { 
        - vector Video* videos
        + Biblioteca()
        + ~Biblioteca()
        + void addVideo(Video* video)
        + void printVideos() 
        + void printMovies()
        + void printSeries()
    }
    class Video {
        # string title
        # string id
        # id duracion 
        # string genero 
        + Video() 
        + Video(string, string, int, string) 
        + string mostrarInformacion() 
        ~ *Video()
    }
    class Serie { 
        - vector Episodio* episodios
        + Serie()
        + Serie(string, string, int, string)
        + void addEpisodio(Episodio* episodio)
        + string mostrarInformacion()
        ~ *Serie()
    }

    class Pelicula {
        + Pelicula()
        + string mostrarInformacion()
        + ~ *Pelicula()
    }

    class Episodio { 
        - string title 
        - int temporada
        + string mostrarInformacion()
        + Episodio()
        + Episodio(string, int)
        + ~ *Episodio()
        + operator<(Episodio)
    }
    Biblioteca --|> "1" Video
    Serie --> Video
    Pelicula --> Video
    Episodio --> Serie 


    
```