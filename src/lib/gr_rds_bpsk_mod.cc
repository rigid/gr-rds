/* -*- c++ -*- */
/*
 * Copyright 2004 Free Software Foundation, Inc.
 * 
 * This file is part of GNU Radio
 * 
 * GNU Radio is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2, or (at your option)
 * any later version.
 * 
 * GNU Radio is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with GNU Radio; see the file COPYING.  If not, write to
 * the Free Software Foundation, Inc., 59 Temple Place - Suite 330,
 * Boston, MA 02111-1307, USA.
 */

/*
 * config.h is generated by configure.  It contains the results
 * of probing for features, options etc.  It should be the first
 * file included in your .cc file.
 */
#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <gr_rds_bpsk_mod.h>
#include <gr_io_signature.h>

#include <fstream>

/*
 * Create a new instance of gr_rds_bpsk_mod and return
 * a boost shared_ptr.  This is effectively the public constructor.
 */
gr_rds_bpsk_mod_sptr gr_rds_make_bpsk_mod (double sampling_rate)
{
	return gr_rds_bpsk_mod_sptr (new gr_rds_bpsk_mod (sampling_rate));
}

/*
 * The private constructor
 */
gr_rds_bpsk_mod::gr_rds_bpsk_mod (double input_sampling_rate)
	: gr_block("gr_rds_bpsk_mod",
			gr_make_io_signature2 (2, 2, sizeof(bool), sizeof(float)),
			gr_make_io_signature (1, 8, sizeof(float)))
{
}

/*
 * Our virtual destructor.
 */
gr_rds_bpsk_mod::~gr_rds_bpsk_mod (){
}



/* in[] is the 1187.5bps data stream, clk[] is the 57kHz carrier */
int gr_rds_bpsk_mod::general_work (int noutput_items,
					gr_vector_int &ninput_items,
					gr_vector_const_void_star &input_items,
					gr_vector_void_star &output_items)
{
	const bool *in = (const bool *) input_items[0];
	const float *clk = (const float *) input_items[1];
	float *out = (float *) output_items[0];

	for (int i = 0; i < noutput_items; i++){
		out[i] = in[i]?clk[i]:(-1*clk[i]);
		consume_each(1);
	}

	return noutput_items;
}
