#include <utility>
#include <iostream>
#include <vector>

#include <boost/iterator/zip_iterator.hpp>
using namespace std;
int main()
{
    
std::vector<int> a = { 1, 2, 3, 4,5,6,7,8 };
std::vector<int>::iterator iter;    
auto first = a.begin();
auto last = a.end();
auto size = a.size();
    
using rev_iter = std::reverse_iterator<std::vector<int>::iterator>;
using zip_iterator = boost::iterators::zip_iterator<boost::tuple<std::vector<int>::iterator, rev_iter>>;  
auto zb = zip_iterator(boost::make_tuple(first,last));

/*
auto zb_first = zip_iterator(boost::make_tuple(first,last));
auto zb_end = zip_iterator(boost::make_tuple(first+size/2,last));
for(auto it =zb_first ; i != zb_end; it){
    cout<< get<0>(*it) <<" " << get<1>(*it)<<endl;
}
*/
// using zip_iterator = boost::iterators::zip_iterator<boost::make_zip_iterator(boost::make_tuple<iter, rev_iter>>;     
// auto zb = zip_iterator(boost::make_zip_iterator(boost::make_tuple(first,last)));

//auto zb = boost::iterators::zip_iterator<iter>(boost::make_zip_iterator(first, rev_iter(last)));    
    

//auto zb = boost::iterators::zip_iterator<boost::make_zip_iterator(boost::make_tuple(first , std::reverse_iterator<iter>(last)))>;    
    
//auto zb = boost::iterators::zip_iterator<iter, rev_iter>(boost::make_zip_iterator(first,last));
for(size_t i = 0; i != size/2; ++i, ++zb){
    cout<< get<0>(*zb) <<" " << get<1>(*zb)<<endl;
}
    
    
// using std::swap;
for(size_t i =0; i < size/2; i++, ++zb){
    std::swap(get<0>(*zb), get<1>(*zb)); 
}
cout << "The reversed array would be: "<< endl;
for(auto it : a){
    cout<< it<<endl;
} 

cout << "The parallel work: \n"<< endl; 
int chunknum = 4;  // assume 4 cores
size_t offset = size/2*chunknum;   // each chunk size length 
for(int j = 0; j<chunknum; j++){
    zb = zb + j*offset; // initialize
    for(size_t i =0; i < size/2; i++, ++zb){
    std::swap(get<0>(*zb), get<1>(*zb)); 
    }
}    

}
