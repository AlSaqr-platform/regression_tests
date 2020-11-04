/*
 * Copyright (C) 2018 ETH Zurich and University of Bologna
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/* 
 * Mantainer: Luca Valente, luca.valente2@unibo.it
 */
RT_LOCAL_DATA int16_t g_expresp[512] = {
0xFFEC,
0xFFEE,
0xFFED,
0xFFEE,
0xFFED,
0xFFED,
0xFFED,
0xFFEF,
0xFFEE,
0xFFED,
0xFFEE,
0xFFEE,
0xFFEE,
0xFFEE,
0xFFEF,
0xFFEE,
0xFFEF,
0xFFEE,
0xFFEF,
0xFFF0,
0xFFEF,
0xFFEF,
0xFFF0,
0xFFEF,
0xFFEF,
0xFFEF,
0xFFF1,
0xFFF0,
0xFFF1,
0xFFF1,
0xFFF0,
0xFFF1,
0xFFF0,
0xFFF0,
0xFFF1,
0xFFF0,
0xFFF2,
0xFFF0,
0xFFF2,
0xFFF2,
0xFFF1,
0xFFF1,
0xFFF2,
0xFFF3,
0xFFF4,
0xFFF3,
0xFFF3,
0xFFF3,
0xFFF1,
0xFFF3,
0xFFF3,
0xFFF3,
0xFFF3,
0xFFF2,
0xFFF5,
0xFFF3,
0xFFF3,
0xFFF3,
0xFFF4,
0xFFF5,
0xFFF4,
0xFFF3,
0xFFF4,
0xFFF5,
0xFFF4,
0xFFF5,
0xFFF4,
0xFFF6,
0xFFF4,
0xFFF5,
0xFFF5,
0xFFF7,
0xFFF5,
0xFFF5,
0xFFF7,
0xFFF6,
0xFFF6,
0xFFF7,
0xFFF6,
0xFFF6,
0xFFF6,
0xFFF6,
0xFFF8,
0xFFF8,
0xFFF9,
0xFFF8,
0xFFF7,
0xFFF8,
0xFFF8,
0xFFF8,
0xFFF8,
0xFFFA,
0xFFF9,
0xFFF9,
0xFFF8,
0xFFFA,
0xFFF9,
0xFFF9,
0xFFF9,
0xFFFA,
0xFFF9,
0xFFF9,
0xFFFA,
0xFFF9,
0xFFF9,
0xFFF9,
0xFFF8,
0xFFF9,
0xFFFA,
0xFFFA,
0xFFFB,
0xFFFA,
0xFFFA,
0xFFFB,
0xFFFA,
0xFFFB,
0xFFFB,
0xFFFB,
0xFFFA,
0xFFFC,
0xFFFA,
0xFFFB,
0xFFFD,
0xFFFD,
0xFFFD,
0xFFFB,
0xFFFE,
0xFFFD,
0xFFFC,
0xFFFC,
0xFFFD,
0xFFFC,
0xFFFD,
0xFFFD,
0xFFFE,
0xFFFC,
0xFFFD,
0xFFFC,
0xFFFE,
0xFFFE,
0xFFFE,
0xFFFE,
0xFFFE,
0xFFFD,
0xFFFE,
0xFFFF,
0xFFFF,
0xFFFE,
0xFFFF,
0xFFFF,
0xFFFE,
0xFFFF,
0xFFFF,
0xFFFF,
0xFFFF,
0x0000,
0xFFFF,
0x0001,
0x0000,
0xFFFF,
0x0000,
0x0000,
0x0002,
0xFFFF,
0x0002,
0x0002,
0x0001,
0x0001,
0x0001,
0x0001,
0x0001,
0x0002,
0x0001,
0x0002,
0x0002,
0x0002,
0x0004,
0x0002,
0x0003,
0x0003,
0x0004,
0x0003,
0x0002,
0x0002,
0x0003,
0x0003,
0x0005,
0x0004,
0x0005,
0x0004,
0x0004,
0x0005,
0x0004,
0x0005,
0x0004,
0x0004,
0x0004,
0x0007,
0x0006,
0x0004,
0x0005,
0x0005,
0x0006,
0x0005,
0x0005,
0x0006,
0x0006,
0x0006,
0x0006,
0x0006,
0x0007,
0x0007,
0x0006,
0x0007,
0x0007,
0x0006,
0x0006,
0x0006,
0x0009,
0x0007,
0x0007,
0x0009,
0x0007,
0x0007,
0x0009,
0x0009,
0x0009,
0x0008,
0x0009,
0x0009,
0x0008,
0x0009,
0x0009,
0x0009,
0x000A,
0x0007,
0x000A,
0x000A,
0x0009,
0x000A,
0x000B,
0x000C,
0x000B,
0x000C,
0x000B,
0x000B,
0x000B,
0x000B,
0x000B,
0x000C,
0x000C,
0x000C,
0x000C,
0x000C,
0x000C,
0x000D,
0x000C,
0x000E,
0x000D,
0x000E,
0x000D,
0x000D,
0x000D,
0x000D,
0x000C,
0x000D,
0x000E,
0x000E,
0x000E,
0x000E,
0x000D,
0x000E,
0x000D,
0x000E,
0x000F,
0x0010,
0x000F,
0x000F,
0x0010,
0x000F,
0x000F,
0x000F,
0x0011,
0x0010,
0x000F,
0x000F,
0x0010,
0x0011,
0x0010,
0x0010,
0x0011,
0x0012,
0x0010,
0x0012,
0x0012,
0x0010,
0x0011,
0x0011,
0x0012,
0x0011,
0x0012,
0x0013,
0x0011,
0x0013,
0x0011,
0x0011,
0x0013,
0x0013,
0x0013,
0x0014,
0x0013,
0x0013,
0x0013,
0x0013,
0x0014,
0x0013,
0x0014,
0x0015,
0x0014,
0x0015,
0x0014,
0x0015,
0x0014,
0x0016,
0x0014,
0x0015,
0x0015,
0x0015,
0x0015,
0x0015,
0x0015,
0x0016,
0x0016,
0x0015,
0x0016,
0x0016,
0x0016,
0x0016,
0x0016,
0x0018,
0x0017,
0x0018,
0x0017,
0x0018,
0x0018,
0x0018,
0x0018,
0x0018,
0x0017,
0x0017,
0x0018,
0x0018,
0x0017,
0x0017,
0x0019,
0x001A,
0x0019,
0x0019,
0x001A,
0x0019,
0x0019,
0x0019,
0x001A,
0x001B,
0x001A,
0x001A,
0x001B,
0x001A,
0x001A,
0x0019,
0x001C,
0x001B,
0x001B,
0x001B,
0x001C,
0x001C,
0x001C,
0x001B,
0x001D,
0x001B,
0x001B,
0x001B,
0x001C,
0x001B,
0x001C,
0x001C,
0x001D,
0x001C,
0x001D,
0x001D,
0x001C,
0x001C,
0x001D,
0x001E,
0x001E,
0x001E,
0x001E,
0x001E,
0x001E,
0x001F,
0x001E,
0x001D,
0x001F,
0x001E,
0x001F,
0x001F,
0x001E,
0x001F,
0x001F,
0x001F,
0x001F,
0x0020,
0x0021,
0x001F,
0x0020,
0x001F,
0x0020,
0x0020,
0x0020,
0x001F,
0x0020,
0x0020,
0x001F,
0x0021,
0x0021,
0x0021,
0x001F,
0x0022,
0x0021,
0x0020,
0x0022,
0x0020,
0x0022,
0x0022,
0x0023,
0x0023,
0x0022,
0x0023,
0x0022,
0x0024,
0x0023,
0x0023,
0x0023,
0x0024,
0x0023,
0x0024,
0x0024,
0x0025,
0x0024,
0x0025,
0x0024,
0x0024,
0x0024,
0x0023,
0x0024,
0x0024,
0x0025,
0x0025,
0x0026,
0x0027,
0x0027,
0x0026,
0x0026,
0x0026,
0x0026,
0x0026,
0x0027,
0x0025,
0x0026,
0x0025,
0x0027,
0x0026,
0x0026,
0x0026,
0x0027,
0x0027,
0x0029,
0x0027,
0x0029,
0x0027,
0x0027,
0x0027,
0x0029,
0x0028,
0x0029,
0x0029,
0x0028,
0x0029,
0x0029,
0x0029,
0x0028,
0x0029,
0x002A,
0x002A,
0x0029,
0x002A,
0x0029,
0x0028,
0x002B,
0x002A,
0x002B,
0x002B,
0x002B,
0x0029,
0x002B,
0x002A,
0x002A,
0x002C,
0x002C,
0x002A,
0x002A,
0x002B,
};