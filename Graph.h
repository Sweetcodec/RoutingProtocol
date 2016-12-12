/*
 * Graph.h
 *
 *  Created on: Dec 11, 2016
 *      Author: nshinde
*/
#ifndef GRAPH_H_
#define GRAPH_H_

#include<set>
#include<iostream>

#include "Link.h"
#include "Interface.h"
#include "Router.h"

#include "Utilities/Util.h"
#include "Utilities/IPAddress.h"
class Link;

class Graph {
public:

	typedef std::set<Router*> RouterSet;
	typedef std::set<Link*> LinkSet;
	typedef RouterSet::iterator Router_iterator;
	typedef LinkSet::iterator Link_iterator;

	Graph();
	Graph(RouterSet &nodes, LinkSet &edges): nodes_(nodes), edges_(edges) {};
	virtual ~Graph();
    void construct_graph();

	Link* get_link(std::string from_router_name, std::string to_router_name);

    Router* get_router(std::string name) {
    	Router *router = new Router(name);
    	Router_iterator router_itr = nodes_.find(router);
		if(*router_itr)
			return *router_itr;
		else {
			nodes_.insert(router);
			return router;
		}
	}

   /* Interface* get_interface(std::string router_name, std::string intf_name) {
    	Router *router = new Router(router_name);
    	Router_iterator router_itr = nodes_.find(router);
    	if(*router_itr) {
			Interface *intf = new Interface(router_name, intf_name);
    		Router::Intf_itr *intf_itr = (*router_itr)->interfaces().find(intf);
			if(*intf_itr)
				return *intf_itr;
			else {
				(*router_itr)->interfaces().insert(intf);
				return intf;
			}
	    } else {
	    	router->interfaces().insert(new Interface(router_name, intf_name));
			nodes_.insert(router);
			return router;
		}
	} */
	RouterSet nodes_;
	LinkSet edges_;
};

#endif /* GRAPH_H_ */
