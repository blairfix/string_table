#include <Rcpp.h>
#include <algorithm>
#include <boost/sort/spreadsort/spreadsort.hpp>
#include <string>
#include <vector>

using namespace Rcpp;

// [[Rcpp::plugins(cpp11)]]
// [[Rcpp::export]]

std::map<std::string, int> string_table(  std::vector<std::string> x )
{
    // sort x
    boost::sort::spreadsort::spreadsort(x.begin(), x.end());

    // output map
    std::map<std::string, int> output;

    // loop over x and test if new element
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

    return output;

}
