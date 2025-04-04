// SPDX-License-Identifier: GPL-2.0-only
// Copyright (c) 2024 FIXME
// Generated with linux-mdss-dsi-panel-driver-generator from vendor device tree:
//   Copyright (c) 2013, The Linux Foundation. All rights reserved. (FIXME)

#include <linux/delay.h>
#include <linux/gpio/consumer.h>
#include <linux/mod_devicetable.h>
#include <linux/module.h>
#include <linux/regulator/consumer.h>

#include <drm/drm_mipi_dsi.h>
#include <drm/drm_modes.h>
#include <drm/drm_panel.h>
#include <drm/drm_probe_helper.h>

/* From panel-novatek-nt35510.c */
#define NT35520_DOPCTR_0_DSIM BIT(4) /* Enable video mode on DSI */

struct yushun_nt35520 {
	struct drm_panel panel;
	struct mipi_dsi_device *dsi;
	struct regulator *supply;
	struct gpio_desc *reset_gpio;
};

static inline struct yushun_nt35520 *to_yushun_nt35520(struct drm_panel *panel)
{
	return container_of(panel, struct yushun_nt35520, panel);
}

static void yushun_nt35520_reset(struct yushun_nt35520 *ctx)
{
	gpiod_set_value_cansleep(ctx->reset_gpio, 0);
	msleep(20);
	gpiod_set_value_cansleep(ctx->reset_gpio, 1);
	msleep(20);
	gpiod_set_value_cansleep(ctx->reset_gpio, 0);
	msleep(20);
}

static int yushun_nt35520_on(struct yushun_nt35520 *ctx)
{
	struct mipi_dsi_multi_context dsi_ctx = { .dsi = ctx->dsi };

	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xf0,
					 0x55, 0xaa, 0x52, 0x08, 0x00);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xff,
					 0xaa, 0x55, 0xa5, 0x80);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x6f, 0x13);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xf7, 0x00);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x6f, 0x01);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xf3, 0x00);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xb1, 0x68 | NT35520_DOPCTR_0_DSIM, 0x21);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xbd,
					 0x02, 0x67, 0x20, 0x20, 0x00);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x6f, 0x02);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xb8, 0x08);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xbb, 0x11, 0x11);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xbc, 0x00, 0x00);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xb6, 0x01);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xc8, 0x83);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xf0,
					 0x55, 0xaa, 0x52, 0x08, 0x01);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xb0, 0x0f, 0x0f);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xb1, 0x0f, 0x0f);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xce, 0x66);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xc0, 0x0c);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xb5, 0x05, 0x05);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xbe, 0x3e);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xb3, 0x28, 0x28);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xb4, 0x19, 0x19);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xb9, 0x34, 0x34);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xba, 0x24, 0x24);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xbc, 0x70, 0x00);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xbd, 0x70, 0x00);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xca, 0x00);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xf0,
					 0x55, 0xaa, 0x52, 0x08, 0x02);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xee, 0x00);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xb0,
					 0x00, 0xd2, 0x00, 0xde, 0x00, 0xf0,
					 0x01, 0x01, 0x01, 0x11, 0x01, 0x29,
					 0x01, 0x41, 0x01, 0x68);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xb1,
					 0x01, 0x87, 0x01, 0xb8, 0x01, 0xe2,
					 0x02, 0x23, 0x02, 0x57, 0x02, 0x5a,
					 0x02, 0x8e, 0x02, 0xc6);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xb2,
					 0x02, 0xef, 0x03, 0x20, 0x03, 0x3e,
					 0x03, 0x63, 0x03, 0x7e, 0x03, 0x9c,
					 0x03, 0xaf, 0x03, 0xbf);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xb3,
					 0x03, 0xfc, 0x03, 0xff);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xb4,
					 0x00, 0x07, 0x00, 0x50, 0x00, 0x84,
					 0x00, 0xa6, 0x00, 0xc1, 0x00, 0xe7,
					 0x01, 0x08, 0x01, 0x3b);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xb5,
					 0x01, 0x63, 0x01, 0xa0, 0x01, 0xcf,
					 0x02, 0x18, 0x02, 0x50, 0x02, 0x52,
					 0x02, 0x88, 0x02, 0xc1);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xb6,
					 0x02, 0xea, 0x03, 0x1b, 0x03, 0x3a,
					 0x03, 0x60, 0x03, 0x79, 0x03, 0x98,
					 0x03, 0xa9, 0x03, 0xc6);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xb7,
					 0x03, 0xd6, 0x03, 0xff);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xb8,
					 0x00, 0xb6, 0x00, 0xc1, 0x00, 0xd3,
					 0x00, 0xe5, 0x00, 0xf5, 0x01, 0x0f,
					 0x01, 0x29, 0x01, 0x51);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xb9,
					 0x01, 0x73, 0x01, 0xa9, 0x01, 0xd6,
					 0x02, 0x1c, 0x02, 0x52, 0x02, 0x55,
					 0x02, 0x8a, 0x02, 0xc4);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xba,
					 0x02, 0xef, 0x03, 0x24, 0x03, 0x4b,
					 0x03, 0x73, 0x03, 0x87, 0x03, 0x9f,
					 0x03, 0xa3, 0x03, 0xbd);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xbb,
					 0x03, 0xf2, 0x03, 0xff);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xbc,
					 0x00, 0xd2, 0x00, 0xde, 0x00, 0xf0,
					 0x01, 0x01, 0x01, 0x11, 0x01, 0x29,
					 0x01, 0x41, 0x01, 0x68);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xbd,
					 0x01, 0x87, 0x01, 0xb8, 0x01, 0xe2,
					 0x02, 0x23, 0x02, 0x57, 0x02, 0x5a,
					 0x02, 0x8e, 0x02, 0xc6);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xbe,
					 0x02, 0xef, 0x03, 0x20, 0x03, 0x3e,
					 0x03, 0x63, 0x03, 0x7e, 0x03, 0x9c,
					 0x03, 0xaf, 0x03, 0xbf);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xbf,
					 0x03, 0xfc, 0x03, 0xff);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xc0,
					 0x00, 0x07, 0x00, 0x50, 0x00, 0x84,
					 0x00, 0xa6, 0x00, 0xc1, 0x00, 0xe7,
					 0x01, 0x08, 0x01, 0x3b);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xc1,
					 0x01, 0x63, 0x01, 0xa0, 0x01, 0xcf,
					 0x02, 0x18, 0x02, 0x50, 0x02, 0x52,
					 0x02, 0x88, 0x02, 0xc1);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xc2,
					 0x02, 0xea, 0x03, 0x1b, 0x03, 0x3a,
					 0x03, 0x60, 0x03, 0x79, 0x03, 0x98,
					 0x03, 0xa9, 0x03, 0xc6);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xc3,
					 0x03, 0xd6, 0x03, 0xff);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xc4,
					 0x00, 0xb6, 0x00, 0xc1, 0x00, 0xd3,
					 0x00, 0xe5, 0x00, 0xf5, 0x01, 0x0f,
					 0x01, 0x29, 0x01, 0x51);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xc5,
					 0x01, 0x73, 0x01, 0xa9, 0x01, 0xd6,
					 0x02, 0x1c, 0x02, 0x52, 0x02, 0x55,
					 0x02, 0x8a, 0x02, 0xc4);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xc6,
					 0x02, 0xef, 0x03, 0x24, 0x03, 0x4b,
					 0x03, 0x73, 0x03, 0x87, 0x03, 0x9f,
					 0x03, 0xa3, 0x03, 0xbd);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xc7,
					 0x03, 0xf2, 0x03, 0xff);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xf0,
					 0x55, 0xaa, 0x52, 0x08, 0x06);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xb0, 0x2e, 0x2e);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xb1, 0x2e, 0x2e);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xb2, 0x2e, 0x2e);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xb3, 0x2e, 0x09);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xb4, 0x0b, 0x23);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xb5, 0x1d, 0x1f);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xb6, 0x11, 0x17);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xb7, 0x13, 0x19);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xb8, 0x01, 0x03);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xb9, 0x2e, 0x2e);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xba, 0x2e, 0x2e);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xbb, 0x02, 0x00);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xbc, 0x18, 0x12);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xbd, 0x16, 0x10);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xbe, 0x1e, 0x1c);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xbf, 0x22, 0x0a);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xc0, 0x08, 0x2e);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xc1, 0x2e, 0x2e);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xc2, 0x2e, 0x2e);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xc3, 0x2e, 0x2e);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xe5, 0x25, 0x24);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xc4, 0x2e, 0x2e);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xc5, 0x2e, 0x2e);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xc6, 0x2e, 0x2e);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xc7, 0x2e, 0x02);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xc8, 0x00, 0x24);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xc9, 0x1e, 0x1c);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xca, 0x18, 0x12);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xcb, 0x16, 0x10);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xcc, 0x0a, 0x08);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xcd, 0x2e, 0x2e);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xce, 0x2e, 0x2e);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xcf, 0x09, 0x0b);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xd0, 0x11, 0x17);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xd1, 0x13, 0x19);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xd2, 0x1d, 0x1f);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xd3, 0x25, 0x01);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xd4, 0x03, 0x2e);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xd5, 0x2e, 0x2e);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xd6, 0x2e, 0x2e);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xd7, 0x2e, 0x2e);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xe6, 0x22, 0x23);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xd8,
					 0x00, 0x00, 0x00, 0x00, 0x00);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xd9,
					 0x00, 0x00, 0x00, 0x00, 0x00);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xe7, 0x00);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xf0,
					 0x55, 0xaa, 0x52, 0x08, 0x05);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xed, 0x30);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xf0,
					 0x55, 0xaa, 0x52, 0x08, 0x03);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xb0, 0x20, 0x00);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xb1, 0x20, 0x00);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xf0,
					 0x55, 0xaa, 0x52, 0x08, 0x05);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xb0, 0x17, 0x06);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xb8, 0x00);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xbd,
					 0x0f, 0x03, 0x03, 0x00, 0x03);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xb1, 0x17, 0x06);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xb9, 0x00, 0x03);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xb2, 0x17, 0x06);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xba, 0x00, 0x03);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xb3, 0x17, 0x06);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xbb, 0x00, 0x00);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xb4, 0x17, 0x06);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xb5, 0x17, 0x06);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xb6, 0x17, 0x06);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xb7, 0x17, 0x06);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xbc, 0x00, 0x01);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xe5, 0x06);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xe6, 0x06);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xe7, 0x06);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xe8, 0x06);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xe9, 0x0a);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xea, 0x06);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xeb, 0x06);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xec, 0x06);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xf0,
					 0x55, 0xaa, 0x52, 0x08, 0x05);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xc0, 0x07);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xc1, 0x05);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xf0,
					 0x55, 0xaa, 0x52, 0x08, 0x03);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xb2,
					 0x04, 0x00, 0x52, 0x01, 0xce);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xb3,
					 0x04, 0x00, 0x52, 0x01, 0xce);
	mipi_dsi_msleep(&dsi_ctx, 120);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xf0,
					 0x55, 0xaa, 0x52, 0x08, 0x05);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xc4, 0x82);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xc5, 0x80);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xf0,
					 0x55, 0xaa, 0x52, 0x08, 0x03);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xb6,
					 0x04, 0x00, 0x52, 0x01, 0xce);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xb7,
					 0x04, 0x00, 0x52, 0x01, 0xce);
	mipi_dsi_msleep(&dsi_ctx, 120);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xf0,
					 0x55, 0xaa, 0x52, 0x08, 0x05);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xc8, 0x03, 0x20);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xc9, 0x01, 0x21);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xca, 0x03, 0x20);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xcb, 0x07, 0x20);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xf0,
					 0x55, 0xaa, 0x52, 0x08, 0x03);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xc4, 0x60);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xc5, 0x40);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xf0,
					 0x55, 0xaa, 0x52, 0x08, 0x03);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xba,
					 0x44, 0x00, 0x4b, 0x01, 0xbe);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xbb,
					 0x44, 0x00, 0x4b, 0x01, 0xbe);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xbc,
					 0x53, 0x00, 0x03, 0x00, 0x4b);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xbd,
					 0x53, 0x00, 0x03, 0x00, 0x4b);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xf0,
					 0x55, 0xaa, 0x52, 0x08, 0x05);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xd1,
					 0x03, 0x05, 0x00, 0x05, 0x00, 0x00,
					 0x00, 0x00, 0x00, 0x00, 0x00);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xd2,
					 0x03, 0x05, 0x00, 0x03, 0x00, 0x00,
					 0x00, 0x00, 0x00, 0x00, 0x00);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xd3,
					 0x03, 0x05, 0x04, 0x05, 0x00, 0x00,
					 0x00, 0x00, 0x00, 0x00, 0x00);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xd4,
					 0x03, 0x05, 0x04, 0x03, 0x00, 0x00,
					 0x00, 0x00, 0x00, 0x00, 0x00);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xf0,
					 0x55, 0xaa, 0x52, 0x08, 0x03);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xc4, 0x40);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xc5, 0x40);
	mipi_dsi_dcs_exit_sleep_mode_multi(&dsi_ctx);
	mipi_dsi_msleep(&dsi_ctx, 120);
	mipi_dsi_dcs_set_display_on_multi(&dsi_ctx);

	return dsi_ctx.accum_err;
}

static int yushun_nt35520_off(struct yushun_nt35520 *ctx)
{
	struct mipi_dsi_multi_context dsi_ctx = { .dsi = ctx->dsi };

	mipi_dsi_dcs_set_display_off_multi(&dsi_ctx);
	mipi_dsi_msleep(&dsi_ctx, 50);
	mipi_dsi_dcs_enter_sleep_mode_multi(&dsi_ctx);
	mipi_dsi_msleep(&dsi_ctx, 120);

	return dsi_ctx.accum_err;
}

static int yushun_nt35520_prepare(struct drm_panel *panel)
{
	struct yushun_nt35520 *ctx = to_yushun_nt35520(panel);
	struct device *dev = &ctx->dsi->dev;
	int ret;

	ret = regulator_enable(ctx->supply);
	if (ret < 0) {
		dev_err(dev, "Failed to enable regulator: %d\n", ret);
		return ret;
	}

	yushun_nt35520_reset(ctx);

	ret = yushun_nt35520_on(ctx);
	if (ret < 0) {
		dev_err(dev, "Failed to initialize panel: %d\n", ret);
		gpiod_set_value_cansleep(ctx->reset_gpio, 1);
		regulator_disable(ctx->supply);
		return ret;
	}

	return 0;
}

static int yushun_nt35520_unprepare(struct drm_panel *panel)
{
	struct yushun_nt35520 *ctx = to_yushun_nt35520(panel);
	struct device *dev = &ctx->dsi->dev;
	int ret;

	ret = yushun_nt35520_off(ctx);
	if (ret < 0)
		dev_err(dev, "Failed to un-initialize panel: %d\n", ret);

	gpiod_set_value_cansleep(ctx->reset_gpio, 1);
	regulator_disable(ctx->supply);

	return 0;
}

static const struct drm_display_mode yushun_nt35520_mode = {
	.clock = (720 + 90 + 12 + 88) * (1280 + 20 + 4 + 16) * 60 / 1000,
	.hdisplay = 720,
	.hsync_start = 720 + 90,
	.hsync_end = 720 + 90 + 12,
	.htotal = 720 + 90 + 12 + 88,
	.vdisplay = 1280,
	.vsync_start = 1280 + 20,
	.vsync_end = 1280 + 20 + 4,
	.vtotal = 1280 + 20 + 4 + 16,
	.width_mm = 62,
	.height_mm = 111,
	.type = DRM_MODE_TYPE_DRIVER,
};

static int yushun_nt35520_get_modes(struct drm_panel *panel,
				    struct drm_connector *connector)
{
	return drm_connector_helper_get_modes_fixed(connector, &yushun_nt35520_mode);
}

static const struct drm_panel_funcs yushun_nt35520_panel_funcs = {
	.prepare = yushun_nt35520_prepare,
	.unprepare = yushun_nt35520_unprepare,
	.get_modes = yushun_nt35520_get_modes,
};

static int yushun_nt35520_probe(struct mipi_dsi_device *dsi)
{
	struct device *dev = &dsi->dev;
	struct yushun_nt35520 *ctx;
	int ret;

	ctx = devm_kzalloc(dev, sizeof(*ctx), GFP_KERNEL);
	if (!ctx)
		return -ENOMEM;

	ctx->supply = devm_regulator_get(dev, "power");
	if (IS_ERR(ctx->supply))
		return dev_err_probe(dev, PTR_ERR(ctx->supply),
				     "Failed to get power regulator\n");

	ctx->reset_gpio = devm_gpiod_get(dev, "reset", GPIOD_OUT_HIGH);
	if (IS_ERR(ctx->reset_gpio))
		return dev_err_probe(dev, PTR_ERR(ctx->reset_gpio),
				     "Failed to get reset-gpios\n");

	ctx->dsi = dsi;
	mipi_dsi_set_drvdata(dsi, ctx);

	dsi->lanes = 4;
	dsi->format = MIPI_DSI_FMT_RGB888;
	dsi->mode_flags = MIPI_DSI_MODE_VIDEO | MIPI_DSI_MODE_VIDEO_SYNC_PULSE |
			  MIPI_DSI_CLOCK_NON_CONTINUOUS | MIPI_DSI_MODE_LPM;

	drm_panel_init(&ctx->panel, dev, &yushun_nt35520_panel_funcs,
		       DRM_MODE_CONNECTOR_DSI);
	ctx->panel.prepare_prev_first = true;

	ret = drm_panel_of_backlight(&ctx->panel);
	if (ret)
		return dev_err_probe(dev, ret, "Failed to get backlight\n");

	drm_panel_add(&ctx->panel);

	ret = mipi_dsi_attach(dsi);
	if (ret < 0) {
		drm_panel_remove(&ctx->panel);
		return dev_err_probe(dev, ret, "Failed to attach to DSI host\n");
	}

	return 0;
}

static void yushun_nt35520_remove(struct mipi_dsi_device *dsi)
{
	struct yushun_nt35520 *ctx = mipi_dsi_get_drvdata(dsi);
	int ret;

	ret = mipi_dsi_detach(dsi);
	if (ret < 0)
		dev_err(&dsi->dev, "Failed to detach from DSI host: %d\n", ret);

	drm_panel_remove(&ctx->panel);
}

static const struct of_device_id yushun_nt35520_of_match[] = {
	{ .compatible = "longcheer,yushun-nt35520" }, // FIXME
	{ /* sentinel */ }
};
MODULE_DEVICE_TABLE(of, yushun_nt35520_of_match);

static struct mipi_dsi_driver yushun_nt35520_driver = {
	.probe = yushun_nt35520_probe,
	.remove = yushun_nt35520_remove,
	.driver = {
		.name = "panel-longcheer-yushun-nt35520",
		.of_match_table = yushun_nt35520_of_match,
	},
};
module_mipi_dsi_driver(yushun_nt35520_driver);

MODULE_AUTHOR("linux-mdss-dsi-panel-driver-generator <fix@me>"); // FIXME
MODULE_DESCRIPTION("DRM driver for yushun NT35520 720p command mode panel");
MODULE_LICENSE("GPL");
