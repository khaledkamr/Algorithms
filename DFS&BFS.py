from collections import deque
graph = {
  'A' : ['B','G'],
  'B' : ['C', 'D', 'E'],
  'C' : [],
  'D' : [],
  'E' : ['F'],
  'F' : [],
  'G' : ['H'],
  'H' : ['I'],
  'I' : [],
}
''' A
   B    G
 C D E  H
     F  I
'''
start='A'
goal='I'

def DFS(graph, start):
    stack=[]
    visited=set()
    stack.append(start)
    visited.add(start)
    while stack:
        s = stack.pop()
        print(s,end=" ")
        if s == goal:
            break
        for x in graph[s]:
            if x not in visited:
                stack.append(x)
                visited.add(x)

def BFS(graph,start):
    queue=deque()
    visited=set()
    queue.append(start)
    visited.add(start)
    while queue:
        s = queue.popleft()
        print(s,end=" ")
        if s == goal:
            break
        for x in graph[s]:
            if x not in visited:
                queue.append(x)
                visited.add(x)
                
print("DFS: ")
DFS(graph, start)
print("\nBFS: ")
BFS(graph,start)
