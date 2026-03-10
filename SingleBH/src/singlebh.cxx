#include <cctk.h>
#include <cctk_Arguments.h>
#include <cctk_Parameters.h>
#include <loop_device.hxx>

#include <cmath>

#include <util_powerinline.hxx>

namespace SingleBH {
using namespace Loop;
using namespace UtilForge;

CCTK_DEVICE CCTK_HOST constexpr CCTK_REAL Sqrt(CCTK_REAL x) {
  return std::sqrt(x);
}

extern "C" void Schwarzschild_InitialData(CCTK_ARGUMENTS) {
  DECLARE_CCTK_ARGUMENTSX_Schwarzschild_InitialData;
  DECLARE_CCTK_PARAMETERS;

  const auto rs = 2 * mass;

  grid.loop_all_device<0, 0, 0>(
      grid.nghostzones,
      [=] CCTK_DEVICE(const PointDesc &p) CCTK_ATTRIBUTE_ALWAYS_INLINE {
        const auto r = Sqrt(p.x * p.x + p.y * p.y + p.z * p.z);
        auto f = (r > rs) ? (1 - rs / r) : epsilon;
        const auto invf = 1.0 / f;

        alp(p.I) = Sqrt(f);
        betax(p.I) = 0.0;
        betay(p.I) = 0.0;
        betaz(p.I) = 0.0;
        gxx(p.I) = 1.0 + (invf - 1.0) * (p.x * p.x) / (r * r);
        gxy(p.I) = 0.0 + (invf - 1.0) * (p.x * p.y) / (r * r);
        gxz(p.I) = 0.0 + (invf - 1.0) * (p.x * p.z) / (r * r);
        gyy(p.I) = 1.0 + (invf - 1.0) * (p.y * p.y) / (r * r);
        gyz(p.I) = 0.0 + (invf - 1.0) * (p.y * p.z) / (r * r);
        gzz(p.I) = 1.0 + (invf - 1.0) * (p.z * p.z) / (r * r);
        kxx(p.I) = 0.0;
        kxy(p.I) = 0.0;
        kxz(p.I) = 0.0;
        kyy(p.I) = 0.0;
        kyz(p.I) = 0.0;
        kzz(p.I) = 0.0;
        dtalp(p.I) = 0.0;
        dtbetax(p.I) = 0.0;
        dtbetay(p.I) = 0.0;
        dtbetaz(p.I) = 0.0;
      });
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
