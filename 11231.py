# Steven Kester Yuwono - UVa 11231

while (True):
    n,m,c = input().split(" ")
    n,m,c = int(n), int(m), int(c)
    if (n == 0): break
    row0 = ((m - 8) + 1 + c) // 2
    row1 = ((m - 8) + 1 + abs(c-1)) // 2
    numRow0 = (n-8+1)//2
    numRow1 = numRow0
    if (n%2 ==0): numRow0 += 1
    total = numRow0*row0 + numRow1*row1
    print (total)

