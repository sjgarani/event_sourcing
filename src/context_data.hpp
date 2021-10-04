#ifndef ContextData_HPP
#define ContextData_HPP

#include <vector>
#include <utility>
#include <memory>
#include <sstream>
#include "event.hpp"

template<typename Data, typename Result>
class ContextData {
    Data active;
    Data candidate;
    std::vector<std::shared_ptr<Event<Data, Result>>> events;
    std::vector<std::shared_ptr<Event<Data, Result>>> candidates;
 public:
    inline Result Execute(std::shared_ptr<Event<Data, Result>> event, bool apply) {
        Result result;
        if (apply) {
            candidate = active;
            result = event->Handle(candidate);
            events.push_back(event);
        } else {
            result = event->Handle(candidate);
            candidates.push_back(event);
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

    inline Data GetData() const { return candidate; }

    inline std::string ToString() const {
        std::ostringstream output;
        if (!events.empty()) {
            output << "Events:\n";
            for (auto event : events) {
                output << "\t" << event->ToString();
            }
        }
        if (!candidates.empty()) {
            output << "Event Candidates:\n";
            for (auto event : candidates) {
                output << "\t" << event->ToString();
            }
        }
        return output.str();
    }
};

#endif