# Exam Trips, Tricks, and Mentality

### Aliases

Use aliases to type less and avoid typos. For example, if you enter `alias wgcc="gcc -Wall -Wextra -Werror -fsanitize=address -g"` into your terminal, you'll be able to compile your code with all warning flags by typing `wgcc <filename.c>`.

### Shell Functions

If you want a more powerful tool to handle repetitive typing, you can use shell functions. For example, to make sure your filenames and paths are correct every time, you can write a function:

```
function mkk() {
	mkdir ~/rendu/$1 && cd ~/rendu/$1 && touch ~/rendu/subjects/$1.c
}
```

### Use #ifdef for test code

```
#ifdef TEST
#include <stdio.h>

int main(void)
{
	printf("%d", ft_strlen("test string"));
	return (0);
}
#endif
```

Compile with `-D TEST` to include the test main in compilation:	`wgcc -D TEST <filename.c> && ./a.out`

### Use zsh

Most of us are used to using a terminal running `zsh`, since that's the default on the lab computers. However, the exam accounts use `sh` by default.

You might notice the difference when running a program that writes to standard output a string that doesn't end with a newline. `zsh` adds a `%` and a newline, while `sh` just prints the string and then the prompt on the same line.

In order to use `zsh` for your shell, just enter `zsh` into your terminal.

### Use LLDB to chase down segfaults

`lldb` is a terminal app that allows you to run your programs step-by-step, and it can show you the values of all your variables and the execution order of each instruction so you can figure out where unexpected behavior is coming from. There's a *lot* you can do with it, but one of the simplest is understanding segmentation faults.

To use lldb, you'll want to first compile your program with debug symbols by adding `-g` to your call to the compiler: `gcc -g -Wall -Wextra -Werror <filename.c>`. If you don't compile with debug symbols, you'll have to be able to read assembly code to understand what's going on.

Once your program is compiled, open it in lldb by running `lldb <program name>`, for example `lldb a.out`. The lldb program will start, and your terminal prompt will be `(lldb)`. Enter `run`, and the program will run until an error occurs or it finishes normally.

If an error occurs, you'll be given the line number of the code causing the error. You can display the contents of all the variables at the current point by entering `frame variable`.

This barely scratches the surface of what lldb can do, so I highly recommend that you read through a tutorial and check out the documentation.

* https://towardsdatascience.com/an-introduction-to-debugging-in-c-and-lldb-part-i-e3c51991f83a
* https://www.classes.cs.uchicago.edu/archive/2017/winter/15200-2/assigns/week5/lldb.html#lldb
* https://aaronbloomfield.github.io/pdr/tutorials/02-lldb/index.html
* https://lldb.llvm.org