#!/usr/bin/python3
def canUnlockAll(boxes):
    unLockBoxes = []
    for box in boxes:
        index = boxes.index(box)
        if len(box) == 0 and 0 not in unLockBoxes:
            unLockBoxes.append(0)
        for key in box:
            if key != index and key < len(boxes) and key not in unLockBoxes:
                unLockBoxes.append(key)
    if len(unLockBoxes) == len(boxes):
        return True
    return False
