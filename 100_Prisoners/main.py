
import random

def printArr(arr, n):
    for i in range(n):
        if(i % 10 == 0):
            print()
        print(arr[i], end=' ')
    print()

def playRandom(arr, n):
    cupBoard = [False] * n
    for i in range(n):
        k = random.randrange(n) #number from 0-99
        success = False
        for j in range(50):
            if(cupBoard[k] == False):
                cupBoard[k] = True
                break
            if(arr[k] == i):
                success = True
                break
        if(success == False):
            return False
    return True

def playSmart(arr, n):
    for i in range(n):
        k = i
        success = False
        for j in range(50):
            if(arr[k] == i):
                success = True
                break
            else:
                k = arr[k]
        if(success == False):
            return False
    return True


cards = []
n = 100

#got the cards and shuffled
for i in range(0,n):
    cards.append(i)



successCount = 0

for i in range(10000):
    random.shuffle(cards)
    if(playSmart(cards, n) == True):
        successCount += 1

print(successCount)