const promise = require('promise')
  ,   readline = require('readline');

const stdRl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
  terminal: false
});

CHAR_USER = 'c';
CHAR_SQUIRREL = 'd';
CHAR_SPACE = '.';

GLOBAL_COUNTER_READLINE = 0;
GLOBAL_MAPSIZE = 0;
GLOBAL_MAPDATA = [];

stdRl.on('line', (input) => {

  // first line : setMapSize
  // second line ~ GLOBAL_MAPSIZE : appendMapDataRow
  // GLOBAL_MAPSIZE + 1 line : getMapData, countChar
  if (GLOBAL_COUNTER_READLINE == 0) {

    // setMapSize;
    GLOBAL_MAPSIZE = input;

    console.log(`Map Size is : ${GLOBAL_MAPSIZE}`);

  } else if (GLOBAL_COUNTER_READLINE != GLOBAL_MAPSIZE) {

    // appendMapDataRow
    GLOBAL_MAPDATA.push(input);

  } else if(GLOBAL_COUNTER_READLINE == GLOBAL_MAPSIZE){

    GLOBAL_MAPDATA.push(input);
   
    //getMapData
    for (var row = 0; row < GLOBAL_MAPDATA.length; row++) {
      console.log(`${GLOBAL_MAPDATA[row]}`);
    }

    countChar(GLOBAL_MAPDATA);

    stdRl.close();
  }

  GLOBAL_COUNTER_READLINE++;  
});


function countChar(GLOBAL_MAPDATA){

}

function main() {
  console.log(`Plz Input Map Size(Map size = inputValue*inputValue)`);
}

main();