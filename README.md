# Push Swap
---



Push swap is a project where you have to sort number in ascending order on a stack.
To do that you can only use two stack (A and B) and only a few operation describe below.

At the start
+ the stack A contains a random number, either positive or negative, without any duplicate
+ the stack B is empty

to know more about the project, you can read the instruction in the [french : push_swap.fr.pdf](https://github.com/rfibigr/push_swap/blob/master/PDF/push_swap.fr.pdf) [english : push_swap.pdf](https://github.com/rfibigr/push_swap/blob/master/PDF/push_swap.en.pdf)

This readme include information from the pdf file.

Visualization of my project
![Alt Text](https://github.com/rfibigr/push_swap/blob/master/divers/ezgif.com-crop.gif)

## The rules to sort

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


to compile use the make command
```bash
$>make
```


## The checker program

Checker programm get as an argument a stack formatted as a list of integers. The first argument should be at the top of the stack.
Checker then wait and read instruction on the standard input. each instruction must be followed by a '\n'
Once all instruction are read, checker will execute and return 'OK\n' if the instruction succes to sort the stack or "KO\n" if it doesn't.
In case of Error in the input, checker will display "Error\n"


## The push_swap program

push_swap get as an argument a stack formatted as a list of integers. The first argument should be at the top of the stack (be careful about the order).
The program will display a list of instructions possible to sort the stack a. Instructions output will must be separaed by a ’\n’
•In case of error, you must display Error followed by a ’\n’ on the standard error.


## My implementation

I used a linked list to save the value in the stack. I have to verify that there is no duplicate number on my stack. To do that in a effecient way, i realised a merge sort on my linked list. Each time i merge my sorted element, i verify for duplicate.

To realise the sort i used three algorithms:
+ for very short list (2 or 3 element) i create a optimise sort to be sur to do the less operation possible.
+ for short list (<= 40 elements) i did a selective sort
+ for all the list (>= at 40 elements) i did a customize short, based on a merge short, and adapated to the contraint of this game.
The principe is to try to short the stack consecutively by ascending and descending order.

The visualizer is a bonus feature I realise.

## Library used

allowed function of standard libc to developp the 2 programs
+ write
+ read
+ malloc
+ free
+ exit

I use a custom library I create [libft](https://github.com/rfibigr/libft)
and the [minilibx library](https://github.com/rfibigr/push_swap/tree/master/lib/minilibx_macos) (a custom graphic library) to create the visualizer.

## How to install and use

To install download the repo and compile the source.

```bash
git clone https://github.com/rfibigr/push_swap.git
cd push_swap
make
```

### Use push_swap

usage : ./push_swap [list of number]
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

### Use checker

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
ARG=`ruby -e "puts (1..100).to_a.shuffle.join(' ')"`; ./push_swap $ARG | ./checker $ARG
```

### Use visualizer

```bash
ARG=`ruby -e "puts (1..100).to_a.shuffle.join(' ')"`; ./push_swap $ARG | ./checker -v $ARG
```

Visualizer command :
+ 'Escap' to quit
+ 'space' to start pause
+ 'right key' to increase the number of cycle each second
+ 'left key' to reduce the number of cycle each second

## Licence and contact

Feel free to use or contact me for more information.
