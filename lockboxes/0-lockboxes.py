#!/usr/bin/python3
"""method that determines if all
boxes can be opened"""


def canUnlockAll(boxes):
    """n = number of locked boxes
    boxes = list of lists
    Return = True if all boxes can be opened
    False if not all boxes can be opened"""
    # box is empty, return false
    if len(boxes) == 0:
        return False
    # box 0 is unlocked
    keys = [0]
    # loop through keys
    for key in keys:
        # loop through boxes
        for new_key in boxes[key]:
            # if new_key is not in keys and new_key is less
            # than the number of boxes
            if new_key not in keys and new_key < len(boxes):
                # add new_key to keys
                keys.append(new_key)
    # if the number of keys is equal to the number of boxes
    if len(keys) == len(boxes):
        return True
    return False
