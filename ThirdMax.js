function ArrayChallenge(strArr) { 

var matrix=[];

//build the array, two dimensions  
for (var i=0; i<strArr.length;i++){
	matrix.push([strArr[i].length,strArr[i]]);
}
//sort
matrix = matrix.sort()
matrix = matrix.slice(1, matrix.length-1)
return matrix[0][1]
}
   
// keep this function call here 
console.log(ArrayChallenge(readline()));