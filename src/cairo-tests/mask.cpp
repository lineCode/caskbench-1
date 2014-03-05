#include <stdio.h>
#include <stdlib.h>
#include <cairo.h>

#include "caskbench.h"

static cairo_pattern_t *mask;

int
ca_setup_mask(caskbench_context_t *ctx)
{
    // TODO: Create a stipple mask pattern
    mask = cairo_pattern_create_rgba (0, 0, 0, 0.5);
    return 1;
}

void
ca_teardown_mask(void)
{
    cairo_pattern_destroy (mask);
}

int
ca_test_mask(caskbench_context_t *ctx)
{
    int i;
    cairo_t *cr = ctx->cairo_cr;

    for (i=0; i<ctx->size; i++) {
        // Apply mask on a circle
        cairo_arc (cr, 40*i, 40, 30, 0, 2*M_PI);
        cairo_fill (cr);
        cairo_mask (cr, mask);
    }
    return 1;
}
