// Copyright 2021
#include <iostream>
#include <string>

#include "../include/train.h"

int main() {
  Train tr;
  Cage* cg = new Cage;
  tr.addCage(cg);
  std::cout << tr.getLenght() << "\n";

  for (size_t i = 0; i < 1000; ++i) {
    Cage* cage = new Cage();
    tr.addCage(cage);
  }
  tr.getState();
  std::cout << tr.getLenght();
  return 0;
}

