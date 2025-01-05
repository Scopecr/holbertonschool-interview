#!/usr/bin/python3
def canUnlockAll(boxes):
    opened = set()
    opened.add(0)
    keys = [0]
    while keys:
        key = keys.pop()
        for new_key in boxes[key]:
            if new_key not in opened:
                opened.add(new_key)
                keys.append(new_key)
    return len(opened) == len(boxes)

if __name__=="__main__":
    boxes = [[1], [2], [3], [4], []]
    print(canUnlockAll(boxes))