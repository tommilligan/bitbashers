# qemu -kernel loads this code at 0x80000000 and causes each CPU to jump
# there. kernel.ld causes the following code to be placed at 0x80000000.
.section .text
_entry:
        la sp, end + 0x1000
        call start

start:
    jal uartinit
    li  a0,0x48
    jal uartputc
    li  a0,0x65
    jal uartputc
    li  a0,0x6c
    jal uartputc
    li  a0,0x6c
    jal uartputc
    li  a0,0x6f
    jal uartputc
    li  a0,0x20
    jal uartputc
    li  a0,0x52
    jal uartputc
    li  a0,0x49
    jal uartputc
    li  a0,0x53
    jal uartputc
    li  a0,0x43
    jal uartputc
    li  a0,0x2d
    jal uartputc
    li  a0,0x56
    jal uartputc
    li  a0,0x21
    jal uartputc
    li  a0,0x0a
    jal uartputc

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
