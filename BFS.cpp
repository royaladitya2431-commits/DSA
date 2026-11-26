
g = {}

while True:
    print("\n1.Create 2.Display 3.BFS 4.Exit")
    c = int(input("Choice: "))

    if c == 1:
        n = int(input("Vertices: "))
        g = {}
        for i in range(n):
            g[i] = []
        e = int(input("Edges: "))
        for i in range(e):
            u, v = map(int, input("Enter edge: ").split())
            g[u] += [v]
            g[v] += [u]

    elif c == 2:
        for i in g:
            print(i, "->", g[i])

    elif c == 3:
        s = int(input("Start: "))
        q = [s]
        visited = [s]
        while q:
            x = q.pop(0)
            print(x, end=" ")
            for v in g[x]:
                if v not in visited:
                    visited += [v]
                    q += [v]
        print()

    elif c == 4:
        break

    else:
        print("Invalid Choice")
