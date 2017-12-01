#!/usr/bin/python

# Student: Joaquin Saldana 
# Assignment: Homework 1 / Insertion Sort program 

import string 
import io 

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

# list/array variable that will hold what we read from the file and later sort
	intArray = []

	file = open('insert.out', 'w')

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
			newArray = insert_sort(intArray) 

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
	print "Finished writing to insert.out.  Please open the file to see the results.  Thanks."

main() 

		
	



