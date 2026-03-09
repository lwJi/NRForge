/* kerrschild.hxx */
/* Produced with Generato */

#ifndef KERRSCHILD_HXX
#define KERRSCHILD_HXX

const auto ADMgam11 = gf_ADMgam[0];
const auto ADMgam12 = gf_ADMgam[1];
const auto ADMgam13 = gf_ADMgam[2];
const auto ADMgam22 = gf_ADMgam[3];
const auto ADMgam23 = gf_ADMgam[4];
const auto ADMgam33 = gf_ADMgam[5];
const auto ADMK11 = gf_ADMK[0];
const auto ADMK12 = gf_ADMK[1];
const auto ADMK13 = gf_ADMK[2];
const auto ADMK22 = gf_ADMK[3];
const auto ADMK23 = gf_ADMK[4];
const auto ADMK33 = gf_ADMK[5];
const auto ADMalpha = gf_ADMalpha;
const auto ADMbeta1 = gf_ADMbeta[0];
const auto ADMbeta2 = gf_ADMbeta[1];
const auto ADMbeta3 = gf_ADMbeta[2];
const auto ADMdtalpha = gf_ADMdtalpha;
const auto ADMdtbeta1 = gf_ADMdtbeta[0];
const auto ADMdtbeta2 = gf_ADMdtbeta[1];
const auto ADMdtbeta3 = gf_ADMdtbeta[2];

noinline([&]() __attribute__((__flatten__, __hot__)) {
grid.loop_all_device<0, 0, 0>(
  grid.nghostzones, [=] ARITH_DEVICE(const PointDesc &p) ARITH_INLINE {
const int ijk = layout2.linear(p.i, p.j, p.k);

const auto
rad
=
Sqrt(-Power(angv,2) + Power(coX,2) + Power(coY,2) + Power(coZ,2) +
    Sqrt(4*Power(angv,2)*Power(coZ,2) +
      Power(Power(angv,2) - Power(coX,2) - Power(coY,2) - Power(coZ,2),2)))/
  Sqrt(2)
;

const auto
drad1
=
(coX*Sqrt(-Power(angv,2) + Power(coX,2) + Power(coY,2) + Power(coZ,2) +
      Sqrt(4*Power(angv,2)*Power(coZ,2) +
        Power(-Power(angv,2) + Power(coX,2) + Power(coY,2) + Power(coZ,2),2)\
)))/(Sqrt(2)*Sqrt(4*Power(angv,2)*Power(coZ,2) +
      Power(-Power(angv,2) + Power(coX,2) + Power(coY,2) + Power(coZ,2),2)))
;

const auto
drad2
=
(coY*Sqrt(-Power(angv,2) + Power(coX,2) + Power(coY,2) + Power(coZ,2) +
      Sqrt(4*Power(angv,2)*Power(coZ,2) +
        Power(-Power(angv,2) + Power(coX,2) + Power(coY,2) + Power(coZ,2),2)\
)))/(Sqrt(2)*Sqrt(4*Power(angv,2)*Power(coZ,2) +
      Power(-Power(angv,2) + Power(coX,2) + Power(coY,2) + Power(coZ,2),2)))
;

const auto
drad3
=
(coZ*(1 + (Power(angv,2) + Power(coX,2) + Power(coY,2) + Power(coZ,2))/
       Sqrt(4*Power(angv,2)*Power(coZ,2) +
         Power(-Power(angv,2) + Power(coX,2) + Power(coY,2) + Power(coZ,2),
          2))))/
  (Sqrt(2)*Sqrt(-Power(angv,2) + Power(coX,2) + Power(coY,2) +
      Power(coZ,2) + Sqrt(4*Power(angv,2)*Power(coZ,2) +
        Power(-Power(angv,2) + Power(coX,2) + Power(coY,2) + Power(coZ,2),2))\
))
;

const auto
dbetaDD11
=
(2*mass*(Power(rad,4)*(Power(angv,2) + Power(rad,2))*
       (Power(angv,2)*Power(coZ,2) + Power(rad,4)) +
      drad1*Power(rad,2)*(3*Power(angv,5)*coY*Power(coZ,2) +
         4*Power(angv,4)*coX*Power(coZ,2)*rad +
         Power(angv,3)*coY*Power(coZ,2)*Power(rad,2) +
         2*Power(angv,2)*coX*Power(coZ,2)*Power(rad,3) -
         Power(angv,3)*coY*Power(rad,4) - 3*angv*coY*Power(rad,6) -
         2*coX*Power(rad,7))))/
  (Power(Power(angv,2) + Power(rad,2),2)*
    Power(Power(angv,2)*Power(coZ,2) + Power(rad,4),2))
;

const auto
dbetaDD12
=
(-2*mass*Power(rad,2)*(angv*rad*(Power(angv,2) + Power(rad,2))*
       (Power(angv,2)*Power(coZ,2) + Power(rad,4)) +
      drad1*(3*Power(angv,5)*coX*Power(coZ,2) -
         4*Power(angv,4)*coY*Power(coZ,2)*rad -
         2*Power(angv,2)*coY*Power(coZ,2)*Power(rad,3) -
         3*angv*coX*Power(rad,6) + 2*coY*Power(rad,7) +
         Power(angv,3)*coX*Power(rad,2)*(Power(coZ,2) - Power(rad,2)))))/
  (Power(Power(angv,2) + Power(rad,2),2)*
    Power(Power(angv,2)*Power(coZ,2) + Power(rad,4),2))
;

const auto
dbetaDD13
=
(4*coZ*drad1*mass*(Power(angv,2)*Power(coZ,2)*rad - Power(rad,5)))/
  Power(Power(angv,2)*Power(coZ,2) + Power(rad,4),2)
;

const auto
dbetaDD21
=
(2*mass*Power(rad,2)*(angv*rad*(Power(angv,2) + Power(rad,2))*
       (Power(angv,2)*Power(coZ,2) + Power(rad,4)) +
      drad2*(3*Power(angv,5)*coY*Power(coZ,2) +
         4*Power(angv,4)*coX*Power(coZ,2)*rad +
         Power(angv,3)*coY*Power(coZ,2)*Power(rad,2) +
         2*Power(angv,2)*coX*Power(coZ,2)*Power(rad,3) -
         Power(angv,3)*coY*Power(rad,4) - 3*angv*coY*Power(rad,6) -
         2*coX*Power(rad,7))))/
  (Power(Power(angv,2) + Power(rad,2),2)*
    Power(Power(angv,2)*Power(coZ,2) + Power(rad,4),2))
;

const auto
dbetaDD22
=
(2*mass*(Power(rad,4)*(Power(angv,2) + Power(rad,2))*
       (Power(angv,2)*Power(coZ,2) + Power(rad,4)) +
      drad2*Power(rad,2)*(-3*Power(angv,5)*coX*Power(coZ,2) +
         4*Power(angv,4)*coY*Power(coZ,2)*rad +
         2*Power(angv,2)*coY*Power(coZ,2)*Power(rad,3) +
         3*angv*coX*Power(rad,6) - 2*coY*Power(rad,7) +
         Power(angv,3)*coX*Power(rad,2)*(-Power(coZ,2) + Power(rad,2)))))/
  (Power(Power(angv,2) + Power(rad,2),2)*
    Power(Power(angv,2)*Power(coZ,2) + Power(rad,4),2))
;

const auto
dbetaDD23
=
(4*coZ*drad2*mass*(Power(angv,2)*Power(coZ,2)*rad - Power(rad,5)))/
  Power(Power(angv,2)*Power(coZ,2) + Power(rad,4),2)
;

const auto
dbetaDD31
=
(-2*mass*Power(rad,2)*(2*Power(angv,2)*coZ*rad*(angv*coY + coX*rad)*
       (Power(angv,2) + Power(rad,2)) +
      drad3*(-3*Power(angv,5)*coY*Power(coZ,2) -
         4*Power(angv,4)*coX*Power(coZ,2)*rad -
         Power(angv,3)*coY*Power(coZ,2)*Power(rad,2) -
         2*Power(angv,2)*coX*Power(coZ,2)*Power(rad,3) +
         Power(angv,3)*coY*Power(rad,4) + 3*angv*coY*Power(rad,6) +
         2*coX*Power(rad,7))))/
  (Power(Power(angv,2) + Power(rad,2),2)*
    Power(Power(angv,2)*Power(coZ,2) + Power(rad,4),2))
;

const auto
dbetaDD32
=
(2*mass*Power(rad,2)*(2*Power(angv,2)*coZ*rad*(angv*coX - coY*rad)*
       (Power(angv,2) + Power(rad,2)) +
      drad3*(-3*Power(angv,5)*coX*Power(coZ,2) +
         4*Power(angv,4)*coY*Power(coZ,2)*rad +
         2*Power(angv,2)*coY*Power(coZ,2)*Power(rad,3) +
         3*angv*coX*Power(rad,6) - 2*coY*Power(rad,7) +
         Power(angv,3)*coX*Power(rad,2)*(-Power(coZ,2) + Power(rad,2)))))/
  (Power(Power(angv,2) + Power(rad,2),2)*
    Power(Power(angv,2)*Power(coZ,2) + Power(rad,4),2))
;

const auto
dbetaDD33
=
(2*mass*rad*(-2*coZ*drad3 + rad)*
    (-(Power(angv,2)*Power(coZ,2)) + Power(rad,4)))/
  Power(Power(angv,2)*Power(coZ,2) + Power(rad,4),2)
;

const auto
dgamDDD111
=
(2*mass*(angv*coY + coX*rad)*(2*Power(rad,4)*
       (Power(angv,2) + Power(rad,2))*
       (Power(angv,2)*Power(coZ,2) + Power(rad,4)) +
      drad1*Power(rad,2)*(3*Power(angv,5)*coY*Power(coZ,2) +
         5*Power(angv,4)*coX*Power(coZ,2)*rad - 5*angv*coY*Power(rad,6) -
         3*coX*Power(rad,7) - Power(angv,3)*coY*Power(rad,2)*
          (Power(coZ,2) + Power(rad,2)) +
         Power(angv,2)*coX*Power(rad,3)*(Power(coZ,2) + Power(rad,2)))))/
  (Power(Power(angv,2) + Power(rad,2),3)*
    Power(Power(angv,2)*Power(coZ,2) + Power(rad,4),2))
;

const auto
dgamDDD112
=
(2*mass*Power(rad,2)*(rad*(Power(angv,2) + Power(rad,2))*
       (-(Power(angv,2)*coY) - 2*angv*coX*rad + coY*Power(rad,2))*
       (Power(angv,2)*Power(coZ,2) + Power(rad,4)) +
      drad1*(-3*Power(angv,6)*coX*coY*Power(coZ,2) +
         4*Power(angv,5)*(-Power(coX,2) + Power(coY,2))*Power(coZ,2)*rad +
         4*angv*(Power(coX,2) - Power(coY,2))*Power(rad,7) -
         3*coX*coY*Power(rad,8) +
         Power(angv,4)*coX*coY*Power(rad,2)*
          (6*Power(coZ,2) + Power(rad,2)) +
         Power(angv,2)*coX*coY*Power(rad,4)*(Power(coZ,2) + 6*Power(rad,2)))\
))/(Power(Power(angv,2) + Power(rad,2),3)*
    Power(Power(angv,2)*Power(coZ,2) + Power(rad,4),2))
;

const auto
dgamDDD113
=
(2*coZ*mass*(Power(rad,3)*(Power(angv,2) + Power(rad,2))*
       (Power(angv,2)*Power(coZ,2) + Power(rad,4)) +
      drad1*rad*(2*Power(angv,5)*coY*Power(coZ,2) +
         3*Power(angv,4)*coX*Power(coZ,2)*rad -
         2*Power(angv,3)*coY*Power(rad,4) - 4*angv*coY*Power(rad,6) -
         3*coX*Power(rad,7) + Power(angv,2)*coX*Power(rad,3)*
          (Power(coZ,2) - Power(rad,2)))))/
  (Power(Power(angv,2) + Power(rad,2),2)*
    Power(Power(angv,2)*Power(coZ,2) + Power(rad,4),2))
;

const auto
dgamDDD122
=
(2*mass*Power(rad,2)*(angv*coX - coY*rad)*
    (2*angv*rad*(Power(angv,2) + Power(rad,2))*
       (Power(angv,2)*Power(coZ,2) + Power(rad,4)) +
      drad1*(3*Power(angv,5)*coX*Power(coZ,2) -
         5*Power(angv,4)*coY*Power(coZ,2)*rad - 5*angv*coX*Power(rad,6) +
         3*coY*Power(rad,7) - Power(angv,3)*coX*Power(rad,2)*
          (Power(coZ,2) + Power(rad,2)) -
         Power(angv,2)*coY*Power(rad,3)*(Power(coZ,2) + Power(rad,2)))))/
  (Power(Power(angv,2) + Power(rad,2),3)*
    Power(Power(angv,2)*Power(coZ,2) + Power(rad,4),2))
;

const auto
dgamDDD123
=
(-2*coZ*mass*rad*(angv*rad*(Power(angv,2) + Power(rad,2))*
       (Power(angv,2)*Power(coZ,2) + Power(rad,4)) +
      drad1*(2*Power(angv,5)*coX*Power(coZ,2) -
         3*Power(angv,4)*coY*Power(coZ,2)*rad -
         2*Power(angv,3)*coX*Power(rad,4) - 4*angv*coX*Power(rad,6) +
         3*coY*Power(rad,7) + Power(angv,2)*coY*Power(rad,3)*
          (-Power(coZ,2) + Power(rad,2)))))/
  (Power(Power(angv,2) + Power(rad,2),2)*
    Power(Power(angv,2)*Power(coZ,2) + Power(rad,4),2))
;

const auto
dgamDDD133
=
(2*Power(coZ,2)*drad1*mass*(Power(angv,2)*Power(coZ,2) - 3*Power(rad,4)))/
  Power(Power(angv,2)*Power(coZ,2) + Power(rad,4),2)
;

const auto
dgamDDD211
=
(2*mass*Power(rad,2)*(angv*coY + coX*rad)*
    (2*angv*rad*(Power(angv,2) + Power(rad,2))*
       (Power(angv,2)*Power(coZ,2) + Power(rad,4)) +
      drad2*(3*Power(angv,5)*coY*Power(coZ,2) +
         5*Power(angv,4)*coX*Power(coZ,2)*rad - 5*angv*coY*Power(rad,6) -
         3*coX*Power(rad,7) - Power(angv,3)*coY*Power(rad,2)*
          (Power(coZ,2) + Power(rad,2)) +
         Power(angv,2)*coX*Power(rad,3)*(Power(coZ,2) + Power(rad,2)))))/
  (Power(Power(angv,2) + Power(rad,2),3)*
    Power(Power(angv,2)*Power(coZ,2) + Power(rad,4),2))
;

const auto
dgamDDD212
=
(2*mass*Power(rad,2)*(rad*(Power(angv,2) + Power(rad,2))*
       (-(Power(angv,2)*coX) + 2*angv*coY*rad + coX*Power(rad,2))*
       (Power(angv,2)*Power(coZ,2) + Power(rad,4)) +
      drad2*(-3*Power(angv,6)*coX*coY*Power(coZ,2) +
         4*Power(angv,5)*(-Power(coX,2) + Power(coY,2))*Power(coZ,2)*rad +
         4*angv*(Power(coX,2) - Power(coY,2))*Power(rad,7) -
         3*coX*coY*Power(rad,8) +
         Power(angv,4)*coX*coY*Power(rad,2)*
          (6*Power(coZ,2) + Power(rad,2)) +
         Power(angv,2)*coX*coY*Power(rad,4)*(Power(coZ,2) + 6*Power(rad,2)))\
))/(Power(Power(angv,2) + Power(rad,2),3)*
    Power(Power(angv,2)*Power(coZ,2) + Power(rad,4),2))
;

const auto
dgamDDD213
=
(2*coZ*mass*rad*(angv*rad*(Power(angv,2) + Power(rad,2))*
       (Power(angv,2)*Power(coZ,2) + Power(rad,4)) +
      drad2*(2*Power(angv,5)*coY*Power(coZ,2) +
         3*Power(angv,4)*coX*Power(coZ,2)*rad -
         2*Power(angv,3)*coY*Power(rad,4) - 4*angv*coY*Power(rad,6) -
         3*coX*Power(rad,7) + Power(angv,2)*coX*Power(rad,3)*
          (Power(coZ,2) - Power(rad,2)))))/
  (Power(Power(angv,2) + Power(rad,2),2)*
    Power(Power(angv,2)*Power(coZ,2) + Power(rad,4),2))
;

const auto
dgamDDD222
=
(2*mass*(-(angv*coX) + coY*rad)*
    (2*Power(rad,4)*(Power(angv,2) + Power(rad,2))*
       (Power(angv,2)*Power(coZ,2) + Power(rad,4)) +
      drad2*Power(rad,2)*(-3*Power(angv,5)*coX*Power(coZ,2) +
         5*Power(angv,4)*coY*Power(coZ,2)*rad + 5*angv*coX*Power(rad,6) -
         3*coY*Power(rad,7) + Power(angv,3)*coX*Power(rad,2)*
          (Power(coZ,2) + Power(rad,2)) +
         Power(angv,2)*coY*Power(rad,3)*(Power(coZ,2) + Power(rad,2)))))/
  (Power(Power(angv,2) + Power(rad,2),3)*
    Power(Power(angv,2)*Power(coZ,2) + Power(rad,4),2))
;

const auto
dgamDDD223
=
(2*coZ*mass*(Power(rad,3)*(Power(angv,2) + Power(rad,2))*
       (Power(angv,2)*Power(coZ,2) + Power(rad,4)) +
      drad2*rad*(-2*Power(angv,5)*coX*Power(coZ,2) +
         3*Power(angv,4)*coY*Power(coZ,2)*rad +
         2*Power(angv,3)*coX*Power(rad,4) + 4*angv*coX*Power(rad,6) -
         3*coY*Power(rad,7) + Power(angv,2)*coY*Power(rad,3)*
          (Power(coZ,2) - Power(rad,2)))))/
  (Power(Power(angv,2) + Power(rad,2),2)*
    Power(Power(angv,2)*Power(coZ,2) + Power(rad,4),2))
;

const auto
dgamDDD233
=
(2*Power(coZ,2)*drad2*mass*(Power(angv,2)*Power(coZ,2) - 3*Power(rad,4)))/
  Power(Power(angv,2)*Power(coZ,2) + Power(rad,4),2)
;

const auto
dgamDDD311
=
(-2*mass*Power(rad,2)*(angv*coY + coX*rad)*
    (2*Power(angv,2)*coZ*rad*(angv*coY + coX*rad)*
       (Power(angv,2) + Power(rad,2)) +
      drad3*(-3*Power(angv,5)*coY*Power(coZ,2) -
         5*Power(angv,4)*coX*Power(coZ,2)*rad + 5*angv*coY*Power(rad,6) +
         3*coX*Power(rad,7) + Power(angv,3)*coY*Power(rad,2)*
          (Power(coZ,2) + Power(rad,2)) -
         Power(angv,2)*coX*Power(rad,3)*(Power(coZ,2) + Power(rad,2)))))/
  (Power(Power(angv,2) + Power(rad,2),3)*
    Power(Power(angv,2)*Power(coZ,2) + Power(rad,4),2))
;

const auto
dgamDDD312
=
(2*mass*Power(rad,2)*(2*Power(angv,2)*coZ*rad*
       (Power(angv,2) + Power(rad,2))*
       (Power(angv,2)*coX*coY + angv*(Power(coX,2) - Power(coY,2))*rad -
         coX*coY*Power(rad,2)) +
      drad3*(-3*Power(angv,6)*coX*coY*Power(coZ,2) +
         4*Power(angv,5)*(-Power(coX,2) + Power(coY,2))*Power(coZ,2)*rad +
         4*angv*(Power(coX,2) - Power(coY,2))*Power(rad,7) -
         3*coX*coY*Power(rad,8) +
         Power(angv,4)*coX*coY*Power(rad,2)*
          (6*Power(coZ,2) + Power(rad,2)) +
         Power(angv,2)*coX*coY*Power(rad,4)*(Power(coZ,2) + 6*Power(rad,2)))\
))/(Power(Power(angv,2) + Power(rad,2),3)*
    Power(Power(angv,2)*Power(coZ,2) + Power(rad,4),2))
;

const auto
dgamDDD313
=
(2*mass*rad*(rad*(angv*coY + coX*rad)*(Power(angv,2) + Power(rad,2))*
       (-(Power(angv,2)*Power(coZ,2)) + Power(rad,4)) +
      coZ*drad3*(2*Power(angv,5)*coY*Power(coZ,2) +
         3*Power(angv,4)*coX*Power(coZ,2)*rad -
         2*Power(angv,3)*coY*Power(rad,4) - 4*angv*coY*Power(rad,6) -
         3*coX*Power(rad,7) + Power(angv,2)*coX*Power(rad,3)*
          (Power(coZ,2) - Power(rad,2)))))/
  (Power(Power(angv,2) + Power(rad,2),2)*
    Power(Power(angv,2)*Power(coZ,2) + Power(rad,4),2))
;

const auto
dgamDDD322
=
(-2*mass*Power(rad,2)*(angv*coX - coY*rad)*
    (2*Power(angv,2)*coZ*rad*(angv*coX - coY*rad)*
       (Power(angv,2) + Power(rad,2)) +
      drad3*(-3*Power(angv,5)*coX*Power(coZ,2) +
         5*Power(angv,4)*coY*Power(coZ,2)*rad + 5*angv*coX*Power(rad,6) -
         3*coY*Power(rad,7) + Power(angv,3)*coX*Power(rad,2)*
          (Power(coZ,2) + Power(rad,2)) +
         Power(angv,2)*coY*Power(rad,3)*(Power(coZ,2) + Power(rad,2)))))/
  (Power(Power(angv,2) + Power(rad,2),3)*
    Power(Power(angv,2)*Power(coZ,2) + Power(rad,4),2))
;

const auto
dgamDDD323
=
(2*mass*rad*(rad*(-(angv*coX) + coY*rad)*(Power(angv,2) + Power(rad,2))*
       (-(Power(angv,2)*Power(coZ,2)) + Power(rad,4)) +
      coZ*drad3*(-2*Power(angv,5)*coX*Power(coZ,2) +
         3*Power(angv,4)*coY*Power(coZ,2)*rad +
         2*Power(angv,3)*coX*Power(rad,4) + 4*angv*coX*Power(rad,6) -
         3*coY*Power(rad,7) + Power(angv,2)*coY*Power(rad,3)*
          (Power(coZ,2) - Power(rad,2)))))/
  (Power(Power(angv,2) + Power(rad,2),2)*
    Power(Power(angv,2)*Power(coZ,2) + Power(rad,4),2))
;

const auto
dgamDDD333
=
(2*coZ*mass*(2*Power(rad,5) + drad3*
       (Power(angv,2)*Power(coZ,3) - 3*coZ*Power(rad,4))))/
  Power(Power(angv,2)*Power(coZ,2) + Power(rad,4),2)
;

const auto
gam11
=
1 + (2*mass*Power(rad,3)*Power(angv*coY + coX*rad,2))/
   (Power(Power(angv,2) + Power(rad,2),2)*
     (Power(angv,2)*Power(coZ,2) + Power(rad,4)))
;

const auto
gam12
=
(2*mass*Power(rad,3)*(angv*coY + coX*rad)*(-(angv*coX) + coY*rad))/
  (Power(Power(angv,2) + Power(rad,2),2)*
    (Power(angv,2)*Power(coZ,2) + Power(rad,4)))
;

const auto
gam13
=
(2*coZ*mass*Power(rad,2)*(angv*coY + coX*rad))/
  ((Power(angv,2) + Power(rad,2))*
    (Power(angv,2)*Power(coZ,2) + Power(rad,4)))
;

const auto
gam22
=
1 + (2*mass*Power(rad,3)*Power(angv*coX - coY*rad,2))/
   (Power(Power(angv,2) + Power(rad,2),2)*
     (Power(angv,2)*Power(coZ,2) + Power(rad,4)))
;

const auto
gam23
=
(2*coZ*mass*Power(rad,2)*(-(angv*coX) + coY*rad))/
  ((Power(angv,2) + Power(rad,2))*
    (Power(angv,2)*Power(coZ,2) + Power(rad,4)))
;

const auto
gam33
=
1 + (2*Power(coZ,2)*mass*rad)/(Power(angv,2)*Power(coZ,2) + Power(rad,4))
;

const auto
detinvgam
=
1/(-(Power(gam13,2)*gam22) + 2*gam12*gam13*gam23 - gam11*Power(gam23,2) -
    Power(gam12,2)*gam33 + gam11*gam22*gam33)
;

const auto
invgam11
=
detinvgam*(-Power(gam23,2) + gam22*gam33)
;

const auto
invgam12
=
detinvgam*(gam13*gam23 - gam12*gam33)
;

const auto
invgam13
=
detinvgam*(-(gam13*gam22) + gam12*gam23)
;

const auto
invgam22
=
detinvgam*(-Power(gam13,2) + gam11*gam33)
;

const auto
invgam23
=
detinvgam*(gam12*gam13 - gam11*gam23)
;

const auto
invgam33
=
detinvgam*(-Power(gam12,2) + gam11*gam22)
;

const auto
betaD1
=
(2*mass*Power(rad,3)*(angv*coY + coX*rad))/
  ((Power(angv,2) + Power(rad,2))*
    (Power(angv,2)*Power(coZ,2) + Power(rad,4)))
;

const auto
betaD2
=
(2*mass*Power(rad,3)*(-(angv*coX) + coY*rad))/
  ((Power(angv,2) + Power(rad,2))*
    (Power(angv,2)*Power(coZ,2) + Power(rad,4)))
;

const auto
betaD3
=
(2*coZ*mass*Power(rad,2))/(Power(angv,2)*Power(coZ,2) + Power(rad,4))
;

const auto
beta1
=
betaD1*invgam11 + betaD2*invgam12 + betaD3*invgam13
;

const auto
beta2
=
betaD1*invgam12 + betaD2*invgam22 + betaD3*invgam23
;

const auto
beta3
=
betaD1*invgam13 + betaD2*invgam23 + betaD3*invgam33
;

const auto
alpha
=
1/Sqrt(1 + (2*mass*Power(rad,3))/(Power(angv,2)*Power(coZ,2) + Power(rad,4)))
;

const auto
Gambeta11
=
(beta1*dgamDDD111 + 2*beta2*dgamDDD112 + 2*beta3*dgamDDD113 -
    beta2*dgamDDD211 - beta3*dgamDDD311)/2.
;

const auto
Gambeta12
=
(beta2*dgamDDD122 + beta1*dgamDDD211 +
    beta3*(dgamDDD123 + dgamDDD213 - dgamDDD312))/2.
;

const auto
Gambeta13
=
(beta3*dgamDDD133 + beta1*dgamDDD311 +
    beta2*(dgamDDD123 - dgamDDD213 + dgamDDD312))/2.
;

const auto
Gambeta22
=
(-(beta1*dgamDDD122) + 2*beta1*dgamDDD212 + beta2*dgamDDD222 +
    2*beta3*dgamDDD223 - beta3*dgamDDD322)/2.
;

const auto
Gambeta23
=
(beta3*dgamDDD233 + beta1*(-dgamDDD123 + dgamDDD213 + dgamDDD312) +
    beta2*dgamDDD322)/2.
;

const auto
Gambeta33
=
(-(beta1*dgamDDD133) - beta2*dgamDDD233 + 2*beta1*dgamDDD313 +
    2*beta2*dgamDDD323 + beta3*dgamDDD333)/2.
;


ADMgam11[ijk]
=
gam11
;

ADMgam12[ijk]
=
gam12
;

ADMgam13[ijk]
=
gam13
;

ADMgam22[ijk]
=
gam22
;

ADMgam23[ijk]
=
gam23
;

ADMgam33[ijk]
=
gam33
;

ADMK11[ijk]
=
(dbetaDD11 - Gambeta11)/alpha
;

ADMK12[ijk]
=
(dbetaDD12 + dbetaDD21 - 2*Gambeta12)/(2.*alpha)
;

ADMK13[ijk]
=
(dbetaDD13 + dbetaDD31 - 2*Gambeta13)/(2.*alpha)
;

ADMK22[ijk]
=
(dbetaDD22 - Gambeta22)/alpha
;

ADMK23[ijk]
=
(dbetaDD23 + dbetaDD32 - 2*Gambeta23)/(2.*alpha)
;

ADMK33[ijk]
=
(dbetaDD33 - Gambeta33)/alpha
;

ADMalpha[ijk]
=
alpha
;

ADMbeta1[ijk]
=
beta1
;

ADMbeta2[ijk]
=
beta2
;

ADMbeta3[ijk]
=
beta3
;

ADMdtalpha[ijk]
=
0
;

ADMdtbeta1[ijk]
=
0
;

ADMdtbeta2[ijk]
=
0
;

ADMdtbeta3[ijk]
=
0
;


});
});

#endif // #ifndef KERRSCHILD_HXX

/* kerrschild.hxx */
