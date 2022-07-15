#pragma once
#include "rednose/helpers/common_ekf.h"
extern "C" {
void gnss_update_6(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void gnss_update_20(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void gnss_update_7(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void gnss_update_21(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void gnss_err_fun(double *nom_x, double *delta_x, double *out_48758063581004439);
void gnss_inv_err_fun(double *nom_x, double *true_x, double *out_1607758100236935416);
void gnss_H_mod_fun(double *state, double *out_4012336181068605512);
void gnss_f_fun(double *state, double dt, double *out_2899754366926900778);
void gnss_F_fun(double *state, double dt, double *out_3689585444102404179);
void gnss_h_6(double *state, double *sat_pos, double *out_8698402948288574844);
void gnss_H_6(double *state, double *sat_pos, double *out_6931197630794968938);
void gnss_h_20(double *state, double *sat_pos, double *out_3720493620565410054);
void gnss_H_20(double *state, double *sat_pos, double *out_7867916610592577929);
void gnss_h_7(double *state, double *sat_pos_vel, double *out_7013708649085588005);
void gnss_H_7(double *state, double *sat_pos_vel, double *out_1300287474491876881);
void gnss_h_21(double *state, double *sat_pos_vel, double *out_7013708649085588005);
void gnss_H_21(double *state, double *sat_pos_vel, double *out_1300287474491876881);
void gnss_predict(double *in_x, double *in_P, double *in_Q, double dt);
}