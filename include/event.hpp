#ifndef EVENT_HPP
#define EVENT_HPP

#include <string>

template<typename Data, typename Result>
class Event {
 public:
    virtual std::string GetName() const = 0;
    virtual std::string ToString() const = 0;
    virtual Result Handle(Data &) = 0;
};

#endif