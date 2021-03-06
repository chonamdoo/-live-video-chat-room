/*****************************************************************************/
/* BroadVoice(R)32 (BV32) Fixed-Point ANSI-C Source Code                     */
/* Revision Date: November 13, 2009                                          */
/* Version 1.1                                                               */
/*****************************************************************************/

/*****************************************************************************/
/* Copyright 2000-2009 Broadcom Corporation                                  */
/*                                                                           */
/* This software is provided under the GNU Lesser General Public License,    */
/* version 2.1, as published by the Free Software Foundation ("LGPL").       */
/* This program is distributed in the hope that it will be useful, but       */
/* WITHOUT ANY SUPPORT OR WARRANTY; without even the implied warranty of     */
/* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the LGPL for     */
/* more details.  A copy of the LGPL is available at                         */
/* http://www.broadcom.com/licenses/LGPLv2.1.php,                            */
/* or by writing to the Free Software Foundation, Inc.,                      */
/* 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.                 */
/*****************************************************************************/


/*****************************************************************************
  tables.c : Tables

  $Log$
******************************************************************************/

#include "typedef.h"

/* for log-gain restriction */

Word16 lgclimit[] = {
       0,      69,    1160,    1507,    2416,       0,
       0,       0,       0,       0,       0,       0,
     330,    2509,    1732,    2346,    2915,       0,
       0,       0,       0,       0,       0,     172,
    3726,    2982,    5971,    5971,       0,       0,
       0,       0,       0,    3232,    2821,    2478,
    3579,    4213,    5887,     972,       0,       0,
       0,       0,       0,    2585,    2607,    3028,
    3544,    3779,    2119,       0,       0,       0,
       0,    -187,    3152,    4234,    2767,    3013,
    5908,    2723,   -2545,       0,       0,       0,
    2822,    3234,    4949,    3884,    5444,    6164,
    4502,    1571,       0,       0,       0,    2026,
    5382,    4316,    3906,    5866,    6123,    5557,
    1449,     768,       0,       0,    3775,    4577,
    4390,    3511,    4955,    5911,    5623,    5342,
    1297,    2590,       0,    3775,    4158,    3412,
    3010,    3890,    5468,    5338,    4848,    3512,
    1569,       0,    2252,    3043,    2934,    2615,
    2916,    4258,    5147,    4214,    3642,    1557,
    -655,     301,    2616,    2773,    2331,    2216,
    2947,    3801,    3399,    3487,    2121,    1698,
      74,    2892,    2590,    2083,    1801,    2087,
    2335,    2556,    2826,    2469,    2658,       0,
    2840,    2640,    1730,    1487,    1407,    1446,
    1728,    2063,    2303,    1752,       0,     201,
    2008,    1369,    1365,    1229,    2381,    1689,
    1106,    1514,     209,       0,       0,     589,
    1314,    2040,    1849,    2390,     299,    -136,
      49,       0,       0,       0,     193,    2205,
    3620,     418,    1469,     611,     358,    -631,
       0,       0,       0,      39,     752,    1788,
    1623,    -431,    1952,    -260,       0,       0
};

Word16 lspecb1[] = {	/* Q16 */
  -252,  -557, -1043,  -236,    -9,   400,  1075,  -109,
  -335,  -861, -1113,   -68,  -797,  -280,  -178,   555,
  -241,  -109,    30,  -203,  1189,   -35,   168,  -546,
  -205,  -320,   185,  -114,     3,   -62, -1295,   201,
  -164,  -212,   101,   277,  -632, -1242,  1117,   144,
   -59,  -228,  -596,  -489,  -430, -1787,  -504,  -147,
   262,   712,   444,    59,   160,  -648,   360,  -412,
   -99,  -381,  -122,  -282, -1172, -1051, -2031,  -432,
  -359,  -628,    62,   789,   456,  1380,   472,    92,
  -258,  -556, -1274,  -966,   894,  -307,  -226,   371,
  -217,  -474,   115,  2050,   506,  -107,   371,  -302,
  -146,  -465,  -381,   742,  -316,   -33,  -680, -1237,
  -213,  -292,   427,   326, -1143,   656,   783,  -105,
   -36,  -144,  -414,  -747, -1256,  -466,    70,  -971,
  -358,    46,  1923,   926,   430,     2,   806,   241,
  -167,    65,  1311,  -108, -1077,  -533,  -440,  -664,
  -134,   174,   -89, -1522,   218,  1124,   885,   131,
  -190,  -485, -1121, -1740,  -885,    99,   -25,   510,
   -19,    42,    15,  -537,    40,  1662,  -539, -1374,
   -19,     1,  -528, -1514,   -54,   -70, -1364, -1155,
   -20,   112,  -427, -1103,    55,  -626,  1755,   628,
   192,   165,  -293, -1168, -1927, -1954,   244,  -276,
  1115,  1690,  -389,   390,   898,   802,   408,   -73,
    40,   -10,   450,    85,  -418, -1363, -3328, -1012,
  -261,   230,  1043,   -50,  1592,  1894,  1022,   460,
  -116,  -643, -2044,  -683,    -9,    29,  -432, -1013,
   168,   667,  1289,  1005,   921,  1079,  -169,  -877,
    58,   -11,  -107,  -131,  -459,  -476, -1684, -2561,
    23,   470,   280,   183,  1341,   452,  1867,   684,
    27,     3, -1190, -2053,  -248, -1455,    92,  -193,
  1030,  1705,   699,  2074,  2200,  1816,  1188,   465,
   578,  1409,   662,   236,    80,  -431, -1241, -1560,
  -441, -1057, -1626,  -121,   499,  1150,   472,   970,
  -338,  -895, -1011,  -688, -1142,  1337,  -577,  -100,
  -199,  -639, -1456,   982,  1588,   613,  -357,  -443,
  -145,  -612, -1315,    22,   192,  -831, -1927,  -356,
  -152,  -169,   173,   -88,   -99,  -371,   436,  2040,
   -81,  -383,  -678, -1299, -1888, -1345, -1090,   375,
   484,  1770,  1188,  1444,   212,  -337,   705,   433,
   229,   193,  -254,  -705, -1423, -2113, -1575, -1536,
  -406,  -890, -1099,   982,  1761,  1734,  1192,   662,
  -301,  -550, -1328, -1708,  1410,  1351,  -427,  -353,
  -266,  -353,   423,  2243,  2457,  1420,   326,  -388,
  -137,  -134,  -144,   150,  1702,   272, -1759, -1228,
  -321,  -626,  -375,   316,  -510,  1004,  2174,  1132,
  -224,  -596,  -328,  -564, -2794,  -359,   234,   234,
   -11,   781,  2285,  2264,  1439,   965,  1989,  1359,
   -72,   310,  1139,   563,  -166, -1995,  -509,  -724,
  -346,  -655,  -616,  -528,  -176,  3187,  1226,   290,
  -208,  -488,  -575, -1344, -2121,  1249,  1235,   344,
   297,  1168,   500,  -491,  2322,  1214,  -241,  -712,
    12,  -233, -1009, -1741,  -182, -1266, -2021,   236,
   -94,   192,   837,   614,    84,  -646,  2723,  1819,
   140,   368,   421,  -583, -2183, -3635,   588,   174,
   695,  3747,  2510,  2108,  1679,  1444,  1291,   605,
   145,   536,  1117,    -5,  -404, -3105, -2332,   368,
  -491,  -411,  1553,  1777,  2269,  2780,  1874,  1072,
 -1368, -3232,   406,   265,   708,   607,   511,   148,
  -114,   848,  2695,  1982,  2606,  2008,   578,  -235,
  -278,  -104,  1612,   707,   401,    69, -1620, -1580,
  -296,  -272,   166,   805,  1492,  1554,  3278,  1942,
  -242, -1164, -2162,  -799, -2117, -1334,  -688,  -459,
   858,  2312,  2770,  3152,  3271,  2971,  2187,  1294,
   155,  1262,  2669,  1821,  1080,  -769, -1547, -1112,
  -284,  -779, -1465,   699,   751,  -430,  1579,  1026,
  -294,  -771, -1556,  -960, -1068, -1214,   948,   738,
  -210,    20,   619,   665,  1987,     5,  -215,  1048,
   -93,  -313,   -21,  -286,  -369, -1395, -2172,  1721,
   -69,   -99,  -118,  -532, -1928, -1204,  2371,   738,
  -156,  -543,  -648,   247, -1775, -2287,  -283,    31,
   835,  1924,   643,  -604, -1068,  -385,   162,    42,
   127,   -99,  -307,  -827, -1619, -2218, -3244,  -222,
  -237,  -535,    97,  2229,   874,  1253,  1489,  1271,
   -87,  -524, -1656, -2111,   215,   531,   623,   882,
  -236,  -171,  2247,  3250,  1190,   578,   -28,  -446,
  -115,  -456,    20,  1787,  -182, -1088, -1766,  -711,
   -69,   474,  1542,   303,  -794,  1492,  1654,   772,
    29,  -206,  -546, -1477, -2353,   350, -1033, -1178,
   174,  1444,  3637,  1580,   568,   633,   628,  -125,
   107,   262,  1022,   -55, -2578,  -837, -1625, -1108,
  -295,  -392, -1127, -1399,  1639,  1514,  1948,  1078,
  -119,  -487, -1386, -2394, -2093,  -110,   296,   613,
  -230,  -277,   -76,    73,  2024,  2943,  -256,  -697,
   124,  -116,  -939, -1712,  -761,  -780, -3068, -1396,
  -154,  -346,  -885, -1216,  -476,  -129,  3275,  1953,
    16,  -355, -1176, -1953, -2510, -3003,   970,   811,
  3280,  2075,  1455,  1024,   610,   501,   546,   165,
   282,   291,   453,  -428, -1127, -2695, -5912,  -589,
    27,   609,   228,   170,  3523,  2542,  1925,   950,
  -322, -1807, -4411, -1616,  -570,  -371,  -387,   232,
  1256,  2294,  1920,  2182,  1786,  1247,  -455, -1078,
   243,   254,    40,  -275, -1028, -1483, -3412, -3067,
   939,  2060,  1057,   611,  1062,  1946,  2240,  1770,
   230,    54, -2039, -4396, -1327, -1219,  -628,  -114,
  3619,  2773,  2765,  2486,  2257,  2065,  1448,   837,
  2605,  2157,   938,    16,    57,  -749, -2352,  -840,
  -551, -1700, -3159,   237,  1168,  1995,  1842,  1564,
  -433, -1417, -2259,  -827, -1590,   906,  1016,  1107,
  -347,  -435, -1008,   -45,  3650,  1209,   199,   117,
  -169,  -587,  -637,  -437,   206,   -82, -3652,    20,
   -32,    27,   -19,  -615,  -545, -2410,  1286,  2225,
    99,  -163,  -658, -1325, -2188, -3304, -1382,   235,
  1174,  4363,  1935,  1113,   101,  -237,   109,  -353,
   317,   728,   769,  -569, -2203, -4085, -2472, -1317,
  -378, -1005, -1216,  2479,  3192,  2623,  1930,  1060,
  -345,  -980, -2371, -3709,    63,  1307,   893,   643,
  -133,   -43,  1952,  4593,  3419,  2350,  1238,   218,
   -11,    46,   592,  2285,  2153,   574, -2032, -2316,
  -302,  -583,  -351,  -397, -1005,  2559,  3431,  1705,
    87,  -151,  -449, -2081, -4548, -1474,  -791,  -246,
  -175,   872,  5077,  3412,  2269,  1909,  1757,   721,
   105,  1284,  3513,   728, -1326, -2460,  -919, -1125,
  -419,  -691,  -478,   199,  1512,  5148,  2640,  1240,
  -231, -1223, -1897, -2350, -4243,  -161,  1378,   991,
   -51,   687,  1034,  1453,  5161,  2910,   201,  -639,
    65, -1149, -1910, -2467, -2576, -2675, -4486, -1228,
  -168,   -22,    35,    46,   -69,    58,  5416,  2137,
   570,   466,  -508, -2213, -4138, -5855, -1177,    58,
  1860,  6231,  4358,  3552,  2930,  2573,  1699,   773,
  2829,  3377,   741, -1445, -2888, -4347, -5531, -3635,
  -204,   213,  1577,  2922,  5217,  5235,  2856,  1044,
 -1700, -5171, -1736, -1938, -1040, -1102,  -450,  -308,
   395,  2007,  4627,  4215,  3030,  1668,   -84,  -998,
   420,   987,  1734,  1055,    97, -1271, -3652, -4260,
  -157,   291,  1250,  2025,  2197,  3326,  4941,  2285,
   -52, -1980, -3837, -4640, -4256, -3287, -1498,  -333,
   386,  2230,  5764,  6110,  4669,  3786,  2189,   705,
  1781,  4897,  5689,  2343,    12, -2309, -3518, -3232
};

Word16 lspecb21[] = {	/* Q19 */
  1476,  1535,  2274,
  -113,  -198, -1322,
  3718, -2930,  -211,
 -1788, -2391,  2807,
 -1028,   755,  7026,
  -941, -2530, -4856,
 -3020,  3570,  1671,
 -2613, -5484,  -952,
  3796,  4678,   -56,
  -527,  3935, -5897,
  8508,  2639, -4868,
 -6910,  -777, -2543,
   730,  6787,  6736,
   842, -1450,-10757,
   252, 11289, -1255,
   637, -9657,  3704,
  6405,   601,  6598,
  2961,   311, -4759,
 11241, -6773,  -224,
 -6084, -6126,  6338,
 -2608, -2254, 13434,
 -1874, -6860, -8020,
 -8448,  7652,  3803,
 -6259,-11123, -2092,
  8966,  8488,  3275,
  3952,  9605,-12575,
 20765,  8117, -2917,
-18269,  1207,   280,
  -236,  8206, 19229,
  -790, -8659,-18883,
  4080, 22382,  3378,
 -6623,-20987,  3345
};

Word16 lspecb22[] = {	/* Q19 */
  1170, -4195, -4714,    34,   306,
  2612,  2018, -3741, -5041, -1611,
    -5,  1207,  4336,  1926,   980,
  1901,  7422,   585,  1394, -2402,
 -5854,   313, -5962,  1661, -4320,
  1921,   183, -3434,  1425,-10172,
 -1480, -4243,  2142, -3122, -5056,
  6735,   810,  3833,  1735, -5233,
 -4452, -3745,    95,  2794,  3841,
 -3355,  3429, -2584, -1805,  6519,
 -2299,  3592, -1301,  8722,   164,
  5391,  3289, -1653,  3583,  5195,
 -8497,  4694,  4997,  1928, -1902,
  -903,  3577,  5235, -6209,  1671,
 -1574, -4308,  5006,  6749, -4235,
  6384, -4056,  4443,  -164,  3385,
 -2472, -5519,-11513, -5551,  2163,
  4690, -1870, -2586,-13374, -5046,
  -642,  3829,  8422,  6318,  8228,
 -2920, 14026, -3055, -1713,   992,
 -9354,   412, -2252, -6882, -1282,
 -2668,  5064,  3714, -6024,-11151,
 -2477, -7025,  3107, -6619,  4279,
 11853,  9277,  4338, -3707, -1835,
 -4601, -4566, -7446,  7771,  9351,
  3830,   146, -1041, -7172, 10996,
  4871, -3705, -2959,  9986,    98,
  5504,  5248,-11417,  2591,    70,
-14162, -6125,  5520,  1685,   494,
  1501, -2801, 13863, -3450, -2176,
  1901,-13731,   932,  2009, -2087,
 14966, -5048, -3130,  -449,  -781
};

Word16 lspmean[] = {	/* Q15 mean value of LSP components */
  1807,  3870,  7372, 10866, 14994, 18746, 23571, 27126
};

Word16 lspp[] = {	/* Q14 LSP Predictor Coefficients */
 12126, 11370,  9882,  8739,  7037,  5299,  3567,  1905,
 13008, 12605, 10997,  9698,  7783,  5827,  3882,  1935,
 12344, 11990, 10365,  9156,  7422,  5562,  3781,  1968,
 11777, 11085,  9491,  8469,  6919,  5247,  3663,  1935,
 10538,  9869,  8376,  7493,  6167,  4593,  3376,  1787,
  9319,  9564,  7563,  7129,  5739,  4264,  3197,  1629,
  8672,  7922,  6374,  5868,  4722,  3705,  2800,  1542,
  8412,  7153,  5770,  5110,  4119,  3197,  2365,  1378
};

Word16 lgpecb[] = {	/* Q11 Log-Gain Prediction Error CodeBook */
-10074, -7681, -6330, -5324, -4560, -2995, -1803,  -711,
 -3961, -2573, -1436,  -341,   417,  1691,  3274,  5646,
 -3450, -2177, -1077,    32,   818,  2164,  3924,  6847,
  1243,  2687,  4705,  8426, 10670, 13730, 17906, 22368
};

Word16 lgp[] =	{	/* Q15 Log-Gain Predictor */
 19376, 17207, 18759, 19588, 15731, 16185, 15498, 13628,
 12471, 11125,  9110,  8045,  6279,  4817,  3731,  2178
};

Word16 lgmean = 24208; /* Q11 11.820152 */

Word16 cccb[] = {	/* Q13 */
 -4403,  7987, -5170, -5062,  9381, 10015,-10260,  5048,
  9619, 11464,  2711,  6743, 24141,  6538, -2250,  -224,
-13960,   809, -4309, -3240, -7283, -2764,  6427,  2445,
 -6201,  -507,  4579, -7432, 11249, -3386,  5657, -6505,
 -4697, -3799, -4972, -5108,  8673, -4637,-13740,  6165,
  3544,  3620, -5165,-11844, 20827,  1696,-13201,  2567,
-21072,-22597, -4091,  -165,  3541,-18872,-16519,  1873,
  5747,-11105, -7058, -1991,  7021,-15092,   -52,  9969,
-12078, 13403, -5602,  2973, -2963,  5832, -1117, 13270,
  3335, 13609,  4640, -4587, 13683,  9500, 14420,  4299,
-15242,  4852,  9940,  5894, -6928,   667, 18004, 13556,
  3485,  5254,  9914,-11834,  1707,  3945, 14815,  5619,
 -8377,  3488, -1384,-13457,  4113, -4026, -2430,  -560,
  2217,    49,  2112, -3820, 18566, -9245, -3272,  3592,
-15371, -7333,  -100,  7265, -3193,-14898,  9714,  7483,
  -334, -9355,  2984, -2324,  3672, -6186, 14480, -5664
};

Word16 pp9cb[] = {	/* Q14 */
 -4752,  9807,  4627,  1422, -1385,   671,  -345, -1468,  -327,
 -4223, 22577, 13421,  2909, -9247,  1729,  -272, -7778, -2748,
 -1130,  6587,  3816,   227,  -767,   132,   -19,  -662,  -222,
  -167, 16464, 12635,    84, -6348,    65,     0, -4136, -2436,
  -191,  9242,  1767,    54,  -498,    10,    -1, -1303,   -48,
  7976, 14729,  9410, -3585, -4230, -2290,  -971, -3311, -1351,
 -2241, -7555,  2499,  -517,   576,   171,   -77,  -871,   -95,
   683, 10511,  7165,  -219, -2298,  -149,    -7, -1686,  -783,
  2726, 10916,   689,  -908,  -230,   -57,  -113, -1818,    -7,
  3914, 20342,  7851, -2430, -4874,  -938,  -234, -6314,  -940,
  2566,  6073,  3006,  -476,  -557,  -235,  -100,  -563,  -138,
  5290, 13806, 10968, -2229, -4621, -1771,  -427, -2908, -1836,
  5577,  8013,  1598, -1364,  -391,  -272,  -475,  -980,   -39,
 11294, 15970,  4874, -5504, -2376, -1680, -1946, -3892,  -363,
  3802, -8178,  2401,   949,   599,  -279,  -221, -1021,   -88,
  9486, 11091,  8012, -3211, -2712, -2319, -1373, -1877,  -980,
 -4369, 11409, -2286,  1521,   796,  -305,  -291, -1986,   -80,
  -288, 27803,  4590,   245, -3894,    40,    -1,-11795,  -321,
 -2642,  6730,  -530,   543,   109,   -43,  -106,  -691,    -4,
 -1088, 15627,  3892,   519, -1856,   129,   -18, -3726,  -231,
    63,  8686, -4284,   -17,  1135,     8,     0, -1151,  -280,
  7186, 23671,  1021, -5191,  -738,  -224,  -788, -8549,   -16,
   253,  2335,   413,   -18,   -29,    -3,    -1,   -83,    -3,
  4827,  8568,  5854, -1262, -1531,  -862,  -356, -1120,  -523,
  4394, 15217, -3424, -2040,  1590,   459,  -295, -3533,  -179,
 13679, 22300, -3807, -9309,  2591,  1589, -2855, -7588,  -221,
  2045,  6359,  -981,  -397,   190,    61,   -64,  -617,   -15,
  5411, 14683,  4909, -2425, -2200,  -811,  -447, -3290,  -368,
  5375,  8863, -3377, -1454,   914,   554,  -441, -1199,  -174,
 12741, 16852,  -819, -6552,   421,   318, -2477, -4333,   -10,
   135, -7183, -2700,    30,  -592,    11,     0,  -787,  -111,
  8927, 11966,  1715, -3260,  -626,  -467, -1216, -2185,   -45
};

/* Pre-Emphasis or De-Emphasis Filter */
Word16 a_pre[] = { 4096, 3072 };
Word16 b_pre[] = { 4096, 2048 };

/* Combined High-Pass & Pre-Emphasis Filter */
Word16 hpfa[] = { 32767,  7936, 24384 };		/* Q15 */
Word16 hpfb[] = { 16320, -8160, -8160  };	/* *0.5 Q15 */

/* coarse pitch search */
Word16 adf_h[] = { 4096, -14583, 19889, -12284,  2895 };	/* DPF Q28 */
Word16 adf_l[] = {    0,	 9679, 18108,  25991, 18873 };
Word16 bdf[] 	= {  4233, -13485, 18964, -13485,  4233 };	/* Q17 */
Word16 x[4]    = { 4096, 8192, 12288, 16384 };
Word16 x2[4]   = { 512, 2048, 4608, 8192 };
Word16 MPTH[4] = {22938, 18022, 15728, 12124};

Word16 winl[] = {	/* Q15 */
     6,    22,    50,    88,   138,   198,   270,   352,
   445,   549,   664,   789,   924,  1071,  1227,  1393,
  1570,  1757,  1953,  2160,  2376,  2601,  2836,  3079,
  3332,  3593,  3864,  4142,  4429,  4724,  5027,  5337,
  5655,  5980,  6312,  6651,  6996,  7348,  7706,  8070,
  8439,  8813,  9193,  9578,  9967, 10361, 10758, 11160,
 11564, 11973, 12384, 12797, 13214, 13632, 14052, 14474,
 14897, 15321, 15746, 16171, 16597, 17022, 17447, 17871,
 18294, 18716, 19136, 19554, 19971, 20384, 20795, 21204,
 21608, 22010, 22407, 22801, 23190, 23575, 23955, 24329,
 24698, 25062, 25420, 25772, 26117, 26456, 26788, 27113,
 27431, 27741, 28044, 28339, 28626, 28904, 29175, 29436,
 29689, 29932, 30167, 30392, 30608, 30815, 31011, 31198,
 31375, 31541, 31697, 31844, 31979, 32104, 32219, 32323,
 32416, 32498, 32570, 32630, 32680, 32718, 32746, 32762,
 32767, 32743, 32667, 32541, 32365, 32138, 31863, 31538,
 31164, 30743, 30274, 29758, 29197, 28590, 27939, 27246,
 26510, 25733, 24917, 24062, 23170, 22243, 21281, 20286,
 19261, 18205, 17121, 16011, 14876, 13719, 12540, 11342,
 10126,  8895,  7650,  6393,  5126,  3851,  2571,  1286 
};

/* spectral smooth technique */
Word16 sstwinl_h[] = {
   32750, 32702, 32621, 32509, 32365, 32189, 31984, 31748 };	/* 45 dB */

Word16 sstwinl_l[] = {
   26146, 11409, 24833,  8680,  6585, 32423,  4714,  8677 };	/* 45 dB */

Word16 idxord[] = {
	0,  1,  2,  3,  4,  8, 16,  5,  9, 17,  6, 10, 18,  7, 11, 19,
	12, 20, 24, 13, 21, 25, 14, 22, 26, 15, 23, 27, 28, 29, 30, 31
};

Word16 lgpecb_nh[]={ -7681,  -6330,  -5324,  -4560,  -3961,  -2573,  -1436,   -341, 
			  -3450,  -2177,  -1077,     32,    818,   2164,   3924,   6847,
			  -2995,  -1803,   -711,    417,   1243,   2687,   4705,   8426,
			   1691,   3274,   5646,  10670,  13730,  17906,  22368};
