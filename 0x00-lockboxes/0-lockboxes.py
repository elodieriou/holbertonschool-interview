#!/usr/bin/python3
"""This module defines the canUnlockAll method"""


def canUnlockAll(boxes):
    """This method determines if all the boxes can be opened"""
    unLockBoxes = [0]
    for box in boxes:
        index = boxes.index(box)
        for key in box:
            if key != index and key < len(boxes) and key not in unLockBoxes:
                unLockBoxes.append(key)
    return len(unLockBoxes) == len(boxes)
