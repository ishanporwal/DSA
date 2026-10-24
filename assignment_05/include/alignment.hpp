#pragma once

#include <vector>
#include <string>
#include <algorithm>

struct AlignmentResult {
    std::string alignedA;
    std::string alignedB;
    int score;
};

/**
 * Computes a global alignment using the Needleman-Wunsch algorithm.
 * Matches score +1; mismatches and gaps score -1.
 * @param a The first input string.
 * @param b The second input string.
 * @return Both aligned strings and their alignment score.
 */
AlignmentResult needlemanWunsch(const std::string& a, const std::string& b) {
    AlignmentResult res;
    int sizea = a.size();
    int sizeb = b.size();
    std::vector<std::vector<int>> dp(sizea + 1, std::vector<int>(sizeb + 1,0));
    // init first row
    for (int c = 0; c < sizeb + 1; c++) {
        dp[0][c] = -c;
    }
    // init first col
    for (int r = 0; r < sizea + 1; r++) {
        dp[r][0] = -r;
    }
    for (int r = 1; r < sizea + 1; r++) {
        for (int c = 1; c < sizeb + 1; c++) {
            // check diag match
            int match = -1;
            if (a[r-1] == b[c-1]) {
                match = 1;
            }
            int diag = dp[r-1][c-1] + match;
            int above = dp[r-1][c] - 1;
            int left = dp[r][c-1] - 1;
            // get max score and fill in
            dp[r][c] = std::max(left, std::max(diag, above));
        }
    }
    int r = sizea;
    int c = sizeb;
    // go until we reach first square
    while (r > 0 || c > 0) {
        int match = -1;
        // reverse algo to figure out best choice taken
        if (r > 0 && c > 0 && a[r-1] == b[c-1]) {
            match = 1;
        }
        if (r > 0 && c > 0 && dp[r][c] == dp[r-1][c-1] + match) {
            res.alignedA += a[r-1];
            res.alignedB += b[c-1];
            r--;
            c--;
        }
        else if (r > 0 && dp[r][c] == dp[r-1][c] - 1) {
            res.alignedA += a[r-1];
            res.alignedB += '-';
            r--;
        }
        else {
            res.alignedA += '-';
            res.alignedB += b[c-1];
            c--;
        }
    }
    // reverse sequence so it reads correctly and get score at end
    std::reverse(res.alignedA.begin(), res.alignedA.end());
    std::reverse(res.alignedB.begin(), res.alignedB.end());
    res.score = dp[sizea][sizeb];
    return res;
}
