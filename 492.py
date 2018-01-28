# Steven Kester Yuwono - UVa 492

def isvowel(ch):
    vowel = ["a","e","i","o","u"]
    if ch.lower() in vowel:
        return True
    return False

while (True):
    try:   
        sentence = input()
    except Exception as e:
        break

    result = ""
    beginIndex = 0
    isCurrAlpha = False
    if (sentence[0].isalpha()): isCurrAlpha = True
    for i in range(1,len(sentence)+1):
        if (i == len(sentence) or not sentence[i].isalpha()) and isCurrAlpha:
            if (isvowel(sentence[beginIndex])):
                result = result + sentence[beginIndex:i] + "ay"
            else:
                result = result + sentence[beginIndex+1:i] + sentence[beginIndex] + "ay"
            beginIndex = i
            isCurrAlpha = False
        elif (i == len(sentence) or sentence[i].isalpha()) and not isCurrAlpha:
            result = result + sentence[beginIndex:i]
            beginIndex = i
            isCurrAlpha = True

    print (result)

