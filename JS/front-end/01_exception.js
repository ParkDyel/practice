// Code_01
// Basic tryCatchFin
function tCF(val) {
  try {
    switch (val) {
      case val > 0:
        throw 'TTTTTTTHROWWWWWWWWWWWW'
        break;
      case 0:
        Err()
        break;
      default:
        console.log(val)
        break;
    }
    console.log('Done every things')
  } catch (exception) {
    console.log(exception)
    console.log('what the fuck?')
  } finally {
    console.log('what care')
    return 'What ever'
  }
}

// result 
// tCF(1)
// 1
// Done every things
// what care
// "What ever"
// tCF(0)
// ReferenceError: Err is not defined
// at tCF (<anonymous>:5:9)
// at <anonymous>:1:1
// what the fuck?
// what care
// "What ever"