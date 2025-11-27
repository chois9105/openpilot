#pragma once
#include "rednose/helpers/ekf.h"
extern "C" {
void car_update_25(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_24(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_30(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_26(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_27(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_29(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_28(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_31(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_err_fun(double *nom_x, double *delta_x, double *out_4824996639199143778);
void car_inv_err_fun(double *nom_x, double *true_x, double *out_4831584671806270183);
void car_H_mod_fun(double *state, double *out_4591550234712496309);
void car_f_fun(double *state, double dt, double *out_5844234740239095806);
void car_F_fun(double *state, double dt, double *out_237592563865845366);
void car_h_25(double *state, double *unused, double *out_1038933864410907054);
void car_H_25(double *state, double *unused, double *out_3825102472630289060);
void car_h_24(double *state, double *unused, double *out_1496752080668854390);
void car_H_24(double *state, double *unused, double *out_2375930207220872366);
void car_h_30(double *state, double *unused, double *out_2489565257039790221);
void car_H_30(double *state, double *unused, double *out_702593857497319138);
void car_h_26(double *state, double *unused, double *out_7491238524700635866);
void car_H_26(double *state, double *unused, double *out_83599153756232836);
void car_h_27(double *state, double *unused, double *out_4027483654307435669);
void car_H_27(double *state, double *unused, double *out_1521000213686624079);
void car_h_29(double *state, double *unused, double *out_3433075109941452656);
void car_H_29(double *state, double *unused, double *out_192362513182926954);
void car_h_28(double *state, double *unused, double *out_9029156921968281314);
void car_H_28(double *state, double *unused, double *out_5274761530252457528);
void car_h_31(double *state, double *unused, double *out_213281758623064198);
void car_H_31(double *state, double *unused, double *out_3855748434507249488);
void car_predict(double *in_x, double *in_P, double *in_Q, double dt);
void car_set_mass(double x);
void car_set_rotational_inertia(double x);
void car_set_center_to_front(double x);
void car_set_center_to_rear(double x);
void car_set_stiffness_front(double x);
void car_set_stiffness_rear(double x);
}