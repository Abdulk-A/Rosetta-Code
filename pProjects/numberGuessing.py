
import random

print("Start: ")
s = input()

print("End: ")
e = input()

sVal = int(s)
eVal = int(e)

# print(f'{sVal}, {eVal}')

num = random.randint(sVal, eVal)

while(True):
    guess = input()
    gVal = int(guess)

    if(gVal == num):
        break
    elif(gVal < num):
        print("Too Small")
    else:
        print("Too Big")

