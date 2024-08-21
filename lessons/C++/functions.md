# C++ Functions

| Function | Header | Format | Description |
|----------|--------|--------|-------------|
| `std::sort`         | `<algorithm>` | `std::sort(first_iterator, last_iterator[, compare_function]);` | Sorts the elements in a range defined by iterators in ascending order using a hybrid of quicksort, heapsort, and insertion sort (introsort). |
| `std::lower_bound`  | `<algorithm>` | `std::vector<int>::iterator it = std::lower_bound(first_iterator, last_iterator, value[, compare_function]);` | Returns the pointer to the first position where an element can be inserted in a sorted range to maintain order. |
| `std::upper_bound`  | `<algorithm>` | `std::vector<int>::iterator it = std::upper_bound(first_iterator, last_iterator, value[, compare_function]);` | Returns the pointer to the position just beyond the last occurrence of an element in a sorted range. |
| `std::equal_range`  | `<algorithm>` | `std::pair<std::vector<int>::iterator, std::vector<int>::iterator> range = std::equal_range(first_iterator, last_iterator, value[, compare_function]);` | Returns pointers the subrange of elements that are equal to the given value in a sorted range. |
| `std::min_element` | `<algorithm>`  | `std::min_element(first_iterator, last_iterator[, compare_function]);` | Returns an iterator pointing to the smallest element in the range defined by the iterators. If the range is empty, the returned iterator is last_iterator. |
| `std::reverse` | `<algorithm>` | `std::reverse(first_iterator, last_iterator);` |Reverses the order of elements in the range defined by the iterators. The range includes the element pointed to by first_iterator and excludes the element pointed to by last_iterator. |
| `std::min_element`  | `<algorithm>` | `std::min_element(first_iterator, last_iterator[, compare_function]);`  | Returns an iterator pointing to the smallest element in the range defined by the iterators. If the range is empty, the returned iterator is last_iterator. |
| `std::max_element`  | `<algorithm>` | `std::max_element(first_iterator, last_iterator[, compare_function]);`  | Returns an iterator pointing to the largest element in the range defined by the iterators. If the range is empty, the returned iterator is last_iterator. |
| `std::vector::insert` | `<vector>` | `vector.insert(position, value);` or `vector.insert(position, count, value);` or `vector.insert(position, first_iterator, last_iterator);` | Inserts elements into the vector before the specified position. Can insert a single value, multiple copies of a value, or a range of elements. |
| `std::advance` | `<iterator>` | `std::advance(iterator, n);` | Advances the iterator by `n` positions. The iterator is modified in place. Useful for moving iterators through containers. |
| `std::next` | `<iterator>` | `std::next(iterator, n);` | Returns a new iterator that is `n` positions ahead of the given iterator. The original iterator remains unchanged. Useful for creating a new iterator from an existing one. |
