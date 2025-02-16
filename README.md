# Kirilang-A-User-Friendly-Programming-Language

Compiler Construction: 

We have designed “Kirilang” language, which is similar in constructs to the python language, but also takes inspiration from the C language in a few aspects such as include statements, function/ conditional statement scope delimited by terminal symbols,(instead of tab spaced function scope as in python), and also simplified print statements as is the case with python. We will make a language translator from Kirilang to C language.

For Compiling the program follow the steps mentioned below:
```bash
1. flex lexical_file.l
2. yacc -d yacc_file.y
3. cc lex.yy.c y.tab.c -lfl
```
