m1 = [[1,0,0],[0,1,0],[0,0,1]]
m2 = [[1,0,2],[0,1,2],[0,0,2]]
def add_matrices(matrix1,matrix2):
    if len(matrix1) == len(matrix2) and len(matrix1[0]) == len(matrix2[0]):
        resultMatrix = []
        for i in range(len(matrix1)):
            row = []
            for j in range(len(matrix1[i])):
                optellen = matrix1[i][j] + matrix2[i][j]
                row.append(optellen)
            resultMatrix.append(row)
        return resultMatrix
    return None
print(add_matrices(m1,m2))