/*
  T41U5XBB_ss_map.h - driver code for IMXRT1062 processor (on Teensy 4.1 board)

  Part of grblHAL

  !!IMPORTANT!! This map is for a modified board, see https://github.com/terjeio/grblHAL/discussions/289 for details.

  Board by Phil Barrett: https://github.com/phil-barrett/grblHAL-teensy-4.x

  Copyright (c) 2020-2024 Terje Io

  grblHAL is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  grblHAL is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with grblHAL. If not, see <http://www.gnu.org/licenses/>.
*/

// Boar modification info: https://www.grbl.org/single-post/modifying-a-t41u5xbb-for-lathe-spindle-sync

#if N_ABC_MOTORS > 2
#error "Axis configuration is not supported!"
#endif

#if QEI_ENABLE && SPINDLE_SYNC_ENABLE
#error "Quadrature encoder and spindle sync cannot be enabled at the same time!"
#endif

#define BOARD_NAME "T41U5XBB"
#define BOARD_URL "https://github.com/phil-barrett/grbl-teensy-4"

#define X_STEP_PIN          (2u)
#define X_DIRECTION_PIN     (3u)
#define X_ENABLE_PIN        (10u)
#define X_LIMIT_PIN         (20u)

#define Y_STEP_PIN          (4u)
#define Y_DIRECTION_PIN     (5u)
#define Y_ENABLE_PIN        (40u)
#define Y_LIMIT_PIN         (21u)

#define Z_STEP_PIN          (6u)
#define Z_DIRECTION_PIN     (7u)
#define Z_ENABLE_PIN        (39u)
#define Z_LIMIT_PIN         (22u)

// Define ganged axis or A axis step pulse and step direction output pins.
#if N_ABC_MOTORS > 0
#define M3_AVAILABLE
#define M3_STEP_PIN         (8u)
#define M3_DIRECTION_PIN    (9u)
#define M3_LIMIT_PIN        (23u)
#define M3_ENABLE_PIN       (38u)
#endif

// Define ganged axis or B axis step pulse and step direction output pins.
#if N_ABC_MOTORS == 2
#define M4_AVAILABLE
#define M4_STEP_PIN         (26u)
#define M4_DIRECTION_PIN    (27u)
#define M4_LIMIT_PIN        (28u)
#define M4_ENABLE_PIN       (37u)
#endif

// Define spindle enable and spindle direction output pins.
#define SPINDLE_ENABLE_PIN      (12u)
#define SPINDLE_DIRECTION_PIN   (11u)
#define SPINDLE_PWM_PIN         (13u) // NOTE: only pin 12 or pin 13 can be assigned!

// Define driver spindle pins

#if DRIVER_SPINDLE_PWM_ENABLE
#define SPINDLE_PWM_PIN         (13u)
#else
#define AUXOUTPUT5_PIN          (13u)
#endif

#if DRIVER_SPINDLE_DIR_ENABLE
#define SPINDLE_DIRECTION_PIN   (11u)
#else
#define AUXOUTPUT4_PIN          (11u)
#endif

#if DRIVER_SPINDLE_ENABLE
#define SPINDLE_ENABLE_PIN      (12u)
#else
#define AUXOUTPUT3_PIN          (12u)
#endif

// Define flood and mist coolant enable output pins.
#define COOLANT_FLOOD_PIN   (19u)
#define COOLANT_MIST_PIN    (18u)

// Define user-control CONTROLs (cycle start, reset, feed hold, door) input pins.
#define RESET_PIN           (35u)
#define FEED_HOLD_PIN       (16u)
#define CYCLE_START_PIN     (17u)

// Define auxillary input pins
#define AUXINPUT0_PIN       (36u) // ST0
#if !QEI_ENABLE
#define AUXINPUT1_PIN       (30u) // ST1
#endif
#if !SPINDLE_SYNC_ENABLE && !QEI_ENABLE
#define AUXINPUT2_PIN       (34u) // ST2
#endif
#if !SPINDLE_SYNC_ENABLE
#define AUXINPUT3_PIN       (14u) // ST3
#endif
#define AUXINPUT4_PIN       (41u) // I2C strobe
#if !defined(M4_LIMIT_PIN)
#define AUXINPUT5_PIN       (28u) // MPG mode
#endif
#define AUXINPUT6_PIN       (29u) // Safety door
#define AUXINPUT7_PIN       (15u) // Probe

#if PROBE_ENABLE
#define PROBE_PIN           AUXINPUT7_PIN
#endif

#if SAFETY_DOOR_ENABLE
#define SAFETY_DOOR_PIN     AUXINPUT6_PIN
#endif

#if MPG_MODE == 1 && defined(AUXINPUT5_PIN)
#define MPG_MODE_PIN        AUXINPUT5_PIN
#endif

#if I2C_STROBE_ENABLE
#define I2C_STROBE_PIN      AUXINPUT4_PIN
#endif

#if MOTOR_FAULT_ENABLE
#define MOTOR_FAULT_PIN     AUXINPUT0_PIN
#endif

#if MOTOR_WARNING_ENABLE && !QEI_ENABLE
#define MOTOR_WARNING_PIN   AUXINPUT1_PIN
#endif

#if QEI_ENABLE
#define QEI_A_PIN           (30u) // ST1
#define QEI_B_PIN           (34u) // ST2
#ifdef AUXINPUT3_PIN
#define QEI_SELECT_PIN      AUXINPUT3_PIN // ST3
#endif
#endif

#if SPINDLE_SYNC_ENABLE
#define SPINDLE_INDEX_PIN   (34u) // ST2
#define SPINDLE_PULSE_PIN   (14u) // ST3
#endif

#define AUXOUTPUT0_PIN      (31u) // AUX0
#define AUXOUTPUT1_PIN      (32u) // AUX1
#define AUXOUTPUT2_PIN      (33u) // AUX2

#if I2C_ENABLE
#define I2C_PORT            4
#define I2C_SCL4            (24u) // Not referenced, for info only
#define I2C_SDA4            (25u) // Not referenced, for info only
#endif
