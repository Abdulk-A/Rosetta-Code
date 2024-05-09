
import random

words = ['rainbow', 'computer', 'science', 'programming', 'python','mathematics', 
         'player', 'condition', 'reverse', 'water', 'board', 'geeks']
          
word = random.choice(words)

count = 10
userInput = ''

##############################################
######GETTING UNIQUE LETTERS OF A STRING######
##############################################

def uniqueLetters(word):
    word = word.lower()
    n = len(word)

    a = [0] * 26

    for i in range(n):
        index = ord(word[i]) - ord('a')
        a[index] = 1

    uniqueLetterCount = 0

    for i in range(26):
        if a[i] == 1:
            uniqueLetterCount += 1
    return uniqueLetterCount

##############################################
##############################################

uniqueLetterCount = uniqueLetters(word)
print(uniqueLetterCount)
while count > 0:
    guess = input("char: ")
    userInput += guess

    for char in word:
        if char in userInput:
            print(char, end=" ")
            uniqueLetterCount -= 1
            print()
        else:
            print("_")

    if(uniqueLetterCount == 0):
        break
    count -= 1