m1 = [[1,0,0],[0,1,0],[0,0,1]]
m2 = [[1,0,2],[0,1,2],[0,0,2]]
def multiply_matrices(matrix1,matrix2):
    if len(matrix1[0]) == len(matrix2):
        resultMatrix = []
        for i in range(len(matrix1)):
            row = []
            for j in range(len(matrix2[0])):
                sum = 0
                for k in range(len(matrix2)):
                    sum += matrix1[i][k] * matrix2[k][j]
                row.append(sum)
            resultMatrix.append(row)
        return resultMatrix
    return None



print(multiply_matrices([[1,2,3], [4,5,6],[7,8,9]], [[1,2,3], [4,5,6],[7,8,9]]))
print(multiply_matrices([[1,3], [4,6],[7,9]], [[1,2], [4,5],[7,8]]))
print(multiply_matrices([[1,2], [4,5],[7,8]], [[1,2,3], [4,5,6]]))
print(multiply_matrices([[1,2], [4,5]],[[1,2], [4,5]]))