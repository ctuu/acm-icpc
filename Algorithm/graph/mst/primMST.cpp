//http://blog.csdn.net/qq1263292336/article/details/50326427
#ifndef __PRIM_MST_H__
#define __PRIM_MST_H__

#include "Edge.h"
#include "EdgeWeightedGraph.h"
#include <queue>
#include <map>

class PrimMST {
private:
	typedef std::map<double, int>::const_iterator IntDoubleMapIter;
	int		vNum;		// 边数
	Edge	*edgeTo;	// 距离树最近的边
	double	*distTo;	// distTo[w] = edgeTo[w].weight()
	bool	*marked;	// 如果v在树中则为true
	std::map<double, int> map;	// key:横切边的权值，value:顶点

public:
	PrimMST(const EdgeWeightedGraph& G);
	~PrimMST() { delete[] edgeTo; delete[] distTo; delete[] marked; }

	double getWeight()const;
	std::list<Edge> edges()const;

private:
	void visit(const EdgeWeightedGraph& G, int v);

};

// constructor
PrimMST::PrimMST(const EdgeWeightedGraph& G) {
	vNum = G.getV();
	edgeTo = new Edge[vNum];
	distTo = new double[vNum];
	for (int i = 0; i < vNum; ++i) distTo[i] = DBL_MAX;
	marked = new bool[vNum];
	for (int i = 0; i < vNum; ++i) marked[i] = false;

	distTo[0] = 0;
	map[0.0] = 0;
	while (!map.empty()) {
		// 每次都将权重最小的pop出来
		// 类似优先队列的操作，不过优先队列没有key和value
		// 可以用带索引的优先列队来替代
		IntDoubleMapIter iter = map.begin();
		int v = iter->second;	// 权值最小的边的顶点
		map.erase(iter);
		visit(G, v);
	}
}

// visit
void PrimMST::visit(const EdgeWeightedGraph& G, int v) {
	
	marked[v] = true;
	for (Edge e : G.getAdj(v)) {
		int w = e.other(v);

		if (marked[w]) continue;	// w也在最小生成树中
		if (e.getWeight() < distTo[w]) {
			// 最小生成树到顶点w权重最小的边为e
			edgeTo[w] = e;
			// 连接w顶点的权重
			distTo[w] = e.getWeight();
			// 将权重-顶点添加进map
			map[distTo[w]] = w;
		}
	}
}

// weight
double PrimMST::getWeight()const {
	double weight = 0.0;
	for (int i = 0; i < vNum; ++i) {
		weight += distTo[i];
	}
	return weight;
}

// edges
std::list<Edge> PrimMST::edges()const {
	std::list<Edge> lst;
	for (int i = 0; i < vNum; ++i) {
		lst.push_back(edgeTo[i]);
	}
	return lst;
}


#endif