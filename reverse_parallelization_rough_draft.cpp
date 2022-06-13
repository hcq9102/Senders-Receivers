//6.13 update:

///////////////////////////////////////////////////////////////////
using namespace std::execution;

sender auto async_reverse(scheduler auto sch,                          
                                 std::span<const double> input, 
                                 Iter first,
                                 Iter last,                                                                  
                                 std::size_t chunk_count)                      
{
    std::size_t const chunk_size = input.size() / chunk_count; 
    auto size = detail::advance(first, last);
                                                         
    scheduler auto sch = my_thread_pool().scheduler(); 
    
    return transfer_just(sch, input)                              
           | bulk(chunk_count,  [=](std::size_t i, std::vector<double>& input) {  // i present chunk_number from, 0,1,2,4..
                            auto start = i * chunk_size;
                            auto end = std::min(input.size(), (i+1)*chunk_size)                                                          
                            std::reverse(begin(input)+start, begin(input)+end) ; 
                                                                          
    }) 
}
//6.13 update
// use zip_iterator
//////////////////////////////////////////////////////////////////
using namespace std::execution;

template<class Iter>
sender auto async_reverse(scheduler auto sch,                          
                                 std::span<const double> input, 
                                 Iter first,
                                 Iter last,                                                                  
                                 std::size_t chunk_count)                      
{
    std::size_t const chunk_size = input.size() / 2*chunk_count; // zip_iterator sequence will be input.size() / 2, so here chunk_size will be like this
    auto size = detail::advance(first, last);
    // type
    using rev_iter = std::reverse_iterator<Iter>;
    using zip_iterator = hpx::util::zip_iterator<Iter, rev_iter>;
    using reference = typename zip_iter::reference;
    auto zb = zip_iterator(hpx::util::make_zip_iterator(first,last));
                                                          
    scheduler auto sch = my_thread_pool().scheduler(); 
    
    return transfer_just(sch, input)                              
        | bulk(chunk_count,  [=](auto i, reference t) {
                            zb_start = i*chunk_size;
                            zb_end = std::min(input.size(), (i+1)*chunk_size)  
                            std::swap(get<0>(t+zb_start), get<1>(t+zb_end));
                                                                          
    }) 


}
