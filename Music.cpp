#include <iostream>
#include <cstring>
#include "Music.h"

using namespace std;

Music::Music() {
  title = new char[50];
  year = 0;
  artist = new char[30];
  duration = 0;
  publisher = new char[30];
}
void Music::setArtist(char* newArtist) {
  strcpy(artist, newArtist);
}
void Music::setDuration(int newDuration) {
  duration = newDuration;
}
void Music::setPublisher(char* newPublisher) {
  strcpy(publisher, newPublisher);
}
char* Music::getArtist() {
  return artist;
}
int Music::getDuration() {
  return duration;
}
char* Music::getPublisher() {
  return publisher;
}

void Music::print() {
  cout << title << ", " << year << ", " << artist << ", " << "duration of " << duration << " minutes, \n published by " << publisher << endl;
}

void Music::deleteTitle() {
  delete title;
  delete publisher;
  delete artist; 
}


