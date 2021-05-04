# ft_printf
At School 42, we are not allowed to use printf... So let's recode ours! This will be an opportunity to discover a feature of the C variadic functions.
This project aims at rebuilding the printf library with basic functionality, It will manage the following conversions [cspdiuxX%].
 # Format Specifiers
 
 ![screen](https://github.com/edithturn/42-silicon-valley-ft-printf/blob/master/img/format_specifiers.png)
 
 # Context
 
 [ flags ] [ width ] [ precision ] [specifier]
 
 - Flags: `0 +`
 - Specifiers: `c s p d i u x X %`
 
 # Compilation
- git clone the repository
- `cd` into the directory and run `make`
- create a main.c file and include ft_printf.h to test the functions.
```bash
gcc main.c libftprintf.a
```
