'''Graph Search'''

graph = {'A': set(['B', 'E']),
         'B': set(['A']),
         'C': set(['D', 'E','G','F']),
         'D': set(['C']),
         'E': set(['A', 'C','H']),
         'F': set(['C', 'I']),
         'G': set(['C','H']),
         'H': set(['E','G','I']),
         'I': set(['F','H'])
         }


cost = {
    'A' : 0,
    'B' : 0,
    'C' : 0,
    'D' : 0,
    'E' : 0,
    'F' : 0,
    'G' : 0,
    'H' : 0,
    'I' : 0
}


def bfs(graph, start, goal,stepCost=1):
    visited, queue = set(), [start]
    path = []
    while queue:
        vertex = queue.pop(0)
        #print(vertex)
        if vertex not in visited:
            visited.add(vertex)
            queue.extend(graph[vertex] - visited)
            for i in graph[vertex]:
                if cost[i] == 0:
                    cost[i]=cost[vertex]+1
            path.append(vertex)
            if vertex == goal:
                break


    return path

path = bfs(graph, 'A','G',1) # {'B', 'C', 'A', 'F', 'D', 'E'}
print(path)
print("start to goal cost is - > ", cost['G'])
