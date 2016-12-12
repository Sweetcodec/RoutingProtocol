/*
 * Interface.h
 *
 *  Created on: Dec 11, 2016
 *      Author: nshinde
 */
#ifndef INTERFACE_H_
#define INTERFACE_H_

#include <iostream>
#include <vector>
#include <string>
#include "Util.h"
#include "IPAddress.h"
#include <set>

class Interface {
public:
	Interface(std::string name): name_(name) {};
	Interface(std::string name, IPAddress *ip, int areaNumber = 0):
		name_(name), ipaddress_(ip), area_number_(areaNumber) {};
	virtual ~Interface();
	std::string name() { return name_; }
	void set_name(std::string name) { name_ = name; }
    int area_number() { return area_number_; }
    void set_area_number(int anumber) { area_number_ = anumber; }
    int bandwidth() { return bandwidth_; }
    void set_bandwidth(int bw) { bandwidth_ = bw; }
    IPAddress* ipaddress() { return ipaddress_; }
    void set_ipaddress(IPAddress *ip) { ipaddress_ = ip; }
    int cost() { return cost_; }
    void set_cost(int cost) { cost_ = cost; }
    int priority() { return priority_; }
    void set_priority(int priority) { priority_ = priority; }

private:
    std::string name_;
	int area_number_;
	int bandwidth_;
	IPAddress *ipaddress_;
	int cost_;
	int priority_;
};

#endif /* INTERFACE_H_ */
