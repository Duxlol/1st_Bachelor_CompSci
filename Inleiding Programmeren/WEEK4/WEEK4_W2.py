def midden(A,B):
    coordinates = []
    for i in range(len(A)):
        result = (A[i] + B[i])/2
        coordinates.append(result)

    return tuple(coordinates)

print(midden([1,2,3],[3,4,5]))