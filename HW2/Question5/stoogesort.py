#!/usr/bin/python

# Student: Joaquin Saldana 
# Assignment: Homework 2 / Stooge Sort program 

import string 
import io 

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

# list/array variable that will hold what we read from the file and later sort
	intArray = []

	file = open('stooge.out', 'w')

	with open('data.txt') as datafile:
		for line in datafile: 
			#read the line from the file and insert/append the values in to a list/array where we will start 
			# the insertsort algorithm and output to a file 
			data = line.split() 

			# append to the list the numbers read from the file 
			for i in data: 
				intArray.append(int(i)) 

			# store the size of the array into the variable 
			arraySize = intArray[0]
			
			# print the variable for testing 
			# print arraySize 

			# remove the variable from the array/list 
			del intArray[0]

			#insertion sort algorithm 
			newArray = stooge_sort(intArray) 

			# print the list for the sake of checking it's working 
			print newArray

			for number in newArray:  
				file.write(str(number))
				file.write(" ")

			file.write("\n")

			# empty the contents of the array so we can start over, and continue starting over until
			# we have reached the end of file 
			del intArray[:]
			del newArray[:]

	file.close()
	print "Finished writing to stooge.out.  Please open the file to see the results.  Thanks."

main() 