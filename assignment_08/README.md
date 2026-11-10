# Assignment 08: K-D Trees and Nearest Neighbor Search

I implemented a K-D tree and brute-force nearest-neighbor search, then compared their performance across different dataset sizes and dimensions. Each experiment used 1,000 random query points, and the code was run in a Release build. All times are in milliseconds.

## Benchmark Results

| Dimensions (k) | Points | Tree Build | K-D Queries | Brute Force Queries |
|---:|---:|---:|---:|---:|
| 2 | 10 | 0.0180 | 0.0920 | 0.0713 |
| 2 | 100 | 0.0512 | 0.1433 | 0.2346 |
| 2 | 1,000 | 0.8154 | 0.1825 | 1.4589 |
| 2 | 10,000 | 8.6137 | 0.3344 | 15.0610 |
| 3 | 10 | 0.0082 | 0.1117 | 0.0836 |
| 3 | 100 | 0.0581 | 0.2472 | 0.2710 |
| 3 | 1,000 | 0.6861 | 0.3089 | 1.5719 |
| 3 | 10,000 | 9.0255 | 0.4819 | 16.1931 |
| 5 | 10 | 0.0054 | 0.1205 | 0.0683 |
| 5 | 100 | 0.0581 | 0.3889 | 0.2568 |
| 5 | 1,000 | 0.6421 | 0.8037 | 1.9178 |
| 5 | 10,000 | 10.2894 | 1.4993 | 21.4420 |
| 10 | 10 | 0.0075 | 0.1355 | 0.1091 |
| 10 | 100 | 0.0992 | 1.7137 | 1.3332 |
| 10 | 1,000 | 0.7241 | 11.2733 | 6.4538 |
| 10 | 10,000 | 21.4822 | 48.9991 | 30.1421 |
| 20 | 10 | 0.0086 | 0.1828 | 0.1373 |
| 20 | 100 | 0.0661 | 0.9659 | 0.5795 |
| 20 | 1,000 | 0.7441 | 8.6902 | 5.8845 |
| 20 | 10,000 | 11.9684 | 161.7242 | 72.8200 |

## Analysis

For larger datasets with fewer dimensions, the K-D tree was much faster at querying than brute force. With 10,000 points in 2D, the K-D tree took 0.33 ms for 1,000 queries versus 15.06 ms for brute force, or about 45 times faster since it sucessfully avoids checking every single node in the tree..

However, as the number of dimensions increased, the K-D tree became slower because it had to search more branches. At 10 and 20 dimensions, brute force was generally faster. K-D trees also have a building overhead cost, so brute force can make more sense for small datasets or only a few queries. Overall, K-D trees work best for large, low-dimensional datasets when we need to make repeated nearest-neighbor queries.
