#include "Movie.h"
#include <iostream>
using namespace std;
// constructors
Movie::Movie(int year, Director* director, const string &title, const string &genre, const vector<Actor*> actors, double rating)
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
const Director* Movie::getDirector() const {
    return director;
}

const string & Movie::getTitle() const {
    return title;
}

const string & Movie::getGenre() const {
    return genre;
}
const vector<Actor*>& Movie::getActors() const {
    return actors;
}

// setters
void Movie::setDirector(Director* director) {
    this->director = director;
}

void Movie::setTitle(const string &title) {
    this->title = title;
}

void Movie::setGenre(const string &genre) {
    this->genre = genre;
}

void Movie::setActors(vector<Actor*> actors) {
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

void Movie::starring(Actor* actor) {
    actors.push_back(actor);
}