def selection_sort(array):  
    length = len(array)  
      
    for i in range(length-1):  
        minIndex = i  
          
        for j in range(i+1, length):  
            if array[j]<array[minIndex]:  
                minIndex = j  
                  
        array[i], array[minIndex] = array[minIndex], array[i]  
          
          
    return array      
array = [2,6,4,8,5,8,6]  
  
print("The sorted array is: ", selection_sort(array))  
