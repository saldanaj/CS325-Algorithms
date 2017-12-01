#!/usr/bin/python

# Student: Joaquin Saldana 
# Assignment: Homework 2 / Stooge Sort program 

import string 
import io 
import random 
from random import randint
import time 

# Much of my code was inspired from the following post: 
# http://www.geeksforgeeks.org/stooge-sort/

def stooge_sort(arrayOfInts, i=0, j=None): 

	if j is None:
		j = len(arrayOfInts) - 1
	if arrayOfInts[j] < arrayOfInts[i]:
		arrayOfInts[i], arrayOfInts[j] = arrayOfInts[j], arrayOfInts[i]
	if j - i > 1:
		t = (j - i + 1) // 3
		stooge_sort(arrayOfInts, i  , j - t)
		stooge_sort(arrayOfInts, i + t, j)
		stooge_sort(arrayOfInts, i  , j - t)
	
	return arrayOfInts


#=====================================================================

def main(): 

	randomIntArray = []

	# what will be the size of the array, this will contain the values 1000, 2000, 5000, and 10,000
	n = 5000

	while len(randomIntArray) < n: 
		randomIntArray.append(randint(0, 10000))

	# will start the timer now that we are about to enter the insertion sort algorithm/function 
	start_time = time.time()

	#insertion sort algorithm 
	newArray = stooge_sort(randomIntArray)

	# to identify how many seconds have passed we substract from the 
	# current time the start time 
	print("--- Algorithm took %s seconds --- " % (time.time() - start_time))

main() 