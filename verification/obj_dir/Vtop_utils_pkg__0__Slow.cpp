// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"

VL_ATTR_COLD void Vtop_utils_pkg___eval_static__TOP__utils_pkg(Vtop_utils_pkg* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vtop_utils_pkg___eval_static__TOP__utils_pkg\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const uint64_t __VscopeHash = VL_MURMUR64_HASH(vlSelf->vlNamep);
    vlSelf->gray2bin__Vstatic__i = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 4209404268432718606ull);
    vlSelf->gray2bin__Vstatic__b = VL_SCOPED_RAND_RESET_I(15, __VscopeHash, 2037203565062515158ull);
}

VL_ATTR_COLD void Vtop_utils_pkg___ctor_var_reset(Vtop_utils_pkg* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vtop_utils_pkg___ctor_var_reset\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}
