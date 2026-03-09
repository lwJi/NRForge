#include <cctk.h>
#include <cctk_Arguments.h>
#include <cctk_Parameters.h>
#include <cx_utils.hxx>
#include <loop_device.hxx>

#include <cmath>

#include <cx_powerinline.hxx>

namespace KerrSchild {
using namespace Loop;
using namespace CXUtils;

extern "C" void KerrSchild_InitialData(CCTK_ARGUMENTS) {
  DECLARE_CCTK_ARGUMENTS_KerrSchild_InitialData;
  DECLARE_CCTK_PARAMETERS;

  const GF3D2layout layout2(cctkGH, {0, 0, 0});

  const array<CCTK_REAL *, 6> gf_ADMgam{gxx, gxy, gxz, gyy, gyz, gzz};
  const array<CCTK_REAL *, 6> gf_ADMK{kxx, kxy, kxz, kyy, kyz, kzz};
  CCTK_REAL *gf_ADMalpha = alp;
  const array<CCTK_REAL *, 3> gf_ADMbeta{betax, betay, betaz};

  CCTK_REAL *gf_dtADMalpha = dtalp;
  const array<CCTK_REAL *, 3> gf_ADMdtbeta{dtbetax, dtbetay, dtbetaz};

  const Loop::GridDescBaseDevice grid(cctkGH);

#include "../wolfram/kerrschild.hxx"
}

} // namespace KerrSchild
