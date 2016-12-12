/*
 * RoutingTable.h
 *
 *  Created on: Dec 11, 2016
 *      Author: nshinde
 */

#ifndef ROUTINGTABLE_H_
#define ROUTINGTABLE_H_

#include <iostream>
#include <vector>
#include <string>
#include "Utilities/Util.h"
#include "Utilities/IPAddress.h"
#include <set>
#include<list>

class RoutingTable {
public:
	RoutingTable();
	virtual ~RoutingTable();
    struct RT_row {
		std::string route_source_;
		IPAddress *destination_;
		std::string outoging_interface_;
		int admin_distance_;

		RT_row (IPAddress *dest, std::string intf, std::string route_source = "OSPF", int admin_dist = 120):
			 destination_(dest), outoging_interface_(intf), route_source_(route_source),
			 admin_distance_(admin_dist) {}

		std::string format() {
			std::string row("RT row--->");
			row =  route_source_ + " | " + destination_->IP_address() + " | " + outoging_interface_;
			std::cout<<row<<std::endl;
			return row;
		}
	};
    typedef std::list<RT_row*> RT_rows;
    RT_rows routing_table() { return rows_; }
    void add_row(RT_row *row);
private:
    RT_rows rows_;
};

#endif /* ROUTINGTABLE_H_ */
