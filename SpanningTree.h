/*
 * SpanningTree.h
 *
 *  Created on: Dec 11, 2016
 *      Author: nshinde
 */

#ifndef SPANNINGTREE_H_
#define SPANNINGTREE_H_

#include <iostream>
#include <vector>
#include <string>
#include <set>
#include "Graph.h"

class SpanningTree : public Graph {
public:
	SpanningTree();
	virtual ~SpanningTree();
	void calculate_spanning_tree();
};

#endif /* SPANNINGTREE_H_ */
