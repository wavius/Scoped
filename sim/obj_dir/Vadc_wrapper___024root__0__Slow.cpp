// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vadc_wrapper.h for the primary calling header

#include "Vadc_wrapper__pch.h"

VL_ATTR_COLD void Vadc_wrapper_utils_pkg___eval_static__TOP__utils_pkg(Vadc_wrapper_utils_pkg* vlSelf);
VL_ATTR_COLD void Vadc_wrapper___024root____Vm_traceActivitySetAll(Vadc_wrapper___024root* vlSelf);

VL_ATTR_COLD void Vadc_wrapper___024root___eval_static(Vadc_wrapper___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadc_wrapper___024root___eval_static\n"); );
    Vadc_wrapper__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vadc_wrapper_utils_pkg___eval_static__TOP__utils_pkg((&vlSymsp->TOP__utils_pkg));
    Vadc_wrapper___024root____Vm_traceActivitySetAll(vlSelf);
    vlSelfRef.__Vtrigprevexpr___TOP__adc_clk__0 = vlSelfRef.adc_clk;
    vlSelfRef.__Vtrigprevexpr___TOP__rst__0 = vlSelfRef.rst;
    vlSelfRef.__Vtrigprevexpr___TOP__ulpi_clk__0 = vlSelfRef.ulpi_clk;
    vlSelfRef.__Vtrigprevexpr___TOP__adc_wrapper__DOT__adc_rst_sync__0 
        = vlSelfRef.adc_wrapper__DOT__adc_rst_sync;
    vlSelfRef.__Vtrigprevexpr___TOP__adc_wrapper__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__wr_a_rst__0 
        = vlSelfRef.adc_wrapper__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__wr_a_rst;
    vlSelfRef.__Vtrigprevexpr___TOP__adc_wrapper__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__rd_a_rst__0 
        = vlSelfRef.adc_wrapper__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__rd_a_rst;
}

VL_ATTR_COLD void Vadc_wrapper___024root___eval_initial__TOP(Vadc_wrapper___024root* vlSelf);

VL_ATTR_COLD void Vadc_wrapper___024root___eval_initial(Vadc_wrapper___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadc_wrapper___024root___eval_initial\n"); );
    Vadc_wrapper__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vadc_wrapper___024root___eval_initial__TOP(vlSelf);
    Vadc_wrapper___024root____Vm_traceActivitySetAll(vlSelf);
}

VL_ATTR_COLD void Vadc_wrapper___024root___eval_initial__TOP(Vadc_wrapper___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadc_wrapper___024root___eval_initial__TOP\n"); );
    Vadc_wrapper__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSymsp->TOP__utils_pkg.gray2bin__Vstatic__i = 0x00000010U;
}

VL_ATTR_COLD void Vadc_wrapper___024root___eval_final(Vadc_wrapper___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadc_wrapper___024root___eval_final\n"); );
    Vadc_wrapper__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vadc_wrapper___024root___dump_triggers__stl(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG
VL_ATTR_COLD bool Vadc_wrapper___024root___eval_phase__stl(Vadc_wrapper___024root* vlSelf);

VL_ATTR_COLD void Vadc_wrapper___024root___eval_settle(Vadc_wrapper___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadc_wrapper___024root___eval_settle\n"); );
    Vadc_wrapper__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ __VstlIterCount;
    // Body
    __VstlIterCount = 0U;
    vlSelfRef.__VstlFirstIteration = 1U;
    do {
        if (VL_UNLIKELY(((0x00000064U < __VstlIterCount)))) {
#ifdef VL_DEBUG
            Vadc_wrapper___024root___dump_triggers__stl(vlSelfRef.__VstlTriggered, "stl"s);
#endif
            VL_FATAL_MT("../hdl/adc/adc_wrapper.sv", 1, "", "DIDNOTCONVERGE: Settle region did not converge after '--converge-limit' of 100 tries");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
        vlSelfRef.__VstlPhaseResult = Vadc_wrapper___024root___eval_phase__stl(vlSelf);
        vlSelfRef.__VstlFirstIteration = 0U;
    } while (vlSelfRef.__VstlPhaseResult);
}

VL_ATTR_COLD void Vadc_wrapper___024root___eval_triggers_vec__stl(Vadc_wrapper___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadc_wrapper___024root___eval_triggers_vec__stl\n"); );
    Vadc_wrapper__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VstlTriggered[0U] = ((0xfffffffffffffffeULL 
                                      & vlSelfRef.__VstlTriggered[0U]) 
                                     | (IData)((IData)(vlSelfRef.__VstlFirstIteration)));
}

VL_ATTR_COLD bool Vadc_wrapper___024root___trigger_anySet__stl(const VlUnpacked<QData/*63:0*/, 1> &in);

#ifdef VL_DEBUG
VL_ATTR_COLD void Vadc_wrapper___024root___dump_triggers__stl(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadc_wrapper___024root___dump_triggers__stl\n"); );
    // Body
    if ((1U & (~ (IData)(Vadc_wrapper___024root___trigger_anySet__stl(triggers))))) {
        VL_DBG_MSGS("         No '" + tag + "' region triggers active\n");
    }
    if ((1U & (IData)(triggers[0U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD bool Vadc_wrapper___024root___trigger_anySet__stl(const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadc_wrapper___024root___trigger_anySet__stl\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        if (in[n]) {
            return (1U);
        }
        n = ((IData)(1U) + n);
    } while ((1U > n));
    return (0U);
}

VL_ATTR_COLD void Vadc_wrapper___024root___stl_sequent__TOP__0(Vadc_wrapper___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadc_wrapper___024root___stl_sequent__TOP__0\n"); );
    Vadc_wrapper__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    SData/*14:0*/ __Vfunc_gray2bin__2__Vfuncout;
    __Vfunc_gray2bin__2__Vfuncout = 0;
    SData/*14:0*/ __Vfunc_gray2bin__2__gray;
    __Vfunc_gray2bin__2__gray = 0;
    SData/*14:0*/ __Vfunc_gray2bin__3__Vfuncout;
    __Vfunc_gray2bin__3__Vfuncout = 0;
    SData/*14:0*/ __Vfunc_gray2bin__3__gray;
    __Vfunc_gray2bin__3__gray = 0;
    // Body
    vlSelfRef.adc_wrapper__DOT__u_adc_int__DOT__adc_ready 
        = (0U == (IData)(vlSelfRef.adc_wrapper__DOT__u_adc_int__DOT__latency_counter));
    vlSelfRef.adc_wrapper__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__wr_ptr_gray 
        = ((IData)(vlSelfRef.adc_wrapper__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__wr_ptr) 
           ^ VL_SHIFTR_III(15,15,32, (IData)(vlSelfRef.adc_wrapper__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__wr_ptr), 1U));
    __Vfunc_gray2bin__3__gray = vlSelfRef.adc_wrapper__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__rd_ptr_gray_wr;
    vlSymsp->TOP__utils_pkg.gray2bin__Vstatic__b = __Vfunc_gray2bin__3__gray;
    vlSymsp->TOP__utils_pkg.gray2bin__Vstatic__b = 
        ((IData)(vlSymsp->TOP__utils_pkg.gray2bin__Vstatic__b) 
         ^ VL_SHIFTR_III(15,15,32, (IData)(vlSymsp->TOP__utils_pkg.gray2bin__Vstatic__b), 1U));
    vlSymsp->TOP__utils_pkg.gray2bin__Vstatic__b = 
        ((IData)(vlSymsp->TOP__utils_pkg.gray2bin__Vstatic__b) 
         ^ VL_SHIFTR_III(15,15,32, (IData)(vlSymsp->TOP__utils_pkg.gray2bin__Vstatic__b), 2U));
    vlSymsp->TOP__utils_pkg.gray2bin__Vstatic__b = 
        ((IData)(vlSymsp->TOP__utils_pkg.gray2bin__Vstatic__b) 
         ^ VL_SHIFTR_III(15,15,32, (IData)(vlSymsp->TOP__utils_pkg.gray2bin__Vstatic__b), 4U));
    vlSymsp->TOP__utils_pkg.gray2bin__Vstatic__b = 
        ((IData)(vlSymsp->TOP__utils_pkg.gray2bin__Vstatic__b) 
         ^ VL_SHIFTR_III(15,15,32, (IData)(vlSymsp->TOP__utils_pkg.gray2bin__Vstatic__b), 8U));
    __Vfunc_gray2bin__3__Vfuncout = vlSymsp->TOP__utils_pkg.gray2bin__Vstatic__b;
    vlSelfRef.adc_wrapper__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__rd_ptr_wr 
        = __Vfunc_gray2bin__3__Vfuncout;
    vlSelfRef.adc_wrapper__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__rd_ptr_gray 
        = ((IData)(vlSelfRef.adc_wrapper__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__rd_ptr) 
           ^ VL_SHIFTR_III(15,15,32, (IData)(vlSelfRef.adc_wrapper__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__rd_ptr), 1U));
    vlSelfRef.adc_wrapper__DOT__u_dc_fifo__DOT__rd_ena 
        = ((IData)(vlSelfRef.adc_wrapper__DOT__current_state) 
           & ((IData)(vlSelfRef.adc_wrapper__DOT__u_dc_fifo__DOT__data_out_valid) 
              & (IData)(vlSelfRef.tx_ready)));
    vlSelfRef.adc_wrapper__DOT__byte_sent = ((IData)(vlSelfRef.tx_ready) 
                                             & (IData)(vlSelfRef.tx_valid));
    __Vfunc_gray2bin__2__gray = vlSelfRef.adc_wrapper__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__wr_ptr_gray_rd;
    vlSymsp->TOP__utils_pkg.gray2bin__Vstatic__b = __Vfunc_gray2bin__2__gray;
    vlSymsp->TOP__utils_pkg.gray2bin__Vstatic__b = 
        ((IData)(vlSymsp->TOP__utils_pkg.gray2bin__Vstatic__b) 
         ^ VL_SHIFTR_III(15,15,32, (IData)(vlSymsp->TOP__utils_pkg.gray2bin__Vstatic__b), 1U));
    vlSymsp->TOP__utils_pkg.gray2bin__Vstatic__b = 
        ((IData)(vlSymsp->TOP__utils_pkg.gray2bin__Vstatic__b) 
         ^ VL_SHIFTR_III(15,15,32, (IData)(vlSymsp->TOP__utils_pkg.gray2bin__Vstatic__b), 2U));
    vlSymsp->TOP__utils_pkg.gray2bin__Vstatic__b = 
        ((IData)(vlSymsp->TOP__utils_pkg.gray2bin__Vstatic__b) 
         ^ VL_SHIFTR_III(15,15,32, (IData)(vlSymsp->TOP__utils_pkg.gray2bin__Vstatic__b), 4U));
    vlSymsp->TOP__utils_pkg.gray2bin__Vstatic__b = 
        ((IData)(vlSymsp->TOP__utils_pkg.gray2bin__Vstatic__b) 
         ^ VL_SHIFTR_III(15,15,32, (IData)(vlSymsp->TOP__utils_pkg.gray2bin__Vstatic__b), 8U));
    __Vfunc_gray2bin__2__Vfuncout = vlSymsp->TOP__utils_pkg.gray2bin__Vstatic__b;
    vlSelfRef.adc_wrapper__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__wr_ptr_rd 
        = __Vfunc_gray2bin__2__Vfuncout;
    vlSelfRef.adc_wrapper__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__u_dpdcram__DOT__wr_ena 
        = (((IData)(vlSelfRef.adc_wrapper__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__wr_ptr_gray) 
            != ((0x00006000U & ((~ ((IData)(vlSelfRef.adc_wrapper__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__rd_ptr_gray_wr) 
                                    >> 0x0000000dU)) 
                                << 0x0000000dU)) | 
                (0x00001fffU & (IData)(vlSelfRef.adc_wrapper__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__rd_ptr_gray_wr)))) 
           & (0U == (IData)(vlSelfRef.adc_wrapper__DOT__u_adc_int__DOT__latency_counter)));
    vlSelfRef.adc_wrapper__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__u_dpdcram__DOT__rd_ena 
        = (((IData)(vlSelfRef.adc_wrapper__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__rd_ptr_gray) 
            != (IData)(vlSelfRef.adc_wrapper__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__wr_ptr_gray_rd)) 
           & ((~ (IData)(vlSelfRef.adc_wrapper__DOT__u_dc_fifo__DOT__data_out_valid)) 
              | ((~ (IData)(vlSelfRef.adc_wrapper__DOT__u_dc_fifo__DOT__middle_valid)) 
                 | (IData)(vlSelfRef.adc_wrapper__DOT__u_dc_fifo__DOT__rd_ena))));
    if (vlSelfRef.adc_wrapper__DOT__current_state) {
        vlSelfRef.adc_wrapper__DOT__next_state = 1U;
        if (((0x01ffU == (IData)(vlSelfRef.adc_wrapper__DOT__burst_count)) 
             & (IData)(vlSelfRef.adc_wrapper__DOT__byte_sent))) {
            vlSelfRef.adc_wrapper__DOT__next_state = 0U;
        }
    } else {
        vlSelfRef.adc_wrapper__DOT__next_state = 0U;
        if ((0x01ffU <= (0x00007fffU & (((IData)(vlSelfRef.adc_wrapper__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__wr_ptr_rd) 
                                         - (IData)(vlSelfRef.adc_wrapper__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__rd_ptr)) 
                                        + ((IData)(vlSelfRef.adc_wrapper__DOT__u_dc_fifo__DOT__data_out_valid) 
                                           + ((IData)(vlSelfRef.adc_wrapper__DOT__u_dc_fifo__DOT__middle_valid) 
                                              + (IData)(vlSelfRef.adc_wrapper__DOT__u_dc_fifo__DOT__fall_through))))))) {
            vlSelfRef.adc_wrapper__DOT__next_state = 1U;
        }
    }
}

VL_ATTR_COLD void Vadc_wrapper___024root___eval_stl(Vadc_wrapper___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadc_wrapper___024root___eval_stl\n"); );
    Vadc_wrapper__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VstlTriggered[0U])) {
        Vadc_wrapper___024root___stl_sequent__TOP__0(vlSelf);
        Vadc_wrapper___024root____Vm_traceActivitySetAll(vlSelf);
    }
}

VL_ATTR_COLD bool Vadc_wrapper___024root___eval_phase__stl(Vadc_wrapper___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadc_wrapper___024root___eval_phase__stl\n"); );
    Vadc_wrapper__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VstlExecute;
    // Body
    Vadc_wrapper___024root___eval_triggers_vec__stl(vlSelf);
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vadc_wrapper___024root___dump_triggers__stl(vlSelfRef.__VstlTriggered, "stl"s);
    }
#endif
    __VstlExecute = Vadc_wrapper___024root___trigger_anySet__stl(vlSelfRef.__VstlTriggered);
    if (__VstlExecute) {
        Vadc_wrapper___024root___eval_stl(vlSelf);
    }
    return (__VstlExecute);
}

bool Vadc_wrapper___024root___trigger_anySet__ico(const VlUnpacked<QData/*63:0*/, 1> &in);

#ifdef VL_DEBUG
VL_ATTR_COLD void Vadc_wrapper___024root___dump_triggers__ico(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadc_wrapper___024root___dump_triggers__ico\n"); );
    // Body
    if ((1U & (~ (IData)(Vadc_wrapper___024root___trigger_anySet__ico(triggers))))) {
        VL_DBG_MSGS("         No '" + tag + "' region triggers active\n");
    }
    if ((1U & (IData)(triggers[0U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: Internal 'ico' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

bool Vadc_wrapper___024root___trigger_anySet__act(const VlUnpacked<QData/*63:0*/, 1> &in);

#ifdef VL_DEBUG
VL_ATTR_COLD void Vadc_wrapper___024root___dump_triggers__act(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadc_wrapper___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ (IData)(Vadc_wrapper___024root___trigger_anySet__act(triggers))))) {
        VL_DBG_MSGS("         No '" + tag + "' region triggers active\n");
    }
    if ((1U & (IData)(triggers[0U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: @(posedge adc_clk)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 1U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 1 is active: @(posedge rst)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 2U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 2 is active: @(posedge ulpi_clk)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 3U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 3 is active: @(posedge adc_wrapper.adc_rst_sync)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 4U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 4 is active: @(posedge adc_wrapper.u_dc_fifo.u_std_dc_fifo.wr_a_rst)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 5U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 5 is active: @(posedge adc_wrapper.u_dc_fifo.u_std_dc_fifo.rd_a_rst)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vadc_wrapper___024root____Vm_traceActivitySetAll(Vadc_wrapper___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadc_wrapper___024root____Vm_traceActivitySetAll\n"); );
    Vadc_wrapper__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vm_traceActivity[0U] = 1U;
    vlSelfRef.__Vm_traceActivity[1U] = 1U;
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.__Vm_traceActivity[3U] = 1U;
    vlSelfRef.__Vm_traceActivity[4U] = 1U;
    vlSelfRef.__Vm_traceActivity[5U] = 1U;
    vlSelfRef.__Vm_traceActivity[6U] = 1U;
}

VL_ATTR_COLD void Vadc_wrapper___024root___ctor_var_reset(Vadc_wrapper___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadc_wrapper___024root___ctor_var_reset\n"); );
    Vadc_wrapper__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const uint64_t __VscopeHash = VL_MURMUR64_HASH(vlSelf->vlNamep);
    vlSelf->rst = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 18209466448985614591ull);
    vlSelf->enable = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11030669854614834172ull);
    vlSelf->adc_clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12043924185765389916ull);
    vlSelf->adc_clk_out = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 233210214785442527ull);
    vlSelf->adc_data_raw = VL_SCOPED_RAND_RESET_I(12, __VscopeHash, 12200082996552574322ull);
    vlSelf->adc_otr = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7740951399803512364ull);
    vlSelf->ulpi_clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14263493562235327906ull);
    vlSelf->tx_ready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1719547800165390182ull);
    vlSelf->tx_data = VL_SCOPED_RAND_RESET_I(12, __VscopeHash, 14770307426006424685ull);
    vlSelf->tx_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16539308436166203032ull);
    vlSelf->adc_wrapper__DOT__adc_data = VL_SCOPED_RAND_RESET_I(12, __VscopeHash, 15634296808369375016ull);
    vlSelf->adc_wrapper__DOT__adc_rst_ms = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7123507903372985571ull);
    vlSelf->adc_wrapper__DOT__adc_rst_sync = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17330173587816429551ull);
    vlSelf->adc_wrapper__DOT__current_state = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 18405454226657261769ull);
    vlSelf->adc_wrapper__DOT__next_state = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9034900711375704523ull);
    vlSelf->adc_wrapper__DOT__burst_count = VL_SCOPED_RAND_RESET_I(10, __VscopeHash, 9942541121770495474ull);
    vlSelf->adc_wrapper__DOT__byte_sent = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17264199062930625713ull);
    vlSelf->adc_wrapper__DOT__u_adc_int__DOT__latency_counter = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 7063551610050467429ull);
    vlSelf->adc_wrapper__DOT__u_adc_int__DOT__adc_ready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6595907159893649761ull);
    vlSelf->adc_wrapper__DOT__u_dc_fifo__DOT__rd_ena = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2938980052301186545ull);
    vlSelf->adc_wrapper__DOT__u_dc_fifo__DOT__std_rd_data = VL_SCOPED_RAND_RESET_I(12, __VscopeHash, 15151316618444520874ull);
    vlSelf->adc_wrapper__DOT__u_dc_fifo__DOT__data_out_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4586640911221792749ull);
    vlSelf->adc_wrapper__DOT__u_dc_fifo__DOT__fall_through = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3924113233788984372ull);
    vlSelf->adc_wrapper__DOT__u_dc_fifo__DOT__middle_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8222432648659086157ull);
    vlSelf->adc_wrapper__DOT__u_dc_fifo__DOT__middle_data = VL_SCOPED_RAND_RESET_I(12, __VscopeHash, 8287143266888134907ull);
    vlSelf->adc_wrapper__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__wr_a_rst = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13806054706986084630ull);
    vlSelf->adc_wrapper__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__wr_a_rst_ms = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12403352563546829655ull);
    vlSelf->adc_wrapper__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__rd_a_rst = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12093686374545130043ull);
    vlSelf->adc_wrapper__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__rd_a_rst_ms = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5535528303800283204ull);
    vlSelf->adc_wrapper__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__wr_ptr = VL_SCOPED_RAND_RESET_I(15, __VscopeHash, 523339482611438484ull);
    vlSelf->adc_wrapper__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__wr_ptr_gray = VL_SCOPED_RAND_RESET_I(15, __VscopeHash, 13801523338750563736ull);
    vlSelf->adc_wrapper__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__wr_ptr_ms = VL_SCOPED_RAND_RESET_I(15, __VscopeHash, 16353870552332616292ull);
    vlSelf->adc_wrapper__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__wr_ptr_rd = VL_SCOPED_RAND_RESET_I(15, __VscopeHash, 5378072037304325049ull);
    vlSelf->adc_wrapper__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__wr_ptr_gray_rd = VL_SCOPED_RAND_RESET_I(15, __VscopeHash, 386218958757982648ull);
    vlSelf->adc_wrapper__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__rd_ptr = VL_SCOPED_RAND_RESET_I(15, __VscopeHash, 8295504060137196607ull);
    vlSelf->adc_wrapper__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__rd_ptr_gray = VL_SCOPED_RAND_RESET_I(15, __VscopeHash, 8261222638262592500ull);
    vlSelf->adc_wrapper__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__rd_ptr_ms = VL_SCOPED_RAND_RESET_I(15, __VscopeHash, 7828938490875460834ull);
    vlSelf->adc_wrapper__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__rd_ptr_wr = VL_SCOPED_RAND_RESET_I(15, __VscopeHash, 14359295268935093424ull);
    vlSelf->adc_wrapper__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__rd_ptr_gray_wr = VL_SCOPED_RAND_RESET_I(15, __VscopeHash, 818247480018202290ull);
    vlSelf->adc_wrapper__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__u_dpdcram__DOT__wr_ena = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 70126578562822654ull);
    vlSelf->adc_wrapper__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__u_dpdcram__DOT__rd_ena = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13103898303311714076ull);
    for (int __Vi0 = 0; __Vi0 < 16384; ++__Vi0) {
        vlSelf->adc_wrapper__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__u_dpdcram__DOT__mem[__Vi0] = VL_SCOPED_RAND_RESET_I(12, __VscopeHash, 2372525648469441993ull);
    }
    vlSelf->__Vdly__adc_wrapper__DOT__u_adc_int__DOT__latency_counter = 0;
    vlSelf->__Vdly__adc_wrapper__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__wr_ptr = 0;
    vlSelf->__Vdly__adc_wrapper__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__rd_ptr = 0;
    vlSelf->__VdlyVal__adc_wrapper__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__u_dpdcram__DOT__mem__v0 = 0;
    vlSelf->__VdlyDim0__adc_wrapper__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__u_dpdcram__DOT__mem__v0 = 0;
    vlSelf->__VdlySet__adc_wrapper__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__u_dpdcram__DOT__mem__v0 = 0;
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VstlTriggered[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VicoTriggered[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VactTriggered[__Vi0] = 0;
    }
    vlSelf->__Vtrigprevexpr___TOP__adc_clk__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__rst__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__ulpi_clk__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__adc_wrapper__DOT__adc_rst_sync__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__adc_wrapper__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__wr_a_rst__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__adc_wrapper__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__rd_a_rst__0 = 0;
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VnbaTriggered[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 7; ++__Vi0) {
        vlSelf->__Vm_traceActivity[__Vi0] = 0;
    }
}
