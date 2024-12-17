#include <iostream>
#include "IMDB.h"
using namespace std;

IMDB::IMDB(const vector<Movie*> &movies)
        : movies(movies) {
}
IMDB::IMDB() {}

void IMDB::addMovie(Movie* movie) {
        movies.push_back(movie);
}

string IMDB::toString() const {
        string result;
        for (const Movie* movie : movies) {result += movie->toString() + "\n";}
        return result;
}

Movie* IMDB::getBest() const {
        Movie* bestMovie = movies[0];
        for ( Movie* movie:movies) {
                if (movie->getRating() > bestMovie->getRating()) {
                        bestMovie = movie;
                }
        }
        return bestMovie;
}

vector<Movie*> IMDB::getSimilar(Movie* movie) const {
        vector<Movie*> similarMovies;
        for (Movie* m:movies) {
                if (movie->getGenre() == m->getGenre() || abs(m->getRating() - movie->getRating()) <= 1) {
                        similarMovies.push_back(m);
                }
        }
        return similarMovies;
}
