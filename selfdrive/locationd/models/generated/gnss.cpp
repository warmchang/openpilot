#include "gnss.h"

namespace {
#define DIM 11
#define EDIM 11
#define MEDIM 11
typedef void (*Hfun)(double *, double *, double *);
const static double MAHA_THRESH_6 = 3.8414588206941227;
const static double MAHA_THRESH_20 = 3.8414588206941227;
const static double MAHA_THRESH_7 = 3.8414588206941227;
const static double MAHA_THRESH_21 = 3.8414588206941227;

/******************************************************************************
 *                      Code generated with SymPy 1.10.1                      *
 *                                                                            *
 *              See http://www.sympy.org/ for more information.               *
 *                                                                            *
 *                         This file is part of 'ekf'                         *
 ******************************************************************************/
void err_fun(double *nom_x, double *delta_x, double *out_48758063581004439) {
   out_48758063581004439[0] = delta_x[0] + nom_x[0];
   out_48758063581004439[1] = delta_x[1] + nom_x[1];
   out_48758063581004439[2] = delta_x[2] + nom_x[2];
   out_48758063581004439[3] = delta_x[3] + nom_x[3];
   out_48758063581004439[4] = delta_x[4] + nom_x[4];
   out_48758063581004439[5] = delta_x[5] + nom_x[5];
   out_48758063581004439[6] = delta_x[6] + nom_x[6];
   out_48758063581004439[7] = delta_x[7] + nom_x[7];
   out_48758063581004439[8] = delta_x[8] + nom_x[8];
   out_48758063581004439[9] = delta_x[9] + nom_x[9];
   out_48758063581004439[10] = delta_x[10] + nom_x[10];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_1607758100236935416) {
   out_1607758100236935416[0] = -nom_x[0] + true_x[0];
   out_1607758100236935416[1] = -nom_x[1] + true_x[1];
   out_1607758100236935416[2] = -nom_x[2] + true_x[2];
   out_1607758100236935416[3] = -nom_x[3] + true_x[3];
   out_1607758100236935416[4] = -nom_x[4] + true_x[4];
   out_1607758100236935416[5] = -nom_x[5] + true_x[5];
   out_1607758100236935416[6] = -nom_x[6] + true_x[6];
   out_1607758100236935416[7] = -nom_x[7] + true_x[7];
   out_1607758100236935416[8] = -nom_x[8] + true_x[8];
   out_1607758100236935416[9] = -nom_x[9] + true_x[9];
   out_1607758100236935416[10] = -nom_x[10] + true_x[10];
}
void H_mod_fun(double *state, double *out_4012336181068605512) {
   out_4012336181068605512[0] = 1.0;
   out_4012336181068605512[1] = 0;
   out_4012336181068605512[2] = 0;
   out_4012336181068605512[3] = 0;
   out_4012336181068605512[4] = 0;
   out_4012336181068605512[5] = 0;
   out_4012336181068605512[6] = 0;
   out_4012336181068605512[7] = 0;
   out_4012336181068605512[8] = 0;
   out_4012336181068605512[9] = 0;
   out_4012336181068605512[10] = 0;
   out_4012336181068605512[11] = 0;
   out_4012336181068605512[12] = 1.0;
   out_4012336181068605512[13] = 0;
   out_4012336181068605512[14] = 0;
   out_4012336181068605512[15] = 0;
   out_4012336181068605512[16] = 0;
   out_4012336181068605512[17] = 0;
   out_4012336181068605512[18] = 0;
   out_4012336181068605512[19] = 0;
   out_4012336181068605512[20] = 0;
   out_4012336181068605512[21] = 0;
   out_4012336181068605512[22] = 0;
   out_4012336181068605512[23] = 0;
   out_4012336181068605512[24] = 1.0;
   out_4012336181068605512[25] = 0;
   out_4012336181068605512[26] = 0;
   out_4012336181068605512[27] = 0;
   out_4012336181068605512[28] = 0;
   out_4012336181068605512[29] = 0;
   out_4012336181068605512[30] = 0;
   out_4012336181068605512[31] = 0;
   out_4012336181068605512[32] = 0;
   out_4012336181068605512[33] = 0;
   out_4012336181068605512[34] = 0;
   out_4012336181068605512[35] = 0;
   out_4012336181068605512[36] = 1.0;
   out_4012336181068605512[37] = 0;
   out_4012336181068605512[38] = 0;
   out_4012336181068605512[39] = 0;
   out_4012336181068605512[40] = 0;
   out_4012336181068605512[41] = 0;
   out_4012336181068605512[42] = 0;
   out_4012336181068605512[43] = 0;
   out_4012336181068605512[44] = 0;
   out_4012336181068605512[45] = 0;
   out_4012336181068605512[46] = 0;
   out_4012336181068605512[47] = 0;
   out_4012336181068605512[48] = 1.0;
   out_4012336181068605512[49] = 0;
   out_4012336181068605512[50] = 0;
   out_4012336181068605512[51] = 0;
   out_4012336181068605512[52] = 0;
   out_4012336181068605512[53] = 0;
   out_4012336181068605512[54] = 0;
   out_4012336181068605512[55] = 0;
   out_4012336181068605512[56] = 0;
   out_4012336181068605512[57] = 0;
   out_4012336181068605512[58] = 0;
   out_4012336181068605512[59] = 0;
   out_4012336181068605512[60] = 1.0;
   out_4012336181068605512[61] = 0;
   out_4012336181068605512[62] = 0;
   out_4012336181068605512[63] = 0;
   out_4012336181068605512[64] = 0;
   out_4012336181068605512[65] = 0;
   out_4012336181068605512[66] = 0;
   out_4012336181068605512[67] = 0;
   out_4012336181068605512[68] = 0;
   out_4012336181068605512[69] = 0;
   out_4012336181068605512[70] = 0;
   out_4012336181068605512[71] = 0;
   out_4012336181068605512[72] = 1.0;
   out_4012336181068605512[73] = 0;
   out_4012336181068605512[74] = 0;
   out_4012336181068605512[75] = 0;
   out_4012336181068605512[76] = 0;
   out_4012336181068605512[77] = 0;
   out_4012336181068605512[78] = 0;
   out_4012336181068605512[79] = 0;
   out_4012336181068605512[80] = 0;
   out_4012336181068605512[81] = 0;
   out_4012336181068605512[82] = 0;
   out_4012336181068605512[83] = 0;
   out_4012336181068605512[84] = 1.0;
   out_4012336181068605512[85] = 0;
   out_4012336181068605512[86] = 0;
   out_4012336181068605512[87] = 0;
   out_4012336181068605512[88] = 0;
   out_4012336181068605512[89] = 0;
   out_4012336181068605512[90] = 0;
   out_4012336181068605512[91] = 0;
   out_4012336181068605512[92] = 0;
   out_4012336181068605512[93] = 0;
   out_4012336181068605512[94] = 0;
   out_4012336181068605512[95] = 0;
   out_4012336181068605512[96] = 1.0;
   out_4012336181068605512[97] = 0;
   out_4012336181068605512[98] = 0;
   out_4012336181068605512[99] = 0;
   out_4012336181068605512[100] = 0;
   out_4012336181068605512[101] = 0;
   out_4012336181068605512[102] = 0;
   out_4012336181068605512[103] = 0;
   out_4012336181068605512[104] = 0;
   out_4012336181068605512[105] = 0;
   out_4012336181068605512[106] = 0;
   out_4012336181068605512[107] = 0;
   out_4012336181068605512[108] = 1.0;
   out_4012336181068605512[109] = 0;
   out_4012336181068605512[110] = 0;
   out_4012336181068605512[111] = 0;
   out_4012336181068605512[112] = 0;
   out_4012336181068605512[113] = 0;
   out_4012336181068605512[114] = 0;
   out_4012336181068605512[115] = 0;
   out_4012336181068605512[116] = 0;
   out_4012336181068605512[117] = 0;
   out_4012336181068605512[118] = 0;
   out_4012336181068605512[119] = 0;
   out_4012336181068605512[120] = 1.0;
}
void f_fun(double *state, double dt, double *out_2899754366926900778) {
   out_2899754366926900778[0] = dt*state[3] + state[0];
   out_2899754366926900778[1] = dt*state[4] + state[1];
   out_2899754366926900778[2] = dt*state[5] + state[2];
   out_2899754366926900778[3] = state[3];
   out_2899754366926900778[4] = state[4];
   out_2899754366926900778[5] = state[5];
   out_2899754366926900778[6] = dt*state[7] + state[6];
   out_2899754366926900778[7] = dt*state[8] + state[7];
   out_2899754366926900778[8] = state[8];
   out_2899754366926900778[9] = state[9];
   out_2899754366926900778[10] = state[10];
}
void F_fun(double *state, double dt, double *out_3689585444102404179) {
   out_3689585444102404179[0] = 1;
   out_3689585444102404179[1] = 0;
   out_3689585444102404179[2] = 0;
   out_3689585444102404179[3] = dt;
   out_3689585444102404179[4] = 0;
   out_3689585444102404179[5] = 0;
   out_3689585444102404179[6] = 0;
   out_3689585444102404179[7] = 0;
   out_3689585444102404179[8] = 0;
   out_3689585444102404179[9] = 0;
   out_3689585444102404179[10] = 0;
   out_3689585444102404179[11] = 0;
   out_3689585444102404179[12] = 1;
   out_3689585444102404179[13] = 0;
   out_3689585444102404179[14] = 0;
   out_3689585444102404179[15] = dt;
   out_3689585444102404179[16] = 0;
   out_3689585444102404179[17] = 0;
   out_3689585444102404179[18] = 0;
   out_3689585444102404179[19] = 0;
   out_3689585444102404179[20] = 0;
   out_3689585444102404179[21] = 0;
   out_3689585444102404179[22] = 0;
   out_3689585444102404179[23] = 0;
   out_3689585444102404179[24] = 1;
   out_3689585444102404179[25] = 0;
   out_3689585444102404179[26] = 0;
   out_3689585444102404179[27] = dt;
   out_3689585444102404179[28] = 0;
   out_3689585444102404179[29] = 0;
   out_3689585444102404179[30] = 0;
   out_3689585444102404179[31] = 0;
   out_3689585444102404179[32] = 0;
   out_3689585444102404179[33] = 0;
   out_3689585444102404179[34] = 0;
   out_3689585444102404179[35] = 0;
   out_3689585444102404179[36] = 1;
   out_3689585444102404179[37] = 0;
   out_3689585444102404179[38] = 0;
   out_3689585444102404179[39] = 0;
   out_3689585444102404179[40] = 0;
   out_3689585444102404179[41] = 0;
   out_3689585444102404179[42] = 0;
   out_3689585444102404179[43] = 0;
   out_3689585444102404179[44] = 0;
   out_3689585444102404179[45] = 0;
   out_3689585444102404179[46] = 0;
   out_3689585444102404179[47] = 0;
   out_3689585444102404179[48] = 1;
   out_3689585444102404179[49] = 0;
   out_3689585444102404179[50] = 0;
   out_3689585444102404179[51] = 0;
   out_3689585444102404179[52] = 0;
   out_3689585444102404179[53] = 0;
   out_3689585444102404179[54] = 0;
   out_3689585444102404179[55] = 0;
   out_3689585444102404179[56] = 0;
   out_3689585444102404179[57] = 0;
   out_3689585444102404179[58] = 0;
   out_3689585444102404179[59] = 0;
   out_3689585444102404179[60] = 1;
   out_3689585444102404179[61] = 0;
   out_3689585444102404179[62] = 0;
   out_3689585444102404179[63] = 0;
   out_3689585444102404179[64] = 0;
   out_3689585444102404179[65] = 0;
   out_3689585444102404179[66] = 0;
   out_3689585444102404179[67] = 0;
   out_3689585444102404179[68] = 0;
   out_3689585444102404179[69] = 0;
   out_3689585444102404179[70] = 0;
   out_3689585444102404179[71] = 0;
   out_3689585444102404179[72] = 1;
   out_3689585444102404179[73] = dt;
   out_3689585444102404179[74] = 0;
   out_3689585444102404179[75] = 0;
   out_3689585444102404179[76] = 0;
   out_3689585444102404179[77] = 0;
   out_3689585444102404179[78] = 0;
   out_3689585444102404179[79] = 0;
   out_3689585444102404179[80] = 0;
   out_3689585444102404179[81] = 0;
   out_3689585444102404179[82] = 0;
   out_3689585444102404179[83] = 0;
   out_3689585444102404179[84] = 1;
   out_3689585444102404179[85] = dt;
   out_3689585444102404179[86] = 0;
   out_3689585444102404179[87] = 0;
   out_3689585444102404179[88] = 0;
   out_3689585444102404179[89] = 0;
   out_3689585444102404179[90] = 0;
   out_3689585444102404179[91] = 0;
   out_3689585444102404179[92] = 0;
   out_3689585444102404179[93] = 0;
   out_3689585444102404179[94] = 0;
   out_3689585444102404179[95] = 0;
   out_3689585444102404179[96] = 1;
   out_3689585444102404179[97] = 0;
   out_3689585444102404179[98] = 0;
   out_3689585444102404179[99] = 0;
   out_3689585444102404179[100] = 0;
   out_3689585444102404179[101] = 0;
   out_3689585444102404179[102] = 0;
   out_3689585444102404179[103] = 0;
   out_3689585444102404179[104] = 0;
   out_3689585444102404179[105] = 0;
   out_3689585444102404179[106] = 0;
   out_3689585444102404179[107] = 0;
   out_3689585444102404179[108] = 1;
   out_3689585444102404179[109] = 0;
   out_3689585444102404179[110] = 0;
   out_3689585444102404179[111] = 0;
   out_3689585444102404179[112] = 0;
   out_3689585444102404179[113] = 0;
   out_3689585444102404179[114] = 0;
   out_3689585444102404179[115] = 0;
   out_3689585444102404179[116] = 0;
   out_3689585444102404179[117] = 0;
   out_3689585444102404179[118] = 0;
   out_3689585444102404179[119] = 0;
   out_3689585444102404179[120] = 1;
}
void h_6(double *state, double *sat_pos, double *out_8698402948288574844) {
   out_8698402948288574844[0] = sqrt(pow(-sat_pos[0] + state[0], 2) + pow(-sat_pos[1] + state[1], 2) + pow(-sat_pos[2] + state[2], 2)) + state[6];
}
void H_6(double *state, double *sat_pos, double *out_6931197630794968938) {
   out_6931197630794968938[0] = (-sat_pos[0] + state[0])/sqrt(pow(-sat_pos[0] + state[0], 2) + pow(-sat_pos[1] + state[1], 2) + pow(-sat_pos[2] + state[2], 2));
   out_6931197630794968938[1] = (-sat_pos[1] + state[1])/sqrt(pow(-sat_pos[0] + state[0], 2) + pow(-sat_pos[1] + state[1], 2) + pow(-sat_pos[2] + state[2], 2));
   out_6931197630794968938[2] = (-sat_pos[2] + state[2])/sqrt(pow(-sat_pos[0] + state[0], 2) + pow(-sat_pos[1] + state[1], 2) + pow(-sat_pos[2] + state[2], 2));
   out_6931197630794968938[3] = 0;
   out_6931197630794968938[4] = 0;
   out_6931197630794968938[5] = 0;
   out_6931197630794968938[6] = 1;
   out_6931197630794968938[7] = 0;
   out_6931197630794968938[8] = 0;
   out_6931197630794968938[9] = 0;
   out_6931197630794968938[10] = 0;
}
void h_20(double *state, double *sat_pos, double *out_3720493620565410054) {
   out_3720493620565410054[0] = sqrt(pow(-sat_pos[0] + state[0], 2) + pow(-sat_pos[1] + state[1], 2) + pow(-sat_pos[2] + state[2], 2)) + sat_pos[3]*state[10] + state[6] + state[9];
}
void H_20(double *state, double *sat_pos, double *out_7867916610592577929) {
   out_7867916610592577929[0] = (-sat_pos[0] + state[0])/sqrt(pow(-sat_pos[0] + state[0], 2) + pow(-sat_pos[1] + state[1], 2) + pow(-sat_pos[2] + state[2], 2));
   out_7867916610592577929[1] = (-sat_pos[1] + state[1])/sqrt(pow(-sat_pos[0] + state[0], 2) + pow(-sat_pos[1] + state[1], 2) + pow(-sat_pos[2] + state[2], 2));
   out_7867916610592577929[2] = (-sat_pos[2] + state[2])/sqrt(pow(-sat_pos[0] + state[0], 2) + pow(-sat_pos[1] + state[1], 2) + pow(-sat_pos[2] + state[2], 2));
   out_7867916610592577929[3] = 0;
   out_7867916610592577929[4] = 0;
   out_7867916610592577929[5] = 0;
   out_7867916610592577929[6] = 1;
   out_7867916610592577929[7] = 0;
   out_7867916610592577929[8] = 0;
   out_7867916610592577929[9] = 1;
   out_7867916610592577929[10] = sat_pos[3];
}
void h_7(double *state, double *sat_pos_vel, double *out_7013708649085588005) {
   out_7013708649085588005[0] = (sat_pos_vel[0] - state[0])*(sat_pos_vel[3] - state[3])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2)) + (sat_pos_vel[1] - state[1])*(sat_pos_vel[4] - state[4])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2)) + (sat_pos_vel[2] - state[2])*(sat_pos_vel[5] - state[5])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2)) + state[7];
}
void H_7(double *state, double *sat_pos_vel, double *out_1300287474491876881) {
   out_1300287474491876881[0] = pow(sat_pos_vel[0] - state[0], 2)*(sat_pos_vel[3] - state[3])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + (sat_pos_vel[0] - state[0])*(sat_pos_vel[1] - state[1])*(sat_pos_vel[4] - state[4])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + (sat_pos_vel[0] - state[0])*(sat_pos_vel[2] - state[2])*(sat_pos_vel[5] - state[5])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) - (sat_pos_vel[3] - state[3])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_1300287474491876881[1] = (sat_pos_vel[0] - state[0])*(sat_pos_vel[1] - state[1])*(sat_pos_vel[3] - state[3])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + pow(sat_pos_vel[1] - state[1], 2)*(sat_pos_vel[4] - state[4])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + (sat_pos_vel[1] - state[1])*(sat_pos_vel[2] - state[2])*(sat_pos_vel[5] - state[5])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) - (sat_pos_vel[4] - state[4])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_1300287474491876881[2] = (sat_pos_vel[0] - state[0])*(sat_pos_vel[2] - state[2])*(sat_pos_vel[3] - state[3])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + (sat_pos_vel[1] - state[1])*(sat_pos_vel[2] - state[2])*(sat_pos_vel[4] - state[4])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + pow(sat_pos_vel[2] - state[2], 2)*(sat_pos_vel[5] - state[5])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) - (sat_pos_vel[5] - state[5])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_1300287474491876881[3] = -(sat_pos_vel[0] - state[0])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_1300287474491876881[4] = -(sat_pos_vel[1] - state[1])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_1300287474491876881[5] = -(sat_pos_vel[2] - state[2])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_1300287474491876881[6] = 0;
   out_1300287474491876881[7] = 1;
   out_1300287474491876881[8] = 0;
   out_1300287474491876881[9] = 0;
   out_1300287474491876881[10] = 0;
}
void h_21(double *state, double *sat_pos_vel, double *out_7013708649085588005) {
   out_7013708649085588005[0] = (sat_pos_vel[0] - state[0])*(sat_pos_vel[3] - state[3])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2)) + (sat_pos_vel[1] - state[1])*(sat_pos_vel[4] - state[4])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2)) + (sat_pos_vel[2] - state[2])*(sat_pos_vel[5] - state[5])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2)) + state[7];
}
void H_21(double *state, double *sat_pos_vel, double *out_1300287474491876881) {
   out_1300287474491876881[0] = pow(sat_pos_vel[0] - state[0], 2)*(sat_pos_vel[3] - state[3])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + (sat_pos_vel[0] - state[0])*(sat_pos_vel[1] - state[1])*(sat_pos_vel[4] - state[4])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + (sat_pos_vel[0] - state[0])*(sat_pos_vel[2] - state[2])*(sat_pos_vel[5] - state[5])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) - (sat_pos_vel[3] - state[3])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_1300287474491876881[1] = (sat_pos_vel[0] - state[0])*(sat_pos_vel[1] - state[1])*(sat_pos_vel[3] - state[3])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + pow(sat_pos_vel[1] - state[1], 2)*(sat_pos_vel[4] - state[4])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + (sat_pos_vel[1] - state[1])*(sat_pos_vel[2] - state[2])*(sat_pos_vel[5] - state[5])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) - (sat_pos_vel[4] - state[4])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_1300287474491876881[2] = (sat_pos_vel[0] - state[0])*(sat_pos_vel[2] - state[2])*(sat_pos_vel[3] - state[3])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + (sat_pos_vel[1] - state[1])*(sat_pos_vel[2] - state[2])*(sat_pos_vel[4] - state[4])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + pow(sat_pos_vel[2] - state[2], 2)*(sat_pos_vel[5] - state[5])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) - (sat_pos_vel[5] - state[5])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_1300287474491876881[3] = -(sat_pos_vel[0] - state[0])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_1300287474491876881[4] = -(sat_pos_vel[1] - state[1])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_1300287474491876881[5] = -(sat_pos_vel[2] - state[2])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_1300287474491876881[6] = 0;
   out_1300287474491876881[7] = 1;
   out_1300287474491876881[8] = 0;
   out_1300287474491876881[9] = 0;
   out_1300287474491876881[10] = 0;
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

void gnss_update_6(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_6, H_6, NULL, in_z, in_R, in_ea, MAHA_THRESH_6);
}
void gnss_update_20(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_20, H_20, NULL, in_z, in_R, in_ea, MAHA_THRESH_20);
}
void gnss_update_7(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_7, H_7, NULL, in_z, in_R, in_ea, MAHA_THRESH_7);
}
void gnss_update_21(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_21, H_21, NULL, in_z, in_R, in_ea, MAHA_THRESH_21);
}
void gnss_err_fun(double *nom_x, double *delta_x, double *out_48758063581004439) {
  err_fun(nom_x, delta_x, out_48758063581004439);
}
void gnss_inv_err_fun(double *nom_x, double *true_x, double *out_1607758100236935416) {
  inv_err_fun(nom_x, true_x, out_1607758100236935416);
}
void gnss_H_mod_fun(double *state, double *out_4012336181068605512) {
  H_mod_fun(state, out_4012336181068605512);
}
void gnss_f_fun(double *state, double dt, double *out_2899754366926900778) {
  f_fun(state,  dt, out_2899754366926900778);
}
void gnss_F_fun(double *state, double dt, double *out_3689585444102404179) {
  F_fun(state,  dt, out_3689585444102404179);
}
void gnss_h_6(double *state, double *sat_pos, double *out_8698402948288574844) {
  h_6(state, sat_pos, out_8698402948288574844);
}
void gnss_H_6(double *state, double *sat_pos, double *out_6931197630794968938) {
  H_6(state, sat_pos, out_6931197630794968938);
}
void gnss_h_20(double *state, double *sat_pos, double *out_3720493620565410054) {
  h_20(state, sat_pos, out_3720493620565410054);
}
void gnss_H_20(double *state, double *sat_pos, double *out_7867916610592577929) {
  H_20(state, sat_pos, out_7867916610592577929);
}
void gnss_h_7(double *state, double *sat_pos_vel, double *out_7013708649085588005) {
  h_7(state, sat_pos_vel, out_7013708649085588005);
}
void gnss_H_7(double *state, double *sat_pos_vel, double *out_1300287474491876881) {
  H_7(state, sat_pos_vel, out_1300287474491876881);
}
void gnss_h_21(double *state, double *sat_pos_vel, double *out_7013708649085588005) {
  h_21(state, sat_pos_vel, out_7013708649085588005);
}
void gnss_H_21(double *state, double *sat_pos_vel, double *out_1300287474491876881) {
  H_21(state, sat_pos_vel, out_1300287474491876881);
}
void gnss_predict(double *in_x, double *in_P, double *in_Q, double dt) {
  predict(in_x, in_P, in_Q, dt);
}
}

const EKF gnss = {
  .name = "gnss",
  .kinds = { 6, 20, 7, 21 },
  .feature_kinds = {  },
  .f_fun = gnss_f_fun,
  .F_fun = gnss_F_fun,
  .err_fun = gnss_err_fun,
  .inv_err_fun = gnss_inv_err_fun,
  .H_mod_fun = gnss_H_mod_fun,
  .predict = gnss_predict,
  .hs = {
    { 6, gnss_h_6 },
    { 20, gnss_h_20 },
    { 7, gnss_h_7 },
    { 21, gnss_h_21 },
  },
  .Hs = {
    { 6, gnss_H_6 },
    { 20, gnss_H_20 },
    { 7, gnss_H_7 },
    { 21, gnss_H_21 },
  },
  .updates = {
    { 6, gnss_update_6 },
    { 20, gnss_update_20 },
    { 7, gnss_update_7 },
    { 21, gnss_update_21 },
  },
  .Hes = {
  },
  .sets = {
  },
  .extra_routines = {
  },
};

ekf_init(gnss);
