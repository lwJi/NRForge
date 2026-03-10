(* ::Package:: *)

(* kerrschild.wl *)

(* (c) Liwei Ji, 03/2025 *)

(******************)
(* Configurations *)
(******************)

Needs["xAct`xCoba`", FileNameJoin[{Environment["GENERATO"], "src/Generato.wl"}]]

SetPVerbose[False];

SetPrintDate[False];

SetGridPointIndex["[[ijk]]"];

(*SetUseLetterForTensorComponet[True];*)

SetTempVariableType["auto"];

DefManifold[M3, 3, IndexRange[a, z]];

DefChart[cart, M3, {1, 2, 3}, {X[], Y[], Z[]}, ChartColor -> Blue];

(**********************************)
(* Define Variables and Equations *)
(**********************************)

Get[FileNameJoin[{Environment["GENERATO"], "module/ADM/ADM_var.wl"}]];

Get["wl/KerrSchild_var.wl"];

Get["wl/KerrSchild_rhs.wl"];

(******************)
(* Print to Files *)
(******************)

SetOutputFile[FileNameJoin[{Directory[], "kerrschild.hxx"}]];

SetMainPrint[
  (* Initialize grid function names *)
  PrintInitializations[{Mode -> "MainOut"}, ADMVarlist];
  PrintInitializations[{Mode -> "MainOut"}, ADMdtVarlist];
  pr[];

  (* Loops *)
  pr["noinline([&]() __attribute__((__flatten__, __hot__)) {"];
  pr["grid.loop_all_device<0, 0, 0>("];
  pr["  grid.nghostzones, [=] ARITH_DEVICE(const PointDesc &p) ARITH_INLINE {"];
  pr["const int ijk = layout2.linear(p.i, p.j, p.k);"];
  pr[];

  pr["const auto coX = p.x;"];
  pr["const auto coY = p.y;"];
  pr["const auto coZ = p.z;"];
  pr[];

  pr["const " <> GetTempVariableType[] <> " "];
  pr[ToString[rad[] // ToValues]];
  pr["= std::max(eps, "];
  PutAppend[CForm[rad$expl // ToValues], GetOutputFile[]];
  pr[");\n"];

  PrintEquations[{Mode -> "Temp", ExtraReplaceRules -> rad$rule}, KerrSchildTempVarlist[[2;;-1]]];
  pr[];

  PrintEquations[{Mode -> "MainOut"}, ADMVarlist];
  PrintEquations[{Mode -> "MainOut"}, ADMdtVarlist];
  pr[];

  pr["});"];
  pr["});"];
];

Import[FileNameJoin[{Environment["GENERATO"], "codes/CarpetXGPU.wl"}]];
