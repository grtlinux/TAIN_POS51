#!/bin/ksh
#
# Ignore  HUP, INT, QUIT now.
# trap "" 1 2 3 15

#---------------------------------------------------
#

DATETIME=`/bin/date "+%Y/%m/%d %H:%M:%S"`

USERID=$USER
HOME_DIR=/hw01/ibridge/KANG/pos51

#---------------------------------------------------
#
func_usage()
{
	/bin/echo "STATUS : usage function"
}

#---------------------------------------------------
#
func_test()
{
	/bin/echo "STATUS : test function"
}

#---------------------------------------------------
#
func_real()
{
	/bin/echo "STATUS : real function"
}

#===================================================
#===================================================
echo "START : $0"

if [ $# -eq 0 ]; then
	func_usage
else
	CMD=`/bin/echo ${1} | /usr/bin/tr 'a-z' 'A-Z'`
	
	case ${CMD} in
		"RUN" | "REAL" )
			func_real
			;;
		"TEST" )
			func_test
			;;
		* )
			func_usage
			;;
	esac

fi


