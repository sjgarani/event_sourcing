#ifndef ContextData_HPP
#define ContextData_HPP

#include <vector>
#include <utility>
#include "event.hpp"

template<typename Data, typename Result>
class ContextData {
    Data active;
    Data candidate;
    std::vector<std::pair<std::string, std::string>> events;
    std::vector<std::pair<std::string, std::string>> candidates;
 public:
    inline Result Execute(Event<Data, Result> &event, bool apply) {
        Result result;
        if (apply) {
            candidate = active;
            result = event.Handle(candidate);
            events.push_back({event.GetName(), event.ToString()});
        } else {
            result = event.Handle(candidate);
            candidates.push_back({event.GetName(), event.ToString()});
        }
        return result;
    }

    inline void Commit() {
        if (!candidates.empty()) {
            events.insert(events.end(), candidates.begin(), candidates.end());
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