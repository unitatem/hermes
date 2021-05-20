#ifndef LOGGER_LOGGER_HPP
#define LOGGER_LOGGER_HPP

#include <iostream>

#define __CLASS__ typeid(*this).name()

#define LOGGER_MSG_PREFIX std::cout << __CLASS__ << "::" << __func__ << "() > "

#define LOG_START()                            \
  do {                                         \
    LOGGER_MSG_PREFIX << "START" << std::endl; \
  } while (false)

#define LOG_END()                            \
  do {                                       \
    LOGGER_MSG_PREFIX << "END" << std::endl; \
  } while (false)

#define LOG_MSG(x)                         \
  do {                                     \
    LOGGER_MSG_PREFIX << (x) << std::endl; \
  } while (false)

#endif  // LOGGER_LOGGER_HPP
