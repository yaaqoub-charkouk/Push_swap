#!/bin/bash

# Array of numbers to permute
numbers=(1 2 3 4)

# Function to generate permutations
permute() {
    local items="$1"
    local out="$2"
    if [ ${#items} -eq 0 ]; then
        echo "$out"
    else
        for (( i=0; i<${#items}; i++ )); do
            permute "${items:0:i}${items:i+1}" "$out${items:i:1} "
        done
    fi
}

# Generate permutations and test with ./push_swap
for perm in $(permute "${numbers[@]}"); do
    ./push_swap $perm
done