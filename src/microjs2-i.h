/* 
 * Copyright(C) 2012 Robinson Mittmann. All Rights Reserved.
 * 
 * This file is part of the YARD-ICE.
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 3.0 of the License, or (at your option) any later version.
 * 
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 * 
 * You can receive a copy of the GNU Lesser General Public License from 
 * http://www.gnu.org/
 */

/** 
 * @file microjs2-i.h
 * @brief MicroJS
 * @author Robinson Mittmann <bobmittmann@gmail.com>
 */


/*****************************************************************************
 * MicroJS2 internal (private) header file
 *****************************************************************************/

#ifndef __MICROJS2_I_H__
#define __MICROJS2_I_H__

#ifndef __MICROJS2_I__
#error "Never use <microjs2-i.h> directly; include <microjs.h> instead."
#endif

#ifdef CONFIG_H
#include "config.h"
#endif

#include "microjs2_ll.h"

#define MICROJS_FUNCTIONS_ENABLED 1

#define __MICROJS_LL_H__
#define __MICROJS_I__
#include "microjs-i.h"

#endif /* __MICROJS2_I_H__ */

