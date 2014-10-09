//Notes From Arrays Untill------
/**
 * Learning Class
 * Scope: is from arrays untill dynamic memory
 * Purpose: Overcommented bunch of notes and test cases that are my first attempt at whatever it happens to be that I'm learning
 */

#include <iostream>
using namespace std;
void dynamicMemSnglEntr(){
	int * ptr1Elmt;						//Initializes a pointer called ptr1Elmt
	ptr1Elmt = new int;					//ptr1Elmt is a pointer to a piece of dynanic memory which can store a single int
	*ptr1Elmt = 5;						//Assigns 5 to the slot pointed to by ptr1Elmt
	std::cout << *ptr1Elmt << '\n';		//Prints 5 and a return character
	delete ptr1Elmt;					//Frees up the dynamic memory space occupied by ptr1Elmnt
}

/**
 * @brief Demonstrates the proper use of dynamic memory
 * @details Initializes a pointer, points to a large segment of dynamic mem, uses that mem, deletes it. Details on-line
 * @LINE BY LINE
 * 		initializes two integers
 * 		Initializes a pointer called ptrExmpl
 * 		Asks the user how many #'s are to be used as input
 * 		user interaction
 * 		Assigns the initial pointer of the first piece of a user defined length block of memory to ptrExmpol
 * 		if statement makes sure that there was no issue for the allocation of mem
 * 			Notification
 * 		if not satisfied
 * 			loop for all i elements
 * 			prompts user for input value
 * 			gets a value input from the user
 * 			
 * 		Prints to prompt a flag for the input
 * 			loop for all i elements except the last one
 * 			outputs the elements neatly
 * 			
 * 		outputs the last element
 * 		deletes the dynamic memory allocated to ptrExmpl
 */
void dynamicMem10Entry(){
	int i, n;
	int * ptrExmpl;
	cout << "How many numbers do you want to type? " << '\n';
	cin >> i;						
	ptrExmpl = new (nothrow) int[i];
	if (ptrExmpl == nullptr)
		cout << "Error: memory could not be allocated";	
	else{
		for(n = 0; n < i; n++){
			cout << "Enter a number: ";
			cin >> ptrExmpl[n];
		}
		cout << "You input the following: {";
		for(n = 0; n < (i -1); n++){
			cout << ptrExmpl[n] << ", ";
		}
		cout << ptrExmpl[i-1] << "}" << '\n';
		cout << "Here it is reversed: {";
		for(n = i-1; n > 0; n--){
			cout << ptrExmpl[n] << ", ";
		}
		cout << ptrExmpl[0] << "}" << '\n';
		delete[] ptrExmpl;
	}
}


/**
 * @brief Main Method			
 * @details Calls my other methods mostly		
 * @return Ends program by returning 0X000000
 */
 int main(){
 	dynamicMemSnglEntr();
 	dynamicMem10Entry();
 	return 0;
 }