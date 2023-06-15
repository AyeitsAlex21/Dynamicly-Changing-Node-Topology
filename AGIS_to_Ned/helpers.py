import networkx as nx
import random
import pandas as pd
from haversine import haversine, Unit

def compute_distance(coord1, coord2):
    return haversine(coord1, coord2, unit=Unit.KILOMETERS)

def compute_latency(distance):
    speed_of_light_in_fiber = 199.861638  # km/ms
    return (distance / speed_of_light_in_fiber)

def generate_topology(n, topology_type):
    if topology_type == "random":
        return nx.erdos_renyi_graph(n, 0.5)
    elif topology_type == "small_world":
        return nx.watts_strogatz_graph(n, int(n / 4), 0.1)
    elif topology_type == "scale_free":
        return nx.barabasi_albert_graph(n, 2)

if __name__ == "__main__":
    cord1 = (42.33143, -83.04575)
    cord2 = (39.95622, -75.05795)
    print(compute_latency(compute_distance(cord1, cord2)))