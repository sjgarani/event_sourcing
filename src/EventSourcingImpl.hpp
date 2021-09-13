#ifndef EVENT_SOURCING_IMPL_HPP
#define EVENT_SOURCING_IMPL_HPP

#include "EventSourcing.hpp"

template<typename Data, typename Result>
class EventSourcingImpl : public EventSourcing<Data, Result> {
    Data data;
 public:
    EventSourcingImpl() = default;

    inline Result Process(Event<Data, Result> &event) { return event.Handle(data); }
};

#endif