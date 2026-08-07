// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vadc_wrapper.h for the primary calling header

#ifndef VERILATED_VADC_WRAPPER_UTILS_PKG_H_
#define VERILATED_VADC_WRAPPER_UTILS_PKG_H_  // guard

#include "verilated.h"


class Vadc_wrapper__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vadc_wrapper_utils_pkg final {
  public:

    // DESIGN SPECIFIC STATE
    SData/*14:0*/ gray2bin__Vstatic__b;
    IData/*31:0*/ gray2bin__Vstatic__i;

    // INTERNAL VARIABLES
    Vadc_wrapper__Syms* vlSymsp;
    const char* vlNamep;

    // CONSTRUCTORS
    Vadc_wrapper_utils_pkg();
    ~Vadc_wrapper_utils_pkg();
    void ctor(Vadc_wrapper__Syms* symsp, const char* namep);
    void dtor();
    VL_UNCOPYABLE(Vadc_wrapper_utils_pkg);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
