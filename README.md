# TOOLS_PP

*TOOLS_PP* is a small collection of preprocessor tools built on top of
*BOOST_PP* (hence the name). It includes:

* `TOOLS_PP_ARRAY_CAT`: concatenates two *BOOST_PP* arrays;
* `TOOLS_PP_ARRAY_LOWER_BOUND`: finds the index of the lower bound of an item in a given array;
* `TOOLS_PP_ARRAY_SORT`: sorts the given array;
* `TOOLS_PP_ARRAY_SORT_U`: sorts the given array and remove duplicates.

All of them also have a _D variant that takes and uses the next available `BOOST_PP_WHILE` iteration.
