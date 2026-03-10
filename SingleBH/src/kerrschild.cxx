#include <cctk.h>
#include <cctk_Arguments.h>
#include <cctk_Parameters.h>
#include <loop_device.hxx>

#include <cmath>

#include <cx_powerinline.hxx>

namespace SingleBH {
using namespace Loop;
using namespace CXUtils;

CCTK_DEVICE CCTK_HOST constexpr CCTK_REAL Sqrt(CCTK_REAL x) {
  return std::sqrt(x);
}

extern "C" void KerrSchild_InitialData(CCTK_ARGUMENTS) {
  DECLARE_CCTK_ARGUMENTS_KerrSchild_InitialData;
  DECLARE_CCTK_PARAMETERS;

  const GF3D2layout layout2(cctkGH, {0, 0, 0});

  const std::array<CCTK_REAL *, 6> gf_ADMgam{gxx, gxy, gxz, gyy, gyz, gzz};
  const std::array<CCTK_REAL *, 6> gf_ADMexK{kxx, kxy, kxz, kyy, kyz, kzz};
  CCTK_REAL *gf_ADMalpha = alp;
  const std::array<CCTK_REAL *, 3> gf_ADMbeta{betax, betay, betaz};

  CCTK_REAL *gf_ADMdtalpha = dtalp;
  const std::array<CCTK_REAL *, 3> gf_ADMdtbeta{dtbetax, dtbetay, dtbetaz};

  const Loop::GridDescBaseDevice grid(cctkGH);

#include "../wolfram/kerrschild.hxx"
}

} // namespace SingleBH
