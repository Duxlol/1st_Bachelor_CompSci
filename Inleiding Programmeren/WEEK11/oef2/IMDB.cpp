#include <iostream>
#include "IMDB.h"
using namespace std;

IMDB::IMDB(const vector<Movie> &movies)
        : movies(movies) {
}
IMDB::IMDB() {}

void IMDB::addMovie(const Movie & movie) {
        movies.push_back(movie);
}

string IMDB::toString() const {
        string result;
        for (const Movie &movie : movies) {result += movie.toString() + "\n";}
        return result;
}

const Movie& IMDB::getBest() const {
        const Movie* bestMovie = &movies[0];
        for (const Movie& movie:movies) {
                if (movie.getRating() > bestMovie->getRating()) {
                        bestMovie = &movie;
                }
        }
        return *bestMovie;
}

vector<Movie> IMDB::getSimilar(const Movie & movie) const {
        vector<Movie> similarMovies;
        for (const Movie& m:movies) {
                if (movie.getGenre() == m.getGenre() || abs(m.getRating() - movie.getRating()) <= 1) {
                        similarMovies.push_back(m);
                }
        }
        return similarMovies;
}