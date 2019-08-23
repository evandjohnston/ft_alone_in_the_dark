# Bitwise Operations

42's Beginner Exam has several problems on it that require an understanding of bitwise operations to solve, such as:

* lvl 2: print_bits
* lvl 2: reverse_bits
* lvl 2: swap_bits
* lvl 5: options

To solve these problems, you will need to understand four bitwise operators.

### Bitwise Operators

##### *&* : Bitwise AND

* Works similarly to logical AND, `&&`
* Evaluates to 1 if *both* operands are 1
* `1 & 1` evaluates to `1`
* `1 & 0` evaluates to `0`
* `0 & 0` evaluates to `0`
* Where the decimal number 3 is represented as '0000 0011' and 153 is represented as `1001 1001`, `3 & 153` evaluates to `0000 0001`

##### *|* : Bitwise OR

* Works similarly to logical OR, `||`
* Evaluates to 1 if *either* operand is 1
* `1 | 1` evaluates to `1`
* `1 | 0` evaluates to `1`
* `0 | 0` evaluates to `0`
* Where the decimal number 3 is represented as '0000 0011' and 153 is represented as `1001 1001`, `3 | 153` evaluates to `1001 1011`

##### *>>* : Bitshift to the right

* Moves every bit to the right by the given number of places
* Given a variable `var` whose bitwise representation is `1001 0000`:
	* `var >> 1` would be represented as `0100 1000`
	* `var >> 7` would be represented as `0000 0001`
	* `var >> 8` would be represented as `0000 0000`

##### *<<* : Bitshift to the left

* Moves every bit to the left by the given number of places in the same manner as bitshift right

### Using Bitwise Operators

##### Using Binary Representation of Numbers in C

Before we start using bitwise operators, we need to know how to set up the values they're operating on. If we want to define a variable's value by its binary representation, we can do so by prefixing the value with `0b` when defining. For example, the decimal number 13 is represented as `0000 1101`, so we can assign that value to a variable `var` with `var = 0b00001101`.

What if we need to convert between binary and decimal to double-check our work on the test? There are lots of great resources available to teach you to do this by hand, but on the test the most reliable way is to use the Calculator app. Open it, click `View` -> `Programmer`, and if necessary click `Show Binary` to display the binary representation of whatever decimal number you enter with the keypad. If you want to convert from binary to decimal, click on the digits of the binary representation to toggle them on and off, and the corresponding decimal number will appear at the top.

##### Bitmasking with Bitwise AND

Let's say we have a variable whose value we've set to `0b01101100`, and we want to isolate the four bits on the right. We can use a bitmask that turns off the bits on the left, which looks like `0b00001111`. 

Now that we have our bitmask, we use the bitwise AND operator to apply it to our variable: `0b01101100 & 0b00001111` evaluates to `0b00001100`. Each digit of the result is found by comparing the corresponding digit of both inputs: because we're using the AND operator, if both input digits are a 1, the output is a 1, otherwise it will be a 0.

##### Combining Values with Bitwise OR

Now let's say we have two values that we want to combine, `0b10110000` and `0b00001001`. All we have to do is use Bitwise OR: `0b10110000 | 0b00001001` evaluates to `0b10111001`.

### Example: Swapping the First and Last Bits of a Byte

Let's say we have some arbitrary 8-bit chunk of data we'll call `octet`, and we want to swap its first and last bits. We'll need to isolate its leftmost bit, move it 7 places to the right, and combine it with the isolated rightmost bit moved 7 places to the left, then combine the result of that with the center bits.

```C
unsigned char swap_first_and_last_bits(unsigned char octet)
{
	unsigned char result;
	unsigned char temp;

	// Example input value for octet: 0b10010100

	// Isolate the leftmost bit:
	result = octet & 0b10000000;
	// With example input, result is now 0b10000000

	// Move the leftmost bit to the right 7 places:
	result = result >> 7;
	// With example input, result is now 0b00000001

	// Isolate the rightmost bit and move it to the left:
	temp = (octet & 0b00000001) << 7;
	// With example input, temp is now 0b00000000

	// Combine the leftmost and rightmost bits:
	result = result | temp;
	// With example input, result is now 0b00000001

	// Isolate the center bits of the input value:
	temp = octet & 0b01111110;
	// With example input, temp is now 0b00010100

	// Combine the center bits with the outer bits:
	result = result | temp;
	// With example input, result is now 0b00010101

	return (result);
}
```