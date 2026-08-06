// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vadc_wrapper.h for the primary calling header

#include "Vadc_wrapper__pch.h"

void Vadc_wrapper_utils_pkg___ctor_var_reset(Vadc_wrapper_utils_pkg* vlSelf);

Vadc_wrapper_utils_pkg::Vadc_wrapper_utils_pkg() = default;
Vadc_wrapper_utils_pkg::~Vadc_wrapper_utils_pkg() = default;

void Vadc_wrapper_utils_pkg::ctor(Vadc_wrapper__Syms* symsp, const char* namep) {
    vlSymsp = symsp;
    vlNamep = strdup(Verilated::catName(vlSymsp->name(), namep));
    // Reset structure values
    Vadc_wrapper_utils_pkg___ctor_var_reset(this);
}

void Vadc_wrapper_utils_pkg::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

void Vadc_wrapper_utils_pkg::dtor() {
    VL_DO_DANGLING(std::free(const_cast<char*>(vlNamep)), vlNamep);
}
