# Comments
# The radix sort is a non-comparative integer sorting algorithm that sorts data with integer keys by grouping keys by the individual digits which share the same significant position and value.

def radixsort(a):
    max = 0
    for i in range(len(a)):
        if a[i] > max:
            max = a[i]
    max = len(str(max))
    for i in range(max):
        buckets = [[] for j in range(10)]
        for j in a:
            buckets[int(j/(10**i))%10].append(j)
        a = []
        for j in buckets:
            a += j
    return a

if __name__ == '__main__':
    a = [5, 4, 3, 2, 1]
    print(radixsort(a))
