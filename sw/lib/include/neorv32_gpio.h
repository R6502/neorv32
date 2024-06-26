// ================================================================================ //
// The NEORV32 RISC-V Processor - https://github.com/stnolting/neorv32              //
// Copyright (c) NEORV32 contributors.                                              //
// Copyright (c) 2020 - 2024 Stephan Nolting. All rights reserved.                  //
// Licensed under the BSD-3-Clause license, see LICENSE for details.                //
// SPDX-License-Identifier: BSD-3-Clause                                            //
// ================================================================================ //

/**
 * @file neorv32_gpio.h
 * @brief General purpose input/output port unit (GPIO) HW driver header file.
 *
 * @note These functions should only be used if the GPIO unit was synthesized (IO_GPIO_EN = true).
 *
 * @see https://stnolting.github.io/neorv32/sw/files.html
 */

#ifndef neorv32_gpio_h
#define neorv32_gpio_h

/**********************************************************************//**
 * @name IO Device: General Purpose Input/Output Port Unit (GPIO)
 **************************************************************************/
/**@{*/
/** GPIO module prototype */
typedef volatile struct __attribute__((packed,aligned(4))) {
  const uint32_t INPUT_LO;  /**< offset 0:  parallel input port lower 32-bit, read-only */
  const uint32_t INPUT_HI;  /**< offset 4:  parallel input port upper 32-bit, read-only */
  uint32_t       OUTPUT_LO; /**< offset 8:  parallel output port lower 32-bit */
  uint32_t       OUTPUT_HI; /**< offset 12: parallel output port upper 32-bit */
} neorv32_gpio_t;

/** GPIO module hardware access (#neorv32_gpio_t) */
#define NEORV32_GPIO ((neorv32_gpio_t*) (NEORV32_GPIO_BASE))
/**@}*/


/**********************************************************************//**
 * @name Prototypes
 **************************************************************************/
/**@{*/
int      neorv32_gpio_available(void);
void     neorv32_gpio_pin_set(int pin);
void     neorv32_gpio_pin_clr(int pin);
void     neorv32_gpio_pin_toggle(int pin);
uint32_t neorv32_gpio_pin_get(int pin);

void     neorv32_gpio_port_set(uint64_t d);
uint64_t neorv32_gpio_port_get(void);
/**@}*/


#endif // neorv32_gpio_h
