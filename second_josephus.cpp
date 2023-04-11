#include<iostream>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

typedef tree<int,null_type,std::less<int>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;

/* A generalization of the first Josephus problem. Now it is possible to skip any positive number of elements,
which is best done using an indexed set. */

int main(){

    long long int upper_limit, skip;
    indexed_set storage;

    std::cin >> upper_limit >> skip;

    for (long long int iii=1; iii<=upper_limit;iii++){
        storage.insert(iii);
    }

    long long int iii = skip;
    while (!storage.empty()){
        iii = iii % storage.size();
        auto x = *storage.find_by_order(iii);
        if (x != 0){std::cout << x << " ";
        storage.erase(x);}
        iii += skip;
    }

    return 0;
}