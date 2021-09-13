#ifndef EVENT_SOURCING_HPP
#define EVENT_SOURCING_HPP

#include <functional>
#include "Event.hpp"

template<typename Data, typename Result>
class EventSourcing {
 public:
    virtual Result Process(Event<Data, Result> &) = 0;
};

#endif