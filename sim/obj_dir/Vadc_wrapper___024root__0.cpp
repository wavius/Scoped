// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vadc_wrapper.h for the primary calling header

#include "Vadc_wrapper__pch.h"

void Vadc_wrapper___024root___eval_triggers_vec__ico(Vadc_wrapper___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadc_wrapper___024root___eval_triggers_vec__ico\n"); );
    Vadc_wrapper__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VicoTriggered[0U] = ((0xfffffffffffffffeULL 
                                      & vlSelfRef.__VicoTriggered[0U]) 
                                     | (IData)((IData)(vlSelfRef.__VicoFirstIteration)));
}

bool Vadc_wrapper___024root___trigger_anySet__ico(const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadc_wrapper___024root___trigger_anySet__ico\n"); );
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

void Vadc_wrapper___024root___ico_sequent__TOP__0(Vadc_wrapper___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadc_wrapper___024root___ico_sequent__TOP__0\n"); );
    Vadc_wrapper__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.adc_wrapper__DOT__u_dc_fifo__DOT__rd_ena 
        = ((IData)(vlSelfRef.adc_wrapper__DOT__current_state) 
           & ((IData)(vlSelfRef.adc_wrapper__DOT__u_dc_fifo__DOT__data_out_valid) 
              & (IData)(vlSelfRef.tx_ready)));
    vlSelfRef.adc_wrapper__DOT__byte_sent = ((IData)(vlSelfRef.tx_ready) 
                                             & (IData)(vlSelfRef.tx_valid));
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

void Vadc_wrapper___024root___eval_ico(Vadc_wrapper___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadc_wrapper___024root___eval_ico\n"); );
    Vadc_wrapper__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VicoTriggered[0U])) {
        Vadc_wrapper___024root___ico_sequent__TOP__0(vlSelf);
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vadc_wrapper___024root___dump_triggers__ico(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG

bool Vadc_wrapper___024root___eval_phase__ico(Vadc_wrapper___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadc_wrapper___024root___eval_phase__ico\n"); );
    Vadc_wrapper__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VicoExecute;
    // Body
    Vadc_wrapper___024root___eval_triggers_vec__ico(vlSelf);
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vadc_wrapper___024root___dump_triggers__ico(vlSelfRef.__VicoTriggered, "ico"s);
    }
#endif
    __VicoExecute = Vadc_wrapper___024root___trigger_anySet__ico(vlSelfRef.__VicoTriggered);
    if (__VicoExecute) {
        Vadc_wrapper___024root___eval_ico(vlSelf);
    }
    return (__VicoExecute);
}

void Vadc_wrapper___024root___eval_triggers_vec__act(Vadc_wrapper___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadc_wrapper___024root___eval_triggers_vec__act\n"); );
    Vadc_wrapper__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VactTriggered[0U] = (QData)((IData)(
                                                    (((((IData)(vlSelfRef.adc_wrapper__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__rd_a_rst) 
                                                        & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__adc_wrapper__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__rd_a_rst__0))) 
                                                       << 5U) 
                                                      | (((IData)(vlSelfRef.adc_wrapper__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__wr_a_rst) 
                                                          & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__adc_wrapper__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__wr_a_rst__0))) 
                                                         << 4U)) 
                                                     | (((((IData)(vlSelfRef.adc_wrapper__DOT__adc_rst_sync) 
                                                           & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__adc_wrapper__DOT__adc_rst_sync__0))) 
                                                          << 3U) 
                                                         | (((IData)(vlSelfRef.ulpi_clk) 
                                                             & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__ulpi_clk__0))) 
                                                            << 2U)) 
                                                        | ((((IData)(vlSelfRef.rst) 
                                                             & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__rst__0))) 
                                                            << 1U) 
                                                           | ((IData)(vlSelfRef.adc_clk) 
                                                              & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__adc_clk__0))))))));
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

bool Vadc_wrapper___024root___trigger_anySet__act(const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadc_wrapper___024root___trigger_anySet__act\n"); );
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

void Vadc_wrapper___024root___nba_sequent__TOP__0(Vadc_wrapper___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadc_wrapper___024root___nba_sequent__TOP__0\n"); );
    Vadc_wrapper__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vdly__adc_wrapper__DOT__u_adc_int__DOT__latency_counter 
        = vlSelfRef.adc_wrapper__DOT__u_adc_int__DOT__latency_counter;
    vlSelfRef.__Vdly__adc_wrapper__DOT__u_adc_int__DOT__latency_counter 
        = ((IData)(vlSelfRef.adc_wrapper__DOT__adc_rst_sync)
            ? 7U : ((IData)(vlSelfRef.adc_wrapper__DOT__u_adc_int__DOT__adc_ready)
                     ? 0U : (7U & ((IData)(vlSelfRef.adc_wrapper__DOT__u_adc_int__DOT__latency_counter) 
                                   - (IData)(1U)))));
    vlSelfRef.adc_clk_out = (1U & (~ (IData)(vlSelfRef.adc_wrapper__DOT__adc_rst_sync)));
}

void Vadc_wrapper___024root___nba_sequent__TOP__1(Vadc_wrapper___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadc_wrapper___024root___nba_sequent__TOP__1\n"); );
    Vadc_wrapper__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vdly__adc_wrapper__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__wr_ptr 
        = vlSelfRef.adc_wrapper__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__wr_ptr;
    if (vlSelfRef.adc_wrapper__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__wr_a_rst) {
        vlSelfRef.__Vdly__adc_wrapper__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__wr_ptr = 0U;
    } else if (vlSelfRef.adc_wrapper__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__u_dpdcram__DOT__wr_ena) {
        vlSelfRef.__Vdly__adc_wrapper__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__wr_ptr 
            = (0x00007fffU & ((IData)(1U) + (IData)(vlSelfRef.adc_wrapper__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__wr_ptr)));
    }
}

void Vadc_wrapper___024root___nba_sequent__TOP__2(Vadc_wrapper___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadc_wrapper___024root___nba_sequent__TOP__2\n"); );
    Vadc_wrapper__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vdly__adc_wrapper__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__rd_ptr 
        = vlSelfRef.adc_wrapper__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__rd_ptr;
    if (vlSelfRef.adc_wrapper__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__rd_a_rst) {
        vlSelfRef.__Vdly__adc_wrapper__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__rd_ptr = 0U;
    } else if (vlSelfRef.adc_wrapper__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__u_dpdcram__DOT__rd_ena) {
        vlSelfRef.__Vdly__adc_wrapper__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__rd_ptr 
            = (0x00007fffU & ((IData)(1U) + (IData)(vlSelfRef.adc_wrapper__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__rd_ptr)));
    }
}

void Vadc_wrapper___024root___nba_sequent__TOP__3(Vadc_wrapper___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadc_wrapper___024root___nba_sequent__TOP__3\n"); );
    Vadc_wrapper__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    SData/*14:0*/ __Vfunc_gray2bin__3__Vfuncout;
    __Vfunc_gray2bin__3__Vfuncout = 0;
    SData/*14:0*/ __Vfunc_gray2bin__3__gray;
    __Vfunc_gray2bin__3__gray = 0;
    // Body
    vlSelfRef.__VdlySet__adc_wrapper__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__u_dpdcram__DOT__mem__v0 = 0U;
    if (vlSelfRef.adc_wrapper__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__u_dpdcram__DOT__wr_ena) {
        vlSelfRef.__VdlyVal__adc_wrapper__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__u_dpdcram__DOT__mem__v0 
            = vlSelfRef.adc_wrapper__DOT__adc_data;
        vlSelfRef.__VdlyDim0__adc_wrapper__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__u_dpdcram__DOT__mem__v0 
            = (0x00003fffU & (IData)(vlSelfRef.adc_wrapper__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__wr_ptr));
        vlSelfRef.__VdlySet__adc_wrapper__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__u_dpdcram__DOT__mem__v0 = 1U;
    }
    vlSelfRef.adc_wrapper__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__rd_ptr_gray_wr 
        = vlSelfRef.adc_wrapper__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__rd_ptr_ms;
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
    vlSelfRef.adc_wrapper__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__rd_ptr_ms 
        = vlSelfRef.adc_wrapper__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__rd_ptr_gray;
}

void Vadc_wrapper___024root___nba_sequent__TOP__4(Vadc_wrapper___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadc_wrapper___024root___nba_sequent__TOP__4\n"); );
    Vadc_wrapper__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    SData/*9:0*/ __Vdly__adc_wrapper__DOT__burst_count;
    __Vdly__adc_wrapper__DOT__burst_count = 0;
    CData/*0:0*/ __Vdly__adc_wrapper__DOT__u_dc_fifo__DOT__data_out_valid;
    __Vdly__adc_wrapper__DOT__u_dc_fifo__DOT__data_out_valid = 0;
    CData/*0:0*/ __Vdly__adc_wrapper__DOT__u_dc_fifo__DOT__middle_valid;
    __Vdly__adc_wrapper__DOT__u_dc_fifo__DOT__middle_valid = 0;
    SData/*11:0*/ __Vdly__adc_wrapper__DOT__u_dc_fifo__DOT__middle_data;
    __Vdly__adc_wrapper__DOT__u_dc_fifo__DOT__middle_data = 0;
    // Body
    __Vdly__adc_wrapper__DOT__burst_count = vlSelfRef.adc_wrapper__DOT__burst_count;
    __Vdly__adc_wrapper__DOT__u_dc_fifo__DOT__middle_data 
        = vlSelfRef.adc_wrapper__DOT__u_dc_fifo__DOT__middle_data;
    __Vdly__adc_wrapper__DOT__u_dc_fifo__DOT__middle_valid 
        = vlSelfRef.adc_wrapper__DOT__u_dc_fifo__DOT__middle_valid;
    __Vdly__adc_wrapper__DOT__u_dc_fifo__DOT__data_out_valid 
        = vlSelfRef.adc_wrapper__DOT__u_dc_fifo__DOT__data_out_valid;
    if (vlSelfRef.rst) {
        __Vdly__adc_wrapper__DOT__burst_count = 0U;
        vlSelfRef.tx_valid = 0U;
        __Vdly__adc_wrapper__DOT__u_dc_fifo__DOT__data_out_valid = 0U;
        __Vdly__adc_wrapper__DOT__u_dc_fifo__DOT__middle_valid = 0U;
        vlSelfRef.tx_data = 0U;
        __Vdly__adc_wrapper__DOT__u_dc_fifo__DOT__middle_data = 0U;
    } else {
        if (vlSelfRef.enable) {
            if (vlSelfRef.adc_wrapper__DOT__current_state) {
                if (vlSelfRef.adc_wrapper__DOT__byte_sent) {
                    __Vdly__adc_wrapper__DOT__burst_count 
                        = (0x000003ffU & ((IData)(1U) 
                                          + (IData)(vlSelfRef.adc_wrapper__DOT__burst_count)));
                }
                vlSelfRef.tx_valid = ((IData)(vlSelfRef.adc_wrapper__DOT__next_state) 
                                      && ((IData)(vlSelfRef.adc_wrapper__DOT__u_dc_fifo__DOT__data_out_valid) 
                                          & (IData)(vlSelfRef.enable)));
            } else {
                __Vdly__adc_wrapper__DOT__burst_count = 0U;
                vlSelfRef.tx_valid = 0U;
            }
        } else {
            __Vdly__adc_wrapper__DOT__burst_count = 0U;
            vlSelfRef.tx_valid = 0U;
        }
        if (((IData)(vlSelfRef.adc_wrapper__DOT__u_dc_fifo__DOT__rd_ena) 
             & (IData)(vlSelfRef.adc_wrapper__DOT__u_dc_fifo__DOT__data_out_valid))) {
            if (vlSelfRef.adc_wrapper__DOT__u_dc_fifo__DOT__middle_valid) {
                vlSelfRef.tx_data = vlSelfRef.adc_wrapper__DOT__u_dc_fifo__DOT__middle_data;
                __Vdly__adc_wrapper__DOT__u_dc_fifo__DOT__middle_valid = 0U;
                __Vdly__adc_wrapper__DOT__u_dc_fifo__DOT__data_out_valid = 1U;
                if (vlSelfRef.adc_wrapper__DOT__u_dc_fifo__DOT__fall_through) {
                    __Vdly__adc_wrapper__DOT__u_dc_fifo__DOT__middle_data 
                        = vlSelfRef.adc_wrapper__DOT__u_dc_fifo__DOT__std_rd_data;
                    __Vdly__adc_wrapper__DOT__u_dc_fifo__DOT__middle_valid = 1U;
                }
            } else if (vlSelfRef.adc_wrapper__DOT__u_dc_fifo__DOT__fall_through) {
                vlSelfRef.tx_data = vlSelfRef.adc_wrapper__DOT__u_dc_fifo__DOT__std_rd_data;
                __Vdly__adc_wrapper__DOT__u_dc_fifo__DOT__data_out_valid = 1U;
            } else {
                __Vdly__adc_wrapper__DOT__u_dc_fifo__DOT__data_out_valid = 0U;
            }
        } else if (((~ (IData)(vlSelfRef.adc_wrapper__DOT__u_dc_fifo__DOT__data_out_valid)) 
                    & (IData)(vlSelfRef.adc_wrapper__DOT__u_dc_fifo__DOT__fall_through))) {
            vlSelfRef.tx_data = vlSelfRef.adc_wrapper__DOT__u_dc_fifo__DOT__std_rd_data;
            __Vdly__adc_wrapper__DOT__u_dc_fifo__DOT__data_out_valid = 1U;
        } else if ((((IData)(vlSelfRef.adc_wrapper__DOT__u_dc_fifo__DOT__data_out_valid) 
                     & (IData)(vlSelfRef.adc_wrapper__DOT__u_dc_fifo__DOT__fall_through)) 
                    & (~ (IData)(vlSelfRef.adc_wrapper__DOT__u_dc_fifo__DOT__middle_valid)))) {
            __Vdly__adc_wrapper__DOT__u_dc_fifo__DOT__middle_data 
                = vlSelfRef.adc_wrapper__DOT__u_dc_fifo__DOT__std_rd_data;
            __Vdly__adc_wrapper__DOT__u_dc_fifo__DOT__middle_valid = 1U;
        }
    }
    vlSelfRef.adc_wrapper__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__rd_a_rst 
        = ((IData)(vlSelfRef.rst) || (IData)(vlSelfRef.adc_wrapper__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__rd_a_rst_ms));
    vlSelfRef.adc_wrapper__DOT__burst_count = __Vdly__adc_wrapper__DOT__burst_count;
    vlSelfRef.adc_wrapper__DOT__u_dc_fifo__DOT__middle_data 
        = __Vdly__adc_wrapper__DOT__u_dc_fifo__DOT__middle_data;
    vlSelfRef.adc_wrapper__DOT__u_dc_fifo__DOT__middle_valid 
        = __Vdly__adc_wrapper__DOT__u_dc_fifo__DOT__middle_valid;
    vlSelfRef.adc_wrapper__DOT__u_dc_fifo__DOT__data_out_valid 
        = __Vdly__adc_wrapper__DOT__u_dc_fifo__DOT__data_out_valid;
    vlSelfRef.adc_wrapper__DOT__byte_sent = ((IData)(vlSelfRef.tx_ready) 
                                             & (IData)(vlSelfRef.tx_valid));
    vlSelfRef.adc_wrapper__DOT__current_state = ((1U 
                                                  & (~ (IData)(vlSelfRef.rst))) 
                                                 && ((IData)(vlSelfRef.enable) 
                                                     && (IData)(vlSelfRef.adc_wrapper__DOT__next_state)));
    vlSelfRef.adc_wrapper__DOT__u_dc_fifo__DOT__fall_through 
        = ((1U & (~ (IData)(vlSelfRef.rst))) && (IData)(vlSelfRef.adc_wrapper__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__u_dpdcram__DOT__rd_ena));
    vlSelfRef.adc_wrapper__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__rd_a_rst_ms 
        = vlSelfRef.rst;
    vlSelfRef.adc_wrapper__DOT__u_dc_fifo__DOT__rd_ena 
        = ((IData)(vlSelfRef.adc_wrapper__DOT__current_state) 
           & ((IData)(vlSelfRef.adc_wrapper__DOT__u_dc_fifo__DOT__data_out_valid) 
              & (IData)(vlSelfRef.tx_ready)));
}

void Vadc_wrapper___024root___nba_sequent__TOP__5(Vadc_wrapper___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadc_wrapper___024root___nba_sequent__TOP__5\n"); );
    Vadc_wrapper__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    SData/*14:0*/ __Vfunc_gray2bin__2__Vfuncout;
    __Vfunc_gray2bin__2__Vfuncout = 0;
    SData/*14:0*/ __Vfunc_gray2bin__2__gray;
    __Vfunc_gray2bin__2__gray = 0;
    // Body
    vlSelfRef.adc_wrapper__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__wr_ptr_gray_rd 
        = vlSelfRef.adc_wrapper__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__wr_ptr_ms;
    if (vlSelfRef.adc_wrapper__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__u_dpdcram__DOT__rd_ena) {
        vlSelfRef.adc_wrapper__DOT__u_dc_fifo__DOT__std_rd_data 
            = vlSelfRef.adc_wrapper__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__u_dpdcram__DOT__mem
            [(0x00003fffU & (IData)(vlSelfRef.adc_wrapper__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__rd_ptr))];
    }
    vlSelfRef.adc_wrapper__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__wr_ptr_ms 
        = vlSelfRef.adc_wrapper__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__wr_ptr_gray;
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
}

void Vadc_wrapper___024root___nba_sequent__TOP__6(Vadc_wrapper___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadc_wrapper___024root___nba_sequent__TOP__6\n"); );
    Vadc_wrapper__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.adc_wrapper__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__wr_a_rst 
        = ((IData)(vlSelfRef.rst) || (IData)(vlSelfRef.adc_wrapper__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__wr_a_rst_ms));
    vlSelfRef.adc_wrapper__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__wr_a_rst_ms 
        = vlSelfRef.rst;
}

void Vadc_wrapper___024root___nba_sequent__TOP__7(Vadc_wrapper___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadc_wrapper___024root___nba_sequent__TOP__7\n"); );
    Vadc_wrapper__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.adc_wrapper__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__wr_ptr 
        = vlSelfRef.__Vdly__adc_wrapper__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__wr_ptr;
    vlSelfRef.adc_wrapper__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__wr_ptr_gray 
        = ((IData)(vlSelfRef.adc_wrapper__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__wr_ptr) 
           ^ VL_SHIFTR_III(15,15,32, (IData)(vlSelfRef.adc_wrapper__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__wr_ptr), 1U));
}

void Vadc_wrapper___024root___nba_sequent__TOP__8(Vadc_wrapper___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadc_wrapper___024root___nba_sequent__TOP__8\n"); );
    Vadc_wrapper__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.adc_wrapper__DOT__adc_data = ((IData)(vlSelfRef.adc_wrapper__DOT__adc_rst_sync)
                                             ? 0U : 
                                            ((0U == (IData)(vlSelfRef.adc_wrapper__DOT__u_adc_int__DOT__latency_counter))
                                              ? (IData)(vlSelfRef.adc_data_raw)
                                              : 0U));
    vlSelfRef.adc_wrapper__DOT__u_adc_int__DOT__latency_counter 
        = vlSelfRef.__Vdly__adc_wrapper__DOT__u_adc_int__DOT__latency_counter;
    vlSelfRef.adc_wrapper__DOT__u_adc_int__DOT__adc_ready 
        = (0U == (IData)(vlSelfRef.adc_wrapper__DOT__u_adc_int__DOT__latency_counter));
}

void Vadc_wrapper___024root___nba_sequent__TOP__9(Vadc_wrapper___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadc_wrapper___024root___nba_sequent__TOP__9\n"); );
    Vadc_wrapper__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSelfRef.__VdlySet__adc_wrapper__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__u_dpdcram__DOT__mem__v0) {
        vlSelfRef.adc_wrapper__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__u_dpdcram__DOT__mem[vlSelfRef.__VdlyDim0__adc_wrapper__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__u_dpdcram__DOT__mem__v0] 
            = vlSelfRef.__VdlyVal__adc_wrapper__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__u_dpdcram__DOT__mem__v0;
    }
}

void Vadc_wrapper___024root___nba_sequent__TOP__10(Vadc_wrapper___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadc_wrapper___024root___nba_sequent__TOP__10\n"); );
    Vadc_wrapper__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.adc_wrapper__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__rd_ptr 
        = vlSelfRef.__Vdly__adc_wrapper__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__rd_ptr;
    vlSelfRef.adc_wrapper__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__rd_ptr_gray 
        = ((IData)(vlSelfRef.adc_wrapper__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__rd_ptr) 
           ^ VL_SHIFTR_III(15,15,32, (IData)(vlSelfRef.adc_wrapper__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__rd_ptr), 1U));
}

void Vadc_wrapper___024root___nba_sequent__TOP__11(Vadc_wrapper___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadc_wrapper___024root___nba_sequent__TOP__11\n"); );
    Vadc_wrapper__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.adc_wrapper__DOT__adc_rst_sync = ((IData)(vlSelfRef.rst) 
                                                || (IData)(vlSelfRef.adc_wrapper__DOT__adc_rst_ms));
    vlSelfRef.adc_wrapper__DOT__adc_rst_ms = vlSelfRef.rst;
}

void Vadc_wrapper___024root___nba_comb__TOP__0(Vadc_wrapper___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadc_wrapper___024root___nba_comb__TOP__0\n"); );
    Vadc_wrapper__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.adc_wrapper__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__u_dpdcram__DOT__wr_ena 
        = (((IData)(vlSelfRef.adc_wrapper__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__wr_ptr_gray) 
            != ((0x00006000U & ((~ ((IData)(vlSelfRef.adc_wrapper__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__rd_ptr_gray_wr) 
                                    >> 0x0000000dU)) 
                                << 0x0000000dU)) | 
                (0x00001fffU & (IData)(vlSelfRef.adc_wrapper__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__rd_ptr_gray_wr)))) 
           & (0U == (IData)(vlSelfRef.adc_wrapper__DOT__u_adc_int__DOT__latency_counter)));
}

void Vadc_wrapper___024root___nba_comb__TOP__1(Vadc_wrapper___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadc_wrapper___024root___nba_comb__TOP__1\n"); );
    Vadc_wrapper__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
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
    vlSelfRef.adc_wrapper__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__u_dpdcram__DOT__rd_ena 
        = (((IData)(vlSelfRef.adc_wrapper__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__rd_ptr_gray) 
            != (IData)(vlSelfRef.adc_wrapper__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__wr_ptr_gray_rd)) 
           & ((~ (IData)(vlSelfRef.adc_wrapper__DOT__u_dc_fifo__DOT__data_out_valid)) 
              | ((~ (IData)(vlSelfRef.adc_wrapper__DOT__u_dc_fifo__DOT__middle_valid)) 
                 | (IData)(vlSelfRef.adc_wrapper__DOT__u_dc_fifo__DOT__rd_ena))));
}

void Vadc_wrapper___024root___eval_nba(Vadc_wrapper___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadc_wrapper___024root___eval_nba\n"); );
    Vadc_wrapper__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((9ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vadc_wrapper___024root___nba_sequent__TOP__0(vlSelf);
    }
    if ((0x0000000000000011ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vadc_wrapper___024root___nba_sequent__TOP__1(vlSelf);
    }
    if ((0x0000000000000024ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vadc_wrapper___024root___nba_sequent__TOP__2(vlSelf);
    }
    if ((1ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vadc_wrapper___024root___nba_sequent__TOP__3(vlSelf);
        vlSelfRef.__Vm_traceActivity[1U] = 1U;
    }
    if ((6ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vadc_wrapper___024root___nba_sequent__TOP__4(vlSelf);
        vlSelfRef.__Vm_traceActivity[2U] = 1U;
    }
    if ((4ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vadc_wrapper___024root___nba_sequent__TOP__5(vlSelf);
        vlSelfRef.__Vm_traceActivity[3U] = 1U;
    }
    if ((3ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vadc_wrapper___024root___nba_sequent__TOP__6(vlSelf);
    }
    if ((0x0000000000000011ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vadc_wrapper___024root___nba_sequent__TOP__7(vlSelf);
        vlSelfRef.__Vm_traceActivity[4U] = 1U;
    }
    if ((9ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vadc_wrapper___024root___nba_sequent__TOP__8(vlSelf);
        vlSelfRef.__Vm_traceActivity[5U] = 1U;
    }
    if ((1ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vadc_wrapper___024root___nba_sequent__TOP__9(vlSelf);
    }
    if ((0x0000000000000024ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vadc_wrapper___024root___nba_sequent__TOP__10(vlSelf);
        vlSelfRef.__Vm_traceActivity[6U] = 1U;
    }
    if ((3ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vadc_wrapper___024root___nba_sequent__TOP__11(vlSelf);
    }
    if ((0x0000000000000019ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vadc_wrapper___024root___nba_comb__TOP__0(vlSelf);
    }
    if ((0x0000000000000026ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vadc_wrapper___024root___nba_comb__TOP__1(vlSelf);
    }
}

void Vadc_wrapper___024root___trigger_orInto__act_vec_vec(VlUnpacked<QData/*63:0*/, 1> &out, const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadc_wrapper___024root___trigger_orInto__act_vec_vec\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        out[n] = (out[n] | in[n]);
        n = ((IData)(1U) + n);
    } while ((0U >= n));
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vadc_wrapper___024root___dump_triggers__act(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG

bool Vadc_wrapper___024root___eval_phase__act(Vadc_wrapper___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadc_wrapper___024root___eval_phase__act\n"); );
    Vadc_wrapper__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vadc_wrapper___024root___eval_triggers_vec__act(vlSelf);
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vadc_wrapper___024root___dump_triggers__act(vlSelfRef.__VactTriggered, "act"s);
    }
#endif
    Vadc_wrapper___024root___trigger_orInto__act_vec_vec(vlSelfRef.__VnbaTriggered, vlSelfRef.__VactTriggered);
    return (0U);
}

void Vadc_wrapper___024root___trigger_clear__act(VlUnpacked<QData/*63:0*/, 1> &out) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadc_wrapper___024root___trigger_clear__act\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        out[n] = 0ULL;
        n = ((IData)(1U) + n);
    } while ((1U > n));
}

bool Vadc_wrapper___024root___eval_phase__nba(Vadc_wrapper___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadc_wrapper___024root___eval_phase__nba\n"); );
    Vadc_wrapper__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = Vadc_wrapper___024root___trigger_anySet__act(vlSelfRef.__VnbaTriggered);
    if (__VnbaExecute) {
        Vadc_wrapper___024root___eval_nba(vlSelf);
        Vadc_wrapper___024root___trigger_clear__act(vlSelfRef.__VnbaTriggered);
    }
    return (__VnbaExecute);
}

void Vadc_wrapper___024root___eval(Vadc_wrapper___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadc_wrapper___024root___eval\n"); );
    Vadc_wrapper__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ __VicoIterCount;
    IData/*31:0*/ __VnbaIterCount;
    // Body
    __VicoIterCount = 0U;
    vlSelfRef.__VicoFirstIteration = 1U;
    do {
        if (VL_UNLIKELY(((0x00000064U < __VicoIterCount)))) {
#ifdef VL_DEBUG
            Vadc_wrapper___024root___dump_triggers__ico(vlSelfRef.__VicoTriggered, "ico"s);
#endif
            VL_FATAL_MT("../hdl/adc/adc_wrapper.sv", 1, "", "DIDNOTCONVERGE: Input combinational region did not converge after '--converge-limit' of 100 tries");
        }
        __VicoIterCount = ((IData)(1U) + __VicoIterCount);
        vlSelfRef.__VicoPhaseResult = Vadc_wrapper___024root___eval_phase__ico(vlSelf);
        vlSelfRef.__VicoFirstIteration = 0U;
    } while (vlSelfRef.__VicoPhaseResult);
    __VnbaIterCount = 0U;
    do {
        if (VL_UNLIKELY(((0x00000064U < __VnbaIterCount)))) {
#ifdef VL_DEBUG
            Vadc_wrapper___024root___dump_triggers__act(vlSelfRef.__VnbaTriggered, "nba"s);
#endif
            VL_FATAL_MT("../hdl/adc/adc_wrapper.sv", 1, "", "DIDNOTCONVERGE: NBA region did not converge after '--converge-limit' of 100 tries");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        vlSelfRef.__VactIterCount = 0U;
        do {
            if (VL_UNLIKELY(((0x00000064U < vlSelfRef.__VactIterCount)))) {
#ifdef VL_DEBUG
                Vadc_wrapper___024root___dump_triggers__act(vlSelfRef.__VactTriggered, "act"s);
#endif
                VL_FATAL_MT("../hdl/adc/adc_wrapper.sv", 1, "", "DIDNOTCONVERGE: Active region did not converge after '--converge-limit' of 100 tries");
            }
            vlSelfRef.__VactIterCount = ((IData)(1U) 
                                         + vlSelfRef.__VactIterCount);
            vlSelfRef.__VactPhaseResult = Vadc_wrapper___024root___eval_phase__act(vlSelf);
        } while (vlSelfRef.__VactPhaseResult);
        vlSelfRef.__VnbaPhaseResult = Vadc_wrapper___024root___eval_phase__nba(vlSelf);
    } while (vlSelfRef.__VnbaPhaseResult);
}

#ifdef VL_DEBUG
void Vadc_wrapper___024root___eval_debug_assertions(Vadc_wrapper___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadc_wrapper___024root___eval_debug_assertions\n"); );
    Vadc_wrapper__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (VL_UNLIKELY(((vlSelfRef.rst & 0xfeU)))) {
        Verilated::overWidthError("rst");
    }
    if (VL_UNLIKELY(((vlSelfRef.enable & 0xfeU)))) {
        Verilated::overWidthError("enable");
    }
    if (VL_UNLIKELY(((vlSelfRef.adc_clk & 0xfeU)))) {
        Verilated::overWidthError("adc_clk");
    }
    if (VL_UNLIKELY(((vlSelfRef.adc_data_raw & 0xf000U)))) {
        Verilated::overWidthError("adc_data_raw");
    }
    if (VL_UNLIKELY(((vlSelfRef.adc_otr & 0xfeU)))) {
        Verilated::overWidthError("adc_otr");
    }
    if (VL_UNLIKELY(((vlSelfRef.ulpi_clk & 0xfeU)))) {
        Verilated::overWidthError("ulpi_clk");
    }
    if (VL_UNLIKELY(((vlSelfRef.tx_ready & 0xfeU)))) {
        Verilated::overWidthError("tx_ready");
    }
}
#endif  // VL_DEBUG
