# radix-sort
A C++ program for the implementatoin of radix sort, which works for both positive and negative integers.

This uses a class and multiple functions to perform sorting in O(d*n) time where n is the number of elements in the input array and d is the maximum of number of digits in the largest positive number or the smallest negative number.
The program also takes O(n) extra space.

It basically uses counting sort but instead of doing it on the elements, it does it on the face value of different digits of an element. 
EX: It will first perform counting sort on units place, then tens place then hundreds etc.

Suggestions / improvements are appreciated.
