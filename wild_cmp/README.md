# 0-wildcmp.c

## Description

This project implements the function `wildcmp`, which compares two strings and determines if they can be considered identical.  
The second string (`s2`) may contain the special character `*`, which can match any sequence of characters (including the empty string).

The function is designed to support wildcard pattern matching similar to shell-style globbing.

---

## Function Prototype

```c
int wildcmp(char *s1, char *s2);
