z = [['a', 'b', 'c'], ['d','e','f'], ['c','x']]
s = [" ".join(j) for j in z]
s1 = "".join(["".join(j) for j in z[::-1]])
print(s)
print(s1)