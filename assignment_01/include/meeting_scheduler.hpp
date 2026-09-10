#pragma once

#include <vector>

// Represents meeting with a start and end time
struct Meeting {
    int start;
    int end;
};

// Checks every pair of meetings and returns true if any two overlap
bool containsConflict(const std::vector<Meeting>& meetings);

// Sorts meetings by start time, then checks meetings for overlap
bool containsConflictSorted(std::vector<Meeting> meetings);
