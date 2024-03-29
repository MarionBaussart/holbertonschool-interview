# 0x10-rain

## 0. Rain
Given a list of non-negative integers representing the heights of walls with unit width 1, as if viewing the cross-section of a relief map, calculate how many square units of water will be retained after it rains.

- Prototype: def rain(walls)
- walls is a list of non-negative integers.
- Return: Integer indicating total amount of rainwater retained.
- Assume that the ends of the list (before index 0 and after index walls[-1]) are not walls, meaning they will not retain water.
- If the list is empty return 0.

Visual representation of the walls [0, 1, 0, 2, 0, 3, 0, 4]
![Visual representation of the walls [0, 1, 0, 2, 0, 3, 0, 4]](walls_1.png)

Visual representation of the walls [2, 0, 0, 4, 0, 0, 1, 0]
![Visual representation of the walls [2, 0, 0, 4, 0, 0, 1, 0]](walls_2.png)