module.array 
var arr = ['hello', 'nice', 'me', 'to']

console.log(arr)
console.log(arr[0] + ', ' + arr[1] + ' ' + arr[2] + ' ' + arr[3])

for(i=0; i<arr.length;i++){
  for(j=0; j<arr[i].length;j++){
    console.log(arr[i][j])
  }
  if(i==0){
    console.log(',')
  }
  console.log(' ')
 }

for(var i in arr){
  console.log(arr[i])
}

