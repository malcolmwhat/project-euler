/**
 * Determines the largest product in the grid found in test_data_q_11.txt
 */
var fs = require('fs');

fs.readFile('test_data_q_11.txt', 'utf8', function(error, data) {

  if (error) {
    return console.log(error);
  }

  var table = [];

  // Regex catches different newline representations while building table
  data.split(/\r\n|\r|\n/).forEach(function(element, index){
    table.push(element.split(' ')); 
  });

  var i, j, k;
  var largestProduct = 0, currentProduct;
  
  // Look for largest product in the rows of the table
  for (i = 0; i < 20; i++){
    for (j = 0; j < 16; j++){
      currentProduct = 1;
      for (k = 0; k < 4; k++){
        currentProduct *= table[i][j + k];
      }
      largestProduct = Math.max(largestProduct, currentProduct);
    }
  }

  // Look for the largest product in the columns of the table
  for (i = 0; i < 20; i++){
    for (j = 0; j < 16; j++){
      currentProduct = 1;
      for (k = 0; k < 4; k++) {
        currentProduct *= table[j + k][i];
      }
      largestProduct = Math.max(largestProduct, currentProduct);
    }
  }

  // Diagonal in the (1,1) direction 
  for (i = 3; i < 20; i++){
    for (j = 0; j < 16; j++){
      currentProduct = 1;
      for (k = 0; k < 4; k++){
        currentProduct *= table[i - k][j + k];
      }
      largestProduct = Math.max(largestProduct, currentProduct);
    }
  }

  // Diagonal in the (1,-1) direction
  for (i = 0; i < 16; i++){
    for (j = 0; j < 16; j++){
      currentProduct = 1;
      for (k = 0; k < 4; k++){
        currentProduct *= table[i + k][j + k];
      }
      largestProduct = Math.max(largestProduct, currentProduct);
    }
  }

  console.log(largestProduct);
});