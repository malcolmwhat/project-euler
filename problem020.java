public class problem020 {

    public static short[] multiply(short[] multiplicand, short[] multiplier){

        int n = multiplicand.length;
        int m = multiplier.length;

        short[][] intermediates = new short[m][];
        short carry = 0; // Avoid dealing with scope issues.


        for (int i = 0; i < m; i++) {
            carry = 0;

            intermediates[i] = initializeIntermediate(i + n + 1, i);
            for (int j = 0; j < n; j++) {
                int product = multiplicand[j] * multiplier[i]+ carry;
                short prod =(short)(product);
                intermediates[i][i + j] = (short)(prod % 10);
                carry = (short)(prod / 10);
            }
            intermediates[i][i + n] = carry;
        }
        // Adds each of the intermediate terms sequentially.
        carry = 0;
        short[] result = {};
        for (int k = 0; k < intermediates.length; k++) {
            result = add(result, intermediates[k]);
        }

        return trimZeros(result);
    }

    private static short[] initializeIntermediate(int size, int zeros){
        short[] intermediate = new short[size];
        for (int i = 0; i < zeros; i++) {
            intermediate[i] = 0;
        }
        return intermediate;
    }

    public static short[] add(short[] augend, short[] addend){
        int inputLength = Math.max(augend.length, addend.length);

        // Normalize the addend and augend to the same length.
        if (addend.length < inputLength) {
            addend = padArray(addend, inputLength);
        } else if (augend.length < inputLength) {
            augend = padArray(augend, inputLength);
        }

        int resultLength = inputLength + 1;

        // Allow changing and accessing carry in different scopes
        short carry = 0;

        short[] result = new short[resultLength];

        // Add the elements into the result array
        for (int i = 0; i < inputLength; i++) {
            int sum = augend[i] + addend[i] + carry;
            result[i] = (short) (sum % 10);
            carry = (short) (sum / 10);
        }

        result[inputLength] = carry;

        return trimZeros(result);
    }


    private static short[] trimZeros(short[] input){
        int i = input.length;
        // Starts at the left and looks for zeros, decrementing i for each one it finds
        while (input[i - 1] == 0 && i > 1){
            i--;
        }

        // Create an array of size i and copy the values of input into it.
        short[] trimmed = new short[i];
        for (int j = 0; j < trimmed.length; j++){
            trimmed[j] = input[j];
        }
        input = null; // Null out input so it gets garbage collected.
        return trimmed;
    }

    private static short[] padArray(short[] input, int size){
        short[] paddedArray = new short[size];

        for (int i = 0; i < input.length; i++) {
            paddedArray[i] = input[i];
        }

        int j = input.length;
        while (j < size) {
            paddedArray[j] = (short) 0;
            j++;
        }

        return paddedArray;
    }

    public static short[] numberToArray(short value) {
        int length = value / 10;

        short[] result = new short[length + 1];
        for (int i = 0; i < result.length; i++) {
            result[i] = (short) (value % 10);
            value = (short) (value / 10);
        }
        return result;
    }

    public static void printShortArray(short[] S) {
        for (int i = S.length - 1; i >= 0; i--) {
            System.out.print(S[i]);
        }
    }

    public static void calculateFactorialSum() {
        short[] factorial = {1};
        for (int i = 1; i <= 105; i++) {
            factorial = multiply(factorial, numberToArray((short)i));
        }

        short[] result = {0};
        for (int j = 0; j < factorial.length; j++) {
            short[] temp = new short[1];
            temp[0] = factorial[j];
            result = add(result, temp);
        }
        printShortArray(result);
    }

    public static void main(String[] args) {
        calculateFactorialSum();
    }

}
