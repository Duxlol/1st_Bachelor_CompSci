#include <vector>
#include <string>
#include "Actor.h"
#include "Director.h"
using namespace std;
#ifndef MOVIE_H
#define MOVIE_H

class Movie {
public:
    // constructor
    Movie(int year, Director* director, const string &title, const string &genre, vector<Actor*> actors, double rating);
    // getters
    int getYear() const;
    double getRating() const;
    const Director* getDirector() const;
    const string & getTitle() const;
    const string & getGenre() const;
    const vector<Actor*>& getActors() const;

    //setters
    void setYear(int year);
    void setRating(double rating);
    void setDirector(Director* director);
    void setTitle(const string &title);
    void setGenre(const string &genre);
    void setActors(vector<Actor*> actors);

    string toString() const;

    void starring(Actor* actor);

private:
    int year;
    double rating;
    Director* director;
    string title;
    string genre;
    vector<Actor*> actors;
};



#endif //MOVIE_H
