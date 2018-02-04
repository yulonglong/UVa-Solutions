# Steven Kester Yuwono - UVa 10751

n = int(input())
temp = input() # Throws empty space

for i in range(n):
    num = int(input())
    try: temp = input()
    except Exception as e: pass

    if (num == 1):
        print ("0.000\n")
    elif (num == 2):
        print ("4.000\n")
    else:
        ans = ((2**0.5) - 1) * ((num - 2)**2) + num**2
        print ("%.3f\n" % ans)
