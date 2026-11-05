#include "AssociativeArray.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <list>
#include <utility>
#include <cctype>

using Followers = std::list<std::pair<std::string, int>>;
using MarkovModel = AssociativeArray<std::string, Followers>;

/**
 * Reads a text file and separates it into lowercase tokens.
 * Keeps hyphens within words and stores sentence-ending punctuation as separate tokens.
 * @param filename The path to the text file
 * @return A vector of tokens from the file
 */
std::vector<std::string> readWords(const std::string& filename) {
    // open file
    std::ifstream file(filename);
    std::vector<std::string> words;
    // make sure file exists
    if (!file.is_open()) {
        std::cout << "couldn't open file";
        return words;
    }
    std::string curWord;
    char c;

    // read each char till end
    while (file.get(c)) {
        // letter or hyphen counting towards word
        if (std::isalpha(c) || c == '-') {
            curWord += std::tolower(c);
        } 
        // punctuation indicating end of word
        else if (c == '.' || c == '!' || c == '?') {
            if (!curWord.empty()) {
                words.push_back(curWord);
                curWord.clear();
            }
            // save punctation as own word
            words.push_back(std::string(1, c));
        } 
        // anything else -> finish word
        else {
            if (!curWord.empty()) {
                words.push_back(curWord);
                curWord.clear();
            }
        }
    }
    // last cleanup
    if (!curWord.empty()) {
        words.push_back(curWord);
    }
    return words;
}

/**
 * Builds a Markov model by counting how often each token follows another.
 * @param words The vector of tokens to process
 * @return An associative array mapping each token to its followers and their counts
 */
MarkovModel buildMarkovModel(const std::vector<std::string>& words) {
    MarkovModel model;
    // iterate through words
    for (int i = 0; i + 1 < words.size(); i++) {
        // get cur word and follower
        const auto& cur = words[i];
        const auto& fol = words[i + 1];
        // get followers if cur word in model
        auto res = model.get(cur);
        Followers list;
        if (res.has_value()) {
            list = res.value();
        }
        bool found = false;
        // update follower count if possible
        for (auto& pair : list) {
            if (pair.first == fol) {
                pair.second++;
                found = true;
                break;
            }
        }
        // if follower not found, add it with count 1
        if (!found) {
            list.push_back({fol, 1});
        }
        // update with new list
        model.set(cur, list);
    }
    return model;
}

/**
 * Reads a text file, builds the Markov model, and allows users to query words.
 * @param argc The number of command-line arguments
 * @param argv The command-line arguments, including the filename
 * @return 0 on success, 1 if the input is invalid or no words are found
 */
int main(int argc, char* argv[]) {
    // check for filename
    if (argc < 2) {
        std::cout << "markov for <filename>\n";
        return 1;
    }

    // read words from file
    auto words = readWords(argv[1]);
    if (words.empty()) {
        std::cout << "no words\n";
        return 1;
    }

    // build model and print stats
    auto model = buildMarkovModel(words);
    std::cout << "total tokens" << words.size() << "\n";
    std::cout << "num unique words with followers" << model.size() << "\n";
    std::string query;

    // keep going till quit
    while (true) {
        std::cout << "\nenter word for search (or 'quit'): ";
        if (!(std::cin >> query)) {
            break;
        }
        for (char& c : query) {
            c = static_cast<char>(std::tolower(static_cast<unsigned char>(c)));
        }
        if (query == "quit") {
            break;
        }

        // get followers for word
        auto res = model.get(query);
        if (!res.has_value()) {
            std::cout << "word not found.\n";
            continue;
        }

        // print follower: count
        std::cout << "words following '" << query << "':\n";
        for (const auto& pair : res.value()) {
            std::cout << pair.first << ": " << pair.second << "\n";
        }
    }
    return 0;
}
