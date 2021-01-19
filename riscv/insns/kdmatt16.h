require_rv64;
P_LOOP(32, {
  int32_t aop = P_SH(ps1, 1);
  int32_t bop = P_SH(ps2, 1);  
  int32_t mres;
  bool sat;

  if ((INT16_MIN != aop) | (INT16_MIN != bop)) {
    mres = aop * bop;
    mres <<= 1;
  } else {
    mres = INT32_MAX;
    P.VU.vxsat |= 1;
  }
  pd = (sat_add<int32_t, uint32_t>(pd, mres, sat));
  P.VU.vxsat |= sat;
})