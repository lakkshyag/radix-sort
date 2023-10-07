# radix-sort
A C++ program for the implementation of radix sort, which works for both positive and negative integers.

This uses a class and multiple functions to perform sorting in O(d*n) time where n is the number of elements in the input array and d is the maximum of number of digits in the largest positive number or the smallest negative number.
The program also takes O(n) extra space.

It basically uses counting sort but instead of doing it on the elements itself, it does it on the face value of different digits of an element. 
EX: It will first perform counting sort on units place, then tens place, then hundreds etc.

Because of its working, radix sort is best used when the number of elements is large when compared to the maximum number of digits in an element.

Suggestions / improvements are appreciated.
