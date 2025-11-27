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
 *                      Code generated with SymPy 1.14.0                      *
 *                                                                            *
 *              See http://www.sympy.org/ for more information.               *
 *                                                                            *
 *                         This file is part of 'ekf'                         *
 ******************************************************************************/
void err_fun(double *nom_x, double *delta_x, double *out_4824996639199143778) {
   out_4824996639199143778[0] = delta_x[0] + nom_x[0];
   out_4824996639199143778[1] = delta_x[1] + nom_x[1];
   out_4824996639199143778[2] = delta_x[2] + nom_x[2];
   out_4824996639199143778[3] = delta_x[3] + nom_x[3];
   out_4824996639199143778[4] = delta_x[4] + nom_x[4];
   out_4824996639199143778[5] = delta_x[5] + nom_x[5];
   out_4824996639199143778[6] = delta_x[6] + nom_x[6];
   out_4824996639199143778[7] = delta_x[7] + nom_x[7];
   out_4824996639199143778[8] = delta_x[8] + nom_x[8];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_4831584671806270183) {
   out_4831584671806270183[0] = -nom_x[0] + true_x[0];
   out_4831584671806270183[1] = -nom_x[1] + true_x[1];
   out_4831584671806270183[2] = -nom_x[2] + true_x[2];
   out_4831584671806270183[3] = -nom_x[3] + true_x[3];
   out_4831584671806270183[4] = -nom_x[4] + true_x[4];
   out_4831584671806270183[5] = -nom_x[5] + true_x[5];
   out_4831584671806270183[6] = -nom_x[6] + true_x[6];
   out_4831584671806270183[7] = -nom_x[7] + true_x[7];
   out_4831584671806270183[8] = -nom_x[8] + true_x[8];
}
void H_mod_fun(double *state, double *out_4591550234712496309) {
   out_4591550234712496309[0] = 1.0;
   out_4591550234712496309[1] = 0.0;
   out_4591550234712496309[2] = 0.0;
   out_4591550234712496309[3] = 0.0;
   out_4591550234712496309[4] = 0.0;
   out_4591550234712496309[5] = 0.0;
   out_4591550234712496309[6] = 0.0;
   out_4591550234712496309[7] = 0.0;
   out_4591550234712496309[8] = 0.0;
   out_4591550234712496309[9] = 0.0;
   out_4591550234712496309[10] = 1.0;
   out_4591550234712496309[11] = 0.0;
   out_4591550234712496309[12] = 0.0;
   out_4591550234712496309[13] = 0.0;
   out_4591550234712496309[14] = 0.0;
   out_4591550234712496309[15] = 0.0;
   out_4591550234712496309[16] = 0.0;
   out_4591550234712496309[17] = 0.0;
   out_4591550234712496309[18] = 0.0;
   out_4591550234712496309[19] = 0.0;
   out_4591550234712496309[20] = 1.0;
   out_4591550234712496309[21] = 0.0;
   out_4591550234712496309[22] = 0.0;
   out_4591550234712496309[23] = 0.0;
   out_4591550234712496309[24] = 0.0;
   out_4591550234712496309[25] = 0.0;
   out_4591550234712496309[26] = 0.0;
   out_4591550234712496309[27] = 0.0;
   out_4591550234712496309[28] = 0.0;
   out_4591550234712496309[29] = 0.0;
   out_4591550234712496309[30] = 1.0;
   out_4591550234712496309[31] = 0.0;
   out_4591550234712496309[32] = 0.0;
   out_4591550234712496309[33] = 0.0;
   out_4591550234712496309[34] = 0.0;
   out_4591550234712496309[35] = 0.0;
   out_4591550234712496309[36] = 0.0;
   out_4591550234712496309[37] = 0.0;
   out_4591550234712496309[38] = 0.0;
   out_4591550234712496309[39] = 0.0;
   out_4591550234712496309[40] = 1.0;
   out_4591550234712496309[41] = 0.0;
   out_4591550234712496309[42] = 0.0;
   out_4591550234712496309[43] = 0.0;
   out_4591550234712496309[44] = 0.0;
   out_4591550234712496309[45] = 0.0;
   out_4591550234712496309[46] = 0.0;
   out_4591550234712496309[47] = 0.0;
   out_4591550234712496309[48] = 0.0;
   out_4591550234712496309[49] = 0.0;
   out_4591550234712496309[50] = 1.0;
   out_4591550234712496309[51] = 0.0;
   out_4591550234712496309[52] = 0.0;
   out_4591550234712496309[53] = 0.0;
   out_4591550234712496309[54] = 0.0;
   out_4591550234712496309[55] = 0.0;
   out_4591550234712496309[56] = 0.0;
   out_4591550234712496309[57] = 0.0;
   out_4591550234712496309[58] = 0.0;
   out_4591550234712496309[59] = 0.0;
   out_4591550234712496309[60] = 1.0;
   out_4591550234712496309[61] = 0.0;
   out_4591550234712496309[62] = 0.0;
   out_4591550234712496309[63] = 0.0;
   out_4591550234712496309[64] = 0.0;
   out_4591550234712496309[65] = 0.0;
   out_4591550234712496309[66] = 0.0;
   out_4591550234712496309[67] = 0.0;
   out_4591550234712496309[68] = 0.0;
   out_4591550234712496309[69] = 0.0;
   out_4591550234712496309[70] = 1.0;
   out_4591550234712496309[71] = 0.0;
   out_4591550234712496309[72] = 0.0;
   out_4591550234712496309[73] = 0.0;
   out_4591550234712496309[74] = 0.0;
   out_4591550234712496309[75] = 0.0;
   out_4591550234712496309[76] = 0.0;
   out_4591550234712496309[77] = 0.0;
   out_4591550234712496309[78] = 0.0;
   out_4591550234712496309[79] = 0.0;
   out_4591550234712496309[80] = 1.0;
}
void f_fun(double *state, double dt, double *out_5844234740239095806) {
   out_5844234740239095806[0] = state[0];
   out_5844234740239095806[1] = state[1];
   out_5844234740239095806[2] = state[2];
   out_5844234740239095806[3] = state[3];
   out_5844234740239095806[4] = state[4];
   out_5844234740239095806[5] = dt*((-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]))*state[6] - 9.8100000000000005*state[8] + stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*state[1]) + (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*state[4])) + state[5];
   out_5844234740239095806[6] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*state[4])) + state[6];
   out_5844234740239095806[7] = state[7];
   out_5844234740239095806[8] = state[8];
}
void F_fun(double *state, double dt, double *out_237592563865845366) {
   out_237592563865845366[0] = 1;
   out_237592563865845366[1] = 0;
   out_237592563865845366[2] = 0;
   out_237592563865845366[3] = 0;
   out_237592563865845366[4] = 0;
   out_237592563865845366[5] = 0;
   out_237592563865845366[6] = 0;
   out_237592563865845366[7] = 0;
   out_237592563865845366[8] = 0;
   out_237592563865845366[9] = 0;
   out_237592563865845366[10] = 1;
   out_237592563865845366[11] = 0;
   out_237592563865845366[12] = 0;
   out_237592563865845366[13] = 0;
   out_237592563865845366[14] = 0;
   out_237592563865845366[15] = 0;
   out_237592563865845366[16] = 0;
   out_237592563865845366[17] = 0;
   out_237592563865845366[18] = 0;
   out_237592563865845366[19] = 0;
   out_237592563865845366[20] = 1;
   out_237592563865845366[21] = 0;
   out_237592563865845366[22] = 0;
   out_237592563865845366[23] = 0;
   out_237592563865845366[24] = 0;
   out_237592563865845366[25] = 0;
   out_237592563865845366[26] = 0;
   out_237592563865845366[27] = 0;
   out_237592563865845366[28] = 0;
   out_237592563865845366[29] = 0;
   out_237592563865845366[30] = 1;
   out_237592563865845366[31] = 0;
   out_237592563865845366[32] = 0;
   out_237592563865845366[33] = 0;
   out_237592563865845366[34] = 0;
   out_237592563865845366[35] = 0;
   out_237592563865845366[36] = 0;
   out_237592563865845366[37] = 0;
   out_237592563865845366[38] = 0;
   out_237592563865845366[39] = 0;
   out_237592563865845366[40] = 1;
   out_237592563865845366[41] = 0;
   out_237592563865845366[42] = 0;
   out_237592563865845366[43] = 0;
   out_237592563865845366[44] = 0;
   out_237592563865845366[45] = dt*(stiffness_front*(-state[2] - state[3] + state[7])/(mass*state[1]) + (-stiffness_front - stiffness_rear)*state[5]/(mass*state[4]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[6]/(mass*state[4]));
   out_237592563865845366[46] = -dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*pow(state[1], 2));
   out_237592563865845366[47] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_237592563865845366[48] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_237592563865845366[49] = dt*((-1 - (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*pow(state[4], 2)))*state[6] - (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*pow(state[4], 2)));
   out_237592563865845366[50] = dt*(-stiffness_front*state[0] - stiffness_rear*state[0])/(mass*state[4]) + 1;
   out_237592563865845366[51] = dt*(-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]));
   out_237592563865845366[52] = dt*stiffness_front*state[0]/(mass*state[1]);
   out_237592563865845366[53] = -9.8100000000000005*dt;
   out_237592563865845366[54] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front - pow(center_to_rear, 2)*stiffness_rear)*state[6]/(rotational_inertia*state[4]));
   out_237592563865845366[55] = -center_to_front*dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*pow(state[1], 2));
   out_237592563865845366[56] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_237592563865845366[57] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_237592563865845366[58] = dt*(-(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*pow(state[4], 2)) - (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*pow(state[4], 2)));
   out_237592563865845366[59] = dt*(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(rotational_inertia*state[4]);
   out_237592563865845366[60] = dt*(-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])/(rotational_inertia*state[4]) + 1;
   out_237592563865845366[61] = center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_237592563865845366[62] = 0;
   out_237592563865845366[63] = 0;
   out_237592563865845366[64] = 0;
   out_237592563865845366[65] = 0;
   out_237592563865845366[66] = 0;
   out_237592563865845366[67] = 0;
   out_237592563865845366[68] = 0;
   out_237592563865845366[69] = 0;
   out_237592563865845366[70] = 1;
   out_237592563865845366[71] = 0;
   out_237592563865845366[72] = 0;
   out_237592563865845366[73] = 0;
   out_237592563865845366[74] = 0;
   out_237592563865845366[75] = 0;
   out_237592563865845366[76] = 0;
   out_237592563865845366[77] = 0;
   out_237592563865845366[78] = 0;
   out_237592563865845366[79] = 0;
   out_237592563865845366[80] = 1;
}
void h_25(double *state, double *unused, double *out_1038933864410907054) {
   out_1038933864410907054[0] = state[6];
}
void H_25(double *state, double *unused, double *out_3825102472630289060) {
   out_3825102472630289060[0] = 0;
   out_3825102472630289060[1] = 0;
   out_3825102472630289060[2] = 0;
   out_3825102472630289060[3] = 0;
   out_3825102472630289060[4] = 0;
   out_3825102472630289060[5] = 0;
   out_3825102472630289060[6] = 1;
   out_3825102472630289060[7] = 0;
   out_3825102472630289060[8] = 0;
}
void h_24(double *state, double *unused, double *out_1496752080668854390) {
   out_1496752080668854390[0] = state[4];
   out_1496752080668854390[1] = state[5];
}
void H_24(double *state, double *unused, double *out_2375930207220872366) {
   out_2375930207220872366[0] = 0;
   out_2375930207220872366[1] = 0;
   out_2375930207220872366[2] = 0;
   out_2375930207220872366[3] = 0;
   out_2375930207220872366[4] = 1;
   out_2375930207220872366[5] = 0;
   out_2375930207220872366[6] = 0;
   out_2375930207220872366[7] = 0;
   out_2375930207220872366[8] = 0;
   out_2375930207220872366[9] = 0;
   out_2375930207220872366[10] = 0;
   out_2375930207220872366[11] = 0;
   out_2375930207220872366[12] = 0;
   out_2375930207220872366[13] = 0;
   out_2375930207220872366[14] = 1;
   out_2375930207220872366[15] = 0;
   out_2375930207220872366[16] = 0;
   out_2375930207220872366[17] = 0;
}
void h_30(double *state, double *unused, double *out_2489565257039790221) {
   out_2489565257039790221[0] = state[4];
}
void H_30(double *state, double *unused, double *out_702593857497319138) {
   out_702593857497319138[0] = 0;
   out_702593857497319138[1] = 0;
   out_702593857497319138[2] = 0;
   out_702593857497319138[3] = 0;
   out_702593857497319138[4] = 1;
   out_702593857497319138[5] = 0;
   out_702593857497319138[6] = 0;
   out_702593857497319138[7] = 0;
   out_702593857497319138[8] = 0;
}
void h_26(double *state, double *unused, double *out_7491238524700635866) {
   out_7491238524700635866[0] = state[7];
}
void H_26(double *state, double *unused, double *out_83599153756232836) {
   out_83599153756232836[0] = 0;
   out_83599153756232836[1] = 0;
   out_83599153756232836[2] = 0;
   out_83599153756232836[3] = 0;
   out_83599153756232836[4] = 0;
   out_83599153756232836[5] = 0;
   out_83599153756232836[6] = 0;
   out_83599153756232836[7] = 1;
   out_83599153756232836[8] = 0;
}
void h_27(double *state, double *unused, double *out_4027483654307435669) {
   out_4027483654307435669[0] = state[3];
}
void H_27(double *state, double *unused, double *out_1521000213686624079) {
   out_1521000213686624079[0] = 0;
   out_1521000213686624079[1] = 0;
   out_1521000213686624079[2] = 0;
   out_1521000213686624079[3] = 1;
   out_1521000213686624079[4] = 0;
   out_1521000213686624079[5] = 0;
   out_1521000213686624079[6] = 0;
   out_1521000213686624079[7] = 0;
   out_1521000213686624079[8] = 0;
}
void h_29(double *state, double *unused, double *out_3433075109941452656) {
   out_3433075109941452656[0] = state[1];
}
void H_29(double *state, double *unused, double *out_192362513182926954) {
   out_192362513182926954[0] = 0;
   out_192362513182926954[1] = 1;
   out_192362513182926954[2] = 0;
   out_192362513182926954[3] = 0;
   out_192362513182926954[4] = 0;
   out_192362513182926954[5] = 0;
   out_192362513182926954[6] = 0;
   out_192362513182926954[7] = 0;
   out_192362513182926954[8] = 0;
}
void h_28(double *state, double *unused, double *out_9029156921968281314) {
   out_9029156921968281314[0] = state[0];
}
void H_28(double *state, double *unused, double *out_5274761530252457528) {
   out_5274761530252457528[0] = 1;
   out_5274761530252457528[1] = 0;
   out_5274761530252457528[2] = 0;
   out_5274761530252457528[3] = 0;
   out_5274761530252457528[4] = 0;
   out_5274761530252457528[5] = 0;
   out_5274761530252457528[6] = 0;
   out_5274761530252457528[7] = 0;
   out_5274761530252457528[8] = 0;
}
void h_31(double *state, double *unused, double *out_213281758623064198) {
   out_213281758623064198[0] = state[8];
}
void H_31(double *state, double *unused, double *out_3855748434507249488) {
   out_3855748434507249488[0] = 0;
   out_3855748434507249488[1] = 0;
   out_3855748434507249488[2] = 0;
   out_3855748434507249488[3] = 0;
   out_3855748434507249488[4] = 0;
   out_3855748434507249488[5] = 0;
   out_3855748434507249488[6] = 0;
   out_3855748434507249488[7] = 0;
   out_3855748434507249488[8] = 1;
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
void car_err_fun(double *nom_x, double *delta_x, double *out_4824996639199143778) {
  err_fun(nom_x, delta_x, out_4824996639199143778);
}
void car_inv_err_fun(double *nom_x, double *true_x, double *out_4831584671806270183) {
  inv_err_fun(nom_x, true_x, out_4831584671806270183);
}
void car_H_mod_fun(double *state, double *out_4591550234712496309) {
  H_mod_fun(state, out_4591550234712496309);
}
void car_f_fun(double *state, double dt, double *out_5844234740239095806) {
  f_fun(state,  dt, out_5844234740239095806);
}
void car_F_fun(double *state, double dt, double *out_237592563865845366) {
  F_fun(state,  dt, out_237592563865845366);
}
void car_h_25(double *state, double *unused, double *out_1038933864410907054) {
  h_25(state, unused, out_1038933864410907054);
}
void car_H_25(double *state, double *unused, double *out_3825102472630289060) {
  H_25(state, unused, out_3825102472630289060);
}
void car_h_24(double *state, double *unused, double *out_1496752080668854390) {
  h_24(state, unused, out_1496752080668854390);
}
void car_H_24(double *state, double *unused, double *out_2375930207220872366) {
  H_24(state, unused, out_2375930207220872366);
}
void car_h_30(double *state, double *unused, double *out_2489565257039790221) {
  h_30(state, unused, out_2489565257039790221);
}
void car_H_30(double *state, double *unused, double *out_702593857497319138) {
  H_30(state, unused, out_702593857497319138);
}
void car_h_26(double *state, double *unused, double *out_7491238524700635866) {
  h_26(state, unused, out_7491238524700635866);
}
void car_H_26(double *state, double *unused, double *out_83599153756232836) {
  H_26(state, unused, out_83599153756232836);
}
void car_h_27(double *state, double *unused, double *out_4027483654307435669) {
  h_27(state, unused, out_4027483654307435669);
}
void car_H_27(double *state, double *unused, double *out_1521000213686624079) {
  H_27(state, unused, out_1521000213686624079);
}
void car_h_29(double *state, double *unused, double *out_3433075109941452656) {
  h_29(state, unused, out_3433075109941452656);
}
void car_H_29(double *state, double *unused, double *out_192362513182926954) {
  H_29(state, unused, out_192362513182926954);
}
void car_h_28(double *state, double *unused, double *out_9029156921968281314) {
  h_28(state, unused, out_9029156921968281314);
}
void car_H_28(double *state, double *unused, double *out_5274761530252457528) {
  H_28(state, unused, out_5274761530252457528);
}
void car_h_31(double *state, double *unused, double *out_213281758623064198) {
  h_31(state, unused, out_213281758623064198);
}
void car_H_31(double *state, double *unused, double *out_3855748434507249488) {
  H_31(state, unused, out_3855748434507249488);
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

ekf_lib_init(car)
