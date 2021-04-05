#include "..\include\train.h"

Train::Train() {
  first = nullptr;
  last = nullptr;
}

void Train::addCage(Cage* cg) {
  if (!first) {
    first = cg;
    last = cg;
    cg->next = cg;
    cg->prev = cg;
    return;
  }
  last->next = cg;
  first->prev = cg;
  cg->prev = last;
  cg->next = first;
  last = cg;
}

unsigned Train::getLenght() {
  if (!first) return 0;
  bool state = first->get();
  Cage* pointer = first;
  unsigned counter(0), lenght(0);
  while (true) {
    pointer = pointer->next;
    if (pointer->get() != state) {
      ++counter;
      continue;
    } else {
      lenght = counter;
      pointer->setState(!state);
      for (size_t i = 0; i <= counter; ++i) {
        pointer = pointer->prev;
      }
      counter = 0;
      if (pointer->get() != state) {
        break;
      }
    }
  }
  return lenght;
}

void Train::getState() {
  if (!first) return;
  Cage* pointer = first;
  unsigned counter = 0;
  std::cout << "Cage list:\n";
  while (pointer != last) {
    std::cout << "\t" << counter << ((pointer->get()) ? ": ON\n" : ": OFF\n");
    pointer = pointer->next;
    ++counter;
  }
  std::cout << "\t" << counter << ((pointer->get()) ? ": ON\n" : ": OFF\n");
}
