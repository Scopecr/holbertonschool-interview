## Lockboxes
# Determines if all the boxes can be opened.

Args:
  boxes (list of lists): A list where each element is a list of keys contained in a box. 
               Each box is numbered sequentially from 0 to n - 1.

Returns:
  bool: True if all boxes can be opened, else False.

The function follows these rules:
- A key with the same number as a box opens that box.
- All keys are positive integers.
- There can be keys that do not have corresponding boxes.
- The first box (boxes[0]) is initially unlocked.
"""