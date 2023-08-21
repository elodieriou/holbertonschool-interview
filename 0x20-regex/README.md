# 0x20. RegEx

## Task

#### 0. Simple RegEx

Write a function that checks whether a given pattern matches a given string.

- Prototype: int regex_match(char const *str, char const *pattern);, where:
  - str is the string to scan
  - pattern is the regular expression
- Your function must return 1 if the pattern matches the string, or 0 if it doesn’t
- str can be empty, and can contain any ASCII character in the exception of . and *
- pattern can be empty, and can contain any ASCII character, including . and *
- The regular expression matching must support the characters . and *
  - . matches any single character
  - * matches zero or more of the preceding character

```text
alex@~/holbertonschool-interview_prep/0x20-regex$ cat main.c
#include <stdlib.h>
#include <stdio.h>

#include "regex.h"

#define TEST_MATCH(s, p)    do {\
    {\
        int res = regex_match(s, p);\
        printf("%s -> %s = %d\n", s, p, res);\
    }\
} while(0)

/**
 * main - Entry point
 *
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */
int main(void)
{
    TEST_MATCH("H", "H");
    TEST_MATCH("HH", "H");
    TEST_MATCH("HH", "H*");
    TEST_MATCH("HHHHHHHHHHHHHHHHH", "H*");

    TEST_MATCH("Holberton", ".*");
    TEST_MATCH("Alex", ".*");
    TEST_MATCH("Guillaume", ".*");
    TEST_MATCH("Julien", ".*");

    TEST_MATCH("Holberton", "Z*H.*");
    TEST_MATCH("Holberton", "Z*H.*olberton");
    TEST_MATCH("Holberton", "Z*H.*o.");
    TEST_MATCH("Holberton", "Z*H.*o");

    TEST_MATCH("Holberton", "holberton");
    TEST_MATCH("Holberton", ".olberton");

    TEST_MATCH("!H@o#l$b%e^r&t(o)n_", "!.@.#.$.%.^.&.(.)._");

    return (EXIT_SUCCESS);
}
alex@~/holbertonschool-interview_prep/0x20-regex$ gcc -Wall -Wextra -Werror -pedantic main.c regex.c
alex@~/holbertonschool-interview_prep/0x20-regex$ ./a.out
H -> H = 1
HH -> H = 0
HH -> H* = 1
HHHHHHHHHHHHHHHHH -> H* = 1
Holberton -> .* = 1
Alex -> .* = 1
Guillaume -> .* = 1
Julien -> .* = 1
Holberton -> Z*H.* = 1
Holberton -> Z*H.*olberton = 1
Holberton -> Z*H.*o. = 1
Holberton -> Z*H.*o = 0
Holberton -> holberton = 0
Holberton -> .olberton = 1
!H@o#l$b%e^r&t(o)n_ -> !.@.#.$.%.^.&.(.)._ = 1
alex@~/holbertonschool-interview_prep/0x20-regex$
```
