#ifndef EVENT_SOURCING_HPP
#define EVENT_SOURCING_HPP

#include <functional>

template<class T, class R>
class EventSourcing {
 public:
    virtual R process(const T &) = 0;

    virtual void setProcessCallback(std::function<R(const T &)>) = 0;
};

#endif