	.data
	.type	v, %object
	.type   n, %object
	.size	v, 8
	.size   n, 1

n:
   .xword 8

v:
	.xword 79, 55, 94, 48, 19, 13, 45, 21

	.text
	.global main
	.global smallest
	.global biggest
	.global swap
	.arch armv8-a+fp+simd
	.type main, %function
	.type smallest, %function
	.type larger, %function
	.type swap, %function
smallest:
    MOV X9,X1
    MOV X10,X2
    LSL X11,X9,#3
    ADD X11,X11,X0
    LDUR X12,[X11,#0]
    MOV X3,X9
loopsmallest:
    CMP X9, X10
    B.GE goback
    LDUR X13,[X11,#0]
    CMP X12,X13
    B.LE skipsmall
    MOV X12,X13
    MOV X3,X9
skipsmall:
    ADD X9, X9, #1
    ADD X11, X11, #8
    B loopsmallest
goback:
    BR X30
larger:
    MOV X9,X1
    MOV X10,X2
    LSL X11,X9,#3
    ADD X11,X11,X0
    LDUR X12,[X11,#0]
    MOV X3,X9
loopslarger:
    CMP X9, X10
    B.GE return
    LDUR X13, [X11,#0]
    CMP X12,X13
    B.GE skiplarger
    MOV X12, X13
    MOV X3, X9
skiplarger:
    ADD X9, X9, #1
    ADD X11, X11, #8
    B loopslarger
return:
    BR X30
swap:
    LSL X9, X3, #3
    ADD X9, X9, X0
    LSL X10, X4, #3
    ADD X10, X10, X0
    LDUR X11, [X9,#0]
    LDUR X12,[X10,#0]
    STUR X11,  [X10,#0]
    STUR X12, [X9,#0]
    BR X30
main:
	ADRP X0, v
	ADD X0, X0, :lo12:v
	SUB X2, X2, X2
	ADD X2, X2, #8
	SUB X1, X1, X1
loop:
    CMP X1, X2
    B.GE exit
    BL smallest
    MOV X4, X1
    BL swap
    BL larger
    SUB X4, X2, #1
    BL swap
    ADD X1, X1, #1
    SUB X2, X2, #1
    B loop
exit:
