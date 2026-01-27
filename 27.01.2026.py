#1
name = input("Paste your name: ")
age = input("Paste your age: ")
print(f"Hello, {name}! You are {age} years old.")


first = int(input("Paste your first number: "))
second = int(input("Paste your second number: "))
third = int(input("Paste your third number: "))
sum_numbers = first+second+third
print(f"sum of numbers: {sum_numbers}")

#2
number = int(input("Paste your number: "))

if number % 2 == 0:
    print(f"Number {number} is even ")
else:
    print(f"Number {number} is not even")




num1 = int(input("Paste your first number: "))
num2 = int(input("Paste your srcond number: "))

if num1 > num2:
    print(f"First number ({num1}) bigger them ({num2})")
elif num1 < num2:
    print(f"Second number ({num2}) bigger them ({num1})")
else:
    print("Numbers are equal")





num = int(input("Paste your age: "))


if num >= 18:
    print("You can get your driving license")
else:
    print("You can not get a driving licxense boy!")

#3
N = int(input("Paste number : "))

for i in range(1, N + 1):
    print(i)





word = input("Paste word: ")

for letter in word:
    print(letter)




N = int(input("Paste number N: "))
summa = 0
for i in range(1, N + 1):
    summa += i 
print(f"{summa}")

#4




