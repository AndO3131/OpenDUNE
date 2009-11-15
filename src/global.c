#include <assert.h>
#include <stdio.h>
#include "types.h"
#include "libemu.h"
#include "global.h"

GlobalData *g_global = NULL;
bool g_dune2_enhanced = true; /*!< If false, the game acts exactly like the original Dune2, including bugs. */

/**
 * Initialize the global system.
 *
 * @init System_Init_Global
 */
void System_Init_Global()
{
	g_global = (GlobalData *)&emu_get_memory8(0x353F, 0x0, 0x0);
}

/**
 * Given a pointer inside the 16bit memory and a segment, find the IP which
 *  belongs to it.
 */
uint16 emu_Global_GetIP(void *ptr, uint16 segment)
{
	return (size_t)ptr - (size_t)emu_memory - (segment << 4);
}

/**
 * Get a piece of memory by csip.
 */
uint8 *emu_get_memorycsip(csip32 csip)
{
	return &emu_get_memory8(csip.s.cs, csip.s.ip, 0x0);
}
