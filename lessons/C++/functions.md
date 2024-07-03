# C++ Functions

| Function | Header | Format | Description |
|----------|--------|--------|-------------|
| `std::sort`         | `<algorithm>` | `std::sort(first_iterator, last_iterator[, compare_function]);` | Sorts the elements in a range defined by iterators in ascending order using a hybrid of quicksort, heapsort, and insertion sort (introsort). |
| `std::lower_bound`  | `<algorithm>` | `std::vector<int>::iterator it = std::lower_bound(first_iterator, last_iterator, value[, compare_function]);` | Returns the pointer to the first position where an element can be inserted in a sorted range to maintain order. |
| `std::upper_bound`  | `<algorithm>` | `std::vector<int>::iterator it = std::upper_bound(first_iterator, last_iterator, value[, compare_function]);` | Returns the pointer to the position just beyond the last occurrence of an element in a sorted range. |
| `std::equal_range`  | `<algorithm>` | `std::pair<std::vector<int>::iterator, std::vector<int>::iterator> range = std::equal_range(first_iterator, last_iterator, value[, compare_function]);` | Returns pointers the subrange of elements that are equal to the given value in a sorted range. |
| `std::min_element` | `<algorithm>`  | `std::min_element(first_iterator, last_iterator[, compare_function]);` | Returns an iterator pointing to the smallest element in the range defined by the iterators. If the range is empty, the returned iterator is last_iterator. |
