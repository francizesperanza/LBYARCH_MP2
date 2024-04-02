# LBYARCH_MP2

Group 10 S14

Members: 

Franciz Emmanuelle Angelo L. Esperanza

Charles Joseph V. Hinolan

# How to run the file?

1. In Visual Studios, click on LBYARCH_MP2.sln
2. If you want run to a preferred mode (Debug/Release x64)
   - Select solution config and platform
   - Build solution
   - Start running

---

# Execution Times

### Debug Mode

**2^20**

C: 0.00473s

x86_64: 0.00227s

**2^24**

C: 0.04793s

x86_64: 0.02003s

**2^28**

C: 0.75133s

x86_64: 0.32147s

### Release Mode

**2^20**

C: 0.00177s

x86_64: 0.0021s

**2^24**

C: 0.02187s

x86_64: 0.01993s

**2^28**

C: 0.3464s

x86_64: 0.2957s

---

# Analysis

In Debug Mode, the x86_64 kernel performs noticeably faster than the C kernel. This is because the assembly code operates closer to the hardware components, unlike high-level languages such as C which need to be compiled to turn the code into machine code. However, in Release Mode, the tests of vector size 2^20 show that the C kernel performed faster than the x86_64 kernel. This may be because Release Mode optimizes the C code and improves its run efficiency. The other test versions in Release Mode still show that the x86_64 kernel performed faster than the C kernel. Although, the gap between the average execution time of the two was noticeably smaller compared to the Debug Mode tests.

---

# Screenshots

### Debug Mode

![image](https://github.com/francizesperanza/LBYARCH_MP2/assets/113343391/1f973b5d-36eb-4b1e-a413-0d97fc10cbc0)


### Release Mode

![image](https://github.com/francizesperanza/LBYARCH_MP2/assets/113343391/ec0269c7-2aa2-46a6-85ff-8364512aaa83)


