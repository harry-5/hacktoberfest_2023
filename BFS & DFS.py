# Solution of the Issue#1
# Implementation of BFS & DFS in Python

from collections import deque

def bfs(node, adj, visited, ans):
    queue = deque([node])
    visited[node] = True
    while queue:
        parent = queue.popleft()
        ans.append(parent)
        for child in adj[parent]:
            if not visited[child]:
                queue.append(child)
                visited[child] = True

def dfs(node, adj, visited, ans):
    visited[node] = True
    ans.append(node)
    for child in adj[node]:
        if not visited[child]:
            dfs(child, adj, visited, ans)

def main():
    n = int(input("Enter the number of Nodes\n"))
    e = int(input("Enter the number of Edges\n"))
    print("Enter the linkages between the nodes\n")
    adj = {}
    for i in range(e):
        u, v = map(int, input().split())
        adj[u] = adj.get(u, []) + [v]
        adj[v] = adj.get(v, []) + [u]

    # making visited array
    visited_bfs = [False] * n
    ans_bfs = []

    visited_dfs = [False] * n
    ans_dfs = []

    # BFS traversal
    bfs(0, adj, visited_bfs, ans_bfs)
    print("BFS Traversal")
    for i in ans_bfs:
        print(i, end=" ")

    # DFS traversal
    dfs(0, adj, visited_dfs, ans_dfs)
    print("\nDFS Traversal")
    for i in ans_dfs:
        print(i, end=" ")

if __name__ == "__main__":
    main()
