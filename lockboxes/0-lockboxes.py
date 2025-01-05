#!/usr/bin/python3
"""method that determines if all boxes can be opened"""

def canUnlcokAll(boxes):
    """ n = number of locked boxes
        boxes = list of lists
        Return = True if all boxes can be opened
        False if not all boxes can be opened
    """
    if len(boxes) == 0:
        return False
    #if box empity return false
    keys = [0]
    #boxes that return 0 are unlocked
    for keys in keys:
        #loop through keys
        for key in keys:
            for new_key in boxes[key]:
                #loop through boxes and if new_keys is or not in key new_keys is less than the number of boxes
                if new_key not in keys and new_key < len(boxes):
                    keys.append(new_key)
                    #Adds new_key to keys and if number is equal to the number of boxes
    if len(keys) == len(boxes):
        return True
    return False