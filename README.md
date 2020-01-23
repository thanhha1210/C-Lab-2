# C-Lab-2
C Lab 2

Introduction to Memory in C
===========================
 
**Important:** You may work with a partner, but you will turn in the lab individually. Please put the netID of the person you worked with, if applicable, in a comment at the top of your submitted file.

Overview
--------

This lab will introduce you to dealing with memory in C. There are three sections to this lab: arrays, pointers, and sorting. After completing each section, have a TA check over your work before you proceed.

Developing C code requires a C compiler and debugger. You may develop on your own machine if you have gcc and gdb installed. However, you should always make sure that your work compiles and runs in the designated course computing environment before submitting. Information about setting up the computing environment can be found on the Resources page.

To begin, find the `lab2.c` file in your github repository and pull it into your VM or CSUG account. It contains some C functions as well as function stubs you will need to implement. By the end of this lab, you will have completed a working implementation of the _selection sort_ algorithm, and will have a working program that demonstrates the sort running on arrays of different sizes.

After completing each function, compile your program with `gcc -std=c99 -Wall -Werror lab2.c -o lab2`; you can then run it with `./lab2`.

As a way to help you debug and visualize what is going on in your code, feel free to use Python Tutor's [C visualization tool](https://goo.gl/buPYHE).

**A helpful resource before starting this lab is looking through the ***Powerpoint***

Part 1: Arrays
--------------

Arrays in C are similar to arrays in other programming languages you may be familiar with, but with one important difference. In C, arrays are simply _contiguous blocks of memory_. In general, there is no way to determine the length of an array from the array itself. Therefore, it is the _programmer's responsibility_ to make sure the length of the array is known and respected so the program does not try to access an index that is outside the valid range of the array.

Arrays in C are indexed using brackets. `arr[idx]` accesses the element of array `arr` at index `idx`. C arrays are zero-indexed, so the first element in an array is `arr[0]`. Since one _cannot_ find the length of an array from the array alone, array handling functions in C usually receive the array's length as a separate parameter.

> Using your new knowledge of arrays in C, implement the `smallest_idx` function to return the index of the smallest element in an array. Be careful not to step out of bounds!

Part 2: Pointers
----------------

Pointers are central to C programming, yet are often one of the most foreign concepts to new C coders. A pointer is an integer that represents the address of an object in memory. Pointers in C are _typed_, which means the pointer's type includes the type of the value it points to. The type of a pointer is the type of the value it points to, followed by a `*`. For example, `int* ptr;` declares a pointer to an int, or an "int pointer".

To access the value (memory location) referenced by a pointer, the `*` character is again used, as the "dereference" operator. The following simple function returns the int value pointed to by an int pointer:

```C
int get\_val(int \*ptr) {
    return \*ptr;
}
```

The dereference (`*`) operator is also used to assign a value to the memory location pointed to by a pointer, as seen in the below function;

```C
void set\_val(int \*ptr, int val) {
    \*ptr = val;
}
```

Lastly, the "address of" (`&`) operator is used to obtain a pointer to a variable. It returns the address of the value given to it. Try to work out in your head what the following main function would print:

```C
int main() {
    int x = 5;
    int \*ptr = &x; // obtain a pointer to x
    printf("%d\\n", get\_val(ptr));
    set\_val(ptr, 4);
    printf("%d\\n", x);
}
```

> Using your new knowledge of pointers in C, implement the `swap` function, which takes two int pointers as parameters and swaps the ints stored at the two addresses.

Part 3: Sorting
---------------

Selection sort is a sorting algorithm that does an in-place comparison sort. The algorithm divides the input array into two parts: the subarray of items already sorted, which is built up from left to right at the front of the array, and the subarray of items remaining to be sorted that occupy the rest of the array. Initially, the sorted subarray is empty and the unsorted subarray is the entire array. The algorithm proceeds by finding the smallest element in the unsorted subarray, exchanging it with the leftmost unsorted element (putting it in sorted order), and moving the subarray boundaries one element to the right.

Here is an example of this sort algorithm sorting five elements:

64 25 12 22 11 // this is the initial, starting state of the array

11 25 12 22 64 // sorted sublist = {11}

11 12 25 22 64 // sorted sublist = {11, 12}

11 12 22 25 64 // sorted sublist = {11, 12, 22}

11 12 22 25 64 // sorted sublist = {11, 12, 22, 25}

11 12 22 25 64 // sorted sublist = {11, 12, 22, 25, 64}

(Source: [Wikipedia](http://en.wikipedia.org/wiki/Selection_sort))

> Implement the `selection_sort` function using your `smallest_idx` and `swap` functions, following the outline in the `lab8.c` file.

Useful Tool to Visualize C Code
-------------------------------

C code sometimes seems to be hard to understand as we just start to learn it. A good way to get a more comprehensive understanding of C code is to use a C code visualization (https://www.onlinegdb.com/online_c_compiler) we recommand a good tool for C code visualization. It can be useful for debugging also!
