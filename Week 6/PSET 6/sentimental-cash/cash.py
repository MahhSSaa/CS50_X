# TODO
from cs50 import get_float

while True:
    remain = get_float("Change owed: ")
    if remain > 0:
        break
    else:
        continue

remain = round(remain * 100)

coins = 0

while remain > 0:
    if remain >= 25:
        remain -= 25
    elif remain >= 10:
        remain -= 10
    elif remain >= 5:
        remain -= 5
    else:
        remain -= 1

    coins += 1

print(coins)
