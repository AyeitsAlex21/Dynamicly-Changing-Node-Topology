import xml.etree.ElementTree as ET

def convert_graphml_to_ned(graphml_filename, ned_filename):
    tree = ET.parse(graphml_filename)
    root = tree.getroot()

    namespace = {'ns': root.tag.split('}')[0].strip('{')}

    with open(ned_filename, 'w') as ned_file:
        ned_file.write('simple ServerNode {\n    parameters:\n')
        ned_file.write('        @display("i=device/server");\n')
        ned_file.write('    gates:\n        inout gate;\n}\n\n')

        ned_file.write('simple ClientNode {\n    parameters:\n')
        ned_file.write('        @display("i=device/pc");\n')
        ned_file.write('    gates:\n        inout gate;\n}\n\n')

        ned_file.write('simple NothingNode {\n    parameters:\n')
        ned_file.write('        @display("i=device/laptop");\n')
        ned_file.write('    gates:\n        inout gate;\n}\n\n')

        ned_file.write('network Network {\n    submodules:\n')

        for node in root.findall('ns:graph/ns:node', namespace):
            node_id = node.get('id')
            node_type = "NothingNode" 
            for data in node.findall('ns:data', namespace):
                if data.get('key') == "d35":
                    if data.text == "Server":
                        node_type = "ServerNode"
                    elif data.text == "Client":
                        node_type = "ClientNode"
            ned_file.write(f'        node{node_id}: {node_type} {{ ')
            for data in node.findall('ns:data', namespace):
                ned_file.write(f'{data.get("key")} = "{data.text}"; ')
            ned_file.write('};\n')

        ned_file.write('    connections allowunconnected:\n')

        for edge in root.findall('ns:graph/ns:edge', namespace):
            source = edge.get('source')
            target = edge.get('target')
            latency = "0"
            for data in edge.findall('ns:data', namespace):
                if data.get("key") == "d41":
                    latency = data.text
            ned_file.write(f'        node{source}.gate++ <--> Delay={{ delay={latency}ms; }} <--> node{target}.gate++;\n')

        ned_file.write('}')


convert_graphml_to_ned('output.graphml', 'output.ned')
