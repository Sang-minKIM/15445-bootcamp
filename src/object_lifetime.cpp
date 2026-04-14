/**
 * @file object_lifetime.cpp
 * @author OpenAI Codex
 * @brief Tutorial code for class basics, constructors/destructors, and RAII.
 */

// Read this file before wrapper_class.cpp, unique_ptr.cpp, shared_ptr.cpp,
// and move_constructors.cpp if you are not yet comfortable with how object
// lifetime works in C++.

// Includes std::cout (printing) for demo purposes.
#include <iostream>
// Includes the C++ string library.
#include <string>

// A small class that announces when it is created and destroyed.
class Tracer {
 public:
  explicit Tracer(std::string name) : name_(std::move(name)) {
    std::cout << "Constructed: " << name_ << std::endl;
  }

  Tracer(const Tracer &other) : name_(other.name_ + " (copy)") {
    std::cout << "Copied from " << other.name_ << " into " << name_ << std::endl;
  }

  ~Tracer() { std::cout << "Destructed: " << name_ << std::endl; }

  void SayHello() const {
    std::cout << "Hello from " << name_ << std::endl;
  }

 private:
  std::string name_;
};

// RAII means that a resource becomes available in a constructor and is cleaned
// up in a destructor. This class does not own a complex resource; it just uses
// printing to demonstrate the pattern.
class ScopedMessage {
 public:
  explicit ScopedMessage(std::string label) : label_(std::move(label)) {
    std::cout << "[enter] " << label_ << std::endl;
  }

  ~ScopedMessage() { std::cout << "[exit] " << label_ << std::endl; }

 private:
  std::string label_;
};

int main() {
  Tracer first("first");
  first.SayHello();

  {
    ScopedMessage scope_guard("inner scope");
    Tracer second("second");
    second.SayHello();
    std::cout << "About to leave the inner scope." << std::endl;
  }

  std::cout << "Back in the outer scope." << std::endl;

  // This is copy initialization. For many beginner-friendly classes, C++
  // can generate copy behavior automatically. Later files explain why copying
  // can be expensive or even disallowed for ownership-managing classes.
  Tracer copy_source("copy_source");
  Tracer copy_target = copy_source;
  copy_target.SayHello();

  // Summary:
  // 1. A class bundles data and behavior together.
  // 2. Constructors run when objects are created.
  // 3. Destructors run automatically when objects leave scope.
  // 4. RAII ties cleanup to scope exit.
  // 5. Once you understand lifetime, wrapper classes and smart pointers become
  //    much easier to understand.
  return 0;
}
