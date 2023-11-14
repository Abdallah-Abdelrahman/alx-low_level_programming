# Dynamic libraries
Creating Shared libraries (dynamic libraries) in c

<details>
<summary><b>libdynamic.so</b></summary>
dynamic library comproises a dozen of `c` object files
</details>

---

<details>
<summary><b>1-create_dynamic_lib</b></summary>
creates a dynamic library called liball.so from all the .c files that are in the current directory <br />
  
-- command <br /> 
  
```
gcc -Wall -Werror -Wextra -pedantic -std=c99 -shared -Wl,-soname,liball.so -o liball.so -fPIC *.c

-Wall
           This enables all the warnings about constructions that some users consider questionable, and that are easy to avoid (or modify to prevent the warning), even
           in conjunction with macros.  This also enables some language-specific warnings described in C++ Dialect Options and Objective-C and Objective-C++ Dialect
           Options.
-Werror
           Make all warnings into errors.
-Wextra
           This enables some extra warning flags that are not enabled by -Wall. (This option used to be called -W.  The older name is still supported, but the newer
           name is more descriptive.)
-pedantic
           Issue all the warnings demanded by strict ISO C and ISO C++; reject all programs that use forbidden extensions, and some other programs that do not follow
           ISO C and ISO C++.  For ISO C, follows the version of the ISO C standard specified by any -std option used.
-std=
           Determine the language standard.   This option is currently only supported when compiling C or C++.
 -shared
           Produce a shared object which can then be linked with other objects to form an executable.  Not all systems support this option.  For predictable results,
           you must also specify the same set of options used for compilation (-fpic, -fPIC, or model suboptions) when you specify this linker option.[1]
-o file
           Place the primary output in file file.  This applies to whatever sort of output is being produced, whether it be an executable file, an object file, an
           assembler file or preprocessed C code.

           If -o is not specified, the default is to put an executable file in a.out
-Wl,option
           Pass option as an option to the linker.  If option contains commas, it is split into multiple options at the commas.  You can use this syntax to pass an
           argument to the option.
-fPIC
           If supported for the target machine, emit position-independent code, suitable for dynamic linking and avoiding any limit on the size of the global offset
           table.  This option makes a difference on AArch64, m68k, PowerPC and SPARC.

           Position-independent code requires special support, and therefore works only on certain machines.

           When this flag is set, the macros "__pic__" and "__PIC__" are defined to 2.
           
```
</details>

---

<details>
<summary><b>100-operations.so</b></summary>
dynamic library comproises a `c` file consists of funcitons that perform the following operations (+, -, %, /)

command to generate the library:

```
gcc -Wall -Werror -Wextra -pedantic -std=c99 -shared -Wl,-soname,100-operations.so  -o 100-operations.so -fPIC -I/usr/include/python3.4 100-operations.c

-I to override a system header file, substituting your own version
```

</details>
