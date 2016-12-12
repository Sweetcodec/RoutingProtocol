/*
 * Router.h
 *
 *  Created on: Dec 11, 2016
 *      Author: nshinde
 */

#ifndef ROUTER_H_
#define ROUTER_H_

#include <iostream>
#include <vector>
#include <string>
#include <set>

#include "Link.h"
#include "Interface.h"
#include "RoutingTable.h"

#include "Utilities/Util.h"
#include "Utilities/IPAddress.h"

class Router {
public:
	typedef std::set<Interface*> InterfaceSet;
	typedef std::set<Link*> LinkSet;
	typedef InterfaceSet::iterator Intf_itr;

	Router(std::string name): name_(name) {};
	virtual ~Router();
	bool Equals(Router *right) {
		if (name_ == right->name())
			return true;
		return false;
	}
	int GetHashCode() {
		return std::stoi(name_);
	}

	std::string name() { return name_; }
	void set_name(std::string name) { name_ = name; }
	std::string type() { return type_; }
	void set_type(std::string type) { type_ = type; }
	std::string software_version() { return software_version_; }
	void set_software_Version(std::string version) { software_version_ = version; }
	IPAddress* router_id() { return router_id_; }
	void set_router_id(IPAddress *address) { router_id_ = address; }
	RoutingTable* routing_table() { return RT_; }
	void set_routing_table(RoutingTable *table) { RT_ = table; }
	LinkSet links() { return links_; }
	void set_links(LinkSet &links) { links_ = links; }
	InterfaceSet interfaces() { return interfaces_; }
	void set_interfaces(InterfaceSet &interfaces) { interfaces_ = interfaces; }
	void fill_routing_table();
    void calculate_spanning_tree();

    /*SpanningTree* spt() { return spt_; }
	void set_spt(SpanningTree *tree) { spt_ = tree; }
	*/
private:
    std::string name_;
    std::string type_;
    std::string software_version_;
	IPAddress *router_id_;
	RoutingTable *RT_;
	//SpanningTree *spt_;
	InterfaceSet interfaces_;
	LinkSet links_;
};

#endif /* ROUTER_H_ */
