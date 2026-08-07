// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VADC_WRAPPER__SYMS_H_
#define VERILATED_VADC_WRAPPER__SYMS_H_  // guard

#include "verilated.h"

// INCLUDE MODEL CLASS

#include "Vadc_wrapper.h"

// INCLUDE MODULE CLASSES
#include "Vadc_wrapper___024root.h"
#include "Vadc_wrapper_utils_pkg.h"

// SYMS CLASS (contains all model state)
class alignas(VL_CACHE_LINE_BYTES) Vadc_wrapper__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    Vadc_wrapper* const __Vm_modelp;
    bool __Vm_activity = false;  ///< Used by trace routines to determine change occurred
    uint32_t __Vm_baseCode = 0;  ///< Used by trace routines when tracing multiple models
    VlDeleter __Vm_deleter;
    bool __Vm_didInit = false;

    // MODULE INSTANCE STATE
    Vadc_wrapper___024root         TOP;
    Vadc_wrapper_utils_pkg         TOP__utils_pkg;

    // CONSTRUCTORS
    Vadc_wrapper__Syms(VerilatedContext* contextp, const char* namep, Vadc_wrapper* modelp);
    ~Vadc_wrapper__Syms();

    // METHODS
    const char* name() const { return TOP.vlNamep; }
};

#endif  // guard
