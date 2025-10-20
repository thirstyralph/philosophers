# Philosophers
A deadly concurrency practice.

# Description
This program is a spin of the classical dining philosophers problem.
N number of philosophers sit on a round table, each with his corresponding
fork, but in order to eat they need to grab two forks, their own and the one
on their left. The programer must simulate this situation avoiding deadlocks.

# Program flow
0. Main calls philo();
1. init().	Arguments get parsed, if they are incorrect, 1 is returned;
			if they are correct, conf and app are alloc'd and returned (app points to conf).


