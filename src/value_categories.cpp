/**
 * @file value_categories.cpp
 * @author OpenAI Codex
 * @brief Tutorial code for pass-by-value, references, and lvalue/rvalue basics.
 */

// Read this file before references.cpp and move_semantics.cpp if the words
// "lvalue", "rvalue", or "std::move" still feel fuzzy.

// Includes std::cout (printing) for demo purposes.
#include <iostream>
// Includes the C++ string library.
#include <string>
// Includes std::move.
#include <utility>

void TakesByValue(std::string text) {
  std::cout << "TakesByValue: " << text << std::endl;
}

void TakesByRef(std::string &text) {
  text += " + modified";
  std::cout << "TakesByRef: " << text << std::endl;
}

void TakesByConstRef(const std::string &text) {
  std::cout << "TakesByConstRef: " << text << std::endl;
}

void TakesByRvalueRef(std::string &&text) {
  std::cout << "TakesByRvalueRef: " << text << std::endl;
}

int main() {
  std::string name = "bustub";

  // name is an lvalue: it has a stable identity and can appear on the left
  // side of an assignment.
  TakesByValue(name);      // makes a copy
  TakesByRef(name);        // modifies the original string
  TakesByConstRef(name);   // reads the original without copying

  // A temporary object such as std::string("temp") is an rvalue.
  TakesByValue(std::string("temp"));
  TakesByConstRef(std::string("temp"));
  TakesByRvalueRef(std::string("temp"));

  // std::move does not move anything by itself. It simply casts an lvalue into
  // an rvalue so that move-enabled code can treat it as a movable object.
  std::string source = "cmu";
  std::string destination = std::move(source);
  std::cout << "destination after move: " << destination << std::endl;
  std::cout << "source after move (valid but unspecified): " << source << std::endl;

  // Summary:
  // 1. Pass-by-value copies (or moves) an argument into the function.
  // 2. T& is a modifiable lvalue reference.
  // 3. const T& can bind to both lvalues and rvalues.
  // 4. T&& is an rvalue reference.
  // 5. std::move is a cast that enables move semantics.
  return 0;
}
