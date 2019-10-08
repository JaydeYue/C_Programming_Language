# C_Programming_Language
My solutions to exercises in C Programming Language 2nd Edition, i.e. K&amp;R2

## How to run

* In each chapter, there is a makefile that should compile all exercises in that chapter into an executable chapter(number).o
* If you want to run only a subset of exercises or change some mutable parameters of some exercises, you can make those changes in main.c

Here is an example for chapter1

```bash
$ cd Chapter1
$ make
$ ./chapter1.o
```

## Structures

* The exercises are divided into chapters according to the book, and all exercises are run by main.c of that chapter
* Each exercise has its own c file named according to its functionality, but all functions are declared in main.h of that chapter.
* Some exercises have helper functions which are included in their c file and declared in main.h under their core functions

## Progress

* Finished and tested all chapter1 exercises
* Finished and tested all chapter2 exercises (though more to be done with floating range calculation for 2-1 later)
* Working on Chapter3!
* I didn't test thoroughly, please report any bugs you may have found!
* Planning on finishing all exercises in this book by 2020
