//
// array_cat.hh for tools
// Made by nicuveo <crucuny@gmail.com>
//

#ifndef TOOLS_PP_ARRAY_CAT_HH_
# define TOOLS_PP_ARRAY_CAT_HH_



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Includes

# include <boost/preprocessor/array/push_back.hpp>
# include <boost/preprocessor/array/pop_front.hpp>
# include <boost/preprocessor/array/elem.hpp>
# include <boost/preprocessor/tuple/elem.hpp>
# include <boost/preprocessor/tuple/elem.hpp>
# include <boost/preprocessor/while.hpp>
# include <boost/preprocessor/cat.hpp>



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Declarations

/*
** Concatenates two PP_ARRAYs.
** _D variant uses the next available PP_WHILE iteration
** For examples, see unit tests below.
*/

# define TOOLS_PP_ARRAY_CAT(     A1, A2) TOOLS_PP_AC_1(                  BOOST_PP_WHILE(TOOLS_PP_AC_PRED, TOOLS_PP_AC_OP, (A1, A2)))
# define TOOLS_PP_ARRAY_CAT_D(D, A1, A2) TOOLS_PP_AC_1(BOOST_PP_CAT(BOOST_PP_WHILE_, D)(TOOLS_PP_AC_PRED, TOOLS_PP_AC_OP, (A1, A2)))



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Implementation

# define TOOLS_PP_AC_1(S) BOOST_PP_TUPLE_ELEM(2, 0, S)
# define TOOLS_PP_AC_2(S) BOOST_PP_TUPLE_ELEM(2, 1, S)
# define TOOLS_PP_AC_PRED(D, S) BOOST_PP_ARRAY_SIZE(TOOLS_PP_AC_2(S))
# define TOOLS_PP_AC_OP(  D, S) (BOOST_PP_ARRAY_PUSH_BACK(TOOLS_PP_AC_1(S), BOOST_PP_ARRAY_ELEM(0, TOOLS_PP_AC_2(S))), BOOST_PP_ARRAY_POP_FRONT(TOOLS_PP_AC_2(S)))



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Unit tests

# if TOOLS_PP_UNIT_TESTS

#  define TEST_0 ( 1, (1))
#  define TEST_1 ( 2, (1, 2))
#  define TEST_2 ( 2, (2, 1))
#  define TEST_3 ( 2, (2, 2))
#  define TEST_4 (12, (2, 1, 1, 4, 3, 5, 12, 6, 0, 4, 5, 3))
#  define TEST_5 ( 0, ())

TEST: TOOLS_PP_ARRAY_CAT(TEST_0, TEST_5) == (1, (1))
TEST: TOOLS_PP_ARRAY_CAT(TEST_3, TEST_2) == (4, (2, 2, 2, 1))

# endif



#endif /* !TOOLS_PP_ARRAY_CAT_HH_ */
