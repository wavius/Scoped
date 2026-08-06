// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"

void Vtop___024root___eval_triggers_vec__ico(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_triggers_vec__ico\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VicoTriggered[0U] = ((0xfffffffffffffffeULL 
                                      & vlSelfRef.__VicoTriggered[0U]) 
                                     | (IData)((IData)(vlSelfRef.__VicoFirstIteration)));
}

bool Vtop___024root___trigger_anySet__ico(const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___trigger_anySet__ico\n"); );
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

void Vtop___024root___ico_sequent__TOP__0(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___ico_sequent__TOP__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.ulpi_data = (((IData)(vlSelfRef.ulpi_dir)
                             ? 0U : 0xffU) & (((IData)(vlSelfRef.ulpi_dir)
                                                ? 0U
                                                : (IData)(vlSelfRef.top__DOT__u_ulpi__DOT__ulpi_data_q)) 
                                              & ((IData)(vlSelfRef.ulpi_dir)
                                                  ? 0U
                                                  : 0xffU)));
    vlSelfRef.top__DOT__u_ulpi__DOT____VdfgRegularize_hdd78e87c_0_2 
        = ((~ (IData)(vlSelfRef.ulpi_dir)) & (IData)(vlSelfRef.ulpi_nxt));
    vlSelfRef.top__DOT__u_ulpi__DOT__turnaround_w = 
        ((IData)(vlSelfRef.top__DOT__u_ulpi__DOT__ulpi_dir_q) 
         ^ (IData)(vlSelfRef.ulpi_dir));
}

void Vtop___024root___eval_ico(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_ico\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VicoTriggered[0U])) {
        Vtop___024root___ico_sequent__TOP__0(vlSelf);
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__ico(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG

bool Vtop___024root___eval_phase__ico(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_phase__ico\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VicoExecute;
    // Body
    Vtop___024root___eval_triggers_vec__ico(vlSelf);
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtop___024root___dump_triggers__ico(vlSelfRef.__VicoTriggered, "ico"s);
    }
#endif
    __VicoExecute = Vtop___024root___trigger_anySet__ico(vlSelfRef.__VicoTriggered);
    if (__VicoExecute) {
        Vtop___024root___eval_ico(vlSelf);
    }
    return (__VicoExecute);
}

void Vtop___024root___eval_triggers_vec__act(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_triggers_vec__act\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VactTriggered[0U] = (QData)((IData)(
                                                    (((((IData)(vlSelfRef.top__DOT__u_adc_wrap__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__rd_a_rst) 
                                                        & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__top__DOT__u_adc_wrap__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__rd_a_rst__0))) 
                                                       << 5U) 
                                                      | (((IData)(vlSelfRef.top__DOT__u_adc_wrap__DOT__adc_rst_sync) 
                                                          & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__top__DOT__u_adc_wrap__DOT__adc_rst_sync__0))) 
                                                         << 4U)) 
                                                     | (((((IData)(vlSelfRef.top__DOT__cdc_rst) 
                                                           & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__top__DOT__cdc_rst__0))) 
                                                          << 3U) 
                                                         | (((IData)(vlSelfRef.ulpi_clk60) 
                                                             & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__ulpi_clk60__0))) 
                                                            << 2U)) 
                                                        | ((((IData)(vlSelfRef.top__DOT__phy_rst) 
                                                             & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__top__DOT__phy_rst__0))) 
                                                            << 1U) 
                                                           | ((IData)(vlSelfRef.clk_25m) 
                                                              & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__clk_25m__0))))))));
    vlSelfRef.__Vtrigprevexpr___TOP__clk_25m__0 = vlSelfRef.clk_25m;
    vlSelfRef.__Vtrigprevexpr___TOP__top__DOT__phy_rst__0 
        = vlSelfRef.top__DOT__phy_rst;
    vlSelfRef.__Vtrigprevexpr___TOP__ulpi_clk60__0 
        = vlSelfRef.ulpi_clk60;
    vlSelfRef.__Vtrigprevexpr___TOP__top__DOT__cdc_rst__0 
        = vlSelfRef.top__DOT__cdc_rst;
    vlSelfRef.__Vtrigprevexpr___TOP__top__DOT__u_adc_wrap__DOT__adc_rst_sync__0 
        = vlSelfRef.top__DOT__u_adc_wrap__DOT__adc_rst_sync;
    vlSelfRef.__Vtrigprevexpr___TOP__top__DOT__u_adc_wrap__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__rd_a_rst__0 
        = vlSelfRef.top__DOT__u_adc_wrap__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__rd_a_rst;
}

bool Vtop___024root___trigger_anySet__act(const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___trigger_anySet__act\n"); );
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

void Vtop___024root___nba_sequent__TOP__0(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    SData/*14:0*/ __Vfunc_gray2bin__3__Vfuncout;
    __Vfunc_gray2bin__3__Vfuncout = 0;
    SData/*14:0*/ __Vfunc_gray2bin__3__gray;
    __Vfunc_gray2bin__3__gray = 0;
    // Body
    vlSelfRef.__VdlySet__top__DOT__u_adc_wrap__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__u_dpdcram__DOT__mem__v0 = 0U;
    if (vlSelfRef.top__DOT__u_adc_wrap__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__u_dpdcram__DOT__wr_ena) {
        vlSelfRef.__VdlyVal__top__DOT__u_adc_wrap__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__u_dpdcram__DOT__mem__v0 
            = vlSelfRef.top__DOT__u_adc_wrap__DOT__adc_data;
        vlSelfRef.__VdlyDim0__top__DOT__u_adc_wrap__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__u_dpdcram__DOT__mem__v0 
            = (0x00003fffU & (IData)(vlSelfRef.top__DOT__u_adc_wrap__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__wr_ptr));
        vlSelfRef.__VdlySet__top__DOT__u_adc_wrap__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__u_dpdcram__DOT__mem__v0 = 1U;
    }
    vlSelfRef.top__DOT__u_adc_wrap__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__rd_ptr_gray_wr 
        = vlSelfRef.top__DOT__u_adc_wrap__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__rd_ptr_ms;
    __Vfunc_gray2bin__3__gray = vlSelfRef.top__DOT__u_adc_wrap__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__rd_ptr_gray_wr;
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
    vlSelfRef.top__DOT__u_adc_wrap__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__rd_ptr_wr 
        = __Vfunc_gray2bin__3__Vfuncout;
    vlSelfRef.top__DOT__u_adc_wrap__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__rd_ptr_ms 
        = vlSelfRef.top__DOT__u_adc_wrap__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__rd_ptr_gray;
}

extern const VlUnpacked<CData/*7:0*/, 512> Vtop__ConstPool__TABLE_h84190edb_0;
extern const VlUnpacked<CData/*0:0*/, 16> Vtop__ConstPool__TABLE_hae65a50a_0;
extern const VlUnpacked<VlWide<3>/*79:0*/, 8> Vtop__ConstPool__TABLE_h646b3b33_0;
extern const VlUnpacked<CData/*2:0*/, 2048> Vtop__ConstPool__TABLE_h5eabb7eb_0;

void Vtop___024root___nba_sequent__TOP__1(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__1\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ top__DOT__u_cdc__DOT____VdfgExtracted_h9796ed88__0;
    top__DOT__u_cdc__DOT____VdfgExtracted_h9796ed88__0 = 0;
    CData/*0:0*/ top__DOT__u_cdc__DOT__u_core__DOT__u_sie_tx__DOT__u_crc16__DOT____VdfgRegularize_h8075a1a5_0_0;
    top__DOT__u_cdc__DOT__u_core__DOT__u_sie_tx__DOT__u_crc16__DOT____VdfgRegularize_h8075a1a5_0_0 = 0;
    CData/*0:0*/ top__DOT__u_cdc__DOT__u_core__DOT__u_sie_tx__DOT__u_crc16__DOT____VdfgRegularize_h8075a1a5_0_1;
    top__DOT__u_cdc__DOT__u_core__DOT__u_sie_tx__DOT__u_crc16__DOT____VdfgRegularize_h8075a1a5_0_1 = 0;
    CData/*0:0*/ top__DOT__u_cdc__DOT__u_core__DOT__u_sie_tx__DOT__u_crc16__DOT____VdfgRegularize_h8075a1a5_0_2;
    top__DOT__u_cdc__DOT__u_core__DOT__u_sie_tx__DOT__u_crc16__DOT____VdfgRegularize_h8075a1a5_0_2 = 0;
    CData/*0:0*/ top__DOT__u_cdc__DOT__u_core__DOT__u_sie_tx__DOT__u_crc16__DOT____VdfgRegularize_h8075a1a5_0_3;
    top__DOT__u_cdc__DOT__u_core__DOT__u_sie_tx__DOT__u_crc16__DOT____VdfgRegularize_h8075a1a5_0_3 = 0;
    CData/*0:0*/ top__DOT__u_cdc__DOT__u_core__DOT__u_sie_tx__DOT__u_crc16__DOT____VdfgRegularize_h8075a1a5_0_4;
    top__DOT__u_cdc__DOT__u_core__DOT__u_sie_tx__DOT__u_crc16__DOT____VdfgRegularize_h8075a1a5_0_4 = 0;
    CData/*0:0*/ top__DOT__u_cdc__DOT__u_core__DOT__u_sie_tx__DOT__u_crc16__DOT____VdfgRegularize_h8075a1a5_0_5;
    top__DOT__u_cdc__DOT__u_core__DOT__u_sie_tx__DOT__u_crc16__DOT____VdfgRegularize_h8075a1a5_0_5 = 0;
    CData/*0:0*/ top__DOT__u_cdc__DOT__u_core__DOT__u_sie_tx__DOT__u_crc16__DOT____VdfgRegularize_h8075a1a5_0_6;
    top__DOT__u_cdc__DOT__u_core__DOT__u_sie_tx__DOT__u_crc16__DOT____VdfgRegularize_h8075a1a5_0_6 = 0;
    CData/*0:0*/ top__DOT__u_cdc__DOT__u_core__DOT__u_sie_tx__DOT__u_crc16__DOT____VdfgRegularize_h8075a1a5_0_7;
    top__DOT__u_cdc__DOT__u_core__DOT__u_sie_tx__DOT__u_crc16__DOT____VdfgRegularize_h8075a1a5_0_7 = 0;
    CData/*0:0*/ top__DOT__u_cdc__DOT__u_core__DOT__u_sie_tx__DOT__u_crc16__DOT____VdfgRegularize_h8075a1a5_0_8;
    top__DOT__u_cdc__DOT__u_core__DOT__u_sie_tx__DOT__u_crc16__DOT____VdfgRegularize_h8075a1a5_0_8 = 0;
    CData/*0:0*/ top__DOT__u_cdc__DOT__u_core__DOT__u_sie_tx__DOT__u_crc16__DOT____VdfgRegularize_h8075a1a5_0_9;
    top__DOT__u_cdc__DOT__u_core__DOT__u_sie_tx__DOT__u_crc16__DOT____VdfgRegularize_h8075a1a5_0_9 = 0;
    CData/*0:0*/ top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__u_crc16__DOT____VdfgRegularize_h8075a1a5_0_0;
    top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__u_crc16__DOT____VdfgRegularize_h8075a1a5_0_0 = 0;
    CData/*0:0*/ top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__u_crc16__DOT____VdfgRegularize_h8075a1a5_0_1;
    top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__u_crc16__DOT____VdfgRegularize_h8075a1a5_0_1 = 0;
    CData/*0:0*/ top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__u_crc16__DOT____VdfgRegularize_h8075a1a5_0_2;
    top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__u_crc16__DOT____VdfgRegularize_h8075a1a5_0_2 = 0;
    CData/*0:0*/ top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__u_crc16__DOT____VdfgRegularize_h8075a1a5_0_3;
    top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__u_crc16__DOT____VdfgRegularize_h8075a1a5_0_3 = 0;
    CData/*0:0*/ top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__u_crc16__DOT____VdfgRegularize_h8075a1a5_0_4;
    top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__u_crc16__DOT____VdfgRegularize_h8075a1a5_0_4 = 0;
    CData/*0:0*/ top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__u_crc16__DOT____VdfgRegularize_h8075a1a5_0_5;
    top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__u_crc16__DOT____VdfgRegularize_h8075a1a5_0_5 = 0;
    CData/*0:0*/ top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__u_crc16__DOT____VdfgRegularize_h8075a1a5_0_6;
    top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__u_crc16__DOT____VdfgRegularize_h8075a1a5_0_6 = 0;
    CData/*0:0*/ top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__u_crc16__DOT____VdfgRegularize_h8075a1a5_0_7;
    top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__u_crc16__DOT____VdfgRegularize_h8075a1a5_0_7 = 0;
    CData/*0:0*/ top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__u_crc16__DOT____VdfgRegularize_h8075a1a5_0_8;
    top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__u_crc16__DOT____VdfgRegularize_h8075a1a5_0_8 = 0;
    CData/*0:0*/ top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__u_crc16__DOT____VdfgRegularize_h8075a1a5_0_9;
    top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__u_crc16__DOT____VdfgRegularize_h8075a1a5_0_9 = 0;
    CData/*3:0*/ __Vtableidx1;
    __Vtableidx1 = 0;
    CData/*2:0*/ __Vtableidx2;
    __Vtableidx2 = 0;
    SData/*10:0*/ __Vtableidx3;
    __Vtableidx3 = 0;
    SData/*8:0*/ __Vtableidx4;
    __Vtableidx4 = 0;
    IData/*22:0*/ __Vdly__top__DOT__startup_timer;
    __Vdly__top__DOT__startup_timer = 0;
    CData/*0:0*/ __Vdly__top__DOT__ready_for_leds;
    __Vdly__top__DOT__ready_for_leds = 0;
    CData/*0:0*/ __Vdly__top__DOT__u_ulpi__DOT__mode_update_q;
    __Vdly__top__DOT__u_ulpi__DOT__mode_update_q = 0;
    CData/*0:0*/ __Vdly__top__DOT__u_ulpi__DOT__otg_update_q;
    __Vdly__top__DOT__u_ulpi__DOT__otg_update_q = 0;
    CData/*2:0*/ __Vdly__top__DOT__u_ulpi__DOT__tx_delay_q;
    __Vdly__top__DOT__u_ulpi__DOT__tx_delay_q = 0;
    CData/*0:0*/ __Vdly__top__DOT__u_ulpi__DOT__tx_wr_idx_q;
    __Vdly__top__DOT__u_ulpi__DOT__tx_wr_idx_q = 0;
    CData/*0:0*/ __Vdly__top__DOT__u_ulpi__DOT__tx_rd_idx_q;
    __Vdly__top__DOT__u_ulpi__DOT__tx_rd_idx_q = 0;
    CData/*1:0*/ __Vdly__top__DOT__u_ulpi__DOT__state_q;
    __Vdly__top__DOT__u_ulpi__DOT__state_q = 0;
    CData/*7:0*/ __Vdly__top__DOT__u_ulpi__DOT__data_q;
    __Vdly__top__DOT__u_ulpi__DOT__data_q = 0;
    CData/*0:0*/ __Vdly__top__DOT__u_ulpi__DOT__mode_write_q;
    __Vdly__top__DOT__u_ulpi__DOT__mode_write_q = 0;
    SData/*9:0*/ __Vdly__top__DOT__u_adc_wrap__DOT__burst_count;
    __Vdly__top__DOT__u_adc_wrap__DOT__burst_count = 0;
    CData/*0:0*/ __Vdly__top__DOT__u_adc_wrap__DOT__u_dc_fifo__DOT__data_out_valid;
    __Vdly__top__DOT__u_adc_wrap__DOT__u_dc_fifo__DOT__data_out_valid = 0;
    CData/*0:0*/ __Vdly__top__DOT__u_adc_wrap__DOT__u_dc_fifo__DOT__middle_valid;
    __Vdly__top__DOT__u_adc_wrap__DOT__u_dc_fifo__DOT__middle_valid = 0;
    SData/*11:0*/ __Vdly__top__DOT__u_adc_wrap__DOT__u_dc_fifo__DOT__middle_data;
    __Vdly__top__DOT__u_adc_wrap__DOT__u_dc_fifo__DOT__middle_data = 0;
    IData/*19:0*/ __Vdly__top__DOT__u_cdc__DOT__genblk1__DOT__usb_rst_time_q;
    __Vdly__top__DOT__u_cdc__DOT__genblk1__DOT__usb_rst_time_q = 0;
    CData/*7:0*/ __Vdly__top__DOT__u_cdc__DOT__genblk1__DOT__chirp_count_q;
    __Vdly__top__DOT__u_cdc__DOT__genblk1__DOT__chirp_count_q = 0;
    CData/*2:0*/ __Vdly__top__DOT__u_cdc__DOT__setup_wr_idx_q;
    __Vdly__top__DOT__u_cdc__DOT__setup_wr_idx_q = 0;
    CData/*7:0*/ __Vdly__top__DOT__u_cdc__DOT__desc_addr_q;
    __Vdly__top__DOT__u_cdc__DOT__desc_addr_q = 0;
    SData/*10:0*/ __Vdly__top__DOT__u_cdc__DOT__inport_cnt_q;
    __Vdly__top__DOT__u_cdc__DOT__inport_cnt_q = 0;
    SData/*14:0*/ __Vdly__top__DOT__u_cdc__DOT__u_core__DOT__se0_cnt_q;
    __Vdly__top__DOT__u_cdc__DOT__u_core__DOT__se0_cnt_q = 0;
    CData/*0:0*/ __Vdly__top__DOT__u_cdc__DOT__u_core__DOT__tx_valid_q;
    __Vdly__top__DOT__u_cdc__DOT__u_core__DOT__tx_valid_q = 0;
    CData/*0:0*/ __Vdly__top__DOT__u_cdc__DOT__u_core__DOT__addr_update_pending_q;
    __Vdly__top__DOT__u_cdc__DOT__u_core__DOT__addr_update_pending_q = 0;
    IData/*31:0*/ __Vdly__top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__data_buffer_q;
    __Vdly__top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__data_buffer_q = 0;
    CData/*3:0*/ __Vdly__top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__data_valid_q;
    __Vdly__top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__data_valid_q = 0;
    CData/*1:0*/ __Vdly__top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__data_crc_q;
    __Vdly__top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__data_crc_q = 0;
    SData/*10:0*/ __Vdly__top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__frame_num_q;
    __Vdly__top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__frame_num_q = 0;
    CData/*0:0*/ __VdlySet__top__DOT__u_ulpi__DOT__tx_buffer_q__v0;
    __VdlySet__top__DOT__u_ulpi__DOT__tx_buffer_q__v0 = 0;
    CData/*0:0*/ __VdlySet__top__DOT__u_ulpi__DOT__tx_buffer_q__v1;
    __VdlySet__top__DOT__u_ulpi__DOT__tx_buffer_q__v1 = 0;
    CData/*7:0*/ __VdlyVal__top__DOT__u_ulpi__DOT__tx_buffer_q__v2;
    __VdlyVal__top__DOT__u_ulpi__DOT__tx_buffer_q__v2 = 0;
    CData/*0:0*/ __VdlyDim0__top__DOT__u_ulpi__DOT__tx_buffer_q__v2;
    __VdlyDim0__top__DOT__u_ulpi__DOT__tx_buffer_q__v2 = 0;
    CData/*0:0*/ __VdlySet__top__DOT__u_ulpi__DOT__tx_buffer_q__v2;
    __VdlySet__top__DOT__u_ulpi__DOT__tx_buffer_q__v2 = 0;
    CData/*0:0*/ __VdlyDim0__top__DOT__u_ulpi__DOT__tx_valid_q__v2;
    __VdlyDim0__top__DOT__u_ulpi__DOT__tx_valid_q__v2 = 0;
    CData/*0:0*/ __VdlyDim0__top__DOT__u_ulpi__DOT__tx_valid_q__v3;
    __VdlyDim0__top__DOT__u_ulpi__DOT__tx_valid_q__v3 = 0;
    CData/*0:0*/ __VdlySet__top__DOT__u_ulpi__DOT__tx_valid_q__v3;
    __VdlySet__top__DOT__u_ulpi__DOT__tx_valid_q__v3 = 0;
    CData/*0:0*/ __VdlySet__top__DOT__u_cdc__DOT__setup_packet_q__v0;
    __VdlySet__top__DOT__u_cdc__DOT__setup_packet_q__v0 = 0;
    CData/*0:0*/ __VdlySet__top__DOT__u_cdc__DOT__setup_packet_q__v1;
    __VdlySet__top__DOT__u_cdc__DOT__setup_packet_q__v1 = 0;
    CData/*0:0*/ __VdlySet__top__DOT__u_cdc__DOT__setup_packet_q__v8;
    __VdlySet__top__DOT__u_cdc__DOT__setup_packet_q__v8 = 0;
    CData/*0:0*/ __VdlySet__top__DOT__u_cdc__DOT__setup_packet_q__v9;
    __VdlySet__top__DOT__u_cdc__DOT__setup_packet_q__v9 = 0;
    CData/*7:0*/ __VdlyVal__top__DOT__u_cdc__DOT__setup_packet_q__v16;
    __VdlyVal__top__DOT__u_cdc__DOT__setup_packet_q__v16 = 0;
    CData/*2:0*/ __VdlyDim0__top__DOT__u_cdc__DOT__setup_packet_q__v16;
    __VdlyDim0__top__DOT__u_cdc__DOT__setup_packet_q__v16 = 0;
    CData/*0:0*/ __VdlySet__top__DOT__u_cdc__DOT__setup_packet_q__v16;
    __VdlySet__top__DOT__u_cdc__DOT__setup_packet_q__v16 = 0;
    // Body
    __Vdly__top__DOT__startup_timer = vlSelfRef.top__DOT__startup_timer;
    __Vdly__top__DOT__ready_for_leds = vlSelfRef.top__DOT__ready_for_leds;
    __Vdly__top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__data_crc_q 
        = vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__data_crc_q;
    __Vdly__top__DOT__u_adc_wrap__DOT__burst_count 
        = vlSelfRef.top__DOT__u_adc_wrap__DOT__burst_count;
    __Vdly__top__DOT__u_cdc__DOT__u_core__DOT__se0_cnt_q 
        = vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__se0_cnt_q;
    __Vdly__top__DOT__u_adc_wrap__DOT__u_dc_fifo__DOT__middle_data 
        = vlSelfRef.top__DOT__u_adc_wrap__DOT__u_dc_fifo__DOT__middle_data;
    __Vdly__top__DOT__u_adc_wrap__DOT__u_dc_fifo__DOT__middle_valid 
        = vlSelfRef.top__DOT__u_adc_wrap__DOT__u_dc_fifo__DOT__middle_valid;
    __Vdly__top__DOT__u_adc_wrap__DOT__u_dc_fifo__DOT__data_out_valid 
        = vlSelfRef.top__DOT__u_adc_wrap__DOT__u_dc_fifo__DOT__data_out_valid;
    __Vdly__top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__frame_num_q 
        = vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__frame_num_q;
    __Vdly__top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__data_valid_q 
        = vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__data_valid_q;
    __Vdly__top__DOT__u_ulpi__DOT__mode_update_q = vlSelfRef.top__DOT__u_ulpi__DOT__mode_update_q;
    __Vdly__top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__data_buffer_q 
        = vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__data_buffer_q;
    __Vdly__top__DOT__u_ulpi__DOT__tx_delay_q = vlSelfRef.top__DOT__u_ulpi__DOT__tx_delay_q;
    __Vdly__top__DOT__u_cdc__DOT__genblk1__DOT__usb_rst_time_q 
        = vlSelfRef.top__DOT__u_cdc__DOT__genblk1__DOT__usb_rst_time_q;
    __Vdly__top__DOT__u_cdc__DOT__inport_cnt_q = vlSelfRef.top__DOT__u_cdc__DOT__inport_cnt_q;
    __Vdly__top__DOT__u_cdc__DOT__genblk1__DOT__chirp_count_q 
        = vlSelfRef.top__DOT__u_cdc__DOT__genblk1__DOT__chirp_count_q;
    __Vdly__top__DOT__u_cdc__DOT__u_core__DOT__tx_valid_q 
        = vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__tx_valid_q;
    __Vdly__top__DOT__u_ulpi__DOT__state_q = vlSelfRef.top__DOT__u_ulpi__DOT__state_q;
    __Vdly__top__DOT__u_ulpi__DOT__data_q = vlSelfRef.top__DOT__u_ulpi__DOT__data_q;
    __Vdly__top__DOT__u_ulpi__DOT__mode_write_q = vlSelfRef.top__DOT__u_ulpi__DOT__mode_write_q;
    __Vdly__top__DOT__u_ulpi__DOT__tx_rd_idx_q = vlSelfRef.top__DOT__u_ulpi__DOT__tx_rd_idx_q;
    __Vdly__top__DOT__u_ulpi__DOT__otg_update_q = vlSelfRef.top__DOT__u_ulpi__DOT__otg_update_q;
    __Vdly__top__DOT__u_ulpi__DOT__tx_wr_idx_q = vlSelfRef.top__DOT__u_ulpi__DOT__tx_wr_idx_q;
    __VdlySet__top__DOT__u_ulpi__DOT__tx_valid_q__v3 = 0U;
    __VdlySet__top__DOT__u_ulpi__DOT__tx_buffer_q__v0 = 0U;
    __VdlySet__top__DOT__u_ulpi__DOT__tx_buffer_q__v1 = 0U;
    __VdlySet__top__DOT__u_ulpi__DOT__tx_buffer_q__v2 = 0U;
    __Vdly__top__DOT__u_cdc__DOT__desc_addr_q = vlSelfRef.top__DOT__u_cdc__DOT__desc_addr_q;
    __Vdly__top__DOT__u_cdc__DOT__setup_wr_idx_q = vlSelfRef.top__DOT__u_cdc__DOT__setup_wr_idx_q;
    __VdlySet__top__DOT__u_cdc__DOT__setup_packet_q__v0 = 0U;
    __VdlySet__top__DOT__u_cdc__DOT__setup_packet_q__v1 = 0U;
    __VdlySet__top__DOT__u_cdc__DOT__setup_packet_q__v8 = 0U;
    __VdlySet__top__DOT__u_cdc__DOT__setup_packet_q__v9 = 0U;
    __VdlySet__top__DOT__u_cdc__DOT__setup_packet_q__v16 = 0U;
    __Vdly__top__DOT__u_cdc__DOT__u_core__DOT__addr_update_pending_q 
        = vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__addr_update_pending_q;
    vlSelfRef.top__DOT__u_ulpi__DOT__ulpi_dir_q = (
                                                   (~ 
                                                    ((IData)(vlSelfRef.top__DOT__rst_sync) 
                                                     >> 2U)) 
                                                   & (IData)(vlSelfRef.ulpi_dir));
    vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__frame_valid_q 
        = ((~ ((IData)(vlSelfRef.top__DOT__rst_sync) 
               >> 2U)) & ((5U == (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__state_q)) 
                          & (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__data_valid_q)));
    vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__last_q 
        = ((1U & (~ ((IData)(vlSelfRef.top__DOT__rst_sync) 
                     >> 2U))) && ((6U == (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__state_q)) 
                                  & (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__data_crc_q)));
    vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__data_complete_q 
        = ((~ ((IData)(vlSelfRef.top__DOT__rst_sync) 
               >> 2U)) & ((7U == (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__state_q)) 
                          & (0U == (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__next_state_r))));
    vlSelfRef.top__DOT__u_cdc__DOT__ctrl_sending_q 
        = ((1U & (~ ((IData)(vlSelfRef.top__DOT__rst_sync) 
                     >> 2U))) && ((1U & (~ (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__rst_event_q))) 
                                  && (IData)(vlSelfRef.top__DOT__u_cdc__DOT__ctrl_sending_r)));
    vlSelfRef.top__DOT__u_cdc__DOT__ctrl_txstall_q 
        = ((1U & (~ ((IData)(vlSelfRef.top__DOT__rst_sync) 
                     >> 2U))) && ((1U & (~ (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__rst_event_q))) 
                                  && (IData)(vlSelfRef.top__DOT__u_cdc__DOT__ctrl_txstall_r)));
    vlSelfRef.top__DOT__u_cdc__DOT__addressed_q = (
                                                   (1U 
                                                    & (~ 
                                                       ((IData)(vlSelfRef.top__DOT__rst_sync) 
                                                        >> 2U))) 
                                                   && ((1U 
                                                        & (~ (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__rst_event_q))) 
                                                       && (IData)(vlSelfRef.top__DOT__u_cdc__DOT__addressed_r)));
    vlSelfRef.top__DOT__u_cdc__DOT__configured_q = 
        ((1U & (~ ((IData)(vlSelfRef.top__DOT__rst_sync) 
                   >> 2U))) && ((1U & (~ (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__rst_event_q))) 
                                && (IData)(vlSelfRef.top__DOT__u_cdc__DOT__configured_r)));
    vlSelfRef.top__DOT__u_cdc__DOT__set_with_data_q 
        = ((1U & (~ ((IData)(vlSelfRef.top__DOT__rst_sync) 
                     >> 2U))) && ((1U & (~ (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__rst_event_q))) 
                                  && (IData)(vlSelfRef.top__DOT__u_cdc__DOT__set_with_data_r)));
    vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__valid_q 
        = ((1U & (~ ((IData)(vlSelfRef.top__DOT__rst_sync) 
                     >> 2U))) && ((IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__input_ready_w) 
                                  | (((6U == (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__state_q)) 
                                      & (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__data_crc_q)) 
                                     & (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__data_zlp_q))));
    vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__rx_enable_q 
        = ((~ ((IData)(vlSelfRef.top__DOT__rst_sync) 
               >> 2U)) & ((~ (((IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__se0_cnt_q) 
                               >> 0x0000000eU) | (2U 
                                                  == (IData)(vlSelfRef.top__DOT__u_cdc__DOT__genblk1__DOT__state_q)))) 
                          & (1U == (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__state_q))));
    vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__intr_q 
        = (1U & ((~ ((IData)(vlSelfRef.top__DOT__rst_sync) 
                     >> 2U)) & (((~ (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__rst_event_q)) 
                                 & ((IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__se0_cnt_q) 
                                    >> 0x0000000eU)) 
                                | ((((2U == (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__state_q)) 
                                     & (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__rx_space_q)) 
                                    & (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__cfg_int_rx_r)) 
                                   | ((5U == (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__state_q)) 
                                      & (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__cfg_int_tx_r))))));
    vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__rx_setup_q 
        = ((~ ((IData)(vlSelfRef.top__DOT__rst_sync) 
               >> 2U)) & ((~ (((IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__se0_cnt_q) 
                               >> 0x0000000eU) | (2U 
                                                  == (IData)(vlSelfRef.top__DOT__u_cdc__DOT__genblk1__DOT__state_q)))) 
                          & ((((0U == (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__state_q)) 
                               & (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__token_valid_q)) 
                              & (0x2dU == (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__token_pid_q))) 
                             & (0U == (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__token_ep_q)))));
    if ((4U & (IData)(vlSelfRef.top__DOT__rst_sync))) {
        __Vdly__top__DOT__startup_timer = 0U;
        __Vdly__top__DOT__ready_for_leds = 0U;
        vlSelfRef.top__DOT__startup_timer = __Vdly__top__DOT__startup_timer;
        vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__rx_active_q = 0U;
        __Vdly__top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__data_crc_q = 0U;
        __Vdly__top__DOT__u_cdc__DOT__u_core__DOT__se0_cnt_q = 0U;
        __Vdly__top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__frame_num_q = 0U;
        vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__frame_num_q 
            = __Vdly__top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__frame_num_q;
        __Vdly__top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__data_valid_q = 0U;
        __Vdly__top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__data_buffer_q = 0U;
        __Vdly__top__DOT__u_ulpi__DOT__tx_delay_q = 0U;
        vlSelfRef.top__DOT__u_ulpi__DOT__tx_delay_q 
            = __Vdly__top__DOT__u_ulpi__DOT__tx_delay_q;
        __Vdly__top__DOT__u_cdc__DOT__genblk1__DOT__usb_rst_time_q = 0U;
        vlSelfRef.top__DOT__u_cdc__DOT__genblk1__DOT__usb_rst_time_q 
            = __Vdly__top__DOT__u_cdc__DOT__genblk1__DOT__usb_rst_time_q;
        __Vdly__top__DOT__u_cdc__DOT__inport_cnt_q = 0U;
        vlSelfRef.top__DOT__u_cdc__DOT__inport_cnt_q 
            = __Vdly__top__DOT__u_cdc__DOT__inport_cnt_q;
        __Vdly__top__DOT__u_cdc__DOT__genblk1__DOT__chirp_count_q = 0U;
        vlSelfRef.top__DOT__u_cdc__DOT__genblk1__DOT__chirp_count_q 
            = __Vdly__top__DOT__u_cdc__DOT__genblk1__DOT__chirp_count_q;
        __Vdly__top__DOT__u_cdc__DOT__u_core__DOT__tx_valid_q = 0U;
        __Vdly__top__DOT__u_ulpi__DOT__otg_update_q = 0U;
        __VdlySet__top__DOT__u_ulpi__DOT__tx_buffer_q__v0 = 1U;
        __Vdly__top__DOT__u_ulpi__DOT__tx_wr_idx_q = 0U;
        __Vdly__top__DOT__u_ulpi__DOT__tx_rd_idx_q = 0U;
        __VdlySet__top__DOT__u_ulpi__DOT__tx_buffer_q__v1 = 1U;
    } else {
        if ((1U & (~ (IData)(vlSelfRef.top__DOT__ready_for_leds)))) {
            if ((0x005b8d80U > vlSelfRef.top__DOT__startup_timer)) {
                __Vdly__top__DOT__startup_timer = (0x007fffffU 
                                                   & ((IData)(1U) 
                                                      + vlSelfRef.top__DOT__startup_timer));
            } else {
                __Vdly__top__DOT__ready_for_leds = 1U;
            }
        }
        vlSelfRef.top__DOT__startup_timer = __Vdly__top__DOT__startup_timer;
        vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__rx_active_q 
            = (((IData)(vlSelfRef.top__DOT__u_ulpi__DOT__utmi_rxactive_q) 
                << 3U) | (7U & ((IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__rx_active_q) 
                                >> 1U)));
        if (vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__shift_en_w) {
            __Vdly__top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__data_crc_q 
                = ((2U & ((~ (IData)(vlSelfRef.top__DOT__u_ulpi__DOT__utmi_rxactive_q)) 
                          << 1U)) | (1U & ((IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__data_crc_q) 
                                           >> 1U)));
            __Vdly__top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__data_valid_q 
                = ((((IData)(vlSelfRef.top__DOT__u_ulpi__DOT__utmi_rxvalid_q) 
                     & (IData)(vlSelfRef.top__DOT__u_ulpi__DOT__utmi_rxactive_q)) 
                    << 3U) | (7U & ((IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__data_valid_q) 
                                    >> 1U)));
            __Vdly__top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__data_buffer_q 
                = (((IData)(vlSelfRef.top__DOT__u_ulpi__DOT__utmi_data_q) 
                    << 0x00000018U) | (vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__data_buffer_q 
                                       >> 8U));
        } else {
            __Vdly__top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__data_valid_q 
                = (0x0000000eU & (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__data_valid_q));
        }
        if ((0U == (IData)(vlSelfRef.top__DOT__u_ulpi__DOT__utmi_linestate_q))) {
            if ((1U & (~ ((IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__se0_cnt_q) 
                          >> 0x0eU)))) {
                __Vdly__top__DOT__u_cdc__DOT__u_core__DOT__se0_cnt_q 
                    = (0x00007fffU & ((IData)(1U) + (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__se0_cnt_q)));
            }
        } else {
            __Vdly__top__DOT__u_cdc__DOT__u_core__DOT__se0_cnt_q = 0U;
        }
        if (((4U == (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__state_q)) 
             & (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__data_valid_q))) {
            __Vdly__top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__frame_num_q 
                = (0x000000ffU & vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__data_buffer_q);
        } else if (((5U == (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__state_q)) 
                    & (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__data_valid_q))) {
            __Vdly__top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__frame_num_q 
                = ((0x00000700U & (vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__data_buffer_q 
                                   << 8U)) | (0x000000ffU 
                                              & (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__frame_num_q)));
        } else if ((1U & (~ (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT____Vcellinp__u_sie_rx__enable_i)))) {
            __Vdly__top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__frame_num_q = 0U;
        }
        vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__frame_num_q 
            = __Vdly__top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__frame_num_q;
        if (vlSelfRef.top__DOT__u_ulpi__DOT__utmi_rxactive_q) {
            __Vdly__top__DOT__u_ulpi__DOT__tx_delay_q = 7U;
        } else if ((0U != (IData)(vlSelfRef.top__DOT__u_ulpi__DOT__tx_delay_q))) {
            __Vdly__top__DOT__u_ulpi__DOT__tx_delay_q 
                = (7U & ((IData)(vlSelfRef.top__DOT__u_ulpi__DOT__tx_delay_q) 
                         - (IData)(1U)));
        }
        vlSelfRef.top__DOT__u_ulpi__DOT__tx_delay_q 
            = __Vdly__top__DOT__u_ulpi__DOT__tx_delay_q;
        if (((1U == (IData)(vlSelfRef.top__DOT__u_cdc__DOT__genblk1__DOT__next_state_r)) 
             & (1U != (IData)(vlSelfRef.top__DOT__u_cdc__DOT__genblk1__DOT__state_q)))) {
            __Vdly__top__DOT__u_cdc__DOT__genblk1__DOT__usb_rst_time_q = 0U;
        } else if (((1U == (IData)(vlSelfRef.top__DOT__u_cdc__DOT__genblk1__DOT__state_q)) 
                    & (0U != (IData)(vlSelfRef.top__DOT__u_ulpi__DOT__utmi_linestate_q)))) {
            __Vdly__top__DOT__u_cdc__DOT__genblk1__DOT__usb_rst_time_q = 0U;
        } else if ((0x000fffffU != vlSelfRef.top__DOT__u_cdc__DOT__genblk1__DOT__usb_rst_time_q)) {
            __Vdly__top__DOT__u_cdc__DOT__genblk1__DOT__usb_rst_time_q 
                = (0x000fffffU & ((IData)(1U) + vlSelfRef.top__DOT__u_cdc__DOT__genblk1__DOT__usb_rst_time_q));
        }
        vlSelfRef.top__DOT__u_cdc__DOT__genblk1__DOT__usb_rst_time_q 
            = __Vdly__top__DOT__u_cdc__DOT__genblk1__DOT__usb_rst_time_q;
        if (((IData)(vlSelfRef.top__DOT__u_cdc__DOT__ep2_tx_data_last_w) 
             & (IData)(vlSelfRef.top__DOT__u_cdc__DOT__ep2_tx_data_accept_w))) {
            __Vdly__top__DOT__u_cdc__DOT__inport_cnt_q = 0U;
        } else if (((IData)(vlSelfRef.top__DOT__u_cdc__DOT__inport_valid_q) 
                    & (IData)(vlSelfRef.top__DOT__u_cdc__DOT__ep2_tx_data_accept_w))) {
            __Vdly__top__DOT__u_cdc__DOT__inport_cnt_q 
                = (0x000007ffU & ((IData)(1U) + (IData)(vlSelfRef.top__DOT__u_cdc__DOT__inport_cnt_q)));
        }
        vlSelfRef.top__DOT__u_cdc__DOT__inport_cnt_q 
            = __Vdly__top__DOT__u_cdc__DOT__inport_cnt_q;
        if ((2U == (IData)(vlSelfRef.top__DOT__u_cdc__DOT__genblk1__DOT__state_q))) {
            __Vdly__top__DOT__u_cdc__DOT__genblk1__DOT__chirp_count_q = 0U;
        } else if ((((3U == (IData)(vlSelfRef.top__DOT__u_cdc__DOT__genblk1__DOT__state_q)) 
                     & ((IData)(vlSelfRef.top__DOT__u_cdc__DOT__genblk1__DOT__last_linestate_q) 
                        != (IData)(vlSelfRef.top__DOT__u_ulpi__DOT__utmi_linestate_q))) 
                    & (0xffU != (IData)(vlSelfRef.top__DOT__u_cdc__DOT__genblk1__DOT__chirp_count_q)))) {
            __Vdly__top__DOT__u_cdc__DOT__genblk1__DOT__chirp_count_q 
                = (0x000000ffU & ((IData)(1U) + (IData)(vlSelfRef.top__DOT__u_cdc__DOT__genblk1__DOT__chirp_count_q)));
        }
        vlSelfRef.top__DOT__u_cdc__DOT__genblk1__DOT__chirp_count_q 
            = __Vdly__top__DOT__u_cdc__DOT__genblk1__DOT__chirp_count_q;
        if ((1U & ((~ (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__tx_valid_q)) 
                   | (0U == (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_tx__DOT__state_q))))) {
            __Vdly__top__DOT__u_cdc__DOT__u_core__DOT__tx_valid_q 
                = vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__tx_valid_r;
        }
        if (((IData)(vlSelfRef.top__DOT__u_ulpi__DOT__otg_update_q) 
             & ((3U == (IData)(vlSelfRef.top__DOT__u_ulpi__DOT__state_q)) 
                & ((IData)(vlSelfRef.top__DOT__u_ulpi__DOT__otg_write_q) 
                   & (IData)(vlSelfRef.top__DOT__u_ulpi__DOT____VdfgRegularize_hdd78e87c_0_2))))) {
            __Vdly__top__DOT__u_ulpi__DOT__otg_update_q = 0U;
        } else if ((((IData)(vlSelfRef.top__DOT__u_ulpi__DOT__dppulldown_q) 
                     != (IData)(vlSelfRef.top__DOT__u_cdc__DOT__genblk1__DOT__utmi_dppulldown_r)) 
                    | ((IData)(vlSelfRef.top__DOT__u_ulpi__DOT__dmpulldown_q) 
                       != (IData)(vlSelfRef.top__DOT__u_cdc__DOT__genblk1__DOT__utmi_dmpulldown_r)))) {
            __Vdly__top__DOT__u_ulpi__DOT__otg_update_q = 1U;
        }
        if (((IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_tx__DOT__utmi_txvalid_r) 
             & (IData)(vlSelfRef.top__DOT__utmi_txready_wrapper))) {
            __VdlyVal__top__DOT__u_ulpi__DOT__tx_buffer_q__v2 
                = vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_tx__DOT__utmi_data_r;
            __VdlyDim0__top__DOT__u_ulpi__DOT__tx_buffer_q__v2 
                = vlSelfRef.top__DOT__u_ulpi__DOT__tx_wr_idx_q;
            __VdlySet__top__DOT__u_ulpi__DOT__tx_buffer_q__v2 = 1U;
            __VdlyDim0__top__DOT__u_ulpi__DOT__tx_valid_q__v2 
                = vlSelfRef.top__DOT__u_ulpi__DOT__tx_wr_idx_q;
            __Vdly__top__DOT__u_ulpi__DOT__tx_wr_idx_q 
                = (1U & ((IData)(1U) + (IData)(vlSelfRef.top__DOT__u_ulpi__DOT__tx_wr_idx_q)));
        }
        if (((IData)(vlSelfRef.top__DOT__u_ulpi__DOT__utmi_tx_ready_w) 
             & ((~ (IData)(vlSelfRef.ulpi_dir)) & (
                                                   ((~ 
                                                     ((IData)(vlSelfRef.top__DOT__u_ulpi__DOT__mode_update_q) 
                                                      | ((IData)(vlSelfRef.top__DOT__u_ulpi__DOT__otg_update_q) 
                                                         | (IData)(vlSelfRef.top__DOT__u_ulpi__DOT__turnaround_w)))) 
                                                    & (0U 
                                                       == (IData)(vlSelfRef.top__DOT__u_ulpi__DOT__state_q))) 
                                                   | ((2U 
                                                       == (IData)(vlSelfRef.top__DOT__u_ulpi__DOT__state_q)) 
                                                      & (IData)(vlSelfRef.ulpi_nxt)))))) {
            __VdlyDim0__top__DOT__u_ulpi__DOT__tx_valid_q__v3 
                = vlSelfRef.top__DOT__u_ulpi__DOT__tx_rd_idx_q;
            __VdlySet__top__DOT__u_ulpi__DOT__tx_valid_q__v3 = 1U;
            __Vdly__top__DOT__u_ulpi__DOT__tx_rd_idx_q 
                = (1U & ((IData)(1U) + (IData)(vlSelfRef.top__DOT__u_ulpi__DOT__tx_rd_idx_q)));
        }
    }
    vlSelfRef.top__DOT__u_ulpi__DOT__tx_rd_idx_q = __Vdly__top__DOT__u_ulpi__DOT__tx_rd_idx_q;
    vlSelfRef.top__DOT__u_ulpi__DOT__tx_wr_idx_q = __Vdly__top__DOT__u_ulpi__DOT__tx_wr_idx_q;
    if (__VdlySet__top__DOT__u_ulpi__DOT__tx_buffer_q__v0) {
        vlSelfRef.top__DOT__u_ulpi__DOT__tx_buffer_q[0U] = 0U;
        vlSelfRef.top__DOT__u_ulpi__DOT__tx_valid_q[0U] = 0U;
    }
    if (__VdlySet__top__DOT__u_ulpi__DOT__tx_buffer_q__v1) {
        vlSelfRef.top__DOT__u_ulpi__DOT__tx_buffer_q[1U] = 0U;
        vlSelfRef.top__DOT__u_ulpi__DOT__tx_valid_q[1U] = 0U;
    }
    if (__VdlySet__top__DOT__u_ulpi__DOT__tx_buffer_q__v2) {
        vlSelfRef.top__DOT__u_ulpi__DOT__tx_buffer_q[__VdlyDim0__top__DOT__u_ulpi__DOT__tx_buffer_q__v2] 
            = __VdlyVal__top__DOT__u_ulpi__DOT__tx_buffer_q__v2;
        vlSelfRef.top__DOT__u_ulpi__DOT__tx_valid_q[__VdlyDim0__top__DOT__u_ulpi__DOT__tx_valid_q__v2] = 1U;
    }
    if (__VdlySet__top__DOT__u_ulpi__DOT__tx_valid_q__v3) {
        vlSelfRef.top__DOT__u_ulpi__DOT__tx_valid_q[__VdlyDim0__top__DOT__u_ulpi__DOT__tx_valid_q__v3] = 0U;
    }
    if ((4U & (IData)(vlSelfRef.top__DOT__rst_sync))) {
        __Vdly__top__DOT__u_cdc__DOT__desc_addr_q = 0U;
        vlSelfRef.top__DOT__u_cdc__DOT__desc_addr_q 
            = __Vdly__top__DOT__u_cdc__DOT__desc_addr_q;
        __VdlySet__top__DOT__u_cdc__DOT__setup_packet_q__v0 = 1U;
        __Vdly__top__DOT__u_cdc__DOT__setup_wr_idx_q = 0U;
        __VdlySet__top__DOT__u_cdc__DOT__setup_packet_q__v1 = 1U;
    } else {
        if (vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__rst_event_q) {
            __Vdly__top__DOT__u_cdc__DOT__desc_addr_q = 0U;
        } else if (vlSelfRef.top__DOT__u_cdc__DOT__setup_valid_q) {
            __Vdly__top__DOT__u_cdc__DOT__desc_addr_q 
                = vlSelfRef.top__DOT__u_cdc__DOT__desc_addr_r;
        } else if (((IData)(vlSelfRef.top__DOT__u_cdc__DOT__ctrl_sending_r) 
                    & (IData)(vlSelfRef.top__DOT__u_cdc__DOT__ctrl_send_accept_w))) {
            __Vdly__top__DOT__u_cdc__DOT__desc_addr_q 
                = (0x000000ffU & ((IData)(1U) + (IData)(vlSelfRef.top__DOT__u_cdc__DOT__desc_addr_q)));
        }
        vlSelfRef.top__DOT__u_cdc__DOT__desc_addr_q 
            = __Vdly__top__DOT__u_cdc__DOT__desc_addr_q;
        if (vlSelfRef.top__DOT__u_cdc__DOT__ep0_rx_setup_w) {
            __VdlySet__top__DOT__u_cdc__DOT__setup_packet_q__v8 = 1U;
            __Vdly__top__DOT__u_cdc__DOT__setup_wr_idx_q = 0U;
            __VdlySet__top__DOT__u_cdc__DOT__setup_packet_q__v9 = 1U;
        } else if (((IData)(vlSelfRef.top__DOT__u_cdc__DOT__ep0_rx_valid_w) 
                    & (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__mask_q))) {
            __VdlyVal__top__DOT__u_cdc__DOT__setup_packet_q__v16 
                = vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__data_q;
            __VdlyDim0__top__DOT__u_cdc__DOT__setup_packet_q__v16 
                = vlSelfRef.top__DOT__u_cdc__DOT__setup_wr_idx_q;
            __VdlySet__top__DOT__u_cdc__DOT__setup_packet_q__v16 = 1U;
            __Vdly__top__DOT__u_cdc__DOT__setup_wr_idx_q 
                = (7U & ((IData)(1U) + (IData)(vlSelfRef.top__DOT__u_cdc__DOT__setup_wr_idx_q)));
        }
    }
    vlSelfRef.top__DOT__u_cdc__DOT__setup_wr_idx_q 
        = __Vdly__top__DOT__u_cdc__DOT__setup_wr_idx_q;
    if (__VdlySet__top__DOT__u_cdc__DOT__setup_packet_q__v0) {
        vlSelfRef.top__DOT__u_cdc__DOT__setup_packet_q[0U] = 0U;
    }
    if (__VdlySet__top__DOT__u_cdc__DOT__setup_packet_q__v1) {
        vlSelfRef.top__DOT__u_cdc__DOT__setup_packet_q[1U] = 0U;
        vlSelfRef.top__DOT__u_cdc__DOT__setup_packet_q[2U] = 0U;
        vlSelfRef.top__DOT__u_cdc__DOT__setup_packet_q[3U] = 0U;
        vlSelfRef.top__DOT__u_cdc__DOT__setup_packet_q[4U] = 0U;
        vlSelfRef.top__DOT__u_cdc__DOT__setup_packet_q[5U] = 0U;
        vlSelfRef.top__DOT__u_cdc__DOT__setup_packet_q[6U] = 0U;
        vlSelfRef.top__DOT__u_cdc__DOT__setup_packet_q[7U] = 0U;
    }
    if (__VdlySet__top__DOT__u_cdc__DOT__setup_packet_q__v8) {
        vlSelfRef.top__DOT__u_cdc__DOT__setup_packet_q[0U] = 0U;
    }
    if (__VdlySet__top__DOT__u_cdc__DOT__setup_packet_q__v9) {
        vlSelfRef.top__DOT__u_cdc__DOT__setup_packet_q[1U] = 0U;
        vlSelfRef.top__DOT__u_cdc__DOT__setup_packet_q[2U] = 0U;
        vlSelfRef.top__DOT__u_cdc__DOT__setup_packet_q[3U] = 0U;
        vlSelfRef.top__DOT__u_cdc__DOT__setup_packet_q[4U] = 0U;
        vlSelfRef.top__DOT__u_cdc__DOT__setup_packet_q[5U] = 0U;
        vlSelfRef.top__DOT__u_cdc__DOT__setup_packet_q[6U] = 0U;
        vlSelfRef.top__DOT__u_cdc__DOT__setup_packet_q[7U] = 0U;
    }
    if (__VdlySet__top__DOT__u_cdc__DOT__setup_packet_q__v16) {
        vlSelfRef.top__DOT__u_cdc__DOT__setup_packet_q[__VdlyDim0__top__DOT__u_cdc__DOT__setup_packet_q__v16] 
            = __VdlyVal__top__DOT__u_cdc__DOT__setup_packet_q__v16;
    }
    vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__data_crc_q 
        = __Vdly__top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__data_crc_q;
    if ((4U & (IData)(vlSelfRef.top__DOT__rst_sync))) {
        __Vdly__top__DOT__u_cdc__DOT__u_core__DOT__addr_update_pending_q = 0U;
        vlSelfRef.top__DOT__u_ulpi__DOT__utmi_rxerror_q = 0U;
        vlSelfRef.top__DOT__u_cdc__DOT__status_ready_q = 0U;
        vlSelfRef.top__DOT__u_cdc__DOT__ctrl_send_idx_q = 0U;
        vlSelfRef.top__DOT__u_cdc__DOT__ctrl_send_len_q = 0U;
        vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__token_dev_q = 0U;
        vlSelfRef.top__DOT__tx_seen = 0U;
        vlSelfRef.top__DOT__u_cdc__DOT__ctrl_txdata_q = 0U;
        vlSelfRef.top__DOT__u_cdc__DOT__inport_data_q = 0U;
        vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__crc_err_q = 0U;
        vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_tx__DOT__valid_q = 0U;
        vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_tx__DOT__crc_sum_q = 0xffffU;
        vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__ep0_in_data_bit_q = 0U;
        vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__ep1_in_data_bit_q = 0U;
        vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__ep2_in_data_bit_q = 0U;
        vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__ep3_in_data_bit_q = 0U;
        vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__ep0_out_data_bit_q = 0U;
        vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__ep1_out_data_bit_q = 0U;
        vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__ep2_out_data_bit_q = 0U;
        vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__ep3_out_data_bit_q = 0U;
        vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_tx__DOT__data_pid_q = 0U;
        vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_tx__DOT__data_zlp_q = 0U;
        vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_tx__DOT__data_q = 0U;
    } else {
        if ((1U & (((((IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__sent_status_zlp_q) 
                      & (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__addr_update_pending_q)) 
                     & (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__handshake_valid_q)) 
                    & (0xd2U == (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__token_pid_q))) 
                   | ((IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__se0_cnt_q) 
                      >> 0x0000000eU)))) {
            __Vdly__top__DOT__u_cdc__DOT__u_core__DOT__addr_update_pending_q = 0U;
        } else if (((IData)(vlSelfRef.top__DOT__u_cdc__DOT__device_addr_q) 
                    != (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__current_addr_q))) {
            __Vdly__top__DOT__u_cdc__DOT__u_core__DOT__addr_update_pending_q = 1U;
        }
        if ((1U & (~ (((IData)(vlSelfRef.top__DOT__u_ulpi__DOT__turnaround_w) 
                       & (IData)(vlSelfRef.ulpi_dir)) 
                      & (IData)(vlSelfRef.ulpi_nxt))))) {
            if ((1U & (~ ((IData)(vlSelfRef.top__DOT__u_ulpi__DOT__turnaround_w) 
                          & (~ (IData)(vlSelfRef.ulpi_dir)))))) {
                if ((1U & (~ (IData)(vlSelfRef.top__DOT__u_ulpi__DOT__turnaround_w)))) {
                    if (((IData)(vlSelfRef.ulpi_dir) 
                         & (~ (IData)(vlSelfRef.ulpi_nxt)))) {
                        if ((0U == (3U & ((IData)(vlSelfRef.ulpi_data) 
                                          >> 4U)))) {
                            vlSelfRef.top__DOT__u_ulpi__DOT__utmi_rxerror_q = 0U;
                        } else if ((1U == (3U & ((IData)(vlSelfRef.ulpi_data) 
                                                 >> 4U)))) {
                            vlSelfRef.top__DOT__u_ulpi__DOT__utmi_rxerror_q = 0U;
                        } else if ((3U == (3U & ((IData)(vlSelfRef.ulpi_data) 
                                                 >> 4U)))) {
                            vlSelfRef.top__DOT__u_ulpi__DOT__utmi_rxerror_q = 1U;
                        }
                    }
                }
            }
        }
        if (vlSelfRef.top__DOT__u_cdc__DOT__ep0_rx_setup_w) {
            vlSelfRef.top__DOT__u_cdc__DOT__status_ready_q = 0U;
        } else if ((1U & (~ ((IData)(vlSelfRef.top__DOT__u_cdc__DOT__ep0_rx_valid_w) 
                             & (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__mask_q))))) {
            if ((((IData)(vlSelfRef.top__DOT__u_cdc__DOT__ep0_rx_valid_w) 
                  & (~ (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__mask_q))) 
                 & (IData)(vlSelfRef.top__DOT__u_cdc__DOT__rx_last_w))) {
                vlSelfRef.top__DOT__u_cdc__DOT__status_ready_q = 1U;
            }
        }
        if (vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__rst_event_q) {
            vlSelfRef.top__DOT__u_cdc__DOT__ctrl_send_idx_q = 0U;
            vlSelfRef.top__DOT__u_cdc__DOT__ctrl_send_len_q = 0U;
            vlSelfRef.top__DOT__u_cdc__DOT__ctrl_txdata_q = 0U;
        } else {
            vlSelfRef.top__DOT__u_cdc__DOT__ctrl_send_idx_q 
                = vlSelfRef.top__DOT__u_cdc__DOT__ctrl_send_idx_r;
            vlSelfRef.top__DOT__u_cdc__DOT__ctrl_send_len_q 
                = vlSelfRef.top__DOT__u_cdc__DOT__ctrl_send_len_r;
            vlSelfRef.top__DOT__u_cdc__DOT__ctrl_txdata_q 
                = vlSelfRef.top__DOT__u_cdc__DOT__ctrl_txdata_r;
        }
        if (((1U == (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__state_q)) 
             & (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__data_valid_q))) {
            vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__token_dev_q 
                = (0x0000007fU & vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__data_buffer_q);
        } else if ((1U & (~ (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT____Vcellinp__u_sie_rx__enable_i)))) {
            vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__token_dev_q = 0U;
        }
        if (vlSelfRef.top__DOT__ready_for_leds) {
            if (((IData)(vlSelfRef.top__DOT__tx_valid) 
                 & (IData)(vlSelfRef.top__DOT__u_adc_wrap__DOT__tx_ready))) {
                vlSelfRef.top__DOT__tx_seen = 1U;
            }
        }
        if (vlSelfRef.top__DOT__u_adc_wrap__DOT__tx_ready) {
            vlSelfRef.top__DOT__u_cdc__DOT__inport_data_q 
                = (0x000000ffU & ((IData)(vlSelfRef.top__DOT__tx_data_12b) 
                                  >> 4U));
        }
        if ((0U == (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__state_q))) {
            vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__crc_err_q = 0U;
        } else if (((7U == (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__state_q)) 
                    & (0U == (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__next_state_r)))) {
            vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__crc_err_q 
                = (0xb001U != (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__crc_sum_q));
        }
        if ((0x00004000U & (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__se0_cnt_q))) {
            vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_tx__DOT__valid_q = 0U;
            vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__ep0_in_data_bit_q = 0U;
            vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__ep0_out_data_bit_q = 0U;
            vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_tx__DOT__data_pid_q = 0U;
            vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_tx__DOT__data_zlp_q = 0U;
            vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_tx__DOT__data_q = 0U;
        } else {
            if (((IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__tx_valid_q) 
                 & (0U == (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_tx__DOT__state_q)))) {
                vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_tx__DOT__valid_q = 1U;
                vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_tx__DOT__data_pid_q 
                    = ((((0x0fU == (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__tx_pid_q)) 
                         || (0x87U == (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__tx_pid_q))) 
                        || (0xc3U == (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__tx_pid_q))) 
                       || (0x4bU == (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__tx_pid_q)));
                vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_tx__DOT__data_zlp_q 
                    = (((((0x0fU == (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__tx_pid_q)) 
                          || (0x87U == (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__tx_pid_q))) 
                         || (0xc3U == (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__tx_pid_q))) 
                        || (0x4bU == (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__tx_pid_q))) 
                       && (((IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__tx_data_valid_r) 
                            & (~ (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__tx_data_strb_r))) 
                           & (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__tx_data_last_r)));
                vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_tx__DOT__data_q 
                    = vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__tx_pid_q;
            } else {
                if (vlSelfRef.top__DOT__utmi_txready_wrapper) {
                    vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_tx__DOT__valid_q = 0U;
                    vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_tx__DOT__data_q = 0U;
                }
                if ((3U == (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_tx__DOT__next_state_r))) {
                    vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_tx__DOT__data_pid_q = 0U;
                    vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_tx__DOT__data_zlp_q = 0U;
                }
            }
            if ((0U == (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__token_ep_q))) {
                vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__ep0_in_data_bit_q 
                    = vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__new_in_bit_r;
                vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__ep0_out_data_bit_q 
                    = vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__new_out_bit_r;
            }
        }
        if ((0U == (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_tx__DOT__state_q))) {
            vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_tx__DOT__crc_sum_q = 0xffffU;
        } else if ((((2U == (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_tx__DOT__state_q)) 
                     & (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_tx__DOT__utmi_txvalid_r)) 
                    & (IData)(vlSelfRef.top__DOT__utmi_txready_wrapper))) {
            vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_tx__DOT__crc_sum_q 
                = vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_tx__DOT__u_crc16__DOT__crc_out_o;
        }
        if ((1U & (((IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__se0_cnt_q) 
                    >> 0x0000000eU) | ((IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__ep_clear_toggle_i) 
                                       >> 1U)))) {
            vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__ep1_in_data_bit_q = 0U;
            vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__ep1_out_data_bit_q = 0U;
        } else if ((1U == (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__token_ep_q))) {
            vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__ep1_in_data_bit_q 
                = vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__new_in_bit_r;
            vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__ep1_out_data_bit_q 
                = vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__new_out_bit_r;
        }
        if ((1U & (((IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__se0_cnt_q) 
                    >> 0x0000000eU) | ((IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__ep_clear_toggle_i) 
                                       >> 2U)))) {
            vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__ep2_in_data_bit_q = 0U;
            vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__ep2_out_data_bit_q = 0U;
        } else if ((2U == (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__token_ep_q))) {
            vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__ep2_in_data_bit_q 
                = vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__new_in_bit_r;
            vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__ep2_out_data_bit_q 
                = vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__new_out_bit_r;
        }
        if ((IData)((((IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__se0_cnt_q) 
                      >> 0x0000000eU) | ((IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__ep_clear_toggle_i) 
                                         >> 3U)))) {
            vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__ep3_in_data_bit_q = 0U;
            vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__ep3_out_data_bit_q = 0U;
        } else if ((3U == (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__token_ep_q))) {
            vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__ep3_in_data_bit_q 
                = vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__new_in_bit_r;
            vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__ep3_out_data_bit_q 
                = vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__new_out_bit_r;
        }
    }
    vlSelfRef.top__DOT__utmi_txready_wrapper = ((~ vlSelfRef.top__DOT__u_ulpi__DOT__tx_valid_q
                                                 [vlSelfRef.top__DOT__u_ulpi__DOT__tx_wr_idx_q]) 
                                                & (0U 
                                                   == (IData)(vlSelfRef.top__DOT__u_ulpi__DOT__tx_delay_q)));
    vlSelfRef.top__DOT__u_cdc__DOT__wIndex_w = ((vlSelfRef.top__DOT__u_cdc__DOT__setup_packet_q[5U] 
                                                 << 8U) 
                                                | vlSelfRef.top__DOT__u_cdc__DOT__setup_packet_q[4U]);
    vlSelfRef.top__DOT__u_cdc__DOT__wValue_w = ((vlSelfRef.top__DOT__u_cdc__DOT__setup_packet_q[3U] 
                                                 << 8U) 
                                                | vlSelfRef.top__DOT__u_cdc__DOT__setup_packet_q[2U]);
    vlSelfRef.top__DOT__u_cdc__DOT__wLength = ((vlSelfRef.top__DOT__u_cdc__DOT__setup_packet_q[7U] 
                                                << 8U) 
                                               | vlSelfRef.top__DOT__u_cdc__DOT__setup_packet_q[6U]);
    vlSelfRef.led_g = vlSelfRef.top__DOT__tx_seen;
    vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT____VdfgRegularize_h04591d3f_0_4 
        = ((IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__rx_enable_q) 
           & (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__valid_q));
    top__DOT__u_cdc__DOT__u_core__DOT__u_sie_tx__DOT__u_crc16__DOT____VdfgRegularize_h8075a1a5_0_5 
        = (1U & VL_REDXOR_8((0x00c0U & (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_tx__DOT__crc_sum_q))));
    top__DOT__u_cdc__DOT__u_core__DOT__u_sie_tx__DOT__u_crc16__DOT____VdfgRegularize_h8075a1a5_0_7 
        = (1U & VL_REDXOR_8((0x0030U & (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_tx__DOT__crc_sum_q))));
    top__DOT__u_cdc__DOT__u_core__DOT__u_sie_tx__DOT__u_crc16__DOT____VdfgRegularize_h8075a1a5_0_6 
        = (1U & VL_REDXOR_4((0x000cU & (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_tx__DOT__crc_sum_q))));
    top__DOT__u_cdc__DOT__u_core__DOT__u_sie_tx__DOT__u_crc16__DOT____VdfgRegularize_h8075a1a5_0_4 
        = (1U & (((IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_tx__DOT__crc_sum_q) 
                  >> 1U) ^ (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_tx__DOT__crc_sum_q)));
    vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__token_valid_q 
        = ((~ ((IData)(vlSelfRef.top__DOT__rst_sync) 
               >> 2U)) & ((3U == (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__state_q)) 
                          & (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__address_match_w)));
    if ((4U & (IData)(vlSelfRef.top__DOT__rst_sync))) {
        vlSelfRef.top__DOT__u_ulpi__DOT__utmi_rxvalid_q = 0U;
        vlSelfRef.top__DOT__u_ulpi__DOT__utmi_data_q = 0U;
        vlSelfRef.top__DOT__u_ulpi__DOT__utmi_rxactive_q = 0U;
        vlSelfRef.top__DOT__u_cdc__DOT__inport_valid_q = 0U;
        vlSelfRef.top__DOT__u_cdc__DOT__genblk1__DOT__last_linestate_q = 0U;
        __Vdly__top__DOT__u_ulpi__DOT__state_q = 0U;
        vlSelfRef.top__DOT__u_ulpi__DOT__ulpi_data_q = 0U;
        __Vdly__top__DOT__u_ulpi__DOT__data_q = 0U;
        vlSelfRef.top__DOT__u_ulpi__DOT__ulpi_stp_q = 1U;
        __Vdly__top__DOT__u_ulpi__DOT__mode_write_q = 0U;
        vlSelfRef.top__DOT__u_ulpi__DOT__otg_write_q = 0U;
    } else {
        vlSelfRef.top__DOT__u_ulpi__DOT__utmi_rxvalid_q = 0U;
        if ((1U & (~ (((IData)(vlSelfRef.top__DOT__u_ulpi__DOT__turnaround_w) 
                       & (IData)(vlSelfRef.ulpi_dir)) 
                      & (IData)(vlSelfRef.ulpi_nxt))))) {
            if ((1U & (~ ((IData)(vlSelfRef.top__DOT__u_ulpi__DOT__turnaround_w) 
                          & (~ (IData)(vlSelfRef.ulpi_dir)))))) {
                if ((1U & (~ (IData)(vlSelfRef.top__DOT__u_ulpi__DOT__turnaround_w)))) {
                    if ((1U & (~ ((IData)(vlSelfRef.ulpi_dir) 
                                  & (~ (IData)(vlSelfRef.ulpi_nxt)))))) {
                        if (((IData)(vlSelfRef.ulpi_dir) 
                             & (IData)(vlSelfRef.ulpi_nxt))) {
                            vlSelfRef.top__DOT__u_ulpi__DOT__utmi_rxvalid_q = 1U;
                            vlSelfRef.top__DOT__u_ulpi__DOT__utmi_data_q 
                                = vlSelfRef.ulpi_data;
                        }
                    }
                }
            }
        }
        if (vlSelfRef.top__DOT__u_adc_wrap__DOT__tx_ready) {
            vlSelfRef.top__DOT__u_cdc__DOT__inport_valid_q 
                = vlSelfRef.top__DOT__tx_valid;
        }
        vlSelfRef.top__DOT__u_cdc__DOT__genblk1__DOT__last_linestate_q 
            = vlSelfRef.top__DOT__u_ulpi__DOT__utmi_linestate_q;
        vlSelfRef.top__DOT__u_ulpi__DOT__ulpi_stp_q = 0U;
        if ((((IData)(vlSelfRef.top__DOT__u_ulpi__DOT__turnaround_w) 
              & (IData)(vlSelfRef.ulpi_dir)) & (IData)(vlSelfRef.ulpi_nxt))) {
            vlSelfRef.top__DOT__u_ulpi__DOT__utmi_rxactive_q = 1U;
            if ((3U == (IData)(vlSelfRef.top__DOT__u_ulpi__DOT__state_q))) {
                __Vdly__top__DOT__u_ulpi__DOT__state_q = 0U;
                vlSelfRef.top__DOT__u_ulpi__DOT__ulpi_data_q = 0U;
            }
        } else if (((IData)(vlSelfRef.top__DOT__u_ulpi__DOT__turnaround_w) 
                    & (~ (IData)(vlSelfRef.ulpi_dir)))) {
            vlSelfRef.top__DOT__u_ulpi__DOT__utmi_rxactive_q = 0U;
            if ((3U == (IData)(vlSelfRef.top__DOT__u_ulpi__DOT__state_q))) {
                __Vdly__top__DOT__u_ulpi__DOT__state_q = 0U;
                vlSelfRef.top__DOT__u_ulpi__DOT__ulpi_data_q = 0U;
            }
        } else if ((1U & (~ (IData)(vlSelfRef.top__DOT__u_ulpi__DOT__turnaround_w)))) {
            if (((IData)(vlSelfRef.ulpi_dir) & (~ (IData)(vlSelfRef.ulpi_nxt)))) {
                if ((0U == (3U & ((IData)(vlSelfRef.ulpi_data) 
                                  >> 4U)))) {
                    vlSelfRef.top__DOT__u_ulpi__DOT__utmi_rxactive_q = 0U;
                } else if ((1U == (3U & ((IData)(vlSelfRef.ulpi_data) 
                                         >> 4U)))) {
                    vlSelfRef.top__DOT__u_ulpi__DOT__utmi_rxactive_q = 1U;
                } else if ((3U == (3U & ((IData)(vlSelfRef.ulpi_data) 
                                         >> 4U)))) {
                    vlSelfRef.top__DOT__u_ulpi__DOT__utmi_rxactive_q = 1U;
                }
            }
            if ((1U & (~ ((IData)(vlSelfRef.ulpi_dir) 
                          & (~ (IData)(vlSelfRef.ulpi_nxt)))))) {
                if ((1U & (~ ((IData)(vlSelfRef.ulpi_dir) 
                              & (IData)(vlSelfRef.ulpi_nxt))))) {
                    if ((1U & (~ (IData)(vlSelfRef.ulpi_dir)))) {
                        if (((0U == (IData)(vlSelfRef.top__DOT__u_ulpi__DOT__state_q)) 
                             & (IData)(vlSelfRef.top__DOT__u_ulpi__DOT__mode_update_q))) {
                            __Vdly__top__DOT__u_ulpi__DOT__data_q 
                                = (0x00000040U | (((IData)(vlSelfRef.top__DOT__u_ulpi__DOT__phy_reset_q) 
                                                   << 5U) 
                                                  | (((IData)(vlSelfRef.top__DOT__u_ulpi__DOT__opmode_q) 
                                                      << 3U) 
                                                     | (((IData)(vlSelfRef.top__DOT__u_ulpi__DOT__termselect_q) 
                                                         << 2U) 
                                                        | (IData)(vlSelfRef.top__DOT__u_ulpi__DOT__xcvrselect_q)))));
                            vlSelfRef.top__DOT__u_ulpi__DOT__ulpi_data_q = 0x84U;
                            vlSelfRef.top__DOT__u_ulpi__DOT__otg_write_q = 0U;
                            __Vdly__top__DOT__u_ulpi__DOT__mode_write_q = 1U;
                            __Vdly__top__DOT__u_ulpi__DOT__state_q = 1U;
                        } else if (((0U == (IData)(vlSelfRef.top__DOT__u_ulpi__DOT__state_q)) 
                                    & (IData)(vlSelfRef.top__DOT__u_ulpi__DOT__otg_update_q))) {
                            __Vdly__top__DOT__u_ulpi__DOT__data_q 
                                = (((IData)(vlSelfRef.top__DOT__u_ulpi__DOT__dmpulldown_q) 
                                    << 2U) | ((IData)(vlSelfRef.top__DOT__u_ulpi__DOT__dppulldown_q) 
                                              << 1U));
                            vlSelfRef.top__DOT__u_ulpi__DOT__ulpi_data_q = 0x8aU;
                            vlSelfRef.top__DOT__u_ulpi__DOT__otg_write_q = 1U;
                            __Vdly__top__DOT__u_ulpi__DOT__mode_write_q = 0U;
                            __Vdly__top__DOT__u_ulpi__DOT__state_q = 1U;
                        } else if (((0U == (IData)(vlSelfRef.top__DOT__u_ulpi__DOT__state_q)) 
                                    & (IData)(vlSelfRef.top__DOT__u_ulpi__DOT__utmi_tx_ready_w))) {
                            vlSelfRef.top__DOT__u_ulpi__DOT__ulpi_data_q 
                                = (0x40U | (0x0000000fU 
                                            & (IData)(vlSelfRef.top__DOT__u_ulpi__DOT__utmi_tx_data_w)));
                            __Vdly__top__DOT__u_ulpi__DOT__state_q = 2U;
                        } else if (((1U == (IData)(vlSelfRef.top__DOT__u_ulpi__DOT__state_q)) 
                                    & (IData)(vlSelfRef.ulpi_nxt))) {
                            __Vdly__top__DOT__u_ulpi__DOT__state_q = 3U;
                            vlSelfRef.top__DOT__u_ulpi__DOT__ulpi_data_q 
                                = vlSelfRef.top__DOT__u_ulpi__DOT__data_q;
                        } else if (((3U == (IData)(vlSelfRef.top__DOT__u_ulpi__DOT__state_q)) 
                                    & (IData)(vlSelfRef.ulpi_nxt))) {
                            __Vdly__top__DOT__u_ulpi__DOT__state_q = 0U;
                            vlSelfRef.top__DOT__u_ulpi__DOT__ulpi_data_q = 0U;
                            vlSelfRef.top__DOT__u_ulpi__DOT__ulpi_stp_q = 1U;
                            vlSelfRef.top__DOT__u_ulpi__DOT__otg_write_q = 0U;
                            __Vdly__top__DOT__u_ulpi__DOT__mode_write_q = 0U;
                        } else if (((2U == (IData)(vlSelfRef.top__DOT__u_ulpi__DOT__state_q)) 
                                    & (IData)(vlSelfRef.ulpi_nxt))) {
                            if (vlSelfRef.top__DOT__u_ulpi__DOT__utmi_tx_ready_w) {
                                __Vdly__top__DOT__u_ulpi__DOT__state_q = 2U;
                                vlSelfRef.top__DOT__u_ulpi__DOT__ulpi_data_q 
                                    = vlSelfRef.top__DOT__u_ulpi__DOT__utmi_tx_data_w;
                            } else {
                                __Vdly__top__DOT__u_ulpi__DOT__state_q = 0U;
                                vlSelfRef.top__DOT__u_ulpi__DOT__ulpi_data_q = 0U;
                                vlSelfRef.top__DOT__u_ulpi__DOT__ulpi_stp_q = 1U;
                            }
                        }
                    }
                }
            }
        }
    }
    vlSelfRef.top__DOT__u_ulpi__DOT__data_q = __Vdly__top__DOT__u_ulpi__DOT__data_q;
    vlSelfRef.top__DOT__u_ulpi__DOT__utmi_tx_data_w 
        = vlSelfRef.top__DOT__u_ulpi__DOT__tx_buffer_q
        [vlSelfRef.top__DOT__u_ulpi__DOT__tx_rd_idx_q];
    vlSelfRef.top__DOT__u_ulpi__DOT__otg_update_q = __Vdly__top__DOT__u_ulpi__DOT__otg_update_q;
    vlSelfRef.top__DOT__u_ulpi__DOT__utmi_tx_ready_w 
        = vlSelfRef.top__DOT__u_ulpi__DOT__tx_valid_q
        [vlSelfRef.top__DOT__u_ulpi__DOT__tx_rd_idx_q];
    if ((4U & (IData)(vlSelfRef.top__DOT__rst_sync))) {
        vlSelfRef.top__DOT__u_cdc__DOT__setup_valid_q = 0U;
        vlSelfRef.top__DOT__u_cdc__DOT__setup_data_q = 0U;
        vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__data_q = 0U;
        vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__current_addr_q = 0U;
        vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__addr_update_pending_q 
            = __Vdly__top__DOT__u_cdc__DOT__u_core__DOT__addr_update_pending_q;
        vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__data_zlp_q = 0U;
        __Vdly__top__DOT__u_adc_wrap__DOT__u_dc_fifo__DOT__data_out_valid = 0U;
        __Vdly__top__DOT__u_adc_wrap__DOT__u_dc_fifo__DOT__middle_valid = 0U;
        vlSelfRef.top__DOT__tx_data_12b = 0U;
        __Vdly__top__DOT__u_adc_wrap__DOT__u_dc_fifo__DOT__middle_data = 0U;
    } else {
        if (vlSelfRef.top__DOT__u_cdc__DOT__ep0_rx_setup_w) {
            vlSelfRef.top__DOT__u_cdc__DOT__setup_valid_q = 0U;
            vlSelfRef.top__DOT__u_cdc__DOT__setup_data_q = 0U;
        } else if (((IData)(vlSelfRef.top__DOT__u_cdc__DOT__ep0_rx_valid_w) 
                    & (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__mask_q))) {
            vlSelfRef.top__DOT__u_cdc__DOT__setup_valid_q 
                = ((IData)(vlSelfRef.top__DOT__u_cdc__DOT__setup_frame_q) 
                   & (IData)(vlSelfRef.top__DOT__u_cdc__DOT__rx_last_w));
            vlSelfRef.top__DOT__u_cdc__DOT__setup_data_q 
                = ((~ (IData)(vlSelfRef.top__DOT__u_cdc__DOT__setup_frame_q)) 
                   & (IData)(vlSelfRef.top__DOT__u_cdc__DOT__rx_last_w));
        } else {
            vlSelfRef.top__DOT__u_cdc__DOT__setup_valid_q = 0U;
        }
        vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__data_q 
            = (0x000000ffU & vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__data_buffer_q);
        if ((0x00004000U & (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__se0_cnt_q))) {
            vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__current_addr_q = 0U;
        } else if (((((IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__sent_status_zlp_q) 
                      & (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__addr_update_pending_q)) 
                     & (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__handshake_valid_q)) 
                    & (0xd2U == (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__token_pid_q)))) {
            vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__current_addr_q 
                = vlSelfRef.top__DOT__u_cdc__DOT__device_addr_q;
        }
        vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__addr_update_pending_q 
            = __Vdly__top__DOT__u_cdc__DOT__u_core__DOT__addr_update_pending_q;
        if (((0U == (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__state_q)) 
             & (6U == (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__next_state_r)))) {
            vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__data_zlp_q = 1U;
        } else if (vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__input_ready_w) {
            vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__data_zlp_q = 0U;
        }
        if (((IData)(vlSelfRef.top__DOT__u_adc_wrap__DOT__u_dc_fifo__DOT__rd_ena) 
             & (IData)(vlSelfRef.top__DOT__u_adc_wrap__DOT__u_dc_fifo__DOT__data_out_valid))) {
            if (vlSelfRef.top__DOT__u_adc_wrap__DOT__u_dc_fifo__DOT__middle_valid) {
                vlSelfRef.top__DOT__tx_data_12b = vlSelfRef.top__DOT__u_adc_wrap__DOT__u_dc_fifo__DOT__middle_data;
                __Vdly__top__DOT__u_adc_wrap__DOT__u_dc_fifo__DOT__middle_valid = 0U;
                __Vdly__top__DOT__u_adc_wrap__DOT__u_dc_fifo__DOT__data_out_valid = 1U;
                if (vlSelfRef.top__DOT__u_adc_wrap__DOT__u_dc_fifo__DOT__fall_through) {
                    __Vdly__top__DOT__u_adc_wrap__DOT__u_dc_fifo__DOT__middle_data 
                        = vlSelfRef.top__DOT__u_adc_wrap__DOT__u_dc_fifo__DOT__std_rd_data;
                    __Vdly__top__DOT__u_adc_wrap__DOT__u_dc_fifo__DOT__middle_valid = 1U;
                }
            } else if (vlSelfRef.top__DOT__u_adc_wrap__DOT__u_dc_fifo__DOT__fall_through) {
                vlSelfRef.top__DOT__tx_data_12b = vlSelfRef.top__DOT__u_adc_wrap__DOT__u_dc_fifo__DOT__std_rd_data;
                __Vdly__top__DOT__u_adc_wrap__DOT__u_dc_fifo__DOT__data_out_valid = 1U;
            } else {
                __Vdly__top__DOT__u_adc_wrap__DOT__u_dc_fifo__DOT__data_out_valid = 0U;
            }
        } else if (((~ (IData)(vlSelfRef.top__DOT__u_adc_wrap__DOT__u_dc_fifo__DOT__data_out_valid)) 
                    & (IData)(vlSelfRef.top__DOT__u_adc_wrap__DOT__u_dc_fifo__DOT__fall_through))) {
            vlSelfRef.top__DOT__tx_data_12b = vlSelfRef.top__DOT__u_adc_wrap__DOT__u_dc_fifo__DOT__std_rd_data;
            __Vdly__top__DOT__u_adc_wrap__DOT__u_dc_fifo__DOT__data_out_valid = 1U;
        } else if ((((IData)(vlSelfRef.top__DOT__u_adc_wrap__DOT__u_dc_fifo__DOT__data_out_valid) 
                     & (IData)(vlSelfRef.top__DOT__u_adc_wrap__DOT__u_dc_fifo__DOT__fall_through)) 
                    & (~ (IData)(vlSelfRef.top__DOT__u_adc_wrap__DOT__u_dc_fifo__DOT__middle_valid)))) {
            __Vdly__top__DOT__u_adc_wrap__DOT__u_dc_fifo__DOT__middle_data 
                = vlSelfRef.top__DOT__u_adc_wrap__DOT__u_dc_fifo__DOT__std_rd_data;
            __Vdly__top__DOT__u_adc_wrap__DOT__u_dc_fifo__DOT__middle_valid = 1U;
        }
    }
    vlSelfRef.top__DOT__u_adc_wrap__DOT__u_dc_fifo__DOT__middle_data 
        = __Vdly__top__DOT__u_adc_wrap__DOT__u_dc_fifo__DOT__middle_data;
    vlSelfRef.top__DOT__u_adc_wrap__DOT__u_dc_fifo__DOT__middle_valid 
        = __Vdly__top__DOT__u_adc_wrap__DOT__u_dc_fifo__DOT__middle_valid;
    top__DOT__u_cdc__DOT__u_core__DOT__u_sie_tx__DOT__u_crc16__DOT____VdfgRegularize_h8075a1a5_0_8 
        = ((IData)(top__DOT__u_cdc__DOT__u_core__DOT__u_sie_tx__DOT__u_crc16__DOT____VdfgRegularize_h8075a1a5_0_7) 
           ^ ((IData)(top__DOT__u_cdc__DOT__u_core__DOT__u_sie_tx__DOT__u_crc16__DOT____VdfgRegularize_h8075a1a5_0_6) 
              ^ (IData)(top__DOT__u_cdc__DOT__u_core__DOT__u_sie_tx__DOT__u_crc16__DOT____VdfgRegularize_h8075a1a5_0_4)));
    if ((4U & (IData)(vlSelfRef.top__DOT__rst_sync))) {
        vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__crc_sum_q = 0xffffU;
        vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__rx_space_q = 0U;
        vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__tx_pid_q = 0U;
    } else {
        if ((0U == (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__state_q))) {
            vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__crc_sum_q = 0xffffU;
        } else if ((1U & (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__data_valid_q))) {
            vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__crc_sum_q 
                = vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__u_crc16__DOT__crc_out_o;
        }
        if ((0U == (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__state_q))) {
            vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__rx_space_q 
                = vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__rx_space_r;
        }
        if ((1U & ((~ (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__tx_valid_q)) 
                   | (0U == (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_tx__DOT__state_q))))) {
            vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__tx_pid_q 
                = vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__tx_pid_r;
        }
    }
    vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__tx_valid_q 
        = __Vdly__top__DOT__u_cdc__DOT__u_core__DOT__tx_valid_q;
    vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__shift_en_w 
        = (1U & ((~ (IData)(vlSelfRef.top__DOT__u_ulpi__DOT__utmi_rxactive_q)) 
                 | ((IData)(vlSelfRef.top__DOT__u_ulpi__DOT__utmi_rxactive_q) 
                    & (IData)(vlSelfRef.top__DOT__u_ulpi__DOT__utmi_rxvalid_q))));
    vlSelfRef.ulpi_stp = vlSelfRef.top__DOT__u_ulpi__DOT__ulpi_stp_q;
    vlSelfRef.top__DOT__u_ulpi__DOT__dmpulldown_q = 
        ((1U & ((IData)(vlSelfRef.top__DOT__rst_sync) 
                >> 2U)) || (IData)(vlSelfRef.top__DOT__u_cdc__DOT__genblk1__DOT__utmi_dmpulldown_r));
    vlSelfRef.top__DOT__u_ulpi__DOT__dppulldown_q = 
        ((1U & ((IData)(vlSelfRef.top__DOT__rst_sync) 
                >> 2U)) || (IData)(vlSelfRef.top__DOT__u_cdc__DOT__genblk1__DOT__utmi_dppulldown_r));
    vlSelfRef.top__DOT__u_cdc__DOT__setup_set_w = (
                                                   (~ 
                                                    (vlSelfRef.top__DOT__u_cdc__DOT__setup_packet_q[0U] 
                                                     >> 7U)) 
                                                   & (IData)(vlSelfRef.top__DOT__u_cdc__DOT__setup_valid_q));
    vlSelfRef.top__DOT__u_adc_wrap__DOT__u_dc_fifo__DOT__fall_through 
        = ((1U & (~ ((IData)(vlSelfRef.top__DOT__rst_sync) 
                     >> 2U))) && (IData)(vlSelfRef.top__DOT__u_adc_wrap__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__u_dpdcram__DOT__rd_ena));
    top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__u_crc16__DOT____VdfgRegularize_h8075a1a5_0_5 
        = (1U & VL_REDXOR_8((0x00c0U & (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__crc_sum_q))));
    top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__u_crc16__DOT____VdfgRegularize_h8075a1a5_0_7 
        = (1U & VL_REDXOR_8((0x0030U & (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__crc_sum_q))));
    top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__u_crc16__DOT____VdfgRegularize_h8075a1a5_0_6 
        = (1U & VL_REDXOR_4((0x000cU & (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__crc_sum_q))));
    top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__u_crc16__DOT____VdfgRegularize_h8075a1a5_0_4 
        = (1U & (((IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__crc_sum_q) 
                  >> 1U) ^ (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__crc_sum_q)));
    vlSelfRef.top__DOT__u_cdc__DOT__genblk1__DOT__state_q 
        = ((4U & (IData)(vlSelfRef.top__DOT__rst_sync))
            ? 0U : (IData)(vlSelfRef.top__DOT__u_cdc__DOT__genblk1__DOT__next_state_r));
    __Vtableidx4 = (((5U == (IData)(vlSelfRef.top__DOT__u_cdc__DOT__genblk1__DOT__state_q)) 
                     << 8U) | (IData)(vlSelfRef.top__DOT__u_cdc__DOT__desc_addr_q));
    vlSelfRef.top__DOT__u_cdc__DOT__u_rom__DOT__desc_rom_r 
        = Vtop__ConstPool__TABLE_h84190edb_0[__Vtableidx4];
    vlSelfRef.top__DOT__u_cdc__DOT__ep2_tx_data_last_w 
        = ((IData)(vlSelfRef.top__DOT__u_cdc__DOT__inport_cnt_q) 
           == ((5U == (IData)(vlSelfRef.top__DOT__u_cdc__DOT__genblk1__DOT__state_q))
                ? 0x01ffU : 0x003fU));
    if ((4U & (IData)(vlSelfRef.top__DOT__rst_sync))) {
        vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__token_ep_q = 0U;
    } else if (((1U == (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__state_q)) 
                & (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__data_valid_q))) {
        vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__token_ep_q 
            = ((0x0eU & (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__token_ep_q)) 
               | (1U & (vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__data_buffer_q 
                        >> 7U)));
    } else if (((2U == (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__state_q)) 
                & (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__data_valid_q))) {
        vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__token_ep_q 
            = ((1U & (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__token_ep_q)) 
               | (0x0000000eU & (vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__data_buffer_q 
                                 << 1U)));
    } else if ((1U & (~ (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT____Vcellinp__u_sie_rx__enable_i)))) {
        vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__token_ep_q = 0U;
    }
    __Vtableidx1 = vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__token_ep_q;
    vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__cfg_int_rx_r 
        = Vtop__ConstPool__TABLE_hae65a50a_0[__Vtableidx1];
    vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__cfg_int_tx_r 
        = Vtop__ConstPool__TABLE_hae65a50a_0[__Vtableidx1];
    vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__in_data_bit_r = 0U;
    vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__rx_space_r = 0U;
    vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__ep_stall_r = 0U;
    vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__out_data_bit_r = 0U;
    vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__ep_iso_r = 0U;
    vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__tx_data_r = 0U;
    if ((4U & (IData)(vlSelfRef.top__DOT__rst_sync))) {
        __Vdly__top__DOT__u_adc_wrap__DOT__burst_count = 0U;
        vlSelfRef.top__DOT__tx_valid = 0U;
        vlSelfRef.top__DOT__u_adc_wrap__DOT__burst_count 
            = __Vdly__top__DOT__u_adc_wrap__DOT__burst_count;
        vlSelfRef.top__DOT__u_adc_wrap__DOT__u_dc_fifo__DOT__data_out_valid 
            = __Vdly__top__DOT__u_adc_wrap__DOT__u_dc_fifo__DOT__data_out_valid;
        vlSelfRef.top__DOT__u_ulpi__DOT__utmi_linestate_q = 0U;
    } else {
        if (vlSelfRef.top__DOT__ready_for_leds) {
            if (vlSelfRef.top__DOT__u_adc_wrap__DOT__current_state) {
                if (vlSelfRef.top__DOT__u_adc_wrap__DOT__byte_sent) {
                    __Vdly__top__DOT__u_adc_wrap__DOT__burst_count 
                        = (0x000003ffU & ((IData)(1U) 
                                          + (IData)(vlSelfRef.top__DOT__u_adc_wrap__DOT__burst_count)));
                }
                vlSelfRef.top__DOT__tx_valid = ((IData)(vlSelfRef.top__DOT__u_adc_wrap__DOT__next_state) 
                                                && ((IData)(vlSelfRef.top__DOT__u_adc_wrap__DOT__u_dc_fifo__DOT__data_out_valid) 
                                                    & (IData)(vlSelfRef.top__DOT__ready_for_leds)));
            } else {
                __Vdly__top__DOT__u_adc_wrap__DOT__burst_count = 0U;
                vlSelfRef.top__DOT__tx_valid = 0U;
            }
        } else {
            __Vdly__top__DOT__u_adc_wrap__DOT__burst_count = 0U;
            vlSelfRef.top__DOT__tx_valid = 0U;
        }
        vlSelfRef.top__DOT__u_adc_wrap__DOT__burst_count 
            = __Vdly__top__DOT__u_adc_wrap__DOT__burst_count;
        vlSelfRef.top__DOT__u_adc_wrap__DOT__u_dc_fifo__DOT__data_out_valid 
            = __Vdly__top__DOT__u_adc_wrap__DOT__u_dc_fifo__DOT__data_out_valid;
        if ((1U & (~ (((IData)(vlSelfRef.top__DOT__u_ulpi__DOT__turnaround_w) 
                       & (IData)(vlSelfRef.ulpi_dir)) 
                      & (IData)(vlSelfRef.ulpi_nxt))))) {
            if ((1U & (~ ((IData)(vlSelfRef.top__DOT__u_ulpi__DOT__turnaround_w) 
                          & (~ (IData)(vlSelfRef.ulpi_dir)))))) {
                if ((1U & (~ (IData)(vlSelfRef.top__DOT__u_ulpi__DOT__turnaround_w)))) {
                    if (((IData)(vlSelfRef.ulpi_dir) 
                         & (~ (IData)(vlSelfRef.ulpi_nxt)))) {
                        vlSelfRef.top__DOT__u_ulpi__DOT__utmi_linestate_q 
                            = (3U & (IData)(vlSelfRef.ulpi_data));
                    }
                }
            }
        }
    }
    vlSelfRef.ulpi_data = (((IData)(vlSelfRef.ulpi_dir)
                             ? 0U : 0xffU) & (((IData)(vlSelfRef.ulpi_dir)
                                                ? 0U
                                                : (IData)(vlSelfRef.top__DOT__u_ulpi__DOT__ulpi_data_q)) 
                                              & ((IData)(vlSelfRef.ulpi_dir)
                                                  ? 0U
                                                  : 0xffU)));
    vlSelfRef.top__DOT__u_ulpi__DOT__turnaround_w = 
        ((IData)(vlSelfRef.top__DOT__u_ulpi__DOT__ulpi_dir_q) 
         ^ (IData)(vlSelfRef.ulpi_dir));
    vlSelfRef.top__DOT__u_cdc__DOT__genblk1__DOT__utmi_dmpulldown_r = 0U;
    vlSelfRef.top__DOT__u_cdc__DOT__genblk1__DOT__utmi_dppulldown_r = 0U;
    if ((4U & (IData)(vlSelfRef.top__DOT__rst_sync))) {
        __Vdly__top__DOT__u_ulpi__DOT__mode_update_q = 0U;
        vlSelfRef.top__DOT__u_ulpi__DOT__phy_reset_q = 0U;
        vlSelfRef.top__DOT__u_ulpi__DOT__mode_write_q 
            = __Vdly__top__DOT__u_ulpi__DOT__mode_write_q;
        vlSelfRef.top__DOT__u_ulpi__DOT__mode_update_q 
            = __Vdly__top__DOT__u_ulpi__DOT__mode_update_q;
        vlSelfRef.top__DOT__u_ulpi__DOT__state_q = __Vdly__top__DOT__u_ulpi__DOT__state_q;
        vlSelfRef.top__DOT__u_cdc__DOT__setup_frame_q = 0U;
    } else {
        if (((IData)(vlSelfRef.top__DOT__u_ulpi__DOT__mode_update_q) 
             & ((3U == (IData)(vlSelfRef.top__DOT__u_ulpi__DOT__state_q)) 
                & ((IData)(vlSelfRef.top__DOT__u_ulpi__DOT__mode_write_q) 
                   & (IData)(vlSelfRef.top__DOT__u_ulpi__DOT____VdfgRegularize_hdd78e87c_0_2))))) {
            __Vdly__top__DOT__u_ulpi__DOT__mode_update_q = 0U;
            vlSelfRef.top__DOT__u_ulpi__DOT__phy_reset_q = 0U;
        } else if (((((IData)(vlSelfRef.top__DOT__u_ulpi__DOT__opmode_q) 
                      != (IData)(vlSelfRef.top__DOT__u_cdc__DOT__genblk1__DOT__utmi_op_mode_r)) 
                     | ((IData)(vlSelfRef.top__DOT__u_ulpi__DOT__termselect_q) 
                        != (IData)(vlSelfRef.top__DOT__u_cdc__DOT__genblk1__DOT__utmi_termselect_r))) 
                    | ((IData)(vlSelfRef.top__DOT__u_ulpi__DOT__xcvrselect_q) 
                       != (IData)(vlSelfRef.top__DOT__u_cdc__DOT__genblk1__DOT__utmi_xcvrselect_r)))) {
            __Vdly__top__DOT__u_ulpi__DOT__mode_update_q = 1U;
        }
        vlSelfRef.top__DOT__u_ulpi__DOT__mode_write_q 
            = __Vdly__top__DOT__u_ulpi__DOT__mode_write_q;
        vlSelfRef.top__DOT__u_ulpi__DOT__mode_update_q 
            = __Vdly__top__DOT__u_ulpi__DOT__mode_update_q;
        vlSelfRef.top__DOT__u_ulpi__DOT__state_q = __Vdly__top__DOT__u_ulpi__DOT__state_q;
        if (vlSelfRef.top__DOT__u_cdc__DOT__ep0_rx_setup_w) {
            vlSelfRef.top__DOT__u_cdc__DOT__setup_frame_q = 1U;
        } else if (((IData)(vlSelfRef.top__DOT__u_cdc__DOT__ep0_rx_valid_w) 
                    & (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__mask_q))) {
            if (vlSelfRef.top__DOT__u_cdc__DOT__rx_last_w) {
                vlSelfRef.top__DOT__u_cdc__DOT__setup_frame_q = 0U;
            }
        }
    }
    vlSelfRef.top__DOT__u_cdc__DOT__ep0_rx_setup_w 
        = ((IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__rx_setup_q) 
           & (0U == (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__token_ep_q)));
    vlSelfRef.top__DOT__u_cdc__DOT__ep0_rx_valid_w 
        = ((IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT____VdfgRegularize_h04591d3f_0_4) 
           & (0U == (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__token_ep_q)));
    vlSelfRef.top__DOT__u_cdc__DOT__rx_last_w = (1U 
                                                 & ((IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__last_q) 
                                                    | (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__data_crc_q)));
    vlSelfRef.top__DOT__u_cdc__DOT__setup_no_data_w 
        = ((IData)(vlSelfRef.top__DOT__u_cdc__DOT__setup_set_w) 
           & (0U == (IData)(vlSelfRef.top__DOT__u_cdc__DOT__wLength)));
    top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__u_crc16__DOT____VdfgRegularize_h8075a1a5_0_8 
        = ((IData)(top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__u_crc16__DOT____VdfgRegularize_h8075a1a5_0_7) 
           ^ ((IData)(top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__u_crc16__DOT____VdfgRegularize_h8075a1a5_0_6) 
              ^ (IData)(top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__u_crc16__DOT____VdfgRegularize_h8075a1a5_0_4)));
    vlSelfRef.top__DOT__u_adc_wrap__DOT__current_state 
        = ((1U & (~ ((IData)(vlSelfRef.top__DOT__rst_sync) 
                     >> 2U))) && ((IData)(vlSelfRef.top__DOT__ready_for_leds) 
                                  && (IData)(vlSelfRef.top__DOT__u_adc_wrap__DOT__next_state)));
    vlSelfRef.top__DOT__u_ulpi__DOT__termselect_q = 
        ((1U & (~ ((IData)(vlSelfRef.top__DOT__rst_sync) 
                   >> 2U))) && (IData)(vlSelfRef.top__DOT__u_cdc__DOT__genblk1__DOT__utmi_termselect_r));
    vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__mask_q 
        = ((1U & (~ ((IData)(vlSelfRef.top__DOT__rst_sync) 
                     >> 2U))) && (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__input_ready_w));
    top__DOT__u_cdc__DOT____VdfgExtracted_h9796ed88__0 
        = ((IData)(vlSelfRef.top__DOT__u_cdc__DOT__setup_set_w) 
           & (IData)(vlSelfRef.top__DOT__u_cdc__DOT__setup_no_data_w));
    if ((4U & (IData)(vlSelfRef.top__DOT__rst_sync))) {
        vlSelfRef.top__DOT__u_cdc__DOT__device_addr_q = 0U;
        vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__token_pid_q = 0U;
        vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__sent_status_zlp_q = 0U;
    } else {
        vlSelfRef.top__DOT__u_cdc__DOT__device_addr_q 
            = ((IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__rst_event_q)
                ? 0U : (IData)(vlSelfRef.top__DOT__u_cdc__DOT__device_addr_r));
        if (((0U == (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__state_q)) 
             & (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__data_valid_q))) {
            vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__token_pid_q 
                = (0x000000ffU & vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__data_buffer_q);
        } else if ((1U & (~ (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT____Vcellinp__u_sie_rx__enable_i)))) {
            vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__token_pid_q = 0U;
        }
        if ((0x00004000U & (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__se0_cnt_q))) {
            vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__sent_status_zlp_q = 0U;
        } else if (((~ (IData)(vlSelfRef.top__DOT__u_cdc__DOT__ctrl_txstrb_q)) 
                    & ((IData)(vlSelfRef.top__DOT__u_cdc__DOT__ctrl_txvalid_q) 
                       & ((IData)(vlSelfRef.top__DOT__u_cdc__DOT__ctrl_txlast_q) 
                          & (IData)(vlSelfRef.top__DOT__u_cdc__DOT__ep0_tx_data_accept_w))))) {
            vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__sent_status_zlp_q = 1U;
        } else if (vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__handshake_valid_q) {
            vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__sent_status_zlp_q = 0U;
        }
    }
    vlSelfRef.top__DOT__u_cdc__DOT__ctrl_txstrb_q = 
        ((1U & (~ ((IData)(vlSelfRef.top__DOT__rst_sync) 
                   >> 2U))) && ((1U & (~ (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__rst_event_q))) 
                                && (IData)(vlSelfRef.top__DOT__u_cdc__DOT__ctrl_txstrb_r)));
    vlSelfRef.top__DOT__u_cdc__DOT__ctrl_txlast_q = 
        ((1U & (~ ((IData)(vlSelfRef.top__DOT__rst_sync) 
                   >> 2U))) && ((1U & (~ (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__rst_event_q))) 
                                && (IData)(vlSelfRef.top__DOT__u_cdc__DOT__ctrl_txlast_r)));
    vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__handshake_valid_q 
        = ((1U & (~ ((IData)(vlSelfRef.top__DOT__rst_sync) 
                     >> 2U))) && (((0U == (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__state_q)) 
                                   & (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__data_valid_q)) 
                                  && (((((0xd2U == 
                                          (0x000000ffU 
                                           & vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__data_buffer_q)) 
                                         || (0x5aU 
                                             == (0x000000ffU 
                                                 & vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__data_buffer_q))) 
                                        || (0x1eU == 
                                            (0x000000ffU 
                                             & vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__data_buffer_q))) 
                                       || (0x96U == 
                                           (0x000000ffU 
                                            & vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__data_buffer_q))) 
                                      && (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__address_match_w))));
    if ((4U & (IData)(vlSelfRef.top__DOT__rst_sync))) {
        vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__state_q = 0U;
        vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_tx__DOT__state_q = 0U;
        vlSelfRef.top__DOT__u_ulpi__DOT__opmode_q = 3U;
        vlSelfRef.top__DOT__u_ulpi__DOT__xcvrselect_q = 0U;
        vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__state_q = 0U;
    } else {
        vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__state_q 
            = vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__next_state_r;
        vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_tx__DOT__state_q 
            = vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_tx__DOT__next_state_r;
        vlSelfRef.top__DOT__u_ulpi__DOT__opmode_q = vlSelfRef.top__DOT__u_cdc__DOT__genblk1__DOT__utmi_op_mode_r;
        vlSelfRef.top__DOT__u_ulpi__DOT__xcvrselect_q 
            = vlSelfRef.top__DOT__u_cdc__DOT__genblk1__DOT__utmi_xcvrselect_r;
        vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__state_q 
            = ((IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT____Vcellinp__u_sie_rx__enable_i)
                ? (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__next_state_r)
                : 0U);
    }
    vlSelfRef.top__DOT__u_cdc__DOT__ctrl_txvalid_q 
        = ((1U & (~ ((IData)(vlSelfRef.top__DOT__rst_sync) 
                     >> 2U))) && ((1U & (~ (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__rst_event_q))) 
                                  && (IData)(vlSelfRef.top__DOT__u_cdc__DOT__ctrl_txvalid_r)));
    __Vtableidx2 = vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__state_q;
    vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__dbg_state[0U] 
        = Vtop__ConstPool__TABLE_h646b3b33_0[__Vtableidx2][0U];
    vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__dbg_state[1U] 
        = Vtop__ConstPool__TABLE_h646b3b33_0[__Vtableidx2][1U];
    vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__dbg_state[2U] 
        = Vtop__ConstPool__TABLE_h646b3b33_0[__Vtableidx2][2U];
    vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__tx_valid_r = 0U;
    if ((1U & (~ ((IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__token_ep_q) 
                  >> 3U)))) {
        if ((1U & (~ ((IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__token_ep_q) 
                      >> 2U)))) {
            if ((2U & (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__token_ep_q))) {
                if ((1U & (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__token_ep_q))) {
                    vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__in_data_bit_r 
                        = vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__ep3_in_data_bit_q;
                    vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__out_data_bit_r 
                        = vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__ep3_out_data_bit_q;
                } else {
                    vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__in_data_bit_r 
                        = vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__ep2_in_data_bit_q;
                    vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__out_data_bit_r 
                        = vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__ep2_out_data_bit_q;
                }
                vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__ep_stall_r 
                    = ((1U & (~ (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__token_ep_q))) 
                       && (IData)(vlSelfRef.top__DOT__u_cdc__DOT__ep2_tx_stall_w));
            } else {
                if ((1U & (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__token_ep_q))) {
                    vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__in_data_bit_r 
                        = vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__ep1_in_data_bit_q;
                    vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__out_data_bit_r 
                        = vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__ep1_out_data_bit_q;
                } else {
                    vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__in_data_bit_r 
                        = vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__ep0_in_data_bit_q;
                    vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__out_data_bit_r 
                        = vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__ep0_out_data_bit_q;
                }
                vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__ep_stall_r 
                    = ((1U & (~ (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__token_ep_q))) 
                       && (IData)(vlSelfRef.top__DOT__u_cdc__DOT__ctrl_txstall_q));
            }
            vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__rx_space_r 
                = (1U & (~ ((IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__token_ep_q) 
                            >> 1U)));
            vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__ep_iso_r = 0U;
        }
    }
    vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__new_out_bit_r 
        = vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__out_data_bit_r;
    if ((2U == (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__state_q))) {
        if (vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__data_complete_q) {
            if ((1U & (~ (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__crc_err_q)))) {
                if ((1U & (~ (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__ep_iso_r)))) {
                    if ((1U & (~ (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__ep_stall_r)))) {
                        if ((1U & (~ (((0xc3U == (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__token_pid_q)) 
                                       & (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__out_data_bit_r)) 
                                      | ((0x4bU == (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__token_pid_q)) 
                                         & (~ (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__out_data_bit_r))))))) {
                            if (vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__rx_space_q) {
                                vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__new_out_bit_r 
                                    = (1U & (~ (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__out_data_bit_r)));
                            }
                        }
                    }
                }
            }
        }
    } else if ((0U == (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__state_q))) {
        if (vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__token_valid_q) {
            if ((0x2dU == (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__token_pid_q))) {
                vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__new_out_bit_r = 0U;
            }
        }
    }
    vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__tx_data_accept_w 
        = ((2U == (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_tx__DOT__state_q))
            ? (IData)(vlSelfRef.top__DOT__utmi_txready_wrapper)
            : ((1U == (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_tx__DOT__state_q)) 
               & ((IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_tx__DOT__data_zlp_q) 
                  & (IData)(vlSelfRef.top__DOT__utmi_txready_wrapper))));
    if ((1U & (~ ((IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__token_ep_q) 
                  >> 3U)))) {
        if ((1U & (~ ((IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__token_ep_q) 
                      >> 2U)))) {
            vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__tx_data_r 
                = ((2U & (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__token_ep_q))
                    ? ((1U & (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__token_ep_q))
                        ? 0U : (IData)(vlSelfRef.top__DOT__u_cdc__DOT__inport_data_q))
                    : ((1U & (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__token_ep_q))
                        ? 0U : (IData)(vlSelfRef.top__DOT__u_cdc__DOT__ctrl_txdata_q)));
        }
    }
    vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_tx__DOT__utmi_data_r 
        = ((6U == (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_tx__DOT__state_q))
            ? 0U : (0x000000ffU & ((3U == (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_tx__DOT__state_q))
                                    ? (~ (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_tx__DOT__crc_sum_q))
                                    : ((4U == (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_tx__DOT__state_q))
                                        ? (~ ((IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_tx__DOT__crc_sum_q) 
                                              >> 8U))
                                        : ((2U == (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_tx__DOT__state_q))
                                            ? (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__tx_data_r)
                                            : (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_tx__DOT__data_q))))));
    vlSelfRef.top__DOT__ready_for_leds = __Vdly__top__DOT__ready_for_leds;
    vlSelfRef.top__DOT__u_cdc__DOT__genblk1__DOT__utmi_op_mode_r = 1U;
    vlSelfRef.top__DOT__u_cdc__DOT__genblk1__DOT__utmi_termselect_r = 0U;
    vlSelfRef.top__DOT__u_cdc__DOT__genblk1__DOT__utmi_xcvrselect_r = 0U;
    vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__address_match_w 
        = ((IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__current_addr_q) 
           == (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__token_dev_q));
    vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__data_valid_q 
        = __Vdly__top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__data_valid_q;
    vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__data_buffer_q 
        = __Vdly__top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__data_buffer_q;
    vlSelfRef.top__DOT__u_cdc__DOT__ep2_tx_data_accept_w 
        = ((IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__tx_data_accept_w) 
           & (2U == (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__token_ep_q)));
    vlSelfRef.top__DOT__u_cdc__DOT__ep0_tx_data_accept_w 
        = ((IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__tx_data_accept_w) 
           & (0U == (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__token_ep_q)));
    top__DOT__u_cdc__DOT__u_core__DOT__u_sie_tx__DOT__u_crc16__DOT____VdfgRegularize_h8075a1a5_0_2 
        = (1U & VL_REDXOR_8((0x60U & (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_tx__DOT__utmi_data_r))));
    top__DOT__u_cdc__DOT__u_core__DOT__u_sie_tx__DOT__u_crc16__DOT____VdfgRegularize_h8075a1a5_0_3 
        = (1U & VL_REDXOR_8((0x18U & (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_tx__DOT__utmi_data_r))));
    top__DOT__u_cdc__DOT__u_core__DOT__u_sie_tx__DOT__u_crc16__DOT____VdfgRegularize_h8075a1a5_0_0 
        = (1U & ((IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_tx__DOT__utmi_data_r) 
                 ^ ((IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_tx__DOT__utmi_data_r) 
                    >> 1U)));
    vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__tx_data_strb_r = 0U;
    vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__tx_data_last_r = 0U;
    vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__new_in_bit_r 
        = vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__in_data_bit_r;
    if ((2U != (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__state_q))) {
        if ((0U == (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__state_q))) {
            if (vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__token_valid_q) {
                if ((0x2dU == (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__token_pid_q))) {
                    vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__new_in_bit_r = 1U;
                }
            } else if (((IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__handshake_valid_q) 
                        & (0xd2U == (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__token_pid_q)))) {
                vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__new_in_bit_r 
                    = (1U & (~ (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__in_data_bit_r)));
            }
        }
    }
    vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__dbg_pid[0U] = 0x0000002dU;
    vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__dbg_pid[1U] = 0U;
    vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__dbg_pid[2U] = 0U;
    vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__dbg_pid_r 
        = (((IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__tx_valid_q) 
            & (0U == (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_tx__DOT__state_q)))
            ? (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__tx_pid_q)
            : ((((IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__token_valid_q) 
                 | (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__handshake_valid_q)) 
                | (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__valid_q))
                ? (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__token_pid_q)
                : 0U));
    if ((0x00000080U & (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__dbg_pid_r))) {
        if ((0x00000040U & (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__dbg_pid_r))) {
            if ((0x00000020U & (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__dbg_pid_r))) {
                if ((1U & (~ ((IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__dbg_pid_r) 
                              >> 4U)))) {
                    if ((1U & (~ ((IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__dbg_pid_r) 
                                  >> 3U)))) {
                        if ((1U & (~ ((IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__dbg_pid_r) 
                                      >> 2U)))) {
                            if ((1U & (~ ((IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__dbg_pid_r) 
                                          >> 1U)))) {
                                if ((1U & (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__dbg_pid_r))) {
                                    vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__dbg_pid[0U] = 0x004f5554U;
                                    vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__dbg_pid[1U] = 0U;
                                    vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__dbg_pid[2U] = 0U;
                                }
                            }
                        }
                    }
                }
            } else if ((0x00000010U & (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__dbg_pid_r))) {
                if ((1U & (~ ((IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__dbg_pid_r) 
                              >> 3U)))) {
                    if ((1U & (~ ((IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__dbg_pid_r) 
                                  >> 2U)))) {
                        if ((2U & (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__dbg_pid_r))) {
                            if ((1U & (~ (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__dbg_pid_r)))) {
                                vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__dbg_pid[0U] = 0x0041434bU;
                                vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__dbg_pid[1U] = 0U;
                                vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__dbg_pid[2U] = 0U;
                            }
                        }
                    }
                }
            } else if ((1U & (~ ((IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__dbg_pid_r) 
                                 >> 3U)))) {
                if ((1U & (~ ((IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__dbg_pid_r) 
                              >> 2U)))) {
                    if ((2U & (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__dbg_pid_r))) {
                        if ((1U & (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__dbg_pid_r))) {
                            vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__dbg_pid[0U] = 0x41544130U;
                            vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__dbg_pid[1U] = 0x00000044U;
                            vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__dbg_pid[2U] = 0U;
                        }
                    }
                }
            }
        } else if ((0x00000020U & (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__dbg_pid_r))) {
            if ((0x00000010U & (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__dbg_pid_r))) {
                if ((1U & (~ ((IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__dbg_pid_r) 
                              >> 3U)))) {
                    if ((4U & (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__dbg_pid_r))) {
                        if ((1U & (~ ((IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__dbg_pid_r) 
                                      >> 1U)))) {
                            if ((1U & (~ (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__dbg_pid_r)))) {
                                vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__dbg_pid[0U] = 0x50494e47U;
                                vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__dbg_pid[1U] = 0U;
                                vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__dbg_pid[2U] = 0U;
                            }
                        }
                    }
                }
            } else if ((1U & (~ ((IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__dbg_pid_r) 
                                 >> 3U)))) {
                if ((4U & (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__dbg_pid_r))) {
                    if ((1U & (~ ((IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__dbg_pid_r) 
                                  >> 1U)))) {
                        if ((1U & (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__dbg_pid_r))) {
                            vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__dbg_pid[0U] = 0x00534f46U;
                            vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__dbg_pid[1U] = 0U;
                            vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__dbg_pid[2U] = 0U;
                        }
                    }
                }
            }
        } else if ((0x00000010U & (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__dbg_pid_r))) {
            if ((1U & (~ ((IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__dbg_pid_r) 
                          >> 3U)))) {
                if ((4U & (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__dbg_pid_r))) {
                    if ((2U & (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__dbg_pid_r))) {
                        if ((1U & (~ (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__dbg_pid_r)))) {
                            vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__dbg_pid[0U] = 0x4e594554U;
                            vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__dbg_pid[1U] = 0U;
                            vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__dbg_pid[2U] = 0U;
                        }
                    }
                }
            }
        } else if ((1U & (~ ((IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__dbg_pid_r) 
                             >> 3U)))) {
            if ((4U & (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__dbg_pid_r))) {
                if ((2U & (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__dbg_pid_r))) {
                    if ((1U & (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__dbg_pid_r))) {
                        vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__dbg_pid[0U] = 0x41544132U;
                        vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__dbg_pid[1U] = 0x00000044U;
                        vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__dbg_pid[2U] = 0U;
                    }
                }
            }
        }
    } else if ((0x00000040U & (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__dbg_pid_r))) {
        if ((0x00000020U & (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__dbg_pid_r))) {
            if ((0x00000010U & (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__dbg_pid_r))) {
                if ((8U & (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__dbg_pid_r))) {
                    if ((1U & (~ ((IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__dbg_pid_r) 
                                  >> 2U)))) {
                        if ((1U & (~ ((IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__dbg_pid_r) 
                                      >> 1U)))) {
                            if ((1U & (~ (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__dbg_pid_r)))) {
                                vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__dbg_pid[0U] = 0x504c4954U;
                                vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__dbg_pid[1U] = 0x00000053U;
                                vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__dbg_pid[2U] = 0U;
                            }
                        }
                    }
                }
            } else if ((8U & (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__dbg_pid_r))) {
                if ((1U & (~ ((IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__dbg_pid_r) 
                              >> 2U)))) {
                    if ((1U & (~ ((IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__dbg_pid_r) 
                                  >> 1U)))) {
                        if ((1U & (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__dbg_pid_r))) {
                            vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__dbg_pid[0U] = 0x0000494eU;
                            vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__dbg_pid[1U] = 0U;
                            vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__dbg_pid[2U] = 0U;
                        }
                    }
                }
            }
        } else if ((0x00000010U & (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__dbg_pid_r))) {
            if ((8U & (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__dbg_pid_r))) {
                if ((1U & (~ ((IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__dbg_pid_r) 
                              >> 2U)))) {
                    if ((2U & (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__dbg_pid_r))) {
                        if ((1U & (~ (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__dbg_pid_r)))) {
                            vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__dbg_pid[0U] = 0x004e414bU;
                            vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__dbg_pid[1U] = 0U;
                            vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__dbg_pid[2U] = 0U;
                        }
                    }
                }
            }
        } else if ((8U & (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__dbg_pid_r))) {
            if ((1U & (~ ((IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__dbg_pid_r) 
                          >> 2U)))) {
                if ((2U & (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__dbg_pid_r))) {
                    if ((1U & (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__dbg_pid_r))) {
                        vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__dbg_pid[0U] = 0x41544131U;
                        vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__dbg_pid[1U] = 0x00000044U;
                        vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__dbg_pid[2U] = 0U;
                    }
                }
            }
        }
    } else if ((0x00000020U & (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__dbg_pid_r))) {
        if ((0x00000010U & (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__dbg_pid_r))) {
            if ((8U & (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__dbg_pid_r))) {
                if ((4U & (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__dbg_pid_r))) {
                    if ((1U & (~ ((IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__dbg_pid_r) 
                                  >> 1U)))) {
                        if ((1U & (~ (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__dbg_pid_r)))) {
                            vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__dbg_pid[0U] = 0x2f455252U;
                            vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__dbg_pid[1U] = 0x00505245U;
                            vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__dbg_pid[2U] = 0U;
                        }
                    }
                }
            }
        } else if ((8U & (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__dbg_pid_r))) {
            if ((4U & (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__dbg_pid_r))) {
                if ((1U & (~ ((IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__dbg_pid_r) 
                              >> 1U)))) {
                    if ((1U & (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__dbg_pid_r))) {
                        vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__dbg_pid[0U] = 0x45545550U;
                        vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__dbg_pid[1U] = 0x00000053U;
                        vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__dbg_pid[2U] = 0U;
                    }
                }
            }
        }
    } else if ((0x00000010U & (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__dbg_pid_r))) {
        if ((8U & (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__dbg_pid_r))) {
            if ((4U & (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__dbg_pid_r))) {
                if ((2U & (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__dbg_pid_r))) {
                    if ((1U & (~ (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__dbg_pid_r)))) {
                        vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__dbg_pid[0U] = 0x54414c4cU;
                        vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__dbg_pid[1U] = 0x00000053U;
                        vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__dbg_pid[2U] = 0U;
                    }
                }
            }
        }
    } else if ((8U & (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__dbg_pid_r))) {
        if ((4U & (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__dbg_pid_r))) {
            if ((2U & (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__dbg_pid_r))) {
                if ((1U & (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__dbg_pid_r))) {
                    vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__dbg_pid[0U] = 0x44415441U;
                    vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__dbg_pid[1U] = 0x0000004dU;
                    vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__dbg_pid[2U] = 0U;
                }
            }
        }
    }
    top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__u_crc16__DOT____VdfgRegularize_h8075a1a5_0_2 
        = (1U & VL_REDXOR_8((0x00000060U & vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__data_buffer_q)));
    top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__u_crc16__DOT____VdfgRegularize_h8075a1a5_0_3 
        = (1U & VL_REDXOR_8((0x00000018U & vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__data_buffer_q)));
    top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__u_crc16__DOT____VdfgRegularize_h8075a1a5_0_0 
        = (1U & (vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__data_buffer_q 
                 ^ (vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__data_buffer_q 
                    >> 1U)));
    vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__tx_ready_r = 0U;
    vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__tx_data_valid_r = 0U;
    if ((1U & (~ ((IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__token_ep_q) 
                  >> 3U)))) {
        if ((1U & (~ ((IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__token_ep_q) 
                      >> 2U)))) {
            if ((2U & (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__token_ep_q))) {
                vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__tx_data_strb_r 
                    = ((1U & (~ (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__token_ep_q))) 
                       && (IData)(vlSelfRef.top__DOT__u_cdc__DOT__inport_valid_q));
                vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__tx_data_last_r 
                    = ((1U & (~ (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__token_ep_q))) 
                       && (IData)(vlSelfRef.top__DOT__u_cdc__DOT__ep2_tx_data_last_w));
                vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__tx_ready_r 
                    = ((1U & (~ (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__token_ep_q))) 
                       && (IData)(vlSelfRef.top__DOT__u_cdc__DOT__inport_valid_q));
                vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__tx_data_valid_r 
                    = ((1U & (~ (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__token_ep_q))) 
                       && (IData)(vlSelfRef.top__DOT__u_cdc__DOT__inport_valid_q));
            } else {
                vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__tx_data_strb_r 
                    = ((1U & (~ (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__token_ep_q))) 
                       && (IData)(vlSelfRef.top__DOT__u_cdc__DOT__ctrl_txstrb_q));
                vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__tx_data_last_r 
                    = ((1U & (~ (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__token_ep_q))) 
                       && (IData)(vlSelfRef.top__DOT__u_cdc__DOT__ctrl_txlast_q));
                vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__tx_ready_r 
                    = ((1U & (~ (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__token_ep_q))) 
                       && (IData)(vlSelfRef.top__DOT__u_cdc__DOT__ctrl_txvalid_q));
                vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__tx_data_valid_r 
                    = ((1U & (~ (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__token_ep_q))) 
                       && (IData)(vlSelfRef.top__DOT__u_cdc__DOT__ctrl_txvalid_q));
            }
        }
    }
    vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__rst_event_q 
        = ((1U & (~ ((IData)(vlSelfRef.top__DOT__rst_sync) 
                     >> 2U))) && (1U & ((IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__se0_cnt_q) 
                                        >> 0x0000000eU)));
    vlSelfRef.top__DOT__u_adc_wrap__DOT__tx_ready = 
        (1U & ((~ (IData)(vlSelfRef.top__DOT__u_cdc__DOT__inport_valid_q)) 
               | (IData)(vlSelfRef.top__DOT__u_cdc__DOT__ep2_tx_data_accept_w)));
    vlSelfRef.top__DOT__u_cdc__DOT__ctrl_send_accept_w 
        = (1U & ((~ (IData)(vlSelfRef.top__DOT__u_cdc__DOT__ctrl_txvalid_q)) 
                 | (IData)(vlSelfRef.top__DOT__u_cdc__DOT__ep0_tx_data_accept_w)));
    top__DOT__u_cdc__DOT__u_core__DOT__u_sie_tx__DOT__u_crc16__DOT____VdfgRegularize_h8075a1a5_0_9 
        = (1U & ((IData)(top__DOT__u_cdc__DOT__u_core__DOT__u_sie_tx__DOT__u_crc16__DOT____VdfgRegularize_h8075a1a5_0_0) 
                 ^ (((IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_tx__DOT__utmi_data_r) 
                     >> 2U) ^ ((IData)(top__DOT__u_cdc__DOT__u_core__DOT__u_sie_tx__DOT__u_crc16__DOT____VdfgRegularize_h8075a1a5_0_3) 
                               ^ (IData)(top__DOT__u_cdc__DOT__u_core__DOT__u_sie_tx__DOT__u_crc16__DOT____VdfgRegularize_h8075a1a5_0_2)))));
    top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__u_crc16__DOT____VdfgRegularize_h8075a1a5_0_9 
        = (1U & ((IData)(top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__u_crc16__DOT____VdfgRegularize_h8075a1a5_0_0) 
                 ^ ((vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__data_buffer_q 
                     >> 2U) ^ ((IData)(top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__u_crc16__DOT____VdfgRegularize_h8075a1a5_0_3) 
                               ^ (IData)(top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__u_crc16__DOT____VdfgRegularize_h8075a1a5_0_2)))));
    vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__tx_pid_r = 0U;
    if ((0U == (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__state_q))) {
        if (vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__token_valid_q) {
            if ((0x69U == (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__token_pid_q))) {
                vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__tx_valid_r = 1U;
                vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__tx_pid_r 
                    = ((IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__ep_stall_r)
                        ? 0x1eU : ((IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__tx_ready_r)
                                    ? ((IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__in_data_bit_r)
                                        ? 0x4bU : 0xc3U)
                                    : 0x5aU));
            } else if ((0xb4U == (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__token_pid_q))) {
                vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__tx_valid_r = 1U;
                vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__tx_pid_r 
                    = ((IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__ep_stall_r)
                        ? 0x1eU : ((IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__rx_space_r)
                                    ? 0xd2U : 0x5aU));
            }
        }
    } else if ((2U == (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__state_q))) {
        if (vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__data_complete_q) {
            if ((1U & (~ (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__crc_err_q)))) {
                if ((1U & (~ (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__ep_iso_r)))) {
                    vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__tx_valid_r = 1U;
                    vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__tx_pid_r 
                        = ((IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__ep_stall_r)
                            ? 0x1eU : ((((0xc3U == (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__token_pid_q)) 
                                         & (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__out_data_bit_r)) 
                                        | ((0x4bU == (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__token_pid_q)) 
                                           & (~ (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__out_data_bit_r))))
                                        ? 0xd2U : ((IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__rx_space_q)
                                                    ? 0xd2U
                                                    : 0x5aU)));
                }
            }
        }
    } else if ((7U == (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__state_q))) {
        vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__tx_valid_r = 1U;
        vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__tx_pid_r = 0U;
    }
    vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_tx__DOT__utmi_txvalid_r 
        = ((6U == (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_tx__DOT__state_q)) 
           || ((3U == (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_tx__DOT__state_q)) 
               || ((4U == (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_tx__DOT__state_q)) 
                   || ((2U == (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_tx__DOT__state_q))
                        ? (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__tx_data_valid_r)
                        : (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_tx__DOT__valid_q)))));
    vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__se0_cnt_q 
        = __Vdly__top__DOT__u_cdc__DOT__u_core__DOT__se0_cnt_q;
    vlSelfRef.top__DOT__u_adc_wrap__DOT__u_dc_fifo__DOT__rd_ena 
        = ((IData)(vlSelfRef.top__DOT__u_adc_wrap__DOT__current_state) 
           & ((IData)(vlSelfRef.top__DOT__u_adc_wrap__DOT__u_dc_fifo__DOT__data_out_valid) 
              & (IData)(vlSelfRef.top__DOT__u_adc_wrap__DOT__tx_ready)));
    vlSelfRef.top__DOT__u_adc_wrap__DOT__byte_sent 
        = ((IData)(vlSelfRef.top__DOT__u_adc_wrap__DOT__tx_ready) 
           & (IData)(vlSelfRef.top__DOT__tx_valid));
    vlSelfRef.top__DOT__u_cdc__DOT__ctrl_stall_r = 0U;
    vlSelfRef.top__DOT__u_cdc__DOT__ctrl_get_len_r = 0U;
    vlSelfRef.top__DOT__u_cdc__DOT__ctrl_ack_r = 0U;
    vlSelfRef.top__DOT__u_cdc__DOT__desc_addr_r = 0U;
    vlSelfRef.top__DOT__u_cdc__DOT__device_addr_r = vlSelfRef.top__DOT__u_cdc__DOT__device_addr_q;
    vlSelfRef.top__DOT__u_cdc__DOT__addressed_r = vlSelfRef.top__DOT__u_cdc__DOT__addressed_q;
    vlSelfRef.top__DOT__u_cdc__DOT__configured_r = vlSelfRef.top__DOT__u_cdc__DOT__configured_q;
    vlSelfRef.top__DOT__u_cdc__DOT__set_with_data_r 
        = vlSelfRef.top__DOT__u_cdc__DOT__set_with_data_q;
    if ((4U & (IData)(vlSelfRef.top__DOT__u_cdc__DOT__genblk1__DOT__state_q))) {
        if ((1U & (~ ((IData)(vlSelfRef.top__DOT__u_cdc__DOT__genblk1__DOT__state_q) 
                      >> 1U)))) {
            vlSelfRef.top__DOT__u_cdc__DOT__genblk1__DOT__utmi_dmpulldown_r = 0U;
            vlSelfRef.top__DOT__u_cdc__DOT__genblk1__DOT__utmi_dppulldown_r = 0U;
            vlSelfRef.top__DOT__u_cdc__DOT__genblk1__DOT__utmi_op_mode_r = 0U;
            vlSelfRef.top__DOT__u_cdc__DOT__genblk1__DOT__utmi_termselect_r 
                = (1U & (~ (IData)(vlSelfRef.top__DOT__u_cdc__DOT__genblk1__DOT__state_q)));
            vlSelfRef.top__DOT__u_cdc__DOT__genblk1__DOT__utmi_xcvrselect_r 
                = ((1U & (IData)(vlSelfRef.top__DOT__u_cdc__DOT__genblk1__DOT__state_q))
                    ? 0U : 1U);
        }
    } else if ((2U & (IData)(vlSelfRef.top__DOT__u_cdc__DOT__genblk1__DOT__state_q))) {
        vlSelfRef.top__DOT__u_cdc__DOT__genblk1__DOT__utmi_dmpulldown_r = 0U;
        vlSelfRef.top__DOT__u_cdc__DOT__genblk1__DOT__utmi_dppulldown_r = 0U;
        vlSelfRef.top__DOT__u_cdc__DOT__genblk1__DOT__utmi_op_mode_r = 2U;
        vlSelfRef.top__DOT__u_cdc__DOT__genblk1__DOT__utmi_termselect_r = 1U;
        vlSelfRef.top__DOT__u_cdc__DOT__genblk1__DOT__utmi_xcvrselect_r = 0U;
    } else if ((1U & (IData)(vlSelfRef.top__DOT__u_cdc__DOT__genblk1__DOT__state_q))) {
        vlSelfRef.top__DOT__u_cdc__DOT__genblk1__DOT__utmi_dmpulldown_r = 0U;
        vlSelfRef.top__DOT__u_cdc__DOT__genblk1__DOT__utmi_dppulldown_r = 0U;
        vlSelfRef.top__DOT__u_cdc__DOT__genblk1__DOT__utmi_op_mode_r = 0U;
        vlSelfRef.top__DOT__u_cdc__DOT__genblk1__DOT__utmi_termselect_r = 1U;
        vlSelfRef.top__DOT__u_cdc__DOT__genblk1__DOT__utmi_xcvrselect_r = 1U;
    }
    if (vlSelfRef.top__DOT__u_cdc__DOT__setup_valid_q) {
        vlSelfRef.top__DOT__u_cdc__DOT__set_with_data_r = 0U;
        if ((0U == (0x60U & vlSelfRef.top__DOT__u_cdc__DOT__setup_packet_q[0U]))) {
            if (((((((((0U == vlSelfRef.top__DOT__u_cdc__DOT__setup_packet_q[1U]) 
                       | (1U == vlSelfRef.top__DOT__u_cdc__DOT__setup_packet_q[1U])) 
                      | (3U == vlSelfRef.top__DOT__u_cdc__DOT__setup_packet_q[1U])) 
                     | (5U == vlSelfRef.top__DOT__u_cdc__DOT__setup_packet_q[1U])) 
                    | (6U == vlSelfRef.top__DOT__u_cdc__DOT__setup_packet_q[1U])) 
                   | (8U == vlSelfRef.top__DOT__u_cdc__DOT__setup_packet_q[1U])) 
                  | (9U == vlSelfRef.top__DOT__u_cdc__DOT__setup_packet_q[1U])) 
                 | (0x0aU == vlSelfRef.top__DOT__u_cdc__DOT__setup_packet_q[1U]))) {
                if (VL_UNLIKELY(((0U == vlSelfRef.top__DOT__u_cdc__DOT__setup_packet_q[1U])))) {
                    VL_WRITEF_NX("GET_STATUS\n",0);
                } else if (VL_UNLIKELY(((1U == vlSelfRef.top__DOT__u_cdc__DOT__setup_packet_q[1U])))) {
                    VL_WRITEF_NX("CLEAR_FEATURE\n",0);
                    vlSelfRef.top__DOT__u_cdc__DOT__ctrl_ack_r 
                        = top__DOT__u_cdc__DOT____VdfgExtracted_h9796ed88__0;
                } else if (VL_UNLIKELY(((3U == vlSelfRef.top__DOT__u_cdc__DOT__setup_packet_q[1U])))) {
                    VL_WRITEF_NX("SET_FEATURE\n",0);
                    vlSelfRef.top__DOT__u_cdc__DOT__ctrl_ack_r 
                        = top__DOT__u_cdc__DOT____VdfgExtracted_h9796ed88__0;
                } else if (VL_UNLIKELY(((5U == vlSelfRef.top__DOT__u_cdc__DOT__setup_packet_q[1U])))) {
                    VL_WRITEF_NX("SET_ADDRESS: Set device address %3#\n",0,
                                 7,(0x0000007fU & (IData)(vlSelfRef.top__DOT__u_cdc__DOT__wValue_w)));
                    vlSelfRef.top__DOT__u_cdc__DOT__ctrl_ack_r 
                        = top__DOT__u_cdc__DOT____VdfgExtracted_h9796ed88__0;
                    vlSelfRef.top__DOT__u_cdc__DOT__device_addr_r 
                        = (0x0000007fU & vlSelfRef.top__DOT__u_cdc__DOT__setup_packet_q[2U]);
                    vlSelfRef.top__DOT__u_cdc__DOT__addressed_r = 1U;
                } else if (VL_UNLIKELY(((6U == vlSelfRef.top__DOT__u_cdc__DOT__setup_packet_q[1U])))) {
                    VL_WRITEF_NX("GET_DESCRIPTOR: Type %3#\n",0,
                                 8,vlSelfRef.top__DOT__u_cdc__DOT__setup_packet_q[3U]);
                    if ((1U == vlSelfRef.top__DOT__u_cdc__DOT__setup_packet_q[3U])) {
                        vlSelfRef.top__DOT__u_cdc__DOT__desc_addr_r = 0U;
                        vlSelfRef.top__DOT__u_cdc__DOT__ctrl_get_len_r = 0x0012U;
                    } else if ((2U == vlSelfRef.top__DOT__u_cdc__DOT__setup_packet_q[3U])) {
                        vlSelfRef.top__DOT__u_cdc__DOT__desc_addr_r = 0x12U;
                        vlSelfRef.top__DOT__u_cdc__DOT__ctrl_get_len_r = 0x0043U;
                    } else if ((3U == vlSelfRef.top__DOT__u_cdc__DOT__setup_packet_q[3U])) {
                        if ((0U == vlSelfRef.top__DOT__u_cdc__DOT__setup_packet_q[2U])) {
                            vlSelfRef.top__DOT__u_cdc__DOT__desc_addr_r = 0x55U;
                            vlSelfRef.top__DOT__u_cdc__DOT__ctrl_get_len_r = 4U;
                        } else if ((1U == vlSelfRef.top__DOT__u_cdc__DOT__setup_packet_q[2U])) {
                            vlSelfRef.top__DOT__u_cdc__DOT__desc_addr_r = 0x59U;
                            vlSelfRef.top__DOT__u_cdc__DOT__ctrl_get_len_r = 0x000eU;
                        } else if ((2U == vlSelfRef.top__DOT__u_cdc__DOT__setup_packet_q[2U])) {
                            vlSelfRef.top__DOT__u_cdc__DOT__desc_addr_r = 0x67U;
                            vlSelfRef.top__DOT__u_cdc__DOT__ctrl_get_len_r = 0x0024U;
                        } else if ((3U == vlSelfRef.top__DOT__u_cdc__DOT__setup_packet_q[2U])) {
                            vlSelfRef.top__DOT__u_cdc__DOT__desc_addr_r = 0x8bU;
                            vlSelfRef.top__DOT__u_cdc__DOT__ctrl_get_len_r = 0x000eU;
                        } else {
                            vlSelfRef.top__DOT__u_cdc__DOT__ctrl_stall_r = 1U;
                        }
                    } else {
                        vlSelfRef.top__DOT__u_cdc__DOT__ctrl_stall_r = 1U;
                    }
                } else if (VL_UNLIKELY(((8U == vlSelfRef.top__DOT__u_cdc__DOT__setup_packet_q[1U])))) {
                    VL_WRITEF_NX("GET_CONF\n",0);
                } else if ((9U == vlSelfRef.top__DOT__u_cdc__DOT__setup_packet_q[1U])) {
                    VL_WRITEF_NX("SET_CONF: Configuration %x\n",0,
                                 16,vlSelfRef.top__DOT__u_cdc__DOT__wValue_w);
                    if ((0U == (IData)(vlSelfRef.top__DOT__u_cdc__DOT__wValue_w))) {
                        vlSelfRef.top__DOT__u_cdc__DOT__configured_r = 0U;
                        vlSelfRef.top__DOT__u_cdc__DOT__ctrl_ack_r 
                            = top__DOT__u_cdc__DOT____VdfgExtracted_h9796ed88__0;
                    } else if ((1U == (IData)(vlSelfRef.top__DOT__u_cdc__DOT__wValue_w))) {
                        vlSelfRef.top__DOT__u_cdc__DOT__configured_r = 1U;
                        vlSelfRef.top__DOT__u_cdc__DOT__ctrl_ack_r 
                            = top__DOT__u_cdc__DOT____VdfgExtracted_h9796ed88__0;
                    } else {
                        vlSelfRef.top__DOT__u_cdc__DOT__ctrl_stall_r = 1U;
                    }
                } else {
                    VL_WRITEF_NX("GET_INTERFACE\n",0);
                    vlSelfRef.top__DOT__u_cdc__DOT__ctrl_stall_r = 1U;
                }
            } else if (VL_UNLIKELY(((0x0bU == vlSelfRef.top__DOT__u_cdc__DOT__setup_packet_q[1U])))) {
                VL_WRITEF_NX("SET_INTERFACE: %x %x\n",0,
                             16,vlSelfRef.top__DOT__u_cdc__DOT__wValue_w,
                             16,(IData)(vlSelfRef.top__DOT__u_cdc__DOT__wIndex_w));
                if (((0U == (IData)(vlSelfRef.top__DOT__u_cdc__DOT__wValue_w)) 
                     & (0U == (IData)(vlSelfRef.top__DOT__u_cdc__DOT__wIndex_w)))) {
                    vlSelfRef.top__DOT__u_cdc__DOT__ctrl_ack_r 
                        = top__DOT__u_cdc__DOT____VdfgExtracted_h9796ed88__0;
                } else {
                    vlSelfRef.top__DOT__u_cdc__DOT__ctrl_stall_r = 1U;
                }
            } else {
                vlSelfRef.top__DOT__u_cdc__DOT__ctrl_stall_r = 1U;
            }
        } else if ((0x40U == (0x60U & vlSelfRef.top__DOT__u_cdc__DOT__setup_packet_q[0U]))) {
            vlSelfRef.top__DOT__u_cdc__DOT__ctrl_stall_r = 1U;
        } else if ((0x20U == (0x60U & vlSelfRef.top__DOT__u_cdc__DOT__setup_packet_q[0U]))) {
            if (VL_UNLIKELY(((0x21U == vlSelfRef.top__DOT__u_cdc__DOT__setup_packet_q[1U])))) {
                VL_WRITEF_NX("CDC_GET_LINE_CODING\n",0);
                vlSelfRef.top__DOT__u_cdc__DOT__desc_addr_r = 0x99U;
                vlSelfRef.top__DOT__u_cdc__DOT__ctrl_get_len_r = 7U;
            } else {
                vlSelfRef.top__DOT__u_cdc__DOT__ctrl_ack_r 
                    = top__DOT__u_cdc__DOT____VdfgExtracted_h9796ed88__0;
                vlSelfRef.top__DOT__u_cdc__DOT__set_with_data_r 
                    = ((~ (IData)(vlSelfRef.top__DOT__u_cdc__DOT__setup_no_data_w)) 
                       & (IData)(vlSelfRef.top__DOT__u_cdc__DOT__setup_set_w));
            }
        } else {
            vlSelfRef.top__DOT__u_cdc__DOT__ctrl_stall_r = 1U;
        }
    } else if (((IData)(vlSelfRef.top__DOT__u_cdc__DOT__set_with_data_q) 
                & ((IData)(vlSelfRef.top__DOT__u_cdc__DOT__setup_data_q) 
                   & (IData)(vlSelfRef.top__DOT__u_cdc__DOT__ctrl_send_accept_w)))) {
        vlSelfRef.top__DOT__u_cdc__DOT__set_with_data_r = 0U;
    }
    top__DOT__u_cdc__DOT__u_core__DOT__u_sie_tx__DOT__u_crc16__DOT____VdfgRegularize_h8075a1a5_0_1 
        = ((IData)(top__DOT__u_cdc__DOT__u_core__DOT__u_sie_tx__DOT__u_crc16__DOT____VdfgRegularize_h8075a1a5_0_9) 
           ^ ((IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_tx__DOT__utmi_data_r) 
              >> 7U));
    top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__u_crc16__DOT____VdfgRegularize_h8075a1a5_0_1 
        = (1U & ((IData)(top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__u_crc16__DOT____VdfgRegularize_h8075a1a5_0_9) 
                 ^ (vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__data_buffer_q 
                    >> 7U)));
    vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__input_ready_w 
        = ((6U == (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__state_q)) 
           & ((~ (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__data_crc_q)) 
              & (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__data_valid_q)));
    vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__next_state_r 
        = vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__state_q;
    if ((8U & (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__state_q))) {
        if ((1U & (~ ((IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__state_q) 
                      >> 2U)))) {
            if ((1U & (~ ((IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__state_q) 
                          >> 1U)))) {
                if ((1U & (~ (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__state_q)))) {
                    if ((1U & (~ (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__rx_active_q)))) {
                        vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__next_state_r = 0U;
                    }
                }
            }
        }
    } else if ((4U & (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__state_q))) {
        if ((2U & (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__state_q))) {
            if ((1U & (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__state_q))) {
                if ((1U & (~ (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__rx_active_q)))) {
                    vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__next_state_r = 0U;
                }
            } else if ((1U & (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__data_crc_q))) {
                vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__next_state_r = 7U;
            }
        } else if ((1U & (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__state_q))) {
            if ((1U & ((~ (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__rx_active_q)) 
                       | (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__data_valid_q)))) {
                vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__next_state_r = 0U;
            }
        } else if ((1U & (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__data_valid_q))) {
            vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__next_state_r = 5U;
        } else if ((1U & (~ (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__rx_active_q)))) {
            vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__next_state_r = 0U;
        }
    } else if ((2U & (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__state_q))) {
        if ((1U & (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__state_q))) {
            vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__next_state_r = 0U;
        } else if ((1U & (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__data_valid_q))) {
            vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__next_state_r = 3U;
        } else if ((1U & (~ (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__rx_active_q)))) {
            vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__next_state_r = 0U;
        }
    } else if ((1U & (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__state_q))) {
        if ((1U & (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__data_valid_q))) {
            vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__next_state_r = 2U;
        } else if ((1U & (~ (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__rx_active_q)))) {
            vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__next_state_r = 0U;
        }
    } else if ((1U & (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__data_valid_q))) {
        vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__next_state_r 
            = ((0x00000080U & vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__data_buffer_q)
                ? ((0x00000040U & vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__data_buffer_q)
                    ? ((0x00000020U & vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__data_buffer_q)
                        ? ((0x00000010U & vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__data_buffer_q)
                            ? 8U : ((8U & vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__data_buffer_q)
                                     ? 8U : ((4U & vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__data_buffer_q)
                                              ? 8U : 
                                             ((2U & vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__data_buffer_q)
                                               ? 8U
                                               : ((1U 
                                                   & vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__data_buffer_q)
                                                   ? 1U
                                                   : 8U)))))
                        : ((0x00000010U & vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__data_buffer_q)
                            ? ((8U & vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__data_buffer_q)
                                ? 8U : ((4U & vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__data_buffer_q)
                                         ? 8U : ((2U 
                                                  & vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__data_buffer_q)
                                                  ? 
                                                 ((1U 
                                                   & vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__data_buffer_q)
                                                   ? 8U
                                                   : 0U)
                                                  : 8U)))
                            : ((8U & vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__data_buffer_q)
                                ? 8U : ((4U & vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__data_buffer_q)
                                         ? 8U : ((2U 
                                                  & vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__data_buffer_q)
                                                  ? 
                                                 ((1U 
                                                   & vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__data_buffer_q)
                                                   ? 6U
                                                   : 8U)
                                                  : 8U)))))
                    : ((0x00000020U & vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__data_buffer_q)
                        ? ((0x00000010U & vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__data_buffer_q)
                            ? ((8U & vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__data_buffer_q)
                                ? 8U : ((4U & vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__data_buffer_q)
                                         ? ((2U & vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__data_buffer_q)
                                             ? 8U : 
                                            ((1U & vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__data_buffer_q)
                                              ? 8U : 1U))
                                         : 8U)) : (
                                                   (8U 
                                                    & vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__data_buffer_q)
                                                    ? 8U
                                                    : 
                                                   ((4U 
                                                     & vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__data_buffer_q)
                                                     ? 
                                                    ((2U 
                                                      & vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__data_buffer_q)
                                                      ? 8U
                                                      : 
                                                     ((1U 
                                                       & vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__data_buffer_q)
                                                       ? 4U
                                                       : 8U))
                                                     : 8U)))
                        : ((0x00000010U & vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__data_buffer_q)
                            ? ((8U & vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__data_buffer_q)
                                ? 8U : ((4U & vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__data_buffer_q)
                                         ? ((2U & vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__data_buffer_q)
                                             ? ((1U 
                                                 & vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__data_buffer_q)
                                                 ? 8U
                                                 : 0U)
                                             : 8U) : 8U))
                            : ((8U & vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__data_buffer_q)
                                ? 8U : ((4U & vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__data_buffer_q)
                                         ? ((2U & vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__data_buffer_q)
                                             ? ((1U 
                                                 & vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__data_buffer_q)
                                                 ? 6U
                                                 : 8U)
                                             : 8U) : 8U)))))
                : ((0x00000040U & vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__data_buffer_q)
                    ? ((0x00000020U & vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__data_buffer_q)
                        ? ((0x00000010U & vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__data_buffer_q)
                            ? 8U : ((8U & vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__data_buffer_q)
                                     ? ((4U & vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__data_buffer_q)
                                         ? 8U : ((2U 
                                                  & vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__data_buffer_q)
                                                  ? 8U
                                                  : 
                                                 ((1U 
                                                   & vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__data_buffer_q)
                                                   ? 1U
                                                   : 8U)))
                                     : 8U)) : ((0x00000010U 
                                                & vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__data_buffer_q)
                                                ? (
                                                   (8U 
                                                    & vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__data_buffer_q)
                                                    ? 
                                                   ((4U 
                                                     & vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__data_buffer_q)
                                                     ? 8U
                                                     : 
                                                    ((2U 
                                                      & vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__data_buffer_q)
                                                      ? 
                                                     ((1U 
                                                       & vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__data_buffer_q)
                                                       ? 8U
                                                       : 0U)
                                                      : 8U))
                                                    : 8U)
                                                : (
                                                   (8U 
                                                    & vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__data_buffer_q)
                                                    ? 
                                                   ((4U 
                                                     & vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__data_buffer_q)
                                                     ? 8U
                                                     : 
                                                    ((2U 
                                                      & vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__data_buffer_q)
                                                      ? 
                                                     ((1U 
                                                       & vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__data_buffer_q)
                                                       ? 6U
                                                       : 8U)
                                                      : 8U))
                                                    : 8U)))
                    : ((0x00000020U & vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__data_buffer_q)
                        ? ((0x00000010U & vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__data_buffer_q)
                            ? 8U : ((8U & vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__data_buffer_q)
                                     ? ((4U & vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__data_buffer_q)
                                         ? ((2U & vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__data_buffer_q)
                                             ? 8U : 
                                            ((1U & vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__data_buffer_q)
                                              ? 1U : 8U))
                                         : 8U) : 8U))
                        : ((0x00000010U & vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__data_buffer_q)
                            ? ((8U & vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__data_buffer_q)
                                ? ((4U & vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__data_buffer_q)
                                    ? ((2U & vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__data_buffer_q)
                                        ? ((1U & vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__data_buffer_q)
                                            ? 8U : 0U)
                                        : 8U) : 8U)
                                : 8U) : ((8U & vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__data_buffer_q)
                                          ? ((4U & vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__data_buffer_q)
                                              ? ((2U 
                                                  & vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__data_buffer_q)
                                                  ? 
                                                 ((1U 
                                                   & vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__data_buffer_q)
                                                   ? 6U
                                                   : 8U)
                                                  : 8U)
                                              : 8U)
                                          : 8U)))));
    }
    vlSelfRef.top__DOT__u_cdc__DOT__genblk1__DOT__next_state_r 
        = vlSelfRef.top__DOT__u_cdc__DOT__genblk1__DOT__state_q;
    if ((4U & (IData)(vlSelfRef.top__DOT__u_cdc__DOT__genblk1__DOT__state_q))) {
        if ((1U & (~ ((IData)(vlSelfRef.top__DOT__u_cdc__DOT__genblk1__DOT__state_q) 
                      >> 1U)))) {
            if ((1U & (IData)(vlSelfRef.top__DOT__u_cdc__DOT__genblk1__DOT__state_q))) {
                if (((0x000927c0U <= vlSelfRef.top__DOT__u_cdc__DOT__genblk1__DOT__usb_rst_time_q) 
                     & (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__rst_event_q))) {
                    vlSelfRef.top__DOT__u_cdc__DOT__genblk1__DOT__next_state_r = 1U;
                }
            } else if (((0x000927c0U <= vlSelfRef.top__DOT__u_cdc__DOT__genblk1__DOT__usb_rst_time_q) 
                        & (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__rst_event_q))) {
                vlSelfRef.top__DOT__u_cdc__DOT__genblk1__DOT__next_state_r = 1U;
            }
        }
    } else if ((2U & (IData)(vlSelfRef.top__DOT__u_cdc__DOT__genblk1__DOT__state_q))) {
        if ((1U & (IData)(vlSelfRef.top__DOT__u_cdc__DOT__genblk1__DOT__state_q))) {
            if ((4U <= (IData)(vlSelfRef.top__DOT__u_cdc__DOT__genblk1__DOT__chirp_count_q))) {
                vlSelfRef.top__DOT__u_cdc__DOT__genblk1__DOT__next_state_r = 5U;
            } else if ((0x000927c0U <= vlSelfRef.top__DOT__u_cdc__DOT__genblk1__DOT__usb_rst_time_q)) {
                vlSelfRef.top__DOT__u_cdc__DOT__genblk1__DOT__next_state_r = 4U;
            }
        } else if ((0x00018e70U <= vlSelfRef.top__DOT__u_cdc__DOT__genblk1__DOT__usb_rst_time_q)) {
            vlSelfRef.top__DOT__u_cdc__DOT__genblk1__DOT__next_state_r = 3U;
        }
    } else if ((1U & (IData)(vlSelfRef.top__DOT__u_cdc__DOT__genblk1__DOT__state_q))) {
        if ((0x00007530U <= vlSelfRef.top__DOT__u_cdc__DOT__genblk1__DOT__usb_rst_time_q)) {
            vlSelfRef.top__DOT__u_cdc__DOT__genblk1__DOT__next_state_r = 2U;
        }
    } else if ((0x00000bb8U <= vlSelfRef.top__DOT__u_cdc__DOT__genblk1__DOT__usb_rst_time_q)) {
        vlSelfRef.top__DOT__u_cdc__DOT__genblk1__DOT__next_state_r = 1U;
    }
    vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT____Vcellinp__u_sie_rx__enable_i 
        = ((~ ((IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__se0_cnt_q) 
               >> 0x0000000eU)) & (2U != (IData)(vlSelfRef.top__DOT__u_cdc__DOT__genblk1__DOT__state_q)));
    __Vtableidx3 = (((((4U & ((~ ((IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__se0_cnt_q) 
                                  >> 0x0000000eU)) 
                              << 2U)) | (((IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__tx_valid_q) 
                                          << 1U) | (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_tx__DOT__data_pid_q))) 
                      << 8U) | (((IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_tx__DOT__data_zlp_q) 
                                 << 7U) | (((IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__tx_data_last_r) 
                                            << 6U) 
                                           | ((IData)(vlSelfRef.top__DOT__utmi_txready_wrapper) 
                                              << 5U)))) 
                    | (((IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_tx__DOT__utmi_txvalid_r) 
                        << 4U) | (((2U == (IData)(vlSelfRef.top__DOT__u_cdc__DOT__genblk1__DOT__state_q)) 
                                   << 3U) | (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_tx__DOT__state_q))));
    vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_tx__DOT__next_state_r 
        = Vtop__ConstPool__TABLE_h5eabb7eb_0[__Vtableidx3];
    vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__next_state_r 
        = vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__state_q;
    if ((4U & (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__state_q))) {
        if ((2U & (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__state_q))) {
            if ((1U & (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__state_q))) {
                if ((2U != (IData)(vlSelfRef.top__DOT__u_cdc__DOT__genblk1__DOT__state_q))) {
                    vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__next_state_r = 0U;
                }
            } else if ((0U == (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_tx__DOT__state_q))) {
                vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__next_state_r = 0U;
            }
        } else if ((1U & (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__state_q))) {
            vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__next_state_r = 0U;
        } else if ((1U & ((~ (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__tx_valid_q)) 
                          | (0U == (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_tx__DOT__state_q))))) {
            if ((((IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__tx_data_valid_r) 
                  & (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__tx_data_last_r)) 
                 & (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__tx_data_accept_w))) {
                vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__next_state_r = 5U;
            }
        }
    } else if ((2U & (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__state_q))) {
        if ((1U & (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__state_q))) {
            if (((IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__valid_q) 
                 & (IData)(vlSelfRef.top__DOT__u_cdc__DOT__rx_last_w))) {
                vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__next_state_r = 2U;
            }
        } else if (vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__data_complete_q) {
            vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__next_state_r 
                = ((IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__crc_err_q)
                    ? 0U : ((IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__ep_iso_r)
                             ? 0U : 6U));
        }
    } else if ((1U & (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__state_q))) {
        if (((((0xc3U == (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__token_pid_q)) 
               & (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__out_data_bit_r)) 
              & (~ (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__ep_iso_r))) 
             | (((0x4bU == (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__token_pid_q)) 
                 & (~ (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__out_data_bit_r))) 
                & (~ (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__ep_iso_r))))) {
            vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__next_state_r = 3U;
        } else if (((IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__valid_q) 
                    & (IData)(vlSelfRef.top__DOT__u_cdc__DOT__rx_last_w))) {
            vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__next_state_r = 2U;
        }
    } else if (vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__token_valid_q) {
        if ((0x69U == (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__token_pid_q))) {
            vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__next_state_r 
                = ((IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__ep_stall_r)
                    ? 6U : ((IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__tx_ready_r)
                             ? 4U : 6U));
        } else if ((0xb4U == (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__token_pid_q))) {
            vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__next_state_r = 6U;
        } else if ((0xe1U == (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__token_pid_q))) {
            vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__next_state_r 
                = ((IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__ep_stall_r)
                    ? 3U : ((IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__rx_space_r)
                             ? 1U : 3U));
        } else if ((0x2dU == (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__token_pid_q))) {
            vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__next_state_r 
                = ((IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__rx_space_r)
                    ? 1U : 3U);
        }
    } else if ((2U == (IData)(vlSelfRef.top__DOT__u_cdc__DOT__genblk1__DOT__state_q))) {
        vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__next_state_r = 7U;
    }
    if ((((IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__se0_cnt_q) 
          >> 0x0000000eU) & (2U != (IData)(vlSelfRef.top__DOT__u_cdc__DOT__genblk1__DOT__state_q)))) {
        vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__next_state_r = 0U;
    }
    vlSelfRef.top__DOT__u_cdc__DOT__ctrl_txstall_r 
        = vlSelfRef.top__DOT__u_cdc__DOT__ctrl_txstall_q;
    vlSelfRef.top__DOT__u_cdc__DOT__ctrl_sending_r 
        = vlSelfRef.top__DOT__u_cdc__DOT__ctrl_sending_q;
    vlSelfRef.top__DOT__u_cdc__DOT__ctrl_send_idx_r 
        = vlSelfRef.top__DOT__u_cdc__DOT__ctrl_send_idx_q;
    vlSelfRef.top__DOT__u_cdc__DOT__ctrl_send_len_r 
        = vlSelfRef.top__DOT__u_cdc__DOT__ctrl_send_len_q;
    vlSelfRef.top__DOT__u_cdc__DOT__ctrl_txvalid_r 
        = vlSelfRef.top__DOT__u_cdc__DOT__ctrl_txvalid_q;
    vlSelfRef.top__DOT__u_cdc__DOT__ctrl_txdata_r = vlSelfRef.top__DOT__u_cdc__DOT__ctrl_txdata_q;
    vlSelfRef.top__DOT__u_cdc__DOT__ctrl_txstrb_r = vlSelfRef.top__DOT__u_cdc__DOT__ctrl_txstrb_q;
    vlSelfRef.top__DOT__u_cdc__DOT__ctrl_txlast_r = vlSelfRef.top__DOT__u_cdc__DOT__ctrl_txlast_q;
    if (vlSelfRef.top__DOT__u_cdc__DOT__setup_valid_q) {
        if (vlSelfRef.top__DOT__u_cdc__DOT__ctrl_stall_r) {
            vlSelfRef.top__DOT__u_cdc__DOT__ctrl_txstall_r = 1U;
            vlSelfRef.top__DOT__u_cdc__DOT__ctrl_txvalid_r = 1U;
            vlSelfRef.top__DOT__u_cdc__DOT__ctrl_txstrb_r = 0U;
            vlSelfRef.top__DOT__u_cdc__DOT__ctrl_txlast_r = 1U;
        } else {
            vlSelfRef.top__DOT__u_cdc__DOT__ctrl_txstall_r = 0U;
            if (vlSelfRef.top__DOT__u_cdc__DOT__ctrl_ack_r) {
                vlSelfRef.top__DOT__u_cdc__DOT__ctrl_txvalid_r = 1U;
                vlSelfRef.top__DOT__u_cdc__DOT__ctrl_txstrb_r = 0U;
                vlSelfRef.top__DOT__u_cdc__DOT__ctrl_txlast_r = 1U;
            } else {
                vlSelfRef.top__DOT__u_cdc__DOT__ctrl_sending_r 
                    = (((IData)(vlSelfRef.top__DOT__u_cdc__DOT__setup_valid_q) 
                        & (vlSelfRef.top__DOT__u_cdc__DOT__setup_packet_q[0U] 
                           >> 7U)) & (~ (IData)(vlSelfRef.top__DOT__u_cdc__DOT__ctrl_stall_r)));
                vlSelfRef.top__DOT__u_cdc__DOT__ctrl_send_idx_r = 0U;
                vlSelfRef.top__DOT__u_cdc__DOT__ctrl_send_len_r 
                    = vlSelfRef.top__DOT__u_cdc__DOT__ctrl_get_len_r;
            }
        }
    } else {
        if ((1U & (~ (IData)(vlSelfRef.top__DOT__u_cdc__DOT__status_ready_q)))) {
            if (((IData)(vlSelfRef.top__DOT__u_cdc__DOT__set_with_data_q) 
                 & (IData)(vlSelfRef.top__DOT__u_cdc__DOT__setup_data_q))) {
                vlSelfRef.top__DOT__u_cdc__DOT__ctrl_txstall_r = 0U;
            }
        }
        if (vlSelfRef.top__DOT__u_cdc__DOT__status_ready_q) {
            vlSelfRef.top__DOT__u_cdc__DOT__ctrl_sending_r = 0U;
            vlSelfRef.top__DOT__u_cdc__DOT__ctrl_send_idx_r = 0U;
            vlSelfRef.top__DOT__u_cdc__DOT__ctrl_send_len_r = 0U;
            vlSelfRef.top__DOT__u_cdc__DOT__ctrl_txvalid_r = 0U;
        } else if (((IData)(vlSelfRef.top__DOT__u_cdc__DOT__set_with_data_q) 
                    & (IData)(vlSelfRef.top__DOT__u_cdc__DOT__setup_data_q))) {
            vlSelfRef.top__DOT__u_cdc__DOT__ctrl_txvalid_r = 1U;
            vlSelfRef.top__DOT__u_cdc__DOT__ctrl_txstrb_r = 0U;
            vlSelfRef.top__DOT__u_cdc__DOT__ctrl_txlast_r = 1U;
        } else if (((IData)(vlSelfRef.top__DOT__u_cdc__DOT__ctrl_sending_r) 
                    & (IData)(vlSelfRef.top__DOT__u_cdc__DOT__ctrl_send_accept_w))) {
            vlSelfRef.top__DOT__u_cdc__DOT__ctrl_txvalid_r = 1U;
            vlSelfRef.top__DOT__u_cdc__DOT__ctrl_txdata_r 
                = vlSelfRef.top__DOT__u_cdc__DOT__u_rom__DOT__desc_rom_r;
            vlSelfRef.top__DOT__u_cdc__DOT__ctrl_txstrb_r = 1U;
            vlSelfRef.top__DOT__u_cdc__DOT__ctrl_txlast_r 
                = ((5U == (IData)(vlSelfRef.top__DOT__u_cdc__DOT__genblk1__DOT__state_q))
                    ? (0x3fU == (0x0000003fU & (IData)(vlSelfRef.top__DOT__u_cdc__DOT__ctrl_send_idx_r)))
                    : (7U == (7U & (IData)(vlSelfRef.top__DOT__u_cdc__DOT__ctrl_send_idx_r))));
            vlSelfRef.top__DOT__u_cdc__DOT__ctrl_send_idx_r 
                = (0x0000ffffU & ((IData)(1U) + (IData)(vlSelfRef.top__DOT__u_cdc__DOT__ctrl_send_idx_r)));
            if ((((IData)(vlSelfRef.top__DOT__u_cdc__DOT__ctrl_send_idx_r) 
                  == (IData)(vlSelfRef.top__DOT__u_cdc__DOT__wLength)) 
                 | ((IData)(vlSelfRef.top__DOT__u_cdc__DOT__ctrl_send_idx_r) 
                    == (IData)(vlSelfRef.top__DOT__u_cdc__DOT__ctrl_send_len_r)))) {
                vlSelfRef.top__DOT__u_cdc__DOT__ctrl_sending_r = 0U;
                vlSelfRef.top__DOT__u_cdc__DOT__ctrl_txlast_r = 1U;
            }
        } else if (vlSelfRef.top__DOT__u_cdc__DOT__ctrl_send_accept_w) {
            vlSelfRef.top__DOT__u_cdc__DOT__ctrl_txvalid_r = 0U;
        }
    }
    vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_tx__DOT__u_crc16__DOT__crc_out_o 
        = ((((((((IData)(top__DOT__u_cdc__DOT__u_core__DOT__u_sie_tx__DOT__u_crc16__DOT____VdfgRegularize_h8075a1a5_0_1) 
                 ^ ((IData)(top__DOT__u_cdc__DOT__u_core__DOT__u_sie_tx__DOT__u_crc16__DOT____VdfgRegularize_h8075a1a5_0_5) 
                    ^ (IData)(top__DOT__u_cdc__DOT__u_core__DOT__u_sie_tx__DOT__u_crc16__DOT____VdfgRegularize_h8075a1a5_0_8))) 
                << 3U) | (4U & (((IData)(top__DOT__u_cdc__DOT__u_core__DOT__u_sie_tx__DOT__u_crc16__DOT____VdfgRegularize_h8075a1a5_0_9) 
                                 ^ (((IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_tx__DOT__crc_sum_q) 
                                     >> 6U) ^ (IData)(top__DOT__u_cdc__DOT__u_core__DOT__u_sie_tx__DOT__u_crc16__DOT____VdfgRegularize_h8075a1a5_0_8))) 
                                << 2U))) | ((2U & (
                                                   (VL_REDXOR_8(
                                                                (0xc0U 
                                                                 & (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_tx__DOT__utmi_data_r))) 
                                                    ^ (IData)(top__DOT__u_cdc__DOT__u_core__DOT__u_sie_tx__DOT__u_crc16__DOT____VdfgRegularize_h8075a1a5_0_5)) 
                                                   << 1U)) 
                                            | (1U & 
                                               ((IData)(top__DOT__u_cdc__DOT__u_core__DOT__u_sie_tx__DOT__u_crc16__DOT____VdfgRegularize_h8075a1a5_0_2) 
                                                ^ VL_REDXOR_8(
                                                              (0x0060U 
                                                               & (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_tx__DOT__crc_sum_q))))))) 
             << 0x0000000cU) | ((((2U & ((VL_REDXOR_8(
                                                      (0x30U 
                                                       & (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_tx__DOT__utmi_data_r))) 
                                          ^ (IData)(top__DOT__u_cdc__DOT__u_core__DOT__u_sie_tx__DOT__u_crc16__DOT____VdfgRegularize_h8075a1a5_0_7)) 
                                         << 1U)) | 
                                  (1U & ((IData)(top__DOT__u_cdc__DOT__u_core__DOT__u_sie_tx__DOT__u_crc16__DOT____VdfgRegularize_h8075a1a5_0_3) 
                                         ^ VL_REDXOR_8(
                                                       (0x0018U 
                                                        & (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_tx__DOT__crc_sum_q)))))) 
                                 << 0x0000000aU) | 
                                (((2U & ((VL_REDXOR_4(
                                                      (0x0cU 
                                                       & (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_tx__DOT__utmi_data_r))) 
                                          ^ (IData)(top__DOT__u_cdc__DOT__u_core__DOT__u_sie_tx__DOT__u_crc16__DOT____VdfgRegularize_h8075a1a5_0_6)) 
                                         << 1U)) | 
                                  (1U & (VL_REDXOR_4(
                                                     (6U 
                                                      & (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_tx__DOT__utmi_data_r))) 
                                         ^ VL_REDXOR_4(
                                                       (6U 
                                                        & (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_tx__DOT__crc_sum_q)))))) 
                                 << 8U))) | ((((((IData)(top__DOT__u_cdc__DOT__u_core__DOT__u_sie_tx__DOT__u_crc16__DOT____VdfgRegularize_h8075a1a5_0_0) 
                                                 ^ 
                                                 ((IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_tx__DOT__crc_sum_q) 
                                                  >> 0x0000000fU)) 
                                                ^ (IData)(top__DOT__u_cdc__DOT__u_core__DOT__u_sie_tx__DOT__u_crc16__DOT____VdfgRegularize_h8075a1a5_0_4)) 
                                               << 7U) 
                                              | (0x00000040U 
                                                 & (((IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_tx__DOT__utmi_data_r) 
                                                     ^ 
                                                     (((IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_tx__DOT__crc_sum_q) 
                                                       >> 0x0000000eU) 
                                                      ^ (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_tx__DOT__crc_sum_q))) 
                                                    << 6U))) 
                                             | ((0x0000003eU 
                                                 & ((IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_tx__DOT__crc_sum_q) 
                                                    >> 8U)) 
                                                | (1U 
                                                   & ((((IData)(top__DOT__u_cdc__DOT__u_core__DOT__u_sie_tx__DOT__u_crc16__DOT____VdfgRegularize_h8075a1a5_0_1) 
                                                        ^ 
                                                        VL_REDXOR_16(
                                                                     (0x013cU 
                                                                      & (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_tx__DOT__crc_sum_q)))) 
                                                       ^ (IData)(top__DOT__u_cdc__DOT__u_core__DOT__u_sie_tx__DOT__u_crc16__DOT____VdfgRegularize_h8075a1a5_0_5)) 
                                                      ^ (IData)(top__DOT__u_cdc__DOT__u_core__DOT__u_sie_tx__DOT__u_crc16__DOT____VdfgRegularize_h8075a1a5_0_4))))));
    vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__u_crc16__DOT__crc_out_o 
        = ((((((((IData)(top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__u_crc16__DOT____VdfgRegularize_h8075a1a5_0_1) 
                 ^ ((IData)(top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__u_crc16__DOT____VdfgRegularize_h8075a1a5_0_5) 
                    ^ (IData)(top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__u_crc16__DOT____VdfgRegularize_h8075a1a5_0_8))) 
                << 3U) | (4U & (((IData)(top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__u_crc16__DOT____VdfgRegularize_h8075a1a5_0_9) 
                                 ^ (((IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__crc_sum_q) 
                                     >> 6U) ^ (IData)(top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__u_crc16__DOT____VdfgRegularize_h8075a1a5_0_8))) 
                                << 2U))) | ((2U & (
                                                   (VL_REDXOR_8(
                                                                (0x000000c0U 
                                                                 & vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__data_buffer_q)) 
                                                    ^ (IData)(top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__u_crc16__DOT____VdfgRegularize_h8075a1a5_0_5)) 
                                                   << 1U)) 
                                            | (1U & 
                                               ((IData)(top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__u_crc16__DOT____VdfgRegularize_h8075a1a5_0_2) 
                                                ^ VL_REDXOR_8(
                                                              (0x0060U 
                                                               & (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__crc_sum_q))))))) 
             << 0x0000000cU) | ((((2U & ((VL_REDXOR_8(
                                                      (0x00000030U 
                                                       & vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__data_buffer_q)) 
                                          ^ (IData)(top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__u_crc16__DOT____VdfgRegularize_h8075a1a5_0_7)) 
                                         << 1U)) | 
                                  (1U & ((IData)(top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__u_crc16__DOT____VdfgRegularize_h8075a1a5_0_3) 
                                         ^ VL_REDXOR_8(
                                                       (0x0018U 
                                                        & (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__crc_sum_q)))))) 
                                 << 0x0000000aU) | 
                                (((2U & ((VL_REDXOR_4(
                                                      (0x0000000cU 
                                                       & vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__data_buffer_q)) 
                                          ^ (IData)(top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__u_crc16__DOT____VdfgRegularize_h8075a1a5_0_6)) 
                                         << 1U)) | 
                                  (1U & (VL_REDXOR_4(
                                                     (6U 
                                                      & vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__data_buffer_q)) 
                                         ^ VL_REDXOR_4(
                                                       (6U 
                                                        & (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__crc_sum_q)))))) 
                                 << 8U))) | ((((((IData)(top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__u_crc16__DOT____VdfgRegularize_h8075a1a5_0_0) 
                                                 ^ 
                                                 ((IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__crc_sum_q) 
                                                  >> 0x0000000fU)) 
                                                ^ (IData)(top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__u_crc16__DOT____VdfgRegularize_h8075a1a5_0_4)) 
                                               << 7U) 
                                              | (0x00000040U 
                                                 & ((vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__data_buffer_q 
                                                     ^ 
                                                     (((IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__crc_sum_q) 
                                                       >> 0x0000000eU) 
                                                      ^ (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__crc_sum_q))) 
                                                    << 6U))) 
                                             | ((0x0000003eU 
                                                 & ((IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__crc_sum_q) 
                                                    >> 8U)) 
                                                | (1U 
                                                   & ((((IData)(top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__u_crc16__DOT____VdfgRegularize_h8075a1a5_0_1) 
                                                        ^ 
                                                        VL_REDXOR_16(
                                                                     (0x013cU 
                                                                      & (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__crc_sum_q)))) 
                                                       ^ (IData)(top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__u_crc16__DOT____VdfgRegularize_h8075a1a5_0_5)) 
                                                      ^ (IData)(top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__u_crc16__DOT____VdfgRegularize_h8075a1a5_0_4))))));
}

void Vtop___024root___nba_sequent__TOP__2(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__2\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vdly__top__DOT__rst_sync = vlSelfRef.top__DOT__rst_sync;
    vlSelfRef.__Vdly__top__DOT__rst_sync = ((IData)(vlSelfRef.top__DOT__phy_rst)
                                             ? 7U : 
                                            (6U & ((IData)(vlSelfRef.top__DOT__rst_sync) 
                                                   << 1U)));
}

void Vtop___024root___nba_sequent__TOP__3(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__3\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*2:0*/ __Vdly__top__DOT__u_adc_wrap__DOT__u_adc_int__DOT__latency_counter;
    __Vdly__top__DOT__u_adc_wrap__DOT__u_adc_int__DOT__latency_counter = 0;
    SData/*14:0*/ __Vdly__top__DOT__u_adc_wrap__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__wr_ptr;
    __Vdly__top__DOT__u_adc_wrap__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__wr_ptr = 0;
    // Body
    __Vdly__top__DOT__u_adc_wrap__DOT__u_adc_int__DOT__latency_counter 
        = vlSelfRef.top__DOT__u_adc_wrap__DOT__u_adc_int__DOT__latency_counter;
    __Vdly__top__DOT__u_adc_wrap__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__wr_ptr 
        = vlSelfRef.top__DOT__u_adc_wrap__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__wr_ptr;
    if (vlSelfRef.top__DOT__u_adc_wrap__DOT__adc_rst_sync) {
        __Vdly__top__DOT__u_adc_wrap__DOT__u_adc_int__DOT__latency_counter = 7U;
        __Vdly__top__DOT__u_adc_wrap__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__wr_ptr = 0U;
        vlSelfRef.top__DOT__u_adc_wrap__DOT__adc_data = 0U;
    } else {
        __Vdly__top__DOT__u_adc_wrap__DOT__u_adc_int__DOT__latency_counter 
            = ((IData)(vlSelfRef.top__DOT__u_adc_wrap__DOT__u_adc_int__DOT__adc_ready)
                ? 0U : (7U & ((IData)(vlSelfRef.top__DOT__u_adc_wrap__DOT__u_adc_int__DOT__latency_counter) 
                              - (IData)(1U))));
        if (vlSelfRef.top__DOT__u_adc_wrap__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__u_dpdcram__DOT__wr_ena) {
            __Vdly__top__DOT__u_adc_wrap__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__wr_ptr 
                = (0x00007fffU & ((IData)(1U) + (IData)(vlSelfRef.top__DOT__u_adc_wrap__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__wr_ptr)));
        }
        vlSelfRef.top__DOT__u_adc_wrap__DOT__adc_data 
            = ((0U == (IData)(vlSelfRef.top__DOT__u_adc_wrap__DOT__u_adc_int__DOT__latency_counter))
                ? (IData)(vlSelfRef.adc_data_raw) : 0U);
    }
    vlSelfRef.adc_clk_out = (1U & (~ (IData)(vlSelfRef.top__DOT__u_adc_wrap__DOT__adc_rst_sync)));
    vlSelfRef.top__DOT__u_adc_wrap__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__wr_ptr 
        = __Vdly__top__DOT__u_adc_wrap__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__wr_ptr;
    vlSelfRef.top__DOT__u_adc_wrap__DOT__u_adc_int__DOT__latency_counter 
        = __Vdly__top__DOT__u_adc_wrap__DOT__u_adc_int__DOT__latency_counter;
    vlSelfRef.top__DOT__u_adc_wrap__DOT__u_adc_int__DOT__adc_ready 
        = (0U == (IData)(vlSelfRef.top__DOT__u_adc_wrap__DOT__u_adc_int__DOT__latency_counter));
}

void Vtop___024root___nba_sequent__TOP__4(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__4\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vdly__top__DOT__u_adc_wrap__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__rd_ptr 
        = vlSelfRef.top__DOT__u_adc_wrap__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__rd_ptr;
    if (vlSelfRef.top__DOT__u_adc_wrap__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__rd_a_rst) {
        vlSelfRef.__Vdly__top__DOT__u_adc_wrap__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__rd_ptr = 0U;
    } else if (vlSelfRef.top__DOT__u_adc_wrap__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__u_dpdcram__DOT__rd_ena) {
        vlSelfRef.__Vdly__top__DOT__u_adc_wrap__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__rd_ptr 
            = (0x00007fffU & ((IData)(1U) + (IData)(vlSelfRef.top__DOT__u_adc_wrap__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__rd_ptr)));
    }
}

void Vtop___024root___nba_sequent__TOP__5(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__5\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    SData/*14:0*/ __Vfunc_gray2bin__2__Vfuncout;
    __Vfunc_gray2bin__2__Vfuncout = 0;
    SData/*14:0*/ __Vfunc_gray2bin__2__gray;
    __Vfunc_gray2bin__2__gray = 0;
    // Body
    vlSelfRef.top__DOT__u_adc_wrap__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__wr_ptr_gray_rd 
        = vlSelfRef.top__DOT__u_adc_wrap__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__wr_ptr_ms;
    if (vlSelfRef.top__DOT__u_adc_wrap__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__u_dpdcram__DOT__rd_ena) {
        vlSelfRef.top__DOT__u_adc_wrap__DOT__u_dc_fifo__DOT__std_rd_data 
            = vlSelfRef.top__DOT__u_adc_wrap__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__u_dpdcram__DOT__mem
            [(0x00003fffU & (IData)(vlSelfRef.top__DOT__u_adc_wrap__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__rd_ptr))];
    }
    vlSelfRef.top__DOT__u_adc_wrap__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__wr_ptr_ms 
        = vlSelfRef.top__DOT__u_adc_wrap__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__wr_ptr_gray;
    __Vfunc_gray2bin__2__gray = vlSelfRef.top__DOT__u_adc_wrap__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__wr_ptr_gray_rd;
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
    vlSelfRef.top__DOT__u_adc_wrap__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__wr_ptr_rd 
        = __Vfunc_gray2bin__2__Vfuncout;
}

void Vtop___024root___nba_sequent__TOP__6(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__6\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSelfRef.__VdlySet__top__DOT__u_adc_wrap__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__u_dpdcram__DOT__mem__v0) {
        vlSelfRef.top__DOT__u_adc_wrap__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__u_dpdcram__DOT__mem[vlSelfRef.__VdlyDim0__top__DOT__u_adc_wrap__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__u_dpdcram__DOT__mem__v0] 
            = vlSelfRef.__VdlyVal__top__DOT__u_adc_wrap__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__u_dpdcram__DOT__mem__v0;
    }
    if ((0x0003d090U > vlSelfRef.top__DOT__rst_cnt)) {
        vlSelfRef.top__DOT__rst_cnt = (0x000fffffU 
                                       & ((IData)(1U) 
                                          + vlSelfRef.top__DOT__rst_cnt));
        vlSelfRef.top__DOT__phy_rst = 1U;
    } else {
        vlSelfRef.top__DOT__rst_cnt = 0x0003d090U;
        vlSelfRef.top__DOT__phy_rst = 0U;
    }
    vlSelfRef.ulpi_reset = vlSelfRef.top__DOT__phy_rst;
}

void Vtop___024root___nba_sequent__TOP__7(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__7\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.top__DOT__u_adc_wrap__DOT__adc_rst_sync 
        = ((1U & ((IData)(vlSelfRef.top__DOT__rst_sync) 
                  >> 2U)) || (IData)(vlSelfRef.top__DOT__u_adc_wrap__DOT__adc_rst_ms));
    vlSelfRef.top__DOT__u_adc_wrap__DOT__adc_rst_ms 
        = (1U & ((IData)(vlSelfRef.top__DOT__rst_sync) 
                 >> 2U));
}

void Vtop___024root___nba_sequent__TOP__8(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__8\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.top__DOT__u_adc_wrap__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__rd_a_rst 
        = ((1U & ((IData)(vlSelfRef.top__DOT__rst_sync) 
                  >> 2U)) || (IData)(vlSelfRef.top__DOT__u_adc_wrap__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__rd_a_rst_ms));
    vlSelfRef.top__DOT__u_adc_wrap__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__rd_a_rst_ms 
        = (1U & ((IData)(vlSelfRef.top__DOT__rst_sync) 
                 >> 2U));
}

void Vtop___024root___nba_sequent__TOP__9(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__9\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.top__DOT__u_adc_wrap__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__rd_ptr 
        = vlSelfRef.__Vdly__top__DOT__u_adc_wrap__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__rd_ptr;
    vlSelfRef.top__DOT__u_adc_wrap__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__rd_ptr_gray 
        = ((IData)(vlSelfRef.top__DOT__u_adc_wrap__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__rd_ptr) 
           ^ VL_SHIFTR_III(15,15,32, (IData)(vlSelfRef.top__DOT__u_adc_wrap__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__rd_ptr), 1U));
}

void Vtop___024root___nba_sequent__TOP__10(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__10\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.top__DOT__u_adc_wrap__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__wr_ptr_gray 
        = ((IData)(vlSelfRef.top__DOT__u_adc_wrap__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__wr_ptr) 
           ^ VL_SHIFTR_III(15,15,32, (IData)(vlSelfRef.top__DOT__u_adc_wrap__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__wr_ptr), 1U));
}

void Vtop___024root___nba_sequent__TOP__11(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__11\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.top__DOT__rst_sync = vlSelfRef.__Vdly__top__DOT__rst_sync;
    vlSelfRef.led_b = (1U & (~ ((IData)(vlSelfRef.top__DOT__rst_sync) 
                                >> 2U)));
    vlSelfRef.top__DOT__cdc_rst = (1U & ((IData)(vlSelfRef.top__DOT__rst_sync) 
                                         >> 2U));
}

void Vtop___024root___nba_comb__TOP__0(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_comb__TOP__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSelfRef.top__DOT__u_adc_wrap__DOT__current_state) {
        vlSelfRef.top__DOT__u_adc_wrap__DOT__next_state = 1U;
        if (((0x01ffU == (IData)(vlSelfRef.top__DOT__u_adc_wrap__DOT__burst_count)) 
             & (IData)(vlSelfRef.top__DOT__u_adc_wrap__DOT__byte_sent))) {
            vlSelfRef.top__DOT__u_adc_wrap__DOT__next_state = 0U;
        }
    } else {
        vlSelfRef.top__DOT__u_adc_wrap__DOT__next_state = 0U;
        if ((0x0400U <= (0x00007fffU & (((IData)(vlSelfRef.top__DOT__u_adc_wrap__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__wr_ptr_rd) 
                                         - (IData)(vlSelfRef.top__DOT__u_adc_wrap__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__rd_ptr)) 
                                        + ((IData)(vlSelfRef.top__DOT__u_adc_wrap__DOT__u_dc_fifo__DOT__data_out_valid) 
                                           + ((IData)(vlSelfRef.top__DOT__u_adc_wrap__DOT__u_dc_fifo__DOT__middle_valid) 
                                              + (IData)(vlSelfRef.top__DOT__u_adc_wrap__DOT__u_dc_fifo__DOT__fall_through))))))) {
            vlSelfRef.top__DOT__u_adc_wrap__DOT__next_state = 1U;
        }
    }
    vlSelfRef.top__DOT__u_adc_wrap__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__u_dpdcram__DOT__rd_ena 
        = (((IData)(vlSelfRef.top__DOT__u_adc_wrap__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__rd_ptr_gray) 
            != (IData)(vlSelfRef.top__DOT__u_adc_wrap__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__wr_ptr_gray_rd)) 
           & ((~ (IData)(vlSelfRef.top__DOT__u_adc_wrap__DOT__u_dc_fifo__DOT__data_out_valid)) 
              | ((~ (IData)(vlSelfRef.top__DOT__u_adc_wrap__DOT__u_dc_fifo__DOT__middle_valid)) 
                 | (IData)(vlSelfRef.top__DOT__u_adc_wrap__DOT__u_dc_fifo__DOT__rd_ena))));
}

void Vtop___024root___nba_comb__TOP__1(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_comb__TOP__1\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.top__DOT__u_adc_wrap__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__u_dpdcram__DOT__wr_ena 
        = (((IData)(vlSelfRef.top__DOT__u_adc_wrap__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__wr_ptr_gray) 
            != ((0x00006000U & ((~ ((IData)(vlSelfRef.top__DOT__u_adc_wrap__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__rd_ptr_gray_wr) 
                                    >> 0x0000000dU)) 
                                << 0x0000000dU)) | 
                (0x00001fffU & (IData)(vlSelfRef.top__DOT__u_adc_wrap__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__rd_ptr_gray_wr)))) 
           & (0U == (IData)(vlSelfRef.top__DOT__u_adc_wrap__DOT__u_adc_int__DOT__latency_counter)));
}

void Vtop___024root___eval_nba(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_nba\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vtop___024root___nba_sequent__TOP__0(vlSelf);
        vlSelfRef.__Vm_traceActivity[1U] = 1U;
    }
    if ((0x000000000000000cULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vtop___024root___nba_sequent__TOP__1(vlSelf);
        vlSelfRef.__Vm_traceActivity[2U] = 1U;
    }
    if ((6ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vtop___024root___nba_sequent__TOP__2(vlSelf);
    }
    if ((0x0000000000000011ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vtop___024root___nba_sequent__TOP__3(vlSelf);
        vlSelfRef.__Vm_traceActivity[3U] = 1U;
    }
    if ((0x0000000000000024ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vtop___024root___nba_sequent__TOP__4(vlSelf);
    }
    if ((4ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vtop___024root___nba_sequent__TOP__5(vlSelf);
        vlSelfRef.__Vm_traceActivity[4U] = 1U;
    }
    if ((1ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vtop___024root___nba_sequent__TOP__6(vlSelf);
    }
    if ((9ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vtop___024root___nba_sequent__TOP__7(vlSelf);
    }
    if ((0x000000000000000cULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vtop___024root___nba_sequent__TOP__8(vlSelf);
    }
    if ((0x0000000000000024ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vtop___024root___nba_sequent__TOP__9(vlSelf);
        vlSelfRef.__Vm_traceActivity[5U] = 1U;
    }
    if ((0x0000000000000011ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vtop___024root___nba_sequent__TOP__10(vlSelf);
    }
    if ((6ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vtop___024root___nba_sequent__TOP__11(vlSelf);
    }
    if ((0x000000000000002cULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vtop___024root___nba_comb__TOP__0(vlSelf);
    }
    if ((0x0000000000000011ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vtop___024root___nba_comb__TOP__1(vlSelf);
    }
}

void Vtop___024root___trigger_orInto__act_vec_vec(VlUnpacked<QData/*63:0*/, 1> &out, const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___trigger_orInto__act_vec_vec\n"); );
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
VL_ATTR_COLD void Vtop___024root___dump_triggers__act(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG

bool Vtop___024root___eval_phase__act(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_phase__act\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vtop___024root___eval_triggers_vec__act(vlSelf);
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtop___024root___dump_triggers__act(vlSelfRef.__VactTriggered, "act"s);
    }
#endif
    Vtop___024root___trigger_orInto__act_vec_vec(vlSelfRef.__VnbaTriggered, vlSelfRef.__VactTriggered);
    return (0U);
}

void Vtop___024root___trigger_clear__act(VlUnpacked<QData/*63:0*/, 1> &out) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___trigger_clear__act\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        out[n] = 0ULL;
        n = ((IData)(1U) + n);
    } while ((1U > n));
}

bool Vtop___024root___eval_phase__nba(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_phase__nba\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = Vtop___024root___trigger_anySet__act(vlSelfRef.__VnbaTriggered);
    if (__VnbaExecute) {
        Vtop___024root___eval_nba(vlSelf);
        Vtop___024root___trigger_clear__act(vlSelfRef.__VnbaTriggered);
    }
    return (__VnbaExecute);
}

void Vtop___024root___eval(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
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
            Vtop___024root___dump_triggers__ico(vlSelfRef.__VicoTriggered, "ico"s);
#endif
            VL_FATAL_MT("../hdl/top.v", 1, "", "DIDNOTCONVERGE: Input combinational region did not converge after '--converge-limit' of 100 tries");
        }
        __VicoIterCount = ((IData)(1U) + __VicoIterCount);
        vlSelfRef.__VicoPhaseResult = Vtop___024root___eval_phase__ico(vlSelf);
        vlSelfRef.__VicoFirstIteration = 0U;
    } while (vlSelfRef.__VicoPhaseResult);
    __VnbaIterCount = 0U;
    do {
        if (VL_UNLIKELY(((0x00000064U < __VnbaIterCount)))) {
#ifdef VL_DEBUG
            Vtop___024root___dump_triggers__act(vlSelfRef.__VnbaTriggered, "nba"s);
#endif
            VL_FATAL_MT("../hdl/top.v", 1, "", "DIDNOTCONVERGE: NBA region did not converge after '--converge-limit' of 100 tries");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        vlSelfRef.__VactIterCount = 0U;
        do {
            if (VL_UNLIKELY(((0x00000064U < vlSelfRef.__VactIterCount)))) {
#ifdef VL_DEBUG
                Vtop___024root___dump_triggers__act(vlSelfRef.__VactTriggered, "act"s);
#endif
                VL_FATAL_MT("../hdl/top.v", 1, "", "DIDNOTCONVERGE: Active region did not converge after '--converge-limit' of 100 tries");
            }
            vlSelfRef.__VactIterCount = ((IData)(1U) 
                                         + vlSelfRef.__VactIterCount);
            vlSelfRef.__VactPhaseResult = Vtop___024root___eval_phase__act(vlSelf);
        } while (vlSelfRef.__VactPhaseResult);
        vlSelfRef.__VnbaPhaseResult = Vtop___024root___eval_phase__nba(vlSelf);
    } while (vlSelfRef.__VnbaPhaseResult);
}

#ifdef VL_DEBUG
void Vtop___024root___eval_debug_assertions(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_debug_assertions\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (VL_UNLIKELY(((vlSelfRef.clk_25m & 0xfeU)))) {
        Verilated::overWidthError("clk_25m");
    }
    if (VL_UNLIKELY(((vlSelfRef.ulpi_clk60 & 0xfeU)))) {
        Verilated::overWidthError("ulpi_clk60");
    }
    if (VL_UNLIKELY(((vlSelfRef.ulpi_dir & 0xfeU)))) {
        Verilated::overWidthError("ulpi_dir");
    }
    if (VL_UNLIKELY(((vlSelfRef.ulpi_nxt & 0xfeU)))) {
        Verilated::overWidthError("ulpi_nxt");
    }
    if (VL_UNLIKELY(((vlSelfRef.adc_otr & 0xfeU)))) {
        Verilated::overWidthError("adc_otr");
    }
    if (VL_UNLIKELY(((vlSelfRef.adc_data_raw & 0xf000U)))) {
        Verilated::overWidthError("adc_data_raw");
    }
}
#endif  // VL_DEBUG
