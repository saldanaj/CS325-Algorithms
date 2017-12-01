#!/usr/bin/python

# Student: Joaquin Saldana 
# Assignment: Homework 3 / Make Change Dynamic Programming

import string 
import io


# Function returns the minimum amount of denominations that are minimum
# necessary to return the change of the total amount

def change_Min(amount, arrayOfDenominations): 

	numberOfCoins = [] 

	coinsUsedArray = [] 

	for i in range(0, amount + 1): 
		if i == 0: 
			# if we're in the first index of the array then it's 0
			numberOfCoins.append(0)
		else:
			# else we append infinity to the "cell"
			numberOfCoins.append(float("inf")) 


	for i in range(0, amount + 1): 
		coinsUsedArray.append(float("inf"))


	for j in range(len(arrayOfDenominations)): 
		for i in range(1, amount + 1): 
				if numberOfCoins[i] > (1 + numberOfCoins[i - arrayOfDenominations[j]]): 
					numberOfCoins[i] = (1 + numberOfCoins[i - arrayOfDenominations[j]])
					coinsUsedArray[i] = j 


	index = len(coinsUsedArray) - 1

	numberOfCoinsUsed = [] 

	# initialize the empty list 
	for i in range(0, len(arrayOfDenominations)): 
		numberOfCoinsUsed.append(0)

	# now create the arry that we will print to the file 
	while index != 0: 
		numberOfCoinsUsed[coinsUsedArray[index]] = numberOfCoinsUsed[coinsUsedArray[index]] + 1
		index = index - arrayOfDenominations[coinsUsedArray[index]]


	return  numberOfCoins[-1], numberOfCoinsUsed

#=====================================================================

def main(): 

	# next we have to assign the variable "amount" the amount read from the file

	file = open('change.txt', 'w')

	with open("amount.txt") as datafile: 

		line_count = 0 

		values = -1 

		for line in datafile: 

			# now we check if we're in the first line which is the denomination values 
			if line_count % 2 == 0: 

				denominationsArray = [] 

				data = line.split() 

				for number in data: 

						tempNum = int(number)
						denominationsArray.append(tempNum)


			# else we are in the 2nd (or in this case the even line) which means we are 
			# about to read the total value 
			elif line_count % 2 == 1: 

				value = line.rstrip("\n")

				# call the make change function 
				coinNumber, coinsUsed = change_Min(int(value), denominationsArray)


				# now we need to write the values to the file change.txt 
				for i in denominationsArray: 
					tempValue = str(i)
					file.write(tempValue + " ")

				file.write("\n")
				file.write(value)
				file.write("\n")

				for i in coinsUsed: 
					tempValue = str(i)
					file.write(tempValue + " ")

				file.write("\n")
				file.write(str(coinNumber))
				file.write("\n")


			line_count+=1

	file.close()
	print "Finished writing to change.txt.  Please open the file to see the results.  Thanks."

main() 