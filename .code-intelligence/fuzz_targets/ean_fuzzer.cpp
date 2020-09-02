#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <cstdint>
#include <iostream>
#include "common.h"
#include "gs1.h"
#include <unistd.h>

int ZBarcode_Buffer(struct zint_symbol *symbol, int rotate_angle);

extern "C" int FUZZ(const uint8_t *Data, size_t Size)
{
  if (Size < 4)
    return 0;


  struct zint_symbol *my_symbol;
  my_symbol = ZBarcode_Create();

  my_symbol->symbology = BARCODE_EANX;
  unsigned char *input = (unsigned char *)Data;
  ZBarcode_Encode(my_symbol, input, Size);
  ZBarcode_Delete(my_symbol);

  return 0;
}
