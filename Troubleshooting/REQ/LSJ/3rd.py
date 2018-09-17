#Q1
def get_odd_each_coe(nums):
    for idx, Coefficient in enumerate(str(nums)):
        if (int(Coefficient) % 2) == 1:
            return idx
    return -1

def user_function(start, stop):
    cursor = start

    ret = ''
    while cursor <= stop:
        print('[DEBUG] {cur}'.format(cur=cursor))
        res = get_odd_each_coe(cursor)   
        if res == -1:
            ret += str(cursor)
            ret += ', '
            cursor += 2
        else:
            cursor += pow(10, (len(str(cursor)) - res - 1))
    return ret

print(user_function(100,500))