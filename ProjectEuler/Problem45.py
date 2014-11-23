"""The starting indices"""
triangular_index = 286
pentagonal_index = 166
hexagonal_index = 144
result_found = False
while not result_found:
    print compt_tri_num(triangular_index)
    print compt_pent_num(pentagonal_index)
    print compt_hex_num(hexagonal_index)
    result_found = True


compt_tri_num(index):
    return index * (1 + index) / 2


compt_pent_num(index):
    return index * (3 * index - 1) / 2


compt_hex_num(index):
    return index * (2 * index - 1)
