default:
	@echo "Please select a program!"
double_conv:
	gcc double_conv.c -o convert
MMM : MMM_computation.c
	gcc -Ofast -o MMM_computation MMM_computation.c -lm -std=c99
dist_loop:
	gcc loopDistribute.c -o loop
clean :
	rm MMM_computation linpack convert *.txt