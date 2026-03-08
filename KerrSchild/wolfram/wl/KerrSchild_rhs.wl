(* ::Package:: *)

(* KerrSchild_rhs.wl *)

(* (c) Liwei Ji, 03/2026 *)

(*****************)

(* BH Parameters *)

(*****************)

DefConstantSymbol[angv, PrintAs -> "a"];

DefConstantSymbol[mass, PrintAs -> "M"];

DefScalarFunction[radi, PrintAs -> "r"];

(***********************)

(* Auxiliary Variables *)

(***********************)

ComponentValue[KSk0[], 1];

ComponentValue[KSk[{1, -GetDefaultChart[]}], (KSr[] X[] + angv Y[]) / (KSr[] ^ 2 + angv^2)];

ComponentValue[KSk[{2, -GetDefaultChart[]}], (KSr[] Y[] - angv X[]) / (KSr[] ^ 2 + angv^2)];

ComponentValue[KSk[{3, -GetDefaultChart[]}], Z[] / KSr[]];

ComponentValue[KSf[], KSr[] ^ 2 / (KSr[] ^ 4 + angv^2 Z[] ^ 2) 2 mass KSr[]];

ComponentValue[KSalpha[], (1 + (2 mass KSr[] ^ 3) / (KSr[] ^ 4 + angv^2 Z[] ^ 2)) ^ (-1/2)];

Do[ComponentValue[KSgam[{ii, -GetDefaultChart[]}, {jj, -GetDefaultChart[]}], KroneckerDelta[ii, jj] + KSf[] KSk[{ii, -GetDefaultChart[]}] KSk[{jj, -GetDefaultChart[]}] // ToValues], {ii, 1, 3}, {jj, 1, 3}];

Do[ComponentValue[KSbeta[{ii, -GetDefaultChart[]}], KSf[] KSk0[] KSk[{ii, -GetDefaultChart[]}] // ToValues], {ii, 1, 3}];

(***********************)

(* Temporary Variables *)

(***********************)

SetEQNDelayed[gam[i_, j_], KSgam[i, j]];

Module[{Mat, invMat},
  Mat = Table[gam[{ii, -GetDefaultChart[]}, {jj, -GetDefaultChart[]}] // ToValues, {ii, 1, 3}, {jj, 1, 3}];
  invMat = Inverse[Mat] /. {1 / Det[Mat] -> detinvgam};
  SetEQNDelayed[detinvgam[], 1 / Det[Mat] // Simplify];
  SetEQNDelayed[invgam[i_, j_], invMat[[i[[1]], j[[1]]]] // Simplify];
];

SetEQNDelayed[betaD[i_], KSbeta[i] // ToValues];

SetEQNDelayed[beta[i_], invgam[i, j] betaD[-j]];

SetEQNDelayed[alpha[], KSalpha[] // ToValues];

SetEQNDelayed[dbetaDD[k_, i_], PDOfBasis[GetDefaultChart[]][k][KSbeta[i] // ToValues]];

SetEQNDelayed[dgamDDD[k_, i_, j_], PDOfBasis[GetDefaultChart[]][k][KSgam[i, j] // ToValues]];

SetEQNDelayed[Gambeta[i_, j_], 1/2 beta[l] (dgamDDD[i, j, -l] + dgamDDD[j, -l, i] - dgamDDD[-l, i, j])];

(*****************)

(* ADM Variables *)

(*****************)

SetEQN[ADMgam[i_, j_], gam[i, j]];

SetEQN[ADMbeta[i_], beta[i]];

SetEQN[ADMalpha[], alpha[]];

SetEQN[ADMK[i_, j_], (dbetaDD[i, j] + dbetaDD[j, i] - 2 Gambeta[i, j]) / (2 alpha[])];
