// Copyright 2021 GHA Test Team
#include <gtest/gtest.h>
#include <string>
#include "../include/train.h"

TEST(Train, test1) {
  Train tr;
  Cage* cage = new Cage;
  unsigned was = tr.getLenght();
  tr.addCage(cage);
  unsigned now = tr.getLenght();
  unsigned expected = 1;
  unsigned result = now - was;
  EXPECT_EQ(expected, result);
}

TEST(Train, test2) {
  Train tr;
  for (size_t i = 0; i < 10; ++i) {
    Cage* cage = new Cage();
    tr.addCage(cage);
  }
  Cage* pointer = tr.getFirst();
  for (size_t i = 0; i < 10; ++i) {
    pointer = pointer->next;
  }
  Cage* expected = tr.getFirst();
  Cage* result = pointer;
  EXPECT_EQ(expected, result);
}

TEST(Train, test3) {
  Train tr;
  unsigned expected = std::rand() % 1000;
  for (size_t i = 0; i < expected; ++i) {
    Cage* cage = new Cage();
    tr.addCage(cage);
  }
  unsigned result = tr.getLenght();
  EXPECT_EQ(expected, result);
}
