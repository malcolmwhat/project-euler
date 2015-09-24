# -*- coding: utf-8 -*-

import math

class SpecialTriplet:
    def increment_values(self):
        self.a = self.b
        self.b += 1
        
    def check_triplet(self):
        while(True):
            self.c = math.sqrt(math.pow(self.a,2)+math.pow(self.b,2))
            result = self.a + self.b + self.c
            if result > 1000 and self.a > 1:
                self.a -= 1
            elif result == 1000:
                return None
            else:
                self.increment_values()
                return self.check_triplet()
    
    
    def __init__(self):
        self.a = 1
        self.b = 2
        self.c = 5

if __name__ == '__main__':
    triplet = SpecialTriplet()
    triplet.check_triplet()
    print("%s + %s + %s = 1000"%(triplet.a, triplet.b, triplet.c))
