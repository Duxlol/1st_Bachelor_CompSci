#include "Movie.h"
#ifndef IMDB_H
#define IMDB_H
using namespace std;

class IMDB {
public:
    IMDB(const vector<Movie> &movies);
    IMDB();

    void addMovie(const Movie & movie);
    string toString() const;
    const Movie& getBest() const;
    vector<Movie> getSimilar(const Movie & movie) const;
private:
    vector<Movie> movies;
};

#endif //IMDB_H
