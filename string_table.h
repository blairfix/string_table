//File: string_table.h
#ifndef STRING_TABLE_H
#define STRING_TABLE_H

#include <algorithm>
#include <boost/sort/spreadsort/spreadsort.hpp>
#include <string>
#include <vector>


std::map<std::string, int> string_table( std::vector<std::string> x )
{

    // output map
    std::map<std::string, int> output;

    // test that x is not null
    if(x.size() >= 1){

        // sort x
        boost::sort::spreadsort::spreadsort(x.begin(), x.end());

        // loop over x and test if new element found
        int count = 1;

        for(int i = 1; i < x.size(); i++){

            if( x[i] == x[i- 1] ) {

                count++;

            } else{

                output[ x[i - 1] ] = count;
                count = 1;

            }
        }

        // last element
        output[ x[ x.size() - 1 ] ] = count;
    }

    return output;

}

#endif
