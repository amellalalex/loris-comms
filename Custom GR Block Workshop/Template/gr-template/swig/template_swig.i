/* -*- c++ -*- */

#define TEMPLATE_API

%include "gnuradio.i"			// the common stuff

//load generated python docstrings
%include "template_swig_doc.i"

%{
#include "template/square_ff.h"
%}


%include "template/square_ff.h"
GR_SWIG_BLOCK_MAGIC2(template, square_ff);
