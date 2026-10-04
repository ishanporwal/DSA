# Master Theorem Worksheet

For a recurrence in the form

`T(n) = aT(n/b) + f(n)`

I compared `f(n)` to `n^(log_b(a))`.

- if `f(n)` is polynomially smaller -> Case 1
- if they are about the same -> Case 2
- if `f(n)` is polynomially bigger -> Case 3

## Problem 1-1

`T(n) = 3T(n/2) + n^2`

- `a = 3`, `b = 2`, so `n^(log_2(3))` is about `n^1.585`
- `n^2` is bigger, so this is Case 3
- **T(n) = Θ(n^2)**

## Problem 1-2

`T(n) = 7T(n/2) + n^2`

- `a = 7`, `b = 2`, so `n^(log_2(7))` is about `n^2.807`
- `n^2` is smaller, so this is Case 1
- **T(n) = Θ(n^(log_2(7)))**

## Problem 1-3

`T(n) = 4T(n/2) + n^2`

- `a = 4`, `b = 2`, so `n^(log_2(4)) = n^2`
- these are the same, so this is Case 2
- **T(n) = Θ(n^2 log n)**

## Problem 1-4

`T(n) = 3T(n/4) + n log n`

- `a = 3`, `b = 4`, so `n^(log_4(3))` is about `n^0.792`
- `n log n` is bigger, so this is Case 3
- **T(n) = Θ(n log n)**

## Problem 1-5

`T(n) = 4T(n/2) + log n`

- `a = 4`, `b = 2`, so `n^(log_2(4)) = n^2`
- `log n` is smaller, so this is Case 1
- **T(n) = Θ(n^2)**

## Problem 1-6

`T(n) = T(n - 1) + n`

- the recursive call is `T(n - 1)` instead of `T(n/b)`
- **Master Theorem does not apply**
- if solved by iteration, this would be **Θ(n^2)**

## Problem 1-7

`T(n) = 4T(n/2) + n^2 log n`

- `a = 4`, `b = 2`, so `n^(log_2(4)) = n^2`
- `f(n)` is `n^2` with an extra `log n`, so this is extended Case 2
- **T(n) = Θ(n^2 log^2 n)**

## Problem 1-8

`T(n) = 5T(n/2) + n^2 log n`

- `a = 5`, `b = 2`, so `n^(log_2(5))` is about `n^2.322`
- `n^2 log n` is still polynomially smaller, so this is Case 1
- **T(n) = Θ(n^(log_2(5)))**

## Problem 1-9

`T(n) = 3T(n/3) + n/log n`

- `a = 3`, `b = 3`, so `n^(log_3(3)) = n`
- `n/log n` is smaller than `n`, but not polynomially smaller
- **Master Theorem does not apply**

## Problem 1-10

`T(n) = 2T(n/4) + c`

- `a = 2`, `b = 4`, so `n^(log_4(2)) = n^(1/2)`
- `c` is constant and is smaller, so this is Case 1
- **T(n) = Θ(n^(1/2))**

## Problem 1-11

`T(n) = T(n/4) + log n`

- `a = 1`, `b = 4`, so `n^(log_4(1)) = 1`
- `f(n) = log n`, so this is extended Case 2
- **T(n) = Θ(log^2 n)**

## Problem 1-12

`T(n) = T(n/2) + T(n/4) + n^2`

- the two recursive calls have different input sizes
- it does not fit `aT(n/b) + f(n)`
- **Master Theorem does not apply**
- a recursion tree gives **Θ(n^2)**

## Problem 1-13

`T(n) = 2T(n/4) + log n`

- `a = 2`, `b = 4`, so `n^(log_4(2)) = n^(1/2)`
- `log n` is smaller, so this is Case 1
- **T(n) = Θ(n^(1/2))**

## Problem 1-14

`T(n) = 3T(n/3) + n log n`

- `a = 3`, `b = 3`, so `n^(log_3(3)) = n`
- `f(n)` is `n` with an extra `log n`, so this is extended Case 2
- **T(n) = Θ(n log^2 n)**

## Problem 1-15

`T(n) = 8T((n - sqrt(n))/4) + n^2`

- the recursive input is `(n - sqrt(n))/4`, not just `n/b`
- **Master Theorem does not apply**
- using other methods, the result is **Θ(n^2)**

## Problem 1-16

`T(n) = 2T(n/4) + sqrt(n)`

- `a = 2`, `b = 4`, so `n^(log_4(2)) = sqrt(n)`
- these are the same, so this is Case 2
- **T(n) = Θ(sqrt(n) log n)**

## Problem 1-17

`T(n) = 2T(n/4) + n^0.51`

- `a = 2`, `b = 4`, so `n^(log_4(2)) = n^0.5`
- `n^0.51` is polynomially bigger, so this is Case 3
- **T(n) = Θ(n^0.51)**

## Problem 1-18

`T(n) = 16T(n/4) + n!`

- `a = 16`, `b = 4`, so `n^(log_4(16)) = n^2`
- `n!` is much bigger than `n^2`, so this is Case 3
- **T(n) = Θ(n!)**

## Problem 1-19

`T(n) = 3T(n/2) + n`

- `a = 3`, `b = 2`, so `n^(log_2(3))` is about `n^1.585`
- `n` is smaller, so this is Case 1
- **T(n) = Θ(n^(log_2(3)))**

## Problem 1-20

`T(n) = 4T(n/2) + cn`

- `a = 4`, `b = 2`, so `n^(log_2(4)) = n^2`
- `cn` is smaller, so this is Case 1
- **T(n) = Θ(n^2)**

## Problem 1-21

`T(n) = 3T(n/3) + n/2`

- `a = 3`, `b = 3`, so `n^(log_3(3)) = n`
- `n/2` is still Θ(n), so this is Case 2
- **T(n) = Θ(n log n)**

## Problem 1-22

`T(n) = 4T(n/2) + n/log n`

- `a = 4`, `b = 2`, so `n^(log_2(4)) = n^2`
- `n/log n` is polynomially smaller than `n^2`, so this is Case 1
- **T(n) = Θ(n^2)**

## Problem 1-23

`T(n) = 7T(n/3) + n^2`

- `a = 7`, `b = 3`, so `n^(log_3(7))` is about `n^1.771`
- `n^2` is bigger, so this is Case 3
- **T(n) = Θ(n^2)**

## Problem 1-24

`T(n) = 8T(n/3) + 2^n`

- `a = 8`, `b = 3`, so `n^(log_3(8))` is about `n^1.893`
- `2^n` is way bigger, so this is Case 3
- **T(n) = Θ(2^n)**

## Problem 1-25

`T(n) = 16T(n/4) + n`

- `a = 16`, `b = 4`, so `n^(log_4(16)) = n^2`
- `n` is smaller, so this is Case 1
- **T(n) = Θ(n^2)**
