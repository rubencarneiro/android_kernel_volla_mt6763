/* drivers/input/touchscreen/gt1x_tpd_custom.h
 *
 * 2010 - 2014 Goodix Technology.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be a reference
 * to you, when you are integrating the GOODiX's CTP IC into your system,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 * 
 * Version: 1.4   
 * Release Date:  2015/07/10
 */

#ifndef GT1X_TPD_CUSTOM_H__
#define GT1X_TPD_CUSTOM_H__

#include <asm/uaccess.h>
//#include <linux/rtpm_prio.h>
#include "tpd.h"
#include "mtk_boot_common.h"
#define PLATFORM_MTK
#define TPD_I2C_NUMBER		        1
#define TPD_SUPPORT_I2C_DMA         0	// if gt9l, better enable it if hardware platform supported
#define TPD_HAVE_BUTTON             1	//report key as coordinate,Vibration feedback

/* s960t */
//#define TPD_POWER_SOURCE_CUSTOM	MT6323_POWER_LDO_VGP1	//MT6323_POWER_LDO_VGP1

/* k53v1_64 */
#define TPD_POWER_SOURCE_CUSTOM	PMIC_APP_CAP_TOUCH_VDD

/* y900 */
//#define TPD_POWER_SOURCE_CUSTOM       MT65XX_POWER_LDO_VGP4    //MT6323_POWER_LDO_VGP1

#if TPD_HAVE_BUTTON
#define TPD_KEY_COUNT   3
#define key_1           160,2100
#define key_3           540,2100
#define key_2           920,2100
//#define key_4           420,2100
#define TPD_KEY_MAP_ARRAY {{key_1},{key_2},{key_3}}
#define TPD_KEYS        {KEY_BACK, KEY_HOME, KEY_MENU/*, KEY_SEARCH*/}
#define TPD_KEYS_DIM    {{key_1,50,30},{key_2,50,30},{key_3,50,30}/*,{key_4,50,30}*/}
#else
#define TPD_KEY_COUNT   3
#endif

/*
// Change I/O define & I/O operation mode.
#define GTP_RST_PORT    GPIO_CTP_RST_PIN
#define GTP_INT_PORT    GPIO_CTP_EINT_PIN

#define GTP_GPIO_AS_INPUT(pin)          do{\
                                            if(pin == GPIO_CTP_EINT_PIN)\
                                                mt_set_gpio_mode(pin, GPIO_CTP_EINT_PIN_M_EINT);\
                                            else\
                                                mt_set_gpio_mode(pin, GPIO_CTP_RST_PIN_M_GPIO);\
                                            mt_set_gpio_dir(pin, GPIO_DIR_IN);\
                                            mt_set_gpio_pull_enable(pin, GPIO_PULL_DISABLE);\
                                        }while(0)
#define GTP_GPIO_AS_INT(pin)            do{\
                                            mt_set_gpio_mode(pin, GPIO_CTP_EINT_PIN_M_EINT);\
                                            mt_set_gpio_dir(pin, GPIO_DIR_IN);\
                                            mt_set_gpio_pull_enable(pin, GPIO_PULL_DISABLE);\
                                        }while(0)
#define GTP_GPIO_GET_VALUE(pin)         mt_get_gpio_in(pin)
#define GTP_GPIO_OUTPUT(pin,level)      do{\
                                            if(pin == GPIO_CTP_EINT_PIN)\
                                                mt_set_gpio_mode(pin, GPIO_CTP_EINT_PIN_M_GPIO);\
                                            else\
                                                mt_set_gpio_mode(pin, GPIO_CTP_RST_PIN_M_GPIO);\
                                            mt_set_gpio_dir(pin, GPIO_DIR_OUT);\
                                            mt_set_gpio_out(pin, level);\
                                        }while(0)

#define GTP_IRQ_TAB                     {IRQ_TYPE_EDGE_RISING, IRQ_TYPE_EDGE_FALLING, IRQ_TYPE_LEVEL_LOW, IRQ_TYPE_LEVEL_HIGH}
*/

#ifdef MT6589
extern void mt65xx_eint_unmask(unsigned int line);
extern void mt65xx_eint_mask(unsigned int line);
#define mt_eint_mask mt65xx_eint_mask
#define mt_eint_unmask mt65xx_eint_unmask
#endif

#define IIC_MAX_TRANSFER_SIZE         8
#define IIC_DMA_MAX_TRANSFER_SIZE     250
#define I2C_MASTER_CLOCK              300

#define TPD_MAX_RESET_COUNT           3

#define TPD_HAVE_CALIBRATION
#define TPD_CALIBRATION_MATRIX        {962,0,0,0,1600,0,0,0};

extern void tpd_on(void);
extern void tpd_off(void);

#endif /* GT1X_TPD_CUSTOM_H__ */
