//
// Copyright Antoine Leblanc 2010 - 2014
// Distributed under the MIT license.
//
// http://nauths.fr
// http://github.com/nicuveo
// mailto://antoine.jp.leblanc@gmail.com
//



#ifndef TOOLS_PP_ARRAY_LOWER_BOUND_HH_
# define TOOLS_PP_ARRAY_LOWER_BOUND_HH_



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Includes

# include <boost/preprocessor/comparison/less.hpp>
# include <boost/preprocessor/array/elem.hpp>
# include <boost/preprocessor/array/size.hpp>
# include <boost/preprocessor/tuple/elem.hpp>
# include <boost/preprocessor/while.hpp>
# include <boost/preprocessor/inc.hpp>
# include <boost/preprocessor/cat.hpp>
# include <boost/preprocessor/if.hpp>

# include "discard.hh"



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Declarations

/*
** Finds the lower bound of a given element in a given PP_ARRAY.
** Return value is the index of the lower bound is the array.
** The array is considered sorted.
** _D variants use the next available PP_WHILE iteration
** For examples, see unit tests below.
*/

# define TOOLS_PP_ARRAY_LOWER_BOUND(     A, E) TOOLS_PP_ALB_INDEX(BOOST_PP_WHILE(                  TOOLS_PP_ALB_PRED, TOOLS_PP_ALB_OP, (A, E, 0)))
# define TOOLS_PP_ARRAY_LOWER_BOUND_D(D, A, E) TOOLS_PP_ALB_INDEX(BOOST_PP_CAT(BOOST_PP_WHILE_, D)(TOOLS_PP_ALB_PRED, TOOLS_PP_ALB_OP, (A, E, 0)))



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Implementation

# define TOOLS_PP_ALB_ARRAY_ELEM_IMPLEM(D, A, S, I) BOOST_PP_IF(BOOST_PP_LESS_D(D, I, S), BOOST_PP_ARRAY_ELEM, TOOLS_PP_DISCARD_MAX_2)(I, A)

# define TOOLS_PP_ALB_ARRAY_ELEM(D, S) TOOLS_PP_ALB_ARRAY_ELEM_IMPLEM(D, TOOLS_PP_ALB_ARRAY(S), TOOLS_PP_ALB_ARRAY_SIZE(S), TOOLS_PP_ALB_INDEX(S))
# define TOOLS_PP_ALB_ARRAY_SIZE(S)    BOOST_PP_ARRAY_SIZE(TOOLS_PP_ALB_ARRAY(S))
# define TOOLS_PP_ALB_ARRAY(S)         BOOST_PP_TUPLE_ELEM(3, 0, S)
# define TOOLS_PP_ALB_BOUND(S)         BOOST_PP_TUPLE_ELEM(3, 1, S)
# define TOOLS_PP_ALB_INDEX(S)         BOOST_PP_TUPLE_ELEM(3, 2, S)

# define TOOLS_PP_ALB_PRED(D, S) BOOST_PP_LESS_D(D, TOOLS_PP_ALB_ARRAY_ELEM(D, S), TOOLS_PP_ALB_BOUND(S))
# define TOOLS_PP_ALB_OP(D, S) (TOOLS_PP_ALB_ARRAY(S), TOOLS_PP_ALB_BOUND(S), BOOST_PP_INC(TOOLS_PP_ALB_INDEX(S)))



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Unit tests

# if TOOLS_PP_UNIT_TESTS

#  define TEST_ALB_0 ( 0, ())
#  define TEST_ALB_1 ( 1, (1))
#  define TEST_ALB_2 ( 2, (1, 2))
#  define TEST_ALB_3 ( 3, (1, 2, 3))
#  define TEST_ALB_4 ( 3, (1, 1, 1))

TEST: TOOLS_PP_ARRAY_LOWER_BOUND(TEST_ALB_0, 0) == 0
TEST: TOOLS_PP_ARRAY_LOWER_BOUND(TEST_ALB_0, 1) == 0

TEST: TOOLS_PP_ARRAY_LOWER_BOUND(TEST_ALB_1, 0) == 0
TEST: TOOLS_PP_ARRAY_LOWER_BOUND(TEST_ALB_1, 1) == 0
TEST: TOOLS_PP_ARRAY_LOWER_BOUND(TEST_ALB_1, 2) == 1

TEST: TOOLS_PP_ARRAY_LOWER_BOUND(TEST_ALB_2, 0) == 0
TEST: TOOLS_PP_ARRAY_LOWER_BOUND(TEST_ALB_2, 1) == 0
TEST: TOOLS_PP_ARRAY_LOWER_BOUND(TEST_ALB_2, 2) == 1
TEST: TOOLS_PP_ARRAY_LOWER_BOUND(TEST_ALB_2, 3) == 2

TEST: TOOLS_PP_ARRAY_LOWER_BOUND(TEST_ALB_3, 0) == 0
TEST: TOOLS_PP_ARRAY_LOWER_BOUND(TEST_ALB_3, 1) == 0
TEST: TOOLS_PP_ARRAY_LOWER_BOUND(TEST_ALB_3, 2) == 1
TEST: TOOLS_PP_ARRAY_LOWER_BOUND(TEST_ALB_3, 3) == 2
TEST: TOOLS_PP_ARRAY_LOWER_BOUND(TEST_ALB_3, 4) == 3

TEST: TOOLS_PP_ARRAY_LOWER_BOUND(TEST_ALB_4, 0) == 0
TEST: TOOLS_PP_ARRAY_LOWER_BOUND(TEST_ALB_4, 1) == 0
TEST: TOOLS_PP_ARRAY_LOWER_BOUND(TEST_ALB_4, 2) == 3

# endif



#endif /* !TOOLS_PP_ARRAY_LOWER_BOUND_HH_ */
