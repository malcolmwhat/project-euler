# -*- coding: utf-8 -*-

from collections import deque

class IntSet:
    """
    This class contains a sequence of stringified integers and methods to 
    allow the user to calculate the largest product in a series of n integers
    """
    def check_product(self):
        self.lgst_product = max(self.lgst_product, self.crnt_product)
        return None

    def calculate_product(self):
        if self.crnt_idx > self.size - self.consec:
            return None
        for i in range(0, self.consec):
            next_val = int(self.int_set[self.crnt_idx])
            # if it's not zero, we add the value to the queue, and multiply
            if next_val != 0:
                self.queue.append(next_val)
                self.crnt_product *= next_val
                self.crnt_idx += 1
            # if zero we need to reset the product and re-call
            else:
                self.queue.clear()
                self.crnt_product = 1
                self.crnt_idx += 1
                return self.calculate_product() # Recursive call
        self.check_product()
        return self.update_product()


    def update_product(self):
        if self.crnt_idx == self.size:
            return None
        next_val = int(self.int_set[self.crnt_idx])
        # if not zero, let's pop, and divide, append and multiply
        if next_val != 0:
            self.crnt_product = self.crnt_product / self.queue.popleft()
            self.queue.append(next_val)
            self.crnt_product *= next_val
            self.crnt_idx += 1
            self.check_product()
            return self.update_product()
        else: 
            self.queue.clear()
            self.crnt_product = 1
            self.crnt_idx += 1
            return self.calculate_product()


    def calculate_largest_product(self):
        self.calculate_product()
        return None

    def __init__(self, integer_set):
        self.int_set = integer_set.replace('\n', '')
        self.size = len(self.int_set)
        self.crnt_idx = 0
        self.lgst_product = 0
        self.crnt_product = 1
        # The number of consecutive numbers to consider in product
        self.consec = int(input('Enter the number of consecutive ' +
            'numbers we want to consider: '))
        self.queue = deque()

if __name__ == "__main__":
    test_file = open("testdata008.txt")
    test_data = test_file.read()
    test_file.close()

    #Initialize the intset and call method to set the largest product
    int_set = IntSet(test_data)
    int_set.calculate_largest_product()
    print("The largest product of %s consecutive numbers is %s"%(
        int_set.consec,int_set.lgst_product))
