// Copyright 2021
#include <iostream>
#include <string>

#include "../include/train.h"

int main() {
  Train train;

  for (size_t i = 0; i < std::rand() % 1000; ++i) {
    Cage* cage = new Cage();
    train.addCage(cage);
  }
  train.getState();
  std::cout << train.getLenght();
  return 0;
}
