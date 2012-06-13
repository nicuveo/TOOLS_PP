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

// # define TOOLS_PP_DISCARD(...)
// # define TOOLS_PP_DISCARD_MIN(...) 0
// # define TOOLS_PP_DISCARD_MAX(...) BOOST_PP_LIMIT_MAG

# define TOOLS_PP_DISCARD_1(a)
# define TOOLS_PP_DISCARD_2(a, b)
# define TOOLS_PP_DISCARD_3(a, b, c)
# define TOOLS_PP_DISCARD_4(a, b, c, d)
# define TOOLS_PP_DISCARD_5(a, b, c, d, e)
# define TOOLS_PP_DISCARD_6(a, b, c, d, e, f)
# define TOOLS_PP_DISCARD_7(a, b, c, d, e, f, g)
# define TOOLS_PP_DISCARD_8(a, b, c, d, e, f, g, h)
# define TOOLS_PP_DISCARD_9(a, b, c, d, e, f, g, h, i)

# define TOOLS_PP_DISCARD_MIN_1(a)                         0
# define TOOLS_PP_DISCARD_MIN_2(a, b)                      0
# define TOOLS_PP_DISCARD_MIN_3(a, b, c)                   0
# define TOOLS_PP_DISCARD_MIN_4(a, b, c, d)                0
# define TOOLS_PP_DISCARD_MIN_5(a, b, c, d, e)             0
# define TOOLS_PP_DISCARD_MIN_6(a, b, c, d, e, f)          0
# define TOOLS_PP_DISCARD_MIN_7(a, b, c, d, e, f, g)       0
# define TOOLS_PP_DISCARD_MIN_8(a, b, c, d, e, f, g, h)    0
# define TOOLS_PP_DISCARD_MIN_9(a, b, c, d, e, f, g, h, i) 0

# define TOOLS_PP_DISCARD_MAX_1(a)                         BOOST_PP_LIMIT_MAG
# define TOOLS_PP_DISCARD_MAX_2(a, b)                      BOOST_PP_LIMIT_MAG
# define TOOLS_PP_DISCARD_MAX_3(a, b, c)                   BOOST_PP_LIMIT_MAG
# define TOOLS_PP_DISCARD_MAX_4(a, b, c, d)                BOOST_PP_LIMIT_MAG
# define TOOLS_PP_DISCARD_MAX_5(a, b, c, d, e)             BOOST_PP_LIMIT_MAG
# define TOOLS_PP_DISCARD_MAX_6(a, b, c, d, e, f)          BOOST_PP_LIMIT_MAG
# define TOOLS_PP_DISCARD_MAX_7(a, b, c, d, e, f, g)       BOOST_PP_LIMIT_MAG
# define TOOLS_PP_DISCARD_MAX_8(a, b, c, d, e, f, g, h)    BOOST_PP_LIMIT_MAG
# define TOOLS_PP_DISCARD_MAX_9(a, b, c, d, e, f, g, h, i) BOOST_PP_LIMIT_MAG



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Unit tests

# if TOOLS_PP_UNIT_TESTS

TEST: TOOLS_PP_DISCARD_1(a)              ==
TEST: TOOLS_PP_DISCARD_2(a, b)           ==
TEST: TOOLS_PP_DISCARD_3(a, b, c)        ==
TEST: TOOLS_PP_DISCARD_4(a, b, c, d)     ==

TEST: TOOLS_PP_DISCARD_MIN_1(a)          == 0
TEST: TOOLS_PP_DISCARD_MIN_2(a, b)       == 0
TEST: TOOLS_PP_DISCARD_MIN_3(a, b, c)    == 0
TEST: TOOLS_PP_DISCARD_MIN_4(a, b, c, d) == 0

TEST: TOOLS_PP_DISCARD_MAX_1(a)          == BOOST_PP_LIMIT_MAG
TEST: TOOLS_PP_DISCARD_MAX_2(a, b)       == BOOST_PP_LIMIT_MAG
TEST: TOOLS_PP_DISCARD_MAX_3(a, b, c)    == BOOST_PP_LIMIT_MAG
TEST: TOOLS_PP_DISCARD_MAX_4(a, b, c, d) == BOOST_PP_LIMIT_MAG

# endif



#endif /* !TOOLS_PP_DISCARD_HH_ */
