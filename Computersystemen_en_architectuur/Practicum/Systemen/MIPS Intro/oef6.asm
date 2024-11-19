	.data
pi: .float 3.14
	.text
main:
	# radius input from user
	li $v0, 6 # user radius input as float
	syscall # reads input and puts in f0
	j circleSurface
circleSurface:
	mul.s $f1, $f0, $f0 # radius^2 in f1
	lwc1 $f2, pi # load pi
	mul.s $f12, $f1, $f2 # radius^2 * pi == surface of the circle (f2)
	
	li $v0, 2 # print float
	syscall # print float
	
	# exit
	li $v0, 10 # syscall for exit
	syscall