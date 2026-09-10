#include "meeting_scheduler.hpp"

#include <algorithm>

bool containsConflict(const std::vector<Meeting>& meetings) {
    std::size_t n = meetings.size();
    for (std::size_t i = 0; i < n; ++i) {
        for (std::size_t j = i + 1; j < n; ++j) {
            const Meeting& A = meetings[i];
            const Meeting& B = meetings[j];
            if (A.start < B.end && B.start < A.end) {
                return true;
            }
        }
    }
    return false;
}

bool containsConflictSorted(std::vector<Meeting> meetings) {    
    std::size_t n = meetings.size();
    std::sort(meetings.begin(), meetings.end(), 
    [](const Meeting& A, const Meeting& B) {
        return A.start < B.start;
    });
    for (std::size_t i = 1; i < n; ++i) {
        const Meeting& A = meetings[i];
        const Meeting& B = meetings[i-1];
        if (A.start < B.end) {
            return true;
        }
    }
    return false;
}
