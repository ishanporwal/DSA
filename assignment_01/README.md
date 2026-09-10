# Assignment 01

## Identifying Effective Strategies for Learning
1. Learning went really well in my Power Electronics class I took last semester. Some strategies that worked particularly well were working independently and then clearing up any uncertainties through working with friends as well as regularly going through previously covered material for recall.
2. Something that doesn't work well for me is just listening to information without being able to test my knowledge of it. I need some sort of "doing" to make sure I retain information. Another strategy that doesn't work for me is trying to learn important information in a huge group, I tend to work better either independently or in smaller groups.
3. I agree with this framing, I think DSA is a pretty fundamental class, so I will not use AI as anything but a learning resource for example if I forget some specific syntax.
4. I will be practicing the topics we learn in this class maybe with the assistance of AI (creating example questions and such). I'll also be working on my own before asking a friend or going to office hours.
5. I think these are reasonable activities, and I would expect them to give me helpful feedback.
6. One thing could be maybe providing some guidance in using C++ for this course instead of Kotlin in terms of structure and deliverables.


## Hello World!...C++

I did something equivalent to this in C++.
1. I like RAII in C++ because I don't have to do manual cleanup. I also really like the C++ standard library because it provides something for almost all fundamental programming.
2. I'd expect there to be built-in package manager such as something like pip for Python.
3. What are situations where you shouldn't use `auto` for typing?
4. I was able to successfully launch the C++ debugger in VS Code using GDB. Yes, I have experience using interactive debuggers like this one.

## Code Translation
I decided to translate the Python solution to the classic LeetCode problem Two Sum. The purpose of this code is to find two indices in an array whose values add up to a given target. My original implementation was written in Python and used a dictionary to store previously seen values and their indices. Translating the code to C++ wasn't too difficult since I could use `std::unordered_map`. The main difference was having to use `find()` and iterators instead of being able to use `in` like in Python. I also used GoogleTest to add unit tests for the translated implementation.

## Meeting Scheduler

For the straightforward implementation, every meeting is compared with every meeting after it. As `n` grows, the number of comparisons grows proportionally to `n^2`, so the runtime is `Θ(n^2)`.

For the sorted implementation, the meetings are first sorted by their start time, which takes `Θ(n log n)`. After sorting, the algorithm iterates through the meetings once and compares each meeting with the previous one, which takes `Θ(n)`. Hence, the overall runtime is `Θ(n log n)`.
