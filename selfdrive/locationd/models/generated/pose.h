#pragma once
#include "rednose/helpers/ekf.h"
extern "C" {
void pose_update_4(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_10(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_13(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_14(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_err_fun(double *nom_x, double *delta_x, double *out_6503352805626710270);
void pose_inv_err_fun(double *nom_x, double *true_x, double *out_5975171236647925331);
void pose_H_mod_fun(double *state, double *out_6149272841185445129);
void pose_f_fun(double *state, double dt, double *out_1838878275411859331);
void pose_F_fun(double *state, double dt, double *out_8197411821134071860);
void pose_h_4(double *state, double *unused, double *out_1806626447084815176);
void pose_H_4(double *state, double *unused, double *out_7682844195594790123);
void pose_h_10(double *state, double *unused, double *out_6123324008369649598);
void pose_H_10(double *state, double *unused, double *out_3416431020486776412);
void pose_h_13(double *state, double *unused, double *out_8162596648124754745);
void pose_H_13(double *state, double *unused, double *out_4470570370262457322);
void pose_h_14(double *state, double *unused, double *out_4210801819040852578);
void pose_H_14(double *state, double *unused, double *out_3719603339255305594);
void pose_predict(double *in_x, double *in_P, double *in_Q, double dt);
}