(* ::Package:: *)

(* KerrSchild_var.wl *)

(* (c) Liwei Ji, 03/2026 *)

(************************)

(* KerrSchild Variables *)

(************************)

KerrSchildAuxVarlist =
  DefTensors[
    {KSrad[], PrintAs -> "R"},
    {KSk0 [], PrintAs -> "\!\(\*SubscriptBox[\(k\), \(0\)]\)"},
    {KSk[-i], PrintAs -> "k"},
    {KSf[], PrintAs -> "f"},
    {KSalpha [], PrintAs -> "\[Alpha]"},
    {KSgam[-i, -j], Symmetric[{-i, -j}], PrintAs -> "\[Gamma]"},
    {KSbeta[-i], PrintAs -> "\[Beta]"}
  ];

KerrSchildTempVarlist =
  TempTensors[
    {rad[], PrintAs -> "R"},
    {drad[-i], PrintAs -> "\[PartialD]R"},
    {dbetaDD[-k, -i], PrintAs -> "\[PartialD]\[Beta]"},
    {dgamDDD[-k, -i, -j], Symmetric[{-i, -j}], PrintAs -> "\[PartialD]\[Gamma]"},
    {gam[-i, -j], Symmetric[{-i, -j}], PrintAs -> "\[Gamma]"},
    {detinvgam[], PrintAs -> "1/\[Gamma]"},
    {invgam[i, j], Symmetric[{i, j}], PrintAs -> "\[Gamma]"},
    {betaD[-i], PrintAs -> "\[Beta]"},
    {beta  [i], PrintAs -> "\[Beta]"},
    {alpha  [], PrintAs -> "\[Alpha]"},
    {Gambeta[-i, -j], Symmetric[{-i, -j}], PrintAs -> "\[CapitalGamma]\[Beta]"}
  ];
