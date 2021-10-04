#ifndef EVENT_SOURCING_IMPL_HPP
#define EVENT_SOURCING_IMPL_HPP

#include "event.hpp"
#include "event_sourcing.hpp"

struct Output {
    int x = 0;
};
struct Input {
    Output output;
};

bool operator==(const Output &lhs, const Output &rhs) { return lhs.x == rhs.x; }
bool operator==(const Input &lhs, const Input &rhs) { return lhs.output == rhs.output; }

class EventImpl : public Event<Input, Output> {
 public:
    inline std::string GetName() const override { return "Test Event"; }
    inline std::string ToString() const override { return "Test Event String"; }
    inline Output Handle(Input &input) override { return input.output; }
};

#endif