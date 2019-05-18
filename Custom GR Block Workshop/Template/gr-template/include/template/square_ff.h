/* -*- c++ -*- */
/* 
 * Copyright 2019 gr-template author.
 * 
 * This is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3, or (at your option)
 * any later version.
 * 
 * This software is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this software; see the file COPYING.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street,
 * Boston, MA 02110-1301, USA.
 */


#ifndef INCLUDED_TEMPLATE_SQUARE_FF_H
#define INCLUDED_TEMPLATE_SQUARE_FF_H

#include <template/api.h>
#include <gnuradio/block.h>

namespace gr {
  namespace template {

    /*!
     * \brief <+description of block+>
     * \ingroup template
     *
     */
    class TEMPLATE_API square_ff : virtual public gr::block
    {
     public:
      typedef boost::shared_ptr<square_ff> sptr;

      /*!
       * \brief Return a shared_ptr to a new instance of template::square_ff.
       *
       * To avoid accidental use of raw pointers, template::square_ff's
       * constructor is in a private implementation
       * class. template::square_ff::make is the public interface for
       * creating new instances.
       */
      static sptr make();
    };

  } // namespace template
} // namespace gr

#endif /* INCLUDED_TEMPLATE_SQUARE_FF_H */

