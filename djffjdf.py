from ast import List


def merge(a, b):
    merged = list()
    i = 0 
    j = 0
    k = 0
    while(i < len(a) and j < len(b)):
        if(a[i] > b[j]):
            merged.append(a[i])
            i += 1
        else:
            merged.append(b[j])
            j += 1

    while(i < len(a)):
        merged.append(a[i])
        k += 1
        i += 1

    while(j < len(b)):
        merged.append(b[j])
        k += 1
        j += 1
    return merged 

a = list(map(int, input().split(',')))
b = list(map(int, input().split(',')))
num = int(input())

merged = merge(a, b)
print(','.join(map(str, merged)))
