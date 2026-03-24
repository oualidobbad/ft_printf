  # ft_printf

  Drop-in reimplementation of the 42 `ft_printf`, covering core specifiers with direct `write(2)` output and no stdio buffering.

  ## Project Overview
  - What it does: formats and prints `c s p d i u x X %` to STDOUT with count of written bytes.
  - Use cases: replacement for `printf` in constrained libc environments (42 projects) where only allowed functions are `write`, `malloc`, etc.
  - Problem solved: provides formatting without relying on stdio or forbidden functions.

  ## Architecture & Design
  - Dispatcher: `ft_printf()` walks the format string and forwards each specifier to `printss()` (ft_printf.c) using `va_list`.
  - Emitters: thin functions per type (ft_putstr, ft_putchar, ft_putnbr, ft_putnbr_uns, ft_puthex) that write directly.
  - Hex/pointer: `ft_puthex()` handles lowercase/uppercase and pointer prefix `(nil)/0x...` (ft_puthex.c).
  - Error path: null format returns `write(1, "", 1) - 2` to signal misuse per subject expectations.

  ## Core Concepts
  - Variadic processing: `va_start/va_arg/va_end` used once; no rewinding, so specifiers are consumed in-order.
  - Recursion for number rendering: `ft_putnbr` and `ft_puthex` recurse to emit higher digits first, ensuring correct order without buffers.
  - Signed vs unsigned: `ft_putnbr_uns` prints `unsigned int`; pointers use `unsigned long` to match address width.

  ### Example: dispatcher and hex
  ```c
  // ft_printf.c
  static int printss(char c, va_list list) {
    if (c == 'x' || c == 'X') return ft_puthex(va_arg(list, unsigned int), c);
    else if (c == 'p') return ft_puthex(va_arg(list, unsigned long), c);
    // ... other specifiers ...
  }

  int ft_puthex(unsigned long n, char c) {
    if (c == 'p') {
      if (n == 0) return write(1, "(nil)", 5);
      return write(1, "0x", 2) + hex_low(n);
    }
    return (c == 'X') ? hex_up(n) : hex_low(n);
  }
  ```

  ## Code Walkthrough
  1) `ft_printf`: iterates the format, dispatches on `%`, accumulates byte count.
  2) `printss`: maps specifier → emitter, pulling the right type from `va_list`.
  3) Emitters:
     - `ft_putnbr`: handles sign, recursion, INT_MIN special case.
     - `ft_putnbr_uns`: unsigned decimal.
     - `ft_puthex`: base-16 conversion; pointer prefix/null handling.
     - `ft_putstr/ft_putchar`: string/char output.

  ## Installation & Setup
  - Build: `make` → `libftprintf.a`.
  - Dependencies: libc (write), headers only; no external libs.

  ## Usage Guide
  ```bash
  cc -Wall -Wextra -Werror main.c -L. -lftprintf -o demo
  ./demo
  ```
  - Include `ft_printf.h`; ensure libft is linked if you reuse its helpers.

  ## Technical Deep Dive
  - Complexity: each emitter is O(n) on the number of digits/chars; no heap except via caller.
  - Stack use: recursion depth bounded by digits (~32 for 64-bit hex).
  - Pointer printing: uses `unsigned long` to avoid truncation on 64-bit.
  - Limitations: no width/precision/flags beyond the subject scope; no floating-point; no length modifiers (hh, ll, etc.).

  ## Improvements & Future Work
  - Add width/precision/flag parsing with a small state machine.
  - Introduce buffered writes to reduce syscalls on large outputs.
  - Expand length modifiers and floating-point support.

  ## Author
  Oualid Obbad (@oualidobbad)