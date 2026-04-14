/**
 * @file pointer_basics.cpp
 * @author OpenAI Codex
 * @brief Tutorial code for raw pointers, addresses, and stack/heap lifetime.
 */

// If you have only used enough C++ to solve algorithms, this file is a good
// place to start before references.cpp, iterator.cpp, unique_ptr.cpp, and
// shared_ptr.cpp. These later files assume you already understand what an
// address is, what a pointer stores, and why object lifetime matters.

// Includes std::cout (printing) for demo purposes.
#include <iostream>

// Takes a pointer. If the pointer is not null, it modifies the pointed value.
void add_five(int *value_ptr) {
  if (value_ptr == nullptr) {
    std::cout << "Pointer was null, so there is nothing to modify." << std::endl;
    return;
  }
  *value_ptr = *value_ptr + 5;
}

int main() {
  // A normal local variable usually lives on the stack.
  int score = 10;

  // The & operator means "address of".
  int *score_ptr = &score;

  std::cout << "score: " << score << std::endl;
  std::cout << "address stored in score_ptr: " << score_ptr << std::endl;

  // The * operator means "dereference": go to the stored address and read or
  // write the value there.
  std::cout << "value through score_ptr: " << *score_ptr << std::endl;
  *score_ptr = 25;
  std::cout << "score after *score_ptr = 25: " << score << std::endl;

  // Passing a pointer to a function lets the function work with the original
  // object rather than a copy.
  add_five(score_ptr);
  std::cout << "score after add_five(score_ptr): " << score << std::endl;

  // Pointers can also be null, meaning that they point to no object.
  int *nothing = nullptr;
  add_five(nothing);

  // Dynamic allocation creates an object whose lifetime lasts until delete.
  int *heap_value = new int(99);
  std::cout << "heap_value address: " << heap_value << std::endl;
  std::cout << "*heap_value before update: " << *heap_value << std::endl;
  *heap_value = 123;
  std::cout << "*heap_value after update: " << *heap_value << std::endl;

  // When you allocate with new, you must eventually delete the object.
  delete heap_value;
  heap_value = nullptr;

  // Summary:
  // 1. A pointer stores an address.
  // 2. & gets an address.
  // 3. * follows an address.
  // 4. nullptr means "points to nothing".
  // 5. new/delete manually control lifetime, which is why modern C++ often
  //    prefers RAII wrappers such as std::unique_ptr.
  return 0;
}
