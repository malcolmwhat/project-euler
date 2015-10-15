from collections import deque

def get_local_product(seq, cons, product = 1):
    if len(seq) < cons:
        return product

    old_prod = product
    product = 1

    # Initialize queue
    queue = deque()
    for i in range(cons):
        next_val = int(seq[i])
        if next_val == 0:
            # If we hit a zero, then we re-call this function with whatever is left of the sequence
            return get_local_product(seq[i+1:], cons, product if product > old_prod else old_prod)
        queue.append(next_val)
        product *= next_val

    # Loop through the rest, pop and append and check for zero in the same manner
    for j in range(cons,len(seq)):
        next_val = int(seq[j])
        if next_val == 0:
            return get_local_product(seq[-j+1:], cons, product if product > old_prod else old_prod)
        divisor = queue.popleft()
        product /= divisor
        queue.append(next_val)
        product *= next_val

    return product if product > old_prod else old_prod



def get_largest_product(sequences, cons):
    largest_product = 0
    count = 0
    for seq in sequences:
        print seq
        product = get_local_product(seq, cons) 
        print product
        largest_product = product if product > largest_product else largest_product
    
    return largest_product


def create_table(data):
    # Parse the data into a two dimensional array
    return [row.split(' ') for row in data.split('\n')]

def get_diagonal(table, index):
    diagonal = []
    for i in range(index + 1):
        diagonal.append(table[i][index - i])
    return diagonal

def create_sequences(table):
    sequence_set = []

    for i in range(len(table)):
        # Add Rows
        sequence_set.append(table[i])
        # Add Diagonals
        sequence_set.append(get_diagonal(table, i))

    # Transpose the matrix (no need to use numpy here as it is a fairly small matrix)
    table_tp = map(list, zip(*table))

    # Do the same evaluation as before on the transposed matrix
    for j in range(len(table_tp)):
        sequence_set.append(table_tp[j])
        sequence_set.append(get_diagonal(table_tp, j))

    return sequence_set



if __name__ == '__main__':
    # Load and parse file
    # Should I parse all 'lines' into sequences? This would simplify the actual methodology
    # Instead of having 4 different evaluation methods, I have one, I just need some 
    # Extra logic to formulate a set of evaluatable sequences

    #PARSE
    # Take the Raw String
    # Parse it into a two dimensional Array
    # The rows are added to the set to be evaluated
    # The columns are formatted into sequences and added to the set
    # The diagonals are formatted into sequences and added to the set

    #PROCESS
    # Loop through the sequences
    # Run a similar loop to the one you ran in your other solution
    # Keep track of the largest variable along the way

    f = open('test_data_q_11.txt')
    
    raw_string = f.read()
    f.close()
    table = create_table(raw_string)
    
    seq_set = create_sequences(table)

    print get_largest_product(seq_set, int(input('Number of consecutive numbers to consider: ')))