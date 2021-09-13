#include "EventSourcingImpl.hpp"
#include "gtest/gtest.h"

struct Output {
    int x;
};
struct Input {
    Output output;
};

class EventImpl : public Event<Input, Output> {
    Output Handle(Input &input) { return input.output; }
};

bool operator==(const Output &lhs, const Output &rhs) { return lhs.x == rhs.x; }
bool operator==(const Input &lhs, const Input &rhs) { return lhs.output == rhs.output; }

class EventSourcingImplTest : public ::testing::Test {
 protected:
    EventSourcing<Input, Output> *eventSourcing;
    Input input;

    void SetUp() override { eventSourcing = new EventSourcingImpl<Input, Output>(); }

    void TearDown() override { delete eventSourcing; }
};

TEST_F(EventSourcingImplTest, process_success) {
    EventImpl event;

    Output result = eventSourcing->Process(event);
    EXPECT_EQ(input.output, result);
}
