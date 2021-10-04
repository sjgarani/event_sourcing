#include "event_sourcing_impl.hpp"
#include "gtest/gtest.h"

class EventSourcingTest : public ::testing::Test {
 protected:
    EventSourcing<Input, Output> *eventSourcing;
    Input input;

    void SetUp() override { 
        eventSourcing = new EventSourcing<Input, Output>();
    }

    void TearDown() override { 
        delete eventSourcing;
    }
};

TEST_F(EventSourcingTest, event_source_get_data) {
    EXPECT_EQ(input, eventSourcing->GetData());
}

TEST_F(EventSourcingTest, event_source_process_success) {
    std::shared_ptr<Event<Input, Output>> event = std::make_shared<EventImpl>();
    Output result = eventSourcing->Process(event);
    std::cout << eventSourcing->ToString() << std::endl;
    EXPECT_EQ(input.output, result);
}
