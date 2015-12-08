f = open('testdata013.txt')

nums = f.read().split('\n')

f.close()

totalsum = ''
carryover = 0
counter = 1
for i in range(49, -1, -1):
    localsum = carryover
    for j in range(100):
        localsum += int(nums[j][i])
    stringsum = str(localsum)
    totalsum = stringsum[len(stringsum) - 1] + totalsum 
    carryover = int(stringsum[0:len(stringsum) - 1])

totalsum = str(carryover) + totalsum

print(totalsum[0:10])
