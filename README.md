# TimingSideChannelSecurity
This repos contains research works on timing side channel security supervised by prof. Siew Kei and prof. Debdeep.
The works focus on attacks and countermeasures on the RISC-V Rocket chip microprocessor platform running on Zedboard.

**fpga-images-zedboard** includes files that are required to make boot SD card for running RISC-V Rocket chip platform on Zedboard. 
**risv** includes riscv compiler toolset that are used to compiler benchmark source codes for RISC-V microprocessor. (normally using riscv64-unknown-linux-gnu-gcc for linux mode and riscv64-unknown-elf-gcc for bare-metal mode)
The sources of these files can be downloaded and compiled at following repos: [https://github.com/ucb-bar/fpga-zynq.git](https://github.com/ucb-bar/fpga-zynq)

**Csrc** contains C files of benchmarks (modExp and mulMod16) with a baseline implementation and an implementation with countermeasures against timing side channel attacks;

**Script** contains bash scripts that run benchmark programs a given number of times to evaluate the execution time of the programs.
