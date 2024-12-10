#include <iostream>
#include <vector>
#include <string>
using namespace std;
#ifndef MOVIE_H
#define MOVIE_H



class Movie {
public:
    int getYear() const;
    double getRating() const;
    string getDirector() const;
    string getTitle() const;
    string getGenre() const;
    vector<string> getActors() const;

    // setters
    void setYear(int year);
    void setRating(double rating);
    void setDirector(const string& director);


    void set_year(int year) {
        this->year = year;
    }

    void set_rating(double rating) {
        this->rating = rating;
    }

    void set_director(const string &director) {
        this->director = director;
    }

    void set_title(const string &title) {
        this->title = title;
    }

    void set_genre(const string &genre) {
        this->genre = genre;
    }

    void set_actors(const vector<string> &actors) {
        this->actors = actors;
    }



private:
    int year;
    double rating;
    string director;
    string title;
    string genre;
    vector<string> actors;

    public:
        Movie(int year, double rating, const string &director, const string &title, const string &genre,
            const vector<string> &actors);

    // getters

};



#endif //OEF1_H
