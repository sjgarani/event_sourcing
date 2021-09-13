#ifndef EVENT_HPP
#define EVENT_HPP

#include <functional>

template<typename Data, typename Result>
class Event {
 public:
    virtual Result Handle(Data &) = 0;
};

#endif