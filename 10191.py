# Steven Kester Yuwono - UVa 10191 - Longest Nap

counter = 1
num = input()

while (num):
    num = int(num)
    timeslot = [False] * 480
    for i in range(num):
        line = input().split()
        start = line[0].split(":")
        end = line[1].split(":")
        startMinutes = ((int(start[0])-10)*60) + int(start[1])
        endMinutes = ((int(end[0])-10)*60) + int(end[1])
        for j in range(startMinutes, endMinutes):
            timeslot[j] = True


    bestStart = 0
    bestDuration = 0
    currStart = 0
    currDuration = 0
    prevFree = False
    for j in range(480):
        if (not timeslot[j]):
            if prevFree: currDuration += 1
            else:
                currDuration = 1
                currStart = j
                prevFree = True
        else:
            if prevFree: 
                prevFree = False
                if currDuration > bestDuration:
                    bestDuration = currDuration
                    bestStart = currStart

    if currDuration > bestDuration:
        bestDuration = currDuration
        bestStart = currStart

    startHour = bestStart /60 + 10
    startMinute = bestStart % 60
    durationHour = bestDuration / 60
    durationMinute = bestDuration % 60

    if bestDuration >= 60:
        print("Day #%d: the longest nap starts at %.2d:%.2d and will last for %d hours and %d minutes." % (counter, startHour, startMinute, durationHour, durationMinute))
    else:
        print("Day #%d: the longest nap starts at %.2d:%.2d and will last for %d minutes."% (counter, startHour, startMinute, bestDuration))
    
    counter += 1
    try:
        num = input()
    except EOFError:
        break
