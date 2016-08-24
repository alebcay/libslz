/* Fixed Huffman table as per RFC1951.
 *
 *       Lit Value    Bits        Codes
 *       ---------    ----        -----
 *         0 - 143     8          00110000 through  10111111
 *       144 - 255     9         110010000 through 111111111
 *       256 - 279     7           0000000 through   0010111
 *       280 - 287     8          11000000 through  11000111
 *
 * The codes are encoded in reverse, the high bit of the code appears encoded
 * as bit 0. The table is built by mkhuff.sh. The 16 bits are encoded this way :
 *  - bits 0..3  : bits
 *  - bits 4..12 : code
 */
static const uint16_t fixed_huff[288] = {
	0x00c8, 0x08c8, 0x04c8, 0x0cc8, 0x02c8, 0x0ac8, 0x06c8, 0x0ec8, //   0
	0x01c8, 0x09c8, 0x05c8, 0x0dc8, 0x03c8, 0x0bc8, 0x07c8, 0x0fc8, //   8
	0x0028, 0x0828, 0x0428, 0x0c28, 0x0228, 0x0a28, 0x0628, 0x0e28, //  16
	0x0128, 0x0928, 0x0528, 0x0d28, 0x0328, 0x0b28, 0x0728, 0x0f28, //  24
	0x00a8, 0x08a8, 0x04a8, 0x0ca8, 0x02a8, 0x0aa8, 0x06a8, 0x0ea8, //  32
	0x01a8, 0x09a8, 0x05a8, 0x0da8, 0x03a8, 0x0ba8, 0x07a8, 0x0fa8, //  40
	0x0068, 0x0868, 0x0468, 0x0c68, 0x0268, 0x0a68, 0x0668, 0x0e68, //  48
	0x0168, 0x0968, 0x0568, 0x0d68, 0x0368, 0x0b68, 0x0768, 0x0f68, //  56
	0x00e8, 0x08e8, 0x04e8, 0x0ce8, 0x02e8, 0x0ae8, 0x06e8, 0x0ee8, //  64
	0x01e8, 0x09e8, 0x05e8, 0x0de8, 0x03e8, 0x0be8, 0x07e8, 0x0fe8, //  72
	0x0018, 0x0818, 0x0418, 0x0c18, 0x0218, 0x0a18, 0x0618, 0x0e18, //  80
	0x0118, 0x0918, 0x0518, 0x0d18, 0x0318, 0x0b18, 0x0718, 0x0f18, //  88
	0x0098, 0x0898, 0x0498, 0x0c98, 0x0298, 0x0a98, 0x0698, 0x0e98, //  96
	0x0198, 0x0998, 0x0598, 0x0d98, 0x0398, 0x0b98, 0x0798, 0x0f98, // 104
	0x0058, 0x0858, 0x0458, 0x0c58, 0x0258, 0x0a58, 0x0658, 0x0e58, // 112
	0x0158, 0x0958, 0x0558, 0x0d58, 0x0358, 0x0b58, 0x0758, 0x0f58, // 120
	0x00d8, 0x08d8, 0x04d8, 0x0cd8, 0x02d8, 0x0ad8, 0x06d8, 0x0ed8, // 128
	0x01d8, 0x09d8, 0x05d8, 0x0dd8, 0x03d8, 0x0bd8, 0x07d8, 0x0fd8, // 136
	0x0139, 0x1139, 0x0939, 0x1939, 0x0539, 0x1539, 0x0d39, 0x1d39, // 144
	0x0339, 0x1339, 0x0b39, 0x1b39, 0x0739, 0x1739, 0x0f39, 0x1f39, // 152
	0x00b9, 0x10b9, 0x08b9, 0x18b9, 0x04b9, 0x14b9, 0x0cb9, 0x1cb9, // 160
	0x02b9, 0x12b9, 0x0ab9, 0x1ab9, 0x06b9, 0x16b9, 0x0eb9, 0x1eb9, // 168
	0x01b9, 0x11b9, 0x09b9, 0x19b9, 0x05b9, 0x15b9, 0x0db9, 0x1db9, // 176
	0x03b9, 0x13b9, 0x0bb9, 0x1bb9, 0x07b9, 0x17b9, 0x0fb9, 0x1fb9, // 184
	0x0079, 0x1079, 0x0879, 0x1879, 0x0479, 0x1479, 0x0c79, 0x1c79, // 192
	0x0279, 0x1279, 0x0a79, 0x1a79, 0x0679, 0x1679, 0x0e79, 0x1e79, // 200
	0x0179, 0x1179, 0x0979, 0x1979, 0x0579, 0x1579, 0x0d79, 0x1d79, // 208
	0x0379, 0x1379, 0x0b79, 0x1b79, 0x0779, 0x1779, 0x0f79, 0x1f79, // 216
	0x00f9, 0x10f9, 0x08f9, 0x18f9, 0x04f9, 0x14f9, 0x0cf9, 0x1cf9, // 224
	0x02f9, 0x12f9, 0x0af9, 0x1af9, 0x06f9, 0x16f9, 0x0ef9, 0x1ef9, // 232
	0x01f9, 0x11f9, 0x09f9, 0x19f9, 0x05f9, 0x15f9, 0x0df9, 0x1df9, // 240
	0x03f9, 0x13f9, 0x0bf9, 0x1bf9, 0x07f9, 0x17f9, 0x0ff9, 0x1ff9, // 248
	0x0007, 0x0407, 0x0207, 0x0607, 0x0107, 0x0507, 0x0307, 0x0707, // 256
	0x0087, 0x0487, 0x0287, 0x0687, 0x0187, 0x0587, 0x0387, 0x0787, // 264
	0x0047, 0x0447, 0x0247, 0x0647, 0x0147, 0x0547, 0x0347, 0x0747, // 272
	0x0038, 0x0838, 0x0438, 0x0c38, 0x0238, 0x0a38, 0x0638, 0x0e38  // 280
};

/* length from 3 to 258 converted to bit strings for use with fixed huffman
 * coding. It was built by tools/dump_len.c. The format is the following :
 *   - bits 0..15  = code
 *   - bits 16..19 = #bits
 */
static const uint32_t len_fh[259] = {
	0x000000,  0x000000,  0x000000,  0x070040,   /* 0-3 */
	0x070020,  0x070060,  0x070010,  0x070050,   /* 4-7 */
	0x070030,  0x070070,  0x070008,  0x080048,   /* 8-11 */
	0x0800c8,  0x080028,  0x0800a8,  0x080068,   /* 12-15 */
	0x0800e8,  0x080018,  0x080098,  0x090058,   /* 16-19 */
	0x0900d8,  0x090158,  0x0901d8,  0x090038,   /* 20-23 */
	0x0900b8,  0x090138,  0x0901b8,  0x090078,   /* 24-27 */
	0x0900f8,  0x090178,  0x0901f8,  0x090004,   /* 28-31 */
	0x090084,  0x090104,  0x090184,  0x0a0044,   /* 32-35 */
	0x0a00c4,  0x0a0144,  0x0a01c4,  0x0a0244,   /* 36-39 */
	0x0a02c4,  0x0a0344,  0x0a03c4,  0x0a0024,   /* 40-43 */
	0x0a00a4,  0x0a0124,  0x0a01a4,  0x0a0224,   /* 44-47 */
	0x0a02a4,  0x0a0324,  0x0a03a4,  0x0a0064,   /* 48-51 */
	0x0a00e4,  0x0a0164,  0x0a01e4,  0x0a0264,   /* 52-55 */
	0x0a02e4,  0x0a0364,  0x0a03e4,  0x0a0014,   /* 56-59 */
	0x0a0094,  0x0a0114,  0x0a0194,  0x0a0214,   /* 60-63 */
	0x0a0294,  0x0a0314,  0x0a0394,  0x0b0054,   /* 64-67 */
	0x0b00d4,  0x0b0154,  0x0b01d4,  0x0b0254,   /* 68-71 */
	0x0b02d4,  0x0b0354,  0x0b03d4,  0x0b0454,   /* 72-75 */
	0x0b04d4,  0x0b0554,  0x0b05d4,  0x0b0654,   /* 76-79 */
	0x0b06d4,  0x0b0754,  0x0b07d4,  0x0b0034,   /* 80-83 */
	0x0b00b4,  0x0b0134,  0x0b01b4,  0x0b0234,   /* 84-87 */
	0x0b02b4,  0x0b0334,  0x0b03b4,  0x0b0434,   /* 88-91 */
	0x0b04b4,  0x0b0534,  0x0b05b4,  0x0b0634,   /* 92-95 */
	0x0b06b4,  0x0b0734,  0x0b07b4,  0x0b0074,   /* 96-99 */
	0x0b00f4,  0x0b0174,  0x0b01f4,  0x0b0274,   /* 100-103 */
	0x0b02f4,  0x0b0374,  0x0b03f4,  0x0b0474,   /* 104-107 */
	0x0b04f4,  0x0b0574,  0x0b05f4,  0x0b0674,   /* 108-111 */
	0x0b06f4,  0x0b0774,  0x0b07f4,  0x0c0003,   /* 112-115 */
	0x0c0103,  0x0c0203,  0x0c0303,  0x0c0403,   /* 116-119 */
	0x0c0503,  0x0c0603,  0x0c0703,  0x0c0803,   /* 120-123 */
	0x0c0903,  0x0c0a03,  0x0c0b03,  0x0c0c03,   /* 124-127 */
	0x0c0d03,  0x0c0e03,  0x0c0f03,  0x0d0083,   /* 128-131 */
	0x0d0183,  0x0d0283,  0x0d0383,  0x0d0483,   /* 132-135 */
	0x0d0583,  0x0d0683,  0x0d0783,  0x0d0883,   /* 136-139 */
	0x0d0983,  0x0d0a83,  0x0d0b83,  0x0d0c83,   /* 140-143 */
	0x0d0d83,  0x0d0e83,  0x0d0f83,  0x0d1083,   /* 144-147 */
	0x0d1183,  0x0d1283,  0x0d1383,  0x0d1483,   /* 148-151 */
	0x0d1583,  0x0d1683,  0x0d1783,  0x0d1883,   /* 152-155 */
	0x0d1983,  0x0d1a83,  0x0d1b83,  0x0d1c83,   /* 156-159 */
	0x0d1d83,  0x0d1e83,  0x0d1f83,  0x0d0043,   /* 160-163 */
	0x0d0143,  0x0d0243,  0x0d0343,  0x0d0443,   /* 164-167 */
	0x0d0543,  0x0d0643,  0x0d0743,  0x0d0843,   /* 168-171 */
	0x0d0943,  0x0d0a43,  0x0d0b43,  0x0d0c43,   /* 172-175 */
	0x0d0d43,  0x0d0e43,  0x0d0f43,  0x0d1043,   /* 176-179 */
	0x0d1143,  0x0d1243,  0x0d1343,  0x0d1443,   /* 180-183 */
	0x0d1543,  0x0d1643,  0x0d1743,  0x0d1843,   /* 184-187 */
	0x0d1943,  0x0d1a43,  0x0d1b43,  0x0d1c43,   /* 188-191 */
	0x0d1d43,  0x0d1e43,  0x0d1f43,  0x0d00c3,   /* 192-195 */
	0x0d01c3,  0x0d02c3,  0x0d03c3,  0x0d04c3,   /* 196-199 */
	0x0d05c3,  0x0d06c3,  0x0d07c3,  0x0d08c3,   /* 200-203 */
	0x0d09c3,  0x0d0ac3,  0x0d0bc3,  0x0d0cc3,   /* 204-207 */
	0x0d0dc3,  0x0d0ec3,  0x0d0fc3,  0x0d10c3,   /* 208-211 */
	0x0d11c3,  0x0d12c3,  0x0d13c3,  0x0d14c3,   /* 212-215 */
	0x0d15c3,  0x0d16c3,  0x0d17c3,  0x0d18c3,   /* 216-219 */
	0x0d19c3,  0x0d1ac3,  0x0d1bc3,  0x0d1cc3,   /* 220-223 */
	0x0d1dc3,  0x0d1ec3,  0x0d1fc3,  0x0d0023,   /* 224-227 */
	0x0d0123,  0x0d0223,  0x0d0323,  0x0d0423,   /* 228-231 */
	0x0d0523,  0x0d0623,  0x0d0723,  0x0d0823,   /* 232-235 */
	0x0d0923,  0x0d0a23,  0x0d0b23,  0x0d0c23,   /* 236-239 */
	0x0d0d23,  0x0d0e23,  0x0d0f23,  0x0d1023,   /* 240-243 */
	0x0d1123,  0x0d1223,  0x0d1323,  0x0d1423,   /* 244-247 */
	0x0d1523,  0x0d1623,  0x0d1723,  0x0d1823,   /* 248-251 */
	0x0d1923,  0x0d1a23,  0x0d1b23,  0x0d1c23,   /* 252-255 */
	0x0d1d23,  0x0d1e23,  0x0800a3               /* 256-258 */
};

/* Table of *inverted* CRC32 for each 8-bit quantity based on the position of
 * the byte being read relative to the last byte. Eg: [0] means we're on the
 * last byte, [1] on the previous one etc. These values have 8 inverted bits
 * at each position so that when processing 32-bit little endian quantities,
 * the CRC already appears inverted in each individual byte and doesn't need
 * to be inverted again in the loop. The precomputed version was generated by
 * mkcrc.sh.
 */
#ifndef PRECOMPUTE_TABLES

static uint32_t crc32_fast[4][256];

#else  /* ifndef PRECOMPUTE_TABLES */

static const uint32_t crc32_fast[4][256] = {
	{ // [0]
		0xd202ef8d, 0xa505df1b, 0x3c0c8ea1, 0x4b0bbe37, // 0-3
		0xd56f2b94, 0xa2681b02, 0x3b614ab8, 0x4c667a2e, // 4-7
		0xdcd967bf, 0xabde5729, 0x32d70693, 0x45d03605, // 8-11
		0xdbb4a3a6, 0xacb39330, 0x35bac28a, 0x42bdf21c, // 12-15
		0xcfb5ffe9, 0xb8b2cf7f, 0x21bb9ec5, 0x56bcae53, // 16-19
		0xc8d83bf0, 0xbfdf0b66, 0x26d65adc, 0x51d16a4a, // 20-23
		0xc16e77db, 0xb669474d, 0x2f6016f7, 0x58672661, // 24-27
		0xc603b3c2, 0xb1048354, 0x280dd2ee, 0x5f0ae278, // 28-31
		0xe96ccf45, 0x9e6bffd3, 0x0762ae69, 0x70659eff, // 32-35
		0xee010b5c, 0x99063bca, 0x000f6a70, 0x77085ae6, // 36-39
		0xe7b74777, 0x90b077e1, 0x09b9265b, 0x7ebe16cd, // 40-43
		0xe0da836e, 0x97ddb3f8, 0x0ed4e242, 0x79d3d2d4, // 44-47
		0xf4dbdf21, 0x83dcefb7, 0x1ad5be0d, 0x6dd28e9b, // 48-51
		0xf3b61b38, 0x84b12bae, 0x1db87a14, 0x6abf4a82, // 52-55
		0xfa005713, 0x8d076785, 0x140e363f, 0x630906a9, // 56-59
		0xfd6d930a, 0x8a6aa39c, 0x1363f226, 0x6464c2b0, // 60-63
		0xa4deae1d, 0xd3d99e8b, 0x4ad0cf31, 0x3dd7ffa7, // 64-67
		0xa3b36a04, 0xd4b45a92, 0x4dbd0b28, 0x3aba3bbe, // 68-71
		0xaa05262f, 0xdd0216b9, 0x440b4703, 0x330c7795, // 72-75
		0xad68e236, 0xda6fd2a0, 0x4366831a, 0x3461b38c, // 76-79
		0xb969be79, 0xce6e8eef, 0x5767df55, 0x2060efc3, // 80-83
		0xbe047a60, 0xc9034af6, 0x500a1b4c, 0x270d2bda, // 84-87
		0xb7b2364b, 0xc0b506dd, 0x59bc5767, 0x2ebb67f1, // 88-91
		0xb0dff252, 0xc7d8c2c4, 0x5ed1937e, 0x29d6a3e8, // 92-95
		0x9fb08ed5, 0xe8b7be43, 0x71beeff9, 0x06b9df6f, // 96-99
		0x98dd4acc, 0xefda7a5a, 0x76d32be0, 0x01d41b76, // 100-103
		0x916b06e7, 0xe66c3671, 0x7f6567cb, 0x0862575d, // 104-107
		0x9606c2fe, 0xe101f268, 0x7808a3d2, 0x0f0f9344, // 108-111
		0x82079eb1, 0xf500ae27, 0x6c09ff9d, 0x1b0ecf0b, // 112-115
		0x856a5aa8, 0xf26d6a3e, 0x6b643b84, 0x1c630b12, // 116-119
		0x8cdc1683, 0xfbdb2615, 0x62d277af, 0x15d54739, // 120-123
		0x8bb1d29a, 0xfcb6e20c, 0x65bfb3b6, 0x12b88320, // 124-127
		0x3fba6cad, 0x48bd5c3b, 0xd1b40d81, 0xa6b33d17, // 128-131
		0x38d7a8b4, 0x4fd09822, 0xd6d9c998, 0xa1def90e, // 132-135
		0x3161e49f, 0x4666d409, 0xdf6f85b3, 0xa868b525, // 136-139
		0x360c2086, 0x410b1010, 0xd80241aa, 0xaf05713c, // 140-143
		0x220d7cc9, 0x550a4c5f, 0xcc031de5, 0xbb042d73, // 144-147
		0x2560b8d0, 0x52678846, 0xcb6ed9fc, 0xbc69e96a, // 148-151
		0x2cd6f4fb, 0x5bd1c46d, 0xc2d895d7, 0xb5dfa541, // 152-155
		0x2bbb30e2, 0x5cbc0074, 0xc5b551ce, 0xb2b26158, // 156-159
		0x04d44c65, 0x73d37cf3, 0xeada2d49, 0x9ddd1ddf, // 160-163
		0x03b9887c, 0x74beb8ea, 0xedb7e950, 0x9ab0d9c6, // 164-167
		0x0a0fc457, 0x7d08f4c1, 0xe401a57b, 0x930695ed, // 168-171
		0x0d62004e, 0x7a6530d8, 0xe36c6162, 0x946b51f4, // 172-175
		0x19635c01, 0x6e646c97, 0xf76d3d2d, 0x806a0dbb, // 176-179
		0x1e0e9818, 0x6909a88e, 0xf000f934, 0x8707c9a2, // 180-183
		0x17b8d433, 0x60bfe4a5, 0xf9b6b51f, 0x8eb18589, // 184-187
		0x10d5102a, 0x67d220bc, 0xfedb7106, 0x89dc4190, // 188-191
		0x49662d3d, 0x3e611dab, 0xa7684c11, 0xd06f7c87, // 192-195
		0x4e0be924, 0x390cd9b2, 0xa0058808, 0xd702b89e, // 196-199
		0x47bda50f, 0x30ba9599, 0xa9b3c423, 0xdeb4f4b5, // 200-203
		0x40d06116, 0x37d75180, 0xaede003a, 0xd9d930ac, // 204-207
		0x54d13d59, 0x23d60dcf, 0xbadf5c75, 0xcdd86ce3, // 208-211
		0x53bcf940, 0x24bbc9d6, 0xbdb2986c, 0xcab5a8fa, // 212-215
		0x5a0ab56b, 0x2d0d85fd, 0xb404d447, 0xc303e4d1, // 216-219
		0x5d677172, 0x2a6041e4, 0xb369105e, 0xc46e20c8, // 220-223
		0x72080df5, 0x050f3d63, 0x9c066cd9, 0xeb015c4f, // 224-227
		0x7565c9ec, 0x0262f97a, 0x9b6ba8c0, 0xec6c9856, // 228-231
		0x7cd385c7, 0x0bd4b551, 0x92dde4eb, 0xe5dad47d, // 232-235
		0x7bbe41de, 0x0cb97148, 0x95b020f2, 0xe2b71064, // 236-239
		0x6fbf1d91, 0x18b82d07, 0x81b17cbd, 0xf6b64c2b, // 240-243
		0x68d2d988, 0x1fd5e91e, 0x86dcb8a4, 0xf1db8832, // 244-247
		0x616495a3, 0x1663a535, 0x8f6af48f, 0xf86dc419, // 248-251
		0x660951ba, 0x110e612c, 0x88073096, 0xff000000, // 252-255
	},
	{ // [1]
		0x93dbfd72, 0x8ac0cc33, 0xa1ed9ff0, 0xb8f6aeb1, // 0-3
		0xf7b73876, 0xeeac0937, 0xc5815af4, 0xdc9a6bb5, // 4-7
		0x5b02777a, 0x4219463b, 0x693415f8, 0x702f24b9, // 8-11
		0x3f6eb27e, 0x2675833f, 0x0d58d0fc, 0x1443e1bd, // 12-15
		0xd919ef23, 0xc002de62, 0xeb2f8da1, 0xf234bce0, // 16-19
		0xbd752a27, 0xa46e1b66, 0x8f4348a5, 0x965879e4, // 20-23
		0x11c0652b, 0x08db546a, 0x23f607a9, 0x3aed36e8, // 24-27
		0x75aca02f, 0x6cb7916e, 0x479ac2ad, 0x5e81f3ec, // 28-31
		0x065fd9d0, 0x1f44e891, 0x3469bb52, 0x2d728a13, // 32-35
		0x62331cd4, 0x7b282d95, 0x50057e56, 0x491e4f17, // 36-39
		0xce8653d8, 0xd79d6299, 0xfcb0315a, 0xe5ab001b, // 40-43
		0xaaea96dc, 0xb3f1a79d, 0x98dcf45e, 0x81c7c51f, // 44-47
		0x4c9dcb81, 0x5586fac0, 0x7eaba903, 0x67b09842, // 48-51
		0x28f10e85, 0x31ea3fc4, 0x1ac76c07, 0x03dc5d46, // 52-55
		0x84444189, 0x9d5f70c8, 0xb672230b, 0xaf69124a, // 56-59
		0xe028848d, 0xf933b5cc, 0xd21ee60f, 0xcb05d74e, // 60-63
		0x63a2b277, 0x7ab98336, 0x5194d0f5, 0x488fe1b4, // 64-67
		0x07ce7773, 0x1ed54632, 0x35f815f1, 0x2ce324b0, // 68-71
		0xab7b387f, 0xb260093e, 0x994d5afd, 0x80566bbc, // 72-75
		0xcf17fd7b, 0xd60ccc3a, 0xfd219ff9, 0xe43aaeb8, // 76-79
		0x2960a026, 0x307b9167, 0x1b56c2a4, 0x024df3e5, // 80-83
		0x4d0c6522, 0x54175463, 0x7f3a07a0, 0x662136e1, // 84-87
		0xe1b92a2e, 0xf8a21b6f, 0xd38f48ac, 0xca9479ed, // 88-91
		0x85d5ef2a, 0x9ccede6b, 0xb7e38da8, 0xaef8bce9, // 92-95
		0xf62696d5, 0xef3da794, 0xc410f457, 0xdd0bc516, // 96-99
		0x924a53d1, 0x8b516290, 0xa07c3153, 0xb9670012, // 100-103
		0x3eff1cdd, 0x27e42d9c, 0x0cc97e5f, 0x15d24f1e, // 104-107
		0x5a93d9d9, 0x4388e898, 0x68a5bb5b, 0x71be8a1a, // 108-111
		0xbce48484, 0xa5ffb5c5, 0x8ed2e606, 0x97c9d747, // 112-115
		0xd8884180, 0xc19370c1, 0xeabe2302, 0xf3a51243, // 116-119
		0x743d0e8c, 0x6d263fcd, 0x460b6c0e, 0x5f105d4f, // 120-123
		0x1051cb88, 0x094afac9, 0x2267a90a, 0x3b7c984b, // 124-127
		0xa8586539, 0xb1435478, 0x9a6e07bb, 0x837536fa, // 128-131
		0xcc34a03d, 0xd52f917c, 0xfe02c2bf, 0xe719f3fe, // 132-135
		0x6081ef31, 0x799ade70, 0x52b78db3, 0x4bacbcf2, // 136-139
		0x04ed2a35, 0x1df61b74, 0x36db48b7, 0x2fc079f6, // 140-143
		0xe29a7768, 0xfb814629, 0xd0ac15ea, 0xc9b724ab, // 144-147
		0x86f6b26c, 0x9fed832d, 0xb4c0d0ee, 0xaddbe1af, // 148-151
		0x2a43fd60, 0x3358cc21, 0x18759fe2, 0x016eaea3, // 152-155
		0x4e2f3864, 0x57340925, 0x7c195ae6, 0x65026ba7, // 156-159
		0x3ddc419b, 0x24c770da, 0x0fea2319, 0x16f11258, // 160-163
		0x59b0849f, 0x40abb5de, 0x6b86e61d, 0x729dd75c, // 164-167
		0xf505cb93, 0xec1efad2, 0xc733a911, 0xde289850, // 168-171
		0x91690e97, 0x88723fd6, 0xa35f6c15, 0xba445d54, // 172-175
		0x771e53ca, 0x6e05628b, 0x45283148, 0x5c330009, // 176-179
		0x137296ce, 0x0a69a78f, 0x2144f44c, 0x385fc50d, // 180-183
		0xbfc7d9c2, 0xa6dce883, 0x8df1bb40, 0x94ea8a01, // 184-187
		0xdbab1cc6, 0xc2b02d87, 0xe99d7e44, 0xf0864f05, // 188-191
		0x58212a3c, 0x413a1b7d, 0x6a1748be, 0x730c79ff, // 192-195
		0x3c4def38, 0x2556de79, 0x0e7b8dba, 0x1760bcfb, // 196-199
		0x90f8a034, 0x89e39175, 0xa2cec2b6, 0xbbd5f3f7, // 200-203
		0xf4946530, 0xed8f5471, 0xc6a207b2, 0xdfb936f3, // 204-207
		0x12e3386d, 0x0bf8092c, 0x20d55aef, 0x39ce6bae, // 208-211
		0x768ffd69, 0x6f94cc28, 0x44b99feb, 0x5da2aeaa, // 212-215
		0xda3ab265, 0xc3218324, 0xe80cd0e7, 0xf117e1a6, // 216-219
		0xbe567761, 0xa74d4620, 0x8c6015e3, 0x957b24a2, // 220-223
		0xcda50e9e, 0xd4be3fdf, 0xff936c1c, 0xe6885d5d, // 224-227
		0xa9c9cb9a, 0xb0d2fadb, 0x9bffa918, 0x82e49859, // 228-231
		0x057c8496, 0x1c67b5d7, 0x374ae614, 0x2e51d755, // 232-235
		0x61104192, 0x780b70d3, 0x53262310, 0x4a3d1251, // 236-239
		0x87671ccf, 0x9e7c2d8e, 0xb5517e4d, 0xac4a4f0c, // 240-243
		0xe30bd9cb, 0xfa10e88a, 0xd13dbb49, 0xc8268a08, // 244-247
		0x4fbe96c7, 0x56a5a786, 0x7d88f445, 0x6493c504, // 248-251
		0x2bd253c3, 0x32c96282, 0x19e43141, 0x00ff0000, // 252-255
	},
	{ // [2]
		0xbe98cbed, 0xbf5aa1da, 0xbd1c1f83, 0xbcde75b4, // 0-3
		0xb9916331, 0xb8530906, 0xba15b75f, 0xbbd7dd68, // 4-7
		0xb08b9a55, 0xb149f062, 0xb30f4e3b, 0xb2cd240c, // 8-11
		0xb7823289, 0xb64058be, 0xb406e6e7, 0xb5c48cd0, // 12-15
		0xa2be689d, 0xa37c02aa, 0xa13abcf3, 0xa0f8d6c4, // 16-19
		0xa5b7c041, 0xa475aa76, 0xa633142f, 0xa7f17e18, // 20-23
		0xacad3925, 0xad6f5312, 0xaf29ed4b, 0xaeeb877c, // 24-27
		0xaba491f9, 0xaa66fbce, 0xa8204597, 0xa9e22fa0, // 28-31
		0x86d58d0d, 0x8717e73a, 0x85515963, 0x84933354, // 32-35
		0x81dc25d1, 0x801e4fe6, 0x8258f1bf, 0x839a9b88, // 36-39
		0x88c6dcb5, 0x8904b682, 0x8b4208db, 0x8a8062ec, // 40-43
		0x8fcf7469, 0x8e0d1e5e, 0x8c4ba007, 0x8d89ca30, // 44-47
		0x9af32e7d, 0x9b31444a, 0x9977fa13, 0x98b59024, // 48-51
		0x9dfa86a1, 0x9c38ec96, 0x9e7e52cf, 0x9fbc38f8, // 52-55
		0x94e07fc5, 0x952215f2, 0x9764abab, 0x96a6c19c, // 56-59
		0x93e9d719, 0x922bbd2e, 0x906d0377, 0x91af6940, // 60-63
		0xce02462d, 0xcfc02c1a, 0xcd869243, 0xcc44f874, // 64-67
		0xc90beef1, 0xc8c984c6, 0xca8f3a9f, 0xcb4d50a8, // 68-71
		0xc0111795, 0xc1d37da2, 0xc395c3fb, 0xc257a9cc, // 72-75
		0xc718bf49, 0xc6dad57e, 0xc49c6b27, 0xc55e0110, // 76-79
		0xd224e55d, 0xd3e68f6a, 0xd1a03133, 0xd0625b04, // 80-83
		0xd52d4d81, 0xd4ef27b6, 0xd6a999ef, 0xd76bf3d8, // 84-87
		0xdc37b4e5, 0xddf5ded2, 0xdfb3608b, 0xde710abc, // 88-91
		0xdb3e1c39, 0xdafc760e, 0xd8bac857, 0xd978a260, // 92-95
		0xf64f00cd, 0xf78d6afa, 0xf5cbd4a3, 0xf409be94, // 96-99
		0xf146a811, 0xf084c226, 0xf2c27c7f, 0xf3001648, // 100-103
		0xf85c5175, 0xf99e3b42, 0xfbd8851b, 0xfa1aef2c, // 104-107
		0xff55f9a9, 0xfe97939e, 0xfcd12dc7, 0xfd1347f0, // 108-111
		0xea69a3bd, 0xebabc98a, 0xe9ed77d3, 0xe82f1de4, // 112-115
		0xed600b61, 0xeca26156, 0xeee4df0f, 0xef26b538, // 116-119
		0xe47af205, 0xe5b89832, 0xe7fe266b, 0xe63c4c5c, // 120-123
		0xe3735ad9, 0xe2b130ee, 0xe0f78eb7, 0xe135e480, // 124-127
		0x5fadd06d, 0x5e6fba5a, 0x5c290403, 0x5deb6e34, // 128-131
		0x58a478b1, 0x59661286, 0x5b20acdf, 0x5ae2c6e8, // 132-135
		0x51be81d5, 0x507cebe2, 0x523a55bb, 0x53f83f8c, // 136-139
		0x56b72909, 0x5775433e, 0x5533fd67, 0x54f19750, // 140-143
		0x438b731d, 0x4249192a, 0x400fa773, 0x41cdcd44, // 144-147
		0x4482dbc1, 0x4540b1f6, 0x47060faf, 0x46c46598, // 148-151
		0x4d9822a5, 0x4c5a4892, 0x4e1cf6cb, 0x4fde9cfc, // 152-155
		0x4a918a79, 0x4b53e04e, 0x49155e17, 0x48d73420, // 156-159
		0x67e0968d, 0x6622fcba, 0x646442e3, 0x65a628d4, // 160-163
		0x60e93e51, 0x612b5466, 0x636dea3f, 0x62af8008, // 164-167
		0x69f3c735, 0x6831ad02, 0x6a77135b, 0x6bb5796c, // 168-171
		0x6efa6fe9, 0x6f3805de, 0x6d7ebb87, 0x6cbcd1b0, // 172-175
		0x7bc635fd, 0x7a045fca, 0x7842e193, 0x79808ba4, // 176-179
		0x7ccf9d21, 0x7d0df716, 0x7f4b494f, 0x7e892378, // 180-183
		0x75d56445, 0x74170e72, 0x7651b02b, 0x7793da1c, // 184-187
		0x72dccc99, 0x731ea6ae, 0x715818f7, 0x709a72c0, // 188-191
		0x2f375dad, 0x2ef5379a, 0x2cb389c3, 0x2d71e3f4, // 192-195
		0x283ef571, 0x29fc9f46, 0x2bba211f, 0x2a784b28, // 196-199
		0x21240c15, 0x20e66622, 0x22a0d87b, 0x2362b24c, // 200-203
		0x262da4c9, 0x27efcefe, 0x25a970a7, 0x246b1a90, // 204-207
		0x3311fedd, 0x32d394ea, 0x30952ab3, 0x31574084, // 208-211
		0x34185601, 0x35da3c36, 0x379c826f, 0x365ee858, // 212-215
		0x3d02af65, 0x3cc0c552, 0x3e867b0b, 0x3f44113c, // 216-219
		0x3a0b07b9, 0x3bc96d8e, 0x398fd3d7, 0x384db9e0, // 220-223
		0x177a1b4d, 0x16b8717a, 0x14fecf23, 0x153ca514, // 224-227
		0x1073b391, 0x11b1d9a6, 0x13f767ff, 0x12350dc8, // 228-231
		0x19694af5, 0x18ab20c2, 0x1aed9e9b, 0x1b2ff4ac, // 232-235
		0x1e60e229, 0x1fa2881e, 0x1de43647, 0x1c265c70, // 236-239
		0x0b5cb83d, 0x0a9ed20a, 0x08d86c53, 0x091a0664, // 240-243
		0x0c5510e1, 0x0d977ad6, 0x0fd1c48f, 0x0e13aeb8, // 244-247
		0x054fe985, 0x048d83b2, 0x06cb3deb, 0x070957dc, // 248-251
		0x02464159, 0x03842b6e, 0x01c29537, 0x0000ff00, // 252-255
	},
	{ // [3]
		0xde05060e, 0x66b9616b, 0x740cce85, 0xccb0a9e0, // 0-3
		0x51679159, 0xe9dbf63c, 0xfb6e59d2, 0x43d23eb7, // 4-7
		0x1bb12ee1, 0xa30d4984, 0xb1b8e66a, 0x0904810f, // 8-11
		0x94d3b9b6, 0x2c6fded3, 0x3eda713d, 0x86661658, // 12-15
		0x8e1c5191, 0x36a036f4, 0x2415991a, 0x9ca9fe7f, // 16-19
		0x017ec6c6, 0xb9c2a1a3, 0xab770e4d, 0x13cb6928, // 20-23
		0x4ba8797e, 0xf3141e1b, 0xe1a1b1f5, 0x591dd690, // 24-27
		0xc4caee29, 0x7c76894c, 0x6ec326a2, 0xd67f41c7, // 28-31
		0x7e37a930, 0xc68bce55, 0xd43e61bb, 0x6c8206de, // 32-35
		0xf1553e67, 0x49e95902, 0x5b5cf6ec, 0xe3e09189, // 36-39
		0xbb8381df, 0x033fe6ba, 0x118a4954, 0xa9362e31, // 40-43
		0x34e11688, 0x8c5d71ed, 0x9ee8de03, 0x2654b966, // 44-47
		0x2e2efeaf, 0x969299ca, 0x84273624, 0x3c9b5141, // 48-51
		0xa14c69f8, 0x19f00e9d, 0x0b45a173, 0xb3f9c616, // 52-55
		0xeb9ad640, 0x5326b125, 0x41931ecb, 0xf92f79ae, // 56-59
		0x64f84117, 0xdc442672, 0xcef1899c, 0x764deef9, // 60-63
		0x45115e33, 0xfdad3956, 0xef1896b8, 0x57a4f1dd, // 64-67
		0xca73c964, 0x72cfae01, 0x607a01ef, 0xd8c6668a, // 68-71
		0x80a576dc, 0x381911b9, 0x2aacbe57, 0x9210d932, // 72-75
		0x0fc7e18b, 0xb77b86ee, 0xa5ce2900, 0x1d724e65, // 76-79
		0x150809ac, 0xadb46ec9, 0xbf01c127, 0x07bda642, // 80-83
		0x9a6a9efb, 0x22d6f99e, 0x30635670, 0x88df3115, // 84-87
		0xd0bc2143, 0x68004626, 0x7ab5e9c8, 0xc2098ead, // 88-91
		0x5fdeb614, 0xe762d171, 0xf5d77e9f, 0x4d6b19fa, // 92-95
		0xe523f10d, 0x5d9f9668, 0x4f2a3986, 0xf7965ee3, // 96-99
		0x6a41665a, 0xd2fd013f, 0xc048aed1, 0x78f4c9b4, // 100-103
		0x2097d9e2, 0x982bbe87, 0x8a9e1169, 0x3222760c, // 104-107
		0xaff54eb5, 0x174929d0, 0x05fc863e, 0xbd40e15b, // 108-111
		0xb53aa692, 0x0d86c1f7, 0x1f336e19, 0xa78f097c, // 112-115
		0x3a5831c5, 0x82e456a0, 0x9051f94e, 0x28ed9e2b, // 116-119
		0x708e8e7d, 0xc832e918, 0xda8746f6, 0x623b2193, // 120-123
		0xffec192a, 0x47507e4f, 0x55e5d1a1, 0xed59b6c4, // 124-127
		0x335cb035, 0x8be0d750, 0x995578be, 0x21e91fdb, // 128-131
		0xbc3e2762, 0x04824007, 0x1637efe9, 0xae8b888c, // 132-135
		0xf6e898da, 0x4e54ffbf, 0x5ce15051, 0xe45d3734, // 136-139
		0x798a0f8d, 0xc13668e8, 0xd383c706, 0x6b3fa063, // 140-143
		0x6345e7aa, 0xdbf980cf, 0xc94c2f21, 0x71f04844, // 144-147
		0xec2770fd, 0x549b1798, 0x462eb876, 0xfe92df13, // 148-151
		0xa6f1cf45, 0x1e4da820, 0x0cf807ce, 0xb44460ab, // 152-155
		0x29935812, 0x912f3f77, 0x839a9099, 0x3b26f7fc, // 156-159
		0x936e1f0b, 0x2bd2786e, 0x3967d780, 0x81dbb0e5, // 160-163
		0x1c0c885c, 0xa4b0ef39, 0xb60540d7, 0x0eb927b2, // 164-167
		0x56da37e4, 0xee665081, 0xfcd3ff6f, 0x446f980a, // 168-171
		0xd9b8a0b3, 0x6104c7d6, 0x73b16838, 0xcb0d0f5d, // 172-175
		0xc3774894, 0x7bcb2ff1, 0x697e801f, 0xd1c2e77a, // 176-179
		0x4c15dfc3, 0xf4a9b8a6, 0xe61c1748, 0x5ea0702d, // 180-183
		0x06c3607b, 0xbe7f071e, 0xaccaa8f0, 0x1476cf95, // 184-187
		0x89a1f72c, 0x311d9049, 0x23a83fa7, 0x9b1458c2, // 188-191
		0xa848e808, 0x10f48f6d, 0x02412083, 0xbafd47e6, // 192-195
		0x272a7f5f, 0x9f96183a, 0x8d23b7d4, 0x359fd0b1, // 196-199
		0x6dfcc0e7, 0xd540a782, 0xc7f5086c, 0x7f496f09, // 200-203
		0xe29e57b0, 0x5a2230d5, 0x48979f3b, 0xf02bf85e, // 204-207
		0xf851bf97, 0x40edd8f2, 0x5258771c, 0xeae41079, // 208-211
		0x773328c0, 0xcf8f4fa5, 0xdd3ae04b, 0x6586872e, // 212-215
		0x3de59778, 0x8559f01d, 0x97ec5ff3, 0x2f503896, // 216-219
		0xb287002f, 0x0a3b674a, 0x188ec8a4, 0xa032afc1, // 220-223
		0x087a4736, 0xb0c62053, 0xa2738fbd, 0x1acfe8d8, // 224-227
		0x8718d061, 0x3fa4b704, 0x2d1118ea, 0x95ad7f8f, // 228-231
		0xcdce6fd9, 0x757208bc, 0x67c7a752, 0xdf7bc037, // 232-235
		0x42acf88e, 0xfa109feb, 0xe8a53005, 0x50195760, // 236-239
		0x586310a9, 0xe0df77cc, 0xf26ad822, 0x4ad6bf47, // 240-243
		0xd70187fe, 0x6fbde09b, 0x7d084f75, 0xc5b42810, // 244-247
		0x9dd73846, 0x256b5f23, 0x37def0cd, 0x8f6297a8, // 248-251
		0x12b5af11, 0xaa09c874, 0xb8bc679a, 0x000000ff, // 252-255
	}
};

#endif /* ifndef PRECOMPUTE_TABLES */

static uint32_t fh_dist_table[32768];

/* Make the table for a fast CRC.
 * Not thread-safe, must be called exactly once.
 */
static inline void __slz_make_crc_table(void)
{
#ifndef PRECOMPUTE_TABLES
	uint32_t c;
	int n, k;

	for (n = 0; n < 256; n++) {
		c = (uint32_t) n ^ 255;
		for (k = 0; k < 8; k++) {
			if (c & 1) {
				c = 0xedb88320 ^ (c >> 1);
			} else {
				c = c >> 1;
			}
		}
		crc32_fast[0][n] = c ^ 0xff000000;
	}

	/* Note: here we *do not* have to invert the bits corresponding to the
	 * byte position, because [0] already has the 8 highest bits inverted,
	 * and these bits are shifted by 8 at the end of the operation, which
	 * results in having the next 8 bits shifted in turn. That's why we
	 * have the xor in the index used just after a computation.
	 */
	for (n = 0; n < 256; n++) {
		crc32_fast[1][n] = 0xff000000 ^ crc32_fast[0][(0xff000000 ^ crc32_fast[0][n] ^ 0xff) & 0xff] ^ (crc32_fast[0][n] >> 8);
		crc32_fast[2][n] = 0xff000000 ^ crc32_fast[0][(0x00ff0000 ^ crc32_fast[1][n] ^ 0xff) & 0xff] ^ (crc32_fast[1][n] >> 8);
		crc32_fast[3][n] = 0xff000000 ^ crc32_fast[0][(0x0000ff00 ^ crc32_fast[2][n] ^ 0xff) & 0xff] ^ (crc32_fast[2][n] >> 8);
	}
#endif
}

/* Returns code for lengths 1 to 32768. The bit size for the next value can be
 * found this way :
 *
 *	bits = code >> 1;
 *	if (bits)
 *		bits--;
 *
 */
static inline uint32_t dist_to_code(uint32_t l)
{
	uint32_t code;

	code = 0;
	switch (l) {
	case 24577 ... 32768: code++;
	case 16385 ... 24576: code++;
	case 12289 ... 16384: code++;
	case 8193 ... 12288: code++;
	case 6145 ... 8192: code++;
	case 4097 ... 6144: code++;
	case 3073 ... 4096: code++;
	case 2049 ... 3072: code++;
	case 1537 ... 2048: code++;
	case 1025 ... 1536: code++;
	case 769 ... 1024: code++;
	case 513 ... 768: code++;
	case 385 ... 512: code++;
	case 257 ... 384: code++;
	case 193 ... 256: code++;
	case 129 ... 192: code++;
	case 97 ... 128: code++;
	case 65 ... 96: code++;
	case 49 ... 64: code++;
	case 33 ... 48: code++;
	case 25 ... 32: code++;
	case 17 ... 24: code++;
	case 13 ... 16: code++;
	case 9 ... 12: code++;
	case 7 ... 8: code++;
	case 5 ... 6: code++;
	case 4: code++;
	case 3: code++;
	case 2: code++;
	}

	return code;
}

/* not thread-safe, must be called exactly once */
static inline void __slz_prepare_dist_table()
{
	uint32_t dist;
	uint32_t code;
	uint32_t bits;

	for (dist = 0; dist < sizeof(fh_dist_table) / sizeof(*fh_dist_table); dist++) {
		code = dist_to_code(dist + 1);
		bits = code >> 1;
		if (bits)
			bits--;

		/* Distance codes are stored on 5 bits reversed. The RFC
		 * doesn't state that they are reversed, but it's the only
		 * way it works.
		 */
		code = ((code & 0x01) << 4) | ((code & 0x02) << 2) |
		       (code & 0x04) |
		       ((code & 0x08) >> 2) | ((code & 0x10) >> 4);

		code += (dist & ((1 << bits) - 1)) << 5;
		fh_dist_table[dist] = (code << 5) + bits + 5;
	}
}