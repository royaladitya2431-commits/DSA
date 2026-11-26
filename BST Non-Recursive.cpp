# BST Non-Recursive
root = None

def insert(x):
    global root
    n = [x, None, None]
    if root == None:
        root = n
    else:
        t = root
        while True:
            if x < t[0]:
                if t[1] == None:
                    t[1] = n
                    break
                t = t[1]
            else:
                if t[2] == None:
                    t[2] = n
                    break
                t = t[2]

def level():
    q = [root]
    while q:
        t = q.pop(0)
        if t:
            print(t[0], end=" ")
            q.append(t[1])
            q.append(t[2])
    print()

def height():
    if root == None:
        return -1
    q = [[root, 0]]
    h = 0
    while q:
        t, d = q.pop(0)
        h = max(h, d)
        if t[1]: q.append([t[1], d+1])
        if t[2]: q.append([t[2], d+1])
    return h

def leaves():
    s = [root]
    while s:
        t = s.pop()
        if t:
            if t[1] == None and t[2] == None:
                print(t[0], end=" ")
            s.append(t[2])
            s.append(t[1])
    print()

while True:
    print("\n1.Insert 2.Level Order 3.Height 4.Leaves 5.Exit")
    c = int(input("Choice: "))
    if c == 1: insert(int(input("Value: ")))
    elif c == 2: level()
    elif c == 3: print("Height:", height())
    elif c == 4: leaves()
    elif c == 5: break
    else: print("Invalid")
