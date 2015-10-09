
def find_largest_product(data_matrix):
    return None

if __name__ == '__main__':
    # Load and parse file
    f = open('test_data_q_11.txt')
    
    raw_string = f.read()
    
    lines = raw_string.split('\n') 
    
    data_matrix = [lines[i].split(' ') for i in range(0, len(lines))] 
    
    find_largest_product(data_matrix)