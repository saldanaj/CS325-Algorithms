#!/usr/bin/python

# Student: Joaquin Saldana 
# Assignment: Homework 1 / Merge Sort program 

import string 
import io 

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

# list/array variable that will hold what we read from the file and later sort
	intArray = []

	file = open('merge.out', 'w')

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
			newArray = merge_sort(intArray) 

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
	print "Finished writing to merge.out.  Please open the file to see the results.  Thanks."

main() 