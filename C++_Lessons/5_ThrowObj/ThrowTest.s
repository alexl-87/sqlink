	.file	"ThrowTest.cpp"
	.text
	.section	.rodata
	.type	_ZStL19piecewise_construct, @object
	.size	_ZStL19piecewise_construct, 1
_ZStL19piecewise_construct:
	.zero	1
	.local	_ZStL8__ioinit
	.comm	_ZStL8__ioinit,1,1
.LC0:
	.string	"error"
	.text
	.globl	main
	.type	main, @function
main:
.LFB1527:
	.cfi_startproc
	.cfi_personality 0x9b,DW.ref.__gxx_personality_v0
	.cfi_lsda 0x1b,.LLSDA1527
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%rbx
	subq	$88, %rsp
	.cfi_offset 3, -24
	movl	%edi, -84(%rbp)
	movq	%rsi, -96(%rbp)
	movq	%fs:40, %rax
	movq	%rax, -24(%rbp)
	xorl	%eax, %eax
.LEHB0:
	call	_Z4foo1v
.LEHE0:
.L5:
	movl	$0, %eax
	movq	-24(%rbp), %rcx
	xorq	%fs:40, %rcx
	je	.L8
	jmp	.L12
.L9:
	movq	%rax, %rbx
	movq	%rdx, %rax
	cmpq	$1, %rax
	jne	.L4
	movq	%rbx, %rax
	movq	%rax, %rdi
	call	__cxa_get_exception_ptr@PLT
	movq	%rax, %rdx
	leaq	-80(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZN11tExeption_tIiNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEiEC1ERKS6_
	movq	%rbx, %rax
	movq	%rax, %rdi
	call	__cxa_begin_catch@PLT
	leaq	-80(%rbp), %rax
	movq	%rax, %rsi
	leaq	_ZSt4cout(%rip), %rdi
.LEHB1:
	call	_ZlsIiNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEiERSoS6_R11tExeption_tIT_T0_T1_E
.LEHE1:
	leaq	-80(%rbp), %rax
	movq	%rax, %rdi
	call	_ZN11tExeption_tIiNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEiED1Ev
.LEHB2:
	call	__cxa_end_catch@PLT
.LEHE2:
	jmp	.L5
.L4:
	movq	%rbx, %rax
	movq	%rax, %rdi
	call	__cxa_begin_catch@PLT
	leaq	.LC0(%rip), %rsi
	leaq	_ZSt4cout(%rip), %rdi
.LEHB3:
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	movq	%rax, %rdx
	movq	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_@GOTPCREL(%rip), %rax
	movq	%rax, %rsi
	movq	%rdx, %rdi
	call	_ZNSolsEPFRSoS_E@PLT
.LEHE3:
.LEHB4:
	call	__cxa_end_catch@PLT
.LEHE4:
	jmp	.L5
.L10:
	movq	%rax, %rbx
	leaq	-80(%rbp), %rax
	movq	%rax, %rdi
	call	_ZN11tExeption_tIiNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEiED1Ev
	call	__cxa_end_catch@PLT
	movq	%rbx, %rax
	movq	%rax, %rdi
.LEHB5:
	call	_Unwind_Resume@PLT
.LEHE5:
.L11:
	movq	%rax, %rbx
	call	__cxa_end_catch@PLT
	movq	%rbx, %rax
	movq	%rax, %rdi
.LEHB6:
	call	_Unwind_Resume@PLT
.LEHE6:
.L12:
	call	__stack_chk_fail@PLT
.L8:
	addq	$88, %rsp
	popq	%rbx
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1527:
	.globl	__gxx_personality_v0
	.section	.gcc_except_table,"a",@progbits
	.align 4
.LLSDA1527:
	.byte	0xff
	.byte	0x9b
	.uleb128 .LLSDATT1527-.LLSDATTD1527
.LLSDATTD1527:
	.byte	0x1
	.uleb128 .LLSDACSE1527-.LLSDACSB1527
.LLSDACSB1527:
	.uleb128 .LEHB0-.LFB1527
	.uleb128 .LEHE0-.LEHB0
	.uleb128 .L9-.LFB1527
	.uleb128 0x3
	.uleb128 .LEHB1-.LFB1527
	.uleb128 .LEHE1-.LEHB1
	.uleb128 .L10-.LFB1527
	.uleb128 0
	.uleb128 .LEHB2-.LFB1527
	.uleb128 .LEHE2-.LEHB2
	.uleb128 0
	.uleb128 0
	.uleb128 .LEHB3-.LFB1527
	.uleb128 .LEHE3-.LEHB3
	.uleb128 .L11-.LFB1527
	.uleb128 0
	.uleb128 .LEHB4-.LFB1527
	.uleb128 .LEHE4-.LEHB4
	.uleb128 0
	.uleb128 0
	.uleb128 .LEHB5-.LFB1527
	.uleb128 .LEHE5-.LEHB5
	.uleb128 0
	.uleb128 0
	.uleb128 .LEHB6-.LFB1527
	.uleb128 .LEHE6-.LEHB6
	.uleb128 0
	.uleb128 0
.LLSDACSE1527:
	.byte	0x2
	.byte	0
	.byte	0x1
	.byte	0x7d
	.align 4
	.long	0

	.long	DW.ref._ZTI11tExeption_tIiNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEiE-.
.LLSDATT1527:
	.text
	.size	main, .-main
	.globl	_Z4foo1v
	.type	_Z4foo1v, @function
_Z4foo1v:
.LFB1528:
	.cfi_startproc
	.cfi_personality 0x9b,DW.ref.__gxx_personality_v0
	.cfi_lsda 0x1b,.LLSDA1528
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%rbx
	subq	$8, %rsp
	.cfi_offset 3, -24
.LEHB7:
	call	_Z4foo2v
.LEHE7:
	jmp	.L18
.L16:
	movq	%rax, %rdi
	call	__cxa_begin_catch@PLT
.LEHB8:
	call	__cxa_rethrow@PLT
.LEHE8:
.L17:
	movq	%rax, %rbx
	call	__cxa_end_catch@PLT
	movq	%rbx, %rax
	movq	%rax, %rdi
.LEHB9:
	call	_Unwind_Resume@PLT
.LEHE9:
.L18:
	addq	$8, %rsp
	popq	%rbx
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1528:
	.section	.gcc_except_table
	.align 4
.LLSDA1528:
	.byte	0xff
	.byte	0x9b
	.uleb128 .LLSDATT1528-.LLSDATTD1528
.LLSDATTD1528:
	.byte	0x1
	.uleb128 .LLSDACSE1528-.LLSDACSB1528
.LLSDACSB1528:
	.uleb128 .LEHB7-.LFB1528
	.uleb128 .LEHE7-.LEHB7
	.uleb128 .L16-.LFB1528
	.uleb128 0x1
	.uleb128 .LEHB8-.LFB1528
	.uleb128 .LEHE8-.LEHB8
	.uleb128 .L17-.LFB1528
	.uleb128 0
	.uleb128 .LEHB9-.LFB1528
	.uleb128 .LEHE9-.LEHB9
	.uleb128 0
	.uleb128 0
.LLSDACSE1528:
	.byte	0x1
	.byte	0
	.align 4
	.long	0

.LLSDATT1528:
	.text
	.size	_Z4foo1v, .-_Z4foo1v
	.globl	_Z4foo2v
	.type	_Z4foo2v, @function
_Z4foo2v:
.LFB1529:
	.cfi_startproc
	.cfi_personality 0x9b,DW.ref.__gxx_personality_v0
	.cfi_lsda 0x1b,.LLSDA1529
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%rbx
	subq	$8, %rsp
	.cfi_offset 3, -24
.LEHB10:
	call	_Z4foo3v
.LEHE10:
	jmp	.L24
.L22:
	movq	%rax, %rdi
	call	__cxa_begin_catch@PLT
.LEHB11:
	call	__cxa_rethrow@PLT
.LEHE11:
.L23:
	movq	%rax, %rbx
	call	__cxa_end_catch@PLT
	movq	%rbx, %rax
	movq	%rax, %rdi
.LEHB12:
	call	_Unwind_Resume@PLT
.LEHE12:
.L24:
	addq	$8, %rsp
	popq	%rbx
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1529:
	.section	.gcc_except_table
	.align 4
.LLSDA1529:
	.byte	0xff
	.byte	0x9b
	.uleb128 .LLSDATT1529-.LLSDATTD1529
.LLSDATTD1529:
	.byte	0x1
	.uleb128 .LLSDACSE1529-.LLSDACSB1529
.LLSDACSB1529:
	.uleb128 .LEHB10-.LFB1529
	.uleb128 .LEHE10-.LEHB10
	.uleb128 .L22-.LFB1529
	.uleb128 0x1
	.uleb128 .LEHB11-.LFB1529
	.uleb128 .LEHE11-.LEHB11
	.uleb128 .L23-.LFB1529
	.uleb128 0
	.uleb128 .LEHB12-.LFB1529
	.uleb128 .LEHE12-.LEHB12
	.uleb128 0
	.uleb128 0
.LLSDACSE1529:
	.byte	0x1
	.byte	0
	.align 4
	.long	0

.LLSDATT1529:
	.text
	.size	_Z4foo2v, .-_Z4foo2v
	.section	.rodata
.LC1:
	.string	"ThrowTest.cpp"
	.text
	.globl	_Z4foo3v
	.type	_Z4foo3v, @function
_Z4foo3v:
.LFB1530:
	.cfi_startproc
	.cfi_personality 0x9b,DW.ref.__gxx_personality_v0
	.cfi_lsda 0x1b,.LLSDA1530
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%r12
	pushq	%rbx
	subq	$64, %rsp
	.cfi_offset 12, -24
	.cfi_offset 3, -32
	movq	%fs:40, %rax
	movq	%rax, -24(%rbp)
	xorl	%eax, %eax
	movl	$48, %edi
	call	__cxa_allocate_exception@PLT
	movq	%rax, %rbx
	movl	$59, -68(%rbp)
	leaq	-73(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSaIcEC1Ev@PLT
	leaq	-73(%rbp), %rdx
	leaq	-64(%rbp), %rax
	leaq	.LC1(%rip), %rsi
	movq	%rax, %rdi
.LEHB13:
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1EPKcRKS3_@PLT
.LEHE13:
	movl	$6, -72(%rbp)
	leaq	-68(%rbp), %rcx
	leaq	-64(%rbp), %rdx
	leaq	-72(%rbp), %rax
	movq	%rax, %rsi
	movq	%rbx, %rdi
.LEHB14:
	call	_ZN11tExeption_tIiNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEiEC1ERKiRKS5_S8_
.LEHE14:
	leaq	-64(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev@PLT
	leaq	-73(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSaIcED1Ev@PLT
	leaq	_ZN11tExeption_tIiNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEiED1Ev(%rip), %rdx
	leaq	_ZTI11tExeption_tIiNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEiE(%rip), %rsi
	movq	%rbx, %rdi
.LEHB15:
	call	__cxa_throw@PLT
.L30:
	movq	%rax, %r12
	leaq	-64(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev@PLT
	jmp	.L27
.L29:
	movq	%rax, %r12
.L27:
	leaq	-73(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSaIcED1Ev@PLT
	movq	%rbx, %rdi
	call	__cxa_free_exception@PLT
	movq	%r12, %rax
	movq	%rax, %rdi
	call	_Unwind_Resume@PLT
.LEHE15:
	.cfi_endproc
.LFE1530:
	.section	.gcc_except_table
.LLSDA1530:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSE1530-.LLSDACSB1530
.LLSDACSB1530:
	.uleb128 .LEHB13-.LFB1530
	.uleb128 .LEHE13-.LEHB13
	.uleb128 .L29-.LFB1530
	.uleb128 0
	.uleb128 .LEHB14-.LFB1530
	.uleb128 .LEHE14-.LEHB14
	.uleb128 .L30-.LFB1530
	.uleb128 0
	.uleb128 .LEHB15-.LFB1530
	.uleb128 .LEHE15-.LEHB15
	.uleb128 0
	.uleb128 0
.LLSDACSE1530:
	.text
	.size	_Z4foo3v, .-_Z4foo3v
	.section	.text._ZN11tExeption_tIiNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEiEC2ERKS6_,"axG",@progbits,_ZN11tExeption_tIiNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEiEC5ERKS6_,comdat
	.align 2
	.weak	_ZN11tExeption_tIiNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEiEC2ERKS6_
	.type	_ZN11tExeption_tIiNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEiEC2ERKS6_, @function
_ZN11tExeption_tIiNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEiEC2ERKS6_:
.LFB1768:
	.cfi_startproc
	.cfi_personality 0x9b,DW.ref.__gxx_personality_v0
	.cfi_lsda 0x1b,.LLSDA1768
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%rbx
	subq	$24, %rsp
	.cfi_offset 3, -24
	movq	%rdi, -24(%rbp)
	movq	%rsi, -32(%rbp)
	movq	-24(%rbp), %rax
	addq	$8, %rax
	movq	%rax, %rdi
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1Ev@PLT
	movq	-32(%rbp), %rax
	movl	(%rax), %edx
	movq	-24(%rbp), %rax
	movl	%edx, (%rax)
	movq	-32(%rbp), %rax
	leaq	8(%rax), %rdx
	movq	-24(%rbp), %rax
	addq	$8, %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
.LEHB16:
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEaSERKS4_@PLT
.LEHE16:
	movq	-32(%rbp), %rax
	movl	40(%rax), %edx
	movq	-24(%rbp), %rax
	movl	%edx, 40(%rax)
	jmp	.L34
.L33:
	movq	%rax, %rbx
	movq	-24(%rbp), %rax
	addq	$8, %rax
	movq	%rax, %rdi
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev@PLT
	movq	%rbx, %rax
	movq	%rax, %rdi
.LEHB17:
	call	_Unwind_Resume@PLT
.LEHE17:
.L34:
	addq	$24, %rsp
	popq	%rbx
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1768:
	.section	.gcc_except_table
.LLSDA1768:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSE1768-.LLSDACSB1768
.LLSDACSB1768:
	.uleb128 .LEHB16-.LFB1768
	.uleb128 .LEHE16-.LEHB16
	.uleb128 .L33-.LFB1768
	.uleb128 0
	.uleb128 .LEHB17-.LFB1768
	.uleb128 .LEHE17-.LEHB17
	.uleb128 0
	.uleb128 0
.LLSDACSE1768:
	.section	.text._ZN11tExeption_tIiNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEiEC2ERKS6_,"axG",@progbits,_ZN11tExeption_tIiNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEiEC5ERKS6_,comdat
	.size	_ZN11tExeption_tIiNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEiEC2ERKS6_, .-_ZN11tExeption_tIiNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEiEC2ERKS6_
	.weak	_ZN11tExeption_tIiNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEiEC1ERKS6_
	.set	_ZN11tExeption_tIiNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEiEC1ERKS6_,_ZN11tExeption_tIiNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEiEC2ERKS6_
	.section	.text._ZN11tExeption_tIiNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEiED2Ev,"axG",@progbits,_ZN11tExeption_tIiNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEiED5Ev,comdat
	.align 2
	.weak	_ZN11tExeption_tIiNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEiED2Ev
	.type	_ZN11tExeption_tIiNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEiED2Ev, @function
_ZN11tExeption_tIiNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEiED2Ev:
.LFB1771:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	addq	$8, %rax
	movq	%rax, %rdi
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev@PLT
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1771:
	.size	_ZN11tExeption_tIiNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEiED2Ev, .-_ZN11tExeption_tIiNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEiED2Ev
	.weak	_ZN11tExeption_tIiNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEiED1Ev
	.set	_ZN11tExeption_tIiNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEiED1Ev,_ZN11tExeption_tIiNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEiED2Ev
	.section	.text._ZlsIiNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEiERSoS6_R11tExeption_tIT_T0_T1_E,"axG",@progbits,_ZlsIiNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEiERSoS6_R11tExeption_tIT_T0_T1_E,comdat
	.weak	_ZlsIiNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEiERSoS6_R11tExeption_tIT_T0_T1_E
	.type	_ZlsIiNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEiERSoS6_R11tExeption_tIT_T0_T1_E, @function
_ZlsIiNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEiERSoS6_R11tExeption_tIT_T0_T1_E:
.LFB1773:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%rbx
	subq	$24, %rsp
	.cfi_offset 3, -24
	movq	%rdi, -24(%rbp)
	movq	%rsi, -32(%rbp)
	movq	-32(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNK11tExeption_tIiNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEiE10getParam_1Ev
	movl	(%rax), %edx
	movq	-24(%rbp), %rax
	movl	%edx, %esi
	movq	%rax, %rdi
	call	_ZNSolsEi@PLT
	movq	%rax, %rdx
	movq	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_@GOTPCREL(%rip), %rax
	movq	%rax, %rsi
	movq	%rdx, %rdi
	call	_ZNSolsEPFRSoS_E@PLT
	movq	%rax, %rbx
	movq	-32(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNK11tExeption_tIiNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEiE10getParam_2Ev
	movq	%rax, %rsi
	movq	%rbx, %rdi
	call	_ZStlsIcSt11char_traitsIcESaIcEERSt13basic_ostreamIT_T0_ES7_RKNSt7__cxx1112basic_stringIS4_S5_T1_EE@PLT
	movq	%rax, %rdx
	movq	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_@GOTPCREL(%rip), %rax
	movq	%rax, %rsi
	movq	%rdx, %rdi
	call	_ZNSolsEPFRSoS_E@PLT
	movq	%rax, %rbx
	movq	-32(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNK11tExeption_tIiNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEiE10getParam_3Ev
	movl	(%rax), %eax
	movl	%eax, %esi
	movq	%rbx, %rdi
	call	_ZNSolsEi@PLT
	movq	%rax, %rdx
	movq	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_@GOTPCREL(%rip), %rax
	movq	%rax, %rsi
	movq	%rdx, %rdi
	call	_ZNSolsEPFRSoS_E@PLT
	movq	-24(%rbp), %rax
	addq	$24, %rsp
	popq	%rbx
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1773:
	.size	_ZlsIiNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEiERSoS6_R11tExeption_tIT_T0_T1_E, .-_ZlsIiNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEiERSoS6_R11tExeption_tIT_T0_T1_E
	.section	.text._ZN11tExeption_tIiNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEiEC2ERKiRKS5_S8_,"axG",@progbits,_ZN11tExeption_tIiNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEiEC5ERKiRKS5_S8_,comdat
	.align 2
	.weak	_ZN11tExeption_tIiNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEiEC2ERKiRKS5_S8_
	.type	_ZN11tExeption_tIiNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEiEC2ERKiRKS5_S8_, @function
_ZN11tExeption_tIiNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEiEC2ERKiRKS5_S8_:
.LFB1781:
	.cfi_startproc
	.cfi_personality 0x9b,DW.ref.__gxx_personality_v0
	.cfi_lsda 0x1b,.LLSDA1781
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%rbx
	subq	$40, %rsp
	.cfi_offset 3, -24
	movq	%rdi, -24(%rbp)
	movq	%rsi, -32(%rbp)
	movq	%rdx, -40(%rbp)
	movq	%rcx, -48(%rbp)
	movq	-32(%rbp), %rax
	movl	(%rax), %edx
	movq	-24(%rbp), %rax
	movl	%edx, (%rax)
	movq	-24(%rbp), %rax
	addq	$8, %rax
	movq	%rax, %rdi
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1Ev@PLT
	movq	-24(%rbp), %rax
	leaq	8(%rax), %rdx
	movq	-40(%rbp), %rax
	movq	%rax, %rsi
	movq	%rdx, %rdi
.LEHB18:
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEaSERKS4_@PLT
.LEHE18:
	movq	-48(%rbp), %rax
	movl	(%rax), %edx
	movq	-24(%rbp), %rax
	movl	%edx, 40(%rax)
	jmp	.L41
.L40:
	movq	%rax, %rbx
	movq	-24(%rbp), %rax
	addq	$8, %rax
	movq	%rax, %rdi
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev@PLT
	movq	%rbx, %rax
	movq	%rax, %rdi
.LEHB19:
	call	_Unwind_Resume@PLT
.LEHE19:
.L41:
	addq	$40, %rsp
	popq	%rbx
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1781:
	.section	.gcc_except_table
.LLSDA1781:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSE1781-.LLSDACSB1781
.LLSDACSB1781:
	.uleb128 .LEHB18-.LFB1781
	.uleb128 .LEHE18-.LEHB18
	.uleb128 .L40-.LFB1781
	.uleb128 0
	.uleb128 .LEHB19-.LFB1781
	.uleb128 .LEHE19-.LEHB19
	.uleb128 0
	.uleb128 0
.LLSDACSE1781:
	.section	.text._ZN11tExeption_tIiNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEiEC2ERKiRKS5_S8_,"axG",@progbits,_ZN11tExeption_tIiNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEiEC5ERKiRKS5_S8_,comdat
	.size	_ZN11tExeption_tIiNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEiEC2ERKiRKS5_S8_, .-_ZN11tExeption_tIiNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEiEC2ERKiRKS5_S8_
	.weak	_ZN11tExeption_tIiNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEiEC1ERKiRKS5_S8_
	.set	_ZN11tExeption_tIiNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEiEC1ERKiRKS5_S8_,_ZN11tExeption_tIiNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEiEC2ERKiRKS5_S8_
	.section	.text._ZNK11tExeption_tIiNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEiE10getParam_1Ev,"axG",@progbits,_ZNK11tExeption_tIiNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEiE10getParam_1Ev,comdat
	.align 2
	.weak	_ZNK11tExeption_tIiNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEiE10getParam_1Ev
	.type	_ZNK11tExeption_tIiNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEiE10getParam_1Ev, @function
_ZNK11tExeption_tIiNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEiE10getParam_1Ev:
.LFB1897:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1897:
	.size	_ZNK11tExeption_tIiNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEiE10getParam_1Ev, .-_ZNK11tExeption_tIiNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEiE10getParam_1Ev
	.section	.text._ZNK11tExeption_tIiNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEiE10getParam_2Ev,"axG",@progbits,_ZNK11tExeption_tIiNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEiE10getParam_2Ev,comdat
	.align 2
	.weak	_ZNK11tExeption_tIiNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEiE10getParam_2Ev
	.type	_ZNK11tExeption_tIiNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEiE10getParam_2Ev, @function
_ZNK11tExeption_tIiNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEiE10getParam_2Ev:
.LFB1898:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	addq	$8, %rax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1898:
	.size	_ZNK11tExeption_tIiNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEiE10getParam_2Ev, .-_ZNK11tExeption_tIiNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEiE10getParam_2Ev
	.section	.text._ZNK11tExeption_tIiNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEiE10getParam_3Ev,"axG",@progbits,_ZNK11tExeption_tIiNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEiE10getParam_3Ev,comdat
	.align 2
	.weak	_ZNK11tExeption_tIiNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEiE10getParam_3Ev
	.type	_ZNK11tExeption_tIiNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEiE10getParam_3Ev, @function
_ZNK11tExeption_tIiNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEiE10getParam_3Ev:
.LFB1900:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	addq	$40, %rax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1900:
	.size	_ZNK11tExeption_tIiNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEiE10getParam_3Ev, .-_ZNK11tExeption_tIiNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEiE10getParam_3Ev
	.weak	_ZTI11tExeption_tIiNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEiE
	.section	.data.rel.ro._ZTI11tExeption_tIiNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEiE,"awG",@progbits,_ZTI11tExeption_tIiNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEiE,comdat
	.align 8
	.type	_ZTI11tExeption_tIiNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEiE, @object
	.size	_ZTI11tExeption_tIiNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEiE, 16
_ZTI11tExeption_tIiNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEiE:
	.quad	_ZTVN10__cxxabiv117__class_type_infoE+16
	.quad	_ZTS11tExeption_tIiNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEiE
	.weak	_ZTS11tExeption_tIiNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEiE
	.section	.rodata._ZTS11tExeption_tIiNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEiE,"aG",@progbits,_ZTS11tExeption_tIiNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEiE,comdat
	.align 32
	.type	_ZTS11tExeption_tIiNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEiE, @object
	.size	_ZTS11tExeption_tIiNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEiE, 70
_ZTS11tExeption_tIiNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEiE:
	.string	"11tExeption_tIiNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEiE"
	.text
	.type	_Z41__static_initialization_and_destruction_0ii, @function
_Z41__static_initialization_and_destruction_0ii:
.LFB2048:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movl	%edi, -4(%rbp)
	movl	%esi, -8(%rbp)
	cmpl	$1, -4(%rbp)
	jne	.L50
	cmpl	$65535, -8(%rbp)
	jne	.L50
	leaq	_ZStL8__ioinit(%rip), %rdi
	call	_ZNSt8ios_base4InitC1Ev@PLT
	leaq	__dso_handle(%rip), %rdx
	leaq	_ZStL8__ioinit(%rip), %rsi
	movq	_ZNSt8ios_base4InitD1Ev@GOTPCREL(%rip), %rax
	movq	%rax, %rdi
	call	__cxa_atexit@PLT
.L50:
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2048:
	.size	_Z41__static_initialization_and_destruction_0ii, .-_Z41__static_initialization_and_destruction_0ii
	.type	_GLOBAL__sub_I_main, @function
_GLOBAL__sub_I_main:
.LFB2049:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	$65535, %esi
	movl	$1, %edi
	call	_Z41__static_initialization_and_destruction_0ii
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2049:
	.size	_GLOBAL__sub_I_main, .-_GLOBAL__sub_I_main
	.section	.init_array,"aw"
	.align 8
	.quad	_GLOBAL__sub_I_main
	.hidden	DW.ref._ZTI11tExeption_tIiNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEiE
	.weak	DW.ref._ZTI11tExeption_tIiNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEiE
	.section	.data.rel.local.DW.ref._ZTI11tExeption_tIiNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEiE,"awG",@progbits,DW.ref._ZTI11tExeption_tIiNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEiE,comdat
	.align 8
	.type	DW.ref._ZTI11tExeption_tIiNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEiE, @object
	.size	DW.ref._ZTI11tExeption_tIiNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEiE, 8
DW.ref._ZTI11tExeption_tIiNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEiE:
	.quad	_ZTI11tExeption_tIiNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEiE
	.hidden	DW.ref.__gxx_personality_v0
	.weak	DW.ref.__gxx_personality_v0
	.section	.data.rel.local.DW.ref.__gxx_personality_v0,"awG",@progbits,DW.ref.__gxx_personality_v0,comdat
	.align 8
	.type	DW.ref.__gxx_personality_v0, @object
	.size	DW.ref.__gxx_personality_v0, 8
DW.ref.__gxx_personality_v0:
	.quad	__gxx_personality_v0
	.hidden	__dso_handle
	.ident	"GCC: (Ubuntu 8.3.0-6ubuntu1) 8.3.0"
	.section	.note.GNU-stack,"",@progbits
