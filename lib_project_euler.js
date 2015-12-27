/**
 * This function allows us to check if the input number is prime.
 *
 * @param {Integer} input : any integer numeric or string
 * @return {Boolean} true if prime, false if not
 */
function isPrime(input){
    // We convert to int so that we can use strict equalities -> Efficiency
    var n = parseInt(input, 10);

    // Check with soft equals to see if we have the same value ('2' -> 2 would give true here, whereas '2.3' -> 2 would not)
    if (n != input || isNaN(n)){
        throw new Error('Why are you entering non-integers... Stop being a dink');
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

