# TODO
from cs50 import get_string

content = get_string("content: ")

alphabet = 0
word = 0
sentence = 0

for i in content:
    if i.isalpha():
        alphabet += 1
    if i == "." or i == "?" or i == "!":
        sentence += 1
word = len(content.split())

average_word = word / 100
l = alphabet / average_word
s = sentence / average_word

result = round(0.0588 * l - 0.296 * s - 15.8)

if result < 1:
    print("Before Grade 1")
elif result >= 16:
    print("Grade 16+")
else:
    print(f"Grade {result}")
