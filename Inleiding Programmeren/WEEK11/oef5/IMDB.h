#include "Movie.h"
#ifndef IMDB_H
#define IMDB_H
using namespace std;

class IMDB {
public:
    IMDB(const vector<Movie*> &movies);
    IMDB();


    void addMovie( Movie* movie);
    string toString() const;
    Movie* getBest() const;
    vector<Movie*> getSimilar(Movie* movie) const;
private:
    vector<Movie*> movies;
};

#endif //IMDB_H
