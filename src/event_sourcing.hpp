#ifndef EVENT_SOURCING_HPP
#define EVENT_SOURCING_HPP

#include <functional>
#include <memory>
#include "event.hpp"
#include "context_data.hpp"

template<typename Data, typename Result>
class EventSourcing {
    ContextData<Data, Result> context;

 public:
    EventSourcing() = default;

    inline Result Process(std::shared_ptr<Event<Data, Result>> event) {
        return context.Execute(event, true);
    }

    inline Data GetData() const { return context.GetData(); }

    inline std::string ToString() const { return context.ToString(); }
};

#endif