# wildcmp - String Comparison with Wildcards

## Description

`wildcmp` is a C function that compares two strings and returns `1` if they can be considered identical, and `0` otherwise.  
The second string (`s2`) may contain the special wildcard character `*`, which can match any sequence of characters (including the empty string).

This is particularly useful for implementing simple pattern matching, similar to how shell globbing works.

---

## Prototype

```c
int wildcmp(char *s1, char *s2);
