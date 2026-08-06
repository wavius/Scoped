// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"

void Vtop_utils_pkg___ctor_var_reset(Vtop_utils_pkg* vlSelf);

Vtop_utils_pkg::Vtop_utils_pkg() = default;
Vtop_utils_pkg::~Vtop_utils_pkg() = default;

void Vtop_utils_pkg::ctor(Vtop__Syms* symsp, const char* namep) {
    vlSymsp = symsp;
    vlNamep = strdup(Verilated::catName(vlSymsp->name(), namep));
    // Reset structure values
    Vtop_utils_pkg___ctor_var_reset(this);
}

void Vtop_utils_pkg::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

void Vtop_utils_pkg::dtor() {
    VL_DO_DANGLING(std::free(const_cast<char*>(vlNamep)), vlNamep);
}
