#ifndef BITS_H
#define BITS_H

// Macros definitions

#define SET_BIT(reg, bit_no) ((reg) |= (1 << (bit_no)))
#define CLR_BIT(reg, bit_no) ((reg) &= ~(1 << (bit_no)))
#define GET_BIT(reg, bit_no) (((reg) >> (bit_no)) & 1)
#define TGL_BIT(reg, bit_no) ((reg) ^= (1 << (bit_no)))

#define SET_REG(reg) ((reg) = 0xFF)
#define CLR_REG(reg) ((reg) = 0x00)
#define TGL_REG(reg) ((reg) ^= 0xFF)

#define ASN_REG(reg, val) ((reg) = (val))
#define ASN_BITS(reg, val) ((reg) |= (val))
#define GET_REG(reg) (reg)

#define assign_bit(var, Bit_No, value) \
    if (value == 1) \
        SET_BIT(var, Bit_No); \
    else \
        CLR_BIT(var, Bit_No);

#endif // BITS_H
