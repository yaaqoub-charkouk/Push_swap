#!/bin/bash

# Define all possible test cases in order
test_cases=(
    "1 2 3 4"
    "1 2 4 3"
    "1 3 2 4"
    "1 3 4 2"
    "1 4 2 3"
    "1 4 3 2"
    "2 1 3 4"
    "2 1 4 3"
    "2 3 1 4"
    "2 3 4 1"
    "2 4 1 3"
    "2 4 3 1"
    "3 1 2 4"
    "3 1 4 2"
    "3 2 1 4"
    "3 2 4 1"
    "3 4 1 2"
    "3 4 2 1"
    "4 1 2 3"
    "4 1 3 2"
    "4 2 1 3"
    "4 2 3 1"
    "4 3 1 2"
    "4 3 2 1"
)

# File to track the last executed test index
INDEX_FILE=".last_test_index"

# Get the last executed test index, default to -1 if file does not exist
if [ -f "$INDEX_FILE" ]; then
    last_index=$(cat "$INDEX_FILE")
else
    last_index=-1
fi

# Move to the next test case
next_index=$((last_index + 1))

# If we finished all cases, restart from the beginning
if [ $next_index -ge ${#test_cases[@]} ]; then
    next_index=0
fi

# Get the next test case
current_case=${test_cases[$next_index]}

# Print the test case
echo "Testing: ./push_swap $current_case"

# Run push_swap and copy the result to clipboard
./push_swap $current_case | tee >(xclip -selection clipboard)

# Save the current index for the next execution
echo $next_index > "$INDEX_FILE"

# Confirm copied result
echo "Result copied to clipboard!"
