//Code modified from Cooper Riley
#include "ListGraph.h"

//http://opendatastructures.org/versions/edition-0.1e/ods-java/12_2_AdjacencyLists_Graph_a.html
ListGraph::ListGraph(int numNodes){

	edgeList.resize(numNodes);
	num_edges = 0;
	
}

ListGraph::~ListGraph(){

}
//http://www.cplusplus.com/forum/general/67443/
void ListGraph::addEdge(NodeID u, NodeID v, EdgeWeight weight){
	bool dup = false;
	if(u >= 0 && u < edgeList.size() && v >= 0 && v < edgeList.size() && u != v && weight > 0){
		EList::iterator it;
		it = edgeList[u].begin();
		for(it = edgeList[u].begin(); it != edgeList[u].end(); it++){
			NWPair myPair = (*it);
			if (myPair.first == v &&  myPair.second == weight){	
				dup = true;				
			}
		}
	}
	if(dup){
		return;
	}
	else{	
	
		edgeList[u].push_back(NWPair(v,weight));
		edgeList[v].push_back(NWPair(u,weight)); 
		num_edges++;
	}
}

//Code from lecture on 11/27
EdgeWeight ListGraph::weight(NodeID u, NodeID v) const {
	EList::const_iterator it;
	for(it = edgeList[u].begin(); it != edgeList[u].end(); it++){
		NWPair edge = *it;
		if(edge.first == v)
			return edge.second;
	}
	return 0;
}

std::list<NWPair> ListGraph::getAdj(NodeID u) const {
	
	std::list<NWPair> adj = std::list<NWPair>();
	if(u >= 0 && u < edgeList.size()){
		adj =  edgeList[u];
	}
	
	return adj;
}

unsigned ListGraph::degree(NodeID u) const {
	
	if(0 <= u && u < edgeList.size()){
		return edgeList[u].size();
	}
	else{
		return 0;
	}
	
}

unsigned ListGraph::size() const {

	return edgeList.size();
}

unsigned ListGraph::numEdges() const {

	return num_edges;
}