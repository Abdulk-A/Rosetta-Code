
import random

s = input("start: ")
e = input("end: ")

sVal = int(s)
eVal = int(e)

# print(f'{sVal}, {eVal}')

num = random.randint(sVal, eVal)
count = 0

while(True):
    guess = input()
    gVal = int(guess)
    count += 1
    if(gVal == num):
        
        break
    elif(gVal < num):
        print("Too Small")
    else:
        print("Too Big")
    

print(f'Number of guesses {count}')
#or
print("Number of guesses", count)


