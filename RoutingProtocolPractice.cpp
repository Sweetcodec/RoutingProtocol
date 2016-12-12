//============================================================================
// Name        : RoutingProtocolPractice.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <string>
#include "Utilities/Util.h"
#include "Utilities/IPAddress.h"
#include <set>

using namespace std;

int main() {
    IPAddress addr("10.2.2.2/24");

	cout << "adr:" << addr.IP_address() <<" mask:" << addr.get_mask()<< endl; // prints !!!Hello World!!!
	return 0;
}
