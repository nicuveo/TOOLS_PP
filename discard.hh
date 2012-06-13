//
// discard.hh for tools
// Made by nicuveo <crucuny@gmail.com>
//

#ifndef TOOLS_PP_DISCARD_HH_
# define TOOLS_PP_DISCARD_HH_



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Includes

# include <boost/preprocessor/config/limits.hpp>



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Declarations

# define TOOLS_PP_DISCARD(...)
# define TOOLS_PP_DISCARD_MIN(...) 0
# define TOOLS_PP_DISCARD_MAX(...) BOOST_PP_LIMIT_MAG



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Unit tests

# if TOOLS_PP_UNIT_TESTS

TEST: TOOLS_PP_DISCARD(a)              ==
TEST: TOOLS_PP_DISCARD(a, b)           ==
TEST: TOOLS_PP_DISCARD(a, b, c)        ==
TEST: TOOLS_PP_DISCARD(a, b, c, d)     ==

TEST: TOOLS_PP_DISCARD_MIN(a)          == 0
TEST: TOOLS_PP_DISCARD_MIN(a, b)       == 0
TEST: TOOLS_PP_DISCARD_MIN(a, b, c)    == 0
TEST: TOOLS_PP_DISCARD_MIN(a, b, c, d) == 0

TEST: TOOLS_PP_DISCARD_MAX(a)          == BOOST_PP_LIMIT_MAG
TEST: TOOLS_PP_DISCARD_MAX(a, b)       == BOOST_PP_LIMIT_MAG
TEST: TOOLS_PP_DISCARD_MAX(a, b, c)    == BOOST_PP_LIMIT_MAG
TEST: TOOLS_PP_DISCARD_MAX(a, b, c, d) == BOOST_PP_LIMIT_MAG

# endif



#endif /* !TOOLS_PP_DISCARD_HH_ */