# Sum-in-list
A program that finds if there is a consecutive sequence of numbers that have sum 100 in a list of numbers.

In order to run the code in Linux environment after you clone that project:

## Step 1 

Build/Create an executable : gcc -o sum Sum_in_list.c 

## Step 2

Run the executable using: ./sum  

When the programm starts you will be asked about how many elements you want to put. After that you will need to put the elements. 

The program tests using a recursive function if two consecutive numbers that the user gave sums to 100. It has two functions, one that is reading the numbers from the user and one that is calculating the sum.
An example of running the program and finding a pair like that is:


>How many elements you want to put:4  
> Put the 1 element:10  
> Put the 2 element:90  
> Put the 3 element:5  
> Put the 4 element:1  
> Success sum of 100 between the numbers 10, 90!!