# do_op

## Conceptual Overview
### The Problem
We are asked to write a program that is given 3 strings as arguments, representing two numbers and a mathematical operation to perform on them. It performs the operation and prints the result.

[ [Full Subject](subject.en.txt) | [Examples](examples.txt) ]

### Approach
Convert the strings representing numbers to ints. Use the string containing the mathematical operator to pick which operation to perform on the two numbers, and print the result. 

## Pseudocode
```
if more or less than 3 arguments have been given
	print a newline and exit
set int x to the converted integer value of the first argument
set int y to the converted integer value of the third argument
if the second argument is "+"
	set int result to the sum x + y
otherwise, if the second argument is "-"
	set int result to the difference x - y
otherwise, if the second argument is "*"
	set int result to the product x * y
otherwise, if the second argument is "/"
	set int result to the dividend x / y
otherwise, if the second argument is "%"
	set int result to the remainder x % y
print the result followed by a newline and exit
```

## Test cases
* Check all operators at least once
* Check negative numbers
* Check 0
* Check INT_MIN and INT_MAX, insuring that the result will fit in an int
```
./do_op "1" "+" "-43" | cat -e
./do_op "5" "-" "-100" | cat -e
./do_op "123" "*" 456 | cat -e
./do_op "9828" "/" 234 | cat -e
./do_op "22" "%" "5" | cat -e
```