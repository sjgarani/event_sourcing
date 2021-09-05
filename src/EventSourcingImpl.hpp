#ifndef EVENT_SOURCING_IMPL_HPP
#define EVENT_SOURCING_IMPL_HPP

#include "EventSourcing.hpp"

template<class T, class R>
class EventSourcingImpl : public EventSourcing<T, R> {
    std::function<R(const T &)> callback;
 public:
    EventSourcingImpl() = default;

    inline R process(const T &input) { return callback(input); }

    inline void setProcessCallback(std::function<R(const T &)> callback_) { callback = callback_; }
};

#endif