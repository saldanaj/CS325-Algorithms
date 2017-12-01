#!/usr/bin/python

# Student: Joaquin Saldana 
# Assignment: Homework 1 / Insertion Sort program 

import string 
import io 
import random 
from random import randint
import time 

# insertion sort algorithm/function 
def insert_sort(arrayOfInts): 

	for a in range(1, len(arrayOfInts)): 
		
		# entering second loop to iterate through the array with the key and 
		# see if it's placed in the correct order
		b = a

		while b > 0 and arrayOfInts[b] < arrayOfInts[b-1]:
			#swap the items if the item at b is greater than b-1
			 arrayOfInts[b], arrayOfInts[b-1] = arrayOfInts[b-1], arrayOfInts[b] 
			 b = b - 1

	# return the new sorted array 
	return arrayOfInts 


#=====================================================================

def main(): 

	randomIntArray = []

	# what will be the size of the array, this will contain the values 1000, 2000, 5000, and 10,000
	n = 50000

	while len(randomIntArray) < n: 
		randomIntArray.append(randint(0, 10000))

	# will start the timer now that we are about to enter the insertion sort algorithm/function 
	start_time = time.time()

	#insertion sort algorithm 
	newArray = insert_sort(randomIntArray)

	# to identify how many seconds have passed we substract from the 
	# current time the start time 
	print("--- Algorithm took %s seconds --- " % (time.time() - start_time))

main() 
