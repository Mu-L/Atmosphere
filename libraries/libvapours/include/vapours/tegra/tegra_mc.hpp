/*
 * Copyright (c) 2018-2020 Atmosphère-NX
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms and conditions of the GNU General Public License,
 * version 2, as published by the Free Software Foundation.
 *
 * This program is distributed in the hope it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#pragma once
#include <vapours/common.hpp>
#include <vapours/assert.hpp>
#include <vapours/literals.hpp>
#include <vapours/util.hpp>
#include <vapours/results.hpp>
#include <vapours/reg.hpp>

#define MC_INTSTATUS                            (0x000)
#define MC_INTMASK                              (0x004)
#define MC_ERR_STATUS                           (0x008)
#define MC_ERR_ADR                              (0x00C)
#define MC_SMMU_CONFIG                          (0x010)
#define MC_SMMU_PTB_ASID                        (0x01C)
#define MC_SMMU_PTB_DATA                        (0x020)
#define MC_SMMU_TLB_FLUSH                       (0x030)
#define MC_SMMU_PTC_FLUSH_0                     (0x034)
#define MC_EMEM_CFG                             (0x050)
#define MC_EMEM_ADR_CFG                         (0x054)
#define MC_EMEM_ADR_CFG_DEV0                    (0x058)
#define MC_EMEM_ADR_CFG_DEV1                    (0x05C)
#define MC_EMEM_ADR_CFG_CHANNEL_MASK            (0x060)
#define MC_EMEM_ADR_CFG_BANK_MASK_0             (0x064)
#define MC_EMEM_ADR_CFG_BANK_MASK_1             (0x068)
#define MC_EMEM_ADR_CFG_BANK_MASK_2             (0x06C)
#define MC_EMEM_ARB_CFG                         (0x090)
#define MC_EMEM_ARB_OUTSTANDING_REQ             (0x094)
#define MC_EMEM_ARB_TIMING_RCD                  (0x098)
#define MC_EMEM_ARB_TIMING_RP                   (0x09C)
#define MC_EMEM_ARB_TIMING_RC                   (0x0A0)
#define MC_EMEM_ARB_TIMING_RAS                  (0x0A4)
#define MC_EMEM_ARB_TIMING_FAW                  (0x0A8)
#define MC_EMEM_ARB_TIMING_RRD                  (0x0AC)
#define MC_EMEM_ARB_TIMING_RAP2PRE              (0x0B0)
#define MC_EMEM_ARB_TIMING_WAP2PRE              (0x0B4)
#define MC_EMEM_ARB_TIMING_R2R                  (0x0B8)
#define MC_EMEM_ARB_TIMING_W2W                  (0x0BC)
#define MC_EMEM_ARB_TIMING_R2W                  (0x0C0)
#define MC_EMEM_ARB_TIMING_W2R                  (0x0C4)
#define MC_EMEM_ARB_MISC2                       (0x0C8)
#define MC_EMEM_ARB_DA_TURNS                    (0x0D0)
#define MC_EMEM_ARB_DA_COVERS                   (0x0D4)
#define MC_EMEM_ARB_MISC0                       (0x0D8)
#define MC_EMEM_ARB_MISC1                       (0x0DC)
#define MC_EMEM_ARB_RING1_THROTTLE              (0x0E0)
#define MC_EMEM_ARB_OVERRIDE                    (0x0E8)
#define MC_EMEM_ARB_RSV                         (0x0EC)
#define MC_CLKEN_OVERRIDE                       (0x0F4)
#define MC_TIMING_CONTROL_DBG                   (0x0F8)
#define MC_TIMING_CONTROL                       (0x0FC)
#define MC_CLIENT_HOTRESET_CTRL                 (0x200)
#define MC_CLIENT_HOTRESET_STATUS               (0x204)
#define MC_SMMU_AFI_ASID                        (0x238)
#define MC_SMMU_DC_ASID                         (0x240)
#define MC_SMMU_DCB_ASID                        (0x244)
#define MC_SMMU_HC_ASID                         (0x250)
#define MC_SMMU_HDA_ASID                        (0x254)
#define MC_SMMU_ISP2_ASID                       (0x258)
#define MC_SMMU_MSENC_NVENC_ASID                (0x264)
#define MC_SMMU_NV_ASID                         (0x268)
#define MC_SMMU_NV2_ASID                        (0x26C)
#define MC_SMMU_PPCS_ASID                       (0x270)
#define MC_SMMU_SATA_ASID                       (0x274)
#define MC_SMMU_VI_ASID                         (0x280)
#define MC_SMMU_VIC_ASID                        (0x284)
#define MC_SMMU_XUSB_HOST_ASID                  (0x288)
#define MC_SMMU_XUSB_DEV_ASID                   (0x28C)
#define MC_SMMU_TSEC_ASID                       (0x294)
#define MC_LATENCY_ALLOWANCE_AVPC_0             (0x2E4)
#define MC_LATENCY_ALLOWANCE_DC_0               (0x2E8)
#define MC_LATENCY_ALLOWANCE_DC_1               (0x2EC)
#define MC_LATENCY_ALLOWANCE_DCB_0              (0x2F4)
#define MC_LATENCY_ALLOWANCE_DCB_1              (0x2F8)
#define MC_LATENCY_ALLOWANCE_HC_0               (0x310)
#define MC_LATENCY_ALLOWANCE_HC_1               (0x314)
#define MC_LATENCY_ALLOWANCE_MPCORE_0           (0x320)
#define MC_LATENCY_ALLOWANCE_NVENC_0            (0x328)
#define MC_LATENCY_ALLOWANCE_PPCS_0             (0x344)
#define MC_LATENCY_ALLOWANCE_PPCS_1             (0x348)
#define MC_LATENCY_ALLOWANCE_ISP2_0             (0x370)
#define MC_LATENCY_ALLOWANCE_ISP2_1             (0x374)
#define MC_LATENCY_ALLOWANCE_XUSB_0             (0x37C)
#define MC_LATENCY_ALLOWANCE_XUSB_1             (0x380)
#define MC_LATENCY_ALLOWANCE_TSEC_0             (0x390)
#define MC_LATENCY_ALLOWANCE_VIC_0              (0x394)
#define MC_LATENCY_ALLOWANCE_VI2_0              (0x398)
#define MC_LATENCY_ALLOWANCE_GPU_0              (0x3AC)
#define MC_LATENCY_ALLOWANCE_SDMMCA_0           (0x3B8)
#define MC_LATENCY_ALLOWANCE_SDMMCAA_0          (0x3BC)
#define MC_LATENCY_ALLOWANCE_SDMMC_0            (0x3C0)
#define MC_LATENCY_ALLOWANCE_SDMMCAB_0          (0x3C4)
#define MC_LATENCY_ALLOWANCE_NVDEC_0            (0x3D8)
#define MC_LATENCY_ALLOWANCE_GPU2_0             (0x3E8)
#define MC_VIDEO_PROTECT_VPR_OVERRIDE           (0x418)
#define MC_DIS_PTSA_RATE                        (0x41C)
#define MC_DIS_PTSA_MIN                         (0x420)
#define MC_DIS_PTSA_MAX                         (0x424)
#define MC_DISB_PTSA_RATE                       (0x428)
#define MC_DISB_PTSA_MIN                        (0x42C)
#define MC_DISB_PTSA_MAX                        (0x430)
#define MC_VE_PTSA_RATE                         (0x434)
#define MC_VE_PTSA_MIN                          (0x438)
#define MC_VE_PTSA_MAX                          (0x43C)
#define MC_MLL_MPCORER_PTSA_RATE                (0x44C)
#define MC_RING1_PTSA_RATE                      (0x47C)
#define MC_RING1_PTSA_MIN                       (0x480)
#define MC_RING1_PTSA_MAX                       (0x484)
#define MC_PCX_PTSA_RATE                        (0x4AC)
#define MC_PCX_PTSA_MIN                         (0x4B0)
#define MC_PCX_PTSA_MAX                         (0x4B4)
#define MC_MSE_PTSA_RATE                        (0x4C4)
#define MC_MSE_PTSA_MIN                         (0x4C8)
#define MC_MSE_PTSA_MAX                         (0x4CC)
#define MC_AHB_PTSA_RATE                        (0x4DC)
#define MC_AHB_PTSA_MIN                         (0x4E0)
#define MC_AHB_PTSA_MAX                         (0x4E4)
#define MC_APB_PTSA_RATE                        (0x4E8)
#define MC_APB_PTSA_MIN                         (0x4EC)
#define MC_APB_PTSA_MAX                         (0x4F0)
#define MC_FTOP_PTSA_RATE                       (0x50C)
#define MC_HOST_PTSA_RATE                       (0x518)
#define MC_HOST_PTSA_MIN                        (0x51C)
#define MC_HOST_PTSA_MAX                        (0x520)
#define MC_USBX_PTSA_RATE                       (0x524)
#define MC_USBX_PTSA_MIN                        (0x528)
#define MC_USBX_PTSA_MAX                        (0x52C)
#define MC_USBD_PTSA_RATE                       (0x530)
#define MC_USBD_PTSA_MIN                        (0x534)
#define MC_USBD_PTSA_MAX                        (0x538)
#define MC_GK_PTSA_RATE                         (0x53C)
#define MC_GK_PTSA_MIN                          (0x540)
#define MC_GK_PTSA_MAX                          (0x544)
#define MC_AUD_PTSA_RATE                        (0x548)
#define MC_AUD_PTSA_MIN                         (0x54C)
#define MC_AUD_PTSA_MAX                         (0x550)
#define MC_VICPC_PTSA_RATE                      (0x554)
#define MC_VICPC_PTSA_MIN                       (0x558)
#define MC_VICPC_PTSA_MAX                       (0x55C)
#define MC_JPG_PTSA_RATE                        (0x584)
#define MC_JPG_PTSA_MIN                         (0x588)
#define MC_JPG_PTSA_MAX                         (0x58C)
#define MC_VIDEO_PROTECT_VPR_OVERRIDE1          (0x590)
#define MC_GK2_PTSA_RATE                        (0x610)
#define MC_GK2_PTSA_MIN                         (0x614)
#define MC_GK2_PTSA_MAX                         (0x618)
#define MC_SDM_PTSA_RATE                        (0x61C)
#define MC_SDM_PTSA_MIN                         (0x620)
#define MC_SDM_PTSA_MAX                         (0x624)
#define MC_HDAPC_PTSA_RATE                      (0x628)
#define MC_HDAPC_PTSA_MIN                       (0x62C)
#define MC_HDAPC_PTSA_MAX                       (0x630)
#define MC_VIDEO_PROTECT_BOM                    (0x648)
#define MC_EMEM_CFG_ACCESS_CTRL                 (0x664)
#define MC_SEC_CARVEOUT_BOM                     (0x670)
#define MC_SEC_CARVEOUT_SIZE_MB                 (0x674)
#define MC_SCALED_LATENCY_ALLOWANCE_DISPLAY0A   (0x690)
#define MC_SCALED_LATENCY_ALLOWANCE_DISPLAY0AB  (0x694)
#define MC_SCALED_LATENCY_ALLOWANCE_DISPLAY0B   (0x698)
#define MC_SCALED_LATENCY_ALLOWANCE_DISPLAY0BB  (0x69C)
#define MC_SCALED_LATENCY_ALLOWANCE_DISPLAY0C   (0x6A0)
#define MC_SCALED_LATENCY_ALLOWANCE_DISPLAY0CB  (0x6A4)
#define MC_EMEM_ARB_TIMING_RFCPB                (0x6C0)
#define MC_EMEM_ARB_TIMING_CCDMW                (0x6C4)
#define MC_EMEM_ARB_REFPB_HP_CTRL               (0x6F0)
#define MC_EMEM_ARB_REFPB_BANK_CTRL             (0x6F4)
#define MC_UNTRANSLATED_REGION_CHECK            (0x948)
#define MC_PTSA_GRANT_DECREMENT                 (0x960)
#define MC_EMEM_ARB_OVERRIDE_1                  (0x968)
#define MC_CLIENT_HOTRESET_CTRL_1               (0x970)
#define MC_CLIENT_HOTRESET_STATUS_1             (0x974)
#define MC_VIDEO_PROTECT_BOM_ADR_HI             (0x978)
#define MC_SMMU_PTC_FLUSH_1                     (0x9B8)
#define MC_SEC_CARVEOUT_ADR_HI                  (0x9D4)
#define MC_DA_CONFIG0                           (0x9DC)
#define MC_SMMU_DC1_ASID                        (0xA88)
#define MC_SMMU_SDMMC1A_ASID                    (0xA94)
#define MC_SMMU_SDMMC2A_ASID                    (0xA98)
#define MC_SMMU_SDMMC3A_ASID                    (0xA9C)
#define MC_SMMU_SDMMC4A_ASID                    (0xAA0)
#define MC_SMMU_ISP2B_ASID                      (0xAA4)
#define MC_SMMU_GPU_ASID                        (0xAA8)
#define MC_SMMU_GPUB_ASID                       (0xAAC)
#define MC_SMMU_PPCS2_ASID                      (0xAB0)
#define MC_SMMU_NVDEC_ASID                      (0xAB4)
#define MC_SMMU_APE_ASID                        (0xAB8)
#define MC_SMMU_SE_ASID                         (0xABC)
#define MC_SMMU_NVJPG_ASID                      (0xAC0)
#define MC_SMMU_HC1_ASID                        (0xAC4)
#define MC_SMMU_SE1_ASID                        (0xAC8)
#define MC_SMMU_AXIAP_ASID                      (0xACC)
#define MC_SMMU_ETR_ASID                        (0xAD0)
#define MC_SMMU_TSECB_ASID                      (0xAD4)
#define MC_SMMU_TSEC1_ASID                      (0xAD8)
#define MC_SMMU_TSECB1_ASID                     (0xADC)
#define MC_SMMU_NVDEC1_ASID                     (0xAE0)
#define MC_EMEM_ARB_DHYST_CTRL                  (0xBCC)
#define MC_EMEM_ARB_DHYST_TIMEOUT_UTIL_0        (0xBD0)
#define MC_EMEM_ARB_DHYST_TIMEOUT_UTIL_1        (0xBD4)
#define MC_EMEM_ARB_DHYST_TIMEOUT_UTIL_2        (0xBD8)
#define MC_EMEM_ARB_DHYST_TIMEOUT_UTIL_3        (0xBDC)
#define MC_EMEM_ARB_DHYST_TIMEOUT_UTIL_4        (0xBE0)
#define MC_EMEM_ARB_DHYST_TIMEOUT_UTIL_5        (0xBE4)
#define MC_EMEM_ARB_DHYST_TIMEOUT_UTIL_6        (0xBE8)
#define MC_EMEM_ARB_DHYST_TIMEOUT_UTIL_7        (0xBEC)
#define MC_ERR_GENERALIZED_CARVEOUT_STATUS      (0xC00)


#define MC_SMMU_TLB_CONFIG                                  (0x014)
#define MC_SMMU_PTC_CONFIG                                  (0x018)

#define MC_SMMU_AVPC_ASID                                   (0x23C)
#define MC_SMMU_PPCS1_ASID                                  (0x298)

#define MC_SECURITY_CFG0                                    (0x070)
#define MC_SECURITY_CFG1                                    (0x074)
#define MC_SECURITY_CFG3                                    (0x9BC)

#define MC_SMMU_TRANSLATION_ENABLE_0                        (0x228)
#define MC_SMMU_TRANSLATION_ENABLE_1                        (0x22C)
#define MC_SMMU_TRANSLATION_ENABLE_2                        (0x230)
#define MC_SMMU_TRANSLATION_ENABLE_3                        (0x234)
#define MC_SMMU_TRANSLATION_ENABLE_4                        (0xB98)

#define MC_SMMU_ASID_SECURITY                               (0x038)
#define MC_SMMU_ASID_SECURITY_1                             (0x03c)
#define MC_SMMU_ASID_SECURITY_2                             (0x9e0)
#define MC_SMMU_ASID_SECURITY_3                             (0x9e4)
#define MC_SMMU_ASID_SECURITY_4                             (0x9e8)
#define MC_SMMU_ASID_SECURITY_5                             (0x9ec)
#define MC_SMMU_ASID_SECURITY_6                             (0x9f0)
#define MC_SMMU_ASID_SECURITY_7                             (0x9f4)

#define MC_IRAM_BOM                                         (0x65c)
#define MC_IRAM_TOM                                         (0x660)
#define MC_IRAM_REG_CTRL                                    (0x964)

#define MC_SEC_CARVEOUT_BOM                                 (0x670)
#define MC_SEC_CARVEOUT_SIZE_MB                             (0x674)
#define MC_SEC_CARVEOUT_REG_CTRL                            (0x678)

#define MC_VIDEO_PROTECT_BOM                                (0x648)
#define MC_VIDEO_PROTECT_SIZE_MB                            (0x64c)
#define MC_VIDEO_PROTECT_REG_CTRL                           (0x650)
#define MC_VIDEO_PROTECT_GPU_OVERRIDE_0                     (0x984)
#define MC_VIDEO_PROTECT_GPU_OVERRIDE_1                     (0x988)

#define MC_MTS_CARVEOUT_BOM                                 (0x9a0)
#define MC_MTS_CARVEOUT_SIZE_MB                             (0x9a4)
#define MC_MTS_CARVEOUT_ADR_HI                              (0x9a8)
#define MC_MTS_CARVEOUT_REG_CTRL                            (0x9ac)

#define MC_SECURITY_CARVEOUT1_CFG0                          (0xc08)
#define MC_SECURITY_CARVEOUT1_BOM                           (0xc0c)
#define MC_SECURITY_CARVEOUT1_BOM_HI                        (0xc10)
#define MC_SECURITY_CARVEOUT1_SIZE_128KB                    (0xc14)
#define MC_SECURITY_CARVEOUT1_CLIENT_ACCESS0                (0xc18)
#define MC_SECURITY_CARVEOUT1_CLIENT_ACCESS1                (0xc1c)
#define MC_SECURITY_CARVEOUT1_CLIENT_ACCESS2                (0xc20)
#define MC_SECURITY_CARVEOUT1_CLIENT_ACCESS3                (0xc24)
#define MC_SECURITY_CARVEOUT1_CLIENT_ACCESS4                (0xc28)
#define MC_SECURITY_CARVEOUT1_CLIENT_FORCE_INTERNAL_ACCESS0 (0xc2c)
#define MC_SECURITY_CARVEOUT1_CLIENT_FORCE_INTERNAL_ACCESS1 (0xc30)
#define MC_SECURITY_CARVEOUT1_CLIENT_FORCE_INTERNAL_ACCESS2 (0xc34)
#define MC_SECURITY_CARVEOUT1_CLIENT_FORCE_INTERNAL_ACCESS3 (0xc38)
#define MC_SECURITY_CARVEOUT1_CLIENT_FORCE_INTERNAL_ACCESS4 (0xc3c)

#define MC_SECURITY_CARVEOUT2_CFG0                          (0xc58)
#define MC_SECURITY_CARVEOUT2_BOM                           (0xc5c)
#define MC_SECURITY_CARVEOUT2_BOM_HI                        (0xc60)
#define MC_SECURITY_CARVEOUT2_SIZE_128KB                    (0xc64)
#define MC_SECURITY_CARVEOUT2_CLIENT_ACCESS0                (0xc68)
#define MC_SECURITY_CARVEOUT2_CLIENT_ACCESS1                (0xc6c)
#define MC_SECURITY_CARVEOUT2_CLIENT_ACCESS2                (0xc70)
#define MC_SECURITY_CARVEOUT2_CLIENT_ACCESS3                (0xc74)
#define MC_SECURITY_CARVEOUT2_CLIENT_ACCESS4                (0xc78)
#define MC_SECURITY_CARVEOUT2_CLIENT_FORCE_INTERNAL_ACCESS0 (0xc7c)
#define MC_SECURITY_CARVEOUT2_CLIENT_FORCE_INTERNAL_ACCESS1 (0xc80)
#define MC_SECURITY_CARVEOUT2_CLIENT_FORCE_INTERNAL_ACCESS2 (0xc84)
#define MC_SECURITY_CARVEOUT2_CLIENT_FORCE_INTERNAL_ACCESS3 (0xc88)
#define MC_SECURITY_CARVEOUT2_CLIENT_FORCE_INTERNAL_ACCESS4 (0xc8c)

#define MC_SECURITY_CARVEOUT3_CFG0                          (0xca8)
#define MC_SECURITY_CARVEOUT3_BOM                           (0xcac)
#define MC_SECURITY_CARVEOUT3_BOM_HI                        (0xcb0)
#define MC_SECURITY_CARVEOUT3_SIZE_128KB                    (0xcb4)
#define MC_SECURITY_CARVEOUT3_CLIENT_ACCESS0                (0xcb8)
#define MC_SECURITY_CARVEOUT3_CLIENT_ACCESS1                (0xcbc)
#define MC_SECURITY_CARVEOUT3_CLIENT_ACCESS2                (0xcc0)
#define MC_SECURITY_CARVEOUT3_CLIENT_ACCESS3                (0xcc4)
#define MC_SECURITY_CARVEOUT3_CLIENT_ACCESS4                (0xcc8)
#define MC_SECURITY_CARVEOUT3_CLIENT_FORCE_INTERNAL_ACCESS0 (0xccc)
#define MC_SECURITY_CARVEOUT3_CLIENT_FORCE_INTERNAL_ACCESS1 (0xcd0)
#define MC_SECURITY_CARVEOUT3_CLIENT_FORCE_INTERNAL_ACCESS2 (0xcd4)
#define MC_SECURITY_CARVEOUT3_CLIENT_FORCE_INTERNAL_ACCESS3 (0xcd8)
#define MC_SECURITY_CARVEOUT3_CLIENT_FORCE_INTERNAL_ACCESS4 (0xcdc)

#define MC_SECURITY_CARVEOUT4_CFG0                          (0xcf8)
#define MC_SECURITY_CARVEOUT4_BOM                           (0xcfc)
#define MC_SECURITY_CARVEOUT4_BOM_HI                        (0xd00)
#define MC_SECURITY_CARVEOUT4_SIZE_128KB                    (0xd04)
#define MC_SECURITY_CARVEOUT4_CLIENT_ACCESS0                (0xd08)
#define MC_SECURITY_CARVEOUT4_CLIENT_ACCESS1                (0xd0c)
#define MC_SECURITY_CARVEOUT4_CLIENT_ACCESS2                (0xd10)
#define MC_SECURITY_CARVEOUT4_CLIENT_ACCESS3                (0xd14)
#define MC_SECURITY_CARVEOUT4_CLIENT_ACCESS4                (0xd18)
#define MC_SECURITY_CARVEOUT4_CLIENT_FORCE_INTERNAL_ACCESS0 (0xd1c)
#define MC_SECURITY_CARVEOUT4_CLIENT_FORCE_INTERNAL_ACCESS1 (0xd20)
#define MC_SECURITY_CARVEOUT4_CLIENT_FORCE_INTERNAL_ACCESS2 (0xd24)
#define MC_SECURITY_CARVEOUT4_CLIENT_FORCE_INTERNAL_ACCESS3 (0xd28)
#define MC_SECURITY_CARVEOUT4_CLIENT_FORCE_INTERNAL_ACCESS4 (0xd2c)

#define MC_SECURITY_CARVEOUT5_CFG0                          (0xd48)
#define MC_SECURITY_CARVEOUT5_BOM                           (0xd4c)
#define MC_SECURITY_CARVEOUT5_BOM_HI                        (0xd50)
#define MC_SECURITY_CARVEOUT5_SIZE_128KB                    (0xd54)
#define MC_SECURITY_CARVEOUT5_CLIENT_ACCESS0                (0xd58)
#define MC_SECURITY_CARVEOUT5_CLIENT_ACCESS1                (0xd5c)
#define MC_SECURITY_CARVEOUT5_CLIENT_ACCESS2                (0xd60)
#define MC_SECURITY_CARVEOUT5_CLIENT_ACCESS3                (0xd64)
#define MC_SECURITY_CARVEOUT5_CLIENT_ACCESS4                (0xd68)
#define MC_SECURITY_CARVEOUT5_CLIENT_FORCE_INTERNAL_ACCESS0 (0xd6c)
#define MC_SECURITY_CARVEOUT5_CLIENT_FORCE_INTERNAL_ACCESS1 (0xd70)
#define MC_SECURITY_CARVEOUT5_CLIENT_FORCE_INTERNAL_ACCESS2 (0xd74)
#define MC_SECURITY_CARVEOUT5_CLIENT_FORCE_INTERNAL_ACCESS3 (0xd78)
#define MC_SECURITY_CARVEOUT5_CLIENT_FORCE_INTERNAL_ACCESS4 (0xd7c)

#define MC_STAT_CONTROL                         (0x100)
#define MC_STAT_EMC_CLOCK_LIMIT                 (0x108)
#define MC_STAT_EMC_CLOCK_LIMIT_MSBS            (0x10c)
#define MC_STAT_EMC_FILTER_SET0_ADR_LIMIT_LO    (0x118)
#define MC_STAT_EMC_FILTER_SET0_ADR_LIMIT_HI    (0x11c)
#define MC_STAT_EMC_FILTER_SET0_SPARE           (0x124)
#define MC_STAT_EMC_FILTER_SET0_CLIENT_0        (0x128)
#define MC_STAT_EMC_FILTER_SET0_CLIENT_1        (0x12c)
#define MC_STAT_EMC_FILTER_SET0_CLIENT_2        (0x130)
#define MC_STAT_EMC_FILTER_SET0_CLIENT_3        (0x134)
#define MC_STAT_EMC_SET0_COUNT                  (0x138)
#define MC_STAT_EMC_SET0_COUNT_MSBS             (0x13c)
#define MC_STAT_EMC_FILTER_SET1_ADR_LIMIT_LO    (0x158)
#define MC_STAT_EMC_FILTER_SET1_ADR_LIMIT_HI    (0x15c)
#define MC_STAT_EMC_FILTER_SET1_SPARE           (0x164)
#define MC_STAT_EMC_FILTER_SET1_CLIENT_0        (0x168)
#define MC_STAT_EMC_FILTER_SET1_CLIENT_1        (0x16c)
#define MC_STAT_EMC_FILTER_SET1_CLIENT_2        (0x170)
#define MC_STAT_EMC_FILTER_SET1_CLIENT_3        (0x174)
#define MC_STAT_EMC_SET1_COUNT                  (0x178)
#define MC_STAT_EMC_SET1_COUNT_MSBS             (0x17c)
#define MC_STAT_EMC_FILTER_SET0_ADR_LIMIT_UPPER (0xa20)
#define MC_STAT_EMC_FILTER_SET1_ADR_LIMIT_UPPER (0xa24)
#define MC_STAT_EMC_FILTER_SET0_CLIENT_4        (0xb88)
#define MC_STAT_EMC_FILTER_SET1_CLIENT_4        (0xb8c)
#define MC_STAT_EMC_FILTER_SET0_CLIENT_5        (0xbc4)
#define MC_STAT_EMC_FILTER_SET1_CLIENT_5        (0xbc8)

#define MC_REG_BITS_MASK(NAME)                                      REG_NAMED_BITS_MASK    (MC, NAME)
#define MC_REG_BITS_VALUE(NAME, VALUE)                              REG_NAMED_BITS_VALUE   (MC, NAME, VALUE)
#define MC_REG_BITS_ENUM(NAME, ENUM)                                REG_NAMED_BITS_ENUM    (MC, NAME, ENUM)
#define MC_REG_BITS_ENUM_SEL(NAME, __COND__, TRUE_ENUM, FALSE_ENUM) REG_NAMED_BITS_ENUM_SEL(MC, NAME, __COND__, TRUE_ENUM, FALSE_ENUM)

#define DEFINE_MC_REG(NAME, __OFFSET__, __WIDTH__)                                                                                                                  REG_DEFINE_NAMED_REG           (MC, NAME, __OFFSET__, __WIDTH__)
#define DEFINE_MC_REG_BIT_ENUM(NAME, __OFFSET__, ZERO, ONE)                                                                                                         REG_DEFINE_NAMED_BIT_ENUM      (MC, NAME, __OFFSET__, ZERO, ONE)
#define DEFINE_MC_REG_TWO_BIT_ENUM(NAME, __OFFSET__, ZERO, ONE, TWO, THREE)                                                                                         REG_DEFINE_NAMED_TWO_BIT_ENUM  (MC, NAME, __OFFSET__, ZERO, ONE, TWO, THREE)
#define DEFINE_MC_REG_THREE_BIT_ENUM(NAME, __OFFSET__, ZERO, ONE, TWO, THREE, FOUR, FIVE, SIX, SEVEN)                                                               REG_DEFINE_NAMED_THREE_BIT_ENUM(MC, NAME, __OFFSET__, ZERO, ONE, TWO, THREE, FOUR, FIVE, SIX, SEVEN)
#define DEFINE_MC_REG_FOUR_BIT_ENUM(NAME, __OFFSET__, ZERO, ONE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, ELEVEN, TWELVE, THIRTEEN, FOURTEEN, FIFTEEN) REG_DEFINE_NAMED_FOUR_BIT_ENUM (MC, NAME, __OFFSET__, ZERO, ONE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, ELEVEN, TWELVE, THIRTEEN, FOURTEEN, FIFTEEN)

DEFINE_MC_REG_BIT_ENUM(SMMU_CONFIG_SMMU_ENABLE, 0, DISABLE, ENABLE);

DEFINE_MC_REG(SMMU_TLB_CONFIG_TLB_ACTIVE_LINES, 0, 6);
DEFINE_MC_REG_BIT_ENUM(SMMU_TLB_CONFIG_TLB_ROUND_ROBIN_ARBITRATION, 28, DISABLE, ENABLE);
DEFINE_MC_REG_BIT_ENUM(SMMU_TLB_CONFIG_TLB_HIT_UNDER_MISS, 29, DISABLE, ENABLE);

DEFINE_MC_REG(SMMU_PTC_CONFIG_PTC_INDEX_MAP,  0, 7);
DEFINE_MC_REG(SMMU_PTC_CONFIG_PTC_REQ_LIMIT, 24, 4);
DEFINE_MC_REG_BIT_ENUM(SMMU_PTC_CONFIG_PTC_CACHE_ENABLE, 29, DISABLE, ENABLE);

DEFINE_MC_REG(SMMU_PTB_ASID_CURRENT_ASID, 0, 7);

DEFINE_MC_REG(SMMU_PTB_DATA_ASID_PDE_BASE, 0, 22);
DEFINE_MC_REG_BIT_ENUM(SMMU_PTB_DATA_ASID_NONSECURE, 29, DISABLE, ENABLE);
DEFINE_MC_REG_BIT_ENUM(SMMU_PTB_DATA_ASID_WRITABLE,  30, DISABLE, ENABLE);
DEFINE_MC_REG_BIT_ENUM(SMMU_PTB_DATA_ASID_READABLE,  31, DISABLE, ENABLE);

DEFINE_MC_REG(SMMU_AVPC_ASID_AVPC_ASID, 0, 7);
DEFINE_MC_REG_BIT_ENUM(SMMU_AVPC_ASID_AVPC_SMMU_ENABLE, 31, DISABLE, ENABLE);

DEFINE_MC_REG(SMMU_PPCS1_ASID_PPCS1_ASID, 0, 7);
DEFINE_MC_REG_BIT_ENUM(SMMU_PPCS1_ASID_PPCS1_SMMU_ENABLE, 31, DISABLE, ENABLE);

DEFINE_MC_REG_BIT_ENUM(SMMU_ASID_SECURITY_SECURE_ASIDS_0,   0, NONSECURE, SECURE);
DEFINE_MC_REG_BIT_ENUM(SMMU_ASID_SECURITY_SECURE_ASIDS_1,   1, NONSECURE, SECURE);
DEFINE_MC_REG_BIT_ENUM(SMMU_ASID_SECURITY_SECURE_ASIDS_2,   2, NONSECURE, SECURE);
DEFINE_MC_REG_BIT_ENUM(SMMU_ASID_SECURITY_SECURE_ASIDS_3,   3, NONSECURE, SECURE);
DEFINE_MC_REG_BIT_ENUM(SMMU_ASID_SECURITY_SECURE_ASIDS_4,   4, NONSECURE, SECURE);
DEFINE_MC_REG_BIT_ENUM(SMMU_ASID_SECURITY_SECURE_ASIDS_5,   5, NONSECURE, SECURE);
DEFINE_MC_REG_BIT_ENUM(SMMU_ASID_SECURITY_SECURE_ASIDS_6,   6, NONSECURE, SECURE);
DEFINE_MC_REG_BIT_ENUM(SMMU_ASID_SECURITY_SECURE_ASIDS_7,   7, NONSECURE, SECURE);
DEFINE_MC_REG_BIT_ENUM(SMMU_ASID_SECURITY_SECURE_ASIDS_8,   8, NONSECURE, SECURE);
DEFINE_MC_REG_BIT_ENUM(SMMU_ASID_SECURITY_SECURE_ASIDS_9,   9, NONSECURE, SECURE);
DEFINE_MC_REG_BIT_ENUM(SMMU_ASID_SECURITY_SECURE_ASIDS_10, 10, NONSECURE, SECURE);
DEFINE_MC_REG_BIT_ENUM(SMMU_ASID_SECURITY_SECURE_ASIDS_11, 11, NONSECURE, SECURE);
DEFINE_MC_REG_BIT_ENUM(SMMU_ASID_SECURITY_SECURE_ASIDS_12, 12, NONSECURE, SECURE);
DEFINE_MC_REG_BIT_ENUM(SMMU_ASID_SECURITY_SECURE_ASIDS_13, 13, NONSECURE, SECURE);
DEFINE_MC_REG_BIT_ENUM(SMMU_ASID_SECURITY_SECURE_ASIDS_14, 14, NONSECURE, SECURE);
DEFINE_MC_REG_BIT_ENUM(SMMU_ASID_SECURITY_SECURE_ASIDS_15, 15, NONSECURE, SECURE);

DEFINE_MC_REG_BIT_ENUM(SMMU_ASID_SECURITY_PROMOTING_ASIDS_0,  16, NONPROMOTING, PROMOTING);
DEFINE_MC_REG_BIT_ENUM(SMMU_ASID_SECURITY_PROMOTING_ASIDS_1,  17, NONPROMOTING, PROMOTING);
DEFINE_MC_REG_BIT_ENUM(SMMU_ASID_SECURITY_PROMOTING_ASIDS_2,  18, NONPROMOTING, PROMOTING);
DEFINE_MC_REG_BIT_ENUM(SMMU_ASID_SECURITY_PROMOTING_ASIDS_3,  19, NONPROMOTING, PROMOTING);
DEFINE_MC_REG_BIT_ENUM(SMMU_ASID_SECURITY_PROMOTING_ASIDS_4,  20, NONPROMOTING, PROMOTING);
DEFINE_MC_REG_BIT_ENUM(SMMU_ASID_SECURITY_PROMOTING_ASIDS_5,  21, NONPROMOTING, PROMOTING);
DEFINE_MC_REG_BIT_ENUM(SMMU_ASID_SECURITY_PROMOTING_ASIDS_6,  22, NONPROMOTING, PROMOTING);
DEFINE_MC_REG_BIT_ENUM(SMMU_ASID_SECURITY_PROMOTING_ASIDS_7,  23, NONPROMOTING, PROMOTING);
DEFINE_MC_REG_BIT_ENUM(SMMU_ASID_SECURITY_PROMOTING_ASIDS_8,  24, NONPROMOTING, PROMOTING);
DEFINE_MC_REG_BIT_ENUM(SMMU_ASID_SECURITY_PROMOTING_ASIDS_9,  25, NONPROMOTING, PROMOTING);
DEFINE_MC_REG_BIT_ENUM(SMMU_ASID_SECURITY_PROMOTING_ASIDS_10, 26, NONPROMOTING, PROMOTING);
DEFINE_MC_REG_BIT_ENUM(SMMU_ASID_SECURITY_PROMOTING_ASIDS_11, 27, NONPROMOTING, PROMOTING);
DEFINE_MC_REG_BIT_ENUM(SMMU_ASID_SECURITY_PROMOTING_ASIDS_12, 28, NONPROMOTING, PROMOTING);
DEFINE_MC_REG_BIT_ENUM(SMMU_ASID_SECURITY_PROMOTING_ASIDS_13, 29, NONPROMOTING, PROMOTING);
DEFINE_MC_REG_BIT_ENUM(SMMU_ASID_SECURITY_PROMOTING_ASIDS_14, 30, NONPROMOTING, PROMOTING);
DEFINE_MC_REG_BIT_ENUM(SMMU_ASID_SECURITY_PROMOTING_ASIDS_15, 31, NONPROMOTING, PROMOTING);

DEFINE_MC_REG(SECURITY_CFG0_SECURITY_BOM,    20, 12);
DEFINE_MC_REG(SECURITY_CFG1_SECURITY_SIZE,    0, 13);
DEFINE_MC_REG(SECURITY_CFG3_SECURITY_BOM_HI,  0,  2);

DEFINE_MC_REG_BIT_ENUM(SEC_CARVEOUT_REG_CTRL_SEC_CARVEOUT_WRITE_ACCESS, 0, ENABLED, DISABLED);

DEFINE_MC_REG_BIT_ENUM(VIDEO_PROTECT_REG_CTRL_VIDEO_PROTECT_WRITE_ACCESS,   0, ENABLED, DISABLED);
DEFINE_MC_REG_BIT_ENUM(VIDEO_PROTECT_REG_CTRL_VIDEO_PROTECT_ALLOW_TZ_WRITE, 1, DISABLED, ENABLED);

DEFINE_MC_REG_BIT_ENUM(MTS_CARVEOUT_REG_CTRL_MTS_CARVEOUT_WRITE_ACCESS, 0, ENABLED, DISABLED);

DEFINE_MC_REG_BIT_ENUM(SECURITY_CARVEOUT_CFG0_PROTECT_MODE,         0, LOCKBIT_SECURE, TZ_SECURE);
DEFINE_MC_REG_BIT_ENUM(SECURITY_CARVEOUT_CFG0_LOCK_MODE,            1, UNLOCKED, LOCKED);
DEFINE_MC_REG_BIT_ENUM(SECURITY_CARVEOUT_CFG0_ADDRESS_TYPE,         2, ANY_ADDRESS, UNTRANSLATED_ONLY);
DEFINE_MC_REG_BIT_ENUM(SECURITY_CARVEOUT_CFG0_READ_ACCESS_LEVEL0,   3, DISABLED, ENABLED);
DEFINE_MC_REG_BIT_ENUM(SECURITY_CARVEOUT_CFG0_READ_ACCESS_LEVEL1,   4, DISABLED, ENABLED);
DEFINE_MC_REG_BIT_ENUM(SECURITY_CARVEOUT_CFG0_READ_ACCESS_LEVEL2,   5, DISABLED, ENABLED);
DEFINE_MC_REG_BIT_ENUM(SECURITY_CARVEOUT_CFG0_READ_ACCESS_LEVEL3,   6, DISABLED, ENABLED);
DEFINE_MC_REG_BIT_ENUM(SECURITY_CARVEOUT_CFG0_WRITE_ACCESS_LEVEL0,  7, DISABLED, ENABLED);
DEFINE_MC_REG_BIT_ENUM(SECURITY_CARVEOUT_CFG0_WRITE_ACCESS_LEVEL1,  8, DISABLED, ENABLED);
DEFINE_MC_REG_BIT_ENUM(SECURITY_CARVEOUT_CFG0_WRITE_ACCESS_LEVEL2,  9, DISABLED, ENABLED);
DEFINE_MC_REG_BIT_ENUM(SECURITY_CARVEOUT_CFG0_WRITE_ACCESS_LEVEL3, 10, DISABLED, ENABLED);
DEFINE_MC_REG(SECURITY_CARVEOUT_CFG0_APERTURE_ID, 11, 3);
DEFINE_MC_REG_BIT_ENUM(SECURITY_CARVEOUT_CFG0_DISABLE_READ_CHECK_ACCESS_LEVEL0,  14, ENABLE_CHECKS, DISABLE_CHECKS);
DEFINE_MC_REG_BIT_ENUM(SECURITY_CARVEOUT_CFG0_DISABLE_READ_CHECK_ACCESS_LEVEL1,  15, ENABLE_CHECKS, DISABLE_CHECKS);
DEFINE_MC_REG_BIT_ENUM(SECURITY_CARVEOUT_CFG0_DISABLE_READ_CHECK_ACCESS_LEVEL2,  16, ENABLE_CHECKS, DISABLE_CHECKS);
DEFINE_MC_REG_BIT_ENUM(SECURITY_CARVEOUT_CFG0_DISABLE_READ_CHECK_ACCESS_LEVEL3,  17, ENABLE_CHECKS, DISABLE_CHECKS);
DEFINE_MC_REG_BIT_ENUM(SECURITY_CARVEOUT_CFG0_DISABLE_WRITE_CHECK_ACCESS_LEVEL0, 18, ENABLE_CHECKS, DISABLE_CHECKS);
DEFINE_MC_REG_BIT_ENUM(SECURITY_CARVEOUT_CFG0_DISABLE_WRITE_CHECK_ACCESS_LEVEL1, 19, ENABLE_CHECKS, DISABLE_CHECKS);
DEFINE_MC_REG_BIT_ENUM(SECURITY_CARVEOUT_CFG0_DISABLE_WRITE_CHECK_ACCESS_LEVEL2, 20, ENABLE_CHECKS, DISABLE_CHECKS);
DEFINE_MC_REG_BIT_ENUM(SECURITY_CARVEOUT_CFG0_DISABLE_WRITE_CHECK_ACCESS_LEVEL3, 21, ENABLE_CHECKS, DISABLE_CHECKS);

DEFINE_MC_REG_BIT_ENUM(SECURITY_CARVEOUT_CFG0_SEND_CFG_TO_GPU,            22, DISABLED, ENABLED);
DEFINE_MC_REG_BIT_ENUM(SECURITY_CARVEOUT_CFG0_TZ_GLOBAL_WR_EN,            23, DISABLED, BYPASS_CHECK);
DEFINE_MC_REG_BIT_ENUM(SECURITY_CARVEOUT_CFG0_TZ_GLOBAL_RD_EN,            24, DISABLED, BYPASS_CHECK);
DEFINE_MC_REG_BIT_ENUM(SECURITY_CARVEOUT_CFG0_ALLOW_APERTURE_ID_MISMATCH, 25, DISABLED, ENABLED);
DEFINE_MC_REG_BIT_ENUM(SECURITY_CARVEOUT_CFG0_FORCE_APERTURE_ID_MATCH,    26, DISABLED, ENABLED);
DEFINE_MC_REG_BIT_ENUM(SECURITY_CARVEOUT_CFG0_IS_WPR,                     27, DISABLED, ENABLED);

#define MC_CLIENT_ACCESS_NUM_CLIENTS   32

/* _ACCESS0 */
DEFINE_MC_REG_BIT_ENUM(CLIENT_ACCESS0_PTCR,           (  0 - (MC_CLIENT_ACCESS_NUM_CLIENTS * 0)), DISABLE, ENABLE);
DEFINE_MC_REG_BIT_ENUM(CLIENT_ACCESS0_DISPLAY0A,      (  1 - (MC_CLIENT_ACCESS_NUM_CLIENTS * 0)), DISABLE, ENABLE);
DEFINE_MC_REG_BIT_ENUM(CLIENT_ACCESS0_DISPLAY0AB,     (  2 - (MC_CLIENT_ACCESS_NUM_CLIENTS * 0)), DISABLE, ENABLE);
DEFINE_MC_REG_BIT_ENUM(CLIENT_ACCESS0_DISPLAY0B,      (  3 - (MC_CLIENT_ACCESS_NUM_CLIENTS * 0)), DISABLE, ENABLE);
DEFINE_MC_REG_BIT_ENUM(CLIENT_ACCESS0_DISPLAY0BB,     (  4 - (MC_CLIENT_ACCESS_NUM_CLIENTS * 0)), DISABLE, ENABLE);
DEFINE_MC_REG_BIT_ENUM(CLIENT_ACCESS0_DISPLAY0C,      (  5 - (MC_CLIENT_ACCESS_NUM_CLIENTS * 0)), DISABLE, ENABLE);
DEFINE_MC_REG_BIT_ENUM(CLIENT_ACCESS0_DISPLAY0CB,     (  6 - (MC_CLIENT_ACCESS_NUM_CLIENTS * 0)), DISABLE, ENABLE);
DEFINE_MC_REG_BIT_ENUM(CLIENT_ACCESS0_AFIR,           ( 14 - (MC_CLIENT_ACCESS_NUM_CLIENTS * 0)), DISABLE, ENABLE);
DEFINE_MC_REG_BIT_ENUM(CLIENT_ACCESS0_AVPCARM7R,      ( 15 - (MC_CLIENT_ACCESS_NUM_CLIENTS * 0)), DISABLE, ENABLE);
DEFINE_MC_REG_BIT_ENUM(CLIENT_ACCESS0_DISPLAYHC,      ( 16 - (MC_CLIENT_ACCESS_NUM_CLIENTS * 0)), DISABLE, ENABLE);
DEFINE_MC_REG_BIT_ENUM(CLIENT_ACCESS0_DISPLAYHCB,     ( 17 - (MC_CLIENT_ACCESS_NUM_CLIENTS * 0)), DISABLE, ENABLE);
DEFINE_MC_REG_BIT_ENUM(CLIENT_ACCESS0_HDAR,           ( 21 - (MC_CLIENT_ACCESS_NUM_CLIENTS * 0)), DISABLE, ENABLE);
DEFINE_MC_REG_BIT_ENUM(CLIENT_ACCESS0_HOST1XDMAR,     ( 22 - (MC_CLIENT_ACCESS_NUM_CLIENTS * 0)), DISABLE, ENABLE);
DEFINE_MC_REG_BIT_ENUM(CLIENT_ACCESS0_HOST1XR,        ( 23 - (MC_CLIENT_ACCESS_NUM_CLIENTS * 0)), DISABLE, ENABLE);
DEFINE_MC_REG_BIT_ENUM(CLIENT_ACCESS0_NVENCSRD,       ( 28 - (MC_CLIENT_ACCESS_NUM_CLIENTS * 0)), DISABLE, ENABLE);
DEFINE_MC_REG_BIT_ENUM(CLIENT_ACCESS0_PPCSAHBDMAR,    ( 29 - (MC_CLIENT_ACCESS_NUM_CLIENTS * 0)), DISABLE, ENABLE);
DEFINE_MC_REG_BIT_ENUM(CLIENT_ACCESS0_PPCSAHBSLVR,    ( 30 - (MC_CLIENT_ACCESS_NUM_CLIENTS * 0)), DISABLE, ENABLE);
DEFINE_MC_REG_BIT_ENUM(CLIENT_ACCESS0_SATAR,          ( 31 - (MC_CLIENT_ACCESS_NUM_CLIENTS * 0)), DISABLE, ENABLE);

/* _ACCESS1 */
DEFINE_MC_REG_BIT_ENUM(CLIENT_ACCESS1_VDEBSEVR,       ( 34 - (MC_CLIENT_ACCESS_NUM_CLIENTS * 1)), DISABLE, ENABLE);
DEFINE_MC_REG_BIT_ENUM(CLIENT_ACCESS1_VDEMBER,        ( 35 - (MC_CLIENT_ACCESS_NUM_CLIENTS * 1)), DISABLE, ENABLE);
DEFINE_MC_REG_BIT_ENUM(CLIENT_ACCESS1_VDEMCER,        ( 36 - (MC_CLIENT_ACCESS_NUM_CLIENTS * 1)), DISABLE, ENABLE);
DEFINE_MC_REG_BIT_ENUM(CLIENT_ACCESS1_VDETPER,        ( 37 - (MC_CLIENT_ACCESS_NUM_CLIENTS * 1)), DISABLE, ENABLE);
DEFINE_MC_REG_BIT_ENUM(CLIENT_ACCESS1_MPCORELPR,      ( 38 - (MC_CLIENT_ACCESS_NUM_CLIENTS * 1)), DISABLE, ENABLE);
DEFINE_MC_REG_BIT_ENUM(CLIENT_ACCESS1_MPCORER,        ( 39 - (MC_CLIENT_ACCESS_NUM_CLIENTS * 1)), DISABLE, ENABLE);
DEFINE_MC_REG_BIT_ENUM(CLIENT_ACCESS1_NVENCSWR,       ( 43 - (MC_CLIENT_ACCESS_NUM_CLIENTS * 1)), DISABLE, ENABLE);
DEFINE_MC_REG_BIT_ENUM(CLIENT_ACCESS1_AFIW,           ( 49 - (MC_CLIENT_ACCESS_NUM_CLIENTS * 1)), DISABLE, ENABLE);
DEFINE_MC_REG_BIT_ENUM(CLIENT_ACCESS1_AVPCARM7W,      ( 50 - (MC_CLIENT_ACCESS_NUM_CLIENTS * 1)), DISABLE, ENABLE);
DEFINE_MC_REG_BIT_ENUM(CLIENT_ACCESS1_HDAW,           ( 53 - (MC_CLIENT_ACCESS_NUM_CLIENTS * 1)), DISABLE, ENABLE);
DEFINE_MC_REG_BIT_ENUM(CLIENT_ACCESS1_HOST1XW,        ( 54 - (MC_CLIENT_ACCESS_NUM_CLIENTS * 1)), DISABLE, ENABLE);
DEFINE_MC_REG_BIT_ENUM(CLIENT_ACCESS1_MPCORELPW,      ( 56 - (MC_CLIENT_ACCESS_NUM_CLIENTS * 1)), DISABLE, ENABLE);
DEFINE_MC_REG_BIT_ENUM(CLIENT_ACCESS1_MPCOREW,        ( 57 - (MC_CLIENT_ACCESS_NUM_CLIENTS * 1)), DISABLE, ENABLE);
DEFINE_MC_REG_BIT_ENUM(CLIENT_ACCESS1_PPCSAHBDMAW,    ( 59 - (MC_CLIENT_ACCESS_NUM_CLIENTS * 1)), DISABLE, ENABLE);
DEFINE_MC_REG_BIT_ENUM(CLIENT_ACCESS1_PPCSAHBSLVW,    ( 60 - (MC_CLIENT_ACCESS_NUM_CLIENTS * 1)), DISABLE, ENABLE);
DEFINE_MC_REG_BIT_ENUM(CLIENT_ACCESS1_SATAW,          ( 61 - (MC_CLIENT_ACCESS_NUM_CLIENTS * 1)), DISABLE, ENABLE);
DEFINE_MC_REG_BIT_ENUM(CLIENT_ACCESS1_VDEBSEVW,       ( 62 - (MC_CLIENT_ACCESS_NUM_CLIENTS * 1)), DISABLE, ENABLE);
DEFINE_MC_REG_BIT_ENUM(CLIENT_ACCESS1_VDEDBGW,        ( 63 - (MC_CLIENT_ACCESS_NUM_CLIENTS * 1)), DISABLE, ENABLE);

/* _ACCESS2 */
DEFINE_MC_REG_BIT_ENUM(CLIENT_ACCESS2_VDEMBEW,        ( 64 - (MC_CLIENT_ACCESS_NUM_CLIENTS * 2)), DISABLE, ENABLE);
DEFINE_MC_REG_BIT_ENUM(CLIENT_ACCESS2_VDETPMW,        ( 65 - (MC_CLIENT_ACCESS_NUM_CLIENTS * 2)), DISABLE, ENABLE);
DEFINE_MC_REG_BIT_ENUM(CLIENT_ACCESS2_ISPRA,          ( 68 - (MC_CLIENT_ACCESS_NUM_CLIENTS * 2)), DISABLE, ENABLE);
DEFINE_MC_REG_BIT_ENUM(CLIENT_ACCESS2_ISPWA,          ( 70 - (MC_CLIENT_ACCESS_NUM_CLIENTS * 2)), DISABLE, ENABLE);
DEFINE_MC_REG_BIT_ENUM(CLIENT_ACCESS2_ISPWB,          ( 71 - (MC_CLIENT_ACCESS_NUM_CLIENTS * 2)), DISABLE, ENABLE);
DEFINE_MC_REG_BIT_ENUM(CLIENT_ACCESS2_XUSB_HOSTR,     ( 74 - (MC_CLIENT_ACCESS_NUM_CLIENTS * 2)), DISABLE, ENABLE);
DEFINE_MC_REG_BIT_ENUM(CLIENT_ACCESS2_XUSB_HOSTW,     ( 75 - (MC_CLIENT_ACCESS_NUM_CLIENTS * 2)), DISABLE, ENABLE);
DEFINE_MC_REG_BIT_ENUM(CLIENT_ACCESS2_XUSB_DEVR,      ( 76 - (MC_CLIENT_ACCESS_NUM_CLIENTS * 2)), DISABLE, ENABLE);
DEFINE_MC_REG_BIT_ENUM(CLIENT_ACCESS2_XUSB_DEVW,      ( 77 - (MC_CLIENT_ACCESS_NUM_CLIENTS * 2)), DISABLE, ENABLE);
DEFINE_MC_REG_BIT_ENUM(CLIENT_ACCESS2_ISPRAB,         ( 78 - (MC_CLIENT_ACCESS_NUM_CLIENTS * 2)), DISABLE, ENABLE);
DEFINE_MC_REG_BIT_ENUM(CLIENT_ACCESS2_ISPWAB,         ( 80 - (MC_CLIENT_ACCESS_NUM_CLIENTS * 2)), DISABLE, ENABLE);
DEFINE_MC_REG_BIT_ENUM(CLIENT_ACCESS2_ISPWBB,         ( 81 - (MC_CLIENT_ACCESS_NUM_CLIENTS * 2)), DISABLE, ENABLE);
DEFINE_MC_REG_BIT_ENUM(CLIENT_ACCESS2_TSECSRD,        ( 84 - (MC_CLIENT_ACCESS_NUM_CLIENTS * 2)), DISABLE, ENABLE);
DEFINE_MC_REG_BIT_ENUM(CLIENT_ACCESS2_TSECSWR,        ( 85 - (MC_CLIENT_ACCESS_NUM_CLIENTS * 2)), DISABLE, ENABLE);
DEFINE_MC_REG_BIT_ENUM(CLIENT_ACCESS2_A9AVPSCR,       ( 86 - (MC_CLIENT_ACCESS_NUM_CLIENTS * 2)), DISABLE, ENABLE);
DEFINE_MC_REG_BIT_ENUM(CLIENT_ACCESS2_A9AVPSCW,       ( 87 - (MC_CLIENT_ACCESS_NUM_CLIENTS * 2)), DISABLE, ENABLE);
DEFINE_MC_REG_BIT_ENUM(CLIENT_ACCESS2_GPUSRD,         ( 88 - (MC_CLIENT_ACCESS_NUM_CLIENTS * 2)), DISABLE, ENABLE);
DEFINE_MC_REG_BIT_ENUM(CLIENT_ACCESS2_GPUSWR,         ( 89 - (MC_CLIENT_ACCESS_NUM_CLIENTS * 2)), DISABLE, ENABLE);
DEFINE_MC_REG_BIT_ENUM(CLIENT_ACCESS2_DISPLAYT,       ( 90 - (MC_CLIENT_ACCESS_NUM_CLIENTS * 2)), DISABLE, ENABLE);

/* _ACCESS3 */
DEFINE_MC_REG_BIT_ENUM(CLIENT_ACCESS3_SDMMCRA,        ( 96 - (MC_CLIENT_ACCESS_NUM_CLIENTS * 3)), DISABLE, ENABLE);
DEFINE_MC_REG_BIT_ENUM(CLIENT_ACCESS3_SDMMCRAA,       ( 97 - (MC_CLIENT_ACCESS_NUM_CLIENTS * 3)), DISABLE, ENABLE);
DEFINE_MC_REG_BIT_ENUM(CLIENT_ACCESS3_SDMMCR,         ( 98 - (MC_CLIENT_ACCESS_NUM_CLIENTS * 3)), DISABLE, ENABLE);
DEFINE_MC_REG_BIT_ENUM(CLIENT_ACCESS3_SDMMCRAB,       ( 99 - (MC_CLIENT_ACCESS_NUM_CLIENTS * 3)), DISABLE, ENABLE);
DEFINE_MC_REG_BIT_ENUM(CLIENT_ACCESS3_SDMMCWA,        (100 - (MC_CLIENT_ACCESS_NUM_CLIENTS * 3)), DISABLE, ENABLE);
DEFINE_MC_REG_BIT_ENUM(CLIENT_ACCESS3_SDMMCWAA,       (101 - (MC_CLIENT_ACCESS_NUM_CLIENTS * 3)), DISABLE, ENABLE);
DEFINE_MC_REG_BIT_ENUM(CLIENT_ACCESS3_SDMMCW,         (102 - (MC_CLIENT_ACCESS_NUM_CLIENTS * 3)), DISABLE, ENABLE);
DEFINE_MC_REG_BIT_ENUM(CLIENT_ACCESS3_SDMMCWAB,       (103 - (MC_CLIENT_ACCESS_NUM_CLIENTS * 3)), DISABLE, ENABLE);
DEFINE_MC_REG_BIT_ENUM(CLIENT_ACCESS3_VICSRD,         (108 - (MC_CLIENT_ACCESS_NUM_CLIENTS * 3)), DISABLE, ENABLE);
DEFINE_MC_REG_BIT_ENUM(CLIENT_ACCESS3_VICSWR,         (109 - (MC_CLIENT_ACCESS_NUM_CLIENTS * 3)), DISABLE, ENABLE);
DEFINE_MC_REG_BIT_ENUM(CLIENT_ACCESS3_VIW,            (114 - (MC_CLIENT_ACCESS_NUM_CLIENTS * 3)), DISABLE, ENABLE);
DEFINE_MC_REG_BIT_ENUM(CLIENT_ACCESS3_DISPLAYD,       (115 - (MC_CLIENT_ACCESS_NUM_CLIENTS * 3)), DISABLE, ENABLE);
DEFINE_MC_REG_BIT_ENUM(CLIENT_ACCESS3_NVDECSRD,       (120 - (MC_CLIENT_ACCESS_NUM_CLIENTS * 3)), DISABLE, ENABLE);
DEFINE_MC_REG_BIT_ENUM(CLIENT_ACCESS3_NVDECSWR,       (121 - (MC_CLIENT_ACCESS_NUM_CLIENTS * 3)), DISABLE, ENABLE);
DEFINE_MC_REG_BIT_ENUM(CLIENT_ACCESS3_APER,           (122 - (MC_CLIENT_ACCESS_NUM_CLIENTS * 3)), DISABLE, ENABLE);
DEFINE_MC_REG_BIT_ENUM(CLIENT_ACCESS3_APEW,           (123 - (MC_CLIENT_ACCESS_NUM_CLIENTS * 3)), DISABLE, ENABLE);
DEFINE_MC_REG_BIT_ENUM(CLIENT_ACCESS3_NVJPGSRD,       (126 - (MC_CLIENT_ACCESS_NUM_CLIENTS * 3)), DISABLE, ENABLE);
DEFINE_MC_REG_BIT_ENUM(CLIENT_ACCESS3_NVJPGSWR,       (127 - (MC_CLIENT_ACCESS_NUM_CLIENTS * 3)), DISABLE, ENABLE);

/* _ACCESS4 */
DEFINE_MC_REG_BIT_ENUM(CLIENT_ACCESS4_SESRD,          (128 - (MC_CLIENT_ACCESS_NUM_CLIENTS * 4)), DISABLE, ENABLE);
DEFINE_MC_REG_BIT_ENUM(CLIENT_ACCESS4_SESWR,          (129 - (MC_CLIENT_ACCESS_NUM_CLIENTS * 4)), DISABLE, ENABLE);
DEFINE_MC_REG_BIT_ENUM(CLIENT_ACCESS4_AXIAPR,         (130 - (MC_CLIENT_ACCESS_NUM_CLIENTS * 4)), DISABLE, ENABLE);
DEFINE_MC_REG_BIT_ENUM(CLIENT_ACCESS4_AXIAPW,         (131 - (MC_CLIENT_ACCESS_NUM_CLIENTS * 4)), DISABLE, ENABLE);
DEFINE_MC_REG_BIT_ENUM(CLIENT_ACCESS4_ETRR,           (132 - (MC_CLIENT_ACCESS_NUM_CLIENTS * 4)), DISABLE, ENABLE);
DEFINE_MC_REG_BIT_ENUM(CLIENT_ACCESS4_ETRW,           (133 - (MC_CLIENT_ACCESS_NUM_CLIENTS * 4)), DISABLE, ENABLE);
DEFINE_MC_REG_BIT_ENUM(CLIENT_ACCESS4_TSECRDB,        (134 - (MC_CLIENT_ACCESS_NUM_CLIENTS * 4)), DISABLE, ENABLE);
DEFINE_MC_REG_BIT_ENUM(CLIENT_ACCESS4_TSECWRB,        (135 - (MC_CLIENT_ACCESS_NUM_CLIENTS * 4)), DISABLE, ENABLE);
DEFINE_MC_REG_BIT_ENUM(CLIENT_ACCESS4_GPUSRD2,        (136 - (MC_CLIENT_ACCESS_NUM_CLIENTS * 4)), DISABLE, ENABLE);
DEFINE_MC_REG_BIT_ENUM(CLIENT_ACCESS4_GPUSWR2,        (137 - (MC_CLIENT_ACCESS_NUM_CLIENTS * 4)), DISABLE, ENABLE);

DEFINE_MC_REG(IRAM_BOM_IRAM_BOM, 12, BITSIZEOF(u32) - 12);
DEFINE_MC_REG(IRAM_TOM_IRAM_TOM, 12, BITSIZEOF(u32) - 12);

DEFINE_MC_REG_BIT_ENUM(IRAM_REG_CTRL_IRAM_CFG_WRITE_ACCESS, 0, ENABLED, DISABLED);

DEFINE_MC_REG_BIT_ENUM(UNTRANSLATED_REGION_CHECK_UNTRANSLATED_REGION_CHECK_ACCESS,          0, ENABLED, DISABLED);
DEFINE_MC_REG_BIT_ENUM(UNTRANSLATED_REGION_CHECK_REQUIRE_UNTRANSLATED_CLIENTS_HIT_CARVEOUT, 8, DISABLED, ENABLED);
DEFINE_MC_REG_BIT_ENUM(UNTRANSLATED_REGION_CHECK_REQUIRE_UNTRANSLATED_GPU_HIT_CARVEOUT,     9, DISABLED, ENABLED);
