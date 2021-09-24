#ifndef ContextData_HPP
#define ContextData_HPP

#include <vector>
#include "event.hpp"

template<typename Data, typename Result>
class ContextData {
    Data active;
    Data candidate;
    std::vector<Event<Data, Result>> events;
    std::vector<Event<Data, Result>> candidates;
 public:
    inline Result Execute(Event<Data, Result> &event, bool apply) {
        Result result;
        if (apply) {
            candidate = active;
            result = event.Handle(candidate);
            // events.push_back(event);
        } else {
            result = event.Handle(candidate);
            // candidates.push_back(event);
        }
        return result;
    }

    inline void Commit() {
        if (!candidates.empty()) {
            events.insert(candidates.begin(), candidates.end());
            candidates.clear();
        }
        active = candidate;
    }
    inline void Rollback() {
        if (!candidates.empty()) {
            candidates.clear();
        } else if (!events.empty()) {
            events.erase(events.end() - 1);
        }
        candidate = active;
    }

    inline Data GetData() { return candidate; }
};

#endif