# Push Swap

Push swap is a project where you have to sort in ascending order number into a stack.
To do that you can use two stack (A and B) and only a few operation describe below.
At the stat
+ the stack A contains a random number, either positive or negative, without any duplicate
+ the stack B is empty

Only the following operation are allowed :

|	Name of operation 	| Description									|
|-----------------------|-----------------------------------------------|
| sa					| swap a - swap the first 2 elements at the top of stack a. Do nothing if there is only one or no elements|
| sb					| swap b - swap the first 2 elements at the top of stack b. Do nothing if there is only one or no elements|
| ss					| sa and sb at the same time |
| pa					| push a - take the first element at the top of b and put it at the top of a. Do nothing if a is empty|
| pb					| push b - take the first element at the top of a and put it at the top of b. Do nothing if a is empty|
| ra					| rotate a - shift up all elements of stack a by 1. The first element becomes the last one. |
| rb					| rotate b - shift up all elements of stack b by 1. The first element becomes the last one. |
| rr					| ra and rb at the same time |
| rra					| reverse rotate a - shift down all elements of stack a by 1. The last element become the first now |
| rrb					| reverse rotate b - shift down all elements of stack a by 1. The last element become the first now |
| rrr					| rra and rrb at the same time |

Two program are developp for this projet. One call checker and one call push_swap

allowed function to developp the 2 programs
+ write
+ read
+ malloc
+ free
+ exit

I use the library [libft](https://github.com/rfibigr/libft)


to compile use the make command
```bash
$>make
```

## The checker program

Checker programm get as an argument the stack a formatted as a list of integers. The first argument should be at the top of
the stack.
Checker then wait and read instruction on the standard input. each instruction must be followed by a '\n'
Once all instruction are read, checker will execute and return 'OK\n' if the instruction succes to sort the stack or "KO\n" if it
doesn't.
In case of Error in the input, checker will display "Error\n"

example

usage : ./checker [-v] [list of number] [instruction]
-v : visual mode
list of number : list of number without duplicate seperated by a space
instruction : set of instruciton followed by a \n

```bash
$>./checker 3 1 2 0
rra
pb
sa
rra
pa
```

To test with random number form 0 to 100 you can use the following command
```bash
ARG=`ruby -e "puts (1..100).to_a.shuffle.join(' ')"`; ./push_swap $ARG | ./checker -v $ARG
```

In the visulazier mode, you can start and stop the sort with the 'space' key and accelerate or deccelerate with the 'arrow left' and 'arrow right' key.
to quit press the 'escape' key




## The push_swap program

push_swap get as an argument the stack a formatted as a list of integers. The first argument should be at the top of the stack (be careful about the order).

The program will display a list of instructions possible to sort the stack a. Instructions output will must be separaed by a ’\n’
•In case of error, you must display Error followed by a ’\n’ on the standard error.

usage : ./push_swap [list of number] <br>
list of number : list of number without duplicate seperated by a space

```bash
$>./push_swap 3 1 2 0

$>./push_swap "3 1 2 0"

$>./push_swap "3 1" 2 0
```

to test with random number from 0 to 100 you can use the following command
```bash
ARG=`ruby -e "puts (1..100).to_a.shuffle.join(' ')"`; ./push_swap $ARG
```
## Author

Romain Fibigr : rfibigr@student.42.fr
