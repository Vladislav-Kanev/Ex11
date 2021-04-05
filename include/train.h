#ifndef _INCLUDE_TRAIN_H
#define _INCLUDE_TRAIN_H

#include <iostream>

class Cage;

class Train {
 private:
  Cage* first;
  Cage* last;

 public:
  Train();
  void addCage(Cage*);
  unsigned getLenght();
  void getState();
};

class Cage {
  bool light;
 public:
  Cage* next;
  Cage* prev;
  Cage() : light(std::rand() % 2), next(nullptr), prev(nullptr) {}
  void on() { light = true; }
  void off() { light = false; }
  void setState(bool state) { light = state; };
  bool get() const { return light; }
};

#endif  // !_INCLUDE_TRAIN_H
