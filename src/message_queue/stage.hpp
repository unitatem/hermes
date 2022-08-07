#ifndef STAGE_HPP
#define STAGE_HPP

#include <functional>

#include "processor.hpp"

// Single processing note.
// Type of processing is defined as a ctor argument.
template <typename T>
class Stage {
 public:
  using WorkDefinition = std::function<void(T)>;

 private:
  WorkDefinition work;
  Processor processor;

 public:
  // Define type of processing executed by this object.
  Stage(WorkDefinition w) : work{w} {}

  // Accepts input data to process.
  void process(T str) {
    processor.send([this, str]() { work(str); });
  }
};

#endif  // STAGE_HPP
