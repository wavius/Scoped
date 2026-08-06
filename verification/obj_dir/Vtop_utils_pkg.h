// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtop.h for the primary calling header

#ifndef VERILATED_VTOP_UTILS_PKG_H_
#define VERILATED_VTOP_UTILS_PKG_H_  // guard

#include "verilated.h"


class Vtop__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vtop_utils_pkg final {
  public:

    // DESIGN SPECIFIC STATE
    SData/*14:0*/ gray2bin__Vstatic__b;
    IData/*31:0*/ gray2bin__Vstatic__i;

    // INTERNAL VARIABLES
    Vtop__Syms* vlSymsp;
    const char* vlNamep;

    // CONSTRUCTORS
    Vtop_utils_pkg();
    ~Vtop_utils_pkg();
    void ctor(Vtop__Syms* symsp, const char* namep);
    void dtor();
    VL_UNCOPYABLE(Vtop_utils_pkg);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
