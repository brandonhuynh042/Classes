#ifndef MEDIA_H
#define MEDIA_H
#include <iostream>
#include <cstring>

using namespace std;

class Media {
 public:
  Media();  
  void setYear(int);
  void setTitle(char*);
  char* getTitle();
  int getYear();
  virtual void print();
 protected:
  char* title;
  int year;
};
#endif
