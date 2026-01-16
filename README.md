# Push_Swap

*This project has been created as part of the 42 curriculum by mkhoubaz.*

## Description

Push_Swap is project that consists of sorting numbers using two stacks (Stack A and Stack B) with a specific moves. The goal is to sort a list of 100 integers in less then 700 moves and a list of 500 integers in less then 5500 moves. Bonus part is to create a checker that will check if the list is sorted correctly.

## Instructions

1. To compile the push_swap program, run the following command in your terminal:

   ```bash
   make
   ```

   For checker program, use:

   ```bash
   make bonus
   ```

2. To run the push_swap program, use command with a list of integers as arguments:

   ```bash
   ./push_swap [list of integers]
   ```

   Example:

   ```bash
   ./push_swap 3 2 5 1 4
   ```

   > This will output the sequence of operations needed to sort the list.

3. To run the checker program, use command with a list of integers as arguments and start providing operations via standard input:

   ```bash
   ./checker [list of integers]
   ```

   Example:

   ```bash
   ./checker 3 2 5 1 4
   ```

   Then, provide the operations line by line, followed by EOF (Ctrl+D on Unix/Linux or Ctrl+Z on Windows).

> Any invalid arguments in push_swap or checker will get "Error" printed on the standard error output.

## Resources

- [w3schools](https://www.w3schools.com/dsa/dsa_timecomplexity_theory.php) for time complexity.
- [GeeksforGeeks](https://www.geeksforgeeks.org/dsa/sorting-algorithms/) for sorting algorithms.
- [GeeksforGeeks](https://www.geeksforgeeks.org/c/implement-stack-in-c/) for stack implementation in C.
- [GeeksforGeeks](https://www.geeksforgeeks.org/dsa/swap-nodes-in-a-linked-list-without-swapping-data/) for linked list node swapping.

I use AI to explain how to swap linked list and debug segfault in my code.
