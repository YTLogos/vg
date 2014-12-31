#include <iostream>
#include <fstream>
#include "pb2json.h"
#include "vg.pb.h"
#include "vg.hpp"

using namespace std;
using namespace google::protobuf;
using namespace vg;

int main(int argc,char *argv[])
{
    VG graph;

    Node* n1 = graph.create_node("AAAACACGAAGGTGCTCACTGAAACATGGGAACCAAAG");
    Node* n2 = graph.create_node("TTTCCCACAACATAAGGAGCAGAGTGAAACTGCAGAGG");
    Node* n3 = graph.create_node("TTTCCCAGAGG");
    Node* n4 = graph.create_node("TACAATCATGGAATTCCAGAAAATG");

    graph.create_edge(n1, n2);
    graph.create_edge(n1, n3);
    graph.create_edge(n3, n4);
    graph.create_edge(n2, n4);

    /*
    ofstream of("test.vg");
    n.SerializeToOstream(&of);
    */

	char *json3 = pb2json(graph.graph);
	cout<<json3<<endl;
	free(json3);

    return 0;
}
