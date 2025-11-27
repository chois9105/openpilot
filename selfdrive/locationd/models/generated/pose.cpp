#include "pose.h"

namespace {
#define DIM 18
#define EDIM 18
#define MEDIM 18
typedef void (*Hfun)(double *, double *, double *);
const static double MAHA_THRESH_4 = 7.814727903251177;
const static double MAHA_THRESH_10 = 7.814727903251177;
const static double MAHA_THRESH_13 = 7.814727903251177;
const static double MAHA_THRESH_14 = 7.814727903251177;

/******************************************************************************
 *                      Code generated with SymPy 1.14.0                      *
 *                                                                            *
 *              See http://www.sympy.org/ for more information.               *
 *                                                                            *
 *                         This file is part of 'ekf'                         *
 ******************************************************************************/
void err_fun(double *nom_x, double *delta_x, double *out_6503352805626710270) {
   out_6503352805626710270[0] = delta_x[0] + nom_x[0];
   out_6503352805626710270[1] = delta_x[1] + nom_x[1];
   out_6503352805626710270[2] = delta_x[2] + nom_x[2];
   out_6503352805626710270[3] = delta_x[3] + nom_x[3];
   out_6503352805626710270[4] = delta_x[4] + nom_x[4];
   out_6503352805626710270[5] = delta_x[5] + nom_x[5];
   out_6503352805626710270[6] = delta_x[6] + nom_x[6];
   out_6503352805626710270[7] = delta_x[7] + nom_x[7];
   out_6503352805626710270[8] = delta_x[8] + nom_x[8];
   out_6503352805626710270[9] = delta_x[9] + nom_x[9];
   out_6503352805626710270[10] = delta_x[10] + nom_x[10];
   out_6503352805626710270[11] = delta_x[11] + nom_x[11];
   out_6503352805626710270[12] = delta_x[12] + nom_x[12];
   out_6503352805626710270[13] = delta_x[13] + nom_x[13];
   out_6503352805626710270[14] = delta_x[14] + nom_x[14];
   out_6503352805626710270[15] = delta_x[15] + nom_x[15];
   out_6503352805626710270[16] = delta_x[16] + nom_x[16];
   out_6503352805626710270[17] = delta_x[17] + nom_x[17];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_5975171236647925331) {
   out_5975171236647925331[0] = -nom_x[0] + true_x[0];
   out_5975171236647925331[1] = -nom_x[1] + true_x[1];
   out_5975171236647925331[2] = -nom_x[2] + true_x[2];
   out_5975171236647925331[3] = -nom_x[3] + true_x[3];
   out_5975171236647925331[4] = -nom_x[4] + true_x[4];
   out_5975171236647925331[5] = -nom_x[5] + true_x[5];
   out_5975171236647925331[6] = -nom_x[6] + true_x[6];
   out_5975171236647925331[7] = -nom_x[7] + true_x[7];
   out_5975171236647925331[8] = -nom_x[8] + true_x[8];
   out_5975171236647925331[9] = -nom_x[9] + true_x[9];
   out_5975171236647925331[10] = -nom_x[10] + true_x[10];
   out_5975171236647925331[11] = -nom_x[11] + true_x[11];
   out_5975171236647925331[12] = -nom_x[12] + true_x[12];
   out_5975171236647925331[13] = -nom_x[13] + true_x[13];
   out_5975171236647925331[14] = -nom_x[14] + true_x[14];
   out_5975171236647925331[15] = -nom_x[15] + true_x[15];
   out_5975171236647925331[16] = -nom_x[16] + true_x[16];
   out_5975171236647925331[17] = -nom_x[17] + true_x[17];
}
void H_mod_fun(double *state, double *out_6149272841185445129) {
   out_6149272841185445129[0] = 1.0;
   out_6149272841185445129[1] = 0.0;
   out_6149272841185445129[2] = 0.0;
   out_6149272841185445129[3] = 0.0;
   out_6149272841185445129[4] = 0.0;
   out_6149272841185445129[5] = 0.0;
   out_6149272841185445129[6] = 0.0;
   out_6149272841185445129[7] = 0.0;
   out_6149272841185445129[8] = 0.0;
   out_6149272841185445129[9] = 0.0;
   out_6149272841185445129[10] = 0.0;
   out_6149272841185445129[11] = 0.0;
   out_6149272841185445129[12] = 0.0;
   out_6149272841185445129[13] = 0.0;
   out_6149272841185445129[14] = 0.0;
   out_6149272841185445129[15] = 0.0;
   out_6149272841185445129[16] = 0.0;
   out_6149272841185445129[17] = 0.0;
   out_6149272841185445129[18] = 0.0;
   out_6149272841185445129[19] = 1.0;
   out_6149272841185445129[20] = 0.0;
   out_6149272841185445129[21] = 0.0;
   out_6149272841185445129[22] = 0.0;
   out_6149272841185445129[23] = 0.0;
   out_6149272841185445129[24] = 0.0;
   out_6149272841185445129[25] = 0.0;
   out_6149272841185445129[26] = 0.0;
   out_6149272841185445129[27] = 0.0;
   out_6149272841185445129[28] = 0.0;
   out_6149272841185445129[29] = 0.0;
   out_6149272841185445129[30] = 0.0;
   out_6149272841185445129[31] = 0.0;
   out_6149272841185445129[32] = 0.0;
   out_6149272841185445129[33] = 0.0;
   out_6149272841185445129[34] = 0.0;
   out_6149272841185445129[35] = 0.0;
   out_6149272841185445129[36] = 0.0;
   out_6149272841185445129[37] = 0.0;
   out_6149272841185445129[38] = 1.0;
   out_6149272841185445129[39] = 0.0;
   out_6149272841185445129[40] = 0.0;
   out_6149272841185445129[41] = 0.0;
   out_6149272841185445129[42] = 0.0;
   out_6149272841185445129[43] = 0.0;
   out_6149272841185445129[44] = 0.0;
   out_6149272841185445129[45] = 0.0;
   out_6149272841185445129[46] = 0.0;
   out_6149272841185445129[47] = 0.0;
   out_6149272841185445129[48] = 0.0;
   out_6149272841185445129[49] = 0.0;
   out_6149272841185445129[50] = 0.0;
   out_6149272841185445129[51] = 0.0;
   out_6149272841185445129[52] = 0.0;
   out_6149272841185445129[53] = 0.0;
   out_6149272841185445129[54] = 0.0;
   out_6149272841185445129[55] = 0.0;
   out_6149272841185445129[56] = 0.0;
   out_6149272841185445129[57] = 1.0;
   out_6149272841185445129[58] = 0.0;
   out_6149272841185445129[59] = 0.0;
   out_6149272841185445129[60] = 0.0;
   out_6149272841185445129[61] = 0.0;
   out_6149272841185445129[62] = 0.0;
   out_6149272841185445129[63] = 0.0;
   out_6149272841185445129[64] = 0.0;
   out_6149272841185445129[65] = 0.0;
   out_6149272841185445129[66] = 0.0;
   out_6149272841185445129[67] = 0.0;
   out_6149272841185445129[68] = 0.0;
   out_6149272841185445129[69] = 0.0;
   out_6149272841185445129[70] = 0.0;
   out_6149272841185445129[71] = 0.0;
   out_6149272841185445129[72] = 0.0;
   out_6149272841185445129[73] = 0.0;
   out_6149272841185445129[74] = 0.0;
   out_6149272841185445129[75] = 0.0;
   out_6149272841185445129[76] = 1.0;
   out_6149272841185445129[77] = 0.0;
   out_6149272841185445129[78] = 0.0;
   out_6149272841185445129[79] = 0.0;
   out_6149272841185445129[80] = 0.0;
   out_6149272841185445129[81] = 0.0;
   out_6149272841185445129[82] = 0.0;
   out_6149272841185445129[83] = 0.0;
   out_6149272841185445129[84] = 0.0;
   out_6149272841185445129[85] = 0.0;
   out_6149272841185445129[86] = 0.0;
   out_6149272841185445129[87] = 0.0;
   out_6149272841185445129[88] = 0.0;
   out_6149272841185445129[89] = 0.0;
   out_6149272841185445129[90] = 0.0;
   out_6149272841185445129[91] = 0.0;
   out_6149272841185445129[92] = 0.0;
   out_6149272841185445129[93] = 0.0;
   out_6149272841185445129[94] = 0.0;
   out_6149272841185445129[95] = 1.0;
   out_6149272841185445129[96] = 0.0;
   out_6149272841185445129[97] = 0.0;
   out_6149272841185445129[98] = 0.0;
   out_6149272841185445129[99] = 0.0;
   out_6149272841185445129[100] = 0.0;
   out_6149272841185445129[101] = 0.0;
   out_6149272841185445129[102] = 0.0;
   out_6149272841185445129[103] = 0.0;
   out_6149272841185445129[104] = 0.0;
   out_6149272841185445129[105] = 0.0;
   out_6149272841185445129[106] = 0.0;
   out_6149272841185445129[107] = 0.0;
   out_6149272841185445129[108] = 0.0;
   out_6149272841185445129[109] = 0.0;
   out_6149272841185445129[110] = 0.0;
   out_6149272841185445129[111] = 0.0;
   out_6149272841185445129[112] = 0.0;
   out_6149272841185445129[113] = 0.0;
   out_6149272841185445129[114] = 1.0;
   out_6149272841185445129[115] = 0.0;
   out_6149272841185445129[116] = 0.0;
   out_6149272841185445129[117] = 0.0;
   out_6149272841185445129[118] = 0.0;
   out_6149272841185445129[119] = 0.0;
   out_6149272841185445129[120] = 0.0;
   out_6149272841185445129[121] = 0.0;
   out_6149272841185445129[122] = 0.0;
   out_6149272841185445129[123] = 0.0;
   out_6149272841185445129[124] = 0.0;
   out_6149272841185445129[125] = 0.0;
   out_6149272841185445129[126] = 0.0;
   out_6149272841185445129[127] = 0.0;
   out_6149272841185445129[128] = 0.0;
   out_6149272841185445129[129] = 0.0;
   out_6149272841185445129[130] = 0.0;
   out_6149272841185445129[131] = 0.0;
   out_6149272841185445129[132] = 0.0;
   out_6149272841185445129[133] = 1.0;
   out_6149272841185445129[134] = 0.0;
   out_6149272841185445129[135] = 0.0;
   out_6149272841185445129[136] = 0.0;
   out_6149272841185445129[137] = 0.0;
   out_6149272841185445129[138] = 0.0;
   out_6149272841185445129[139] = 0.0;
   out_6149272841185445129[140] = 0.0;
   out_6149272841185445129[141] = 0.0;
   out_6149272841185445129[142] = 0.0;
   out_6149272841185445129[143] = 0.0;
   out_6149272841185445129[144] = 0.0;
   out_6149272841185445129[145] = 0.0;
   out_6149272841185445129[146] = 0.0;
   out_6149272841185445129[147] = 0.0;
   out_6149272841185445129[148] = 0.0;
   out_6149272841185445129[149] = 0.0;
   out_6149272841185445129[150] = 0.0;
   out_6149272841185445129[151] = 0.0;
   out_6149272841185445129[152] = 1.0;
   out_6149272841185445129[153] = 0.0;
   out_6149272841185445129[154] = 0.0;
   out_6149272841185445129[155] = 0.0;
   out_6149272841185445129[156] = 0.0;
   out_6149272841185445129[157] = 0.0;
   out_6149272841185445129[158] = 0.0;
   out_6149272841185445129[159] = 0.0;
   out_6149272841185445129[160] = 0.0;
   out_6149272841185445129[161] = 0.0;
   out_6149272841185445129[162] = 0.0;
   out_6149272841185445129[163] = 0.0;
   out_6149272841185445129[164] = 0.0;
   out_6149272841185445129[165] = 0.0;
   out_6149272841185445129[166] = 0.0;
   out_6149272841185445129[167] = 0.0;
   out_6149272841185445129[168] = 0.0;
   out_6149272841185445129[169] = 0.0;
   out_6149272841185445129[170] = 0.0;
   out_6149272841185445129[171] = 1.0;
   out_6149272841185445129[172] = 0.0;
   out_6149272841185445129[173] = 0.0;
   out_6149272841185445129[174] = 0.0;
   out_6149272841185445129[175] = 0.0;
   out_6149272841185445129[176] = 0.0;
   out_6149272841185445129[177] = 0.0;
   out_6149272841185445129[178] = 0.0;
   out_6149272841185445129[179] = 0.0;
   out_6149272841185445129[180] = 0.0;
   out_6149272841185445129[181] = 0.0;
   out_6149272841185445129[182] = 0.0;
   out_6149272841185445129[183] = 0.0;
   out_6149272841185445129[184] = 0.0;
   out_6149272841185445129[185] = 0.0;
   out_6149272841185445129[186] = 0.0;
   out_6149272841185445129[187] = 0.0;
   out_6149272841185445129[188] = 0.0;
   out_6149272841185445129[189] = 0.0;
   out_6149272841185445129[190] = 1.0;
   out_6149272841185445129[191] = 0.0;
   out_6149272841185445129[192] = 0.0;
   out_6149272841185445129[193] = 0.0;
   out_6149272841185445129[194] = 0.0;
   out_6149272841185445129[195] = 0.0;
   out_6149272841185445129[196] = 0.0;
   out_6149272841185445129[197] = 0.0;
   out_6149272841185445129[198] = 0.0;
   out_6149272841185445129[199] = 0.0;
   out_6149272841185445129[200] = 0.0;
   out_6149272841185445129[201] = 0.0;
   out_6149272841185445129[202] = 0.0;
   out_6149272841185445129[203] = 0.0;
   out_6149272841185445129[204] = 0.0;
   out_6149272841185445129[205] = 0.0;
   out_6149272841185445129[206] = 0.0;
   out_6149272841185445129[207] = 0.0;
   out_6149272841185445129[208] = 0.0;
   out_6149272841185445129[209] = 1.0;
   out_6149272841185445129[210] = 0.0;
   out_6149272841185445129[211] = 0.0;
   out_6149272841185445129[212] = 0.0;
   out_6149272841185445129[213] = 0.0;
   out_6149272841185445129[214] = 0.0;
   out_6149272841185445129[215] = 0.0;
   out_6149272841185445129[216] = 0.0;
   out_6149272841185445129[217] = 0.0;
   out_6149272841185445129[218] = 0.0;
   out_6149272841185445129[219] = 0.0;
   out_6149272841185445129[220] = 0.0;
   out_6149272841185445129[221] = 0.0;
   out_6149272841185445129[222] = 0.0;
   out_6149272841185445129[223] = 0.0;
   out_6149272841185445129[224] = 0.0;
   out_6149272841185445129[225] = 0.0;
   out_6149272841185445129[226] = 0.0;
   out_6149272841185445129[227] = 0.0;
   out_6149272841185445129[228] = 1.0;
   out_6149272841185445129[229] = 0.0;
   out_6149272841185445129[230] = 0.0;
   out_6149272841185445129[231] = 0.0;
   out_6149272841185445129[232] = 0.0;
   out_6149272841185445129[233] = 0.0;
   out_6149272841185445129[234] = 0.0;
   out_6149272841185445129[235] = 0.0;
   out_6149272841185445129[236] = 0.0;
   out_6149272841185445129[237] = 0.0;
   out_6149272841185445129[238] = 0.0;
   out_6149272841185445129[239] = 0.0;
   out_6149272841185445129[240] = 0.0;
   out_6149272841185445129[241] = 0.0;
   out_6149272841185445129[242] = 0.0;
   out_6149272841185445129[243] = 0.0;
   out_6149272841185445129[244] = 0.0;
   out_6149272841185445129[245] = 0.0;
   out_6149272841185445129[246] = 0.0;
   out_6149272841185445129[247] = 1.0;
   out_6149272841185445129[248] = 0.0;
   out_6149272841185445129[249] = 0.0;
   out_6149272841185445129[250] = 0.0;
   out_6149272841185445129[251] = 0.0;
   out_6149272841185445129[252] = 0.0;
   out_6149272841185445129[253] = 0.0;
   out_6149272841185445129[254] = 0.0;
   out_6149272841185445129[255] = 0.0;
   out_6149272841185445129[256] = 0.0;
   out_6149272841185445129[257] = 0.0;
   out_6149272841185445129[258] = 0.0;
   out_6149272841185445129[259] = 0.0;
   out_6149272841185445129[260] = 0.0;
   out_6149272841185445129[261] = 0.0;
   out_6149272841185445129[262] = 0.0;
   out_6149272841185445129[263] = 0.0;
   out_6149272841185445129[264] = 0.0;
   out_6149272841185445129[265] = 0.0;
   out_6149272841185445129[266] = 1.0;
   out_6149272841185445129[267] = 0.0;
   out_6149272841185445129[268] = 0.0;
   out_6149272841185445129[269] = 0.0;
   out_6149272841185445129[270] = 0.0;
   out_6149272841185445129[271] = 0.0;
   out_6149272841185445129[272] = 0.0;
   out_6149272841185445129[273] = 0.0;
   out_6149272841185445129[274] = 0.0;
   out_6149272841185445129[275] = 0.0;
   out_6149272841185445129[276] = 0.0;
   out_6149272841185445129[277] = 0.0;
   out_6149272841185445129[278] = 0.0;
   out_6149272841185445129[279] = 0.0;
   out_6149272841185445129[280] = 0.0;
   out_6149272841185445129[281] = 0.0;
   out_6149272841185445129[282] = 0.0;
   out_6149272841185445129[283] = 0.0;
   out_6149272841185445129[284] = 0.0;
   out_6149272841185445129[285] = 1.0;
   out_6149272841185445129[286] = 0.0;
   out_6149272841185445129[287] = 0.0;
   out_6149272841185445129[288] = 0.0;
   out_6149272841185445129[289] = 0.0;
   out_6149272841185445129[290] = 0.0;
   out_6149272841185445129[291] = 0.0;
   out_6149272841185445129[292] = 0.0;
   out_6149272841185445129[293] = 0.0;
   out_6149272841185445129[294] = 0.0;
   out_6149272841185445129[295] = 0.0;
   out_6149272841185445129[296] = 0.0;
   out_6149272841185445129[297] = 0.0;
   out_6149272841185445129[298] = 0.0;
   out_6149272841185445129[299] = 0.0;
   out_6149272841185445129[300] = 0.0;
   out_6149272841185445129[301] = 0.0;
   out_6149272841185445129[302] = 0.0;
   out_6149272841185445129[303] = 0.0;
   out_6149272841185445129[304] = 1.0;
   out_6149272841185445129[305] = 0.0;
   out_6149272841185445129[306] = 0.0;
   out_6149272841185445129[307] = 0.0;
   out_6149272841185445129[308] = 0.0;
   out_6149272841185445129[309] = 0.0;
   out_6149272841185445129[310] = 0.0;
   out_6149272841185445129[311] = 0.0;
   out_6149272841185445129[312] = 0.0;
   out_6149272841185445129[313] = 0.0;
   out_6149272841185445129[314] = 0.0;
   out_6149272841185445129[315] = 0.0;
   out_6149272841185445129[316] = 0.0;
   out_6149272841185445129[317] = 0.0;
   out_6149272841185445129[318] = 0.0;
   out_6149272841185445129[319] = 0.0;
   out_6149272841185445129[320] = 0.0;
   out_6149272841185445129[321] = 0.0;
   out_6149272841185445129[322] = 0.0;
   out_6149272841185445129[323] = 1.0;
}
void f_fun(double *state, double dt, double *out_1838878275411859331) {
   out_1838878275411859331[0] = atan2((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), -(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]));
   out_1838878275411859331[1] = asin(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]));
   out_1838878275411859331[2] = atan2(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), -(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]));
   out_1838878275411859331[3] = dt*state[12] + state[3];
   out_1838878275411859331[4] = dt*state[13] + state[4];
   out_1838878275411859331[5] = dt*state[14] + state[5];
   out_1838878275411859331[6] = state[6];
   out_1838878275411859331[7] = state[7];
   out_1838878275411859331[8] = state[8];
   out_1838878275411859331[9] = state[9];
   out_1838878275411859331[10] = state[10];
   out_1838878275411859331[11] = state[11];
   out_1838878275411859331[12] = state[12];
   out_1838878275411859331[13] = state[13];
   out_1838878275411859331[14] = state[14];
   out_1838878275411859331[15] = state[15];
   out_1838878275411859331[16] = state[16];
   out_1838878275411859331[17] = state[17];
}
void F_fun(double *state, double dt, double *out_8197411821134071860) {
   out_8197411821134071860[0] = ((-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*cos(state[0])*cos(state[1]) - sin(state[0])*cos(dt*state[6])*cos(dt*state[7])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + ((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*cos(state[0])*cos(state[1]) - sin(dt*state[6])*sin(state[0])*cos(dt*state[7])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_8197411821134071860[1] = ((-sin(dt*state[6])*sin(dt*state[8]) - sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*cos(state[1]) - (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*sin(state[1]) - sin(state[1])*cos(dt*state[6])*cos(dt*state[7])*cos(state[0]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*sin(state[1]) + (-sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) + sin(dt*state[8])*cos(dt*state[6]))*cos(state[1]) - sin(dt*state[6])*sin(state[1])*cos(dt*state[7])*cos(state[0]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_8197411821134071860[2] = 0;
   out_8197411821134071860[3] = 0;
   out_8197411821134071860[4] = 0;
   out_8197411821134071860[5] = 0;
   out_8197411821134071860[6] = (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(dt*cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*sin(dt*state[8]) - dt*sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-dt*sin(dt*state[6])*cos(dt*state[8]) + dt*sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) - dt*cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (dt*sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_8197411821134071860[7] = (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[6])*sin(dt*state[7])*cos(state[0])*cos(state[1]) + dt*sin(dt*state[6])*sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) - dt*sin(dt*state[6])*sin(state[1])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[7])*cos(dt*state[6])*cos(state[0])*cos(state[1]) + dt*sin(dt*state[8])*sin(state[0])*cos(dt*state[6])*cos(dt*state[7])*cos(state[1]) - dt*sin(state[1])*cos(dt*state[6])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_8197411821134071860[8] = ((dt*sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + dt*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (dt*sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + ((dt*sin(dt*state[6])*sin(dt*state[8]) + dt*sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*cos(dt*state[8]) + dt*sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_8197411821134071860[9] = 0;
   out_8197411821134071860[10] = 0;
   out_8197411821134071860[11] = 0;
   out_8197411821134071860[12] = 0;
   out_8197411821134071860[13] = 0;
   out_8197411821134071860[14] = 0;
   out_8197411821134071860[15] = 0;
   out_8197411821134071860[16] = 0;
   out_8197411821134071860[17] = 0;
   out_8197411821134071860[18] = (-sin(dt*state[7])*sin(state[0])*cos(state[1]) - sin(dt*state[8])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_8197411821134071860[19] = (-sin(dt*state[7])*sin(state[1])*cos(state[0]) + sin(dt*state[8])*sin(state[0])*sin(state[1])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_8197411821134071860[20] = 0;
   out_8197411821134071860[21] = 0;
   out_8197411821134071860[22] = 0;
   out_8197411821134071860[23] = 0;
   out_8197411821134071860[24] = 0;
   out_8197411821134071860[25] = (dt*sin(dt*state[7])*sin(dt*state[8])*sin(state[0])*cos(state[1]) - dt*sin(dt*state[7])*sin(state[1])*cos(dt*state[8]) + dt*cos(dt*state[7])*cos(state[0])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_8197411821134071860[26] = (-dt*sin(dt*state[8])*sin(state[1])*cos(dt*state[7]) - dt*sin(state[0])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_8197411821134071860[27] = 0;
   out_8197411821134071860[28] = 0;
   out_8197411821134071860[29] = 0;
   out_8197411821134071860[30] = 0;
   out_8197411821134071860[31] = 0;
   out_8197411821134071860[32] = 0;
   out_8197411821134071860[33] = 0;
   out_8197411821134071860[34] = 0;
   out_8197411821134071860[35] = 0;
   out_8197411821134071860[36] = ((sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[7]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[7]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_8197411821134071860[37] = (-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(-sin(dt*state[7])*sin(state[2])*cos(state[0])*cos(state[1]) + sin(dt*state[8])*sin(state[0])*sin(state[2])*cos(dt*state[7])*cos(state[1]) - sin(state[1])*sin(state[2])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*(-sin(dt*state[7])*cos(state[0])*cos(state[1])*cos(state[2]) + sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1])*cos(state[2]) - sin(state[1])*cos(dt*state[7])*cos(dt*state[8])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_8197411821134071860[38] = ((-sin(state[0])*sin(state[2]) - sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (-sin(state[0])*sin(state[1])*sin(state[2]) - cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_8197411821134071860[39] = 0;
   out_8197411821134071860[40] = 0;
   out_8197411821134071860[41] = 0;
   out_8197411821134071860[42] = 0;
   out_8197411821134071860[43] = (-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(dt*(sin(state[0])*cos(state[2]) - sin(state[1])*sin(state[2])*cos(state[0]))*cos(dt*state[7]) - dt*(sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[7])*sin(dt*state[8]) - dt*sin(dt*state[7])*sin(state[2])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*(dt*(-sin(state[0])*sin(state[2]) - sin(state[1])*cos(state[0])*cos(state[2]))*cos(dt*state[7]) - dt*(sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[7])*sin(dt*state[8]) - dt*sin(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_8197411821134071860[44] = (dt*(sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*cos(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*sin(state[2])*cos(dt*state[7])*cos(state[1]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + (dt*(sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*cos(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[7])*cos(state[1])*cos(state[2]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_8197411821134071860[45] = 0;
   out_8197411821134071860[46] = 0;
   out_8197411821134071860[47] = 0;
   out_8197411821134071860[48] = 0;
   out_8197411821134071860[49] = 0;
   out_8197411821134071860[50] = 0;
   out_8197411821134071860[51] = 0;
   out_8197411821134071860[52] = 0;
   out_8197411821134071860[53] = 0;
   out_8197411821134071860[54] = 0;
   out_8197411821134071860[55] = 0;
   out_8197411821134071860[56] = 0;
   out_8197411821134071860[57] = 1;
   out_8197411821134071860[58] = 0;
   out_8197411821134071860[59] = 0;
   out_8197411821134071860[60] = 0;
   out_8197411821134071860[61] = 0;
   out_8197411821134071860[62] = 0;
   out_8197411821134071860[63] = 0;
   out_8197411821134071860[64] = 0;
   out_8197411821134071860[65] = 0;
   out_8197411821134071860[66] = dt;
   out_8197411821134071860[67] = 0;
   out_8197411821134071860[68] = 0;
   out_8197411821134071860[69] = 0;
   out_8197411821134071860[70] = 0;
   out_8197411821134071860[71] = 0;
   out_8197411821134071860[72] = 0;
   out_8197411821134071860[73] = 0;
   out_8197411821134071860[74] = 0;
   out_8197411821134071860[75] = 0;
   out_8197411821134071860[76] = 1;
   out_8197411821134071860[77] = 0;
   out_8197411821134071860[78] = 0;
   out_8197411821134071860[79] = 0;
   out_8197411821134071860[80] = 0;
   out_8197411821134071860[81] = 0;
   out_8197411821134071860[82] = 0;
   out_8197411821134071860[83] = 0;
   out_8197411821134071860[84] = 0;
   out_8197411821134071860[85] = dt;
   out_8197411821134071860[86] = 0;
   out_8197411821134071860[87] = 0;
   out_8197411821134071860[88] = 0;
   out_8197411821134071860[89] = 0;
   out_8197411821134071860[90] = 0;
   out_8197411821134071860[91] = 0;
   out_8197411821134071860[92] = 0;
   out_8197411821134071860[93] = 0;
   out_8197411821134071860[94] = 0;
   out_8197411821134071860[95] = 1;
   out_8197411821134071860[96] = 0;
   out_8197411821134071860[97] = 0;
   out_8197411821134071860[98] = 0;
   out_8197411821134071860[99] = 0;
   out_8197411821134071860[100] = 0;
   out_8197411821134071860[101] = 0;
   out_8197411821134071860[102] = 0;
   out_8197411821134071860[103] = 0;
   out_8197411821134071860[104] = dt;
   out_8197411821134071860[105] = 0;
   out_8197411821134071860[106] = 0;
   out_8197411821134071860[107] = 0;
   out_8197411821134071860[108] = 0;
   out_8197411821134071860[109] = 0;
   out_8197411821134071860[110] = 0;
   out_8197411821134071860[111] = 0;
   out_8197411821134071860[112] = 0;
   out_8197411821134071860[113] = 0;
   out_8197411821134071860[114] = 1;
   out_8197411821134071860[115] = 0;
   out_8197411821134071860[116] = 0;
   out_8197411821134071860[117] = 0;
   out_8197411821134071860[118] = 0;
   out_8197411821134071860[119] = 0;
   out_8197411821134071860[120] = 0;
   out_8197411821134071860[121] = 0;
   out_8197411821134071860[122] = 0;
   out_8197411821134071860[123] = 0;
   out_8197411821134071860[124] = 0;
   out_8197411821134071860[125] = 0;
   out_8197411821134071860[126] = 0;
   out_8197411821134071860[127] = 0;
   out_8197411821134071860[128] = 0;
   out_8197411821134071860[129] = 0;
   out_8197411821134071860[130] = 0;
   out_8197411821134071860[131] = 0;
   out_8197411821134071860[132] = 0;
   out_8197411821134071860[133] = 1;
   out_8197411821134071860[134] = 0;
   out_8197411821134071860[135] = 0;
   out_8197411821134071860[136] = 0;
   out_8197411821134071860[137] = 0;
   out_8197411821134071860[138] = 0;
   out_8197411821134071860[139] = 0;
   out_8197411821134071860[140] = 0;
   out_8197411821134071860[141] = 0;
   out_8197411821134071860[142] = 0;
   out_8197411821134071860[143] = 0;
   out_8197411821134071860[144] = 0;
   out_8197411821134071860[145] = 0;
   out_8197411821134071860[146] = 0;
   out_8197411821134071860[147] = 0;
   out_8197411821134071860[148] = 0;
   out_8197411821134071860[149] = 0;
   out_8197411821134071860[150] = 0;
   out_8197411821134071860[151] = 0;
   out_8197411821134071860[152] = 1;
   out_8197411821134071860[153] = 0;
   out_8197411821134071860[154] = 0;
   out_8197411821134071860[155] = 0;
   out_8197411821134071860[156] = 0;
   out_8197411821134071860[157] = 0;
   out_8197411821134071860[158] = 0;
   out_8197411821134071860[159] = 0;
   out_8197411821134071860[160] = 0;
   out_8197411821134071860[161] = 0;
   out_8197411821134071860[162] = 0;
   out_8197411821134071860[163] = 0;
   out_8197411821134071860[164] = 0;
   out_8197411821134071860[165] = 0;
   out_8197411821134071860[166] = 0;
   out_8197411821134071860[167] = 0;
   out_8197411821134071860[168] = 0;
   out_8197411821134071860[169] = 0;
   out_8197411821134071860[170] = 0;
   out_8197411821134071860[171] = 1;
   out_8197411821134071860[172] = 0;
   out_8197411821134071860[173] = 0;
   out_8197411821134071860[174] = 0;
   out_8197411821134071860[175] = 0;
   out_8197411821134071860[176] = 0;
   out_8197411821134071860[177] = 0;
   out_8197411821134071860[178] = 0;
   out_8197411821134071860[179] = 0;
   out_8197411821134071860[180] = 0;
   out_8197411821134071860[181] = 0;
   out_8197411821134071860[182] = 0;
   out_8197411821134071860[183] = 0;
   out_8197411821134071860[184] = 0;
   out_8197411821134071860[185] = 0;
   out_8197411821134071860[186] = 0;
   out_8197411821134071860[187] = 0;
   out_8197411821134071860[188] = 0;
   out_8197411821134071860[189] = 0;
   out_8197411821134071860[190] = 1;
   out_8197411821134071860[191] = 0;
   out_8197411821134071860[192] = 0;
   out_8197411821134071860[193] = 0;
   out_8197411821134071860[194] = 0;
   out_8197411821134071860[195] = 0;
   out_8197411821134071860[196] = 0;
   out_8197411821134071860[197] = 0;
   out_8197411821134071860[198] = 0;
   out_8197411821134071860[199] = 0;
   out_8197411821134071860[200] = 0;
   out_8197411821134071860[201] = 0;
   out_8197411821134071860[202] = 0;
   out_8197411821134071860[203] = 0;
   out_8197411821134071860[204] = 0;
   out_8197411821134071860[205] = 0;
   out_8197411821134071860[206] = 0;
   out_8197411821134071860[207] = 0;
   out_8197411821134071860[208] = 0;
   out_8197411821134071860[209] = 1;
   out_8197411821134071860[210] = 0;
   out_8197411821134071860[211] = 0;
   out_8197411821134071860[212] = 0;
   out_8197411821134071860[213] = 0;
   out_8197411821134071860[214] = 0;
   out_8197411821134071860[215] = 0;
   out_8197411821134071860[216] = 0;
   out_8197411821134071860[217] = 0;
   out_8197411821134071860[218] = 0;
   out_8197411821134071860[219] = 0;
   out_8197411821134071860[220] = 0;
   out_8197411821134071860[221] = 0;
   out_8197411821134071860[222] = 0;
   out_8197411821134071860[223] = 0;
   out_8197411821134071860[224] = 0;
   out_8197411821134071860[225] = 0;
   out_8197411821134071860[226] = 0;
   out_8197411821134071860[227] = 0;
   out_8197411821134071860[228] = 1;
   out_8197411821134071860[229] = 0;
   out_8197411821134071860[230] = 0;
   out_8197411821134071860[231] = 0;
   out_8197411821134071860[232] = 0;
   out_8197411821134071860[233] = 0;
   out_8197411821134071860[234] = 0;
   out_8197411821134071860[235] = 0;
   out_8197411821134071860[236] = 0;
   out_8197411821134071860[237] = 0;
   out_8197411821134071860[238] = 0;
   out_8197411821134071860[239] = 0;
   out_8197411821134071860[240] = 0;
   out_8197411821134071860[241] = 0;
   out_8197411821134071860[242] = 0;
   out_8197411821134071860[243] = 0;
   out_8197411821134071860[244] = 0;
   out_8197411821134071860[245] = 0;
   out_8197411821134071860[246] = 0;
   out_8197411821134071860[247] = 1;
   out_8197411821134071860[248] = 0;
   out_8197411821134071860[249] = 0;
   out_8197411821134071860[250] = 0;
   out_8197411821134071860[251] = 0;
   out_8197411821134071860[252] = 0;
   out_8197411821134071860[253] = 0;
   out_8197411821134071860[254] = 0;
   out_8197411821134071860[255] = 0;
   out_8197411821134071860[256] = 0;
   out_8197411821134071860[257] = 0;
   out_8197411821134071860[258] = 0;
   out_8197411821134071860[259] = 0;
   out_8197411821134071860[260] = 0;
   out_8197411821134071860[261] = 0;
   out_8197411821134071860[262] = 0;
   out_8197411821134071860[263] = 0;
   out_8197411821134071860[264] = 0;
   out_8197411821134071860[265] = 0;
   out_8197411821134071860[266] = 1;
   out_8197411821134071860[267] = 0;
   out_8197411821134071860[268] = 0;
   out_8197411821134071860[269] = 0;
   out_8197411821134071860[270] = 0;
   out_8197411821134071860[271] = 0;
   out_8197411821134071860[272] = 0;
   out_8197411821134071860[273] = 0;
   out_8197411821134071860[274] = 0;
   out_8197411821134071860[275] = 0;
   out_8197411821134071860[276] = 0;
   out_8197411821134071860[277] = 0;
   out_8197411821134071860[278] = 0;
   out_8197411821134071860[279] = 0;
   out_8197411821134071860[280] = 0;
   out_8197411821134071860[281] = 0;
   out_8197411821134071860[282] = 0;
   out_8197411821134071860[283] = 0;
   out_8197411821134071860[284] = 0;
   out_8197411821134071860[285] = 1;
   out_8197411821134071860[286] = 0;
   out_8197411821134071860[287] = 0;
   out_8197411821134071860[288] = 0;
   out_8197411821134071860[289] = 0;
   out_8197411821134071860[290] = 0;
   out_8197411821134071860[291] = 0;
   out_8197411821134071860[292] = 0;
   out_8197411821134071860[293] = 0;
   out_8197411821134071860[294] = 0;
   out_8197411821134071860[295] = 0;
   out_8197411821134071860[296] = 0;
   out_8197411821134071860[297] = 0;
   out_8197411821134071860[298] = 0;
   out_8197411821134071860[299] = 0;
   out_8197411821134071860[300] = 0;
   out_8197411821134071860[301] = 0;
   out_8197411821134071860[302] = 0;
   out_8197411821134071860[303] = 0;
   out_8197411821134071860[304] = 1;
   out_8197411821134071860[305] = 0;
   out_8197411821134071860[306] = 0;
   out_8197411821134071860[307] = 0;
   out_8197411821134071860[308] = 0;
   out_8197411821134071860[309] = 0;
   out_8197411821134071860[310] = 0;
   out_8197411821134071860[311] = 0;
   out_8197411821134071860[312] = 0;
   out_8197411821134071860[313] = 0;
   out_8197411821134071860[314] = 0;
   out_8197411821134071860[315] = 0;
   out_8197411821134071860[316] = 0;
   out_8197411821134071860[317] = 0;
   out_8197411821134071860[318] = 0;
   out_8197411821134071860[319] = 0;
   out_8197411821134071860[320] = 0;
   out_8197411821134071860[321] = 0;
   out_8197411821134071860[322] = 0;
   out_8197411821134071860[323] = 1;
}
void h_4(double *state, double *unused, double *out_1806626447084815176) {
   out_1806626447084815176[0] = state[6] + state[9];
   out_1806626447084815176[1] = state[7] + state[10];
   out_1806626447084815176[2] = state[8] + state[11];
}
void H_4(double *state, double *unused, double *out_7682844195594790123) {
   out_7682844195594790123[0] = 0;
   out_7682844195594790123[1] = 0;
   out_7682844195594790123[2] = 0;
   out_7682844195594790123[3] = 0;
   out_7682844195594790123[4] = 0;
   out_7682844195594790123[5] = 0;
   out_7682844195594790123[6] = 1;
   out_7682844195594790123[7] = 0;
   out_7682844195594790123[8] = 0;
   out_7682844195594790123[9] = 1;
   out_7682844195594790123[10] = 0;
   out_7682844195594790123[11] = 0;
   out_7682844195594790123[12] = 0;
   out_7682844195594790123[13] = 0;
   out_7682844195594790123[14] = 0;
   out_7682844195594790123[15] = 0;
   out_7682844195594790123[16] = 0;
   out_7682844195594790123[17] = 0;
   out_7682844195594790123[18] = 0;
   out_7682844195594790123[19] = 0;
   out_7682844195594790123[20] = 0;
   out_7682844195594790123[21] = 0;
   out_7682844195594790123[22] = 0;
   out_7682844195594790123[23] = 0;
   out_7682844195594790123[24] = 0;
   out_7682844195594790123[25] = 1;
   out_7682844195594790123[26] = 0;
   out_7682844195594790123[27] = 0;
   out_7682844195594790123[28] = 1;
   out_7682844195594790123[29] = 0;
   out_7682844195594790123[30] = 0;
   out_7682844195594790123[31] = 0;
   out_7682844195594790123[32] = 0;
   out_7682844195594790123[33] = 0;
   out_7682844195594790123[34] = 0;
   out_7682844195594790123[35] = 0;
   out_7682844195594790123[36] = 0;
   out_7682844195594790123[37] = 0;
   out_7682844195594790123[38] = 0;
   out_7682844195594790123[39] = 0;
   out_7682844195594790123[40] = 0;
   out_7682844195594790123[41] = 0;
   out_7682844195594790123[42] = 0;
   out_7682844195594790123[43] = 0;
   out_7682844195594790123[44] = 1;
   out_7682844195594790123[45] = 0;
   out_7682844195594790123[46] = 0;
   out_7682844195594790123[47] = 1;
   out_7682844195594790123[48] = 0;
   out_7682844195594790123[49] = 0;
   out_7682844195594790123[50] = 0;
   out_7682844195594790123[51] = 0;
   out_7682844195594790123[52] = 0;
   out_7682844195594790123[53] = 0;
}
void h_10(double *state, double *unused, double *out_6123324008369649598) {
   out_6123324008369649598[0] = 9.8100000000000005*sin(state[1]) - state[4]*state[8] + state[5]*state[7] + state[12] + state[15];
   out_6123324008369649598[1] = -9.8100000000000005*sin(state[0])*cos(state[1]) + state[3]*state[8] - state[5]*state[6] + state[13] + state[16];
   out_6123324008369649598[2] = -9.8100000000000005*cos(state[0])*cos(state[1]) - state[3]*state[7] + state[4]*state[6] + state[14] + state[17];
}
void H_10(double *state, double *unused, double *out_3416431020486776412) {
   out_3416431020486776412[0] = 0;
   out_3416431020486776412[1] = 9.8100000000000005*cos(state[1]);
   out_3416431020486776412[2] = 0;
   out_3416431020486776412[3] = 0;
   out_3416431020486776412[4] = -state[8];
   out_3416431020486776412[5] = state[7];
   out_3416431020486776412[6] = 0;
   out_3416431020486776412[7] = state[5];
   out_3416431020486776412[8] = -state[4];
   out_3416431020486776412[9] = 0;
   out_3416431020486776412[10] = 0;
   out_3416431020486776412[11] = 0;
   out_3416431020486776412[12] = 1;
   out_3416431020486776412[13] = 0;
   out_3416431020486776412[14] = 0;
   out_3416431020486776412[15] = 1;
   out_3416431020486776412[16] = 0;
   out_3416431020486776412[17] = 0;
   out_3416431020486776412[18] = -9.8100000000000005*cos(state[0])*cos(state[1]);
   out_3416431020486776412[19] = 9.8100000000000005*sin(state[0])*sin(state[1]);
   out_3416431020486776412[20] = 0;
   out_3416431020486776412[21] = state[8];
   out_3416431020486776412[22] = 0;
   out_3416431020486776412[23] = -state[6];
   out_3416431020486776412[24] = -state[5];
   out_3416431020486776412[25] = 0;
   out_3416431020486776412[26] = state[3];
   out_3416431020486776412[27] = 0;
   out_3416431020486776412[28] = 0;
   out_3416431020486776412[29] = 0;
   out_3416431020486776412[30] = 0;
   out_3416431020486776412[31] = 1;
   out_3416431020486776412[32] = 0;
   out_3416431020486776412[33] = 0;
   out_3416431020486776412[34] = 1;
   out_3416431020486776412[35] = 0;
   out_3416431020486776412[36] = 9.8100000000000005*sin(state[0])*cos(state[1]);
   out_3416431020486776412[37] = 9.8100000000000005*sin(state[1])*cos(state[0]);
   out_3416431020486776412[38] = 0;
   out_3416431020486776412[39] = -state[7];
   out_3416431020486776412[40] = state[6];
   out_3416431020486776412[41] = 0;
   out_3416431020486776412[42] = state[4];
   out_3416431020486776412[43] = -state[3];
   out_3416431020486776412[44] = 0;
   out_3416431020486776412[45] = 0;
   out_3416431020486776412[46] = 0;
   out_3416431020486776412[47] = 0;
   out_3416431020486776412[48] = 0;
   out_3416431020486776412[49] = 0;
   out_3416431020486776412[50] = 1;
   out_3416431020486776412[51] = 0;
   out_3416431020486776412[52] = 0;
   out_3416431020486776412[53] = 1;
}
void h_13(double *state, double *unused, double *out_8162596648124754745) {
   out_8162596648124754745[0] = state[3];
   out_8162596648124754745[1] = state[4];
   out_8162596648124754745[2] = state[5];
}
void H_13(double *state, double *unused, double *out_4470570370262457322) {
   out_4470570370262457322[0] = 0;
   out_4470570370262457322[1] = 0;
   out_4470570370262457322[2] = 0;
   out_4470570370262457322[3] = 1;
   out_4470570370262457322[4] = 0;
   out_4470570370262457322[5] = 0;
   out_4470570370262457322[6] = 0;
   out_4470570370262457322[7] = 0;
   out_4470570370262457322[8] = 0;
   out_4470570370262457322[9] = 0;
   out_4470570370262457322[10] = 0;
   out_4470570370262457322[11] = 0;
   out_4470570370262457322[12] = 0;
   out_4470570370262457322[13] = 0;
   out_4470570370262457322[14] = 0;
   out_4470570370262457322[15] = 0;
   out_4470570370262457322[16] = 0;
   out_4470570370262457322[17] = 0;
   out_4470570370262457322[18] = 0;
   out_4470570370262457322[19] = 0;
   out_4470570370262457322[20] = 0;
   out_4470570370262457322[21] = 0;
   out_4470570370262457322[22] = 1;
   out_4470570370262457322[23] = 0;
   out_4470570370262457322[24] = 0;
   out_4470570370262457322[25] = 0;
   out_4470570370262457322[26] = 0;
   out_4470570370262457322[27] = 0;
   out_4470570370262457322[28] = 0;
   out_4470570370262457322[29] = 0;
   out_4470570370262457322[30] = 0;
   out_4470570370262457322[31] = 0;
   out_4470570370262457322[32] = 0;
   out_4470570370262457322[33] = 0;
   out_4470570370262457322[34] = 0;
   out_4470570370262457322[35] = 0;
   out_4470570370262457322[36] = 0;
   out_4470570370262457322[37] = 0;
   out_4470570370262457322[38] = 0;
   out_4470570370262457322[39] = 0;
   out_4470570370262457322[40] = 0;
   out_4470570370262457322[41] = 1;
   out_4470570370262457322[42] = 0;
   out_4470570370262457322[43] = 0;
   out_4470570370262457322[44] = 0;
   out_4470570370262457322[45] = 0;
   out_4470570370262457322[46] = 0;
   out_4470570370262457322[47] = 0;
   out_4470570370262457322[48] = 0;
   out_4470570370262457322[49] = 0;
   out_4470570370262457322[50] = 0;
   out_4470570370262457322[51] = 0;
   out_4470570370262457322[52] = 0;
   out_4470570370262457322[53] = 0;
}
void h_14(double *state, double *unused, double *out_4210801819040852578) {
   out_4210801819040852578[0] = state[6];
   out_4210801819040852578[1] = state[7];
   out_4210801819040852578[2] = state[8];
}
void H_14(double *state, double *unused, double *out_3719603339255305594) {
   out_3719603339255305594[0] = 0;
   out_3719603339255305594[1] = 0;
   out_3719603339255305594[2] = 0;
   out_3719603339255305594[3] = 0;
   out_3719603339255305594[4] = 0;
   out_3719603339255305594[5] = 0;
   out_3719603339255305594[6] = 1;
   out_3719603339255305594[7] = 0;
   out_3719603339255305594[8] = 0;
   out_3719603339255305594[9] = 0;
   out_3719603339255305594[10] = 0;
   out_3719603339255305594[11] = 0;
   out_3719603339255305594[12] = 0;
   out_3719603339255305594[13] = 0;
   out_3719603339255305594[14] = 0;
   out_3719603339255305594[15] = 0;
   out_3719603339255305594[16] = 0;
   out_3719603339255305594[17] = 0;
   out_3719603339255305594[18] = 0;
   out_3719603339255305594[19] = 0;
   out_3719603339255305594[20] = 0;
   out_3719603339255305594[21] = 0;
   out_3719603339255305594[22] = 0;
   out_3719603339255305594[23] = 0;
   out_3719603339255305594[24] = 0;
   out_3719603339255305594[25] = 1;
   out_3719603339255305594[26] = 0;
   out_3719603339255305594[27] = 0;
   out_3719603339255305594[28] = 0;
   out_3719603339255305594[29] = 0;
   out_3719603339255305594[30] = 0;
   out_3719603339255305594[31] = 0;
   out_3719603339255305594[32] = 0;
   out_3719603339255305594[33] = 0;
   out_3719603339255305594[34] = 0;
   out_3719603339255305594[35] = 0;
   out_3719603339255305594[36] = 0;
   out_3719603339255305594[37] = 0;
   out_3719603339255305594[38] = 0;
   out_3719603339255305594[39] = 0;
   out_3719603339255305594[40] = 0;
   out_3719603339255305594[41] = 0;
   out_3719603339255305594[42] = 0;
   out_3719603339255305594[43] = 0;
   out_3719603339255305594[44] = 1;
   out_3719603339255305594[45] = 0;
   out_3719603339255305594[46] = 0;
   out_3719603339255305594[47] = 0;
   out_3719603339255305594[48] = 0;
   out_3719603339255305594[49] = 0;
   out_3719603339255305594[50] = 0;
   out_3719603339255305594[51] = 0;
   out_3719603339255305594[52] = 0;
   out_3719603339255305594[53] = 0;
}
#include <eigen3/Eigen/Dense>
#include <iostream>

typedef Eigen::Matrix<double, DIM, DIM, Eigen::RowMajor> DDM;
typedef Eigen::Matrix<double, EDIM, EDIM, Eigen::RowMajor> EEM;
typedef Eigen::Matrix<double, DIM, EDIM, Eigen::RowMajor> DEM;

void predict(double *in_x, double *in_P, double *in_Q, double dt) {
  typedef Eigen::Matrix<double, MEDIM, MEDIM, Eigen::RowMajor> RRM;

  double nx[DIM] = {0};
  double in_F[EDIM*EDIM] = {0};

  // functions from sympy
  f_fun(in_x, dt, nx);
  F_fun(in_x, dt, in_F);


  EEM F(in_F);
  EEM P(in_P);
  EEM Q(in_Q);

  RRM F_main = F.topLeftCorner(MEDIM, MEDIM);
  P.topLeftCorner(MEDIM, MEDIM) = (F_main * P.topLeftCorner(MEDIM, MEDIM)) * F_main.transpose();
  P.topRightCorner(MEDIM, EDIM - MEDIM) = F_main * P.topRightCorner(MEDIM, EDIM - MEDIM);
  P.bottomLeftCorner(EDIM - MEDIM, MEDIM) = P.bottomLeftCorner(EDIM - MEDIM, MEDIM) * F_main.transpose();

  P = P + dt*Q;

  // copy out state
  memcpy(in_x, nx, DIM * sizeof(double));
  memcpy(in_P, P.data(), EDIM * EDIM * sizeof(double));
}

// note: extra_args dim only correct when null space projecting
// otherwise 1
template <int ZDIM, int EADIM, bool MAHA_TEST>
void update(double *in_x, double *in_P, Hfun h_fun, Hfun H_fun, Hfun Hea_fun, double *in_z, double *in_R, double *in_ea, double MAHA_THRESHOLD) {
  typedef Eigen::Matrix<double, ZDIM, ZDIM, Eigen::RowMajor> ZZM;
  typedef Eigen::Matrix<double, ZDIM, DIM, Eigen::RowMajor> ZDM;
  typedef Eigen::Matrix<double, Eigen::Dynamic, EDIM, Eigen::RowMajor> XEM;
  //typedef Eigen::Matrix<double, EDIM, ZDIM, Eigen::RowMajor> EZM;
  typedef Eigen::Matrix<double, Eigen::Dynamic, 1> X1M;
  typedef Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic, Eigen::RowMajor> XXM;

  double in_hx[ZDIM] = {0};
  double in_H[ZDIM * DIM] = {0};
  double in_H_mod[EDIM * DIM] = {0};
  double delta_x[EDIM] = {0};
  double x_new[DIM] = {0};


  // state x, P
  Eigen::Matrix<double, ZDIM, 1> z(in_z);
  EEM P(in_P);
  ZZM pre_R(in_R);

  // functions from sympy
  h_fun(in_x, in_ea, in_hx);
  H_fun(in_x, in_ea, in_H);
  ZDM pre_H(in_H);

  // get y (y = z - hx)
  Eigen::Matrix<double, ZDIM, 1> pre_y(in_hx); pre_y = z - pre_y;
  X1M y; XXM H; XXM R;
  if (Hea_fun){
    typedef Eigen::Matrix<double, ZDIM, EADIM, Eigen::RowMajor> ZAM;
    double in_Hea[ZDIM * EADIM] = {0};
    Hea_fun(in_x, in_ea, in_Hea);
    ZAM Hea(in_Hea);
    XXM A = Hea.transpose().fullPivLu().kernel();


    y = A.transpose() * pre_y;
    H = A.transpose() * pre_H;
    R = A.transpose() * pre_R * A;
  } else {
    y = pre_y;
    H = pre_H;
    R = pre_R;
  }
  // get modified H
  H_mod_fun(in_x, in_H_mod);
  DEM H_mod(in_H_mod);
  XEM H_err = H * H_mod;

  // Do mahalobis distance test
  if (MAHA_TEST){
    XXM a = (H_err * P * H_err.transpose() + R).inverse();
    double maha_dist = y.transpose() * a * y;
    if (maha_dist > MAHA_THRESHOLD){
      R = 1.0e16 * R;
    }
  }

  // Outlier resilient weighting
  double weight = 1;//(1.5)/(1 + y.squaredNorm()/R.sum());

  // kalman gains and I_KH
  XXM S = ((H_err * P) * H_err.transpose()) + R/weight;
  XEM KT = S.fullPivLu().solve(H_err * P.transpose());
  //EZM K = KT.transpose(); TODO: WHY DOES THIS NOT COMPILE?
  //EZM K = S.fullPivLu().solve(H_err * P.transpose()).transpose();
  //std::cout << "Here is the matrix rot:\n" << K << std::endl;
  EEM I_KH = Eigen::Matrix<double, EDIM, EDIM>::Identity() - (KT.transpose() * H_err);

  // update state by injecting dx
  Eigen::Matrix<double, EDIM, 1> dx(delta_x);
  dx  = (KT.transpose() * y);
  memcpy(delta_x, dx.data(), EDIM * sizeof(double));
  err_fun(in_x, delta_x, x_new);
  Eigen::Matrix<double, DIM, 1> x(x_new);

  // update cov
  P = ((I_KH * P) * I_KH.transpose()) + ((KT.transpose() * R) * KT);

  // copy out state
  memcpy(in_x, x.data(), DIM * sizeof(double));
  memcpy(in_P, P.data(), EDIM * EDIM * sizeof(double));
  memcpy(in_z, y.data(), y.rows() * sizeof(double));
}




}
extern "C" {

void pose_update_4(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<3, 3, 0>(in_x, in_P, h_4, H_4, NULL, in_z, in_R, in_ea, MAHA_THRESH_4);
}
void pose_update_10(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<3, 3, 0>(in_x, in_P, h_10, H_10, NULL, in_z, in_R, in_ea, MAHA_THRESH_10);
}
void pose_update_13(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<3, 3, 0>(in_x, in_P, h_13, H_13, NULL, in_z, in_R, in_ea, MAHA_THRESH_13);
}
void pose_update_14(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<3, 3, 0>(in_x, in_P, h_14, H_14, NULL, in_z, in_R, in_ea, MAHA_THRESH_14);
}
void pose_err_fun(double *nom_x, double *delta_x, double *out_6503352805626710270) {
  err_fun(nom_x, delta_x, out_6503352805626710270);
}
void pose_inv_err_fun(double *nom_x, double *true_x, double *out_5975171236647925331) {
  inv_err_fun(nom_x, true_x, out_5975171236647925331);
}
void pose_H_mod_fun(double *state, double *out_6149272841185445129) {
  H_mod_fun(state, out_6149272841185445129);
}
void pose_f_fun(double *state, double dt, double *out_1838878275411859331) {
  f_fun(state,  dt, out_1838878275411859331);
}
void pose_F_fun(double *state, double dt, double *out_8197411821134071860) {
  F_fun(state,  dt, out_8197411821134071860);
}
void pose_h_4(double *state, double *unused, double *out_1806626447084815176) {
  h_4(state, unused, out_1806626447084815176);
}
void pose_H_4(double *state, double *unused, double *out_7682844195594790123) {
  H_4(state, unused, out_7682844195594790123);
}
void pose_h_10(double *state, double *unused, double *out_6123324008369649598) {
  h_10(state, unused, out_6123324008369649598);
}
void pose_H_10(double *state, double *unused, double *out_3416431020486776412) {
  H_10(state, unused, out_3416431020486776412);
}
void pose_h_13(double *state, double *unused, double *out_8162596648124754745) {
  h_13(state, unused, out_8162596648124754745);
}
void pose_H_13(double *state, double *unused, double *out_4470570370262457322) {
  H_13(state, unused, out_4470570370262457322);
}
void pose_h_14(double *state, double *unused, double *out_4210801819040852578) {
  h_14(state, unused, out_4210801819040852578);
}
void pose_H_14(double *state, double *unused, double *out_3719603339255305594) {
  H_14(state, unused, out_3719603339255305594);
}
void pose_predict(double *in_x, double *in_P, double *in_Q, double dt) {
  predict(in_x, in_P, in_Q, dt);
}
}

const EKF pose = {
  .name = "pose",
  .kinds = { 4, 10, 13, 14 },
  .feature_kinds = {  },
  .f_fun = pose_f_fun,
  .F_fun = pose_F_fun,
  .err_fun = pose_err_fun,
  .inv_err_fun = pose_inv_err_fun,
  .H_mod_fun = pose_H_mod_fun,
  .predict = pose_predict,
  .hs = {
    { 4, pose_h_4 },
    { 10, pose_h_10 },
    { 13, pose_h_13 },
    { 14, pose_h_14 },
  },
  .Hs = {
    { 4, pose_H_4 },
    { 10, pose_H_10 },
    { 13, pose_H_13 },
    { 14, pose_H_14 },
  },
  .updates = {
    { 4, pose_update_4 },
    { 10, pose_update_10 },
    { 13, pose_update_13 },
    { 14, pose_update_14 },
  },
  .Hes = {
  },
  .sets = {
  },
  .extra_routines = {
  },
};

ekf_lib_init(pose)
