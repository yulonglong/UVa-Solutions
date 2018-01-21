# Steven Kester Yuwono - UVa 11496
# Python 3.5.1

while True:
    n = int(input())
    if (n == 0): break
    store = [None]* (n+2)
    magnitudes = input().split(" ")
    for i in range(len(magnitudes)):
        store[i] = int(magnitudes[i])
    # Add two more extra array entries for comparison
    store[n] = store[0]
    store[n+1] = store[1]

    peaks = 0
    for i in range(n):
        if (store[i] < store[i+1]) and (store[i+1] > store[i+2]):
            peaks += 1
        elif (store[i] > store[i+1]) and (store[i+1] < store[i+2]):
            peaks += 1
    print(peaks)
    