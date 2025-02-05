# TODO
from cs50 import get_int

while True:
    h = get_int("Height: ")
    if h <= 8 and h >= 1:
        break
    else:
        continue
for i in range(h):
    print((h - 1 - i) * " " + (i + 1) * "#" + "  " + (i + 1) * "#")
