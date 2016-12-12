/*
 * IPAddress.h
 *
 *  Created on: Dec 11, 2016
 *      Author: nshinde
 */

#ifndef IPADDRESS_H_
#define IPADDRESS_H_

#include <iostream>
#include <cstring>
#include "Util.h"

class IPAddress {
public:
	IPAddress(std::string address): ip_string_(address) {
		mask_ = get_mask(address);
		ipAddress_ = get_addr(address);
	}
	virtual ~IPAddress();
	std::string IP_address() { return ip_string_; }
	u_int32_t get_network() { return ipAddress_; }
	u_int32_t get_mask() { return mask_; }

	int equal();
	u_int32_t get_addr(std::string ipaddr) {
		int lastIdx = ipaddr.rfind('/');
		std::string addr = ipaddr.substr(0, lastIdx - 1);
		std::cout<<"addr:"<<addr<<std::endl;
		std::vector<std::string> parts;
		parts = Util::split(addr,'.');
		u_int32_t value = (std::stoi(parts[0]) << 24) +
		      (std::stoi((parts[1])) << 16) +
		      (std::stoi((parts[2])) << 8) +
		      std::stoi((parts[3]));
		return value;
	}
    u_int32_t get_mask(std::string ipaddr) {
    	int beginIdx = ipaddr.rfind('/');
    	std::string mask = ipaddr.substr(beginIdx + 1, ipaddr.length());
    	return std::stoi(mask);
    }
private:
	std::string ip_string_;
	u_int32_t ipAddress_;
	u_int32_t mask_;
};

#endif /* IPADDRESS_H_ */
