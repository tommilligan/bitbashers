# qemu -kernel loads this code at 0x80000000 and causes each CPU to jump
# there. kernel.ld causes the following code to be placed at 0x80000000.
.section .text
_entry:
        la sp, end + 0x1000
        call start


start:
    jal uartinit
    # so a7 will contain address 0x1000 for instance
    la  a7,helloworld
    # initialize our value reg as zero
    li  a0,0

printchar:
    # load value at 0x1000 into a0
    lb  a0,0(a7)
    # when the character is zero (null terminator), exit loop
    beq zero,a0,spin
    # print char
    jal uartputc
    # increment the address to 0x1001
    addi a7,a7,1
    j   printchar

spin:
	wfi
        j spin

# void uartinit() - initialize console UART
uartinit:
    li  a5,268435456
    sb  zero,1(a5)
    li  a4,-128
    sb  a4,3(a5)
    li  a4,3
    sb  a4,0(a5)
    sb  zero,1(a5)
    sb  a4,3(a5)
    li  a3,7
    sb  a3,2(a5)
    sb  a4,1(a5)
    ret

# void uartputc(int c) - output character with code `c`
uartputc:
    li  a4,268435456
.L1:
    lbu a5,5(a4)
    andi    a5,a5,32
    beq a5,zero,.L1
    andi    a0,a0,0xff
    sb  a0,0(a4)
    ret

.data
helloworld:  .ascii "Hello, world!\n"
