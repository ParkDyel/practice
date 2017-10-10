"""
넥슨아 다람쥐 뿌려줘
Park Dyel
2017.10.11
"""

# Pylint C0111 : docString : comments
# Pylint C0103 : function name must be lowerCase
# Pylint W0105 : using those strings as documentation, instead of comments.

import random

def set_array_size():
    """set Array Size between 5~20"""
    map_size = 0
    while int(map_size) < 5 or int(map_size) > 20:
        map_size = input("Plz Input Value(mapSize=inputValue^2, and must be between 5 to 20: ")
    return map_size
def set_map_data(map_size):
    """set map Data"""
    map_data = []
    for row in range(0, map_size):
        # Handling when input exceeds the bounds of the map
        map_data.append(list(input("read Map Data : " + str(row) + "\n"))[0:map_size])
    return map_data

def get_num_of_char(array, the_char):
    """count the character in array"""
    counter = 0
    for string in array:
        for char in string:
            if char == the_char:
                counter += 1
    return counter


def cal_num_of_summons_req(size, num_of_user, num_of_squirrel):
    """Calculate the number of squirrel summons need, and summon squirrel."""
    num_of_summon_need = 0

    if num_of_user * 3 > size*size:
        #The number of summoned individuals exceeds the area width.
        num_of_summon_need = (size*size) - num_of_user - num_of_squirrel
        print("Cannot Summon enought " + str(-(num_of_summon_need-(num_of_user*2))))

    elif num_of_user * 2 > num_of_squirrel:
        #It needs to be summoned, and it will be done normally.
        num_of_summon_need = (num_of_user*2) - num_of_squirrel

    else:
        #There are enough squirrels already.
        num_of_summon_need = 0

    print("number of summon need : " + str(num_of_summon_need))
    return num_of_summon_need

def check_space(space, dotge_char):
    """There seems to be an overlap with the func `get_num_of_char()`."""
    if space == dotge_char:
        return True
    else:
        return False

def summon_squirrel(size, map_data, num_of_summon_need):
    """Summons squirrels as many times as needed"""
    """
    position = randrange(0, size*size)

    row = position % size;
    col = position / size;
    """
    num_of_summons = 0

    while num_of_summons != num_of_summon_need:
        row = random.randrange(0, size)
        col = random.randrange(0, size)

        if check_space(map_data[row][col], '.'):
            map_data[row][col] = 'd'
            num_of_summons += 1

    return map_data


# def checkTheChar(char theChar):
#   # check something in point(x,y)
# def freeTwoDimensionalArray(address, size):

def main():
    """UPPER CASE STRING MEAN DEFINE!!"""
    user_char = 'c'
    squirrel_char = 'd'
    dotge_char = '.'

    map_size = 0
    map_size = int(set_array_size())
    map_data = set_map_data(map_size)

    user_counter = get_num_of_char(map_data, user_char)
    squirrel_counter = get_num_of_char(map_data, squirrel_char)

    print("USER : " + str(user_counter) + " Squirrel : " + str(squirrel_counter))

    num_of_summons_req = cal_num_of_summons_req(map_size, user_counter, squirrel_counter)

    summon_squirrel(map_size, map_data, num_of_summons_req)

    print("Map\n")
    string = ''
    for row in map_data:
        for char in row:
            string += char
        string += '\n'
    print(string)

if __name__ == "__main__":
    main()
