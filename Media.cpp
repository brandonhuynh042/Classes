#include <iostream>
#include <cstring>
#include "Media.h"

using namespace std;
Media::Media() {
  title = new char[50];
  year = 0;
}
void Media::setYear(int newYear) {
  year = newYear;
}

void Media::setTitle(char* newTitle) {
  strcpy(title, newTitle);
}

int Media::getYear() {
  return year;
}

char* Media::getTitle() {
  return title;
}

void Media::print() {
  cout << title << ", " << year << endl;
}
