// Copyright 2022 Jose Pablo Ramirez (@jpe230)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#include_next <mcuconf.h>

//#undef RP_PWM_USE_PWM0
//#define RP_PWM_USE_PWM0 TRUE

#undef RP_PWM_USE_PWM3
#define RP_PWM_USE_PWM3 TRUE

#undef RP_SPI_USE_SPI0
#define RP_SPI_USE_SPI0 TRUE