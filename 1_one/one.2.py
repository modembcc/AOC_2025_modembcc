with open('one.in', 'r', encoding="utf-8") as f:
    value = 50
    ans = 0
    for instruction in f:
        direction = instruction[0]
        rotations = int(instruction[1:].strip())
        i_value = value
        value = value + rotations if direction == 'R' else value - rotations
        while value < 0 or value > 100:
            ans += 1 if i_value != 0 or value > 0 else 0
            value += 100 if value < 0 else -100
            i_value = 177013 # magic!
        if value == 0 or value == 100:
            ans = ans + 1
            value = 0
    print(ans)
    
