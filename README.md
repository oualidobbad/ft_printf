    # ft_printf

    Drop-in reimplementation of a subset of `printf` with width/precision/flag handling and buffered writes, built atop libft helpers.

    ## Architecture
    - Parser: tokenizes `%` sequences, tracks flags/width/precision/length, and dispatches per-specifier printers.
    - Emitters: small writers for `c s p d i u x X %`, handling padding/alignment/zero-fill and numeric bases.
    - Buffering: direct `write(2)` calls; no stdio dependency; uses libft for string/number helpers.

    ## Build & Install
    - `make` → produces `libftprintf.a`.
    - Requires: libft available or vendored; `cc`, `make`.

    ## Usage
    - Link the archive and include the header:

    ```bash
    cc -Wall -Wextra -Werror main.c -L. -lftprintf -lft -o demo
    ```

    ## Technical Notes
    - Supported specifiers: `%c %s %p %d %i %u %x %X %%` with width, precision, `-` left align, `0` pad, `#` alt form, `+` sign, and space flag.
    - Pointer printing uses `0x` prefix; null pointers render as `(nil)`.
    - No floating-point or length modifiers beyond default int/unsigned; focus is on 42 subject scope.
    - Variadic handling uses `va_list`; avoid reusing the list without rewinding.

    ## Testing Ideas
    - Cross-check against libc `printf` for flags/width/precision permutations.
    - Fuzz numeric formatting with edge cases (INT_MIN, 0, UINT_MAX) and padding interactions.

    ## Author
    Oualid Obbad (@oualidobbad)