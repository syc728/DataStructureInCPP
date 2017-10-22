import random
maxSize = 100000
with open(str(maxSize) + ".txt", "w") as f:
    for x in range(maxSize):
        f.write(str(random.randint(-maxSize, maxSize)))
        f.write('\n')
