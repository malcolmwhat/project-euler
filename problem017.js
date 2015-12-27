/** Number letter counter*/
function NumberReader () {
    this.precisions = {
        0 : '',
        3 : 'thousand',
        6 : 'million',
        9 : 'billion'
    };

    this.singleDigits = {
        1 : 'one',
        2 : 'two',
        3 : 'three',
        4 : 'four',
        5 : 'five',
        6 : 'six',
        7 : 'seven',
        8 : 'eight',
        9 : 'nine'
    };

    this.teens = {
        10 : 'ten',
        11 : 'eleven',
        12 : 'twelve',
        13 : 'thirteen',
        14 : 'fourteen',
        15 : 'fifteen',
        16 : 'sixteen',
        17 : 'seventeen',
        18 : 'eighteen',
        19 : 'nineteen'
    };

    this.doubleDigits = {
        2 : 'twenty',
        3 : 'thirty',
        4 : 'forty',
        5 : 'fifty',
        6 : 'sixty',
        7 : 'seventy',
        8 : 'eighty',
        9 : 'ninety'
    };
}

/** Resolves any number to words by evaluating it chunk by chunk */
NumberReader.prototype.resolveNumber = function (num) {
    var numericRepresentation = String(num);
    this.validateInput(num);
    var verbalRepresentation = '';

    var temp = null,
        subResult = null,
        checkForAnd = false;

    for (var i = 0; i < numericRepresentation.length; i+=3) {
        subResult = null;
        // If second arg of slice call is -0, we send undefined because '123'.slice(-2,0) returns '' as oposed to '23'
        temp = numericRepresentation.slice(-i-3, -i || undefined);
        if (!this.checkForZeroes(temp)) {
            // Resolve the current sub number
            subResult = this.resolveChunk(temp);
            if (checkForAnd === true) {
                verbalRepresentation = ' and' + verbalRepresentation; // Add 'and' based on the previous subResult
            }
            checkForAnd = subResult.checkForAnd; // Set checkForAnd based on the most recent subResult
            verbalRepresentation = subResult.words + this.precisions[i] + verbalRepresentation;
        }
    }

    return verbalRepresentation || '';

};

/** Resolves a number to words, if the number is between 0 and 999*/
NumberReader.prototype.resolveChunk = function (num) {
    var result = {
        words : '',
        checkForAnd : false
    };

    var checkForAnd = false;
    if (num.length == 3) {
        if (this.singleDigits.hasOwnProperty(num[0])) {
            result.words += this.singleDigits[num[0]] + ' hundred';
            checkForAnd = true;
        } else {
            result.checkForAnd = true;
        }
        if (this.teens.hasOwnProperty(num.slice(1,3))) {
            if (checkForAnd) {result.words += 'and';}
            result.words += this.teens[num.slice(1,3)];
        } else {
            if (this.doubleDigits.hasOwnProperty(num[1])) {
                if (checkForAnd) {result.words += 'and'; checkForAnd = false;}
                result.words += this.doubleDigits[num[1]];
            }
            if (this.singleDigits.hasOwnProperty(num[2])) {
                if (checkForAnd) {result.words += 'and'; checkForAnd = false;}
                result.words += this.singleDigits[num[2]];
            }
        }
    } else if (num.length == 2) {
        result.checkForAnd = true;
        if (this.teens.hasOwnProperty(num)) {
            result.words += this.teens[num];
        } else {
            if (this.doubleDigits.hasOwnProperty(num[0])) {
                result.words += this.doubleDigits[num[0]];
            }
            if (this.singleDigits.hasOwnProperty(num[1])) {
                result.words += this.singleDigits[num[1]];
            }
        }
    } else if (num.length == 1) {
        result.checkForAnd = true;
        result.words += this.singleDigits[num]
    }

    return result;
}

NumberReader.prototype.checkForZeroes = function (num) {
    for (var i = 0; i < num.length; i++) {
        if (num[i] != 0) {
            return false;
        }
    }
    return true;
};

NumberReader.prototype.validateInput = function (num) {
    if (typeof num !== 'number' && typeof num !== 'string') {
        throw new TypeError('Requires a string or number input.');
    }

    if (typeof num === 'string' && isNaN(parseFloat(num))) {
        throw new Error('The string you enter needs to be numericRepresentation.');
    }
}


/** This is the main object for this script. */
var LetterCounter = {
    properties : {
        lowerLimit : 1,
        upperLimit : 1000
    },
    methods : {
        main : function () {
            LetterCounter.methods.initializeArguments();
            var numberReader = new NumberReader();
            if (process.argv[2] == 'test') {
                LetterCounter.methods.test(numberReader);
            } else {
                LetterCounter.methods.run(numberReader);
            }
        },
        run : function (numberReader) {
            var count = 0;
            var lowerLimit = LetterCounter.properties.lowerLimit;
            var upperLimit = LetterCounter.properties.upperLimit;
            var temp;
            for (var i = lowerLimit; i <= upperLimit; i++) {
                temp = numberReader.resolveNumber(i) || '';
                count += temp.replace(/\s/g, '').length;
            }
            console.log(count);
        },
        initializeArguments : function () {
            // Extra parameters can be used to specify upper and lower limits to execution
            process.argv.slice(2).forEach(function (element, index, array) {
                if (index == 0) {
                    upperLimit = element;
                } else if (index == 1) {
                    lowerLimit = element;
                }
            });
        },
        test : function (numberReader) {
            valueTest = LetterCounter.methods.valueUnitTest;
            stageTest = LetterCounter.methods.stageTest;
            valueTest(numberReader, 134, 'one hundred and thirty four');
            valueTest(numberReader, 21, 'twenty one');
            valueTest(numberReader, 111, 'one hundred and eleven');
            valueTest(numberReader, 101, 'one hundred and one');
            valueTest(numberReader, 190, 'one hundred and ninety');
            valueTest(numberReader, 191, 'one hundred and ninety one');
            valueTest(numberReader, 206, 'two hundred and six');
            valueTest(numberReader, 1002, 'one thousand and two');
            valueTest(numberReader, 15726, 'fifteen thousand seven hundred and twenty six');
            valueTest(numberReader, 276521, 'two hundred and seventy six thousand five hundred and twenty one');
            valueTest(numberReader, 1000001, 'one million and one');
            stageTest(numberReader, 1, 5, 19);
        },
        valueUnitTest : function (numberReader, num, str) {
            var temp = numberReader.resolveNumber(num);
            if (temp.replace(/\s/g, '') == str.replace(/\s/g, '')) {
                console.log('PASS: Value test for ' + num);
            } else {
                console.log('FAIL: Value test for ' + num + ' yielded ' + temp + ' instead of ' + str);
            }
        },
        stageTest : function (numberReader, lowerLimit, upperLimit, expected) {
            var count = 0;
            var temp;
            for (var i = lowerLimit; i <= upperLimit; i++) {
                temp = numberReader.resolveNumber(i) || '';
                count += temp.replace(/\s/g, '').length;
            }
            if (count == expected) {
                console.log('PASS: Stage test for [' + lowerLimit + ', ' + upperLimit + ']');
            } else {
                console.log('FAIL: Stage test for [' + lowerLimit + ', ' + upperLimit + ']' + '. Yielded ' + count + ' instead of ' + expected);
            }
        }
    }
};

// If you call this module directly via Node
if (require.main === module) {
    LetterCounter.methods.main();
}
