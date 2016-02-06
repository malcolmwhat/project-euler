# Need to calculate the maximum path sum for testdata018
def calculate():
    data = open('testdata018.txt', 'r').read()
    lines = data.split('\n')
    matrix = [lines[i].split(' ') for i in range(len(lines))]

    # The matrix is a pyramid of values, we roll up the pyramid
    # by adding the max child of a given node to that node's value
    for j in range(len(matrix) - 2, -1, -1):
        for k in range(len(matrix[j])):
            currentNode = int(matrix[j][k])
            child1 = int(matrix[j + 1][k])
            child2 = int(matrix[j + 1][k + 1])

            matrix[j][k] = currentNode + max(child1, child2)

    print(matrix[0][0]) # The top of the pyramid is the rolled up value

if __name__ == '__main__':
    calculate();
