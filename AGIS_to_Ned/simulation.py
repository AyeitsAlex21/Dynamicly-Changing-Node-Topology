import networkx as nx
import os
import sys
import matplotlib.pyplot as plt
from helpers import *

def draw_graph(G, colorMap):

    nx.draw(G, node_color=colorMap, with_labels=True)
    plt.show()

def assign_client_server(G):
    colorMap = []

    sizeofnetwork = len(G.nodes)
    num_servers = sizeofnetwork // 15 if sizeofnetwork // 15 > 0 else 1
    num_clients = sizeofnetwork // 6 if sizeofnetwork // 6 > 0 else 1

    for node in G.nodes:
        G.nodes[node]["role"] = "nothing"
        G.nodes[node]["color"] = "grey"


    for _ in range(num_servers):
        candidate = str(random.randint(0, len(G.nodes) - 1))
        while(G.nodes[candidate]["role"] == "Server"):
            candidate = str(random.randint(0, len(G.nodes) - 1))

        G.nodes[candidate]["role"] = "Server"
        G.nodes[candidate]["color"] = "red"
    
    for _ in range(num_clients):
        candidate = str(random.randint(0, len(G.nodes) - 1))
        while(G.nodes[candidate]["role"] == "Server" or G.nodes[candidate]["role"] == "Client"):
            candidate = str(random.randint(0, len(G.nodes) - 1))

        G.nodes[candidate]["role"] = "Client"
        G.nodes[candidate]["color"] = "blue"
    
    colorMap = [G.nodes[node]["color"] for node in G.nodes]
    return colorMap

def assign_weights(G):
    for u, v in G.edges():
        cord1 = (G.nodes[u]["Latitude"], G.nodes[u]["Longitude"])
        cord2 = (G.nodes[v]["Latitude"], G.nodes[v]["Longitude"])
        G[u][v]["latency"] = compute_latency(haversine(cord1, cord2))

def main():

    if len(sys.argv) != 2:
        print("Usage: python3 simulation.py [directory of graphml files]")
        sys.exit(1)

    colorMap = []
    dir = sys.argv[1]
    graphml_files = [f for f in os.listdir(dir) if f.endswith('.graphml')]

    for graphml_file in graphml_files:
        graph = nx.read_graphml(os.path.join(dir, graphml_file))
        colorMap = assign_client_server(graph)
        assign_weights(graph)
        nx.write_graphml(graph, 'output.graphml')
        draw_graph(graph, colorMap)

   

if __name__ == "__main__":
    random.seed(1)
    main()
