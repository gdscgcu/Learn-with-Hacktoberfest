import itertools
def PrimeChecker(num): 
  temp = str(num)
  for num in itertools.permutations(temp, len(temp)):
    if is_Prime(int("".join(num))):
      return 1
  return 0  