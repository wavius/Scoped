// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vadc_wrapper.h for the primary calling header

#include "Vadc_wrapper__pch.h"

void Vadc_wrapper___024root___ctor_var_reset(Vadc_wrapper___024root* vlSelf);

Vadc_wrapper___024root::Vadc_wrapper___024root(Vadc_wrapper__Syms* symsp, const char* namep)
 {
    vlSymsp = symsp;
    vlNamep = strdup(namep);
    // Reset structure values
    Vadc_wrapper___024root___ctor_var_reset(this);
}

void Vadc_wrapper___024root::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

Vadc_wrapper___024root::~Vadc_wrapper___024root() {
    VL_DO_DANGLING(std::free(const_cast<char*>(vlNamep)), vlNamep);
}
