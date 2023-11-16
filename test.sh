#!/bin/bash

# Test interactive mode
echo -e "($)" | ./hsh

echo -e "($) /bin/ls" | ./hsh
echo -e "($) exit" | ./hsh

# Test non-interactive mode
echo -e "/bin/ls\nexit" | ./hsh

# Create a test input file
echo -e "/bin/ls" > test_ls_2

# Test non-interactive mode with input from a file */
cat test_ls_2 | ./hsh

# Clean up
rm test_ls_2
