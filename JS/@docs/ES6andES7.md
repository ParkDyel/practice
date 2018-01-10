1. [Asynchronous and synchronous](https://derickbailey.com/2017/06/06/3-features-of-es7-and-beyond-that-you-should-be-using-now/)

   _ES6_ __promises__ 
    ```
    async function   createEmployee(){
      return new Promise((resolve, reject) => {
    
        // do stuff here to create the employee
        var employee = // ...
    
       // now check if it worked or not
        if (/* some success case */) {
          resolve(employee);   
        } else {
          reject(someError);
        }
      });
    }
    ```
  _ES7_ __async__
    ```
    async function createEmployeeWorkflow(cb){
      var err;

      try {
        var employee = await createEmployee();
    
        if (employee.needsManager()){
          var manager = await selectManager(employee);
          employee.manager = manager;
        }
    
        await saveEmployee(employee);
      } catch (ex) {
        err = ex;
      }
      cb(err, employee);
    }
    ```
2. [Object Rest / Spread Properties](https://derickbailey.com/2017/06/06/3-features-of-es7-and-beyond-that-you-should-be-using-now/)

    _ES6_

    _ES7_ 

3. [Arrow functions](https://msdn.microsoft.com/ko-kr/library/ff841995(v=vs.94).aspx)

    _ES5_ __bind__
    ```
    // Define the original function.
    var checkNumericRange = function (value) {
    if (typeof value !== 'number')
      return false;
    else
      return value >= this.minimum && value <= this.maximum;
    }

    // The range object will become the this value in the callback function.
    var range = { minimum: 10, maximum: 20 };

    // Bind the checkNumericRange function.
    var boundCheckNumericRange = checkNumericRange.bind(range);

    // Use the new function to check whether 12 is in the numeric range.
    var result = boundCheckNumericRange (12);
    document.write(result);
    ```
