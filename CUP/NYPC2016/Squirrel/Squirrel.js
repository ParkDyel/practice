const promise = require('promise')
    , readline = require('readline');

const stdRl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});


CHAR_USER = new String('c');
CHAR_SQUIRREL = new String('d');
CHAR_SPACE = new String('.');

GLOBAL_COUNTER_READLINE = new Number(-1);
GLOBAL_MAPSIZE = new Number(0);
GLOBAL_MAPDATA = [];

stdRl.on('line', (input) => {
  if (GLOBAL_COUNTER_READLINE == -1){
    GLOBAL_MAPSIZE = input;
    console.log(`Map Size is : ${GLOBAL_MAPSIZE}`);
    GLOBAL_COUNTER_READLINE++;
  } else if(GLOBAL_COUNTER_READLINE == GLOBAL_MAPSIZE) {
    countChar(GLOBAL_MAPDATA);
  } else {
    if(GLOBAL_COUNTER_READLINE == GLOBAL_MAPSIZE+1){
      console.log(GLOBAL_MAPDATA);
    } else {
      GLOBAL_MAPDATA.push(input);
      console.log(`ReadLine ${GLOBAL_COUNTER_READLINE}: ${GLOBAL_MAPDATA[GLOBAL_COUNTER_READLINE]}`);
      GLOBAL_COUNTER_READLINE++;
    }
  }
});

function countChar(){
  
}