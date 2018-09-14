#!/bin/sh

GREEN=$(tput setaf 2)
RED=$(tput setaf 1)
CLR=$(tput sgr 0)

CLEAR='\e[0m'
FAIL=${RED}'FAIL'${CLR}
PASS=${GREEN}'PASS'${CLR}

print_test()
{
	printf "   %-45s%s\n" "$TEST" "$RES"
}

print_vb()
{
	printf "   %-45s%s%5s\n" "$TEST" "$RES" "$COUNT"
}

if [ -a push_swap ];
then
	echo ${CLR}'Testing push_swap\n'

	echo 'Invalid ARGUMENTS'
	TEST="Letters in imput"
	RET=`./push_swap "1 2 a" 2>&1`
	if [ "$RET" == "Error" ] || [ "${OUTP}" == "error" ]
	then
		RES="$PASS"
	else
		RES="$FAIL"
	fi
	print_test

	TEST="Double numbers"
	RET=`./push_swap "1 2 2" 2>&1`
	if [ "$RET" == "Error" ] || [ "${OUTP}" == "error" ]
	then
		RES="$PASS"
	else
		RES="$FAIL"
	fi
	print_test

	TEST="Greater than max int"
	RET=`./push_swap "0 2 23410236541 5" 2>&1`
	if [ "$RET" == "Error" ] || [ "${OUTP}" == "error" ]
	then
		RES="$PASS"
	else
		RES="$FAIL"
	fi
	print_test

	echo ${CLR}'SORTED SETS'

	TEST="[42]"
	RET=`./push_swap "42"`
	if [ "$RET" == "" ]
	then
		RES="$PASS"
	else
		RES="$FAIL"
	fi
	print_test

	TEST="[0 1 2 3]"
	RET=`./push_swap "0 1 2 3"`
	if [ "$RET" == "" ]
	then
		RES="$PASS"
	else
		RES="$FAIL"
	fi
	print_test

	TEST="[0 1 2 3 4 5 6 7 8 9]"
	RET=`./push_swap "0 1 2 3 4 5 6 7 8 9"`
	if [ "$RET" == "" ]
	then
		RES="$PASS"
	else
		RES="$FAIL"
	fi
	print_test

	echo ${CLR}'SIMPLE SORT'

	TEST="[2 1 0]"
	ARG="2 1 0"
	RET=`./push_swap $ARG | ./checker $ARG`
	COUNT=`./push_swap $ARG | wc -l`
	if [ $RET == "OK" ] && [ $COUNT -le 3 ]
	then
		RES="$PASS"
	else
		RES="$FAIL"
	fi
	print_vb

	for i in range {0..9}
	do
		ARG=`ruby -e "puts (0..4).to_a.shuffle.join(' ')"`
		TEST="[$ARG]"
		RET=`./push_swap $ARG | ./checker $ARG`
		COUNT=`./push_swap $ARG | wc -l`
		if [ $RET == "OK" ] && [ $COUNT -le 12 ]
		then
			RES="$PASS"
		else
			RES="$FAIL"
		fi
		print_vb
	done

	echo ${CLR}'MIDDLE SORT'

	TEST=${CLR}'Average in range (0 to 99)'
	TOTAL=0
	for i in range {1..99}
		do 
			ARG=`ruby -e "puts (0..99).to_a.shuffle.join(' ')"`
			RET=`./push_swap $ARG | wc -l`
			TOTAL=`expr $RET + $TOTAL`
	done
	COUNT=`expr $TOTAL / 100`
	if [ $COUNT -lt 1500 ]
	then
		RES="$PASS"
	else
		RES="$FAIL"	
	fi
	print_vb

	echo ${CLR}'ADVANCED SORT'

	TOTAL=0

	TEST=${CLR}'Average in range (0 to 499)'
	ERR=0
	for i in range {1..99}
		do 
			ARG=`ruby -e "puts (0..499).to_a.shuffle.join(' ')"`
			RET=`./push_swap $ARG | wc -l`
			TOTAL=`expr $RET + $TOTAL`
	done
	COUNT=`expr $TOTAL / 100`
	if [ $COUNT -lt 11500 ]
	then
		RES="$PASS"
	else
		RES="$FAIL"	
	fi
	print_vb

else
	echo $CLR'push_swap not found!'
fi
