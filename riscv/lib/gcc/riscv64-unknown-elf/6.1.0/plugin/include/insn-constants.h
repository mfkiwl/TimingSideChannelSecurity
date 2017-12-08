/* Generated automatically by the program `genconstants'
   from the machine description file `md'.  */

#ifndef GCC_INSN_CONSTANTS_H
#define GCC_INSN_CONSTANTS_H

#define RETURN_ADDR_REGNUM 1
#define T0_REGNUM 5
#define T1_REGNUM 6

enum unspec {
  UNSPEC_LOAD_LOW = 0,
  UNSPEC_LOAD_HIGH = 1,
  UNSPEC_STORE_WORD = 2,
  UNSPEC_EH_RETURN = 3,
  UNSPEC_ADDRESS_FIRST = 4,
  UNSPEC_PCREL = 5,
  UNSPEC_LOAD_GOT = 6,
  UNSPEC_TLS = 7,
  UNSPEC_TLS_LE = 8,
  UNSPEC_TLS_IE = 9,
  UNSPEC_TLS_GD = 10,
  UNSPEC_AUIPC = 11,
  UNSPEC_GPR_SAVE = 12,
  UNSPEC_GPR_RESTORE = 13,
  UNSPEC_BLOCKAGE = 14,
  UNSPEC_FENCE = 15,
  UNSPEC_FENCE_I = 16,
  UNSPEC_COMPARE_AND_SWAP = 17,
  UNSPEC_SYNC_OLD_OP = 18,
  UNSPEC_SYNC_EXCHANGE = 19,
  UNSPEC_ATOMIC_STORE = 20,
  UNSPEC_MEMORY_BARRIER = 21
};
#define NUM_UNSPEC_VALUES 22
extern const char *const unspec_strings[];

#endif /* GCC_INSN_CONSTANTS_H */
