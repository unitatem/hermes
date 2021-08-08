#ifndef STAGE_HPP
#define STAGE_HPP

#include <functional>

#include "processor.hpp"

class Stage {
 public:
  using Work = std::function<void(std::string str)>;

 private:
  Work work;
  Processor processor;

 public:
  Stage(Work w) : work{w} {}

  void process(std::string str) {
    processor.send([=]() { work(str); });
  }
};

#endif  // STAGE_HPP
