#pragma once
#include "rednose/helpers/common_ekf.h"
extern "C" {
void car_update_25(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_24(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_30(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_26(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_27(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_29(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_28(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_31(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_err_fun(double *nom_x, double *delta_x, double *out_8638737340907944159);
void car_inv_err_fun(double *nom_x, double *true_x, double *out_3239921893740951208);
void car_H_mod_fun(double *state, double *out_4240077404384860696);
void car_f_fun(double *state, double dt, double *out_5338255258925719745);
void car_F_fun(double *state, double dt, double *out_3163113605080166128);
void car_h_25(double *state, double *unused, double *out_3882899396539912529);
void car_H_25(double *state, double *unused, double *out_882525970824787937);
void car_h_24(double *state, double *unused, double *out_6139325645259190332);
void car_H_24(double *state, double *unused, double *out_2295554218863196774);
void car_h_30(double *state, double *unused, double *out_1643158040011110584);
void car_H_30(double *state, double *unused, double *out_3645170359302820261);
void car_h_26(double *state, double *unused, double *out_699648187109448149);
void car_H_26(double *state, double *unused, double *out_2858977348049268287);
void car_h_27(double *state, double *unused, double *out_3212995403429080090);
void car_H_27(double *state, double *unused, double *out_1421576288118877044);
void car_h_29(double *state, double *unused, double *out_4247563360819808235);
void car_H_29(double *state, double *unused, double *out_3134939014988428077);
void car_h_28(double *state, double *unused, double *out_8214668671089925735);
void car_H_28(double *state, double *unused, double *out_8217338032057958651);
void car_h_31(double *state, double *unused, double *out_5974587392588906886);
void car_H_31(double *state, double *unused, double *out_913171932701748365);
void car_predict(double *in_x, double *in_P, double *in_Q, double dt);
void car_set_mass(double x);
void car_set_rotational_inertia(double x);
void car_set_center_to_front(double x);
void car_set_center_to_rear(double x);
void car_set_stiffness_front(double x);
void car_set_stiffness_rear(double x);
}