//
// Copyright Antoine Leblanc 2010 - 2014
// Distributed under the MIT license.
//
// http://nauths.fr
// http://github.com/nicuveo
// mailto://antoine.jp.leblanc@gmail.com
//



#ifndef TOOLS_PP_ARRAY_SORT_HH_
# define TOOLS_PP_ARRAY_SORT_HH_



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Includes

# include <boost/preprocessor/comparison/less.hpp>
# include <boost/preprocessor/array/insert.hpp>
# include <boost/preprocessor/array/elem.hpp>
# include <boost/preprocessor/array/size.hpp>
# include <boost/preprocessor/tuple/elem.hpp>
# include <boost/preprocessor/while.hpp>
# include <boost/preprocessor/inc.hpp>
# include <boost/preprocessor/cat.hpp>
# include <boost/preprocessor/if.hpp>

# include "array_lower_bound.hh"



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Declarations

/*
** Sorts the given PP_ARRAY.
** _U variants remove duplicates.
** _D variants use the next available PP_WHILE iteration
** For examples, see unit tests below.
*/

# define TOOLS_PP_ARRAY_SORT(A)        TOOLS_PP_AS_RES(BOOST_PP_WHILE(                  TOOLS_PP_AS_PRED, TOOLS_PP_AS_OP,   (A, 0, (0, ()))))
# define TOOLS_PP_ARRAY_SORT_U(A)      TOOLS_PP_AS_RES(BOOST_PP_WHILE(                  TOOLS_PP_AS_PRED, TOOLS_PP_AS_OP_U, (A, 0, (0, ()))))
# define TOOLS_PP_ARRAY_SORT_D(D, A)   TOOLS_PP_AS_RES(BOOST_PP_CAT(BOOST_PP_WHILE_, D)(TOOLS_PP_AS_PRED, TOOLS_PP_AS_OP,   (A, 0, (0, ()))))
# define TOOLS_PP_ARRAY_SORT_U_D(D, A) TOOLS_PP_AS_RES(BOOST_PP_CAT(BOOST_PP_WHILE_, D)(TOOLS_PP_AS_PRED, TOOLS_PP_AS_OP_U, (A, 0, (0, ()))))



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Workarounds

/*
** Boost 1.49.0 lacks BOOST_PP_TUPLE_REM_0.
** PP_ARRAY_INSERT documentation examples do not work...
*/

# ifndef BOOST_PP_TUPLE_REM_0
#  define BOOST_PP_TUPLE_REM_0()
# endif



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Implementation

# define TOOLS_PP_AS_LB(D, S) TOOLS_PP_ARRAY_LOWER_BOUND_D(D, TOOLS_PP_AS_RES(S), TOOLS_PP_AS_ARRAY_ELEM(S))

# define TOOLS_PP_AS_ARRAY_ELEM(S)  BOOST_PP_ARRAY_ELEM(TOOLS_PP_AS_INDEX(S), TOOLS_PP_AS_ARRAY(S))
# define TOOLS_PP_AS_ARRAY_SIZE(S)  BOOST_PP_ARRAY_SIZE(TOOLS_PP_AS_ARRAY(S))
# define TOOLS_PP_AS_ARRAY(S)       BOOST_PP_TUPLE_ELEM(3, 0, S)
# define TOOLS_PP_AS_INDEX(S)       BOOST_PP_TUPLE_ELEM(3, 1, S)
# define TOOLS_PP_AS_RES(S)         BOOST_PP_TUPLE_ELEM(3, 2, S)

# define TOOLS_PP_AS_MERGE(  D, E, R, P) BOOST_PP_ARRAY_INSERT_D(D, R, P, E)
# define TOOLS_PP_AS_MERGE_R(D, E, R, P) BOOST_PP_IF(BOOST_PP_LESS(E, BOOST_PP_ARRAY_ELEM(P, R)), TOOLS_PP_AS_MERGE(D, E, R, P), R)
# define TOOLS_PP_AS_MERGE_U(D, E, R, P) BOOST_PP_IF(BOOST_PP_LESS(P, BOOST_PP_ARRAY_SIZE(R)), TOOLS_PP_AS_MERGE_R, TOOLS_PP_AS_MERGE)(D, E, R, P)

# define TOOLS_PP_AS_PRED(D, S) BOOST_PP_LESS_D(D, TOOLS_PP_AS_INDEX(S), TOOLS_PP_AS_ARRAY_SIZE(S))
# define TOOLS_PP_AS_OP(  D, S) (TOOLS_PP_AS_ARRAY(S), BOOST_PP_INC(TOOLS_PP_AS_INDEX(S)), TOOLS_PP_AS_MERGE  (D, TOOLS_PP_AS_ARRAY_ELEM(S), TOOLS_PP_AS_RES(S), TOOLS_PP_AS_LB(D, S)))
# define TOOLS_PP_AS_OP_U(D, S) (TOOLS_PP_AS_ARRAY(S), BOOST_PP_INC(TOOLS_PP_AS_INDEX(S)), TOOLS_PP_AS_MERGE_U(D, TOOLS_PP_AS_ARRAY_ELEM(S), TOOLS_PP_AS_RES(S), TOOLS_PP_AS_LB(D, S)))



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Unit tests

# if TOOLS_PP_UNIT_TESTS

#  define TEST_AS_0 ( 1, (1))
#  define TEST_AS_1 ( 2, (1, 2))
#  define TEST_AS_2 ( 2, (2, 1))
#  define TEST_AS_3 ( 2, (2, 2))
#  define TEST_AS_4 (12, (2, 1, 1, 4, 3, 5, 12, 6, 0, 4, 5, 3))
#  define TEST_AS_5 ( 0, ())

TEST: TOOLS_PP_ARRAY_SORT(TEST_AS_0)   == (1, (1))
TEST: TOOLS_PP_ARRAY_SORT(TEST_AS_1)   == (2, (1, 2))
TEST: TOOLS_PP_ARRAY_SORT(TEST_AS_2)   == (2, (1, 2))
TEST: TOOLS_PP_ARRAY_SORT(TEST_AS_3)   == (2, (2, 2))
TEST: TOOLS_PP_ARRAY_SORT(TEST_AS_4)   == (12, (0, 1, 1, 2, 3, 3, 4, 4, 5, 5, 6, 12))
TEST: TOOLS_PP_ARRAY_SORT(TEST_AS_5)   == (0, ())
TEST: TOOLS_PP_ARRAY_SORT_U(TEST_AS_0) == (1, (1))
TEST: TOOLS_PP_ARRAY_SORT_U(TEST_AS_1) == (2, (1, 2))
TEST: TOOLS_PP_ARRAY_SORT_U(TEST_AS_2) == (2, (1, 2))
TEST: TOOLS_PP_ARRAY_SORT_U(TEST_AS_3) == (1, (2))
TEST: TOOLS_PP_ARRAY_SORT_U(TEST_AS_4) == (8, (0, 1, 2, 3, 4, 5, 6, 12))
TEST: TOOLS_PP_ARRAY_SORT_U(TEST_AS_5) == (0, ())

# endif



#endif /* !TOOLS_PP_ARRAY_SORT_HH_ */
