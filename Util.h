/*
 * Util.h
 *
 *  Created on: Dec 11, 2016
 *      Author: nshinde
 */

#ifndef UTIL_H_
#define UTIL_H_

#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <list>


class Util {
public:

	Util();
	virtual ~Util();
	static std::vector<std::string> split(const std::string& str, const char& c)
	{
		std::string buff = "";
		std::vector<std::string> v;

		for(std::string::const_iterator itr = str.begin(); itr != str.end() ; ++itr)
		{
			if( *itr != c)
				buff+= *itr;
			else {
				if(*itr == c && buff != "") {
					v.push_back(buff);
					std::cout<<" val:"<<buff<<std::endl;
					buff = "";
				}
			}

		}
		if(buff != "") v.push_back(buff);
		return v;
	}
};

#endif /* UTIL_H_ */
