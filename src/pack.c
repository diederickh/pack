#include "pack.h"

int pack_init(pack* p, uint8_t* buffer, uint32_t size) {

  if (!p) { return -1; } 
  if (!buffer) { return -2; } 
  if (!size) { return -3; } 

  p->buffer = buffer;
  p->capacity = size;
  p->wdx = 0;
  p->rdx = 0;

  return 0;
}

int pack_u8(pack* p, uint8_t v) {
  if (!p) { return -1; } 
  if ((p->wdx + 1) >= p->capacity) { return -2; }
  p->buffer[p->wdx++] = v;
  return 0;
}

int pack_u16(pack* p, uint16_t v) {
  uint8_t* d = (uint8_t*)&v;
  if (!p) { return -1; } 
  if ((p->wdx + 2) >= p->capacity) { return -2; }
  p->buffer[p->wdx++] = d[1];
  p->buffer[p->wdx++] = d[0];
  return 0;
}

int pack_u32(pack* p, uint32_t v) {
  uint8_t* d = (uint8_t*)&v;
  if (!p) { return -1; } 
  if ((p->wdx + 4) >= p->capacity) { return -2; } 
  p->buffer[p->wdx++] = d[3];
  p->buffer[p->wdx++] = d[2];
  p->buffer[p->wdx++] = d[1];
  p->buffer[p->wdx++] = d[0];
  return 0;
}

int pack_u64(pack* p, uint64_t v) {
  uint8_t* d = (uint8_t*)&v;
  if (!p) { return -1; } 
  if ((p->wdx + 8) >= p->capacity) { return -2; } 
  p->buffer[p->wdx++] = d[7];
  p->buffer[p->wdx++] = d[6];
  p->buffer[p->wdx++] = d[5];
  p->buffer[p->wdx++] = d[4];
  p->buffer[p->wdx++] = d[3];
  p->buffer[p->wdx++] = d[2];
  p->buffer[p->wdx++] = d[1];
  p->buffer[p->wdx++] = d[0];
  return 0;
}

uint8_t unpack_u8(pack* p) {
  uint8_t v = 0;
  if (!p) { return -1; } 
  if ( (p->rdx + 1) >= p->capacity) { return -2; }
  v = p->buffer[p->rdx++];
  return v;
}

uint16_t unpack_u16(pack* p) {
  uint16_t v = 0;
  uint8_t* r = (uint8_t*) &v;
  if (!p) { return -1; } 
  if ( (p->rdx + 2) >= p->capacity) { return -2; }
  r[0] = p->buffer[p->rdx + 1];
  r[1] = p->buffer[p->rdx + 0];
  p->rdx += 2;
  return v;
}

uint32_t unpack_u32(pack* p) {
  uint32_t v = 0;
  uint8_t* r = (uint8_t*) &v;
  if (!p) { return -1; } 
  if ( (p->rdx + 4) >= p->capacity) { return -2; }
  r[0] = p->buffer[p->rdx + 3];
  r[1] = p->buffer[p->rdx + 2];
  r[2] = p->buffer[p->rdx + 1];
  r[3] = p->buffer[p->rdx + 0];
  p->rdx += 4;
  return v;
}

uint64_t unpack_u64(pack* p) {
  uint64_t v = 0;
  uint8_t* r = (uint8_t*) &v;
  if (!p) { return -1; } 
  if ( (p->rdx + 8) >= p->capacity) { return -2; }
  r[0] = p->buffer[p->rdx + 7];
  r[1] = p->buffer[p->rdx + 6];
  r[2] = p->buffer[p->rdx + 5];
  r[3] = p->buffer[p->rdx + 4];
  r[4] = p->buffer[p->rdx + 3];
  r[5] = p->buffer[p->rdx + 2];
  r[6] = p->buffer[p->rdx + 1];
  r[7] = p->buffer[p->rdx + 0];
  p->rdx += 8;
  return v;
}
