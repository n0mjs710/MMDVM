/*
 *   Copyright (C) 2020 by Jonathan Naylor G4KLX
 *
 *   This program is free software; you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation; either version 2 of the License, or
 *   (at your option) any later version.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with this program; if not, write to the Free Software
 *   Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */

#if !defined(AX25Demodulator_H)
#define  AX25Demodulator_H

#include "Config.h"

#include "AX25Frame.h"


class CAX25Demodulator {
public:
  CAX25Demodulator();

  bool process(const q15_t* samples, uint8_t length, CAX25Frame& frame);

private:
  bool*    m_delayLine;
  uint16_t m_delayPos;
  bool     m_nrziState;

  bool delay(bool b);
  bool NRZI(bool b);
};

#endif

