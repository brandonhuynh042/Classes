#include <iostream>
#include <cstring>
#include <iomanip>
#include "VideoGame.h"

using namespace std;

VideoGame::VideoGame() {
  title = new char[50];
  year = 0;
  publisher = new char[30];
  rating = 0.0;
}
void VideoGame::setRating(float newRating) {
  rating = newRating;
}
void VideoGame::setPublisher(char* newPublisher) {
  strcpy(publisher, newPublisher);
}
float VideoGame::getRating() {
  return rating;
}
char* VideoGame::getPublisher() {
  return publisher;
}

void VideoGame::print() {
  cout << title << ", " << year << ", " << publisher << ", rating of " << setprecision(3) << rating << endl;
}

void VideoGame::deleteTitle() {
  delete title;
  delete publisher;
}
