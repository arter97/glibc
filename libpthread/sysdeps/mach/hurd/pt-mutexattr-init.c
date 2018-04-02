/* Copyright (C) 2016 Free Software Foundation, Inc.
   Contributed by Agustina Arzille <avarzille@riseup.net>, 2016.

   This program is free software; you can redistribute it and/or
   modify it under the terms of the GNU Library General Public License
   as published by the Free Software Foundation; either
   version 2 of the license, or (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
   GNU Library General Public License for more details.

   You should have received a copy of the GNU Library General Public
   License along with this program; if not, see
   <http://www.gnu.org/licenses/>.
*/

#include <pthread.h>
#include <stdlib.h>
#include <assert.h>
#include <pt-internal.h>
#include "pt-mutex.h"
#include <hurdlock.h>

static const pthread_mutexattr_t dfl_attr =
{
  .__prioceiling = 0,
  .__protocol = PTHREAD_PRIO_NONE,
  .__pshared = PTHREAD_PROCESS_PRIVATE,
  .__mutex_type = __PTHREAD_MUTEX_TIMED
};

int __pthread_mutexattr_init (pthread_mutexattr_t *attrp)
{
  *attrp = dfl_attr;
  return (0);
}
weak_alias (__pthread_mutexattr_init, pthread_mutexattr_init)
