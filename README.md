## Project 3/buddy-system 

* Author: McKenzie Steenson
* Class: CS452/CS552 [Operating Systems] Section #1

Main idea: define 30 circular doubly linked lists:
List 0 connects block headers, and each header
represents a memory block whose size is 2^0=1 byte.
It's kval is 0;
List 2 connects block headers, and each header represents a memory block whose size is 2^2=4 bytes

## Overview

This project is an attempt at implementing a memory allocator by replacing the malloc/free with a personal memory management system based on the buddy system.


## Manifest

`buddy.c` - This is the main project file of this program and contains the four main functions of the implementation of the buddy system. 

The four main functions and their importance are listed below:

- buddy_init(): initializes the main buddy system
- printBuddyLists(): prints the lists of available blocks in the system
- buddy_malloc(): allocates the memory and returns a pointer to the allocated memory
- buddy_free(): frees the memory space allocated by buddy_malloc()

## Building the project

After cloning the repository, from the root of the project run the `make` command in the terminal to build the project. 

## Features and usage

This project is run through the use of test files and cases.

This is how you should run the buddy-unit-test program:
```
(base) [@onyx ]$ ./buddy-unit-test s
(base) [@onyx ]$ ./buddy-unit-test v
```

This is how you should run the buddy-test or malloc-test program:
```
(base) [@onyx ]$ ./buddy-test 100 1234 s
(base) [@onyx ]$ ./buddy-test 100 1234 v
(base) [@onyx ]$ ./malloc-test 100 1234 s
(base) [@onyx ]$ ./malloc-test 100 1234 v
```

My project does not run properly, so the outcome of running the above test cases will result in the printing out of empty lists without any allocation of memory.

## Testing

Code was tested by checking the errors and warnings after the project was built. Running through the gdb debugger helped with troubleshooting the issues in my code, but not enough of my project ran appropriately for this to be useful.

## Known Bugs

Due to issues remaining in the buddy_malloc() and buddy_free() functions, my implementation does not appropriatly allocate or free memory for user use. 

## Reflection and Self Assessment

I was successful (as far as I can tell) in initializing my lists which was confirmed by my buddy print function running correctly and printing out all of the empty lists that were initialized. This was a great feeling!

Things seemed to go down hill from there. I utilized the pseudo code worked on in class in conjunction with the XOR example and casting research from the previous project to build the malloc and free functions with. But after I felt as though I had gotten those fleshed out with the initial aspects, I got lost thinking through the circular double linked list. This is where my project is lacking in the most. Doubly linked lists were a concept I struggled with implementing in CS 321 as well, and my lack of knowledge and practice in C made this even more difficult in this program.

Due to a very busy work and school schedule, I did not leave adequete time to complete this project or even ask for help. I am cutting myself short in a very big way because of this. For future assignments, I'd like to take the advice of my classmates and attempt to get a little bit of the project read through or accomplished each day prior to the due date. 

## Sources Used
[Printing Structs](https://stackoverflow.com/questions/41304497/print-the-structure-fields-and-values-in-c)
[Linked Lists](https://stackoverflow.com/questions/20418624/how-to-check-if-a-linked-list-is-empty)
[Type Casting](https://www.tutorialspoint.com/cprogramming/c_type_casting.htm)