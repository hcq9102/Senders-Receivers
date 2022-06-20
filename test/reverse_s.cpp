// #include <hpx/config.hpp>
// 
// #include <boost/asio/execution/executor.hpp>
// #include <boost/asio/execution/receiver.hpp>
// #include <boost/asio/execution/sender.hpp>
// #include <boost/asio/execution.hpp>
#include <experimental/executor>

#include <hpx/execution_base/sender.hpp>
#include <hpx/execution_base/receiver.hpp>
#include <hpx/execution/algorithms/just.hpp>
#include <hpx/execution/algorithms/then.hpp>
#include <hpx/execution/algorithms/bulk.hpp>
#include <hpx/modules/execution.hpp>
#include <hpx/execution_base/this_thread.hpp>
#include <hpx/local/thread.hpp>
#include <hpx/modules/execution.hpp>
#include <execution>

#include <iostream>
#include <cstddef>
#include <algorithm>
#include <iterator>
#include <utility>
#include <thread>
#include <vector>
using namespace std::execution;
namespace ex = hpx::execution::experimental;
namespace tt = hpx::this_thread::experimental;

template <typename BidirIter>
auto async_reverse( BidirIter first, BidirIter last, std::size_t chunk_count){

    auto size = std::distance(first, last);
    std::size_t const chunk_size = size / chunk_count;
    // initial
    auto part_begin = first;

    auto s =  ex::just(first, last, part_begin)                             
                    |ex::bulk(chunk_count,[&](std::size_t i) { 
			std::size_t step = i * chunk_size;
                        part_begin = std::next(part_begin, step);
                        auto part_end = std::next(part_begin, step);
                        std::reverse(part_begin, part_end);
                   });

    
    
    auto const result = tt::sync_wait(s);
    return result;    
}

//auto async_reverse(std::vector<int> input){
//	auto begin2 = ex::just(input);
//	 return ex::then(begin2, [](auto && input){std::reverse(input.begin(), input.end());});
//}

int main(){
    std::vector<int> v = {1,2,3,4,5,6,7,8,9,10};
    async_reverse(v.begin(), v.end(), 3);
    for(auto it : v){
	std::cout << it <<std::endl;
    }	
    return 0;
}

