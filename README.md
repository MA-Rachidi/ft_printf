# ft_printf

## Description

ft_printf is a custom implementation of the standard C library function printf.
The goal of this project is to rebuild printf from scratch in order to understand how formatted output works in C, and to practice handling variadic functions as well as advanced formatting rules.

This implementation supports:

Character and string output (%c, %s, %p)

Integer conversions (%d, %i, %o, %u, %x, %X) with length modifiers (hh, h, l, ll)

Floating-point numbers (%f) with l and L modifiers

The literal percent sign (%%)

Formatting flags: #, 0, -, +, and space

Minimum field width and precision

The project provides a library libftprintf.a, which can be linked to other programs and reused across future projects.
