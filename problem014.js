// Using a map allows me to eliminate duplication of effort in determineChainLength
var colatzMap = Object.create(null); 

var longestChain = 0;
var longestChainNum;


/** 
 * The point of this problem is to find the number (under a million)
 * that produces the longest colatz chain.
 *
 * See https://projecteuler.net/problem=14 for details.
 */
(function main () {
	for (var i = 1; i < 1e6; i++) {
		colatzMap[i] = determineChainLength(i);
		if (longestChain < colatzMap[i]) {
			longestChain = colatzMap[i];
			longestChainNum = i;
		}
	}
	// console.log(longestChain);
	// console.log(longestChainNum);
})();

function determineChainLength (n) {
	var currentValue = n;
	var currentChainLength = 1;
	while (currentValue !== 1) {
		if (colatzMap[currentValue] !== undefined) {
			return currentChainLength + colatzMap[currentValue] - 1;
		} else if (currentValue % 2 === 0) {
			currentChainLength++;
			currentValue /= 2;
		} else {
			currentChainLength++;
			currentValue = 3 * currentValue + 1;
		}
	}
	return currentChainLength;
}