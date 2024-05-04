
import random 

s = input()

def encode(s, n):
    t = ""
    for i in range(len(s)):
        # print(ord(s[i]))
        rem = 0
        chVal = ord(s[i])
        if chVal >= 65 and chVal <= 90 and chVal + n > 90:
            rem = 64 + (n - (90 - chVal))
        elif chVal >= 97 and chVal <= 122 and chVal + n > 122:
            rem = 96 + (n - (122 - chVal))
        else:
            rem = chVal + n
        t += chr(rem)
    return t

cipher = encode(s, random.randint(0,25))

print(cipher)