#!/usr/bin/env python2
# -*- coding: utf-8 -*-
# 
# Copyright 2019 gr-template author.
# 
# This is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 3, or (at your option)
# any later version.
# 
# This software is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
# 
# You should have received a copy of the GNU General Public License
# along with this software; see the file COPYING.  If not, write to
# the Free Software Foundation, Inc., 51 Franklin Street,
# Boston, MA 02110-1301, USA.
# 

from gnuradio import gr, gr_unittest
from gnuradio import blocks
import template_swig as template

class qa_square_ff (gr_unittest.TestCase):

    def setUp (self):
        self.tb = gr.top_block ()

    def tearDown (self):
        self.tb = None

    def test_001_t (self):
        #create placeholders for block input data and expected output data
        src_data = (-3, 4, -5.5, 2, 3)
        expected_result = (9, 16, 30.25, 4, 9)
        
        #creace placeholders for abstract block input, the abstract block itself and the abstract output
        src = blocks.vector_source_f(src_data)
        sqr = test_module.square_ff()
        dst = blocks.vector_sink_f()
        
        #'connect' the block input to the block, and the block to the block's output
        self.tb.connect(src, sqr)
        self.tb.connect(sqr, dst)
        
        #execute block
        self.tb.run()
        
        #verify that expected results match results obtained
        result_data = dst.data()
        self.assetFloatTuplesAlmostEqual(expected_result, result_data, 6)
        
        # set up fg
        self.tb.run ()
        # check data


if __name__ == '__main__':
    gr_unittest.run(qa_square_ff, "qa_square_ff.xml")
