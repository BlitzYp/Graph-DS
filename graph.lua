function addvertex(value, graph) 
  graph[value] = {}
end

function addedge(v1, v2, graph)
  if graph[v1] == nil or graph[v2] == nil then
    print("those values don't exist")
    return
  end
  table.insert(graph[v1], v2)
  table.insert(graph[v2], v1)
end

function printConnections(graph)
  for key, value in pairs(graph) do
    print("Values for: " .. key)
    for i=1, #value do
      print(value[i])
    end
  end
end

local graph = {}
addvertex("blitz", graph)
addvertex("bob", graph)
addvertex("john", graph)
addedge("blitz", "bob", graph)
addedge("blitz", "john", graph)
printConnections(graph)
