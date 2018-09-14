#!/bin/sh

GREEN=$(tput setaf 2)
RED=$(tput setaf 1)
CLR=$(tput sgr 0)

CLEAR='\e[0m'
FAIL=${RED}'FAIL'${CLR}
PASS=${GREEN}'PASS'${CLR}

print_test()
{
	printf "   %-45s%-10s\n" "$TEST" "$RES"
}

if [ -a checker ];
then
	echo ${CLR}'Testing checker\n'

	echo 'Invalid ARGUMENTS'
	TEST="Letters in imput"
	RET=`./checker "1 2 a" 2>&1`
	if [ "$RET" == "Error" ] || [ "${OUTP}" == "error" ]
	then
		RES="$PASS"
	else
		RES="$FAIL"
	fi
	print_test

	TEST="Double numbers"
	RET=`./checker "1 2 2" 2>&1`
	if [ "$RET" == "Error" ] || [ "${OUTP}" == "error" ]
	then
		RES="$PASS"
	else
		RES="$FAIL"
	fi
	print_test

	TEST="Greater than max int"
	RET=`./checker "0 2 23410236541 5" 2>&1`
	if [ "$RET" == "Error" ] || [ "${OUTP}" == "error" ]
	then
		RES="$PASS"
	else
		RES="$FAIL"
	fi
	print_test

	echo "\nInvalid INSTRUCTIONS"

	TEST="Instruction : \"abc\""
	RET=`echo "abc" |./checker "2 3 4 1" 2>&1`
	if [ "$RET" == "Error" ] || [ "${OUTP}" == "error" ]
	then
		RES="$PASS"
	else
		RES="$FAIL"
	fi
	print_test

	TEST="Instruction : \"rrrr\""
	RET=`echo "rrrr" |./checker "2 3 4 1" 2>&1`
	if [ "$RET" == "Error" ] || [ "${OUTP}" == "error" ]
	then
		RES="$PASS"
	else
		RES="$FAIL"
	fi
	print_test

	TEST="Instruction : \"sasa\""
	RET=`echo "sasa" |./checker "2 3 4 1" 2>&1`
	if [ "$RET" == "Error" ] || [ "${OUTP}" == "error" ]
	then
		RES="$PASS"
	else
		RES="$FAIL"
	fi
	print_test

	TEST="Instruction : \" pb\""
	RET=`echo " pb" |./checker "2 3 4 1" 2>&1`
	if [ "$RET" == "Error" ] || [ "${OUTP}" == "error" ]
	then
		RES="$PASS"
	else
		RES="$FAIL"
	fi
	print_test

	TEST="Instruction : \"ra \""
	RET=`echo "ra " |./checker "2 3 4 1" 2>&1`
	if [ "$RET" == "Error" ] || [ "${OUTP}" == "error" ]
	then
		RES="$PASS"
	else
		RES="$FAIL"
	fi
	print_test

	echo "\nFAILED Tests"

	TEST="\"0 9 1 8 2 7 3 6 4 5\" [sa, pb, rrr]"
	RET=`echo "sa\npb\nrrr" | ./checker "0 9 1 8 2 7 3 6 4 5" 2>&1`
	if [ $RET == "KO" ]
	then
		RES="$PASS"
	else
		RES="$FAIL"
	fi
	print_test
	
	TEST="\"0 2 1\" [pb, sa]"
	RET=`echo "pb\nsa" | ./checker "0 2 1" 2>&1`
	if [ $RET == "KO" ]
	then
		RES="$PASS"
	else
		RES="$FAIL"
	fi
	print_test

	TEST="\"0 1 2\" [pb, sa]"
	RET=`echo "pb\nsa" | ./checker "0 1 2" 2>&1`
	if [ $RET == "KO" ]
	then
		RES="$PASS"
	else
		RES="$FAIL"
	fi
	print_test

	echo "\nPASS Tests"

	TEST="\"0 1 2\" []"
	touch __empty
	RET=`cat empty | ./checker "0 1 2" 2>&1`
	if [ $RET == "OK" ]
	then
		RES="$PASS"
	else
		RES="$FAIL"
	fi
	print_test
	rm __empty

	TEST="\"0 9 1 8 2\" [pb, ra, pb, ra, sa, ra, pa, pa]"
	RET=`echo "pb\nra\npb\nra\nsa\nra\npa\npa" | ./checker "0 9 1 8 2" 2>&1`
	if [ $RET == "OK" ]
	then
		RES="$PASS"
	else
		RES="$FAIL"
	fi
	print_test

	TEST="\"4 3 2 1\" [pb, pb, ss, pa, pa, ra, ra]"
	RET=`echo "pb\npb\nss\npa\npa\nra\nra" | ./checker "4 3 2 1" 2>&1`
	if [ $RET == "OK" ]
	then
		RES="$PASS"
	else
		RES="$FAIL"
	fi
	print_test

else
	echo $CLR'Checker not found!'
fi
