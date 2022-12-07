#!/usr/bin/python3
"""This module defines the canUnlockAll method"""


def canUnlockAll(boxes):
    """This method determines if all the boxes can be opened"""
    unLockBoxes = []
    for box in boxes:
        index = boxes.index(box)
        if len(box) == 0 and 0 not in unLockBoxes:
            unLockBoxes.append(0)
        for key in box:
            if key != index and key < len(boxes) and key not in unLockBoxes:
                unLockBoxes.append(key)
    return len(unLockBoxes) == len(boxes)
