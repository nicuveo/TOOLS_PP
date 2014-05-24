#
# Copyright Antoine Leblanc 2010 - 2013
# Distributed under the MIT license.
#
# http://nauths.fr
# http://github.com/nicuveo
# mailto://antoine.jp.leblanc@gmail.com
#



# MAIN

PROJ = tools_pp
SUB_DIRS = check

$(PROJ): all



# VARIABLES

CLEAN += '*~' '\#*' '.\#*' '.DS_Store' '.gdb_history' '*.stackdump' \
'.gdb_history' 'gmon.out' '*.dSYM'



# ALL

all: $(TARGETS)

install: all
	@if [ -x ./install ] ; then ./install "$(PREFIX)" ; else		\
	    find include -type f \! -path '*.svn*' 			        \
                -exec install -v -m 644 "{}" -D "$(PREFIX)/{}" \;;		\
	fi



# DISPATCH

sub_call_func = (cd ./$1 && $2)
sub_call_rule = $(call sub_call_func,$1,$(MAKE) $2)
define sub_make_rule
$1: all
	$(call sub_call_rule,$1,all)
endef

$(foreach sub,$(SUB_DIRS),$(eval $(call sub_make_rule,$(sub))))


clean: do_clean
	$(foreach sub,$(SUB_DIRS),$(call sub_call_rule,$(sub), clean);)

distclean: do_distclean
	$(foreach sub,$(SUB_DIRS),$(call sub_call_rule,$(sub), distclean);)



# CLEAN

do_clean:
	for f in ${CLEAN} ; do find . -name "$$f" | xargs rm -Rfv ; done

do_distclean: do_clean



# SPECIALS

.PHONY: $(SUB_DIRS)
