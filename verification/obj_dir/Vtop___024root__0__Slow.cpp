// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"

VL_ATTR_COLD void Vtop___024root___eval_static__TOP(Vtop___024root* vlSelf);
VL_ATTR_COLD void Vtop___024root____Vm_traceActivitySetAll(Vtop___024root* vlSelf);
VL_ATTR_COLD void Vtop_utils_pkg___eval_static__TOP__utils_pkg(Vtop_utils_pkg* vlSelf);

VL_ATTR_COLD void Vtop___024root___eval_static(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_static\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vtop___024root___eval_static__TOP(vlSelf);
    Vtop___024root____Vm_traceActivitySetAll(vlSelf);
    Vtop_utils_pkg___eval_static__TOP__utils_pkg((&vlSymsp->TOP__utils_pkg));
    vlSelfRef.__Vtrigprevexpr___TOP__clk_25m__0 = vlSelfRef.clk_25m;
    vlSelfRef.__Vtrigprevexpr___TOP__top__DOT__phy_rst__0 = 1U;
    vlSelfRef.__Vtrigprevexpr___TOP__ulpi_clk60__0 
        = vlSelfRef.ulpi_clk60;
    vlSelfRef.__Vtrigprevexpr___TOP__top__DOT__cdc_rst__0 
        = vlSelfRef.top__DOT__cdc_rst;
    vlSelfRef.__Vtrigprevexpr___TOP__top__DOT__u_adc_wrap__DOT__adc_rst_sync__0 
        = vlSelfRef.top__DOT__u_adc_wrap__DOT__adc_rst_sync;
    vlSelfRef.__Vtrigprevexpr___TOP__top__DOT__u_adc_wrap__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__rd_a_rst__0 
        = vlSelfRef.top__DOT__u_adc_wrap__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__rd_a_rst;
}

VL_ATTR_COLD void Vtop___024root___eval_static__TOP(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_static__TOP\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.top__DOT__rst_cnt = 0U;
    vlSelfRef.top__DOT__phy_rst = 1U;
    vlSelfRef.top__DOT__rst_sync = 7U;
    vlSelfRef.top__DOT__startup_timer = 0U;
    vlSelfRef.top__DOT__ready_for_leds = 0U;
    vlSelfRef.top__DOT__tx_seen = 0U;
}

VL_ATTR_COLD void Vtop___024root___eval_initial__TOP(Vtop___024root* vlSelf);

VL_ATTR_COLD void Vtop___024root___eval_initial(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_initial\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vtop___024root___eval_initial__TOP(vlSelf);
    Vtop___024root____Vm_traceActivitySetAll(vlSelf);
}

VL_ATTR_COLD void Vtop___024root___eval_initial__TOP(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_initial__TOP\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSymsp->TOP__utils_pkg.gray2bin__Vstatic__i = 0x00000010U;
    vlSelfRef.led_r = 0U;
}

VL_ATTR_COLD void Vtop___024root___eval_final(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_final\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__stl(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG
VL_ATTR_COLD bool Vtop___024root___eval_phase__stl(Vtop___024root* vlSelf);

VL_ATTR_COLD void Vtop___024root___eval_settle(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_settle\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ __VstlIterCount;
    // Body
    __VstlIterCount = 0U;
    vlSelfRef.__VstlFirstIteration = 1U;
    do {
        if (VL_UNLIKELY(((0x00000064U < __VstlIterCount)))) {
#ifdef VL_DEBUG
            Vtop___024root___dump_triggers__stl(vlSelfRef.__VstlTriggered, "stl"s);
#endif
            VL_FATAL_MT("../hdl/top.v", 1, "", "DIDNOTCONVERGE: Settle region did not converge after '--converge-limit' of 100 tries");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
        vlSelfRef.__VstlPhaseResult = Vtop___024root___eval_phase__stl(vlSelf);
        vlSelfRef.__VstlFirstIteration = 0U;
    } while (vlSelfRef.__VstlPhaseResult);
}

VL_ATTR_COLD void Vtop___024root___eval_triggers_vec__stl(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_triggers_vec__stl\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VstlTriggered[0U] = ((0xfffffffffffffffeULL 
                                      & vlSelfRef.__VstlTriggered[0U]) 
                                     | (IData)((IData)(vlSelfRef.__VstlFirstIteration)));
}

VL_ATTR_COLD bool Vtop___024root___trigger_anySet__stl(const VlUnpacked<QData/*63:0*/, 1> &in);

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__stl(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___dump_triggers__stl\n"); );
    // Body
    if ((1U & (~ (IData)(Vtop___024root___trigger_anySet__stl(triggers))))) {
        VL_DBG_MSGS("         No '" + tag + "' region triggers active\n");
    }
    if ((1U & (IData)(triggers[0U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD bool Vtop___024root___trigger_anySet__stl(const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___trigger_anySet__stl\n"); );
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

extern const VlUnpacked<VlWide<3>/*79:0*/, 8> Vtop__ConstPool__TABLE_h646b3b33_0;
extern const VlUnpacked<CData/*0:0*/, 16> Vtop__ConstPool__TABLE_hae65a50a_0;
extern const VlUnpacked<CData/*7:0*/, 512> Vtop__ConstPool__TABLE_h84190edb_0;
extern const VlUnpacked<CData/*2:0*/, 2048> Vtop__ConstPool__TABLE_h5eabb7eb_0;

VL_ATTR_COLD void Vtop___024root___stl_sequent__TOP__0(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___stl_sequent__TOP__0\n"); );
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
    SData/*14:0*/ __Vfunc_gray2bin__2__Vfuncout;
    __Vfunc_gray2bin__2__Vfuncout = 0;
    SData/*14:0*/ __Vfunc_gray2bin__2__gray;
    __Vfunc_gray2bin__2__gray = 0;
    SData/*14:0*/ __Vfunc_gray2bin__3__Vfuncout;
    __Vfunc_gray2bin__3__Vfuncout = 0;
    SData/*14:0*/ __Vfunc_gray2bin__3__gray;
    __Vfunc_gray2bin__3__gray = 0;
    CData/*3:0*/ __Vtableidx1;
    __Vtableidx1 = 0;
    CData/*2:0*/ __Vtableidx2;
    __Vtableidx2 = 0;
    SData/*10:0*/ __Vtableidx3;
    __Vtableidx3 = 0;
    SData/*8:0*/ __Vtableidx4;
    __Vtableidx4 = 0;
    // Body
    vlSelfRef.top__DOT__u_cdc__DOT__genblk1__DOT__utmi_op_mode_r = 1U;
    vlSelfRef.top__DOT__u_cdc__DOT__genblk1__DOT__utmi_dmpulldown_r = 0U;
    vlSelfRef.top__DOT__u_cdc__DOT__genblk1__DOT__utmi_dppulldown_r = 0U;
    vlSelfRef.top__DOT__u_cdc__DOT__genblk1__DOT__utmi_termselect_r = 0U;
    vlSelfRef.top__DOT__u_cdc__DOT__genblk1__DOT__utmi_xcvrselect_r = 0U;
    vlSelfRef.ulpi_stp = vlSelfRef.top__DOT__u_ulpi__DOT__ulpi_stp_q;
    vlSelfRef.ulpi_reset = vlSelfRef.top__DOT__phy_rst;
    vlSelfRef.led_g = vlSelfRef.top__DOT__tx_seen;
    vlSelfRef.led_b = (1U & (~ ((IData)(vlSelfRef.top__DOT__rst_sync) 
                                >> 2U)));
    vlSelfRef.top__DOT__cdc_rst = (1U & ((IData)(vlSelfRef.top__DOT__rst_sync) 
                                         >> 2U));
    vlSelfRef.top__DOT__u_adc_wrap__DOT__u_adc_int__DOT__adc_ready 
        = (0U == (IData)(vlSelfRef.top__DOT__u_adc_wrap__DOT__u_adc_int__DOT__latency_counter));
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
    vlSelfRef.top__DOT__u_cdc__DOT__ep0_rx_setup_w 
        = ((IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__rx_setup_q) 
           & (0U == (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__token_ep_q)));
    vlSelfRef.top__DOT__u_ulpi__DOT__utmi_tx_ready_w 
        = vlSelfRef.top__DOT__u_ulpi__DOT__tx_valid_q
        [vlSelfRef.top__DOT__u_ulpi__DOT__tx_rd_idx_q];
    vlSelfRef.top__DOT__u_ulpi__DOT__utmi_tx_data_w 
        = vlSelfRef.top__DOT__u_ulpi__DOT__tx_buffer_q
        [vlSelfRef.top__DOT__u_ulpi__DOT__tx_rd_idx_q];
    vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__shift_en_w 
        = (1U & ((~ (IData)(vlSelfRef.top__DOT__u_ulpi__DOT__utmi_rxactive_q)) 
                 | ((IData)(vlSelfRef.top__DOT__u_ulpi__DOT__utmi_rxactive_q) 
                    & (IData)(vlSelfRef.top__DOT__u_ulpi__DOT__utmi_rxvalid_q))));
    vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT____Vcellinp__u_sie_rx__enable_i 
        = ((~ ((IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__se0_cnt_q) 
               >> 0x0000000eU)) & (2U != (IData)(vlSelfRef.top__DOT__u_cdc__DOT__genblk1__DOT__state_q)));
    vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__address_match_w 
        = ((IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__current_addr_q) 
           == (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__token_dev_q));
    vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__tx_data_strb_r = 0U;
    vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__input_ready_w 
        = ((6U == (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__state_q)) 
           & ((~ (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__data_crc_q)) 
              & (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__data_valid_q)));
    vlSelfRef.top__DOT__u_cdc__DOT__genblk1__DOT__next_state_r 
        = vlSelfRef.top__DOT__u_cdc__DOT__genblk1__DOT__state_q;
    if ((4U & (IData)(vlSelfRef.top__DOT__u_cdc__DOT__genblk1__DOT__state_q))) {
        if ((1U & (~ ((IData)(vlSelfRef.top__DOT__u_cdc__DOT__genblk1__DOT__state_q) 
                      >> 1U)))) {
            vlSelfRef.top__DOT__u_cdc__DOT__genblk1__DOT__utmi_op_mode_r = 0U;
            vlSelfRef.top__DOT__u_cdc__DOT__genblk1__DOT__utmi_dmpulldown_r = 0U;
            vlSelfRef.top__DOT__u_cdc__DOT__genblk1__DOT__utmi_dppulldown_r = 0U;
            vlSelfRef.top__DOT__u_cdc__DOT__genblk1__DOT__utmi_termselect_r 
                = (1U & (~ (IData)(vlSelfRef.top__DOT__u_cdc__DOT__genblk1__DOT__state_q)));
            if ((1U & (IData)(vlSelfRef.top__DOT__u_cdc__DOT__genblk1__DOT__state_q))) {
                vlSelfRef.top__DOT__u_cdc__DOT__genblk1__DOT__utmi_xcvrselect_r = 0U;
                if (((0x000927c0U <= vlSelfRef.top__DOT__u_cdc__DOT__genblk1__DOT__usb_rst_time_q) 
                     & (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__rst_event_q))) {
                    vlSelfRef.top__DOT__u_cdc__DOT__genblk1__DOT__next_state_r = 1U;
                }
            } else {
                vlSelfRef.top__DOT__u_cdc__DOT__genblk1__DOT__utmi_xcvrselect_r = 1U;
                if (((0x000927c0U <= vlSelfRef.top__DOT__u_cdc__DOT__genblk1__DOT__usb_rst_time_q) 
                     & (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__rst_event_q))) {
                    vlSelfRef.top__DOT__u_cdc__DOT__genblk1__DOT__next_state_r = 1U;
                }
            }
        }
    } else if ((2U & (IData)(vlSelfRef.top__DOT__u_cdc__DOT__genblk1__DOT__state_q))) {
        vlSelfRef.top__DOT__u_cdc__DOT__genblk1__DOT__utmi_op_mode_r = 2U;
        vlSelfRef.top__DOT__u_cdc__DOT__genblk1__DOT__utmi_dmpulldown_r = 0U;
        vlSelfRef.top__DOT__u_cdc__DOT__genblk1__DOT__utmi_dppulldown_r = 0U;
        vlSelfRef.top__DOT__u_cdc__DOT__genblk1__DOT__utmi_termselect_r = 1U;
        vlSelfRef.top__DOT__u_cdc__DOT__genblk1__DOT__utmi_xcvrselect_r = 0U;
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
        vlSelfRef.top__DOT__u_cdc__DOT__genblk1__DOT__utmi_op_mode_r = 0U;
        vlSelfRef.top__DOT__u_cdc__DOT__genblk1__DOT__utmi_dmpulldown_r = 0U;
        vlSelfRef.top__DOT__u_cdc__DOT__genblk1__DOT__utmi_dppulldown_r = 0U;
        vlSelfRef.top__DOT__u_cdc__DOT__genblk1__DOT__utmi_termselect_r = 1U;
        vlSelfRef.top__DOT__u_cdc__DOT__genblk1__DOT__utmi_xcvrselect_r = 1U;
        if ((0x00007530U <= vlSelfRef.top__DOT__u_cdc__DOT__genblk1__DOT__usb_rst_time_q)) {
            vlSelfRef.top__DOT__u_cdc__DOT__genblk1__DOT__next_state_r = 2U;
        }
    } else if ((0x00000bb8U <= vlSelfRef.top__DOT__u_cdc__DOT__genblk1__DOT__usb_rst_time_q)) {
        vlSelfRef.top__DOT__u_cdc__DOT__genblk1__DOT__next_state_r = 1U;
    }
    __Vtableidx2 = vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__state_q;
    vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__dbg_state[0U] 
        = Vtop__ConstPool__TABLE_h646b3b33_0[__Vtableidx2][0U];
    vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__dbg_state[1U] 
        = Vtop__ConstPool__TABLE_h646b3b33_0[__Vtableidx2][1U];
    vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__dbg_state[2U] 
        = Vtop__ConstPool__TABLE_h646b3b33_0[__Vtableidx2][2U];
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
    __Vtableidx1 = vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__token_ep_q;
    vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__cfg_int_rx_r 
        = Vtop__ConstPool__TABLE_hae65a50a_0[__Vtableidx1];
    vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__cfg_int_tx_r 
        = Vtop__ConstPool__TABLE_hae65a50a_0[__Vtableidx1];
    vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT____VdfgRegularize_h04591d3f_0_4 
        = ((IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__rx_enable_q) 
           & (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__valid_q));
    vlSelfRef.top__DOT__u_adc_wrap__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__wr_ptr_gray 
        = ((IData)(vlSelfRef.top__DOT__u_adc_wrap__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__wr_ptr) 
           ^ VL_SHIFTR_III(15,15,32, (IData)(vlSelfRef.top__DOT__u_adc_wrap__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__wr_ptr), 1U));
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
    vlSelfRef.top__DOT__u_adc_wrap__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__rd_ptr_gray 
        = ((IData)(vlSelfRef.top__DOT__u_adc_wrap__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__rd_ptr) 
           ^ VL_SHIFTR_III(15,15,32, (IData)(vlSelfRef.top__DOT__u_adc_wrap__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__rd_ptr), 1U));
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
    top__DOT__u_cdc__DOT__u_core__DOT__u_sie_tx__DOT__u_crc16__DOT____VdfgRegularize_h8075a1a5_0_5 
        = (1U & VL_REDXOR_8((0x00c0U & (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_tx__DOT__crc_sum_q))));
    top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__u_crc16__DOT____VdfgRegularize_h8075a1a5_0_5 
        = (1U & VL_REDXOR_8((0x00c0U & (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__crc_sum_q))));
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
    vlSelfRef.top__DOT__u_cdc__DOT__rx_last_w = (1U 
                                                 & ((IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__last_q) 
                                                    | (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__data_crc_q)));
    vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__in_data_bit_r = 0U;
    top__DOT__u_cdc__DOT__u_core__DOT__u_sie_tx__DOT__u_crc16__DOT____VdfgRegularize_h8075a1a5_0_7 
        = (1U & VL_REDXOR_8((0x0030U & (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_tx__DOT__crc_sum_q))));
    top__DOT__u_cdc__DOT__u_core__DOT__u_sie_tx__DOT__u_crc16__DOT____VdfgRegularize_h8075a1a5_0_6 
        = (1U & VL_REDXOR_4((0x000cU & (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_tx__DOT__crc_sum_q))));
    top__DOT__u_cdc__DOT__u_core__DOT__u_sie_tx__DOT__u_crc16__DOT____VdfgRegularize_h8075a1a5_0_4 
        = (1U & (((IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_tx__DOT__crc_sum_q) 
                  >> 1U) ^ (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_tx__DOT__crc_sum_q)));
    top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__u_crc16__DOT____VdfgRegularize_h8075a1a5_0_7 
        = (1U & VL_REDXOR_8((0x0030U & (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__crc_sum_q))));
    top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__u_crc16__DOT____VdfgRegularize_h8075a1a5_0_6 
        = (1U & VL_REDXOR_4((0x000cU & (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__crc_sum_q))));
    top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__u_crc16__DOT____VdfgRegularize_h8075a1a5_0_4 
        = (1U & (((IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__crc_sum_q) 
                  >> 1U) ^ (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__crc_sum_q)));
    vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__rx_space_r = 0U;
    vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__tx_ready_r = 0U;
    __Vtableidx4 = (((5U == (IData)(vlSelfRef.top__DOT__u_cdc__DOT__genblk1__DOT__state_q)) 
                     << 8U) | (IData)(vlSelfRef.top__DOT__u_cdc__DOT__desc_addr_q));
    vlSelfRef.top__DOT__u_cdc__DOT__u_rom__DOT__desc_rom_r 
        = Vtop__ConstPool__TABLE_h84190edb_0[__Vtableidx4];
    vlSelfRef.top__DOT__u_cdc__DOT__ep2_tx_data_last_w 
        = ((IData)(vlSelfRef.top__DOT__u_cdc__DOT__inport_cnt_q) 
           == ((5U == (IData)(vlSelfRef.top__DOT__u_cdc__DOT__genblk1__DOT__state_q))
                ? 0x01ffU : 0x003fU));
    vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__tx_data_valid_r = 0U;
    vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__ep_stall_r = 0U;
    vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__out_data_bit_r = 0U;
    top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__u_crc16__DOT____VdfgRegularize_h8075a1a5_0_2 
        = (1U & VL_REDXOR_8((0x00000060U & vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__data_buffer_q)));
    top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__u_crc16__DOT____VdfgRegularize_h8075a1a5_0_3 
        = (1U & VL_REDXOR_8((0x00000018U & vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__data_buffer_q)));
    top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__u_crc16__DOT____VdfgRegularize_h8075a1a5_0_0 
        = (1U & (vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__data_buffer_q 
                 ^ (vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__data_buffer_q 
                    >> 1U)));
    vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__ep_iso_r = 0U;
    vlSelfRef.top__DOT__u_cdc__DOT__wIndex_w = ((vlSelfRef.top__DOT__u_cdc__DOT__setup_packet_q[5U] 
                                                 << 8U) 
                                                | vlSelfRef.top__DOT__u_cdc__DOT__setup_packet_q[4U]);
    vlSelfRef.top__DOT__u_cdc__DOT__wValue_w = ((vlSelfRef.top__DOT__u_cdc__DOT__setup_packet_q[3U] 
                                                 << 8U) 
                                                | vlSelfRef.top__DOT__u_cdc__DOT__setup_packet_q[2U]);
    vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__tx_data_r = 0U;
    vlSelfRef.top__DOT__utmi_txready_wrapper = ((~ vlSelfRef.top__DOT__u_ulpi__DOT__tx_valid_q
                                                 [vlSelfRef.top__DOT__u_ulpi__DOT__tx_wr_idx_q]) 
                                                & (0U 
                                                   == (IData)(vlSelfRef.top__DOT__u_ulpi__DOT__tx_delay_q)));
    vlSelfRef.top__DOT__u_cdc__DOT__wLength = ((vlSelfRef.top__DOT__u_cdc__DOT__setup_packet_q[7U] 
                                                << 8U) 
                                               | vlSelfRef.top__DOT__u_cdc__DOT__setup_packet_q[6U]);
    vlSelfRef.top__DOT__u_cdc__DOT__setup_set_w = (
                                                   (~ 
                                                    (vlSelfRef.top__DOT__u_cdc__DOT__setup_packet_q[0U] 
                                                     >> 7U)) 
                                                   & (IData)(vlSelfRef.top__DOT__u_cdc__DOT__setup_valid_q));
    vlSelfRef.top__DOT__u_cdc__DOT__ep0_rx_valid_w 
        = ((IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT____VdfgRegularize_h04591d3f_0_4) 
           & (0U == (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__token_ep_q)));
    vlSelfRef.top__DOT__u_adc_wrap__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__u_dpdcram__DOT__wr_ena 
        = (((IData)(vlSelfRef.top__DOT__u_adc_wrap__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__wr_ptr_gray) 
            != ((0x00006000U & ((~ ((IData)(vlSelfRef.top__DOT__u_adc_wrap__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__rd_ptr_gray_wr) 
                                    >> 0x0000000dU)) 
                                << 0x0000000dU)) | 
                (0x00001fffU & (IData)(vlSelfRef.top__DOT__u_adc_wrap__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__rd_ptr_gray_wr)))) 
           & (0U == (IData)(vlSelfRef.top__DOT__u_adc_wrap__DOT__u_adc_int__DOT__latency_counter)));
    if ((1U & (~ ((IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__token_ep_q) 
                  >> 3U)))) {
        if ((1U & (~ ((IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__token_ep_q) 
                      >> 2U)))) {
            if ((2U & (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__token_ep_q))) {
                vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__tx_data_strb_r 
                    = ((1U & (~ (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__token_ep_q))) 
                       && (IData)(vlSelfRef.top__DOT__u_cdc__DOT__inport_valid_q));
                vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__in_data_bit_r 
                    = ((1U & (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__token_ep_q))
                        ? (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__ep3_in_data_bit_q)
                        : (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__ep2_in_data_bit_q));
            } else {
                vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__tx_data_strb_r 
                    = ((1U & (~ (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__token_ep_q))) 
                       && (IData)(vlSelfRef.top__DOT__u_cdc__DOT__ctrl_txstrb_q));
                vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__in_data_bit_r 
                    = ((1U & (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__token_ep_q))
                        ? (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__ep1_in_data_bit_q)
                        : (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__ep0_in_data_bit_q));
            }
        }
    }
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
    top__DOT__u_cdc__DOT__u_core__DOT__u_sie_tx__DOT__u_crc16__DOT____VdfgRegularize_h8075a1a5_0_8 
        = ((IData)(top__DOT__u_cdc__DOT__u_core__DOT__u_sie_tx__DOT__u_crc16__DOT____VdfgRegularize_h8075a1a5_0_7) 
           ^ ((IData)(top__DOT__u_cdc__DOT__u_core__DOT__u_sie_tx__DOT__u_crc16__DOT____VdfgRegularize_h8075a1a5_0_6) 
              ^ (IData)(top__DOT__u_cdc__DOT__u_core__DOT__u_sie_tx__DOT__u_crc16__DOT____VdfgRegularize_h8075a1a5_0_4)));
    top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__u_crc16__DOT____VdfgRegularize_h8075a1a5_0_8 
        = ((IData)(top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__u_crc16__DOT____VdfgRegularize_h8075a1a5_0_7) 
           ^ ((IData)(top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__u_crc16__DOT____VdfgRegularize_h8075a1a5_0_6) 
              ^ (IData)(top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__u_crc16__DOT____VdfgRegularize_h8075a1a5_0_4)));
    vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__tx_data_last_r = 0U;
    if ((1U & (~ ((IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__token_ep_q) 
                  >> 3U)))) {
        if ((1U & (~ ((IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__token_ep_q) 
                      >> 2U)))) {
            vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__rx_space_r 
                = (1U & (~ ((IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__token_ep_q) 
                            >> 1U)));
            if ((2U & (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__token_ep_q))) {
                vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__tx_ready_r 
                    = ((1U & (~ (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__token_ep_q))) 
                       && (IData)(vlSelfRef.top__DOT__u_cdc__DOT__inport_valid_q));
                vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__tx_data_valid_r 
                    = ((1U & (~ (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__token_ep_q))) 
                       && (IData)(vlSelfRef.top__DOT__u_cdc__DOT__inport_valid_q));
                vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__ep_stall_r 
                    = ((1U & (~ (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__token_ep_q))) 
                       && (IData)(vlSelfRef.top__DOT__u_cdc__DOT__ep2_tx_stall_w));
                if ((1U & (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__token_ep_q))) {
                    vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__out_data_bit_r 
                        = vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__ep3_out_data_bit_q;
                    vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__tx_data_r = 0U;
                } else {
                    vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__out_data_bit_r 
                        = vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__ep2_out_data_bit_q;
                    vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__tx_data_r 
                        = vlSelfRef.top__DOT__u_cdc__DOT__inport_data_q;
                }
                vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__tx_data_last_r 
                    = ((1U & (~ (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__token_ep_q))) 
                       && (IData)(vlSelfRef.top__DOT__u_cdc__DOT__ep2_tx_data_last_w));
            } else {
                vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__tx_ready_r 
                    = ((1U & (~ (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__token_ep_q))) 
                       && (IData)(vlSelfRef.top__DOT__u_cdc__DOT__ctrl_txvalid_q));
                vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__tx_data_valid_r 
                    = ((1U & (~ (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__token_ep_q))) 
                       && (IData)(vlSelfRef.top__DOT__u_cdc__DOT__ctrl_txvalid_q));
                vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__ep_stall_r 
                    = ((1U & (~ (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__token_ep_q))) 
                       && (IData)(vlSelfRef.top__DOT__u_cdc__DOT__ctrl_txstall_q));
                if ((1U & (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__token_ep_q))) {
                    vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__out_data_bit_r 
                        = vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__ep1_out_data_bit_q;
                    vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__tx_data_r = 0U;
                } else {
                    vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__out_data_bit_r 
                        = vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__ep0_out_data_bit_q;
                    vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__tx_data_r 
                        = vlSelfRef.top__DOT__u_cdc__DOT__ctrl_txdata_q;
                }
                vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__tx_data_last_r 
                    = ((1U & (~ (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__token_ep_q))) 
                       && (IData)(vlSelfRef.top__DOT__u_cdc__DOT__ctrl_txlast_q));
            }
            vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__ep_iso_r = 0U;
        }
    }
    vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_tx__DOT__utmi_txvalid_r 
        = ((6U == (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_tx__DOT__state_q)) 
           || ((3U == (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_tx__DOT__state_q)) 
               || ((4U == (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_tx__DOT__state_q)) 
                   || ((2U == (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_tx__DOT__state_q))
                        ? (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__tx_data_valid_r)
                        : (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_tx__DOT__valid_q)))));
    top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__u_crc16__DOT____VdfgRegularize_h8075a1a5_0_9 
        = (1U & ((IData)(top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__u_crc16__DOT____VdfgRegularize_h8075a1a5_0_0) 
                 ^ ((vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__data_buffer_q 
                     >> 2U) ^ ((IData)(top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__u_crc16__DOT____VdfgRegularize_h8075a1a5_0_3) 
                               ^ (IData)(top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__u_crc16__DOT____VdfgRegularize_h8075a1a5_0_2)))));
    vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__tx_valid_r = 0U;
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
    vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__tx_data_accept_w 
        = ((2U == (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_tx__DOT__state_q))
            ? (IData)(vlSelfRef.top__DOT__utmi_txready_wrapper)
            : ((1U == (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_tx__DOT__state_q)) 
               & ((IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_tx__DOT__data_zlp_q) 
                  & (IData)(vlSelfRef.top__DOT__utmi_txready_wrapper))));
    vlSelfRef.top__DOT__u_cdc__DOT__setup_no_data_w 
        = ((IData)(vlSelfRef.top__DOT__u_cdc__DOT__setup_set_w) 
           & (0U == (IData)(vlSelfRef.top__DOT__u_cdc__DOT__wLength)));
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
    top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__u_crc16__DOT____VdfgRegularize_h8075a1a5_0_1 
        = (1U & ((IData)(top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__u_crc16__DOT____VdfgRegularize_h8075a1a5_0_9) 
                 ^ (vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__data_buffer_q 
                    >> 7U)));
    top__DOT__u_cdc__DOT__u_core__DOT__u_sie_tx__DOT__u_crc16__DOT____VdfgRegularize_h8075a1a5_0_2 
        = (1U & VL_REDXOR_8((0x60U & (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_tx__DOT__utmi_data_r))));
    top__DOT__u_cdc__DOT__u_core__DOT__u_sie_tx__DOT__u_crc16__DOT____VdfgRegularize_h8075a1a5_0_3 
        = (1U & VL_REDXOR_8((0x18U & (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_tx__DOT__utmi_data_r))));
    top__DOT__u_cdc__DOT__u_core__DOT__u_sie_tx__DOT__u_crc16__DOT____VdfgRegularize_h8075a1a5_0_0 
        = (1U & ((IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_tx__DOT__utmi_data_r) 
                 ^ ((IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_tx__DOT__utmi_data_r) 
                    >> 1U)));
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
    vlSelfRef.top__DOT__u_cdc__DOT__ep2_tx_data_accept_w 
        = ((IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__tx_data_accept_w) 
           & (2U == (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__token_ep_q)));
    vlSelfRef.top__DOT__u_cdc__DOT__ep0_tx_data_accept_w 
        = ((IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__tx_data_accept_w) 
           & (0U == (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__token_ep_q)));
    top__DOT__u_cdc__DOT____VdfgExtracted_h9796ed88__0 
        = ((IData)(vlSelfRef.top__DOT__u_cdc__DOT__setup_set_w) 
           & (IData)(vlSelfRef.top__DOT__u_cdc__DOT__setup_no_data_w));
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
    top__DOT__u_cdc__DOT__u_core__DOT__u_sie_tx__DOT__u_crc16__DOT____VdfgRegularize_h8075a1a5_0_9 
        = (1U & ((IData)(top__DOT__u_cdc__DOT__u_core__DOT__u_sie_tx__DOT__u_crc16__DOT____VdfgRegularize_h8075a1a5_0_0) 
                 ^ (((IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_tx__DOT__utmi_data_r) 
                     >> 2U) ^ ((IData)(top__DOT__u_cdc__DOT__u_core__DOT__u_sie_tx__DOT__u_crc16__DOT____VdfgRegularize_h8075a1a5_0_3) 
                               ^ (IData)(top__DOT__u_cdc__DOT__u_core__DOT__u_sie_tx__DOT__u_crc16__DOT____VdfgRegularize_h8075a1a5_0_2)))));
    vlSelfRef.top__DOT__u_adc_wrap__DOT__tx_ready = 
        (1U & ((~ (IData)(vlSelfRef.top__DOT__u_cdc__DOT__inport_valid_q)) 
               | (IData)(vlSelfRef.top__DOT__u_cdc__DOT__ep2_tx_data_accept_w)));
    vlSelfRef.top__DOT__u_cdc__DOT__ctrl_send_accept_w 
        = (1U & ((~ (IData)(vlSelfRef.top__DOT__u_cdc__DOT__ctrl_txvalid_q)) 
                 | (IData)(vlSelfRef.top__DOT__u_cdc__DOT__ep0_tx_data_accept_w)));
    top__DOT__u_cdc__DOT__u_core__DOT__u_sie_tx__DOT__u_crc16__DOT____VdfgRegularize_h8075a1a5_0_1 
        = ((IData)(top__DOT__u_cdc__DOT__u_core__DOT__u_sie_tx__DOT__u_crc16__DOT____VdfgRegularize_h8075a1a5_0_9) 
           ^ ((IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_tx__DOT__utmi_data_r) 
              >> 7U));
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
    vlSelfRef.top__DOT__u_adc_wrap__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__u_dpdcram__DOT__rd_ena 
        = (((IData)(vlSelfRef.top__DOT__u_adc_wrap__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__rd_ptr_gray) 
            != (IData)(vlSelfRef.top__DOT__u_adc_wrap__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__wr_ptr_gray_rd)) 
           & ((~ (IData)(vlSelfRef.top__DOT__u_adc_wrap__DOT__u_dc_fifo__DOT__data_out_valid)) 
              | ((~ (IData)(vlSelfRef.top__DOT__u_adc_wrap__DOT__u_dc_fifo__DOT__middle_valid)) 
                 | (IData)(vlSelfRef.top__DOT__u_adc_wrap__DOT__u_dc_fifo__DOT__rd_ena))));
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
}

VL_ATTR_COLD void Vtop___024root___eval_stl(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_stl\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VstlTriggered[0U])) {
        Vtop___024root___stl_sequent__TOP__0(vlSelf);
        Vtop___024root____Vm_traceActivitySetAll(vlSelf);
    }
}

VL_ATTR_COLD bool Vtop___024root___eval_phase__stl(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_phase__stl\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VstlExecute;
    // Body
    Vtop___024root___eval_triggers_vec__stl(vlSelf);
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtop___024root___dump_triggers__stl(vlSelfRef.__VstlTriggered, "stl"s);
    }
#endif
    __VstlExecute = Vtop___024root___trigger_anySet__stl(vlSelfRef.__VstlTriggered);
    if (__VstlExecute) {
        Vtop___024root___eval_stl(vlSelf);
    }
    return (__VstlExecute);
}

bool Vtop___024root___trigger_anySet__ico(const VlUnpacked<QData/*63:0*/, 1> &in);

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__ico(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___dump_triggers__ico\n"); );
    // Body
    if ((1U & (~ (IData)(Vtop___024root___trigger_anySet__ico(triggers))))) {
        VL_DBG_MSGS("         No '" + tag + "' region triggers active\n");
    }
    if ((1U & (IData)(triggers[0U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: Internal 'ico' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

bool Vtop___024root___trigger_anySet__act(const VlUnpacked<QData/*63:0*/, 1> &in);

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__act(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ (IData)(Vtop___024root___trigger_anySet__act(triggers))))) {
        VL_DBG_MSGS("         No '" + tag + "' region triggers active\n");
    }
    if ((1U & (IData)(triggers[0U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: @(posedge clk_25m)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 1U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 1 is active: @(posedge top.phy_rst)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 2U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 2 is active: @(posedge ulpi_clk60)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 3U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 3 is active: @(posedge top.cdc_rst)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 4U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 4 is active: @(posedge top.u_adc_wrap.adc_rst_sync)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 5U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 5 is active: @(posedge top.u_adc_wrap.u_dc_fifo.u_std_dc_fifo.rd_a_rst)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vtop___024root____Vm_traceActivitySetAll(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root____Vm_traceActivitySetAll\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vm_traceActivity[0U] = 1U;
    vlSelfRef.__Vm_traceActivity[1U] = 1U;
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.__Vm_traceActivity[3U] = 1U;
    vlSelfRef.__Vm_traceActivity[4U] = 1U;
    vlSelfRef.__Vm_traceActivity[5U] = 1U;
}

VL_ATTR_COLD void Vtop___024root___ctor_var_reset(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___ctor_var_reset\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const uint64_t __VscopeHash = VL_MURMUR64_HASH(vlSelf->vlNamep);
    vlSelf->clk_25m = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14766181183018948450ull);
    vlSelf->ulpi_clk60 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3200598936335657644ull);
    vlSelf->ulpi_data = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 788099008386200122ull);
    vlSelf->ulpi_dir = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15860594998693804923ull);
    vlSelf->ulpi_nxt = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17396226249873647166ull);
    vlSelf->ulpi_stp = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14098183620969565911ull);
    vlSelf->ulpi_reset = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3835029559609428238ull);
    vlSelf->adc_clk_out = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 233210214785442527ull);
    vlSelf->adc_otr = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7740951399803512364ull);
    vlSelf->adc_data_raw = VL_SCOPED_RAND_RESET_I(12, __VscopeHash, 12200082996552574322ull);
    vlSelf->led_r = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6087721404143237194ull);
    vlSelf->led_g = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11976136186543392332ull);
    vlSelf->led_b = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9557128468027382993ull);
    vlSelf->top__DOT__cdc_rst = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14860454909596048670ull);
    vlSelf->top__DOT__utmi_txready_wrapper = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 18221191426904243964ull);
    vlSelf->top__DOT__tx_data_12b = VL_SCOPED_RAND_RESET_I(12, __VscopeHash, 13711312286564329ull);
    vlSelf->top__DOT__tx_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1900543319970386220ull);
    vlSelf->top__DOT__u_ulpi__DOT__state_q = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 11327776843294126015ull);
    vlSelf->top__DOT__u_ulpi__DOT__mode_update_q = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12180433470018270802ull);
    vlSelf->top__DOT__u_ulpi__DOT__xcvrselect_q = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 15317072592744386231ull);
    vlSelf->top__DOT__u_ulpi__DOT__termselect_q = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15154558923025390766ull);
    vlSelf->top__DOT__u_ulpi__DOT__opmode_q = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 10911460771205463753ull);
    vlSelf->top__DOT__u_ulpi__DOT__phy_reset_q = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7237211840839360240ull);
    vlSelf->top__DOT__u_ulpi__DOT__mode_write_q = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17426477744449770075ull);
    vlSelf->top__DOT__u_ulpi__DOT__otg_update_q = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4328782507479040668ull);
    vlSelf->top__DOT__u_ulpi__DOT__dppulldown_q = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5614998356367545218ull);
    vlSelf->top__DOT__u_ulpi__DOT__dmpulldown_q = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14500096654092002350ull);
    vlSelf->top__DOT__u_ulpi__DOT__otg_write_q = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1332744610202254927ull);
    vlSelf->top__DOT__u_ulpi__DOT__ulpi_dir_q = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7427911008231118822ull);
    vlSelf->top__DOT__u_ulpi__DOT__turnaround_w = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4080722407960663980ull);
    vlSelf->top__DOT__u_ulpi__DOT__tx_delay_q = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 2649093697474985446ull);
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->top__DOT__u_ulpi__DOT__tx_buffer_q[__Vi0] = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 8296212789067090889ull);
    }
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->top__DOT__u_ulpi__DOT__tx_valid_q[__Vi0] = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4684476031690640708ull);
    }
    vlSelf->top__DOT__u_ulpi__DOT__tx_wr_idx_q = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 18429288406343659713ull);
    vlSelf->top__DOT__u_ulpi__DOT__tx_rd_idx_q = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12247216549857083197ull);
    vlSelf->top__DOT__u_ulpi__DOT__utmi_tx_ready_w = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2519616170617795650ull);
    vlSelf->top__DOT__u_ulpi__DOT__utmi_tx_data_w = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 12656256600665457070ull);
    vlSelf->top__DOT__u_ulpi__DOT__ulpi_data_q = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 12778749576393210912ull);
    vlSelf->top__DOT__u_ulpi__DOT__ulpi_stp_q = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6679806990658786247ull);
    vlSelf->top__DOT__u_ulpi__DOT__data_q = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 2639219003990481723ull);
    vlSelf->top__DOT__u_ulpi__DOT__utmi_rxvalid_q = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12394615866250105828ull);
    vlSelf->top__DOT__u_ulpi__DOT__utmi_rxerror_q = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12479337057399391442ull);
    vlSelf->top__DOT__u_ulpi__DOT__utmi_rxactive_q = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15148222566292734037ull);
    vlSelf->top__DOT__u_ulpi__DOT__utmi_linestate_q = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 17772883747383293864ull);
    vlSelf->top__DOT__u_ulpi__DOT__utmi_data_q = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 4100314916867892890ull);
    vlSelf->top__DOT__u_ulpi__DOT____VdfgRegularize_hdd78e87c_0_2 = 0;
    vlSelf->top__DOT__u_adc_wrap__DOT__tx_ready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4711901957476524641ull);
    vlSelf->top__DOT__u_adc_wrap__DOT__adc_data = VL_SCOPED_RAND_RESET_I(12, __VscopeHash, 6908159536228100211ull);
    vlSelf->top__DOT__u_adc_wrap__DOT__adc_rst_ms = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12079907817891146625ull);
    vlSelf->top__DOT__u_adc_wrap__DOT__adc_rst_sync = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16464517338985732393ull);
    vlSelf->top__DOT__u_adc_wrap__DOT__current_state = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15120357185632925563ull);
    vlSelf->top__DOT__u_adc_wrap__DOT__next_state = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3045046371868121096ull);
    vlSelf->top__DOT__u_adc_wrap__DOT__burst_count = VL_SCOPED_RAND_RESET_I(10, __VscopeHash, 9564379960769526359ull);
    vlSelf->top__DOT__u_adc_wrap__DOT__byte_sent = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5978161065827402019ull);
    vlSelf->top__DOT__u_adc_wrap__DOT__u_adc_int__DOT__latency_counter = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 16001552017024920596ull);
    vlSelf->top__DOT__u_adc_wrap__DOT__u_adc_int__DOT__adc_ready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14827139973289693833ull);
    vlSelf->top__DOT__u_adc_wrap__DOT__u_dc_fifo__DOT__rd_ena = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17133011626904275897ull);
    vlSelf->top__DOT__u_adc_wrap__DOT__u_dc_fifo__DOT__std_rd_data = VL_SCOPED_RAND_RESET_I(12, __VscopeHash, 4123145495012811957ull);
    vlSelf->top__DOT__u_adc_wrap__DOT__u_dc_fifo__DOT__data_out_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3160550151300734544ull);
    vlSelf->top__DOT__u_adc_wrap__DOT__u_dc_fifo__DOT__fall_through = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14539510401227991581ull);
    vlSelf->top__DOT__u_adc_wrap__DOT__u_dc_fifo__DOT__middle_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8451824198389025396ull);
    vlSelf->top__DOT__u_adc_wrap__DOT__u_dc_fifo__DOT__middle_data = VL_SCOPED_RAND_RESET_I(12, __VscopeHash, 15051423471672278788ull);
    vlSelf->top__DOT__u_adc_wrap__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__rd_a_rst = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17680759624688168607ull);
    vlSelf->top__DOT__u_adc_wrap__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__rd_a_rst_ms = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13487406288283777260ull);
    vlSelf->top__DOT__u_adc_wrap__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__wr_ptr = VL_SCOPED_RAND_RESET_I(15, __VscopeHash, 10194128334516488637ull);
    vlSelf->top__DOT__u_adc_wrap__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__wr_ptr_gray = VL_SCOPED_RAND_RESET_I(15, __VscopeHash, 13673661195516433981ull);
    vlSelf->top__DOT__u_adc_wrap__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__wr_ptr_ms = VL_SCOPED_RAND_RESET_I(15, __VscopeHash, 15679029968343592950ull);
    vlSelf->top__DOT__u_adc_wrap__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__wr_ptr_rd = VL_SCOPED_RAND_RESET_I(15, __VscopeHash, 12477510237715579149ull);
    vlSelf->top__DOT__u_adc_wrap__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__wr_ptr_gray_rd = VL_SCOPED_RAND_RESET_I(15, __VscopeHash, 16493064798772070406ull);
    vlSelf->top__DOT__u_adc_wrap__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__rd_ptr = VL_SCOPED_RAND_RESET_I(15, __VscopeHash, 2424347892834303057ull);
    vlSelf->top__DOT__u_adc_wrap__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__rd_ptr_gray = VL_SCOPED_RAND_RESET_I(15, __VscopeHash, 17319643930240111667ull);
    vlSelf->top__DOT__u_adc_wrap__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__rd_ptr_ms = VL_SCOPED_RAND_RESET_I(15, __VscopeHash, 15294596425723187074ull);
    vlSelf->top__DOT__u_adc_wrap__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__rd_ptr_wr = VL_SCOPED_RAND_RESET_I(15, __VscopeHash, 2359591034995687173ull);
    vlSelf->top__DOT__u_adc_wrap__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__rd_ptr_gray_wr = VL_SCOPED_RAND_RESET_I(15, __VscopeHash, 9648728484623215190ull);
    vlSelf->top__DOT__u_adc_wrap__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__u_dpdcram__DOT__wr_ena = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1818727884112626254ull);
    vlSelf->top__DOT__u_adc_wrap__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__u_dpdcram__DOT__rd_ena = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 227086372623033581ull);
    for (int __Vi0 = 0; __Vi0 < 16384; ++__Vi0) {
        vlSelf->top__DOT__u_adc_wrap__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__u_dpdcram__DOT__mem[__Vi0] = VL_SCOPED_RAND_RESET_I(12, __VscopeHash, 15167653040919380548ull);
    }
    vlSelf->top__DOT__u_cdc__DOT__device_addr_q = VL_SCOPED_RAND_RESET_I(7, __VscopeHash, 5723826961820103238ull);
    vlSelf->top__DOT__u_cdc__DOT__usb_ep0_tx_rd_w = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1994924896816511359ull);
    vlSelf->top__DOT__u_cdc__DOT__usb_ep0_tx_data_w = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 1245390699583532586ull);
    vlSelf->top__DOT__u_cdc__DOT__usb_ep0_tx_empty_w = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8151894803519234069ull);
    vlSelf->top__DOT__u_cdc__DOT__usb_ep0_rx_wr_w = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10191779708648323409ull);
    vlSelf->top__DOT__u_cdc__DOT__usb_ep0_rx_data_w = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 17068487046197191507ull);
    vlSelf->top__DOT__u_cdc__DOT__usb_ep0_rx_full_w = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15643189029624980842ull);
    vlSelf->top__DOT__u_cdc__DOT__usb_ep1_tx_rd_w = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16666672545811090583ull);
    vlSelf->top__DOT__u_cdc__DOT__usb_ep1_tx_data_w = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 15269865451381548180ull);
    vlSelf->top__DOT__u_cdc__DOT__usb_ep1_tx_empty_w = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14188952241900116049ull);
    vlSelf->top__DOT__u_cdc__DOT__usb_ep1_rx_wr_w = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2583213559217188349ull);
    vlSelf->top__DOT__u_cdc__DOT__usb_ep1_rx_data_w = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 6399457295206159915ull);
    vlSelf->top__DOT__u_cdc__DOT__usb_ep1_rx_full_w = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10487119271983525344ull);
    vlSelf->top__DOT__u_cdc__DOT__usb_ep2_tx_rd_w = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8739533591401656817ull);
    vlSelf->top__DOT__u_cdc__DOT__usb_ep2_tx_data_w = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 10214154816749658754ull);
    vlSelf->top__DOT__u_cdc__DOT__usb_ep2_tx_empty_w = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1639897664631318226ull);
    vlSelf->top__DOT__u_cdc__DOT__usb_ep2_rx_wr_w = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13660482902272717920ull);
    vlSelf->top__DOT__u_cdc__DOT__usb_ep2_rx_data_w = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 12031994900337108382ull);
    vlSelf->top__DOT__u_cdc__DOT__usb_ep2_rx_full_w = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 26903160433543428ull);
    vlSelf->top__DOT__u_cdc__DOT__usb_ep3_tx_rd_w = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7510007842233455736ull);
    vlSelf->top__DOT__u_cdc__DOT__usb_ep3_tx_data_w = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 4658346972770464308ull);
    vlSelf->top__DOT__u_cdc__DOT__usb_ep3_tx_empty_w = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9906655257768644167ull);
    vlSelf->top__DOT__u_cdc__DOT__usb_ep3_rx_wr_w = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12469006290968022577ull);
    vlSelf->top__DOT__u_cdc__DOT__usb_ep3_rx_data_w = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 9249834296793145537ull);
    vlSelf->top__DOT__u_cdc__DOT__usb_ep3_rx_full_w = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10811670165923235132ull);
    vlSelf->top__DOT__u_cdc__DOT__rx_last_w = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 606344482442682862ull);
    vlSelf->top__DOT__u_cdc__DOT__ep0_rx_valid_w = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4548504834609117534ull);
    vlSelf->top__DOT__u_cdc__DOT__ep0_rx_setup_w = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 18203576606876898069ull);
    vlSelf->top__DOT__u_cdc__DOT__ep0_tx_data_accept_w = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11097845562685217731ull);
    vlSelf->top__DOT__u_cdc__DOT__ep2_tx_data_last_w = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1254496586981956797ull);
    vlSelf->top__DOT__u_cdc__DOT__ep2_tx_data_accept_w = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10107562393844289869ull);
    vlSelf->top__DOT__u_cdc__DOT__ep2_tx_stall_w = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15326546862617669041ull);
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        vlSelf->top__DOT__u_cdc__DOT__setup_packet_q[__Vi0] = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 1943746736196292889ull);
    }
    vlSelf->top__DOT__u_cdc__DOT__setup_wr_idx_q = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 17080292237672073581ull);
    vlSelf->top__DOT__u_cdc__DOT__setup_frame_q = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15859333687240050391ull);
    vlSelf->top__DOT__u_cdc__DOT__setup_valid_q = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10357050969909102036ull);
    vlSelf->top__DOT__u_cdc__DOT__setup_data_q = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3514760663665602089ull);
    vlSelf->top__DOT__u_cdc__DOT__status_ready_q = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8394112686808627091ull);
    vlSelf->top__DOT__u_cdc__DOT__wValue_w = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 6356134935253298911ull);
    vlSelf->top__DOT__u_cdc__DOT__wIndex_w = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 7017180088302566857ull);
    vlSelf->top__DOT__u_cdc__DOT__wLength = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 6609784601278831572ull);
    vlSelf->top__DOT__u_cdc__DOT__setup_set_w = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17869605438133725710ull);
    vlSelf->top__DOT__u_cdc__DOT__setup_no_data_w = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12774556299759635324ull);
    vlSelf->top__DOT__u_cdc__DOT__ctrl_stall_r = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11688636296764851120ull);
    vlSelf->top__DOT__u_cdc__DOT__ctrl_ack_r = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5711330492484463467ull);
    vlSelf->top__DOT__u_cdc__DOT__ctrl_get_len_r = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 9367324366934059502ull);
    vlSelf->top__DOT__u_cdc__DOT__desc_addr_r = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 1098808080217173996ull);
    vlSelf->top__DOT__u_cdc__DOT__addressed_q = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1062081775370937069ull);
    vlSelf->top__DOT__u_cdc__DOT__addressed_r = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3583002001196890518ull);
    vlSelf->top__DOT__u_cdc__DOT__device_addr_r = VL_SCOPED_RAND_RESET_I(7, __VscopeHash, 916001997537443302ull);
    vlSelf->top__DOT__u_cdc__DOT__configured_q = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11381519612877768680ull);
    vlSelf->top__DOT__u_cdc__DOT__configured_r = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8039905070757874ull);
    vlSelf->top__DOT__u_cdc__DOT__set_with_data_q = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12626673675634714127ull);
    vlSelf->top__DOT__u_cdc__DOT__set_with_data_r = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6143103124075005843ull);
    vlSelf->top__DOT__u_cdc__DOT__ctrl_sending_q = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4861850122224064621ull);
    vlSelf->top__DOT__u_cdc__DOT__ctrl_send_idx_q = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 1604738690113841335ull);
    vlSelf->top__DOT__u_cdc__DOT__ctrl_send_len_q = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 11407383105630715847ull);
    vlSelf->top__DOT__u_cdc__DOT__ctrl_sending_r = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 18142546127682235930ull);
    vlSelf->top__DOT__u_cdc__DOT__ctrl_send_idx_r = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 9267307053689099331ull);
    vlSelf->top__DOT__u_cdc__DOT__ctrl_send_len_r = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 10897572659268634639ull);
    vlSelf->top__DOT__u_cdc__DOT__ctrl_txvalid_q = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8384407838343111966ull);
    vlSelf->top__DOT__u_cdc__DOT__ctrl_txdata_q = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 15198262958592913816ull);
    vlSelf->top__DOT__u_cdc__DOT__ctrl_txstrb_q = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10436720539342187022ull);
    vlSelf->top__DOT__u_cdc__DOT__ctrl_txlast_q = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2808533530702874307ull);
    vlSelf->top__DOT__u_cdc__DOT__ctrl_txstall_q = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11116871007329856549ull);
    vlSelf->top__DOT__u_cdc__DOT__ctrl_txvalid_r = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11493018223200224118ull);
    vlSelf->top__DOT__u_cdc__DOT__ctrl_txdata_r = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 4075262582324347900ull);
    vlSelf->top__DOT__u_cdc__DOT__ctrl_txstrb_r = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4554997660496917336ull);
    vlSelf->top__DOT__u_cdc__DOT__ctrl_txlast_r = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11154296657382909178ull);
    vlSelf->top__DOT__u_cdc__DOT__ctrl_txstall_r = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14477272291375902506ull);
    vlSelf->top__DOT__u_cdc__DOT__ctrl_send_accept_w = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10949770027215718007ull);
    vlSelf->top__DOT__u_cdc__DOT__desc_addr_q = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 10382331202350396853ull);
    vlSelf->top__DOT__u_cdc__DOT__inport_valid_q = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16527710818239843306ull);
    vlSelf->top__DOT__u_cdc__DOT__inport_data_q = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 7298286996582741385ull);
    vlSelf->top__DOT__u_cdc__DOT__inport_cnt_q = VL_SCOPED_RAND_RESET_I(11, __VscopeHash, 12250889475087141910ull);
    vlSelf->top__DOT__u_cdc__DOT__genblk1__DOT__state_q = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 11326497511180021629ull);
    vlSelf->top__DOT__u_cdc__DOT__genblk1__DOT__next_state_r = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 4585349928098900415ull);
    vlSelf->top__DOT__u_cdc__DOT__genblk1__DOT__usb_rst_time_q = VL_SCOPED_RAND_RESET_I(20, __VscopeHash, 8359528214779525508ull);
    vlSelf->top__DOT__u_cdc__DOT__genblk1__DOT__chirp_count_q = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 15792202176032821158ull);
    vlSelf->top__DOT__u_cdc__DOT__genblk1__DOT__last_linestate_q = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 2371480012367627426ull);
    vlSelf->top__DOT__u_cdc__DOT__genblk1__DOT__utmi_op_mode_r = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 16833818455522169066ull);
    vlSelf->top__DOT__u_cdc__DOT__genblk1__DOT__utmi_xcvrselect_r = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 9510575154707482165ull);
    vlSelf->top__DOT__u_cdc__DOT__genblk1__DOT__utmi_termselect_r = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9707725546645944334ull);
    vlSelf->top__DOT__u_cdc__DOT__genblk1__DOT__utmi_dppulldown_r = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2451048071124557550ull);
    vlSelf->top__DOT__u_cdc__DOT__genblk1__DOT__utmi_dmpulldown_r = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12318766555290038169ull);
    vlSelf->top__DOT__u_cdc__DOT__u_core__DOT__ep_clear_toggle_i = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 2862747954140780579ull);
    vlSelf->top__DOT__u_cdc__DOT__u_core__DOT__state_q = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 17472274494707535178ull);
    vlSelf->top__DOT__u_cdc__DOT__u_core__DOT__se0_cnt_q = VL_SCOPED_RAND_RESET_I(15, __VscopeHash, 1735444972117629622ull);
    vlSelf->top__DOT__u_cdc__DOT__u_core__DOT__frame_num_w = VL_SCOPED_RAND_RESET_I(11, __VscopeHash, 4978903491050725551ull);
    vlSelf->top__DOT__u_cdc__DOT__u_core__DOT__tx_data_valid_r = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1696150487821347914ull);
    vlSelf->top__DOT__u_cdc__DOT__u_core__DOT__tx_data_strb_r = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10254724156306105511ull);
    vlSelf->top__DOT__u_cdc__DOT__u_core__DOT__tx_data_r = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 5577241753589292863ull);
    vlSelf->top__DOT__u_cdc__DOT__u_core__DOT__tx_data_last_r = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9248345062232594017ull);
    vlSelf->top__DOT__u_cdc__DOT__u_core__DOT__tx_data_accept_w = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14257281301312517522ull);
    vlSelf->top__DOT__u_cdc__DOT__u_core__DOT__tx_valid_q = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3035307496340747901ull);
    vlSelf->top__DOT__u_cdc__DOT__u_core__DOT__tx_pid_q = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 17210807738085168127ull);
    vlSelf->top__DOT__u_cdc__DOT__u_core__DOT__rx_space_q = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1776260902285413954ull);
    vlSelf->top__DOT__u_cdc__DOT__u_core__DOT__rx_space_r = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17428318759920116339ull);
    vlSelf->top__DOT__u_cdc__DOT__u_core__DOT__tx_ready_r = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17157903097192113597ull);
    vlSelf->top__DOT__u_cdc__DOT__u_core__DOT__out_data_bit_r = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4366569446485127469ull);
    vlSelf->top__DOT__u_cdc__DOT__u_core__DOT__in_data_bit_r = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6787475732951949428ull);
    vlSelf->top__DOT__u_cdc__DOT__u_core__DOT__ep_stall_r = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 18370113997113540425ull);
    vlSelf->top__DOT__u_cdc__DOT__u_core__DOT__ep_iso_r = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17135296792314071359ull);
    vlSelf->top__DOT__u_cdc__DOT__u_core__DOT__rx_enable_q = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3339508636174379802ull);
    vlSelf->top__DOT__u_cdc__DOT__u_core__DOT__rx_setup_q = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16432183995763742442ull);
    vlSelf->top__DOT__u_cdc__DOT__u_core__DOT__ep0_out_data_bit_q = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11081277096373484986ull);
    vlSelf->top__DOT__u_cdc__DOT__u_core__DOT__ep0_in_data_bit_q = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3003665488991564133ull);
    vlSelf->top__DOT__u_cdc__DOT__u_core__DOT__ep1_out_data_bit_q = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16893367658895740451ull);
    vlSelf->top__DOT__u_cdc__DOT__u_core__DOT__ep1_in_data_bit_q = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5307294835694657766ull);
    vlSelf->top__DOT__u_cdc__DOT__u_core__DOT__ep2_out_data_bit_q = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2882093004716182429ull);
    vlSelf->top__DOT__u_cdc__DOT__u_core__DOT__ep2_in_data_bit_q = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3882368574054738742ull);
    vlSelf->top__DOT__u_cdc__DOT__u_core__DOT__ep3_out_data_bit_q = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9649006778652836980ull);
    vlSelf->top__DOT__u_cdc__DOT__u_core__DOT__ep3_in_data_bit_q = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8746528133412533748ull);
    vlSelf->top__DOT__u_cdc__DOT__u_core__DOT__current_addr_q = VL_SCOPED_RAND_RESET_I(7, __VscopeHash, 14562901883508594516ull);
    vlSelf->top__DOT__u_cdc__DOT__u_core__DOT____Vcellinp__u_sie_rx__enable_i = 0;
    vlSelf->top__DOT__u_cdc__DOT__u_core__DOT__next_state_r = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 13051854871780170221ull);
    vlSelf->top__DOT__u_cdc__DOT__u_core__DOT__tx_valid_r = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1276034971475447924ull);
    vlSelf->top__DOT__u_cdc__DOT__u_core__DOT__tx_pid_r = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 12144736843475432727ull);
    vlSelf->top__DOT__u_cdc__DOT__u_core__DOT__addr_update_pending_q = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15826670048744818859ull);
    vlSelf->top__DOT__u_cdc__DOT__u_core__DOT__sent_status_zlp_q = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2909700296019971848ull);
    vlSelf->top__DOT__u_cdc__DOT__u_core__DOT__new_out_bit_r = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17925968013093970912ull);
    vlSelf->top__DOT__u_cdc__DOT__u_core__DOT__new_in_bit_r = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15601967441701302073ull);
    vlSelf->top__DOT__u_cdc__DOT__u_core__DOT__rst_event_q = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9906198403354983148ull);
    vlSelf->top__DOT__u_cdc__DOT__u_core__DOT__intr_q = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14818515893932709216ull);
    vlSelf->top__DOT__u_cdc__DOT__u_core__DOT__cfg_int_rx_r = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4025911137936417212ull);
    vlSelf->top__DOT__u_cdc__DOT__u_core__DOT__cfg_int_tx_r = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10962588938702168562ull);
    VL_SCOPED_RAND_RESET_W(80, vlSelf->top__DOT__u_cdc__DOT__u_core__DOT__dbg_state, __VscopeHash, 15825466560727664125ull);
    VL_SCOPED_RAND_RESET_W(80, vlSelf->top__DOT__u_cdc__DOT__u_core__DOT__dbg_pid, __VscopeHash, 2731384254188404310ull);
    vlSelf->top__DOT__u_cdc__DOT__u_core__DOT__dbg_pid_r = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 6326291683473256318ull);
    vlSelf->top__DOT__u_cdc__DOT__u_core__DOT____VdfgRegularize_h04591d3f_0_4 = 0;
    vlSelf->top__DOT__u_cdc__DOT__u_core__DOT__u_sie_tx__DOT__state_q = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 14329869500542204425ull);
    vlSelf->top__DOT__u_cdc__DOT__u_core__DOT__u_sie_tx__DOT__next_state_r = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 3852655387104825103ull);
    vlSelf->top__DOT__u_cdc__DOT__u_core__DOT__u_sie_tx__DOT__data_pid_q = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3355974826535724854ull);
    vlSelf->top__DOT__u_cdc__DOT__u_core__DOT__u_sie_tx__DOT__data_zlp_q = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14879805345600036798ull);
    vlSelf->top__DOT__u_cdc__DOT__u_core__DOT__u_sie_tx__DOT__crc_sum_q = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 506005410879459158ull);
    vlSelf->top__DOT__u_cdc__DOT__u_core__DOT__u_sie_tx__DOT__crc_err_q = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7038306627131829511ull);
    vlSelf->top__DOT__u_cdc__DOT__u_core__DOT__u_sie_tx__DOT__valid_q = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7913547371502925508ull);
    vlSelf->top__DOT__u_cdc__DOT__u_core__DOT__u_sie_tx__DOT__data_q = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 30474587799508589ull);
    vlSelf->top__DOT__u_cdc__DOT__u_core__DOT__u_sie_tx__DOT__utmi_txvalid_r = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11430594593400359930ull);
    vlSelf->top__DOT__u_cdc__DOT__u_core__DOT__u_sie_tx__DOT__utmi_data_r = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 10311648064791531397ull);
    vlSelf->top__DOT__u_cdc__DOT__u_core__DOT__u_sie_tx__DOT__u_crc16__DOT__crc_out_o = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 1930430191989286613ull);
    vlSelf->top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__state_q = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 15024007835898940004ull);
    vlSelf->top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__frame_num_q = VL_SCOPED_RAND_RESET_I(11, __VscopeHash, 2087848635469287427ull);
    vlSelf->top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__token_dev_q = VL_SCOPED_RAND_RESET_I(7, __VscopeHash, 16753135445365393267ull);
    vlSelf->top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__token_ep_q = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 6861602417626449439ull);
    vlSelf->top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__token_pid_q = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 17308937458054003766ull);
    vlSelf->top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__data_buffer_q = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 14919775237886918119ull);
    vlSelf->top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__data_valid_q = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 6491304540503040158ull);
    vlSelf->top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__rx_active_q = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 4357329465288447266ull);
    vlSelf->top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__shift_en_w = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15112660575301210644ull);
    vlSelf->top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__data_crc_q = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 1558579515208532143ull);
    vlSelf->top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__address_match_w = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7775278597945397144ull);
    vlSelf->top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__next_state_r = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 17957778854191142122ull);
    vlSelf->top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__handshake_valid_q = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4670517943527753034ull);
    vlSelf->top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__frame_valid_q = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8638254674744625429ull);
    vlSelf->top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__token_valid_q = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1711863877959244706ull);
    vlSelf->top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__input_ready_w = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12245642260780800054ull);
    vlSelf->top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__crc_sum_q = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 10425445518977129530ull);
    vlSelf->top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__crc_err_q = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1632428577980466229ull);
    vlSelf->top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__data_complete_q = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6061882508294340112ull);
    vlSelf->top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__data_zlp_q = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4606879243517816184ull);
    vlSelf->top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__valid_q = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14418765233418494902ull);
    vlSelf->top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__last_q = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5465306589038304180ull);
    vlSelf->top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__data_q = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 6178511387093474076ull);
    vlSelf->top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__mask_q = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14917382858418532668ull);
    vlSelf->top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__u_crc16__DOT__crc_out_o = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 4584304616023793882ull);
    vlSelf->top__DOT__u_cdc__DOT__u_rom__DOT__desc_rom_r = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 4301439970608473564ull);
    vlSelf->__Vdly__top__DOT__rst_sync = 0;
    vlSelf->__Vdly__top__DOT__u_adc_wrap__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__rd_ptr = 0;
    vlSelf->__VdlyVal__top__DOT__u_adc_wrap__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__u_dpdcram__DOT__mem__v0 = 0;
    vlSelf->__VdlyDim0__top__DOT__u_adc_wrap__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__u_dpdcram__DOT__mem__v0 = 0;
    vlSelf->__VdlySet__top__DOT__u_adc_wrap__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__u_dpdcram__DOT__mem__v0 = 0;
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VstlTriggered[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VicoTriggered[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VactTriggered[__Vi0] = 0;
    }
    vlSelf->__Vtrigprevexpr___TOP__clk_25m__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__top__DOT__phy_rst__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__ulpi_clk60__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__top__DOT__cdc_rst__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__top__DOT__u_adc_wrap__DOT__adc_rst_sync__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__top__DOT__u_adc_wrap__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__rd_a_rst__0 = 0;
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VnbaTriggered[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 6; ++__Vi0) {
        vlSelf->__Vm_traceActivity[__Vi0] = 0;
    }
}
