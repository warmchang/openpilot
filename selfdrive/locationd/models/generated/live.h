#pragma once
#include "rednose/helpers/common_ekf.h"
extern "C" {
void live_update_4(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_9(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_10(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_12(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_35(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_32(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_13(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_14(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_33(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_H(double *in_vec, double *out_2168916314203170392);
void live_err_fun(double *nom_x, double *delta_x, double *out_3677991861132702640);
void live_inv_err_fun(double *nom_x, double *true_x, double *out_4193639185133627321);
void live_H_mod_fun(double *state, double *out_7723395843437171411);
void live_f_fun(double *state, double dt, double *out_7654632586872644998);
void live_F_fun(double *state, double dt, double *out_3514164014686322129);
void live_h_4(double *state, double *unused, double *out_4597397267778489686);
void live_H_4(double *state, double *unused, double *out_7541359671816305160);
void live_h_9(double *state, double *unused, double *out_1228896713598557772);
void live_H_9(double *state, double *unused, double *out_254140736551857690);
void live_h_10(double *state, double *unused, double *out_3864771250231827369);
void live_H_10(double *state, double *unused, double *out_7243155102400884539);
void live_h_12(double *state, double *unused, double *out_208960420128193132);
void live_H_12(double *state, double *unused, double *out_125768641866145332);
void live_h_35(double *state, double *unused, double *out_4664419399287101723);
void live_H_35(double *state, double *unused, double *out_2871331674191159041);
void live_h_32(double *state, double *unused, double *out_3012430670723782515);
void live_H_32(double *state, double *unused, double *out_5819537124154597386);
void live_h_13(double *state, double *unused, double *out_3605650335685201037);
void live_H_13(double *state, double *unused, double *out_2652288282113174433);
void live_h_14(double *state, double *unused, double *out_1228896713598557772);
void live_H_14(double *state, double *unused, double *out_254140736551857690);
void live_h_33(double *state, double *unused, double *out_1189235170817110326);
void live_H_33(double *state, double *unused, double *out_6021888678830016645);
void live_predict(double *in_x, double *in_P, double *in_Q, double dt);
}