#include <iostream>
#include <vector>
#include <string>
using namespace std;
#ifndef MOVIE_H
#define MOVIE_H



class Movie {
public:
    // constructor
    Movie(int year, const string &director, const string &title, const string &genre, const vector<string> &actors, double rating);
    // getters
    int getYear() const;
    double getRating() const;
    const string & getDirector() const;
    const string & getTitle() const;
    const string & getGenre() const;
    const vector<string> & getActors() const;

    //setters
    void setYear(int year);
    void setRating(double rating);
    void setDirector(const string &director);
    void setTitle(const string &title);
    void setGenre(const string &genre);
    void setActors(const vector<string> &actors);

    string toString() const;

    void starring(const string &actor);

private:
    int year;
    double rating;
    string director;
    string title;
    string genre;
    vector<string> actors;
};



#endif //MOVIE_H
