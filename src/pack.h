#ifndef ROXLU_PACK_H
#define ROXLU_PACK_H

#include <stdint.h>

/* ---------------------------------------------------- */

typedef struct pack pack;

struct pack {
  uint8_t* buffer;
  uint32_t wdx;
  uint32_t rdx;
  uint32_t capacity;
};

int pack_init(pack* p, uint8_t* buffer, uint32_t size);

/* packing */
int pack_u8(pack* p, uint8_t v);
int pack_u16(pack* p, uint16_t v);
int pack_u32(pack* p, uint32_t v);
int pack_u64(pack* p, uint64_t v);

/* unpacking */
uint8_t unpack_u8(pack* p);
uint16_t unpack_u16(pack* p);
uint32_t unpack_u32(pack* p);
uint64_t unpack_u64(pack* p);

/* ----------------------------------------------------- */
#endif
