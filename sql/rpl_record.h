/* Copyright 2007 MySQL AB. All rights reserved.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; version 2 of the License.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software Foundation,
   51 Franklin Street, Suite 500, Boston, MA 02110-1335 USA */

#ifndef RPL_RECORD_H
#define RPL_RECORD_H

#include <rpl_reporting.h>
#include "my_global.h"                          /* uchar */

class Relay_log_info;
struct TABLE;
typedef struct st_bitmap MY_BITMAP;

#if !defined(MYSQL_CLIENT)
size_t pack_row(TABLE* table, MY_BITMAP const* cols,
                uchar *row_data, const uchar *data);
#endif

#if !defined(MYSQL_CLIENT) && defined(HAVE_REPLICATION)
int unpack_row(Relay_log_info const *rli,
               TABLE *table, uint const colcnt,
               uchar const *const row_data, MY_BITMAP const *cols,
               uchar const **const row_end, ulong *const master_reclength,
               const bool abort_on_warning= TRUE, const bool first_row= TRUE);

// Fill table's record[0] with default values.
int prepare_record(TABLE *const table, const uint skip, const bool check,
                   const bool abort_on_warning= TRUE,
                   const bool first_row= TRUE);
#endif

#endif
