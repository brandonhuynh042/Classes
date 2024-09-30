#include <iostream>
#include <cstring>
#include <iomanip>
#include "Movies.h"

using namespace std;

Movies::Movies() {
  title = new char[50];
  year = 0;
  director = new char[30];
  duration = 0;
  rating = 0.0;
}
void Movies::setDirector(char* newDirector) {
  strcpy(director, newDirector);
}
void Movies::setDuration(int newDuration) {
  duration = newDuration;
}
void Movies::setRating(float newRating) {
  rating = newRating;
}
char* Movies::getDirector() {
  return director;
}
int Movies::getDuration() {
  return duration;
}
float Movies::getRating() {
  return rating;
}
void Movies::print() {
  cout << title << ", " << year << ", " << duration << " minutes, directed by " << director << ", " << setprecision(3) << rating << endl;   
}
void Movies::deleteTitle() {
  delete title;
  delete director;
}
