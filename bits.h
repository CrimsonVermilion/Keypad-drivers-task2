#ifndef bits_H_INCLUDED_
#define bits_H_INCLUDED_

#define set_bit(x,bits) (x |= (1<<bits))
#define clr_bit(x,bits) (x &= ~(1<<bits))
#define tog_bit(x,bits) (x ^= (1<<bits))
#define get_define(x,bits) ((x>>bits)&1)

#define on 1
#define off 0

#endif
