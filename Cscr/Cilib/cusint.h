#ifndef SRC_MAIN_C_CUSINT_H
#define SRC_MAIN_C_CUSINT_H

#include <stdio.h>
#include <stdint.h>
#include "rocc.h"

#define k_DO_WRITE 0
#define k_DO_READ 1
#define k_DO_LOAD 2
#define k_DO_ACCUM 3
#define k_DO_MULT 4

#define XCUSTOM_ACC 0
#define XCUSTOM_CuI 2

#define doWrite(y, rocc_rd, data)                                       \
  ROCC_INSTRUCTION(XCUSTOM_ACC, y, data, rocc_rd, k_DO_WRITE);
#define doRead(y, rocc_rd)                                              \
  ROCC_INSTRUCTION(XCUSTOM_ACC, y, 0, rocc_rd, k_DO_READ);
#define doLoad(y, rocc_rd, mem_addr)                                    \
  ROCC_INSTRUCTION(XCUSTOM_ACC, y, mem_addr, rocc_rd, k_DO_LOAD);
#define doAccum(y, rocc_rd, data) \
  ROCC_INSTRUCTION(XCUSTOM_ACC, y, data, rocc_rd, k_DO_ACCUM);
#define doMult(y, rocc_rd, data) \
  ROCC_INSTRUCTION(XCUSTOM_ACC, y, data, rocc_rd, k_DO_MULT);

#define CiAddi(y, op1, op2) \
  ROCC_INSTRUCTION(XCUSTOM_CuI, y, op1, op2, 0);
#define CiMult(y, op1, op2) \
  ROCC_INSTRUCTION(XCUSTOM_CuI, y, op1, op2, 1);
#define CiModu(y, op1, op2) \
  ROCC_INSTRUCTION(XCUSTOM_CuI, y, op1, op2, 2);
#endif  // SRC_MAIN_C_ACCUMULATOR_H
