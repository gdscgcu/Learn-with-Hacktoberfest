
 var subset = [], min = 0;
  function findMin (arr) { return arr.sort(function (a,b) {return Number(a)-Number(b);})[0]; }
  for (var i=0;i<strArr.length;i++) {
    if (strArr[i] == "E") { 
      min = findMin(strArr.slice(0,i));
      minIndex = strArr.slice(0,i).indexOf(min)
      subset.push(Number(min));
      strArr = strArr.slice(0,minIndex).concat(strArr.slice(minIndex+1,i)).concat(strArr.slice(i+1));
      i-=2;
    }
  }
  return subset.join(",");         
         