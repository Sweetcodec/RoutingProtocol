/*
 * Topology.h
 *
 *  Created on: Dec 11, 2016
 *      Author: nshinde
 */

#ifndef TOPOLOGY_H_
#define TOPOLOGY_H_

#include <iostream>
#include <vector>
#include <string>
#include "Util.h"
#include "IPAddress.h"
#include <set>
#include "AreaTopology.h"

class Topology {
public:
	typedef std::map<int, AreaTopology*> SubTopology;
    typedef SubTopology::iterator SubTopo_iterator;
	Topology();
	virtual ~Topology();
	SubTopology& sub_toplogy() { return sub_topology_; }
	int get_total_area_number();
	AreaTopology* get_topology(int area_number) {
		SubTopo_iterator itr = sub_topology_.find(area_number);
		return  itr->second;
	}
	void add_area_topology(int area_number, AreaTopology *topo) {
		sub_topology_.insert(std::pair<int, AreaTopology*> (area_number, topo));
	}

private:
	SubTopology sub_topology_;
};

#endif /* TOPOLOGY_H_ */
