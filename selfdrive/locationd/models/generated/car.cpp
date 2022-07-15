#include "car.h"

namespace {
#define DIM 9
#define EDIM 9
#define MEDIM 9
typedef void (*Hfun)(double *, double *, double *);

double mass;

void set_mass(double x){ mass = x;}

double rotational_inertia;

void set_rotational_inertia(double x){ rotational_inertia = x;}

double center_to_front;

void set_center_to_front(double x){ center_to_front = x;}

double center_to_rear;

void set_center_to_rear(double x){ center_to_rear = x;}

double stiffness_front;

void set_stiffness_front(double x){ stiffness_front = x;}

double stiffness_rear;

void set_stiffness_rear(double x){ stiffness_rear = x;}
const static double MAHA_THRESH_25 = 3.8414588206941227;
const static double MAHA_THRESH_24 = 5.991464547107981;
const static double MAHA_THRESH_30 = 3.8414588206941227;
const static double MAHA_THRESH_26 = 3.8414588206941227;
const static double MAHA_THRESH_27 = 3.8414588206941227;
const static double MAHA_THRESH_29 = 3.8414588206941227;
const static double MAHA_THRESH_28 = 3.8414588206941227;
const static double MAHA_THRESH_31 = 3.8414588206941227;

/******************************************************************************
 *                      Code generated with SymPy 1.10.1                      *
 *                                                                            *
 *              See http://www.sympy.org/ for more information.               *
 *                                                                            *
 *                         This file is part of 'ekf'                         *
 ******************************************************************************/
void err_fun(double *nom_x, double *delta_x, double *out_8638737340907944159) {
   out_8638737340907944159[0] = delta_x[0] + nom_x[0];
   out_8638737340907944159[1] = delta_x[1] + nom_x[1];
   out_8638737340907944159[2] = delta_x[2] + nom_x[2];
   out_8638737340907944159[3] = delta_x[3] + nom_x[3];
   out_8638737340907944159[4] = delta_x[4] + nom_x[4];
   out_8638737340907944159[5] = delta_x[5] + nom_x[5];
   out_8638737340907944159[6] = delta_x[6] + nom_x[6];
   out_8638737340907944159[7] = delta_x[7] + nom_x[7];
   out_8638737340907944159[8] = delta_x[8] + nom_x[8];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_3239921893740951208) {
   out_3239921893740951208[0] = -nom_x[0] + true_x[0];
   out_3239921893740951208[1] = -nom_x[1] + true_x[1];
   out_3239921893740951208[2] = -nom_x[2] + true_x[2];
   out_3239921893740951208[3] = -nom_x[3] + true_x[3];
   out_3239921893740951208[4] = -nom_x[4] + true_x[4];
   out_3239921893740951208[5] = -nom_x[5] + true_x[5];
   out_3239921893740951208[6] = -nom_x[6] + true_x[6];
   out_3239921893740951208[7] = -nom_x[7] + true_x[7];
   out_3239921893740951208[8] = -nom_x[8] + true_x[8];
}
void H_mod_fun(double *state, double *out_4240077404384860696) {
   out_4240077404384860696[0] = 1.0;
   out_4240077404384860696[1] = 0;
   out_4240077404384860696[2] = 0;
   out_4240077404384860696[3] = 0;
   out_4240077404384860696[4] = 0;
   out_4240077404384860696[5] = 0;
   out_4240077404384860696[6] = 0;
   out_4240077404384860696[7] = 0;
   out_4240077404384860696[8] = 0;
   out_4240077404384860696[9] = 0;
   out_4240077404384860696[10] = 1.0;
   out_4240077404384860696[11] = 0;
   out_4240077404384860696[12] = 0;
   out_4240077404384860696[13] = 0;
   out_4240077404384860696[14] = 0;
   out_4240077404384860696[15] = 0;
   out_4240077404384860696[16] = 0;
   out_4240077404384860696[17] = 0;
   out_4240077404384860696[18] = 0;
   out_4240077404384860696[19] = 0;
   out_4240077404384860696[20] = 1.0;
   out_4240077404384860696[21] = 0;
   out_4240077404384860696[22] = 0;
   out_4240077404384860696[23] = 0;
   out_4240077404384860696[24] = 0;
   out_4240077404384860696[25] = 0;
   out_4240077404384860696[26] = 0;
   out_4240077404384860696[27] = 0;
   out_4240077404384860696[28] = 0;
   out_4240077404384860696[29] = 0;
   out_4240077404384860696[30] = 1.0;
   out_4240077404384860696[31] = 0;
   out_4240077404384860696[32] = 0;
   out_4240077404384860696[33] = 0;
   out_4240077404384860696[34] = 0;
   out_4240077404384860696[35] = 0;
   out_4240077404384860696[36] = 0;
   out_4240077404384860696[37] = 0;
   out_4240077404384860696[38] = 0;
   out_4240077404384860696[39] = 0;
   out_4240077404384860696[40] = 1.0;
   out_4240077404384860696[41] = 0;
   out_4240077404384860696[42] = 0;
   out_4240077404384860696[43] = 0;
   out_4240077404384860696[44] = 0;
   out_4240077404384860696[45] = 0;
   out_4240077404384860696[46] = 0;
   out_4240077404384860696[47] = 0;
   out_4240077404384860696[48] = 0;
   out_4240077404384860696[49] = 0;
   out_4240077404384860696[50] = 1.0;
   out_4240077404384860696[51] = 0;
   out_4240077404384860696[52] = 0;
   out_4240077404384860696[53] = 0;
   out_4240077404384860696[54] = 0;
   out_4240077404384860696[55] = 0;
   out_4240077404384860696[56] = 0;
   out_4240077404384860696[57] = 0;
   out_4240077404384860696[58] = 0;
   out_4240077404384860696[59] = 0;
   out_4240077404384860696[60] = 1.0;
   out_4240077404384860696[61] = 0;
   out_4240077404384860696[62] = 0;
   out_4240077404384860696[63] = 0;
   out_4240077404384860696[64] = 0;
   out_4240077404384860696[65] = 0;
   out_4240077404384860696[66] = 0;
   out_4240077404384860696[67] = 0;
   out_4240077404384860696[68] = 0;
   out_4240077404384860696[69] = 0;
   out_4240077404384860696[70] = 1.0;
   out_4240077404384860696[71] = 0;
   out_4240077404384860696[72] = 0;
   out_4240077404384860696[73] = 0;
   out_4240077404384860696[74] = 0;
   out_4240077404384860696[75] = 0;
   out_4240077404384860696[76] = 0;
   out_4240077404384860696[77] = 0;
   out_4240077404384860696[78] = 0;
   out_4240077404384860696[79] = 0;
   out_4240077404384860696[80] = 1.0;
}
void f_fun(double *state, double dt, double *out_5338255258925719745) {
   out_5338255258925719745[0] = state[0];
   out_5338255258925719745[1] = state[1];
   out_5338255258925719745[2] = state[2];
   out_5338255258925719745[3] = state[3];
   out_5338255258925719745[4] = state[4];
   out_5338255258925719745[5] = dt*((-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]))*state[6] - 9.8000000000000007*state[8] + stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*state[1]) + (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*state[4])) + state[5];
   out_5338255258925719745[6] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*state[4])) + state[6];
   out_5338255258925719745[7] = state[7];
   out_5338255258925719745[8] = state[8];
}
void F_fun(double *state, double dt, double *out_3163113605080166128) {
   out_3163113605080166128[0] = 1;
   out_3163113605080166128[1] = 0;
   out_3163113605080166128[2] = 0;
   out_3163113605080166128[3] = 0;
   out_3163113605080166128[4] = 0;
   out_3163113605080166128[5] = 0;
   out_3163113605080166128[6] = 0;
   out_3163113605080166128[7] = 0;
   out_3163113605080166128[8] = 0;
   out_3163113605080166128[9] = 0;
   out_3163113605080166128[10] = 1;
   out_3163113605080166128[11] = 0;
   out_3163113605080166128[12] = 0;
   out_3163113605080166128[13] = 0;
   out_3163113605080166128[14] = 0;
   out_3163113605080166128[15] = 0;
   out_3163113605080166128[16] = 0;
   out_3163113605080166128[17] = 0;
   out_3163113605080166128[18] = 0;
   out_3163113605080166128[19] = 0;
   out_3163113605080166128[20] = 1;
   out_3163113605080166128[21] = 0;
   out_3163113605080166128[22] = 0;
   out_3163113605080166128[23] = 0;
   out_3163113605080166128[24] = 0;
   out_3163113605080166128[25] = 0;
   out_3163113605080166128[26] = 0;
   out_3163113605080166128[27] = 0;
   out_3163113605080166128[28] = 0;
   out_3163113605080166128[29] = 0;
   out_3163113605080166128[30] = 1;
   out_3163113605080166128[31] = 0;
   out_3163113605080166128[32] = 0;
   out_3163113605080166128[33] = 0;
   out_3163113605080166128[34] = 0;
   out_3163113605080166128[35] = 0;
   out_3163113605080166128[36] = 0;
   out_3163113605080166128[37] = 0;
   out_3163113605080166128[38] = 0;
   out_3163113605080166128[39] = 0;
   out_3163113605080166128[40] = 1;
   out_3163113605080166128[41] = 0;
   out_3163113605080166128[42] = 0;
   out_3163113605080166128[43] = 0;
   out_3163113605080166128[44] = 0;
   out_3163113605080166128[45] = dt*(stiffness_front*(-state[2] - state[3] + state[7])/(mass*state[1]) + (-stiffness_front - stiffness_rear)*state[5]/(mass*state[4]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[6]/(mass*state[4]));
   out_3163113605080166128[46] = -dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*pow(state[1], 2));
   out_3163113605080166128[47] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_3163113605080166128[48] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_3163113605080166128[49] = dt*((-1 - (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*pow(state[4], 2)))*state[6] - (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*pow(state[4], 2)));
   out_3163113605080166128[50] = dt*(-stiffness_front*state[0] - stiffness_rear*state[0])/(mass*state[4]) + 1;
   out_3163113605080166128[51] = dt*(-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]));
   out_3163113605080166128[52] = dt*stiffness_front*state[0]/(mass*state[1]);
   out_3163113605080166128[53] = -9.8000000000000007*dt;
   out_3163113605080166128[54] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front - pow(center_to_rear, 2)*stiffness_rear)*state[6]/(rotational_inertia*state[4]));
   out_3163113605080166128[55] = -center_to_front*dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*pow(state[1], 2));
   out_3163113605080166128[56] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_3163113605080166128[57] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_3163113605080166128[58] = dt*(-(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*pow(state[4], 2)) - (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*pow(state[4], 2)));
   out_3163113605080166128[59] = dt*(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(rotational_inertia*state[4]);
   out_3163113605080166128[60] = dt*(-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])/(rotational_inertia*state[4]) + 1;
   out_3163113605080166128[61] = center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_3163113605080166128[62] = 0;
   out_3163113605080166128[63] = 0;
   out_3163113605080166128[64] = 0;
   out_3163113605080166128[65] = 0;
   out_3163113605080166128[66] = 0;
   out_3163113605080166128[67] = 0;
   out_3163113605080166128[68] = 0;
   out_3163113605080166128[69] = 0;
   out_3163113605080166128[70] = 1;
   out_3163113605080166128[71] = 0;
   out_3163113605080166128[72] = 0;
   out_3163113605080166128[73] = 0;
   out_3163113605080166128[74] = 0;
   out_3163113605080166128[75] = 0;
   out_3163113605080166128[76] = 0;
   out_3163113605080166128[77] = 0;
   out_3163113605080166128[78] = 0;
   out_3163113605080166128[79] = 0;
   out_3163113605080166128[80] = 1;
}
void h_25(double *state, double *unused, double *out_3882899396539912529) {
   out_3882899396539912529[0] = state[6];
}
void H_25(double *state, double *unused, double *out_882525970824787937) {
   out_882525970824787937[0] = 0;
   out_882525970824787937[1] = 0;
   out_882525970824787937[2] = 0;
   out_882525970824787937[3] = 0;
   out_882525970824787937[4] = 0;
   out_882525970824787937[5] = 0;
   out_882525970824787937[6] = 1;
   out_882525970824787937[7] = 0;
   out_882525970824787937[8] = 0;
}
void h_24(double *state, double *unused, double *out_6139325645259190332) {
   out_6139325645259190332[0] = state[4];
   out_6139325645259190332[1] = state[5];
}
void H_24(double *state, double *unused, double *out_2295554218863196774) {
   out_2295554218863196774[0] = 0;
   out_2295554218863196774[1] = 0;
   out_2295554218863196774[2] = 0;
   out_2295554218863196774[3] = 0;
   out_2295554218863196774[4] = 1;
   out_2295554218863196774[5] = 0;
   out_2295554218863196774[6] = 0;
   out_2295554218863196774[7] = 0;
   out_2295554218863196774[8] = 0;
   out_2295554218863196774[9] = 0;
   out_2295554218863196774[10] = 0;
   out_2295554218863196774[11] = 0;
   out_2295554218863196774[12] = 0;
   out_2295554218863196774[13] = 0;
   out_2295554218863196774[14] = 1;
   out_2295554218863196774[15] = 0;
   out_2295554218863196774[16] = 0;
   out_2295554218863196774[17] = 0;
}
void h_30(double *state, double *unused, double *out_1643158040011110584) {
   out_1643158040011110584[0] = state[4];
}
void H_30(double *state, double *unused, double *out_3645170359302820261) {
   out_3645170359302820261[0] = 0;
   out_3645170359302820261[1] = 0;
   out_3645170359302820261[2] = 0;
   out_3645170359302820261[3] = 0;
   out_3645170359302820261[4] = 1;
   out_3645170359302820261[5] = 0;
   out_3645170359302820261[6] = 0;
   out_3645170359302820261[7] = 0;
   out_3645170359302820261[8] = 0;
}
void h_26(double *state, double *unused, double *out_699648187109448149) {
   out_699648187109448149[0] = state[7];
}
void H_26(double *state, double *unused, double *out_2858977348049268287) {
   out_2858977348049268287[0] = 0;
   out_2858977348049268287[1] = 0;
   out_2858977348049268287[2] = 0;
   out_2858977348049268287[3] = 0;
   out_2858977348049268287[4] = 0;
   out_2858977348049268287[5] = 0;
   out_2858977348049268287[6] = 0;
   out_2858977348049268287[7] = 1;
   out_2858977348049268287[8] = 0;
}
void h_27(double *state, double *unused, double *out_3212995403429080090) {
   out_3212995403429080090[0] = state[3];
}
void H_27(double *state, double *unused, double *out_1421576288118877044) {
   out_1421576288118877044[0] = 0;
   out_1421576288118877044[1] = 0;
   out_1421576288118877044[2] = 0;
   out_1421576288118877044[3] = 1;
   out_1421576288118877044[4] = 0;
   out_1421576288118877044[5] = 0;
   out_1421576288118877044[6] = 0;
   out_1421576288118877044[7] = 0;
   out_1421576288118877044[8] = 0;
}
void h_29(double *state, double *unused, double *out_4247563360819808235) {
   out_4247563360819808235[0] = state[1];
}
void H_29(double *state, double *unused, double *out_3134939014988428077) {
   out_3134939014988428077[0] = 0;
   out_3134939014988428077[1] = 1;
   out_3134939014988428077[2] = 0;
   out_3134939014988428077[3] = 0;
   out_3134939014988428077[4] = 0;
   out_3134939014988428077[5] = 0;
   out_3134939014988428077[6] = 0;
   out_3134939014988428077[7] = 0;
   out_3134939014988428077[8] = 0;
}
void h_28(double *state, double *unused, double *out_8214668671089925735) {
   out_8214668671089925735[0] = state[0];
}
void H_28(double *state, double *unused, double *out_8217338032057958651) {
   out_8217338032057958651[0] = 1;
   out_8217338032057958651[1] = 0;
   out_8217338032057958651[2] = 0;
   out_8217338032057958651[3] = 0;
   out_8217338032057958651[4] = 0;
   out_8217338032057958651[5] = 0;
   out_8217338032057958651[6] = 0;
   out_8217338032057958651[7] = 0;
   out_8217338032057958651[8] = 0;
}
void h_31(double *state, double *unused, double *out_5974587392588906886) {
   out_5974587392588906886[0] = state[8];
}
void H_31(double *state, double *unused, double *out_913171932701748365) {
   out_913171932701748365[0] = 0;
   out_913171932701748365[1] = 0;
   out_913171932701748365[2] = 0;
   out_913171932701748365[3] = 0;
   out_913171932701748365[4] = 0;
   out_913171932701748365[5] = 0;
   out_913171932701748365[6] = 0;
   out_913171932701748365[7] = 0;
   out_913171932701748365[8] = 1;
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

void car_update_25(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_25, H_25, NULL, in_z, in_R, in_ea, MAHA_THRESH_25);
}
void car_update_24(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<2, 3, 0>(in_x, in_P, h_24, H_24, NULL, in_z, in_R, in_ea, MAHA_THRESH_24);
}
void car_update_30(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_30, H_30, NULL, in_z, in_R, in_ea, MAHA_THRESH_30);
}
void car_update_26(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_26, H_26, NULL, in_z, in_R, in_ea, MAHA_THRESH_26);
}
void car_update_27(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_27, H_27, NULL, in_z, in_R, in_ea, MAHA_THRESH_27);
}
void car_update_29(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_29, H_29, NULL, in_z, in_R, in_ea, MAHA_THRESH_29);
}
void car_update_28(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_28, H_28, NULL, in_z, in_R, in_ea, MAHA_THRESH_28);
}
void car_update_31(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_31, H_31, NULL, in_z, in_R, in_ea, MAHA_THRESH_31);
}
void car_err_fun(double *nom_x, double *delta_x, double *out_8638737340907944159) {
  err_fun(nom_x, delta_x, out_8638737340907944159);
}
void car_inv_err_fun(double *nom_x, double *true_x, double *out_3239921893740951208) {
  inv_err_fun(nom_x, true_x, out_3239921893740951208);
}
void car_H_mod_fun(double *state, double *out_4240077404384860696) {
  H_mod_fun(state, out_4240077404384860696);
}
void car_f_fun(double *state, double dt, double *out_5338255258925719745) {
  f_fun(state,  dt, out_5338255258925719745);
}
void car_F_fun(double *state, double dt, double *out_3163113605080166128) {
  F_fun(state,  dt, out_3163113605080166128);
}
void car_h_25(double *state, double *unused, double *out_3882899396539912529) {
  h_25(state, unused, out_3882899396539912529);
}
void car_H_25(double *state, double *unused, double *out_882525970824787937) {
  H_25(state, unused, out_882525970824787937);
}
void car_h_24(double *state, double *unused, double *out_6139325645259190332) {
  h_24(state, unused, out_6139325645259190332);
}
void car_H_24(double *state, double *unused, double *out_2295554218863196774) {
  H_24(state, unused, out_2295554218863196774);
}
void car_h_30(double *state, double *unused, double *out_1643158040011110584) {
  h_30(state, unused, out_1643158040011110584);
}
void car_H_30(double *state, double *unused, double *out_3645170359302820261) {
  H_30(state, unused, out_3645170359302820261);
}
void car_h_26(double *state, double *unused, double *out_699648187109448149) {
  h_26(state, unused, out_699648187109448149);
}
void car_H_26(double *state, double *unused, double *out_2858977348049268287) {
  H_26(state, unused, out_2858977348049268287);
}
void car_h_27(double *state, double *unused, double *out_3212995403429080090) {
  h_27(state, unused, out_3212995403429080090);
}
void car_H_27(double *state, double *unused, double *out_1421576288118877044) {
  H_27(state, unused, out_1421576288118877044);
}
void car_h_29(double *state, double *unused, double *out_4247563360819808235) {
  h_29(state, unused, out_4247563360819808235);
}
void car_H_29(double *state, double *unused, double *out_3134939014988428077) {
  H_29(state, unused, out_3134939014988428077);
}
void car_h_28(double *state, double *unused, double *out_8214668671089925735) {
  h_28(state, unused, out_8214668671089925735);
}
void car_H_28(double *state, double *unused, double *out_8217338032057958651) {
  H_28(state, unused, out_8217338032057958651);
}
void car_h_31(double *state, double *unused, double *out_5974587392588906886) {
  h_31(state, unused, out_5974587392588906886);
}
void car_H_31(double *state, double *unused, double *out_913171932701748365) {
  H_31(state, unused, out_913171932701748365);
}
void car_predict(double *in_x, double *in_P, double *in_Q, double dt) {
  predict(in_x, in_P, in_Q, dt);
}
void car_set_mass(double x) {
  set_mass(x);
}
void car_set_rotational_inertia(double x) {
  set_rotational_inertia(x);
}
void car_set_center_to_front(double x) {
  set_center_to_front(x);
}
void car_set_center_to_rear(double x) {
  set_center_to_rear(x);
}
void car_set_stiffness_front(double x) {
  set_stiffness_front(x);
}
void car_set_stiffness_rear(double x) {
  set_stiffness_rear(x);
}
}

const EKF car = {
  .name = "car",
  .kinds = { 25, 24, 30, 26, 27, 29, 28, 31 },
  .feature_kinds = {  },
  .f_fun = car_f_fun,
  .F_fun = car_F_fun,
  .err_fun = car_err_fun,
  .inv_err_fun = car_inv_err_fun,
  .H_mod_fun = car_H_mod_fun,
  .predict = car_predict,
  .hs = {
    { 25, car_h_25 },
    { 24, car_h_24 },
    { 30, car_h_30 },
    { 26, car_h_26 },
    { 27, car_h_27 },
    { 29, car_h_29 },
    { 28, car_h_28 },
    { 31, car_h_31 },
  },
  .Hs = {
    { 25, car_H_25 },
    { 24, car_H_24 },
    { 30, car_H_30 },
    { 26, car_H_26 },
    { 27, car_H_27 },
    { 29, car_H_29 },
    { 28, car_H_28 },
    { 31, car_H_31 },
  },
  .updates = {
    { 25, car_update_25 },
    { 24, car_update_24 },
    { 30, car_update_30 },
    { 26, car_update_26 },
    { 27, car_update_27 },
    { 29, car_update_29 },
    { 28, car_update_28 },
    { 31, car_update_31 },
  },
  .Hes = {
  },
  .sets = {
    { "mass", car_set_mass },
    { "rotational_inertia", car_set_rotational_inertia },
    { "center_to_front", car_set_center_to_front },
    { "center_to_rear", car_set_center_to_rear },
    { "stiffness_front", car_set_stiffness_front },
    { "stiffness_rear", car_set_stiffness_rear },
  },
  .extra_routines = {
  },
};

ekf_init(car);
