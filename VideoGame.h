#ifndef VIDEOGAME_H
#define VIDEOGAME_H
#include <iostream>
#include <cstring>
#include "Media.h"

using namespace std;

class VideoGame : public Media {
 public:
  VideoGame();
  void setRating(float newRating);
  void setPublisher(char* newPublisher);
  float getRating();
  char* getPublisher();
  void print();
 protected:
  float rating;
  char* publisher;
};

#endif






