// Power Digit Sum
(function main () {
	var context = process.argv[2];
	if (context == 'run') {
		unitTest();
	} else if (context == 'test') {
		run();
	}
})();

// Manually add strings
function stringMultByTwo (x) {
	var result = '';
	var carry = 0;
	x = String(x);
	for (var i = x.length - 1; i >=0; i--) {
		var temp = String(parseFloat(x[i]) * 2 + carry);
		if (temp.length === 1) {
			carry = 0;
			result = temp + result;
		} else {
			carry = 1;
			result = temp[1] + result;
		}
	}
	if (carry == 1) {
		result = carry + result;
	}
	return result;
}

function twoToThePowerOf (n) {
	var result = 1;
	for (var i = 1; i <= n; i++) {
		result = stringMultByTwo(result);
	}
	return result;
}

function sumDigits (str) {
	var result = 0;
	for (var i = 0; i < str.length; i++) {
		result += parseFloat(str[i]);
	}
	return result;
}


function unitTest () {
	console.log('2 x 2 = ' + stringMultByTwo('2'));
	console.log('128 x 2 = ' + stringMultByTwo('128'));
	console.log('2 ^ 4 = ' + twoToThePowerOf('4'));
	console.log('2 ^ 15 = ' + twoToThePowerOf('15'));
	console.log('Sum of digits for 2 ^ 15 = ' + sumDigits(twoToThePowerOf('15')));
	console.log('2 ^ 1000 = ' + sumDigits(twoToThePowerOf('1000')));
}

function run () {
	console.log('Sum of digits for 2 ^ 15 is ' + sumDigits(twoToThePowerOf('1000')));
}
