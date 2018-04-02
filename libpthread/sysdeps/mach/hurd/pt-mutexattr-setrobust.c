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

int pthread_mutexattr_setrobust (pthread_mutexattr_t *attrp, int robust)
{
  if (robust != PTHREAD_MUTEX_ROBUST &&
      robust != PTHREAD_MUTEX_STALLED)
    return (EINVAL);

  attrp->__prioceiling |= robust;
  return (0);
}

weak_alias (pthread_mutexattr_setrobust, pthread_mutexattr_setrobust_np)
