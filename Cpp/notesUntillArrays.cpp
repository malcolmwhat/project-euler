//This is a learning class. Most outputs are menial and only for learning purposes.
//While the contents are not super important and it doesn't do anything sofisticated, it is a development of style as well as substance
//THIS IS A PERFECT EXAMPLE OF OVER-commenting
//IMPORTANT NOTES can be found at the bottom underneath the main method.

#include <iostream>                         //I should find out what this means
using namespace std;                        //Unless otherwise specified, all library methods are from the std namespace
    
    namespace bar{                          //intitiallizes variables in the namespace bar: accessed using bar::a and bar::b
        int a = 5;                          
        int b = 6;
    }
    
    template <class T>                      //initializes a template class who's return variable is dependant on the fn call
    T sum (T a, T b){                       //Takes in any two variables of the same type and outputs their sum
        T result;                           
        result = a + b;                     //Adds the two variables of type T (detrmnd by fn call)
        return result;                      //returns a result of type T
    }
    
    void simplePrint(){                     //void method with no return type and no input vars
        /*      
        double a = 3.2, b = 4.5;            //initializes variables a, b, r, t.
        string r = "Hello", t = "World";    
        cout << sum(3, 2) << ent;           //Outputs the result of the method Sum with different input params. 
        cout << sum(a, b) << ent;
        cout << sum(r, t) << ent;
        bar::a = 2;                         //Accesses the variable a in the namespace bar above
        bar::b = 1;                         //""            ""      b       ""          ""
        cout << sum(bar::a, bar::b) << ent;
        */
    }
    
    void printAnArray(int arg[], int length){   //Print method which takes an array and the length of the array as inputs
        for(int n = 0; n < length; n++)         //The for loop is satisfied as long as the count is still within the bounds of the array
            cout << arg[n] << ' ';              //Outputs the value in the array at point counter, with a space after
        cout << '\n';                           //Adds a return carachter after the for loop is finished
    }
    
    void simpleArrays(){                                //simpleArrays is a void method with no input params
        //int foo[5] = {};                  
        // int foo[] = {0, 0 , 0 , 0 , 0};              //Same as the previous line
        int foo[] = {10, 20, 30, 40, 50};               //initialization of Array, its name is foo, its length is determined by the # of chars in the {}
        int jar[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};    //Same as the previous line, its name is jar
        printAnArray(foo, 5);                           //Passes the entire foo array to the function passingAnArray, along with the length
        printAnArray(jar, 10);                          //Passes the emtire jar array to the ""             ""
    }

    void castAndPrint(char word[]){         //method castAndPrint has no return type and a character array for an input parameter
        int counter = 0;                    //Sets a counter variable to 0
        while(word[counter] != '\0'){       //evaluates to true as long as the value at the current position in the array is not a null carachter aka the end of the array
            cout << word[counter];          //If it evaluates to true, then it does 2 things:
            counter++;                      //#1: print the value at the current pos in array, #2: increment the counter variable.
        }
        cout << '\n';                       //After the completion of the print loop, a return char is output for readability
        string wordCast = word;             //IMPORTANT: Casts the word char array onto a library string (wordCast) in a single statement
        cout << wordCast << '\n';           //Prints the library string WordCast and a rtrn char
    }
    
    void charachterSequences(){                             //Method charachterSequences has no return type and no input params
        char myWord[10] = "Hello";                          //initiallizes a char array of length ten, by simply casting in a String. This is perfectly fine and in fact the same as 
        //char myWord[10] = {'H', 'e', 'l', 'l', 'o'};      //This myWord char array is the same as the line above.
        castAndPrint(myWord);                               //Calls castAndPrint and passes it the myWord Char array
    }
    void pointerExample(){                                  //Method PointerExample has no return type and no input params
        int firstvalue, secondvalue;                        //Declares to intergers
        int * mypointer;                                    //Declares a pointer which must point to an int
        mypointer = &firstvalue;                            //The pointer has the reference of the firstvalue stored in it
        *mypointer = 10;                                    //Ten is stored into the section pointed to by mypointer, into the point at the address of firstvalue
        mypointer = &secondvalue;                           //Same as two lines prior
        *mypointer = 20;                                    //Twenty is stored into the section pointed to by mypointer, into the point at the address of secondvalue
        cout << "firstvalue is " << firstvalue << '\n';     //Simple Print statements
        cout << "secondvalue is " << secondvalue << '\n';
    }   

    int main(){                         //Main method, the program starts here
        simplePrint();                  //Calls simplePrint, passes no params
        simpleArrays();                 //Calls simpleArrays, passes no params
        charachterSequences();          //Calls carachterSequences, passes no params
        pointerExample();               //Calls pointerExample, passes no params
        return 0;                       //Explicit return of 0, this terminates the program. In C++ this can be excluded without consequence
    }

// IMPORTANT NOTES      IMPORTANT NOTES         IMPORTANT NOTES         IMPORTANT NOTES         IMPORTANT NOTES         IMPORTANT NOTES
/*

'\0' signifies null

Address of a variable can be obtained with the ampersand sign &, which can be litterally translated to "address of".

Dereference operator (*): baz = *foo; equivalent to "baz equal to the value pointed to by foo"

Pointer Properties
*p++   // same as *(p++): increment pointer, and dereference unincremented address
*++p   // same as *(++p): increment pointer, and dereference incremented address
++*p   // same as ++(*p): dereference pointer, and increment the value it points to
(*p)++ // dereference pointer, and post-increment the value it points to 

*/
