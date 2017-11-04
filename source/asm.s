.THUMB				@ turn on thumb
.ALIGN  2			@ no idea why we do this
.GLOBL  add1Number		 
.GLOBL  sub1Number		
.GLOBL  addNumber		@ name of function goes here
.GLOBL  subNumber	
.GLOBL  timer	

@new
.GLOBL  addToTotal		
.GLOBL  subToTotal	
.GLOBL  multiplyNumbers		
.GLOBL  ifEqual		
.GLOBL  ifNotEqual		
.GLOBL  forLoop		
.GLOBL addSprites
.GLOBL ifAlive
.GLOBL statMath
@ ================================== 

.THUMB_FUNC			 
add1Number:			@adds two numbers together and stores the value in r0

push { r4-r7, lr }	
					
						
	ldr r4, [r0]		@ dereference first value into r4 
	ldr r5, [r1]		@ dereference second value into r5
	add r4, r5			@ add r5 to value in r4  
	str r4, [r0] 		@ store data in r4 at r0 address
		
pop { r4-r7 }		 
pop { r3 }			 
bx r3				 

@ ================================== 

.THUMB_FUNC			 
sub1Number:			@subtracts two numbers together and stores the value in r0

push { r4-r7, lr }	 
					
						 
	ldr r4, [r0]		@ dereference first value into r4 
	ldr r5, [r1]		@ dereference second value into r5
	sub r4, r5			@ sub r5 to value in r4  
	str r4, [r0] 		@ store data in r4 at r0 address
		
pop { r4-r7 }		 
pop { r3 }			 
bx r3				 

@ ==================================

.THUMB_FUNC			
addNumber:

push { r4-r7, lr }	
					
						
	ldr r4, [r0]	@load the value of r0 (input variable) into r4
	add r4, #1		@adds 1 from r4
	str r4, [r0] 	@stores the value of r4 back into r0
		
pop { r4-r7 }		
pop { r3 }		
bx r3			

.THUMB_FUNC			
subNumber:

push { r4-r7, lr } 
						
	ldr r4, [r0]		@load the value of r0 (input variable) into r4
	sub r4, #1			@subtract 1 from r4
	str r4, [r0] 		@stores the value of r4 back into r0
		
pop { r4-r7 }		
pop { r3 }			
bx r3				
@ ==================================
	
.THUMB_FUNC			@same as the add function but this continually runs due to where I have used it in the main loop
					
timer:

push { r4-r7, lr }	
					
					
	ldr r4, [r0]		
	add r4, #1			
	str r4, [r0] 		

	
pop { r4-r7 }		
pop { r3 }		
bx r3			
@ ==================================


@"extern void addToTotal(int* x, int* y, int* total);"

.THUMB_FUNC			@ we are about to declare a thumb function
addToTotal:				@ function start

push { r4-r7, lr }	@ push r4-r7 and link register onto stack. Your function might use these
					@ registers, so we need to preserve the values just in case!
					@ we don't need to worry about r0-r3 as it is assumed they will be regularly messed up anyway

@ the magic happens here!
@ r0-r3 will automatically contain the parameters sent when calling the function.

	ldr r4, [r0]		@ hopefully whichever function called this left a memory address in r0 - dereference value into r4
	ldr r5, [r1]		@ loads the variable at address r1 into r5
	add r6, r4, r5		@ uses the register r6, adding together the values of r4/r5 (x/y)
	str r6, [r2] 		@ store data in r6 at r2 address (the total variable)

pop { r4-r7 }		@ pop first 4 values from stack back into r4-r7, and also
pop { r3 }			@ pop the next value from stack (stored value for lr) into some unused register, e.g. r3 -
					@ we cannot overwrite lr so we have to do it via a normal register
bx r3				@ "branch and exchange" (return) back to C, using the previous value for lr stored in r3
@ ==================================
@"extern void subToTotal(int* x, int* y, int* total);"

.THUMB_FUNC			@ we are about to declare a thumb function
subToTotal:				@ function start

push { r4-r7, lr }	

	ldr r4, [r0]		@ loads the variable at address r0 into r4
	ldr r5, [r1]		@ loads the variable at address r1 into r5
	sub r6, r4, r5		@ uses the register r6 to store the result of subtracting the values of r4/r5 (x/y)
	str r6, [r2] 		@ store data in r6 at r2 address (the total variable)

pop { r4-r7 }		@ pop first 4 values from stack back into r4-r7, and also
pop { r3 }			@ pop the next value from stack (stored value for lr) into some unused register, e.g. r3 -
					@ we cannot overwrite lr so we have to do it via a normal register
bx r3				@ "branch and exchange" (return) back to C, using the previous value for lr stored in r3
@ ==================================
@"extern void multiplyNumbers(int* x, int* y, int* total);"

.THUMB_FUNC			
multiplyNumbers:		@multiplies two numbers and returns the result	

push { r4-r7, lr }	

	ldr r4, [r0]		@takes the variable add address r0 (x) and loads it into r4
	ldr r5, [r1] 		@stores the variable in adddress of r1(y) in r5
	mul r4, r5			@ multiples value r4(x) and r5(y) 
	str r4, [r2] 		@ store result in r4 at r2(total) address 

pop { r4-r7 }		
pop { r3 }				
					
bx r3				
@ ==================================

@"extern void ifEqual(int* x, int* y, int* result);"

.THUMB_FUNC			
ifEqual:			@this compares the values x/y and returns the result in r2 (result), this is the basis for the "ifAlive" function below 	
					@not used in code, does work
push { r4-r7, lr }

	mov r6, #1  	@ sets the asm register r6, to #1 this register is used for the result that is passed back to c#
	ldr r4, [r0]	@ loads the variable at address r0 (x) into r4
	ldr r5, [r1]	@ loads the variable at address r1 (y) into r5
	cmp r4, r5 		@ compares the registers r4 and r5
	
	beq endEqual 	@if they are equal, it will jump to the end, if not it will continue running down
	
	mov r6, #0 		@this sets r6 to #0, this indicates that r0/r1(x/y) are not equal
	
	endEqual: 		@if it skips to here, the numbers are equal, if it sets r6 to 0, then they are not equal
	str r6, [r2] 	@stores the value r6 back in the address of r2 (result)
	
pop { r4-r7 }		
pop { r3 }			
					
bx r3				
@ ==================================

@"extern void ifNotEqual(int* x, int* y, int* result);"

.THUMB_FUNC			
ifNotEqual:			@this is the similar to the "ifEqual" function above, except using bne
					@not used in code, does work
push { r4-r7, lr }

	mov r6, #1		@ sets the asm register r6, to #0 this register is used for the result that is passed back to c#
	ldr r4, [r0]	@ loads the variable at address r0 (x) into r4
	ldr r5, [r1]	@ loads the variable at address r1 (y) into r5
	cmp r4, r5		@ compares the registers r4 and r5
	
	bne endNotEqual	@if they are NOT equal, it will jump to the end, if so, it will continue running down
	
	mov r6, #0		@this sets r6 to #1, this indicates that r0/r1(x/y) ARE equal
	
	endNotEqual:	@if it skips to here, the numbers are NOT equal, if it sets r6 to 1, then they are not equal
	str r6, [r2] 	@stores the value r6 back in the address of r2 (result)
	
pop { r4-r7 }		
pop { r3 }			
					
bx r3		
@ ==================================

@"extern void forLoop(int* start, int* Finish, int* result);"

.THUMB_FUNC			
forLoop:			@this for loop does work, this is the basis for the "addSprites" function below
					@not used in code, does work
push { r4-r7, lr }
	
	
	ldr r4, [r0] 	@start of loop (ie i = 0;) - this is also used as the current place in the loop
	ldr r5, [r1] 	@end of the loop (ie i < 10;) 
	ldr r6, [r2] 	@the variable I want to effect, which is the address stored in r2 (result)
	mov r7, #2	 	@this moves #2 into r7, this is just used so that the for loop has something to do (to show it was working)
	startFor: 		@this is where it jumps back to if the numbers are not equal
	
	mul r6, r7		@multiplies r6 (result) by r7 (#2)
	add r4, #1		@add 1 to r4 indicating it has moved another step in the loop
	cmp r4, r5 		@compares the current loop with the end of the loop
	bne startFor

	str r6, [r2] @store the result into the result variable (currently set to r4, just to test it actually loops)
	
pop { r4-r7 }		
pop { r3 }			
					
bx r3	


	@ ==================================

@"extern void addSprites(int* start, int* Finish, int* characterAddress, int *spriteData);"

.THUMB_FUNC			
addSprites:			@this function adds the custom tile set to either the character and sprite sheets, but both are compatible

push { r4-r7, lr }
	
	
	ldr r4, [r0] 	@start of loop (ie i = 0;) - this is also used as the current place in the loop
	ldr r5, [r1] 	@end of the loop (ie i < 10;) 
	
	spriteFor: 		@this is where it jumps back to if the numbers are not equal


	ldr r6, [r3]	@Loads the current value of r3 (spriteData) into r6
	str r6, [r2]	@stores r6 (sprite data) into r2(character address)
	add r2, #4		@moves the resigester r2 4 steps in memory, so 1 place
	add r3, #4		@moves the resigester r3 4 steps in memory, so 1 place

	add r4, #1		@add 1 to r4 indicating it has moved another step in the loop
	cmp r4, r5 		@compares the current loop with the end of the loop
	bne spriteFor	@jumps back to top of for loop
	
pop { r4-r7 }		
pop { r3 }			
					
bx r3	

@ ==================================

@"extern void ifAlive(int * alive, int * enable);"

.THUMB_FUNC			
ifAlive:			@currently used to determine if the object passed is alive/dead, and thus enabled/disabled

push { r4-r7, lr }

	mov r5, #0		@sets r5 to 0, enabling the input object
	ldr r4, [r0]	@ loads the variable at address r0 (alive = true/false) into r4
	cmp r4, #1 		@ compares the registers r4 and r5 (if the object is alive)
	beq endAlive 	@if they are equal, it will jump to the end, if not it will continue running down (if the object is alive, it will skip)
	
	mov r5, #1		@if the object is not alive, it will set r5 to 1 (disabling the object)
	
	endAlive: 		@if it skips to here, the numbers are equal, if it sets r6 to 0, then they are not equal
	str r5, [r1]	@stores the result in r1 (enable) if alive, the player will be enabled, if not alive, the player will be disabled

pop { r4-r7 }		
pop { r3 }			
					
bx r3	
@ ==================================

@"extern void statMath(int *first, int *second, int *third);"

.THUMB_FUNC		@this function calculates the xp required to level and the HP and MP gained per level	
statMath:			

push { r4-r7, lr }
	
	@ Math: third = first * (second*second) + third - this stores it back into third, because having a forth result produced undesired results, the math worked but the number also added on 150 (e.g. 470 became 470150) and this destroyed the result
	@I probably could have replaced ldr/str with push/pop in places, but this didn't work as intended using r0, r4 was fine. I have explained in further detail below (see indented comments)
	@anyway, it works, but I was disapointed that I could not get it to push/pop how I required, it would have removed the need to load r0 into r4 in the first place
	ldr r4, [r0]		@loads r0 into r4
	ldr r5, [r1]		@loads r1 into r5
	ldr r6, [r2]		@loads r2 into r6
@push {r0}					@I thought if I pushed r0 here, it would be the same, for some reason it changed the results. If I used r4 instead, it worked as intended				
	str r5, [r0]		@store value or r1 (stored in r5) in r0
	bl multiplyNumbers	@multiplies r0(value or r1) and r1 (value or r1) and stores the result in r2

	ldr r7, [r2]		@stores the result into unused r7
	str r4, [r0]		@stores r4 [contents of r0] back into r0
@pop {r0}					@if r4, I would move str r4, [r0] a line below this pop
@str r4, [r0]				@if push/pop r4, this is where the str is... as stated, r4 push/pop seems to work without issues, just r0. I thought it was because I am using ldr/str and this effected the variable, but even using ldr/str straight away, produces the same incorrect result
	str r7, [r1]		@stores the result of (r1*r1) in r1

	bl multiplyNumbers @multiplies r0(first) by r1(second*second)
	ldr r7, [r2]		@loads the result into r7 
	str r7, [r0]		@stores the result into r0
	str r6, [r1]		@stores third into r1

	bl addToTotal	@ this adds r0(first * (second*second)) and r1 (third)


pop { r4-r7 }		
pop { r3 }			
bx r3