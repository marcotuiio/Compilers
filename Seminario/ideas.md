# Machine Dependent Code Optimization

## Introduction

0. Why optimize and Machine Independent Code Optimization

* Metrics cand vary such as time, memory, power consumption, etc.
* In any conditions its important to either have a fast code or a code that uses less memory or less energy
* Machine Independent Code Optimization: It is the process of optimizing the code without considering the machine where it will run. This improves the readability and maintainability of the code, but does not take advantage of the specific features of the machine but its very portable. All the techniques seen like CSE, DeadCode, Constant Folding, etc. are examples of Machine Independent Code Optimization.

1. Definition of Machine Dependent Code Optimization

* Machine Dependent Code Optimization: It is the process of optimizing the code for a particular machine. This improves some aspects of the generated assembly but eliminates the portability of the code. 

* Important points:
    * Uses specific features of the machine to reduce speed and memory usage.
    * the programmer has greater control over the flow, as it can use certain APIs or libraries that are specific to the machine.
    * It is not portable and demands great rework to be used in another machine, reducing scalability.
    * Demands someone to analyze the situation, poderate if its worth the effort and then implement the optimizations.

2. Why it's important?

* The main reason is to improve the performance of the code, reducing the time and memory usage. This is important in applications that require high performance, such as games, simulations, and real-time applications.
* Not all optimizations can be done by the compiler, so the programmer must be aware of the machine's architecture to make the necessary changes.

3. Algorithms and Techniques

* To illustrate machine-dependent optimization, let's consider a C program optimized for an Intel x86 processor using inline assembly. Inline assembly allows embedding processor-specific instructions within C code, offering direct hardware manipulation and potentially enhancing performance.
```c
#include <stdio.h>

int main() {

    int x = 10;

    int y = 20;

    int result;

    __asm__("addl %%ebx, %%eax;"

        : "=a" (result)

        : "a" (x), "b" (y)

        );
 

    printf("Result: %d\n", result);

    return 0;

}
```

* Peephole optimizations: This refers to any optimization that looks at a small section of code narrowly, this could be two or three instructions, then makes focused changes within the examined section. 
* An example of a peephole optimization is Redundant load elimination. In Redundant load elimination, a sequence of expressions that modify and use similar variables can easily result in two adjacent instructions that save a register into memory, then immediately load the same value again.

(ADD EXAMPLES)
```assembly
MOVQ %R8, x
MOVQ x, %R8
```
A peephole optimization could eliminate the second instruction, as it is redundant.

```assembly
MOVQ %R8, x
```

* A variation is that a load to a different register can be converted into a direct move between registers, this saves unnecessary load and pipeline stall.
x = R8

R9 = x
```assembly
MOVQ %R8, x
MOVQ x, %R9
```
R9 = R8
```assembly
MOVQ %R8, x
MOVQ %R8, %R9
```

* Instruction selection: In a rich CISC instruction set, a single instruction can combine multiple operations such as dereferencing pointers, memory accesses, and arithmetic operations. We can exploit these powerful instructions by using instruction selection by tree coverage. The idea is to first represent each instruction in the architecture as a template tree whereby leaves are addresses in memory, constants, or registers that can be substituted into an instruction.

(ADD EXAMPLES)
```c
int a = 10;
int b = 20;
int c = a + b;
```

```assembly
MOV R0, #10     ; Load constant 10 into register R0
MOV R1, #20     ; Load constant 20 into register R1
ADD R2, R0, R1  ; Add R0 and R1, store result in R2
```

After applying a instruction selection in some architecture with a instruction that can add two registers and store the result in another register, the code would be:

```assembly
MOV R0, #10     ; Load constant 10 into register R0
ADD R1, R0, #20 ; Add R0 and constant 20, store result in R1
```

4. Examples of Machine Dependent Code Optimization

* Scientific Computing: In scientific computing, where large amounts of data need to be processed quickly, machine-dependent code optimization can significantly improve performance. This can involve optimizing code to run on specific types of processors or using specific hardware features like SIMD (Single Instruction, Multiple Data) instructions.

* Use of specific APIs: Some machines have specific APIs that can be used to improve the performance of the code. For example, on GPUs, the programmer can use CUDA or OpenCL to take advantage of the parallel processing capabilities of the GPU. This may even envolve videogames (because of the GPU use)

* Real-Time Systems: In real-time systems, such as those used in aviation or automotive applications, the code needs to run within strict timing constraints. Machine-dependent code optimization can help meet these timing requirements by optimizing the code for the specific hardware the system is running on.

* High-Performance Computing: In high-performance computing, where large-scale simulations or data processing tasks are performed, machine-dependent code optimization can help improve the performance of the code by taking advantage of the specific features of the hardware the code is running on.

5. Using Compiler Explorer to see code with and without optimizations in practice on different architectures
x86-64 gcc 13.2
mips gcc 5.4
```c
#include <stdio.h>

#define size 1000000
int main() {
    int sum = 0;
    int v[size];
    int i;
    for (i = 0; i < size; i++) {
        v[i] = sum;
        sum += i;
    }
    printf("Sum: %d\n", sum);
    return 0;
}
```

# REFERENCES

https://godbolt.org/

https://www.geeksforgeeks.org/machine-dependent-and-machine-independent-code-optimization/

https://www.naukri.com/code360/library/machine-dependent-code-optimization

https://iq.opengenus.org/machine-dependent-optimizations/

https://www.brainkart.com/article/Peephole-Optimization_8111/