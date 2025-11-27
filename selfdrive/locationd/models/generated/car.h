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
void car_err_fun(double *nom_x, double *delta_x, double *out_6067310311250202908);
void car_inv_err_fun(double *nom_x, double *true_x, double *out_8448616162531093988);
void car_H_mod_fun(double *state, double *out_5958727610096104051);
void car_f_fun(double *state, double dt, double *out_8528889567494776155);
void car_F_fun(double *state, double dt, double *out_8216682491442460375);
void car_h_25(double *state, double *unused, double *out_5214361416198013126);
void car_H_25(double *state, double *unused, double *out_3234460615816133186);
void car_h_24(double *state, double *unused, double *out_4921532633404858084);
void car_H_24(double *state, double *unused, double *out_7980969942782642220);
void car_h_30(double *state, double *unused, double *out_6461547431161187554);
void car_H_30(double *state, double *unused, double *out_716127657308884559);
void car_h_26(double *state, double *unused, double *out_1459874163500341909);
void car_H_26(double *state, double *unused, double *out_6975963934690189410);
void car_h_27(double *state, double *unused, double *out_7890515421625507927);
void car_H_27(double *state, double *unused, double *out_8509823815965385321);
void car_h_29(double *state, double *unused, double *out_1119680195275156991);
void car_H_29(double *state, double *unused, double *out_7251925601629349200);
void car_h_28(double *state, double *unused, double *out_5286110100816810276);
void car_H_28(double *state, double *unused, double *out_5288295330064022949);
void car_h_31(double *state, double *unused, double *out_3266605041875997847);
void car_H_31(double *state, double *unused, double *out_7602172036923540886);
void car_predict(double *in_x, double *in_P, double *in_Q, double dt);
void car_set_mass(double x);
void car_set_rotational_inertia(double x);
void car_set_center_to_front(double x);
void car_set_center_to_rear(double x);
void car_set_stiffness_front(double x);
void car_set_stiffness_rear(double x);
}