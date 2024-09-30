#ifndef MUSIC_H
#define MUSIC_H
#include <iostream>
#include <cstring>
#include "Media.h"

using namespace std;

class Music : public Media {
 public:
  Music();
  void setArtist (char* newArtist);
  void setDuration(int newDuration);
  void setPublisher(char* newPublisher);
  char* getArtist();
  int getDuration();
  char* getPublisher();
  void print();
  void deleteTitle();
 protected:
  char* artist;
  int duration;
  char* publisher;
};

#endif




