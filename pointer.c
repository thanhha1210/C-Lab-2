/*
  Lab 2(Data Lab  - Pointers)
 *
 * <Irene Luu - hdl4>
 *
 * pointer.c - Source file with your solutions to the Lab.
 *             This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>. The included file, "common.c" contains a function declaration
 * that should prevent a compiler warning. In general, it's not good practice
 * to ignore compiler warnings, but in this case it's OK.
 */

#ifndef COMMON_H
#include "common.h"
#endif

/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

#if 0
You will provide your solution to this homework by
editing the collection of functions in this source file.

INTEGER CODING RULES:

  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code
  must conform to the following style:

  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
     not allowed to use big constants such as 0xffffffff.
     However you are allowed to add constants to values greater
     than 255. e.g. 250+250 = 500.
  2. Function arguments and local variables (no global variables).
  3. For 1-3, only use the following:
     Pointer operations '*' and  '&'. (Note that these are only for
     dereferencing and taking addresses, bitwise & is not allowed).
     Binary integer operations - + *.
     Unary integer operation !.
     For the last three, you may also use shifts (<<, >>), ~, ==, and ^.

  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, ?:, sizeof,
     != or binary (bitwise & or |)
  6. Use the [] operator to index into arrays for reading or writing.

  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has *undefined* behavior when shifting by a negative amount or an amount
  greater than or equal to the number of bits in the value being shifted.
  e.g. For x >> n, shifts by n < 0 or n >= *size of x* are undefined
  e.g. if x is a 32-bit int, shifts by >= 32 bits are undefined
  Undefined means you do not know what result you will get from the operation.
#endif

/*
 * STEP 2: Modify the following functions according the coding rules.
 *
 * Test the code below in your own 'main' program.
 *
 */

/*
 * STEP 2: Modify the following functions according the coding rules.
 */

/*
 * Return the size of an integer in bytes.
 *
 * ALLOWED:
 *   Pointer operators: *, &
 *   Binary integer operators: -, +, *
 *   Unary integer operators: !
 *   Shorthand operators based on the above: ex. +=, *=, ++, --, eFDIStc.
 *
 * DISALLOWED:
 *   Pointer operators: [] (Array Indexing Operator)
 *   Binary integer operators: &, &&, |, ||, <, >, <<, >>, ==, !=, ^, /, %
 *   Unary integer operators: ~, -
 */
int intSize() {
  int intArray[10];
  int *intPtr1;
  int *intPtr2;
  // Write code to compute size of an integer.
  /*
    Idea: Use Pointers: 
      1. Declare 2 int pointer
      2. set them to consecutive int element 
      3. Compute different between 2 pointers
  */
  intPtr1 = intArray;
  intPtr2 = intArray + 1;
  // printf("%x\n", intPtr2);
  // printf("%x\n", intPtr1);
  // printf("%p\n", intPtr2 - intPtr1);  
  // Pointer Arithmetric: When subtract 2 pointers point to element of the same array, result
  // NUMBER OF ELEMENTS between 2 points, not NUMBER OF BYTE 

  char *bytePtr1 = (char *)intPtr1; // cast b/c char is always 1 byte in size
  char *bytePtr2 = (char *)intPtr2;
  // each increment of the pointer in pointer arithmetic corresponds to 1 byte. 
  // This allows you to directly calculate the address difference in bytes.
  // Calculate the address difference in bytes
  return bytePtr2 - bytePtr1;
}
/*
 * Return the size of a double in bytes.
 *
 * ALLOWED:
 *   Pointer operators: *, &
 *   Binary integer operators: -, +, *
 *   Unary integer operators: !
 *   Shorthand operators based on the above: ex. +=, *=, ++, --, etc.
 *
 * DISALLOWED:
 *   Pointer operators: [] (Array Indexing Operator)
 *   Binary integer operators: &, &&, |, ||, <, >, <<, >>, ==, !=, ^, /, %
 *   Unary integer operators: ~, -
 */
int doubleSize() {
  double doubArray[10];
  double *doubPtr1;
  double *doubPtr2;
  // Write code to compute size of a double.
  doubPtr1 = doubArray;
  doubPtr2 = doubArray + 1;

  char* c1 = (char*) doubPtr1;
  char* c2 = (char*) doubPtr2;

  return c2 - c1;
}

/*
 * Return the size of a pointer in bytes.
 *
 * ALLOWED:
 *   Pointer operators: *, &
 *   Binary integer operators: -, +, *
 *   Unary integer operators: !
 *   Shorthand operators based on the above: ex. +=, *=, ++, --, etc.
 *
 * DISALLOWED:
 *   Pointer operators: [] (Array Indexing Operator)
 *   Binary integer operators: &, &&, |, ||, <, >, <<, >>, ==, !=, ^, /, %
 *   Unary integer operators: ~, -
 */
int pointerSize() {
  double *ptrArray[10];
  double **ptrPtr1;
  double **ptrPtr2;
  // Write code to compute size of a pointer.

  ptrPtr1 = ptrArray;
  ptrPtr2 = ptrArray + 1;

  char *c1 = (char*) ptrPtr1;
  char *c2 = (char*) ptrPtr2;

  return c2 - c1;
}

/*
 * Given pointers to two distinct variables write a function to swap the values
 * of said variables.
 *
 * ALLOWED:
 *   Pointer operators: *, &
 *   Binary integer operators: -, +, *
 *   Unary integer operators: !
 *   Shorthand operators based on the above: ex. +=, *=, ++, --, etc.
 *
 * DISALLOWED:
 *   Pointer operators: [] (Array Indexing Operator)
 *   Binary integer operators: &, &&, |, ||, <, >, <<, >>, ==, !=, ^, /, %
 *   Unary integer operators: ~, -
 */
void swapInts(int *ptr1, int *ptr2) {
  // Your code here
  int temp = *ptr1;
  *ptr1 = *ptr2;
  *ptr2 = temp;  
}

/*
 * Modify intArray[5] to be the value 295 using only intArray and pointer
 * arithmetic.
 *
 * ALLOWED:
 *   Pointer operators: *, &
 *   Binary integer operators: -, +, *, <<, >>, ==, ^
 *   Unary integer operators: !, ~
 *   Shorthand operators based on the above: ex. +=, *=, ++, --, ~= etc.
 *
 * DISALLOWED:
 *   Pointer operators: [] (Array Indexing Operator)
 *   Binary integer operators: &, &&, |, ||, <, >, !=, /, %
 *   Unary integer operators: -
 */
int changeValue() {
  int intArray[10];
  int *intPtr1 = intArray;
  // Remember not to use constants greater than 255.
  // Remember to use * to dereference. You cannot use '[<index>]' syntax.
  *(intPtr1 + 5) = 255 + sizeof(intArray);

  return intArray[5];
}

/*
 * Return 1 if the addresses stored in ptr1 and ptr2 are within the
 * *same* 64-byte aligned  block of memory. Check the spec for examples if you
 * are confused about what this means. Return zero otherwise. Operators / and %
 * and loops are NOT allowed.
 *
 * ALLOWED:
 *   Pointer operators: *, &
 *   Binary integer operators: -, +, *, <<, >>, ==, ^
 *   Unary integer operators: !, ~
 *   Shorthand operators based on the above: ex. <<=, *=, ++, --, etc.
 *
 * DISALLOWED:
 *   Pointer operators: [] (Array Indexing Operator)
 *   Binary integer operators: &, &&, |, ||, <, >, !=, /, %
 *   Unary integer operators: -
 */
int withinSameBlock(int *ptr1, int *ptr2) {
  // Your code here

  return 1;

}

/*
 * Return 1 if ptr points to an element within the specified intArray, 0
 * otherwise. Pointing anywhere in the array is fair game, ptr does not have to
 * point to the beginning of an element. Check the spec for examples if you are
 * confused about what this method is determining.
 * size is the size of intArray in number of ints. Can assume size != 0.
 * Operators / and % and loops are NOT allowed.
 *
 * ALLOWED:
 *   Pointer operators: *, &
 *   Binary integer operators: -, +, *, <<, >>, ==, ^
 *   Unary integer operators: !, ~
 *   Shorthand operators based on the above: ex. <<=, *=, ++, --, etc.
 *
 * DISALLOWED:
 *   Pointer operators: [] (Array Indexing Operator)
 *   Binary integer operators: &, &&, |, ||, <, >, !=, /, %
 *   Unary integer operators: -
 */
int withinArray(int *intArray, int size, int *ptr) {
  // Your code here
  
  return 2;
}

/*
 * In C characters are are terminated by the null character ('\0')
 * given a pointer to the start of the string return the length of this string.
 * (The null character is not counted as part of the string length.)
 *
 * ALLOWED:
 *   Pointer operators: *, &
 *   Binary integer operators: -, +, *, ==, !=, <, >
 *   Unary integer operators: !
 *   Shorthand operators based on the above: ex. <<=, *=, ++, --, etc.
 *   Control constructs: for, while
 *
 * DISALLOWED:
 *   Pointer operators: [] (Array Indexing Operator)
 *   Binary integer operators: &, &&, |, ||, <<, >>, ^, /, %
 *   Unary integer operators: ~, -
 */
int stringLength(char *s) {
  // Your code here
  char *cur = s;
  int len = 0;
  while (*cur != '\0') {
    len++;
    cur = cur + 1;
  }
  return len;
}

/*
 * Change the value pointed to by ptr byte-by-byte so that when returned as an
 * integer the value is 295295.
 *
 * Hint: Remember that an int is 4 bytes.
 *
 * Hint: Remember how little endian works for data storage, how is it different
 * between an multiple bytes(int) and a single byte?
 *
 * Hint: It will be easiest to start convert 295295 into binary form and
 * starting seeing how the endian works from there.
 *
 * ALLOWED:
 *   Pointer operators: *, &
 *   Binary integer operators: -, +, *
 *   Shorthand operators based on the above: ex. +=, *=, ++, --, etc.
 *   Unary integer operators: !
 *
 * DISALLOWED:
 *   Pointer operators: [] (Array Indexing Operator)
 *   Binary integer operators: &, &&, |, ||, <, >, <<, >>, ==, !=, ^, /, %
 *   Unary integer operators: ~, -
 */
int endianExperiment(int *ptr) {
  char *bytePtr;
  // Your code here
  // 295295 to hex = 0x4817F => 0x0004817F. Little endian: 7F, 81, 04, 00
  bytePtr = (char*) ptr; // change byteptr to be start of ptr
  *(bytePtr) = 0x7F;
  *(bytePtr + 1) = 0x81;
  *(bytePtr + 2) = 0x04;
  *(bytePtr + 3) = 0x00;

  return *ptr;
}

/**
 * Swaps the values stored at the memory addresses pointed to by a and b.
 */

/**
 * Performs an in-place selection sort on int array arr with length len.
 */
/*
 * Selection sort is a sorting algorithim that works by partitioning the array
 * into a sorted section and unsorted section. Then it repeatedly selects the
 * minimum element from the unsorted section and moves it to the end of the
 * sorted section.
 *
 * So the pseudo-code might look something like this:
 * arr - an array
 * n - the length of arr
 *
 * for i = 0 to n - 1
 *   minIndex = i
 *   for  j = i + 1 to n - 1
 *       if arr[minIndex] > arr[j]
 *           minIndex = j
 *       end if
 *   end for
 *   Swap(arr[i], arr[minIndex])
 * end for
 *
 * We have implemented selection sort below, it might be helpful to use the
 * swapInts you defined earlier, and the to be written smallest_idx function now
 * .
 *
 * ALLOWED:
 *   Pointer operators: *, &
 *   Binary integer operators: -, +, *, ==, !=, <, >
 *   Unary integer operators: !
 *   Shorthand operators based on the above: ex. +=, *=, ++, --, etc.
 *   Control constructs: for, while, if
 *   Function calls: swapInt()
 *
 * DISALLOWED:
 *   Pointer operators: [] (Array Indexing Operator)
 *   Binary integer operators: &, &&, |, ||, <<, >>, ^, /
 *   Unary integer operators: ~, -
 */

/*
Using your new knowledge of arrays in C, implement the smallest_idx function to
return the index of the smallest element in an array. Be careful not to step out
of bounds!
*/

/**
 * Returns the index of the smallest element in int array arr with length len.
 */
int smallest_idx(int *arr, int len) {
  int i;
  int smallest_i = 0;
  int smallest = arr[0];

  // TODO: implement me using a for loop.
  for (int i = 1; i < len; i++) {
    if (smallest > *(arr + i)) {
      smallest = *(arr + i);
      smallest_i = i;
    }
  }
  return smallest_i;
}

// This function will work, if you implement smallest_idx and swapInts.
void selectionSort(int *arr, int len) {
  int i, swap_idx;
  for (i = 0; i < len; i++) {
    swap_idx = i + smallest_idx(arr + i, len - i);
    swapInts(arr + i, arr + swap_idx);
  }
}
