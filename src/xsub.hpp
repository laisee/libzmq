/*
    Copyright (c) 2007-2011 iMatix Corporation
    Copyright (c) 2007-2011 Other contributors as noted in the AUTHORS file

    This file is part of 0MQ.

    0MQ is free software; you can redistribute it and/or modify it under
    the terms of the GNU Lesser General Public License as published by
    the Free Software Foundation; either version 3 of the License, or
    (at your option) any later version.

    0MQ is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef __ZMQ_XSUB_HPP_INCLUDED__
#define __ZMQ_XSUB_HPP_INCLUDED__

#include "socket_base.hpp"
#include "fq.hpp"

namespace zmq
{

    class xsub_t :
        public socket_base_t
    {
    public:

        xsub_t (class ctx_t *parent_, uint32_t tid_);
        ~xsub_t ();

    protected:

        //  Overloads of functions from socket_base_t.
        void xattach_pipe (class pipe_t *pipe_, const blob_t &peer_identity_);
        int xsend (class msg_t *msg_, int options_);
        bool xhas_out ();
        int xrecv (class msg_t *msg_, int flags_);
        bool xhas_in ();
        void xread_activated (class pipe_t *pipe_);
        void xterminated (class pipe_t *pipe_);

    private:

        //  Fair queueing object for inbound pipes.
        fq_t fq;

        xsub_t (const xsub_t&);
        const xsub_t &operator = (const xsub_t&);
    };

}

#endif

