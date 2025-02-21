#!/bin/bash

# Function to count the number of moves
count_moves() {
    echo "$1" | wc -l
}

# Array of all permutations of four numbers
permutations=(
    "0 1 2 3"
    "0 1 3 2"
    "0 2 1 3"
    "0 2 3 1"
    "0 3 1 2"
    "0 3 2 1"
    "1 0 2 3"
    "1 0 3 2"
    "1 2 0 3"
    "1 2 3 0"
    "1 3 0 2"
    "1 3 2 0"
    "2 0 1 3"
    "2 0 3 1"
    "2 1 0 3"
    "2 1 3 0"
    "2 3 0 1"
    "2 3 1 0"
    "3 0 1 2"
    "3 0 2 1"
    "3 1 0 2"
    "3 1 2 0"
    "3 2 0 1"
    "3 2 1 0"
)

# Loop through each permutation and test with ./push_swap
for perm in "${permutations[@]}"; do
    moves=$(./push_swap $perm)
    move_count=$(count_moves "$moves")
    echo "Number of moves for input $perm: $move_count"
done
