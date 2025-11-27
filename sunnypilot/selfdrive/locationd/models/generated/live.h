#pragma once
#include "rednose/helpers/ekf.h"
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
void live_H(double *in_vec, double *out_3746088166132159127);
void live_err_fun(double *nom_x, double *delta_x, double *out_4597720566166518726);
void live_inv_err_fun(double *nom_x, double *true_x, double *out_5152015585227025930);
void live_H_mod_fun(double *state, double *out_3538775857274182510);
void live_f_fun(double *state, double dt, double *out_2835497647505510770);
void live_F_fun(double *state, double dt, double *out_8957585311766843944);
void live_h_4(double *state, double *unused, double *out_3069339368439668716);
void live_H_4(double *state, double *unused, double *out_5213668598284550872);
void live_h_9(double *state, double *unused, double *out_2621828903796805241);
void live_H_9(double *state, double *unused, double *out_4972478951654960227);
void live_h_10(double *state, double *unused, double *out_7320230676000023735);
void live_H_10(double *state, double *unused, double *out_3713780294100606798);
void live_h_12(double *state, double *unused, double *out_1877924099639949704);
void live_H_12(double *state, double *unused, double *out_194212190252589077);
void live_h_35(double *state, double *unused, double *out_4443540922947752642);
void live_H_35(double *state, double *unused, double *out_2551350842072424632);
void live_h_32(double *state, double *unused, double *out_3401693932972443803);
void live_H_32(double *state, double *unused, double *out_4492189179405433433);
void live_h_13(double *state, double *unused, double *out_8401295644687153679);
void live_H_13(double *state, double *unused, double *out_9041248866241180444);
void live_h_14(double *state, double *unused, double *out_2621828903796805241);
void live_H_14(double *state, double *unused, double *out_4972478951654960227);
void live_h_33(double *state, double *unused, double *out_2831877191129948679);
void live_H_33(double *state, double *unused, double *out_1303550463726914108);
void live_predict(double *in_x, double *in_P, double *in_Q, double dt);
}