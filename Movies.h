#ifndef MOVIES_H
#define MOVIES_H
#include <iostream>
#include <cstring>
#include "Media.h"

using namespace std;

class Movies : public Media {
 public:
  Movies();
  void setDirector (char* newDirector);
  void setDuration(int newDuration);
  void setRating(float newRating);
  char* getDirector();
  int getDuration();
  float getRating();
  void print();
 protected:
  char* director;
  int duration;
  float rating;
};

#endif
