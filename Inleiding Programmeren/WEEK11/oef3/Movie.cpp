#include "Movie.h"
#include <iostream>
using namespace std;
// constructors
Movie::Movie(int year, const string &director, const string &title, const string &genre, const vector<string> &actors, double rating)
        : year(year),
          rating(rating),
          director(director),
          title(title),
          genre(genre),
          actors(actors) {
}
//getters
int Movie::getYear() const {
    return year;
}

double Movie::getRating() const {
    return rating;
}
const string & Movie::getDirector() const {
    return director;
}

const string & Movie::getTitle() const {
    return title;
}

const string & Movie::getGenre() const {
    return genre;
}
const vector<string>& Movie::getActors() const {
    return actors;
}

// setters
void Movie::setDirector(const string &director) {
    this->director = director;
}

void Movie::setTitle(const string &title) {
    this->title = title;
}

void Movie::setGenre(const string &genre) {
    this->genre = genre;
}

void Movie::setActors(const vector<string> &actors) {
    this->actors = actors;
}

void Movie::setYear(int year) {
    this->year = year;
}

void Movie::setRating(double rating) {
    this->rating = rating;
}

string Movie::toString() const {
    return title + " (" + to_string(year) + ")";
}

void Movie::starring(const string &actor) {
    actors.push_back(actor);
}