This folder consists of all of the Project Euler Problems completed in this folder
along with some design decisions made. If anything isn't clear based on the comments
or you want to know which script correlates to which problem, you can find this below. 

Problem to File Mapping

Problem 8 - largest_product_in_series.py
Problem 9 - special_pyt_triplet.py

Designs & Notes

Problem 8 - largest_product_in_series.py
Overview of Question: 
Basically we're given a text stream (see test_data_series.txt) and the goal of the 
problem is, based on a numeric value x, calculate the largest product consisting of 
x consecutive numbers in the text file. 
Design: 
Class calles IntSet who's properties are the data and a set of pointers, as well as
obvious things like size. 
The main case is to first calculate the consecutive product for the first x numbers. 
Then, for each itteration through the set, we divide by the oldest value and multiply
by the newest. For this we use a built in python queue to allow fast pops and appends. 
The major concern is zero handling. Honestly the best way to do it is to have a method
which calculates the product between n and m, and a kind of update method. 
That way if we catch a zero comming in, at index i, we can set the left sided index at 
i + 1 and restart. 

