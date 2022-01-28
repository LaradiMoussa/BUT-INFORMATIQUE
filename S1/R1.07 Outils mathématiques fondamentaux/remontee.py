t = [[1,3,2], [0,-1,-1],[0,0,3]]
v = [64, -24, 31]

def remontee(t,v):
    n = len(t)
    copy = v [:]
    x = [None for i in range (n)]
    for i in range(n-1, -1, -1):
        x[i] = round(copy[i]/t[i][i],2)
        for j in range(i-1, -1, -1):
            copy[j] = copy[j]-x[i]*t[j][i]
    return x

print (remontee(t,v))


# AVEC PYHTHON 2
# x = [2 , 14 , 10 ]

# AVEC PYHTHON 3
# x = [2.33 , 13.67 , 10.33 ]