with open('one.in', 'r', encoding="utf-8") as f:
    value = 50
    ans = 0
    for instruction in f:
        direction = instruction[0]
        rotations = int(instruction[1:].strip())
        value = value + rotations if direction == 'R' else value - rotations
        value = value % 100
        if value == 0:
            ans = ans + 1
    print(ans)
    
