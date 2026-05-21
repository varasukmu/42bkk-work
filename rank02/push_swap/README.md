*This project has been created as part of the 42 curriculum by vasukmua*

# PUSH_SWAP

## Description
**Push_swap** is a 42 algorithm project. The goal is to sort numbers on a stack using a limited set of instructions and the fewest moves possible. 

This implementation uses the **Chunk Sort (Butterfly)** approach. It indexes numbers by size, divides them into chunks, pushes them to Stack B to create a "butterfly" shape, and then systematically pushes the largest numbers back to Stack A.

## Instructions

### Operations
- `pa` : Push top of B to A.
- `pb` : Push top of A to B.
- `ra` : Rotate A (shift up, first becomes last).
- `rb` : Rotate B (shift up, first becomes last).
- `sa` : Swap first 2 elements of A.
- `sb` : Swap first 2 elements of B.
- `rra` : Reverse Rotate A (shift down, last becomes first).
- `rrb` : Reverse Rotate B (shift down, last becomes first).

### Compilation and Usage
Run `make` to compile the `push_swap` executable.

```bash
make
./push_swap 2 1 3 6 5 8
# or
./push_swap "2 1 3 6 5 8"
# or with random numbers
ARG=$(seq -1000 1000 | shuf -n 100 | tr '\n' ' '); ./push_swap $ARG
```
### Other Commands

- `make clean` : Remove .o files.
- `make fclean` : Remove .o files and the executable.
- `make re` : Recompile everything.

### Project File

`main.c`: Program entry point and main sorting dispatcher.

`parse_utils.c` / `split_utils.c` : Input parsing and error checking.

`stack.c`: Linked list setup and node management.

`operation.c`: Core logic (push, swap, rotate, reverse rotate).

`wrappers_operations_a.c` / `wrappers_operations_b.c`: Executes actions and prints to standard output.

`easy_sort.c`: Hardcoded sort for 3, 4, and 5 elements.

`sort.c` : Main Chunk/Butterfly Sort algorithm for larger datasets.

`helper.c` : Utilities for chunk sizes, indexing, and memory freeing.

## Resources

### People

- usoontra ( 42 BKK )

### Youtube

- [Push_swap: The least amount of moves with two stacks (Oceano)](https://youtu.be/OaG81sDEpVk?si=T2BCs9wO0HhyZlq6)

### Document

- [Push_Swap: The least amount of moves with two stacks](https://medium.com/@jamierobertdawson/push-swap-the-least-amount-of-moves-with-two-stacks-d1e76a71789a)

### AI Used

- Idea for wrapper_operation
- Calculate chunk size
- free stack, node, argvs (memory)