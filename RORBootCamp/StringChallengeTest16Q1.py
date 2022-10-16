steps = 0
   while num > 9:
     snum = str(num)
     sdigits = list(snum)
     num = 1
     for snum in sdigits:
        n = int(snum)
        num = num * n
     steps = steps + 1
   return steps