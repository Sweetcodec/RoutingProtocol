/*
 * AreaTopology.h
 *
 *  Created on: Dec 11, 2016
 *      Author: nshinde
 */

#ifndef AREATOPOLOGY_H_
#define AREATOPOLOGY_H_

#include <iostream>
#include <vector>
#include <string>
#include "Util.h"
#include "IPAddress.h"
#include <set>
#include "Graph.h"
#include "Router.h"
class Router;
class Link;
class Interface;

class AreaTopology {
public:
	AreaTopology(int number): area_number_(number) {}
	virtual ~AreaTopology();
	int area_number() { return area_number_; }
	Graph* topology() { return sub_topology_; }

private:
	int area_number_;
	Graph *sub_topology_;
};

#endif /* AREATOPOLOGY_H_ */
