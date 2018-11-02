# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    bonus_verif.sh                                   .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: tduverge <marvin@le-101.fr>                +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/04/11 13:30:18 by tduverge     #+#   ##    ##    #+#        #
#    Updated: 2018/04/11 13:55:14 by tduverge    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

if [ ! -e push_swap ] || [ ! -e checker ]
then
	echo "push_swap or checker does not exist"
elif [ $# -ne 2 ]
then
	echo "usage : ./bonus_verif.sh nb_of_values nb_of_tests"
elif [[ ! $1 =~ ^[0-9]+$ ]] || [[ ! $2 =~ ^[0-9]+$ ]]
then
	echo "error : nb_of_values and nb_of_tests have to be numbers scrictly positive"
elif [ $1 -le 0 ] || [ $2 -le 0 ]
then
	echo "error : nb_of_values and nb_of_tests have to be numbers scrictly positive"
else
	let "NB = 0"
	let "J = 0"
	let "SUM_OK = 0"
	let "SUM_KO = 0"
	let "MIN = -1"
	let "MAX = -1"
	for ((a=$2; a>0; a--))
	do
		ARG="`ruby -e "puts (1..$1).to_a.shuffle.join(' ')"`"
		let "RES = $(./push_swap $ARG | wc -l)"
		let "NB = $NB + $RES"
		OK=$(./push_swap $ARG | ./checker $ARG)
		if [ $OK = "OK" ]
		then
			let "SUM_OK= $SUM_OK + 1"
		else
			let "SUM_KO= $SUM_KO + 1"
		fi
		if [ $MIN = -1 ] || [ $RES -lt $MIN ]
		then
			let "MIN = $RES"
		fi
		if [ $MAX = -1 ] || [ $RES -gt $MAX ]
		then
			let "MAX = $RES"
		fi
	done
	let "NB = $NB / $2"
	if [ $SUM_KO -eq 0 ]
	then
		echo "              \033[42m\033[30mCONGRATULATION !!!\033[0m"
	else
		echo "                     \033[41m\033[30mFAIL\033[0m"
	fi
	echo "\033[1;34mYou have \033[32m$SUM_OK\033[34m success for \033[36m$2\033[34m test(s) and \033[31m$SUM_KO\033[34m fail(s)"
	echo "Your maximum is \033[31m$MAX\033[34m"
	echo "Your average is \033[36m$NB\033[34m"
	echo "Your minimum is \033[32m$MIN\033[0m"
fi
