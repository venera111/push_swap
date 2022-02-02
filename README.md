# push_swap

### Mandatory part
- You have to write a program named push_swap which will receive as an argument the stack a formatted as a list of integers. The first argument should be at the top of the stack (be careful about the order).
- The program must display the smallest list of instructions possible to sort the stack a, the smallest number being at the top.
- Instructions must be separated by a ’\n’ and nothing else.
- The goal is to sort the stack with the minimum possible number of operations.
During defence we’ll compare the number of instructions your program found with a maximum number of operations tolerated. If your program either displays a list too big or if the list isn’t sorted properly, you’ll get no points.
- If no parameters are specified, the program must not display anything and give the
prompt back
- In case of error, you must display Error followed by a ’\n’ on the standard error. Errors include for example: some arguments aren’t integers, some arguments are bigger than an integer, and/or there are duplicates.

### Bonus part


### Examples
```
./push_swap "54 0 -16" "9"
```
should be output:
```
pb
sa
pa
ra
```

### Resources
Unix Processes in C: [Лекция push_swap @einterdi](https://www.youtube.com/watch?v=98r9uhjPveE)

