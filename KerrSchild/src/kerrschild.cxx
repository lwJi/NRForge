#include <cctk.h>
#include <cctk_Arguments.h>
#include <cctk_Parameters.h>
#include <loop_device.hxx>
#include <cx_utils.hxx>

#include <cmath>

#include <cx_derivsGF3D5.hxx>
#include <cx_derivsinline.hxx>
#include <cx_dissinline.hxx>
#include <cx_powerinline.hxx>

namespace KerrSchild {
using namespace Loop;
using namespace CXUtils;

extern "C" void KerrSchild_InitialData(CCTK_ARGUMENTS) {
  DECLARE_CCTK_ARGUMENTS_KerrSchild_InitialData;
  DECLARE_CCTK_PARAMETERS;

  const Loop::GridDescBaseDevice grid(cctkGH);

  grid.loop_all_device<0, 0, 0>(
      grid.nghostzones,
      [=] CCTK_DEVICE(const Loop::PointDesc &p) CCTK_ATTRIBUTE_ALWAYS_INLINE {

#include "../wolfram/kerrschild.hxx"

      });
}

} // namespace KerrSchild
