#ifndef CEXCEPTIONS_H
#define CEXCEPTIONS_H

#include <stdexcept>
#include <iostream>

class position_coord_invalid : public std::logic_error {
public:
    using _Mybase = std::logic_error;
    explicit position_coord_invalid(const std::string& _Message) : _Mybase(_Message.c_str()) {}
};

class velocity_is_invalid : public std::logic_error {
public:
    using _Mybase = std::logic_error;
    explicit velocity_is_invalid(const std::string& _Message) : _Mybase(_Message.c_str()) {}
};

class angular_value_is_invalid : public std::logic_error {
public:
    using _Mybase = std::logic_error;
    explicit angular_value_is_invalid(const std::string& _Message) : _Mybase(_Message.c_str()) {}
};



#endif // CEXCEPTIONS_H
