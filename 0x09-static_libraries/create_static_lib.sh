#!/bin/bash
gcc -c -Wall -Werror -pedantic -Wextra -std=gnu89 *.c && ar -crs liball.a *.o
