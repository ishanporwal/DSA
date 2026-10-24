## Part 2: Matrix Multiplication

I implemented traditional matrix multiplication and Strassen's algorithm, then added a hybrid version that switches to traditional multiplication once the matrix size gets small enough. I also used Google Test to check the main matrix operations.

### Benchmarks

I first tested traditional multiplication against Strassen without a switching threshold. These are the runtimes from my initial Release build, in milliseconds...

| Matrix size | Traditional | Strassen |
|---|---:|---:|
| 8 | 0.0011 | 0.3199 |
| 16 | 0.0064 | 1.8883 |
| 32 | 0.0432 | 12.7091 |
| 64 | 0.4072 | 94.2748 |
| 128 | 3.2099 | 647.839 |

Since Strassen was significantly slower, I then tested a hybrid approach using thresholds of 32, 64, and 128. These are the average runtimes over 10 runs using a Release build, in milliseconds...

| Matrix size | Traditional | Threshold 32 | Threshold 64 | Threshold 128 |
|---|---:|---:|---:|---:|
| 64 | 0.427 | 0.627 | 0.485 | 0.461 |
| 128 | 3.993 | 4.406 | 4.248 | 3.721 |
| 256 | 28.371 | 27.417 | 24.296 | 24.814 |
| 512 | 221.020 | 191.711 | 167.036 | 181.576 |

### Performance Analysis

In my initial benchmark testing, the traditional multiplication was much faster than Strassen at every tested size. Although Strassen theoretically has better time complexity, it still has extra overhead due to splitting matrices, creating temporary matrices, and then making recursive calls. That overhead isn't really worth it for smaller inputs, especially when recursively splitting all the way down to 1x1 matrices.

However, after implementing the hybrid approach, Strassen started performing better at larger matrix sizes. At a size of 256, using a threshold of 64 was about 14% faster than traditional multiplication. At a size of 512, it was about 24% faster.

Based on these results, **64** seems like the best switching threshold for my implementation. This means using traditional multiplication for matrices of size 64 or smaller and Strassen for larger matrices. Traditional multiplication was still generally faster for smaller matrices, but the hybrid approach became more beneficial as the matrix size increased. The exact times can vary between runs, so 64 is the best threshold from the sizes I tested rather than a universal cutoff.

## Part 3: DNA Sequence Alignment

For this part, I implemented the Needleman-Wunsch algorithm to find the optimal alignment between two DNA sequences using dynamic programming.

I used a 2D DP table where each cell stores the best alignment score up to that point. For each cell, I considered matching two characters or introducing a gap in either the first or second sequence. I used +1 for a match and -1 for a mismatch or gap. After filling the table, I backtracked from the bottom-right to reverse engineer the actual alignment.

### Results

I ran the algorithm on the provided `genomeSnippet` and `testAgainst` sequences.

**Aligned genome snippet:**
```text
TGGCGACAACCG-TAGCGGAATATTTTCGCGACCAGGGAAAACGGGTCGTGCTT-TTTATCGATTC-CATGACCCGTTATGCGC-GTGCTTTGCGAGACGTGGCACTGG-CGTCGG-GAGAGCGTCCGG-CTCGTCGAGGTTATCCCGCC-TCCGTA-TTCGAT-AATTTGCCCCG-CTTGCTGGAACGCCCAGGG---GCGACCAGCGAGGGAAGCATTACTGCCTTTTATACGGTACTGCTGGAAAGCGAGGA-A-GAGGCGGACCCGATGGCGGATGAAATTCGCTCTA-TCCTTGACGGTCA-CCTGTATCTGA-GCAGAAAGCTGGCCGGGCA-GGGACATTACCCGGCAATCGATGTACT-GAAAAGCGTAAGCCGCGTTTTT
```

**Aligned test against:**
```text
TGGCCACCA-CGATAGCAGAATTTTTTCGCGATAATGGAAAGCGAGTCGT-CTTGCTTGCCGACTCAC-TGACGCGTTATGC-CAGGGCCGCACGGGAAATCGCTCTGGCCGCCGGAGAGACCG--CGGTTTC-TGGAGAATAT-CCGCCAGGCGTATTTAG-TGCA-TTGCCACGACTT-TTAGAACGTAC-GGGAATGGGA-GA-AAAAGGCAGTATTACCGCATTTTATACGGTACTGGTGGAAGGCGATGATATGA--ATGAGCCGTTGGCGGATGAAGTCCGTTC-ACTGCTTGATGGACATATTGTA-CT-ATCCCGACGGCTTGCAGAG-AGGGGGCATTATCCTGCCATTGACGTGTTGGCAACGC-TCAGCCGCGTTTTT
```

**Final alignment score: 143**

The algorithm put in gaps wherever needed to get a better overall alignment. The final score of 143 was calculated using the penalties as described above.
