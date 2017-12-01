#!/usr/bin/python

# Student: Joaquin Saldana 
# Assignment: Homework 1 / Merge Sort program 

import string 
import io 
import random 
from random import randint
import time 


# Citation: the code for the merge_sort and the sort functions was borrowed from the 
# following site https://pythonandr.com/2015/07/05/the-merge-sort-python-code/

def merge(array1, array2):

    mergedArray = []

    while len(array1) != 0 and len(array2) != 0:
        if array1[0] < array2[0]:
            mergedArray.append(array1[0])
            array1.remove(array1[0])
        else:
            mergedArray.append(array2[0])
            array2.remove(array2[0])

    if len(array1) == 0:
        mergedArray += array2
    else:
        mergedArray += array1

    return mergedArray

#=====================================================================

# Citation: the code for the merge_sort and the sort functions was borrowed from the 
# following site https://pythonandr.com/2015/07/05/the-merge-sort-python-code/

def merge_sort(arrayOfInts): 

    if len(arrayOfInts) == 0 or len(arrayOfInts) == 1:
        
        return arrayOfInts
    
    else:
        
        middle = len(arrayOfInts)/2
        
        a1 = merge_sort(arrayOfInts[:middle])
        
        a2 = merge_sort(arrayOfInts[middle:])
        
        return merge(a1,a2)

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
	newArray = merge_sort(randomIntArray)

	# to identify how many seconds have passed we substract from the 
	# current time the start time 
	print("--- Algorithm took %s seconds --- " % (time.time() - start_time))

main() 