/*
 * Link.h
 *
 *  Created on: Dec 11, 2016
 *      Author: nshinde
 */
#ifndef LINK_H_
#define LINK_H_

#include <iostream>
#include <vector>
#include <string>
#include "Util.h"
#include "IPAddress.h"
#include <set>

class Link {
public:
	struct edge {
			std::string router_name_;
			std::string intf_name_;

			edge(std::string router_name, std::string intf_name):
				router_name_(router_name), intf_name_(intf_name) {}
			void operator=(edge &e) {
				router_name_ = e.router_name_;
				intf_name_ = e.intf_name_;
			}
	};
	typedef struct edge Edge;

	Link(Edge *from, Edge *to) {
		from_ = from;
		to_ = to;
	}
	Link(std::string from_router, std::string from_intf, std::string to_router, std::string to_intf) {
		Edge *from = new Edge(from_router, from_intf);
		from_ = from;
		Edge *to = new Edge(to_router, to_intf);
		to_ = to;
	}
	virtual ~Link();

	std::string from_router_name() { return from_->router_name_; }
	std::string to_router_name() { return to_->router_name_; }
	std::string from_intf_name() { return from_->intf_name_; }
	std::string to_intf_name() { return to_->intf_name_; }
    int bandwidth() { return bandwidth_; }
    void set_bandwidth(int bandwidth) { bandwidth_ = bandwidth; }
private:
	Edge *from_;
	Edge *to_;
	int bandwidth_;
};

#endif /* LINK_H_ */
