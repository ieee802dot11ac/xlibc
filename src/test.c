typedef unsigned long long uint64_t;
typedef unsigned long uint32_t;

uint64_t syscall(register uint32_t num, register uint64_t arg0, register uint64_t arg1, 
	register uint64_t arg2, register uint64_t arg3, register uint64_t arg4, register uint64_t arg5) {
	register uint64_t ret;
	asm("movq %0, %%rax;" :: "ri" (num));
	asm("movq %0, %%rdi;" :: "ri" (arg0));
	asm("movq %0, %%rsi;" :: "ri" (arg1));
	asm("movq %0, %%rdx;" :: "ri" (arg2));
	asm("movq %0, %%r10;" :: "ri" (arg3));
	asm("movq %0, %%r8;" :: "ri" (arg4));
	asm("movq %0, %%r9;" :: "ri" (arg5));
	asm("syscall;");
	asm("mov %%rax, %0" : "=rm" (ret));
	return ret;
}

void _start() {
	syscall(60, 0, 
	0,0,0,0,0);
	__builtin_unreachable();
}
