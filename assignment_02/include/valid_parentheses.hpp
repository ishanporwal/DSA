#pragma once

#include <string>
#include "stack.hpp"
#include <unordered_map>

bool isValidParentheses(const std::string& s) {
    std::unordered_map<char, char> map = {
        {'}' , '{'},
        {')' , '('},
        {']' , '['},
    };
    Stack<char> stack;
    for (char c : s) {
        auto it = map.find(c);
        if (it != map.end()) {
            if (stack.isEmpty() || stack.peek() != it->second) {
                return false;
            }
            stack.pop();
        }
        else {
            stack.push(c);
        }
    }
    return stack.isEmpty();
}
