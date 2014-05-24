#! /usr/bin/env bash

for header in "$(dirname $0)"/../include/*/*/*.hh ; do
    CODE=`cpp -D TOOLS_PP_UNIT_TESTS $header | tr -d ' ' | sed -n 's/^TEST://p'`
    TESTS_N=0
    TESTS_R=0
    for line in $CODE; do
        a=`echo $line | sed -n 's/\(.*\)==\(.*\)/_\1_/p'`
        b=`echo $line | sed -n 's/\(.*\)==\(.*\)/_\2_/p'`
        if [ "$a" == "$b"  -a ! -z "$a" ] ; then
            TESTS_R=$(( $TESTS_R + 1 ))
        fi
        TESTS_N=$(( $TESTS_N + 1 ))
    done
    printf "%-32s" $(basename "$header")
    if [ "$TESTS_R" -eq "$TESTS_N" ] ; then
        echo -ne "[\033[1;32mOK\033[0m]"
    else
        echo -ne "[\033[1;31mKO\033[0m]"
    fi
    printf " (%2s / %2s)" "$TESTS_R" "$TESTS_N"
    echo
done
