#!/bin/bash

# Print ASCII art in yellow
tput setaf 3
echo "

  /\$\$\$\$\$\$  /\$\$\$\$\$\$\$  /\$\$\$\$\$\$\$   /\$\$\$\$\$\$   /\$\$\$\$\$\$        /\$\$\$\$\$\$\$\$                       /\$\$                        
 /\$\$__  \$\$| \$\$__  \$\$| \$\$__  \$\$ /\$\$\$_  \$\$ /\$\$__  \$\$      |__  \$\$__/                      | \$\$                        
| \$\$  \__/| \$\$  \ \$\$| \$\$  \ \$\$| \$\$\$\$\ \$\$| \$\$  \ \$\$         | \$\$     /\$\$\$\$\$\$   /\$\$\$\$\$\$\$ /\$\$\$\$\$\$    /\$\$\$\$\$\$   /\$\$\$\$\$\$ 
| \$\$      | \$\$\$\$\$\$\$/| \$\$\$\$\$\$\$/| \$\$ \$\$ \$\$|  \$\$\$\$\$\$\$         | \$\$    /\$\$__  \$\$ /\$\$_____/|_  \$\$_/   /\$\$__  \$\$ /\$\$__  \$\$
| \$\$      | \$\$____/ | \$\$____/ | \$\$\ \$\$\$\$ \____  \$\$         | \$\$   | \$\$\$\$\$\$\$\$|  \$\$\$\$\$\$   | \$\$    | \$\$\$\$\$\$\$\$| \$\$  \__/
| \$\$    \$\$| \$\$      | \$\$      | \$\$ \ \$\$\$ /\$\$  \ \$\$         | \$\$   | \$\$_____/ \____  \$\$  | \$\$ /\$\$| \$\$_____/| \$\$      
|  \$\$\$\$\$\$/| \$\$      | \$\$      |  \$\$\$\$\$\$/|  \$\$\$\$\$\$/         | \$\$   |  \$\$\$\$\$\$\$ /\$\$\$\$\$\$\$/  |  \$\$\$\$/|  \$\$\$\$\$\$\$| \$\$      
 \______/ |__/      |__/       \______/  \______/          |__/    \_______/|_______/    \___/   \_______/|__/

v1.0 by troberts
"
tput sgr0 # Reset colors

# Define the range of integers
intergerMin=0
intergerMax=2147483647

# Define the lenght of the list of integers
lenghtMin=1
lenghtMax=5000

# Check if an argument is provided and set a default value if not
if [ -z "$1" ]; then
   loops=20
else
   loops=$1
fi

# Define color codes
RED='\033[0;31m'
GREEN='\033[0;32m'
NC='\033[0m' # No Color

# Test case: Empty list
output=$(./PmergeMe 2>&1)
if [ $? -eq 1 ]; then
    echo -e "${GREEN}Test case Empty list: Passed${NC}"
else
    echo -e "${RED}Test case Empty list: Failed\n$output\n${NC}"
fi

# Test case: Negative numbers
output=$(./PmergeMe -1 -2 -3 2>&1)
if [ $? -eq 1 ]; then
    echo -e "${GREEN}Test case Negative numbers: Passed${NC}"
else
    echo -e "${RED}Test case Negative numbers: Failed\n$output\n${NC}"
fi

# Test case: Zero
output=$(./PmergeMe 0 2>&1)
if [ $? -eq 0 ]; then
    echo -e "${GREEN}Test case Zero: Passed${NC}"
else
    echo -e "${RED}Test case Zero: Failed\n$output\n${NC}"
fi

# Test case: Non-integer values
output=$(./PmergeMe 1.5 2.5 3.5 2>&1)
if [ $? -eq 1 ]; then
    echo -e "${GREEN}Test case Non-integer values: Passed${NC}"
else
    echo -e "${RED}Test case Non-integer values: Failed\n$output\n${NC}"
fi

# Test case: Non-numeric values
output=$(./PmergeMe a b c 2>&1)
if [ $? -eq 1 ]; then
    echo -e "${GREEN}Test case Non-numeric values: Passed${NC}"
else
    echo -e "${RED}Test case Non-numeric values: Failed\n$output\n${NC}"
fi

# Test case: Duplicates
output=$(./PmergeMe 1 2 2 3 2>&1)
if [ $? -eq 1 ]; then
    echo -e "${GREEN}Test case Duplicates: Passed${NC}"
else
    echo -e "${RED}Test case Duplicates: Failed\n$output\n${NC}"
fi

# Test case: Mixed invalid inputs
output=$(./PmergeMe 1 -1 0 2.5 a 2 2>&1)
if [ $? -eq 1 ]; then
    echo -e "${GREEN}Test case Mixed invalid inputs: Passed${NC}"
else
    echo -e "${RED}Test case Mixed invalid inputs: Failed\n$output\n${NC}"
fi

# Test case: List with negative and positive numbers
output=$(./PmergeMe -1 2 3 2>&1)
if [ $? -eq 1 ]; then
    echo -e "${GREEN}Test case with negative and positive numbers: Passed${NC}"
else
    echo -e "${RED}Test case with negative and positive numbers: Failed\n$output\n${NC}"
fi

# Test case: List with zero and positive numbers
output=$(./PmergeMe 0 2 3 2>&1)
if [ $? -eq 0 ]; then
    echo -e "${GREEN}Test case with zero and positive numbers: Passed${NC}"
else
    echo -e "${RED}Test case with zero and positive numbers: Failed\n$output\n${NC}"
fi

# Test case: List with non-integer and integer numbers
output=$(./PmergeMe 1.5 2 3 2>&1)
if [ $? -eq 1 ]; then
    echo -e "${GREEN}Test case with non-integer and integer numbers: Passed${NC}"
else
    echo -e "${RED}Test case with non-integer and integer numbers: Failed\n$output\n${NC}"
fi

# Test case: List with non-numeric and numeric values
output=$(./PmergeMe a 2 3 2>&1)
if [ $? -eq 1 ]; then
    echo -e "${GREEN}Test case with non-numeric and numeric values: Passed${NC}"
else
    echo -e "${RED}Test case with non-numeric and numeric values: Failed\n$output\n${NC}"
fi

# Test case: List with duplicate and unique numbers
output=$(./PmergeMe 1 2 2 3 2>&1)
if [ $? -eq 1 ]; then
    echo -e "${GREEN}Test case with duplicate and unique numbers: Passed${NC}"
else
    echo -e "${RED}Test case with duplicate and unique numbers: Failed\n$output\n${NC}"
fi

# Test case: List with mixed invalid inputs
output=$(./PmergeMe 1 -1 0 2.5 a 2 2>&1)
if [ $? -eq 1 ]; then
    echo -e "${GREEN}Test case with mixed invalid inputs: Passed${NC}"
else
    echo -e "${RED}Test case with mixed invalid inputs: Failed\n$output\n${NC}"
fi

printf -- "\n\nCorrect arguments test : \n\n["

# Repeat the process loops times
for ((i = 0 ; i < loops ; i++ )); do
    # Generate a random length for the list of integers (between 1 and max)
    length=$(( RANDOM % (lenghtMax - lenghtMin + 1) + lenghtMin ))

    # Generate a random list of integers with no duplicates
    list=$(shuf -i $intergerMin-$intergerMax -n $length | tr '\n' ' ')

   # Run the program with the generated list as input and suppress its output
   ./PmergeMe $list > /dev/null



# Check the return status of the program
 if [ $? -eq 0 ]; then
     # Print a green # with no new line
     printf -- "\033[32m#\033[0m"
 elif [ $? -eq 1 ]; then
     # Print a red # and the list of numbers used with no new line
     printf -- "\033[31m# $list\033[0m"
 fi
done

printf -- "]\n"