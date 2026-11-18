*This project has been created as part of the 42 curriculum by joacarva.*

# ft_printf

## Description

**ft_printf** is a project from the 42 curriculum that consists of recreating the standard C `printf()` function.

The goal is to understand variadic functions, format string parsing, number conversions, and low-level output operations in C.

The project generates a static library called `libftprintf.a`, which can be linked to other C programs.

### Supported Conversions

| Specifier | Description |
|-----------|-------------|
| `%c` | Prints a single character |
| `%s` | Prints a string |
| `%p` | Prints a pointer address in hexadecimal |
| `%d` | Prints a signed decimal integer |
| `%i` | Prints a signed integer |
| `%u` | Prints an unsigned decimal integer |
| `%x` | Prints a hexadecimal number (lowercase) |
| `%X` | Prints a hexadecimal number (uppercase) |
| `%%` | Prints a percent sign |

## Instructions

### Compilation

Clone the repository:

```bash
git clone https://github.com/joacarva/ft_printf.git
cd ft_printf
```

Compile the library:

```bash
make
```

This generates:

```text
libftprintf.a
```

### Makefile Commands

| Command | Description |
|---------|-------------|
| `make` | Compiles the library |
| `make clean` | Removes object files |
| `make fclean` | Removes object files and the library |
| `make re` | Recompiles the library |

### Usage

Create a `main.c` file:

```c
#include "ft_printf.h"

int main(void)
{
    ft_printf("Hello, %s!\n", "42");
    ft_printf("Number: %d\n", 42);
    ft_printf("Hexadecimal: %x\n", 255);
    return (0);
}
```

Compile and execute:

```bash
cc main.c -L. -lftprintf -o program
./program
```

Expected output:

```text
Hello, 42!
Number: 42
Hexadecimal: ff
```

## Algorithm and Data Structures

### 1. Variadic Arguments

The project uses the `stdarg.h` library to handle a variable number of arguments.

- `va_list` stores the argument list state.
- `va_start` initializes the argument list.
- `va_arg` retrieves the next argument.
- `va_end` ends argument processing.

This approach allows `ft_printf()` to receive different numbers and types of arguments.

### 2. Format String Parsing

The main function iterates through the format string character by character.

When a `%` is found, the next character determines which conversion should be performed.

Each conversion is handled by a helper function.

Regular characters are written directly using `write()`.

The function tracks the total number of printed characters and returns that value.

This algorithm was chosen because it is simple, efficient, and does not require dynamic memory allocation.

### 3. Decimal Conversion

Decimal integers are converted using division and modulo operations.

- `% 10` extracts the last decimal digit.
- `/ 10` removes the last decimal digit.
- Negative numbers require printing a minus sign.

Recursion can be used to print the digits in the correct order.

### 4. Hexadecimal Conversion

Hexadecimal numbers use base 16.

A character array maps values from 0 to 15 to hexadecimal digits:

```c
char *hex_chars = "0123456789abcdef";
```

The expression:

```c
hex_chars[num & 0xF]
```

extracts the lowest four bits of the number and converts them into the corresponding hexadecimal character.

The operation:

```c
num >>= 4;
```

shifts the number four bits to the right, allowing the next hexadecimal digit to be processed.

This approach is efficient because hexadecimal digits directly correspond to groups of four bits.

### 5. Pointer Conversion

Pointer addresses are converted into an unsigned integer type capable of representing an address.

The resulting value is printed in hexadecimal, usually with a `0x` prefix.

This prevents address truncation that could occur when using a regular `unsigned int`.

### 6. Data Structures

The project does not require complex data structures.

The main structures used are:

- **va_list:** Manages variadic arguments.
- **Character arrays:** Convert numeric values into hexadecimal characters.
- **Integer counters:** Track the number of printed characters.

These structures were chosen to keep the implementation simple and lightweight.

### 7. Error Handling

Helper functions return the number of characters written or `-1` when an output operation fails.

The main function propagates write errors and returns `-1` when necessary.

## Resources

### Documentation

- [printf — Linux Manual](https://man7.org/linux/man-pages/man3/printf.3.html)
- [Variadic Arguments — cppreference](https://en.cppreference.com/w/c/variadic.html)
- [write — Linux Manual](https://man7.org/linux/man-pages/man2/write.2.html)
- [Bitwise Operators — cppreference](https://en.cppreference.com/w/c/language/operator_arithmetic.html)

### AI Usage

AI was used as a learning and debugging resource during the development of this project.

Specifically, it was used to:

- Understand variadic functions (`va_start`, `va_arg`, `va_end`).
- Explain decimal and hexadecimal number conversions.
- Understand bitwise operations and bit shifting.
- Clarify pointer representation and argument types.
- Review implementation ideas and explain potential errors.
- Assist with README documentation.

The implementation and programming decisions were developed and reviewed by the author.
