// Time: O(log n) for all queries

// set
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

// find_by_order(k) - returns iterator to kth largest element (0-indexed) or an iterator to end if it doesn't exist
// order_of_key(x) - returns the number of elements in the set strictly smaller than x



// multiset
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

template<typename T>
using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

// find_by_order(k) - returns iterator to kth largest element (0-indexed) or an iterator to end if it doesn't exist
// order_of_key(x) - returns the number of elements in the set strictly smaller than x