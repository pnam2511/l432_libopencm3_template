#include <stdlib.h>
#include "flash_map_backend/flash_map_backend.h"

#include "sysflash/sysflash.h"

int flash_area_open(uint8_t id, const struct flash_area **area_outp)
{
    (void) id;
    (void) area_outp;
    return -1;
}

void flash_area_close(const struct flash_area *fa)
{
    (void) fa;
}

int flash_area_read(const struct flash_area *fa, uint32_t off, void *dst, uint32_t len)
{
    (void) fa;
    (void) off;
    (void) dst;
    (void) len;
    return -1;
}

int flash_area_write(const struct flash_area *fa, uint32_t off, const void *src, uint32_t len)
{
    (void) fa;
    (void) off;
    (void) src;
    (void) len;
    return -1;
}

int flash_area_erase(const struct flash_area *fa, uint32_t off, uint32_t len)
{
    (void) fa;
    (void) off;
    (void) len;
    return -1;
}

uint32_t flash_area_align(const struct flash_area *area)
{
    (void) area;
    return -1;
}

uint8_t flash_area_erased_val(const struct flash_area *area)
{
    (void) area;
    return -1;
}

int flash_area_get_sectors(int fa_id, uint32_t *count, struct flash_sector *sectors)
{
    (void) fa_id;
    (void) count;
    (void) sectors;
    return -1;
}

int flash_area_sector_from_off(uint32_t off, struct flash_sector *sector)
{
    (void) off;
    (void) sector;
    return -1;
}

int flash_area_get_sector(const struct flash_area *area, uint32_t off, struct flash_sector *sector)
{
    (void) area;
    (void) off;
    (void) sector;
    return -1;
}


int flash_area_id_from_multi_image_slot(int image_index, int slot)
{
    (void) image_index;
    (void) slot;
    return -1;
}

int flash_area_id_from_image_slot(int slot)
{
    return flash_area_id_from_multi_image_slot(0, slot);
}

int flash_area_to_sectors(int idx, int *cnt, struct flash_area *fa)
{
    (void) idx;
    (void) cnt;
    (void) fa;
    return -1;
}
