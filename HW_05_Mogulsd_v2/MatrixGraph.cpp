//Code modified from Cooper Riley
#include "MatrixGraph.h"



//http://stackoverflow.com/questions/4320085/vector-of-vector-initialization
//http://stackoverflow.com/questions/6491251/multi-dimensional-vector-initialization?rq=1
MatrixGraph::MatrixGraph(unsigned num_nodes){
	num_edges = 0;
	
	M.resize(num_nodes);
	
	for(int i = 0; i < num_nodes; i++){
		M.resize(num_nodes);
		
		for(int j = 0; j < num_nodes; j++){
			M[i].push_back(0);
		}
	}
}

MatrixGraph::~MatrixGraph(){

}

//http://thecodecracker.com/c-programming/addition-and-deletion-of-nodes-and-edges-in-a-graph/
//http://www.cplusplus.com/forum/general/49608/
//http://stackoverflow.com/questions/2207009/reference-to-element-in-2d-vector-c
void MatrixGraph::addEdge(NodeID u, NodeID v, EdgeWeight weight){
	
	if(u >= 0 && u < M.size() && v >= 0 && v < M.size() && u!= v && weight > 0 && M[u][v] == 0 && M[v][u] == 0){
		if(M[u][v] == 0){
			M[u][v] = weight;
			M[v][u] = weight;
			num_edges++;
		}
	}
}

EdgeWeight MatrixGraph::weight(NodeID u, NodeID v) const{

	if(0 <= u && u < M.size() && 0 <= v && v < M.size()){
		return M[u][v];
	}
	else{
		return 0;
	}
}

std::list<NWPair> MatrixGraph::getAdj(NodeID u) const{
	std::list<NWPair> adjNodes;
	
	for (int i=0; i<M[u].size(); i++){
		NWPair cur (i, M[u][i]);
		if(cur.second != 0) 
			adjNodes.push_back(cur);
	}
	return adjNodes;
	
}

unsigned MatrixGraph::degree(NodeID u) const{
	
	unsigned degree = 0;
	
	for(int i = 0; i < M[u].size() ; i++){
		if(M[u][i] > -1)
			degree++;
	} 
	
	return degree;
}

unsigned MatrixGraph::size() const{
	return M.size();
}

unsigned MatrixGraph::numEdges() const{
	return num_edges;
}