# COMPARISON-OF-CLASSIFICATION-ALGORITHMS 

Sorting Algorithms Comparison
This repository contains a C program that compares the performance of three sorting algorithms: 
Insertion Sort, Improved Quicksort, and Non-Recursive Merge Sort. 

The program measures the execution time of each algorithm for arrays of varying sizes and prints the average execution time for each algorithm.

### Files

sorting_algorithms.c: The C program that implements the sorting algorithms and measures their performance.

### How to Run

Compile the program using gcc:
Run the program:

The program will print the average execution time for each algorithm for arrays of sizes 10,000 to 100,000 with a step of 10,000.
For each dimension, the program creates 10 different snapshots of random number tables.

Algorithms Implemented

Insertion Sort
insertionsort2: An inefficient implementation of Insertion Sort.
insertionsort: An efficient implementation of Insertion Sort.

Non-Recursive Merge Sort
mergesort: The Non-Recursive Merge Sort algorithm.
merge: A helper function that merges two sorted arrays.

Improved Quicksort
quicksort: The Quicksort algorithm with a median-of-three pivot selection.
partition: A helper function that partitions the array around the pivot.
sort: The Improved Quicksort algorithm that uses Quicksort for large arrays and Insertion Sort for small arrays.

### Goal

The goal of this project is to determine which algorithm is the fastest for classification among the three algorithms compared.

### License

This program is licensed under the UOWM(University of Western Macedonia) License, as part of Algorithms and Data Structures course.

### Acknowledgments

This program was developed as part of a project to compare the performance of different sorting algorithms.



