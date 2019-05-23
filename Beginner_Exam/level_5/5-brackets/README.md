# brackets

## Conceptual Overview
### The Problem
We are asked to write a program that takes an arbitrary number of arguments. For each argument, it checks to see if each opening bracket, '(', '[', or '{', is matched by the corresponding closing bracket, ')', ']', or '}', in the correct order. For each argument in which all brackets that appear are matched in the correct order, the program prints "OK", otherwise it prints "Error".

<details>
	<summary>Full Subject</summary>

```
	Assignment name  : brackets 
	Expected files   : *.c *.h
	Allowed functions: write
	--------------------------------------------------------------------------------

	Write a program that takes an undefined number of strings in arguments. For each
	argument, the program prints on the standard output "OK" followed by a newline 
	if the expression is correctly bracketed, otherwise it prints "Error" followed by
	a newline.

	Symbols considered as 'brackets' are brackets '(' and ')', square brackets '[' 
	and ']'and braces '{' and '}'. Every other symbols are simply ignored.

	An opening bracket must always be closed by the good closing bracket in the 
	correct order. A string which not contains any bracket is considered as a 
	correctly bracketed string.

	If there is no arguments, the program must print only a newline.

	Examples :

	$> ./brackets '(johndoe)' | cat -e
	OK$
	$> ./brackets '([)]' | cat -e
	Error$
	$> ./brackets '' '{[(0 + 0)(1 + 1)](3*(-1)){()}}' | cat -e
	OK$
	OK$
	$> ./brackets | cat -e
	$
	$>
```
</details>

### References
* [Subject File (English)](subject.en.txt)
* [brackets.c (iterative)](brackets.c)
* [brackets_recursive.c (recursive, longer and slower than iterative)](brackets_recursive.c)

### Approaches
1. **Iterate through the string, using a second string as a stack of brackets**
	For each string given as argument, create an array of chars the size of the string or bigger. Iterate through the string. For each opening bracket, store it in the array. For each closing bracket, check whether the most recent opening bracket matches it. If it does, remove the opening bracket from the array; otherwise, print "Error" and repeat with the next argument.
2. **Recurse one function to check each pair of brackets**
	For each string given as argument, iterate through the string until an opening bracket is found. When an opening bracket is found, iterate through the string looking for the matching closing bracket, recursing if another opening bracket is found.

### Code
1. **Iterative Approach**

```C
#include <unistd.h>

#define MATCH(a, b) ((a == ')' && b == '(') || (a == ']' && b == '[') || (a == '}' && b == '{'))

int	ft_strlen(char *str)
{
	int i = -1;
	while (str[++i]);
	return (i);
}

int	brackets(char *str)
{
	int i = 0;
	int stack[ft_strlen(str)];

	while (*str)
	{
		if (*str == '(' || *str == '[' || *str == '{')
			stack[++i] = *str;
		else if (*str == ')' || *str == ']' || *str == '}')
		{
			if (MATCH(*str, stack[i]) == 0)
				return (-1);
			--i;
		}
		str++;
	}
	if (i != 0)
		return (-1);
	return (0);
}

int	main(int ac, char **av)
{
	if (ac < 2)
	{
		write(1, "\n", 1);
		return (0);
	}

	int i = 1;
	while (i < ac)
	{
		if (brackets(av[i]) == -1)
			write(1, "Error\n", 6);
		else
			write(1, "OK\n", 3);
		++i;
	}
	return (0);
}
```

2. **Recursive Approach**

```C
#include <unistd.h>

int	recurse(char *str)
{
	char c;

	if (str[0] == '(')
		 c = ')';
	else if (str[0] == '[')
		c = ']';
	else if (str[0] == '{')
		c = '}';
	else
		return (-1);

	int i = 1;
	int result;
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		else if (str[i] == ')' || str[i] == ']' || str[i] == '}')
			return (-1);
		else if (str[i] == '(' || str[i] == '[' || str[i] == '{')
		{
			if ((result = recurse(str + i)) == -1)
				return (-1);
			else
				i += result;
		}
		++i;
	}

	return (-1);
}

int	brackets(char *str)
{
	int i = 0;
	int result;

	while (str[i])
	{
		if (str[i] == ')' || str[i] == ']' || str[i] == '}')
			return (-1);
		else if (str[i] == '(' || str[i] == '[' || str[i] == '{')
		{
			if ((result = recurse(str + i)) == -1)
				return (-1);
			else
				i += result;
		}
		++i;
	}
	return (0);
}

int	main(int ac, char **av)
{
	if (ac < 2)
	{
		write(1, "\n", 1);
		return (0);
	}

	int i = 1;
	while (i < ac)
	{
		if (brackets(av[i]) == -1)
			write(1, "Error\n", 6);
		else
			write(1, "OK\n", 3);
		++i;
	}
	return (0);
}
```

### Test Cases
```
$> ./brackets '(johndoe)' | cat -e
OK$
$> ./brackets '([)]' | cat -e
Error$
$> ./brackets '' | cat -e
OK$
$> ./brackets 'no brackets' | cat -e
OK$
$> ./brackets '({[unresolved opening bracket]}' | cat -e
Error$
$> ./brackets '({[extra closing bracket]}))' | cat -e
Error$
$> ./brackets '' '{[(0 + 0)(1 + 1)](3*(-1)){()}}' | cat -e
OK$
OK$
$> ./brackets | cat -e
$
$>
```

##### Moulinette's Tests
```
./brackets '(toto)'
OK
./brackets '([)]'
Error
./brackets '' '{[(0 + 0)(1 + 1)](3*(-1)){()}}'
OK
OK
./brackets

./brackets '()' '[]' '{}' '' 'toto' '([{}[{(()[])}()]]())(((([])))())'
OK
OK
OK
OK
OK
OK
./brackets '()[]{}' '([{}])[({})]{([])}'
OK
OK
./brackets '(]' '{)' '[}' ')' '}' ')' '(' '{' '['
Error
Error
Error
Error
Error
Error
Error
Error
Error
./brackets '({)}' '[()]{}]' '])}' '([{' "(cette (trace n'a pas [de but precis]) {a part embeter (tout le monde)})"
Error
Error
Error
Error
OK
```