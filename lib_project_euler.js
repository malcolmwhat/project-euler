/**
 * This function allows us to check if the input number is prime.
 *
 * @param {Integer} input : any integer numeric or string
 * @return {Boolean} true if prime, false if not
 */
function isPrime(input){
    // Convert to int, allows strict equality checks
    var n = parseInt(input, 10);

    // Check for true integer
    if (n % 1 !== 0 || isNaN(n)){
        throw new Error('Do not enter non-integer values.');
    }

    if (n < 2) {
        return false;
    }

    if (n === 2) {
        return true;
    }

    // Check if even so we don't waste time checking every even number
    if (n % 2 === 0) {
        return false;
    }

    // Loop untill the square root rounded up
    var itterationUpperLim = Math.ceil(Math.sqrt(n));
    for (var i = 3; i <= itterationUpperLim; i += 2) {
        if (n % i === 0) {
            return false;
        }
    }

    // If we made it all the way here then we have a prime number
    return true;
}

/** Gets the greatestCommonDenominator of a and b*/
function greatestCommonDenominator (a, b) {
    if (b == 0) {
        return a;
    } else {
        return greatestCommonDenominator(b, a % b);
    }
}

