#ifndef HEADER
#define HEADER

#include <stdio.h>
int _pow_recursion(int x, int y);
int stoi(char *, int);
int _isdigit(char c);
int add_recursive(char **ptr, int arg, int size);
int has_ndigit(char *ptr, int idx);
int next_change(int idx, int amount);
int count_changes(int amount, int sum);

#endif
